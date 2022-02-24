#ifndef CHAPTER_7
#define CHAPTER_7

#include <opencv2/opencv.hpp>
#include <cmath>

/// <summary>
/// Shapes/Contour Detection
/// </summary>
namespace ch7 {

	/// <summary>
	/// Contour docs on OpenCV are pretty good check them out
	/// </summary>
	void detectShape(cv::Mat sourceImage, bool debug = false) {
		// image to draw the contours on ( Basically storing the original image in a variable rather
		// than the other way around because im lazy )
		cv::Mat image = sourceImage;


		/// preprocessing the image
		/// ( you can simple use the [dilateImage] function from Chapter-2 )
		cv::cvtColor(sourceImage, sourceImage, cv::COLOR_BGR2GRAY);
		cv::GaussianBlur(sourceImage, sourceImage, cv::Size(3, 3), 3, 0);
		cv::Canny(sourceImage, sourceImage, 25, 75);
		cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3));
		cv::dilate(sourceImage, sourceImage, kernel);
		// it's not detecting the small yellow triangle but whatever

		std::vector<std::vector<cv::Point>> contours;
		std::vector<cv::Vec4i> heirarchy;
		cv::findContours(sourceImage, contours, heirarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
		// [drawContours]: -1 means draw all contours
		//cv::drawContours(image, contours, -1, cv::Scalar(0, 0, 255), 2);

		/// filtering the contours to only draw contours that are above a certain limit
		int area = -1;

		std::vector<std::vector<cv::Point>> contourApproxPoly(contours.size());
		std::vector<cv::Rect> boundingRectVector(contours.size());

		std::string objectType = "undefined"; // "undefined" will probably never be actually used
		int corners = 0;

		for (int i = 0; i < contours.size(); i++) {
			area = cv::contourArea(contours[i]);
			std::cout << "area of contour #" << i << " is: " << area << std::endl;

			if (area > 200) {
				double perimter = cv::arcLength(contours[i], true);
				cv::approxPolyDP(contours[i], contourApproxPoly[i], 0.02 * perimter, true);
				//cv::drawContours(image, contourApproxPoly, i, cv::Scalar(105, 11, 176), 5);

				// debug
				std::cout << "contours[" << i << "] : " << contours[i].size() << std::endl;
				std::cout << "contourApproxPoly[" << i << "] : " << contourApproxPoly[i].size() << std::endl;

				// draw bounding rectangle
				boundingRectVector[i] = cv::boundingRect(contourApproxPoly[i]);
				cv::rectangle(image, boundingRectVector[i].tl(), boundingRectVector[i].br(), cv::Scalar(0, 255, 0), 2);

				// printing the suitable text ( object type )
				corners = contourApproxPoly[i].size();

				switch (corners)
				{
				case 1: objectType = "dot"; break; // hehe
				case 2: objectType = "line"; break;
				case 3: objectType = "trngle"; break;
				case 4:
					// maybe refactor this to be a little cleaner ? maybe ? hehe
				{
					float aspectRatio = float(boundingRectVector[i].width) / float(boundingRectVector[i].height);
					// just giving it a little forgiving range
					if (abs(aspectRatio - 1) < 0.1) objectType = "sqr";
					else objectType = "rect";
					break;
				}
				case 6: objectType = "hxgn"; break;
				case 8: objectType = "circle"; break;
				default:
					objectType = "star";
					break;
				}

				std::cout << objectType << std::endl;

				// or use {boundingRectVector[i].x, boundingRectVector[i].y}
				cv::putText(
					image, objectType,
					cv::Point(boundingRectVector[i].x, boundingRectVector[i].y - 5),
					cv::FONT_HERSHEY_DUPLEX,
					0.5,
					cv::Scalar(0, 0, 180)
				);
			}
		}

		showDebug(image, debug);
	}


} // end ch7

#endif // !CHAPTER_7
