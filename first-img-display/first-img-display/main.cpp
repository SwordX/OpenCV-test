#include<opencv2\opencv.hpp>

using namespace cv;

int main()
{
	Mat srcImage = imread("2.jpg");
	Mat srcImage2 = imread("1.jpg");
	//if(!srcImage.empty())
	//{
     imshow("��ԭʼͼ��",srcImage);
   // }
	if(!srcImage2.empty())
	{
      imshow("�����Ҳ���ͼ��",srcImage2);
	}
	
	waitKey(0);
}