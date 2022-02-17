#ifndef CHAPTER_1
#define CHAPTER_1


#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>


// idk if this is good practice to use namespaces but i think it's kinda suitable in this case
// actually i think it's good, i dont need to use a class to access them whenever i want to + 
// i can just `using namespace std;`

/// <summary>
/// read/show image, video & webcam
/// </summary>
namespace ch1 {

	void showImage(std::string imagePath, std::string windowName = "bongoTap") {
		/// Matrix to store the image data
		cv::Mat image = cv::imread(imagePath);
		cv::imshow(windowName, image);
		cv::waitKey(0);
	}

	void showVideo(std::string videoPath, double fps = 60.0, std::string windowName = "bongoTap") {
		// TODO add audio bongoTap
		cv::VideoCapture vidCap(videoPath);
		cv::Mat frame;

		while (true) {
			vidCap.read(frame);

			cv::imshow(windowName, frame);
			// delay between every frame (framerate)
			cv::waitKey(1000 / fps);

		}
	}

	void showWebcam(double fps = 60.0, int cameraId = 0, std::string windowName = "bongoTap") {
		// Exact saame code as [showVideo] except you pass [cameraId] instead of [videoPath]
		// TODO refactor ? :)

		// TODO add audio        bongoTap

		// 0 represents the id of the camera, if you e.g. have 2 cams and want to use the second simply pass 1 as an argument
		cv::VideoCapture vidCap(cameraId);
		cv::Mat frame;

		while (true) {
			vidCap.read(frame);

			cv::imshow(windowName, frame);
			// delay between every frame (framerate)
			cv::waitKey(1000 / fps);

		}
	}

}


#endif // !CHAPTER_1