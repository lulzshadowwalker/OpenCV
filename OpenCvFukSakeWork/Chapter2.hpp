#ifndef CHAPTER_2
#define CHAPTER_2

#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

namespace ch2 {
	/// <summary>
	/// colored image to a gray scale image
	/// </summary>
	void rgbToGray(std::string imagePath) {
		cv::Mat normalImage = cv::imread(imagePath);

		cv::Mat grayImage;
		cv::cvtColor(normalImage, grayImage, cv::COLOR_BGR2GRAY);

		cv::imshow("normal image", normalImage);
		cv::imshow("gray image", grayImage);
		cv::waitKey(0);
	}

}


#endif // !CHAPTER_2
