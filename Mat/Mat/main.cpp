#include<opencv2\opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;

int main()
{
	//ʹ��Mat�������캯��
	Mat M(2, 2, CV_8UC3, Scalar(0,0,255));//CV_8UC3 ��ʾ8λ Unsigned char���͵�ÿ������������Ԫ����ɵ���ͨ��
	cout << "M=" << endl << " " << M << endl << endl;




	system("pause");
	return 0;
}