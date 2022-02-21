#ifndef CHAPTER_7
#define CHAPTER_7

#include <opencv2/opencv.hpp>

/// <summary>
/// Shapes/Contour Detection
/// </summary>
namespace ch7 {

	void detectShape(cv::Mat sourceImage, bool debug = false) {
		// image to draw the contours on
		cv::Mat image = sourceImage;


		/// preprocessing the image
		/// ( you can simple use the [dilateImage] function from Chapter-2 )
		cv::cvtColor(sourceImage, sourceImage, cv::COLOR_BGR2GRAY);
		cv::GaussianBlur(sourceImage, sourceImage, cv::Size(7,7), 5, 0);
		cv::Canny(sourceImage, sourceImage, 25, 75);
		cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3));
		cv::dilate(sourceImage, sourceImage, kernel);
		// it's not detecting the small yellow triangle but whatever

		std::vector<std::vector<cv::Point>> contours;
		std::vector<cv::Vec4i> heirarchy;
		cv::findContours(sourceImage, contours, heirarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_NONE); 
		// [drawContours]: -1 means draw all contours
		//cv::drawContours(image, contours, -1, cv::Scalar(0, 0, 255), 2);

		/// filtering the contours to only draw contours that are above a certain limit
		int area = -1;
		for (int i = 0; i < contours.size(); i++) {
			area = cv::contourArea(contours[i]);
			std::cout << "area of contour #" << i << " is: " << area << std::endl;

			if (area > 200) {
				cv::drawContours(image, contours, i, cv::Scalar(0, 0, 255), 2);
			}
			
				
		}

		showDebug(image, debug);
	}


} // end ch7

#endif // !CHAPTER_7
