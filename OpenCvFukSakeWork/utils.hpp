#ifndef UTILS
#define UTILS
#include <opencv2/opencv.hpp>

void showDebug(cv::Mat image1, cv::Mat image2, bool showDebug = false) {

	if (showDebug) {
		cv::imshow("image1", image1);
		cv::imshow("image2", image2);
		cv::waitKey(0);
	}
}

void showDebug(cv::Mat image1, bool showDebug = false) {

	if (showDebug) {
		cv::imshow("image1", image1);
		cv::waitKey(0);
	}
}

#endif // !UTILS
