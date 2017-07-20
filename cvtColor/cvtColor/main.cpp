#include<opencv2\opencv.hpp>
#include "opencv2/imgproc/imgproc.hpp"
#include"opencv2/highgui/highgui.hpp"

using namespace cv;

void main()
{
	Mat srcImage = imread("1.jpg",1),dstImage1,dstImage2,dstImage3;

	//转化颜色空间
	cvtColor(srcImage,dstImage1,COLOR_BGR2Lab);
	cvtColor(srcImage,dstImage2,COLOR_BGR2HLS);
	cvtColor(srcImage,dstImage3,COLOR_RGB2GRAY);

	//显示原图
	imshow("【原图】",srcImage);

	//显示效果图
	imshow("【效果图1】",dstImage1);
	imshow("【效果图2】",dstImage2);
	imshow("【效果图3】",dstImage3);

	waitKey(0);
}