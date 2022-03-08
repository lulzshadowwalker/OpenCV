#ifndef UTILS
#define UTILS
#include <opencv2/opencv.hpp>

void showDebug(cv::Mat image1, cv::Mat image2, bool showDebug = false,
               int waitKey = 0) {
  if (showDebug) {
    cv::imshow("image1", image1);
    cv::imshow("image2", image2);
    cv::waitKey(waitKey);
  }
}

void showDebug(cv::Mat image1, bool showDebug = false, int waitKey = 0) {
  if (showDebug) {
    cv::imshow("image1", image1);
    cv::waitKey(waitKey);
  }
}

void colorDetectWebcam() {
  cv::VideoCapture webcam(0);
  cv::Mat frame;
  int a = 1;

  int hueMin = 0, satMin = 0, valMin = 0;
  int hueMax = 179, satMax = 255, valMax = 255;

  std::string windowName = "isloate Color";
  cv::namedWindow(windowName, cv::WINDOW_NORMAL);

  cv::createTrackbar("Hue min", windowName, &hueMin, 179);
  cv::createTrackbar("Hue max", windowName, &hueMax, 179);
  cv::createTrackbar("Sat min", windowName, &satMin, 255);
  cv::createTrackbar("Sat max", windowName, &satMax, 255);
  cv::createTrackbar("Value min", windowName, &valMin, 255);
  cv::createTrackbar("Value max", windowName, &valMax, 255);

  while (true) {
    webcam.read(frame);
    cv::putText(frame, "frame count: " + std::to_string(a++), cv::Point(50, 50),
                cv::FONT_HERSHEY_COMPLEX, 0.75, cv::Scalar(0, 179, 0), 2);
    cv::cvtColor(frame, frame, cv::COLOR_BGR2HSV);

    // would be nice if i can find a way to set it after declaration not to
    // declare every time inside of the loop
    cv::Scalar lowerRange(hueMin, satMin, valMin),
        upperRange(hueMax, satMax, valMax);

    cv::inRange(frame, lowerRange, upperRange, frame);

    cv::imshow("webcam", frame);
    cv::waitKey(10);

    // debug
    // {hueMin, satMin, valMin, hueMax, satMax, valMax}
    std::cout << '{' << hueMin << ',' << satMin << ',' << valMin << ','
              << hueMax << ',' << satMax << ',' << valMax << "}\n";
  }
}
#endif  // !UTILS
