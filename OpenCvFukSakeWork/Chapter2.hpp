#ifndef CHAPTER_2
#define CHAPTER_2

#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>

/// <summary>
/// Basic functions
/// </summary>
namespace ch2 {
	cv::Mat rgbToGray(std::string imagePath) {
		cv::Mat normalImage = cv::imread(imagePath);

		cv::Mat grayImage;
		cv::cvtColor(normalImage, grayImage, cv::COLOR_BGR2GRAY);

		// debug 
		//cv::imshow("normal image", normalImage);
		//cv::imshow("gray image", grayImage);
		//cv::waitKey(0);

		return grayImage;
	}

	cv::Mat gaussianBlur(std::string imagePath, double sigmaX = 5, double sigmaY = 0, cv::Size kernelSize = cv::Size(7, 7)) {
		cv::Mat sourceImage = cv::imread(imagePath);
		cv::Mat outputImage;

		cv::GaussianBlur(sourceImage, outputImage, kernelSize, sigmaX, sigmaY);

		//// debug
		//cv::imshow("Source Image", sourceImage);
		//cv::imshow("Blurred Image", outputImage);
		//cv::waitKey(0);

		return outputImage;
	}

	/// <summary>
	/// Edge detector
	/// </summary>
	cv::Mat canny(std::string imagePath, double threshHold1 = 25, double threshHold2 = 75) {
		cv::Mat sourceImage,
			outputImage;

		/// Canny is usually used alongside blur 
		/// doc: ( https://docs.opencv.org/3.4/da/d5c/tutorial_canny_detector.html )
		sourceImage = gaussianBlur(imagePath);


		cv::Canny(sourceImage, outputImage, threshHold1, threshHold2);

		//// debug
		//cv::imshow("Source Image", sourceImage);
		//cv::imshow("Canny Image", outputImage);
		//cv::waitKey(0);

		return outputImage;
	}


	/// <summary>
	///  basically, increases thickness. use this with a [Canny] image to understand
	/// </summary>
	cv::Mat dilateImage(std::string imagePath, cv::Size kernelSize = cv::Size(3, 3)) {
		/// for real, why am I supposed to handle this exception ?! it should be the library itself 
		if (kernelSize == cv::Size(0, 0)) kernelSize = cv::Size(1, 1);

		cv::Mat sourceImage,
			outputImage;

		sourceImage = canny(imagePath);

		// TODO read more about [getStructuringElement]
		/// for the [kernel], use equal values for the [size] width&height 3,3 5,5 ...etc
		cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT, kernelSize);

		dilate(sourceImage, outputImage, kernel);

		//// debug
		//cv::imshow("Source Image", sourceImage);
		//cv::imshow("dilated Image", outputImage);
		//cv::waitKey(0);

		return outputImage;
	}

	/// <summary>
	/// Erosion. Basically decrease the thickness.
	/// </summary>
	cv::Mat erodeImage(std::string imagePath, cv::Size kernelSize = cv::Size(2, 2)) {
		/// Unhandled exception handling :)
		if (kernelSize == cv::Size(0, 0)) kernelSize = cv::Size(1, 1);

		cv::Mat sourceImage,
			outputImage;

		/// dilating the image just to have more space to decrease the thickness
		sourceImage = dilateImage(imagePath);

		// TODO read more about [getStructuringElement]
		// for the [kernel], use equal values for the [size] width&height 3,3 5,5 ...etc
		cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT, kernelSize);

		erode(sourceImage, outputImage, kernel);

		//// debug
		//cv::imshow("Source Image", sourceImage);
		//cv::imshow("eroded Image", outputImage);
		//cv::waitKey(0);

		return outputImage;
	}

} /// end namespace ch2 


#endif // !CHAPTER_2
