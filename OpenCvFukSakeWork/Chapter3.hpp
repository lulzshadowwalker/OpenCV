#ifndef CHAPTER_3
#define CHAPTER_3

/// <summary>
/// resizing and cropping images
/// </summary>
namespace ch3 {

	/// <summary>
	/// Resize an image
	/// </summary>
	/// <param name="size"> if you want to scale the image to a specific size e.g. Size(1920, 1080) [default] </param>
	/// <param name="scaleX, Y">scale an image by a factor, e.g. 2.0 or 0.5 (make sure to set the [size] to `Size()` to get an accurate result</param>
	/// <returns></returns>
	cv::Mat resizeImage(bool isDebug, std::string imagePath, double scaleX, double scaleY, cv::Size size = cv::Size(1920, 1080)) {
		cv::Mat sourceImage = cv::imread(imagePath),
			outputImage;

		cv::resize(sourceImage, outputImage, size, scaleX, scaleY);

		//// debug
		if (isDebug) {
			cv::imshow("source image", sourceImage);
			cv::imshow("resized image", outputImage);
			cv::waitKey(0);
		}

		return outputImage;

	}

	cv::Mat cropImage(bool isDebug, std::string imagePath, double width, double height, double offsetX = 0, double offsetY = 0) {
		cv::Mat sourceImage = cv::imread(imagePath),
			outputImage;

		// TODO resolve unhandled exception where roi is outside of the image borders

		// roi: region of interest
		cv::Rect roi = cv::Rect(offsetX, offsetY, width, height);
		outputImage = sourceImage(roi);

		//// debug
		std::cout << "source image size: " << sourceImage.size() << std::endl;
		if (isDebug) {
			cv::imshow("source image", sourceImage);
			cv::imshow("cropped image", outputImage);
			cv::waitKey(0);
		}

		return outputImage;

	}

}

#endif // !CHAPTER_3
