#include <opencv2\opencv.hpp>
#include "opencv2/highgui/highgui.hpp"
#include<iostream>

using namespace std;
using namespace cv;

#define WINDOW_NAME "�����Ի��ʵ����" //Ϊ���ڱ���ȡ����


//---------------------------��ȫ�ֱ����������֡�------------------------------------
//                            ������ȫ�ֱ�������
//-----------------------------------------------------------------------------------

const int g_nMaxAlphaValue = 100;        //Alpha�����ֵ
int g_nAlphaValueSlider;                 //��������Ӧ�ı���
double g_dAlphaValue;
double g_dBetaValue;

//��������ͼ��ı���
Mat g_dstImage;
Mat g_srcImage1;
Mat g_srcImage2;


//-------------------------------��on_Trackbar()������-----------------------------------
//                              ��������Ӧ�������Ļص�����
//---------------------------------------------------------------------------------------



void on_Trackbar(int, void* )
{
	//�����ǰAlphaֵ��������ֵ�ı���
	g_dAlphaValue = (double) g_nAlphaValueSlider/g_nMaxAlphaValue;
	
	//��beta��ֵΪ1��ȥAlpha��ֵ
	g_dBetaValue = (1.0 - g_dAlphaValue );

	//����Alpha��beta��ֵ�������Ի��
	addWeighted(g_srcImage1,g_dAlphaValue,g_srcImage2,g_dBetaValue,0.0,g_dstImage);


	//��ʾЧ��ͼ
	imshow(WINDOW_NAME,g_dstImage);
}



//----------------------------------��main����������---------------------------------------
//                      ����������̨Ӧ�ó������ں�������������￪ʼִ��
//------------------------------------------------------------------------------------------
int main( int argc , char** argv )
{
	//����ͼƬ������ͼƬ�ĳߴ���Ҫ��ͬ
	g_srcImage1 = imread("2.jpg");
	g_srcImage2 = imread("3.jpg");

	if(!g_srcImage1.data){
		cout << "��ȡ��һ��ͼƬ���ִ�����ȷ��Ŀ¼·����׼ȷ��ȷ��Ŀ¼���Ƿ���imread����ָ����ͼƬ���ڣ�" << endl;
		return -1;
	}
	if(!g_srcImage2.data){
		cout << "��ȡ�ڶ���ͼƬ���ִ�����ȷ��Ŀ¼·����׼ȷ��ȷ��Ŀ¼���Ƿ���imread����ָ����ͼƬ���ڣ�" << endl;
		return -1;
	}

	//���û���������
	 g_nAlphaValueSlider = 50;
	 
	 //��������
	 namedWindow(WINDOW_NAME , 1);
	 namedWindow("101001011010",1);
	 //�ڴ����Ĵ����ڴ���һ���������ؼ�
	 char TrackbarName[50];
	 sprintf( TrackbarName, "͸��ֵ %d", g_nMaxAlphaValue );
	 createTrackbar( TrackbarName, WINDOW_NAME, &g_nAlphaValueSlider, g_nMaxAlphaValue, on_Trackbar );

	 //����ڻص���������ʾ
	 on_Trackbar( g_nAlphaValueSlider, 0 );
      
	 //���ڲ�ѯ�����ػ�������ֵ
     int k=getTrackbarPos(TrackbarName , WINDOW_NAME);
	 cout << k << endl;
	
      
	 

	 //���������
	 waitKey(0);

	 return 0;
}
