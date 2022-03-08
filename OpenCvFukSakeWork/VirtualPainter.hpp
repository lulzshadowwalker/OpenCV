#ifndef VIRTUAL_PAINTER
#define VIRTUAL_PAINTER

#include <opencv2/opencv.hpp>
#define OUT // out parameter 

using namespace cv;

namespace vp {

void virtualPainter(Mat inputImg, std::vector<std::vector<int>> OUT &targetPoints) {
  /// maybe refactor just maybe
  /// those values were found using the [colorDetectWebcam] function from
  /// "utils.hpp" hueMin, satMin, valMin, hueMax, satMax, valMax HSV color
  std::vector<std::vector<int>> myColors = {
      {63, 80, 36, 86, 255, 255},  // green
      {62, 62, 95, 179, 255, 255}  // Pink
  };

  /// BGR color corresponding to the HSV color from [myColors]
  std::vector<Scalar> myColorValues = {
      Scalar(0, 206, 143),  // green
      Scalar(105, 11, 176)  // Pink
  };

  Mat outImg;
  /// generating a mask for every color in [myColors]
  for (int j = 0; j < myColors.size(); j++) {
    cvtColor(inputImg, outImg, COLOR_BGR2HSV);

    Scalar lower(myColors[j][0], myColors[j][1], myColors[j][2]);
    Scalar upper(myColors[j][3], myColors[j][4], myColors[j][5]);
    Mat mask;
    inRange(outImg, lower, upper, mask);

    // finding the contours
    std::vector<std::vector<Point>> contours;
    std::vector<Vec4i> heirarchy;
    findContours(mask, contours, heirarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

    int area = -1;
    std::vector<std::vector<cv::Point>> contourApproxPoly(contours.size());
    std::vector<cv::Rect> boundingRectVector(contours.size());
    // the point where the drawing will take place
    Point targetPoint(0, 0);
    for (int i = 0; i < contours.size(); i++) {
      //std::cout << "contours.size() => " << contours.size() << std::endl;

      area = contourArea(
          contours[i],
          false);  // i think it should be open "false" but we'll see

      // 2000 because im using the phone as a webcam and it's stretched out for
      // some reason
      if (area > 2000) {
        //std::cout << "contours area => " << contourArea(contours[i], false) << std::endl;
        double perimter = cv::arcLength(contours[i], true);
        cv::approxPolyDP(contours[i], contourApproxPoly[i], 0.2 * perimter,
                         false);

        boundingRectVector[i] = cv::boundingRect(contourApproxPoly[i]);
        // TODO way better results if i were to implement a rotated rect 
        // debug
        rectangle(inputImg, boundingRectVector[i].tl(),
                  boundingRectVector[i].br(), Scalar(143, 206, 0), 3);

        targetPoint.x =
            boundingRectVector[i].x + boundingRectVector[i].width * 0.5;
        targetPoint.y = boundingRectVector[i].y;

        if ((targetPoint.x + targetPoint.y) != 0) {
          OUT targetPoints.push_back({targetPoint.x, targetPoint.y, j});
        }


        // debug
        drawContours(inputImg, contours, i, Scalar(176, 128, 18), 3);

       
      }
    
     
    }

    // draw
    // imagine seperating functions couldnt be me
    for (int i = 0; i < targetPoints.size(); i++) {
      circle(inputImg, {targetPoints[i][0], targetPoints[i][1]}, 20,
             myColorValues[targetPoints[i][2]], FILLED);
    }
    std::string windowName = "webcam";
    imshow(windowName, inputImg);
    waitKey(1);
  }
}

}  // namespace vp

#endif