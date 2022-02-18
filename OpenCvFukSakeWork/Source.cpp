#include "Chapter1.hpp"
#include "Chapter2.hpp"
#include "Chapter3.hpp"
#include "Chapter4.hpp"
#include "Chapter5.hpp"
#include "Chapter6.hpp"
#include <iostream>

using namespace ch1;
using namespace ch2;
using namespace ch3;
using namespace ch4;
using namespace ch5;
using namespace ch6;

// TODO Chapter 6, implement an algorithm to analyze an image and find the average color

int main() {
	cv::Mat kitty = cv::imread("resources/Kitty.png");
	cv::Mat bongKitty = cv::imread("resources/hitdabong.JFIF");
	cv::Mat cards = cv::imread("resources/cards.jpg");

	//addText(bongKitty, "hit da bong wiht mee ?", true, "hey.. hooman");

	/// image warping
	//cv::Mat outputImage;
	//cv::Point2f source[] = { {527, 146}, {769,190}, {405,397}, {674,457} };
	//warpImage(cards, outputImage, source, 250, 350, true);

	isoloateColor(kitty);

	return 0;
}