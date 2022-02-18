#ifndef CHAPTER_4
#define CHAPTER_4

#include "utils.hpp"

/// <summary>
/// Drawing shapes and texts on images
/// </summary>
namespace ch4 {

	/// create a blank image 
	cv::Mat createBlankImage(cv::Size size, cv::Scalar color, bool debug = false) {
		/// **CV_8UC3**
		/// 8: each pixel will have 8bits to represent the value ( a range of 256 values )
		/// U: Unsigned bits ( meaning the range is from 0-255, Signed: -127 - 127 )
		/// C3: # of channels ( rgb or as in CV "BGR" )
		cv::Mat outputImage(size, CV_8UC3, color);

		/// this line will not work if [debug] is false
		showDebug(outputImage, debug);

		return outputImage;
	}

	// dart programmer move Hehe :D 
	// same approach for e.g. a rectangle [Rect] or a [line] or text [putText]
	cv::Mat drawCircleInCenter(
		cv::Mat image,
		bool debug = false,
		int thickness = cv::FILLED,
		cv::Scalar color = cv::Scalar(0, 0, 0)
	) {

		double imageWidth = image.size().width;
		double imageHeight = image.size().height;
		cv::circle(image, cv::Point(imageWidth / 2, imageHeight / 2), 0.125 * imageWidth, color, thickness);

		showDebug(image, debug);

		return image;

	}

	cv::Mat addText(cv::Mat sourceImage, std::string body, bool debug = false, std::string header = "") {

		// i'll probably make this an entire project with flutter/c++/firebase
		// coming from flutter, I like everything to be dynamic :D 
		double width = sourceImage.size().width;
		double bodyWidth = width * 0.50;
		double headerWidth = width * 0.50;

		double height = sourceImage.size().height;
		double bodyHeight = height * 0.80;
		double headerHeight = height * 0.10;


		/// TODO  find a way to dynamically calculate the width of each character to perfectly center the line
		/// TODO  wrap to the next line on overflow 

		// header:: the outline
		cv::putText(sourceImage, header, cv::Point(headerWidth - header.length() * 8, headerHeight), cv::FONT_HERSHEY_COMPLEX, 0.75, cv::Scalar(0, 0, 0), 10);

		// header:: the actual text
		cv::putText(sourceImage, header, cv::Point(headerWidth - header.length() * 8, headerHeight), cv::FONT_HERSHEY_COMPLEX, 0.75, cv::Scalar(255, 255, 255), 2);

		// body:: the outline
		cv::putText(sourceImage, body, cv::Point(bodyWidth - body.length() * 6, bodyHeight), cv::FONT_HERSHEY_COMPLEX, 0.75, cv::Scalar(0, 0, 0), 10);

		// body:: the actual text
		cv::putText(sourceImage, body, cv::Point(bodyWidth - body.length() * 6, bodyHeight), cv::FONT_HERSHEY_COMPLEX, 0.75, cv::Scalar(255, 255, 255), 2);

		showDebug(sourceImage, debug);

		// nice
		// TIME TO MAKE CAT MEMES MUAHAHAHA

		return sourceImage;

	}



} // end ch4

#endif // !CHAPTER_4
