#ifndef IMAGE_HPP
#define IMAGE_HPP

#include "utils.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <opencv2/objdetect/objdetect.hpp>

class Compare
{
public:
	int final_x;
	int final_y;
    Mat resize_new(int initial_x,int initial_y,int final_x,int final_y);
    Mat capture_new();
};

#endif IMAGE_HPP