﻿#include "Chapter1.hpp"
#include "Chapter2.hpp"
#include "Chapter3.hpp"
#include "Chapter4.hpp"
#include "Chapter5.hpp"
#include "Chapter6.hpp"
#include "Chapter7.hpp"
#include "Chapter8.hpp"
#include "VirtualPainter.hpp"
#include <iostream>

// namespaces aren't rly necessary but just to keep track of things
using namespace ch1;
using namespace ch2;
using namespace ch3;
using namespace ch4;
using namespace ch5;
using namespace ch6;
using namespace ch7;
using namespace ch8;
using namespace vp;

// TODO Chapter 6, implement an algorithm to analyze an image and find the average color

int main() {
	cv::Mat kitty = cv::imread("resources/Kitty.png");
	cv::Mat bongKitty = cv::imread("resources/hitdabong.JFIF");
	cv::Mat cards = cv::imread("resources/cards.jpg");
	cv::Mat shapes = cv::imread("resources/my-shapes.png");
	cv::Mat stars = cv::imread("resources/stars.png");
	cv::Mat face = cv::imread("resources/face.jpg");

	//addText(bongKitty, "take a sniff, its ghood X:O---:Z", true, "wanna smoke ahss whit me ?");

	/// image warping
	//cv::Mat outputImage;
	//cv::Point2f source[] = { {527, 146}, {769,190}, {405,397}, {674,457} };
	//warpImage(cards, outputImage, source, 250, 350, true);

	//detectShape(stars, true);

	//detectFace(face, true);

	//colorDetectWebcam();

	// virtual painter
        cv::VideoCapture webcam(0);
        cv::Mat frame;

		std::vector<std::vector<int>> targetPoints = {};
        while (true) {
          webcam.read(frame);
          virtualPainter(frame, targetPoints);
		}

	return 0;
}