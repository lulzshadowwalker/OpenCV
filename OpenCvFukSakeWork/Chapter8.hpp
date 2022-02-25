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
		faceCascade.detectMultiScale(sourceImage, faces, 1.1, 20);

		struct status {
			std::string status;
			cv::Scalar color;
		};

		status personStatus[] = { {"alive", cv::Scalar(0, 255, 149)}, {"dead", cv::Scalar(52, 52, 247)} };
		int randomIndex = 0;

		for (int i = 0; i < faces.size(); i++) {
			cv::rectangle(sourceImage, faces[i].tl(), faces[i].br(), cv::Scalar(0, 255, 149), 2);
			randomIndex = rand() % 2;
			cv::putText(
				sourceImage,
				personStatus[randomIndex].status,
				{ faces[i].x, faces[i].y - 5 },
				cv::FONT_HERSHEY_DUPLEX, 0.5,
				personStatus[randomIndex].color,
				1
			);
			showDebug(sourceImage, debug, 500);
		}
		cv::waitKey(0);

	}

} // END CH8

#endif // !CHAPTER_8
