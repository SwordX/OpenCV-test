#include<opencv2\opencv.hpp>
#include "opencv2/imgproc/imgproc.hpp"
#include"opencv2/highgui/highgui.hpp"

using namespace cv;

void main()
{
	Mat srcImage = imread("1.jpg",1),dstImage1,dstImage2,dstImage3;

	//ת����ɫ�ռ�
	cvtColor(srcImage,dstImage1,COLOR_BGR2Lab);
	cvtColor(srcImage,dstImage2,COLOR_BGR2HLS);
	cvtColor(srcImage,dstImage3,COLOR_RGB2GRAY);

	//��ʾԭͼ
	imshow("��ԭͼ��",srcImage);

	//��ʾЧ��ͼ
	imshow("��Ч��ͼ1��",dstImage1);
	imshow("��Ч��ͼ2��",dstImage2);
	imshow("��Ч��ͼ3��",dstImage3);

	waitKey(0);
}