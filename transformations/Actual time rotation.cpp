#include "stdafx.h"
#include <iostream>
#include <glut.h>
#include <glaux.h>
#include <math.h>
using namespace std;
#define pi 3.14
float hh,mm,ss;
float xh,yh,xm,ym,xs,ys,xc=0,yc=0;
float r=60,n=12; 

void mykeyboard(unsigned char key,int x,int y)
{
		if(key==27)//esc退出
		{
			exit(0);
		}
}
void myidle()
{
	Sleep(100);
	//变化变量
	SYSTEMTIME timenow;
   GetLocalTime(&timenow);
   hh=timenow.wHour;
   mm=timenow.wMinute;
   ss=timenow.wSecond;
	glutPostRedisplay();
}
void display(void)
{
/* 清楚所有像素*/
   glClear (GL_COLOR_BUFFER_BIT);

   glMatrixMode(GL_MODELVIEW);//世界坐标系
   glLoadIdentity();
   glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
   glColor3f(0.1,0.4,0.7);
   glBegin(GL_POLYGON);
	for(int i=1;i<=n;i++)
   {
		glVertex2f(r*cos(i/n*2*pi),r*sin(i/n*2*pi));
   }
   glEnd();

   glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
   glColor3f(0.7,0.4,0.7);
   glBegin(GL_POLYGON);
	for(int i=1;i<=n;i++)
   {
		glVertex2f(r*cos(i/n*2*pi),r*sin(i/n*2*pi));
   }
   glEnd();

   glColor3f(0.9,0.5,0.7);
   glPointSize(5);
   glBegin(GL_POINTS);
	for(int i=1;i<=n;i++)
   {
		glVertex2f((r-5)*cos(i/n*2*pi),(r-5)*sin(i/n*2*pi));
   }
   glEnd();

   xs=xc+50*(cos(pi/2-ss/60*2*pi));
   ys=yc+50*(sin(pi/2-ss/60*2*pi));

   xm=xc+45*cos(pi/2-(mm+ss/60.0)/60*2*pi);
   ym=yc+45*sin(pi/2-(mm+ss/60.0)/60*2*pi);

   xh=xc+40*(cos(pi/2-(hh+mm/60)/12*2*pi));
   yh=yc+40*(sin(pi/2-(hh+mm/60)/12*2*pi));
   glColor3f(1,0,0);
   glBegin(GL_LINES);
   glVertex2f(xc,yc);
   glVertex2f(xs,ys);

   glColor3f(0,1,0);
   glVertex2f(xc,yc);
   glVertex2f(xm,ym);

   glColor3f(1,0.38,0);
   glVertex2f(xc,yc);
   glVertex2f(xh,yh);


   glEnd();
 

  

/* 程序刷新*/
   glFlush ();
}

void init (void) 
{
/* 设置清除颜色	*/
   glClearColor (0.4, 0.5, 0.6, 0.0);
   SYSTEMTIME timenow;
   GetLocalTime(&timenow);
   hh=timenow.wHour;
   mm=timenow.wMinute;
   ss=timenow.wSecond;

/* 初始化视景体*/
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(-100,100,-100,100,-50,50);
}

void main(void)
{

	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize (500, 500); 
   glutInitWindowPosition (100, 100);
   glutCreateWindow ("hello");

   init ();
   glutDisplayFunc(display); 
   glutIdleFunc(myidle);
   glutKeyboardFunc(mykeyboard);
   glutMainLoop();
	getchar();
}