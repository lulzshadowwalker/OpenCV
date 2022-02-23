#ifndef CHAPTER_8
#define CHAPTER_8

#include <opencv2/opencv.hpp>

namespace ch8 {

	void detectFace(cv::Mat sourceImage, bool debug = false) {
		cv::CascadeClassifier faceCascade;
		faceCascade.load("resources/haarcascade_frontalface_default.xml");

		if (!faceCascade.empty()) std::cout << "loading success: face cascade" << std::endl;
		assert(!faceCascade.empty());
		
		std::vector<cv::Rect> faces;
		faceCascade.detectMultiScale(sourceImage, faces, 1.1, 7);

		for (int i = 0; i < faces.size(); i++) {
			cv::rectangle(sourceImage, faces[i].tl(), faces[i].br(), cv::Scalar(0, 255, 149), 2);
			cv::putText(sourceImage, "dead", { faces[i].x, faces[i].y - 5 }, cv::FONT_HERSHEY_DUPLEX, 0.5, cv::Scalar(0, 0, 255));
				
		}

		showDebug(sourceImage, debug);
	}

} // END CH8

#endif // !CHAPTER_8
