#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/objdetect/objdetect.hpp>
#include <iostream>

using namespace cv;


int main(int argc, char* argv[])
{
    cv::CascadeClassifier cascade;
    cascade.load("/home/roy/Documents/Licence Plate Recognition/LBP/cascade.xml");

    char* filename = "/home/roy/Desktop/video";
    cv::VideoCapture cap(filename);
    if (!cap.isOpened())
    {
        std::cout << "!!! Failed to open file: " << argv[1] << std::endl;
        return -1;
    }

    cv::Mat frame;
    for(;;)
    {

        if (!cap.read(frame))
            break;

        std::vector<Rect> licence;
        cascade.detectMultiScale(frame,licence,1.2,2,0|CV_HAAR_SCALE_IMAGE,Size(50,15));


    for( size_t i = 0; i < licence.size(); i++ )
    {
        rectangle( frame, Point(licence[i].x ,licence[i].y),Point(licence[i].x+licence[i].width,licence[i].y+licence[i].height), Scalar( 255, 0, 255 ), 4, 8);
    }

    cv::imshow("window", frame);
        char key = cvWaitKey(10);
        if (key == 27) // ESC
            break;


    }

    return 0;
}
