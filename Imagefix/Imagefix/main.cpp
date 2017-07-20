//----------------------------------��ͷ�ļ��������ռ�������֡�--------------------------------------------
//                               ����������������������ͷ�ļ��������ռ�
//----------------------------------------------------------------------------------------------------------
#include<opencv2\opencv.hpp>
#include<highgui\highgui.hpp>
#include<iostream>
#include "opencv2/imgproc/imgproc.hpp"
using namespace std;
using namespace cv;


//-----------------------------------------��ȫ�ֺ����������֡�--------------------------------------------
//                                         ������ȫ�ֺ���������
//---------------------------------------------------------------------------------------------------------
bool ROI_AddImage();
bool LinearBlending();
bool ROI_LinearBlending();

//-----------------------------------------��ROI_AddImage()������--------------------------------------------
//                 ��������ROI_AddImage()
//                     ���������ø���Ȥ����ROIʵ��ͼƬ�ĵ���
//-----------------------------------------------------------------------------------------------------------
bool ROI_AddImage()
{
	//����ͼ��
	Mat srcImage1 = imread("dota_pa.jpg");
	Mat logoImage = imread("dota_logo.jpg");
	if(!srcImage1.data)
	{
		cout << "��ȡsrcImage1���ִ���" << endl;
		return 0;
	}
	if(!logoImage.data)
	{
		cout << "��ȡlogoImage���ִ���" << endl;
		return 0;
	}

	//����һ��Mat�ಢ�����趨ROI����
	Mat imageROI = srcImage1 (Rect(200,250,logoImage.cols,logoImage.rows));

	//������ģ�������ǻҶ�ͼ��
	Mat mask= imread("dota_logo.jpg",0);

	//����ģ���Ƶ�ROI
	logoImage.copyTo(imageROI,mask);

	//��ʾ���
	namedWindow("<1>����ROIʵ��ͼ�����ʵ������");
	imshow("<1>����ROIʵ��ͼ�����ʵ������",srcImage1);

	return 1;
}


//-----------------------------------------��LinearBlending()������-----------------------------------------
//                 ��������LinearBlending()
//                     ����������cv::addWeighted()����ʵ��ͼ������Ե���
//-----------------------------------------------------------------------------------------------------------
bool LinearBlending()
{
	//����һЩ�ֲ�����
	double alphaValue = 0.5;
	double betaValue;
	Mat srcImage2,srcImage3,dstImage;

	//��ȡͼ��
	srcImage2 = imread("mogu.jpg");
	srcImage3 = imread("rain.jpg");
	if(!srcImage2.data)
	{
		cout << "��ȡsrcImage2���ִ���" << endl;
		return 0;
	}
	if(!srcImage3.data)
	{
		cout << "��ȡsrcImage3���ִ���" << endl;
		return 0;
	}

	//����ͼ��Ļ�ϼ�Ȩ����
	betaValue = (1.0 - alphaValue);
	addWeighted(srcImage2,alphaValue,srcImage3,betaValue,0.0,dstImage);

	//��������ʾ����ԭͼ����
	namedWindow("<2>���Ի��ʾ�����ڡ�ԭͼ��",1);
	imshow("<2>���Ի��ʾ�����ڡ�ԭͼ��",srcImage2);

	namedWindow("<3>���Ի��ʾ�����ڡ�Ч��ͼ��",1);
	imshow("<3>���Ի��ʾ�����ڡ�Ч��ͼ��",dstImage);

	return 1;
}


//-----------------------------------------��ROI_LinearBlending()������-------------------------------------
//                 ��������ROI_LinearBlending()
//                     ���������Ի��ʵ�ֺ���
//-----------------------------------------------------------------------------------------------------------
bool ROI_LinearBlending()
{
	//��ȡͼ��
	Mat srcImage4 = imread("dota_pa.jpg",1);
	Mat logoImage = imread("dota_logo.jpg");

	if(!srcImage4.data)
	{
		cout << "��ȡsrcImage4���ִ���" << endl;
		return 0;
	}
	if(!logoImage.data)
	{
		cout << "��ȡlogoImage���ִ���" << endl;
		return 0;
	}

	//����һ��Mat�ಢ�����趨ROI����
	Mat imageROI;
	imageROI = srcImage4(Rect(200,250,logoImage.cols,logoImage.rows));

	//��logo�ӵ�ԭͼ��
	addWeighted(imageROI,0.5,logoImage,0.3,0.,imageROI);

	//��ʾ���
	namedWindow("<4>��������ͼ����ʾ������");
	imshow("<4>��������ͼ����ʾ������",srcImage4);
	return true;
}

int main()
{
	system("color 5E");
	if( ROI_AddImage() && LinearBlending() && ROI_LinearBlending() )
	{
		cout << endl << "���гɹ����õ�����Ҫ��ͼ��:)";
	//system("pause");
	waitKey(0);
	return 0;
}