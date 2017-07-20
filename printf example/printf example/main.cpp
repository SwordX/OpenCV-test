#include<opencv2\opencv.hpp>

using namespace cv;
//  \t 为Tab字符
void main()
{
	int a=66,b=68;
	printf("\n\t%d %d\n",a,b);//输出十进制整数
	printf("\n\t%07d,%06d\n",a,b);//输出7位、6位十进制整数
	printf("\n\t%c %c\n",a,b);//按字符型输出
	printf("\n\t结果为：a=%d,b=%d",a,b);//配合其他内容一起输出
	getchar();//等待输入任意字符结束，用于保存窗口显示，按任意键结束
}