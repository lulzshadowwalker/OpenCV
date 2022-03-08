#ifndef CHAPTER_5
#define CHAPTER_5
#include <opencv2/opencv.hpp>


namespace ch5 {

	/// started to pass by reference not to wait for debug [waitKey] to return the image
	void warpImage(cv::Mat sourceImage, cv::Mat& outPutImage, cv::Point2f source[], float width, float height, bool debug = false) {
		cv::Point2f warp[] = { {0, 0}, {width,0}, {0, height}, {width,height} };

		// [getPerspectiveTransform]: "Calculates a perspective transform from four pairs of the corresponding points."
		cv::Mat warpMatrix = cv::getPerspectiveTransform(source, warp);
		/// [warpPerspective]: Applies a perspective transformation to an image.
		/// The function [warpPerspective] transforms the source image using the specified matrix
		cv::warpPerspective(sourceImage, outPutImage, warpMatrix, cv::Point(width, height));

		// sometimes.	. im like "ilovec+". sometimes im like fuk, like imagine having .length() ? imagine.
		// draw debug circles around the points used to warp on the source image
		int sourceLength = sizeof(source) / sizeof(float) * 2;

		for (int i = 0; i < sourceLength; i++) {
			cv::circle(sourceImage, source[i], 5, cv::Scalar(224, 47, 103), cv::FILLED);
		}

		showDebug(sourceImage, outPutImage, debug);
	}

} // end ch5

#endif // !CHAPTER_5
