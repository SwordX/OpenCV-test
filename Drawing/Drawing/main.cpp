//-------------------------------【头文件、命名空间】-------------------------------------
//                    描述：包含程序所使用的头文件和命名空间
//----------------------------------------------------------------------------------------
#include<opencv2\core\core.hpp>
#include<opencv2\highgui\highgui.hpp>
#include<opencv2\imgproc\imgproc.hpp>
using namespace cv;


//-------------------------------【宏定义部分】-------------------------------------------
//                            描述：定义一些辅助宏
//----------------------------------------------------------------------------------------
#define WINDOW_NAME1 "原子示意图"
#define WINDOW_NAME2 "组合图"
#define WINDOW_WIDTH 600       //定义窗口的宏


//-------------------------------【DrawEllipse（）函数】----------------------------------
//                     描述：自定义的绘制函数，实现了绘制不同角度、相同尺寸的椭圆
//----------------------------------------------------------------------------------------
void DrawEllipse(Mat img, double angle)
{
	int thickness = 2;
	int lineType = 8;

	//调用OpenCV中的ellipse函数
	ellipse(img,                                 //将椭圆画到图像img上
		Point(WINDOW_WIDTH/2, WINDOW_WIDTH/2 ),  //椭圆中心点为 （WINDOW_WIDTH/2, WINDOW_WIDTH/2）
		Size(WINDOW_WIDTH/4, WINDOW_WIDTH/16 ),  //椭圆的大小在矩形 （WINDOW_WIDTH/4, WINDOW_WIDTH/16 ）内
		angle,                                   //椭圆旋转角度为angle
		0,360,                                   //扩展的弧度从0度到360度
		Scalar(255,129,0),                       //图片的颜色为Scalar（255,129,0）代表的蓝色
		thickness,                               //线宽
		lineType                                 //线性 为 8 （8联通线性）
		);
}


//-------------------------------【DrawFilledCircle()函数】----------------------------------
//                     描述：自定义的绘制函数，实现同心圆的绘制
//-------------------------------------------------------------------------------------------
void DrawFilledCircle(Mat img, Point center)
{
	int thickness = -1;
	int lineType = 8;

	//调用OpenCV中的circle函数
	circle(img,       
		center,                  //圆心点由center定义
		WINDOW_WIDTH/32,         //圆的半径
		Scalar(0,0,255),         //颜色，按照BGR格式为红色
		thickness,               //线粗定义为 -1   所以是实线
		lineType
		);
}


//-------------------------------【DrawPolygon()函数】----------------------------------
//                     描述：自定义的绘制函数，实现凹多边形的绘制
//--------------------------------------------------------------------------------------
void DrawPolygon( Mat img )
{
	int lineType = 8;
	
	//创建一些点
	Point rookPoints[1][20];
	rookPoints[0][0] = Point(WINDOW_WIDTH/4 , 7*WINDOW_WIDTH/8);
	rookPoints[0][1] = Point(3*WINDOW_WIDTH/4 , 7*WINDOW_WIDTH/8);
	rookPoints[0][2] = Point(3*WINDOW_WIDTH/4 , 13*WINDOW_WIDTH/16);
	rookPoints[0][3] = Point(11*WINDOW_WIDTH/16 , 13*WINDOW_WIDTH/16);
	rookPoints[0][4] = Point(19*WINDOW_WIDTH/32 , 3*WINDOW_WIDTH/8);
	rookPoints[0][5] = Point(3*WINDOW_WIDTH/4 , 3*WINDOW_WIDTH/8);
	rookPoints[0][6] = Point(3*WINDOW_WIDTH/4 , WINDOW_WIDTH/8);
	rookPoints[0][7] = Point(26*WINDOW_WIDTH/40 ,WINDOW_WIDTH/8);
	rookPoints[0][8] = Point(26*WINDOW_WIDTH/40 ,WINDOW_WIDTH/4);
	rookPoints[0][9] = Point(22*WINDOW_WIDTH/40 ,WINDOW_WIDTH/4);
	rookPoints[0][10] = Point(22*WINDOW_WIDTH/40 ,WINDOW_WIDTH/8);
	rookPoints[0][11] = Point(18*WINDOW_WIDTH/40 ,WINDOW_WIDTH/8);
	rookPoints[0][12] = Point(18*WINDOW_WIDTH/40 ,WINDOW_WIDTH/4);
	rookPoints[0][13] = Point(14*WINDOW_WIDTH/40 ,WINDOW_WIDTH/4);
	rookPoints[0][14] = Point(14*WINDOW_WIDTH/40 ,WINDOW_WIDTH/8);
	rookPoints[0][15] = Point(WINDOW_WIDTH/4 ,WINDOW_WIDTH/8);
	rookPoints[0][16] = Point(WINDOW_WIDTH/4 ,3*WINDOW_WIDTH/8);
	rookPoints[0][17] = Point(13*WINDOW_WIDTH/32 ,3*WINDOW_WIDTH/8);
	rookPoints[0][18] = Point(5*WINDOW_WIDTH/16 ,13*WINDOW_WIDTH/16);
	rookPoints[0][19] = Point(WINDOW_WIDTH/4 ,13*WINDOW_WIDTH/16);

	const Point* ppt[1] = {rookPoints[0]};
	int npt[] = {20};

	//调用OpenCV的fillPoly函数
	fillPoly(img,
		ppt,        //多边形顶点集
		npt,        //要绘制的多边形定点数目
		1,          //绘制一个多边形
		Scalar(255,255,255),    //白色
		lineType
		);
}


//-------------------------------【DrawLine()函数】----------------------------------
//                     描述：自定义的绘制函数，实现线的绘制
//------------------------------------------------------------------------------------
void DrawLine(Mat img,Point start,Point end)
{
	int thickness = 2;
	int lineType = 8;
	//调用OpenCV的line函数
	line(img,
		start,
		end,
		Scalar(0,0,0),   //黑色
		thickness,
		lineType
		);
}

//-------------------------------【main()函数】-----------------------------------------
//                     描述：控制台应用程序的入口，程序从这里开始
//--------------------------------------------------------------------------------------
int main(void)
{
	//创建空白的Mat图像
	Mat atomImage = Mat::zeros(WINDOW_WIDTH,WINDOW_WIDTH,CV_8UC3);
	Mat rookImage = Mat::zeros(WINDOW_WIDTH,WINDOW_WIDTH,CV_8UC3);

	//=====================绘制化学中的原子示意图================================

	//----------------------------<1>先绘制椭圆-------------------------------------
	DrawEllipse(atomImage,90);
	//DrawEllipse(atomImage,150);
	DrawEllipse(atomImage,0);
	DrawEllipse(atomImage,45);
	DrawEllipse(atomImage,315);

	//----------------------------<2>绘制圆心--------------------------------------------
	DrawFilledCircle(atomImage , Point(WINDOW_WIDTH/2, WINDOW_WIDTH/2));


	//===================================绘制组合图===========================================

	//-------------------------<1>先绘制多边形------------------------------------------------
	DrawPolygon(rookImage);

	//-------------------------<2>绘制矩形------------------------------------------------
	rectangle(rookImage,
		Point(0,7*WINDOW_WIDTH/8),
		Point(WINDOW_WIDTH,WINDOW_WIDTH),
		Scalar(0,255,255),
		8
		);

	//-------------------------------<3>绘制一些线段-----------------------------------------
	DrawLine(rookImage, Point(0, 15*WINDOW_WIDTH/16), Point(WINDOW_WIDTH, 15*WINDOW_WIDTH/16));
	DrawLine(rookImage, Point(WINDOW_WIDTH/4, 7*WINDOW_WIDTH/8), Point(WINDOW_WIDTH/4, WINDOW_WIDTH));
	DrawLine(rookImage, Point(WINDOW_WIDTH/2, 7*WINDOW_WIDTH/8), Point(WINDOW_WIDTH/2, WINDOW_WIDTH));
	DrawLine(rookImage, Point(3*WINDOW_WIDTH/4, 7*WINDOW_WIDTH/8), Point(3*WINDOW_WIDTH/4, WINDOW_WIDTH));

	//------------------------------------------显示绘制图像-------------------------------
	imshow(WINDOW_NAME1,atomImage);
	moveWindow(WINDOW_NAME1,0,200);
	imshow(WINDOW_NAME2,rookImage);
	moveWindow(WINDOW_NAME2,WINDOW_WIDTH,200);

	waitKey(0);
	return(0);
}