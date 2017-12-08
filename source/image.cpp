#include "image.hpp"

//poor resize function
//add support for black and white image
int nearest(int i, float ratio)
{
    float check = ratio*i;

}

float min(float x, float y)
{
    if(x < y)
    return x;
    else
    return y;
}

int near(int i, float ratio)
{
    float x, y;
    x = i - (i*ratio);
    y = (i*ratio) - (i-1);

    if(min(x, y) == x)
    return i;
    else
    return (i-1);
}

process_image::resize_new(Mat frame)
{
	Mat Resize(Mat frame)
	{
	    /*Only when size of image is increased*/
	    int i=0, j=0, frows=frame.rows, fcols=frame.cols;
	    int x_ratio, y_ratio;

	    Mat outimage(orows, ocols, CV_8UC3, Scalar(0, 0, 0));
	    y_ratio = frows/orows;
	    x_ratio = fcols/ocols;

	    /*Nearest Neighbour method*/
	    for(i=0; i<orows; i++)
	    {
		for(j=0; j<ocols; j++)
		{
		    outimage.at<Vec3b>(i, j)[2] = frame.at<Vec3b>((near(i, y_ratio)), near(j, x_ratio))[2];
		    outimage.at<Vec3b>(i, j)[1] = frame.at<Vec3b>((near(i, y_ratio)), near(j, x_ratio))[1];
		    outimage.at<Vec3b>(i, j)[0] = frame.at<Vec3b>((near(i, y_ratio)), near(j, x_ratio))[0];
		    /*A check for non-negetivity is still required*/
		}
	    }

	    return outimage;
	}
}

// process_image::capture_new(){
// 	VideoCapture cap(0);                        /* open webcam */
// 	if(!cap.isOpened())  
// 	{  
// 		cout<<"camera can't be opened,exiting....."<<endl;
// 		return -1;  
// 	}
// 	Mat frame;
	
// 	while (true)
// 	{
// 		Mat frame
// 		cap>>frame;
// 		cap.set(CV_CAP_PROP_FRAME_WIDTH, final_x);      /* set width */
// 		cap.set(CV_CAP_PROP_FRAME_HEIGHT, final_y); 	/* set height */
// 		frame=process_image::resize_new(frame,final_y,final_x);/* because cap.set may or may not set the parameters you require */
// 		imshow("client",a);   
// 		if( waitKey(100) == 27 ) break;
// 	}    


// }
