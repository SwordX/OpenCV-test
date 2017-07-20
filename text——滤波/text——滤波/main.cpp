//------------------------------------------【头文件和命名空间部分】------------------------------------------
//                                    描述：包含程序所依赖的头文件和命名空间
//------------------------------------------------------------------------------------------------------------
#include<opencv2\opencv.hpp>
#include<iostream>
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
using namespace std;
using namespace cv;


//---------------------------------------------【main()函数】---------------------------------------------------
//                                     描述：我们的程序从这里开始
//---------------------------------------------------------------------------------------------------------------
int main()
{
	//载入图片
	Mat srcImage = imread("1.jpg");

	//创建窗口
	namedWindow("【1】原图");
	namedWindow("【2】效果图");

	//显示原图
	imshow("【1】原图",srcImage);

	//进行滤波操作
	Mat cut;
	boxFilter(srcImage,cut,-1,Size(5,5));

	//显示效果图
	imshow("【2】效果图",cut);

	//等待按任意键继续
	waitKey(0);

	return 0;
}