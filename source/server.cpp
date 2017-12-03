#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include <boost/array.hpp>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <opencv2/objdetect/objdetect.hpp>
#include <iostream>
#include <vector>
#include <boost/thread/thread.hpp>
using boost::asio::ip::tcp;
using namespace  std;
using namespace cv;
Mat  img = Mat::zeros( 320,240, CV_8UC3);
bool flag = false;                              /* if flag is false ,the thread is not ready to show the mat frame */
 
void servershow()
{
    while (true)
    {
        if (flag)
        {
            imshow("server",img);
            waitKey(20);
        }
         
         
    }
     
}
int main()
{
    boost::thread thrd(&servershow);
    try
    {
        boost::asio::io_service io_service;
        boost::array<char, 230400> buf;         /* the size of reciev mat frame is caculate by 320*240*3 */
        tcp::acceptor acceptor(io_service, tcp::endpoint(tcp::v4(), 8080));
         
        while(1)
        {
            tcp::socket socket(io_service);
            acceptor.accept(socket);
            boost::system::error_code error;
            size_t len = socket.read_some(boost::asio::buffer(buf), error);
            cout<<"get data length :"<<len<<endl; /* disp the data size recieved */
            std::vector<uchar> vectordata(buf.begin(),buf.end()); /* change the recieved mat frame(1*230400) to vector */
            cv::Mat data_mat(vectordata,true);
            img= data_mat.reshape(3,240);       /* reshape to 3 channel and 240 rows */
            cout<<"reshape over"<<endl;
            flag =true;
            
        }
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    thrd.join();
     
 
    return 0;
}


