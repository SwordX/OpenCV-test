#include <opencv2\opencv.hpp>
#include "opencv2/highgui/highgui.hpp"
#include<iostream>

using namespace std;
using namespace cv;

#define WINDOW_NAME "【线性混合实例】" //为窗口标题取名字


//---------------------------【全局变量声明部分】------------------------------------
//                            描述：全局变量声明
//-----------------------------------------------------------------------------------

const int g_nMaxAlphaValue = 100;        //Alpha的最大值
int g_nAlphaValueSlider;                 //滑动条对应的变量
double g_dAlphaValue;
double g_dBetaValue;

//声明储存图像的变量
Mat g_dstImage;
Mat g_srcImage1;
Mat g_srcImage2;


//-------------------------------【on_Trackbar()函数】-----------------------------------
//                              描述：响应滑动条的回调函数
//---------------------------------------------------------------------------------------



void on_Trackbar(int, void* )
{
	//求出当前Alpha值相对于最大值的比例
	g_dAlphaValue = (double) g_nAlphaValueSlider/g_nMaxAlphaValue;
	
	//则beta的值为1减去Alpha的值
	g_dBetaValue = (1.0 - g_dAlphaValue );

	//根据Alpha和beta的值进行线性混合
	addWeighted(g_srcImage1,g_dAlphaValue,g_srcImage2,g_dBetaValue,0.0,g_dstImage);


	//显示效果图
	imshow(WINDOW_NAME,g_dstImage);
}



//----------------------------------【main（）函数】---------------------------------------
//                      描述：控制台应用程序的入口函数，程序从这里开始执行
//------------------------------------------------------------------------------------------
int main( int argc , char** argv )
{
	//加载图片，两张图片的尺寸需要相同
	g_srcImage1 = imread("2.jpg");
	g_srcImage2 = imread("3.jpg");

	if(!g_srcImage1.data){
		cout << "读取第一张图片出现错误，请确认目录路径的准确，确认目录下是否有imread函数指定的图片存在！" << endl;
		return -1;
	}
	if(!g_srcImage2.data){
		cout << "读取第二张图片出现错误，请确认目录路径的准确，确认目录下是否有imread函数指定的图片存在！" << endl;
		return -1;
	}

	//设置滑动条处置
	 g_nAlphaValueSlider = 50;
	 
	 //创建窗体
	 namedWindow(WINDOW_NAME , 1);
	 namedWindow("101001011010",1);
	 //在创建的窗体内创建一个滑动条控件
	 char TrackbarName[50];
	 sprintf( TrackbarName, "透明值 %d", g_nMaxAlphaValue );
	 createTrackbar( TrackbarName, WINDOW_NAME, &g_nAlphaValueSlider, g_nMaxAlphaValue, on_Trackbar );

	 //结果在回调函数中显示
	 on_Trackbar( g_nAlphaValueSlider, 0 );
      
	 //用于查询并返回滑动条的值
     int k=getTrackbarPos(TrackbarName , WINDOW_NAME);
	 cout << k << endl;
	
      
	 

	 //任意键继续
	 waitKey(0);

	 return 0;
}
