#ifndef VIRTUAL_PAINTER
#define VIRTUAL_PAINTER 

#include <opencv2/opencv.hpp>

using namespace cv;

namespace vp {

	void virtualPainter(Mat srcImg) {
		/// maybe refactor just maybe
		/// finding the color
		/// hueMin, satMin, valMin, hueMax, satMax, valMax
		std::vector<std::vector<int>> myColors = {
				{124, 48, 117, 143, 170, 255}, // purple
				{68, 72, 156, 102, 126, 255} // green
		};

		std::vector<Scalar> myColorValues = {
			Scalar(255, 0, 255), // purple
			Scalar(0, 255, 0) // green
		};

		cvtColor(srcImg, srcImg, COLOR_BGR2HSV);
		Scalar lower(hueMin, satMin, valMin);
		Scalar upper(hueMax, satMax, valMax);
		Mat mask;
		inRange(srcImg, lower, upper, mask);
	}
} // END VP

#endif 