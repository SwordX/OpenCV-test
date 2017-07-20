#include<opencv/opencv.hpp>

using namespace cv;

int main()
{
	Mat img=imread("1.jpg");
	imshow("¡¾ÔØÈëµÄÍ¼Æ¬¡¿",img);
	waitKey(6000);
}