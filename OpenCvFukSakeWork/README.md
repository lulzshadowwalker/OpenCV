# OpenCV C++

I created a header file for every chapter, each one with it's one namespace just to keep track of stuff even though not very neccessary.

## Table of Contents

- [Chapter 1](#chapter-1)
- [Chapter 2](#chapter-2)
- [Chapter 3](#chapter-3)
- [Chapter 4](#chapter-4)
- [Chapter 5](#chapter-5)
- [Chapter 6](#chapter-6)

## Chapter 1

> show, read image, video & webcam

- `Mat` datatype by the OpebCV lib: Matrix to handle storing images;
- to read a video, you basically want to iterate through all the frames;

## Chapter 2

> basic functions;

- `Canny` edge detector is usually used alongside with some blur e.g. `GaussianBlur` as common practice, [**Canny docs**](https://docs.opencv.org/3.4/da/d5c/tutorial_canny_detector.html);

- **dilating**[increasing the thickness] and **eroding**[decreasing the thickness], which are usually used in conjuction with [Canny] should have an equal width&height for the kernel size;
  
  > unhandled exception for a kernelSize of (0, 0) so you better handle it in the function;

## Chapter 3

> resize & crop

- `someImage.size()` to get the size :O imagine :)
- RoI: Region of Interest, more often that not, we need to crop the image to a specific region to focus processing on a specific part of the image;

## Chapter 4

> drawing shapes & texts on images

>  **CV_8UC3** type example
>   **8**: each pixel will have 8bits to represent the value ( a range of 256 values )
>   **U**: Unsigned bits ( meaning the range is from 0-255, Signed: -127 - 127 )
>   **C3**: # of channels ( rgb or as in CV "BGR" )

- `Scalar`: are used to represent colors

## Chapter 5

> warp perspective
> 
> ![] (ReadMeImages\warping%20example.png)

> **"** In OpenCV, coordinates can be 2-dimensional, 3-dimensional, or 4-dimensional.
> 
> The number "2", "3", and "4" refers to the number of elements (components) in the coordinate vector.
> 
> The value for each element can be stored as:
> 
> - signed 32-bit integer, denoted with letter "**i**",
> - 32-bit floating point (single precision), denoted with letter "**f**", and
> - 64-bit floating point (double precision), denoted with letter "**d**".
> 
> Therefore, a 2D vector of integer values is named `Point2i`. Likewise, a 3D vector of 32-bit single-precision floating point values is named `Point3f`.
> 
> OpenCV defines a C++ type alias, named `Point`, is a shorthand for `Point2i`. This is merely for convenience and for reduce code clutter.**"**
> 
> [**source**]([What is Point2f and Point3f? - OpenCV Q&amp;A Forum](https://answers.opencv.org/question/196492/what-is-point2f-and-point3f/))

- `getPerspectiveTransform` "Calculates a perspective transform from four pairs of the corresponding points." 

- `warpPerspective` "Applies a perspective transformation to an image.
  
  The function `warpPerspective` transforms the source image using the specified matrix"

## Chapter 6

> color detection

> **HSV** color model ( Cylinderical coordinate representation of points in RGB color model )
> 
> **H**: Hue, the dominant color percieved by an observer ( angle )
> 
> **S**: Saturation, the amount of white light mixed with the hue ( radius )
> 
> **V**: Value, the chromatic notation of intensity ( height )
>
> > ![] (ReadMeImages\HSV-color-model.png)
> 
