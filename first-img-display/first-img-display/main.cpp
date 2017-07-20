#include<opencv2\opencv.hpp>

using namespace cv;

int main()
{
	Mat srcImage = imread("2.jpg");
	Mat srcImage2 = imread("1.jpg");
	//if(!srcImage.empty())
	//{
     imshow("【原始图】",srcImage);
   // }
	if(!srcImage2.empty())
	{
      imshow("【自我测试图】",srcImage2);
	}
	
	waitKey(0);
}