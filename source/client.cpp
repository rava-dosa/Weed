#include "client.hpp"

int main()
{
	VideoCapture cap(0);                        /* open webcam */
	if(!cap.isOpened())  
	{  
		return -1;  
	}  

	process_image::image_x=320;
	process_image::image_y=240;
	Mat frame;
	cap.set(CV_CAP_PROP_FRAME_WIDTH, process_image::image_x);      /* set width */
	cap.set(CV_CAP_PROP_FRAME_HEIGHT, process_image::image_y);     /* set height */
	Mat a(process_image::image_y,process_image::image_x,CV_8UC3,Scalar(0,0,0));
	while (true)
	{
		cap>>frame;
		frame=process_image::resize_new(frame)
		if(waitKey(100)==27)break;
		imshow("client",frame);   
		frame = (frame.reshape(0,1)); // to make it continuous //reshape function converts matrix to a new matrix with 1 row with same no of channels of colors;
		int num=frame.total();                      /* num = 320*240 */
		int num2=frame.elemSize();                  /* mun2 =3 channel */
		int  imgSize = frame.total()*frame.elemSize();
		try
		{
			boost::asio::io_service io_service;
			tcp::endpoint end_point(boost::asio::ip::address::from_string("127.0.0.1"), 8080);
			tcp::socket socket(io_service);
			socket.connect(end_point);
			boost::system::error_code ignored_error;
			std::string message((char *)frame.data,230400);
			cout<<"sending...."<<endl;
			socket.write_some(boost::asio::buffer(message), ignored_error);
			cout<<"send image finished"<<endl;
		}
		catch (std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}

		}
			

	return 0;

