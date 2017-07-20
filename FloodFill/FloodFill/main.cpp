#include<opencv2\opencv.hpp>
#include<opencv2\core\core.hpp>
#include<opencv2\imgproc\imgproc.hpp>

using namespace cv;

int main()
{
	Mat src = imread("2.jpg");

	namedWindow("【原图】");
	namedWindow("【FloodFill效果图】");

	imshow("【原图】",src);

	Rect ccomp;
	floodFill(src,Point(50,300),Scalar(155,255,55),&ccomp,Scalar(20,20,20),Scalar(20,20,20));

	imshow("【FloodFill效果图】",src);
	waitKey(0);
	return 0;
}