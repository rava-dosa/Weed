#include "image.hpp"

//poor resize function
//add support for black and white image
process_image::resize_new(Mat frame){
		Mat a(final_y,final_x,CV_8UC3,Scalar(0,0,0));
		if(frame.cols!=final_x && frame.rows!=final_y){
			for(int x=0;x<final_x;x++){
				for(int y=0;y<final_y;y++){
					a.at<Vec3b>(y,x)[0]=frame.at<Vec3b>(frame.rows/final_y*y,frame.cols/final_x*x)[0];
					a.at<Vec3b>(y,x)[1]=frame.at<Vec3b>(frame.rows/final_y*y,frame.cols/final_x*x)[1];
					a.at<Vec3b>(y,x)[2]=frame.at<Vec3b>(frame.rows/final_y*y,frame.cols/final_x*x)[2];

				}
			}
		}
		return a;

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
