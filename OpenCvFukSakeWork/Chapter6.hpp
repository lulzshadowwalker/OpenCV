#ifndef CHAPTER_6
#define CHAPTER_6

#include <opencv2/opencv.hpp>

namespace ch6 {

	/// <summary>
	/// color detector 
	/// </summary>
	void isoloateColor(cv::Mat sourceImage) {
		cv::cvtColor(sourceImage, sourceImage, cv::COLOR_BGR2HSV);

		int hueMin = 0, satMin = 0, valMin = 0;
		int hueMax = 179, satMax = 255, valMax = 255;

		cv::Mat mask;

		cv::imshow("Source Image (HSV)", sourceImage);

		/// Trackbars window
		std::string windowName = "Color range specifier";

		cv::namedWindow(windowName, cv::WINDOW_NORMAL);

		cv::createTrackbar("Hue min", windowName, &hueMin, 179);
		cv::createTrackbar("Hue max", windowName, &hueMax, 179);
		cv::createTrackbar("Sat min", windowName, &satMin, 255);
		cv::createTrackbar("Sat max", windowName, &satMax, 255);
		cv::createTrackbar("Value min", windowName, &valMin, 255);
		cv::createTrackbar("Value max", windowName, &valMax, 255);



		// realtime preview of the image
		while (true) {
			cv::Scalar lowerRange(hueMin, satMin, valMin);
			cv::Scalar upperRange(hueMax, satMax, valMax);

			cv::inRange(sourceImage, lowerRange, upperRange, mask);
			cv::imshow("Color Detection Mask", mask);
			cv::waitKey(1);
		}
	}

} //end ch6
#endif // !CHAPTER_6
