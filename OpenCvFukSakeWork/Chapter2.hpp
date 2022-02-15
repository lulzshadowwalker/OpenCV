#ifndef CHAPTER_2
#define CHAPTER_2

#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

namespace ch2 {
	cv::Mat rgbToGray(std::string imagePath) {
		cv::Mat normalImage = cv::imread(imagePath);

		cv::Mat grayImage;
		cv::cvtColor(normalImage, grayImage, cv::COLOR_BGR2GRAY);

		// debug 
		cv::imshow("normal image", normalImage);
		cv::imshow("gray image", grayImage);
		cv::waitKey(0);

		return grayImage;
	}
	

	cv::Mat gaussianBlur(std::string imagePath,  double sigmaX = 5, double sigmaY = 0, cv::Size kernelSize = cv::Size(7, 7)) {
		cv::Mat sourceImage = cv::imread(imagePath);
		cv::Mat outputImage;

		cv::GaussianBlur(sourceImage, outputImage, kernelSize, sigmaX, sigmaY);

		// debug
		cv::imshow("Source Image", sourceImage);
		cv::imshow("Blurred Image", outputImage);
		cv::waitKey(0);

		return outputImage;
	}

}


#endif // !CHAPTER_2
