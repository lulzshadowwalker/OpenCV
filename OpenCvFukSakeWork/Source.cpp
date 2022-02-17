#include "Chapter4.hpp"
#include "Chapter1.hpp"
#include "Chapter2.hpp"
#include "Chapter3.hpp"
#include <iostream>

using namespace ch1;
using namespace ch2;
using namespace ch3;
using namespace ch4;
// TODO Chapter 6, implement an algorithm to analyze an image and find the average color

int main() {
	const std::string imagePath = "resources/kitty.png";

	createBlankImage(cv::Size(1920, 1080), cv::Scalar(100, 100, 100), true);

	return 0;
}