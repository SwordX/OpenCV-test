#include<opencv2\opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;

int main()
{
	//使用Mat（）构造函数
	Mat M(2, 2, CV_8UC3, Scalar(0,0,255));//CV_8UC3 表示8位 Unsigned char类型的每个像素由三个元素组成的三通道
	cout << "M=" << endl << " " << M << endl << endl;




	system("pause");
	return 0;
}