#include<opencv2\opencv.hpp>

using namespace cv;
//  \t ΪTab�ַ�
void main()
{
	int a=66,b=68;
	printf("\n\t%d %d\n",a,b);//���ʮ��������
	printf("\n\t%07d,%06d\n",a,b);//���7λ��6λʮ��������
	printf("\n\t%c %c\n",a,b);//���ַ������
	printf("\n\t���Ϊ��a=%d,b=%d",a,b);//�����������һ�����
	getchar();//�ȴ����������ַ����������ڱ��洰����ʾ�������������
}