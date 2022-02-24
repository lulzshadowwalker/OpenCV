#ifndef UTILS
#define UTILS
#include <opencv2/opencv.hpp>

void showDebug(cv::Mat image1, cv::Mat image2, bool showDebug = false, int waitKey = 0) {

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

#endif // !UTILS
