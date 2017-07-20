//----------------------------------【头文件、命名空间包含部分】--------------------------------------------
//                               描述：包含程序所依赖的头文件和命名空间
//----------------------------------------------------------------------------------------------------------
#include<opencv2\opencv.hpp>
#include<highgui\highgui.hpp>
#include<iostream>
#include "opencv2/imgproc/imgproc.hpp"
using namespace std;
using namespace cv;


//-----------------------------------------【全局函数声明部分】--------------------------------------------
//                                         描述：全局函数的声明
//---------------------------------------------------------------------------------------------------------
bool ROI_AddImage();
bool LinearBlending();
bool ROI_LinearBlending();

//-----------------------------------------【ROI_AddImage()函数】--------------------------------------------
//                 函数名：ROI_AddImage()
//                     描述：利用感兴趣区域ROI实现图片的叠加
//-----------------------------------------------------------------------------------------------------------
bool ROI_AddImage()
{
	//读入图像
	Mat srcImage1 = imread("dota_pa.jpg");
	Mat logoImage = imread("dota_logo.jpg");
	if(!srcImage1.data)
	{
		cout << "读取srcImage1出现错误！" << endl;
		return 0;
	}
	if(!logoImage.data)
	{
		cout << "读取logoImage出现错误！" << endl;
		return 0;
	}

	//定义一个Mat类并给其设定ROI区域
	Mat imageROI = srcImage1 (Rect(200,250,logoImage.cols,logoImage.rows));

	//加载掩模（必须是灰度图）
	Mat mask= imread("dota_logo.jpg",0);

	//将掩模复制到ROI
	logoImage.copyTo(imageROI,mask);

	//显示结果
	namedWindow("<1>利用ROI实现图像叠加实例窗口");
	imshow("<1>利用ROI实现图像叠加实例窗口",srcImage1);

	return 1;
}


//-----------------------------------------【LinearBlending()函数】-----------------------------------------
//                 函数名：LinearBlending()
//                     描述：利用cv::addWeighted()函数实现图像的线性叠加
//-----------------------------------------------------------------------------------------------------------
bool LinearBlending()
{
	//定义一些局部变量
	double alphaValue = 0.5;
	double betaValue;
	Mat srcImage2,srcImage3,dstImage;

	//读取图像
	srcImage2 = imread("mogu.jpg");
	srcImage3 = imread("rain.jpg");
	if(!srcImage2.data)
	{
		cout << "读取srcImage2出现错误！" << endl;
		return 0;
	}
	if(!srcImage3.data)
	{
		cout << "读取srcImage3出现错误！" << endl;
		return 0;
	}

	//进行图像的混合加权操作
	betaValue = (1.0 - alphaValue);
	addWeighted(srcImage2,alphaValue,srcImage3,betaValue,0.0,dstImage);

	//创建并显示窗口原图窗口
	namedWindow("<2>线性混合示例窗口【原图】",1);
	imshow("<2>线性混合示例窗口【原图】",srcImage2);

	namedWindow("<3>线性混合示例窗口【效果图】",1);
	imshow("<3>线性混合示例窗口【效果图】",dstImage);

	return 1;
}


//-----------------------------------------【ROI_LinearBlending()函数】-------------------------------------
//                 函数名：ROI_LinearBlending()
//                     描述：线性混合实现函数
//-----------------------------------------------------------------------------------------------------------
bool ROI_LinearBlending()
{
	//读取图像
	Mat srcImage4 = imread("dota_pa.jpg",1);
	Mat logoImage = imread("dota_logo.jpg");

	if(!srcImage4.data)
	{
		cout << "读取srcImage4出现错误！" << endl;
		return 0;
	}
	if(!logoImage.data)
	{
		cout << "读取logoImage出现错误！" << endl;
		return 0;
	}

	//定义一个Mat类并给其设定ROI区域
	Mat imageROI;
	imageROI = srcImage4(Rect(200,250,logoImage.cols,logoImage.rows));

	//将logo加到原图上
	addWeighted(imageROI,0.5,logoImage,0.3,0.,imageROI);

	//显示结果
	namedWindow("<4>区域线性图像混合示例窗口");
	imshow("<4>区域线性图像混合示例窗口",srcImage4);
	return true;
}

int main()
{
	system("color 5E");
	if( ROI_AddImage() && LinearBlending() && ROI_LinearBlending() )
	{
		cout << endl << "运行成功，得到所需要的图像！:)";
	//system("pause");
	waitKey(0);
	return 0;
}