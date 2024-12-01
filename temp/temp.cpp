#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<time.h>
#include<windows.h>
#include<graphics.h>
#include<mmsystem.h>//要调用mciSendString必须包含这个头文件
#pragma comment(lib,"WINMM.LIB");//及这个预处理
#define SIZE 9
#define CANVAS_WIDTH 640
#define CANVAS_HEIGHT 480
#define CANVAS_CEBTER_X CANVAS_WIDTH / 2
#define CANVAS_CEBTER_Y CANVAS_HEIGHT / 2
void scatter_inside(int xo, int yo, double beta = 0.1)
{
	//随机内部扩散
	double ratio_x = -beta * log(rand());
	double ratio_y = beta * log(rand());
	double x, y;
	x = ratio_x * xo;
	y = ratio_y * yo;
	putpixel(x, y, RGB(245,145,247));
}
void heart(int particle,double ratio,COLORREF color)
{
	double x, y;//记录直角坐标
	double i;//控制循环和心的精细程度
	//笛卡尔爱心
	//for (i = 0; i <= 2 * size; i += 0.1)
	//{
	//	m = i;
	//	n = -size * (((sin(i) * sqrt(fabs(cos(i)))) / (sin(i) + 1.4142)) - 2 * sin(i) + 2);
	//	x = n * cos(m) + xo;
	//	y = n * sin(m) + yo;
	//	putpixel(x, y, color);
	//}
	for (i = 0; i <= 2 * particle; i += 0.001)
	{
		//关键，画爱心的公式
		x = 16 * (sin(i) * sin(i)* sin(i));
		y = -(13 * cos(i) - 5 * cos(2 * i) - 2 * cos(3 * i) - cos(4 * i));
		//控制爱心的大小
		x = x * ratio;
		y = y * ratio;
		putpixel(x, y, color);
		//扩散
		if((int)(i*10000)% 7 == 0)//扩散粒子太多了，控制粒子产生量
		scatter_inside(x, y);
		if ((int)(i * 10000) % 107 == 0)
		scatter_inside(x, y, 0.07);
		//爱心里面加字
		settextcolor(RGB(91, 176, 179));//设置爱心字体颜色
		settextstyle(40, 0, L"楷体");
		outtextxy(0, 0, L"喵");
	}
 
}
 
int main()
{
	srand(time(0));
	initgraph(CANVAS_WIDTH, CANVAS_HEIGHT);
	//添加音乐
	mciSendString(L"open youhebuke.mp3 alias music", 0, 0, 0);
	mciSendString(L"play music repeat",0,0,0);//+repeat循环播放
// -----------------------------------------------------------------------------------------
             //开头界面，可删除
		settextcolor(RGB(245,152,173));//颜色参数调配，画图板查看颜色参数
		settextstyle(15, 0, L"宋体");
		outtextxy(300, 300, L"----被虐的喵");
		settextcolor(RGB(91, 176, 179));//颜色参数调配，画图板查看颜色参数
		settextstyle(40, 0, L"楷体");
		outtextxy(175, 180, L"C/C++版跳动爱心");
		fflush(stdout);
		Sleep(10000);
 
		cleardevice();//清画布，重新画
// -----------------------------------------------------------------------------------------
	setorigin(CANVAS_CEBTER_X, CANVAS_CEBTER_Y);
	//循环播放
	while (1)
	{
 
		double ratio;//控制粒子频率和图像大小
		for (int i = 140; i <= 250; i++)
		{
			ratio = 16 * sin(i / 360.0 * 3.1415926535);
		}
		
		if (ratio < 0)
		{
			ratio *= -1;
     	}
		//Sleep(10);
		heart(80, ratio, RED);
		cleardevice();
		
	}
	mciSendString(L"close music", 0, 0, 0);
	getchar();
	closegraph();
	return 0;
}