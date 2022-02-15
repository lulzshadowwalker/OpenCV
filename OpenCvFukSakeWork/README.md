# OpenCV C++

## Table of Contents
- [Chapter 1](#chapter-1)
- [Chapter 2](#chapter-2)
- [Chapter 3](#chapter-3)

## Chapter 1
> Chapter1: show, read image, video & webcam
- `Mat` datatype by the OpebCV lib: Matrix to handle storing images;
- to read a video, you basically want to iterate through all the frames;

## Chapter 2
> Chapter2: basic functions
- `Canny` edge detector is usually used alongside with some blur e.g. `GaussianBlur` as common practice. [**Canny docs**](https://docs.opencv.org/3.4/da/d5c/tutorial_canny_detector.html)
- **dilating**[increasing the thickness] and **eroding**[decreasing the thickness], which are usually used in conjuction with [Canny] should have an equal width&height for the kernel size
> unhandled exception for a kernelSize of (0, 0) so you better handle it in the function

## Chapter 3
> Chapter 3: resize & crop
