// 20.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <glut.h>
#include <glaux.h>
using namespace std;
float ax=0,ay=0,az=0;

//void myidle()
//{
//	Sleep(100);
//	thera+=3;
//	if(thera>360)
//	{
//		thera-=360;
//	}
//	glutPostRedisplay();
//
//}

void mySpecial(int key,int x,int y)
{
	if (key==GLUT_KEY_UP)
	{
		ax-=3;
	}
	if (key==GLUT_KEY_DOWN)
	{
		ax+=3;
	}
	if(key==GLUT_KEY_LEFT)
	{
		ay-=3;
	}
	if(key==GLUT_KEY_RIGHT)
	{
		ay+=3;
	}
	if(key==GLUT_KEY_HOME)
	{
		az-=3;
	}
	if(key==GLUT_KEY_END)
	{
		az+=3;
	}
	if((ax>360)||(ax<-360))
	{
		ax=0;
	}
	if((ay>360)||(ay<-360))
	{
		ay=0;
	}
	if((az>360)||(az<-360))
	{
		az=0;
	}
glutPostRedisplay();

}
void myKeyboard(unsigned char key,int x,int y)
{
	if(key==27)
	exit(0);
}

void display(void)
{
/* 清楚所有像素*/
   glClear (GL_COLOR_BUFFER_BIT);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glColor3f(0.5,0.4,0.7);
   glRotatef(ax,1,0,0);
   glRotatef(ay,0,1,0);
   glRotatef(az,0,0,1);
   
   glutWireSphere(40,25,25);
  


/* 程序刷新*/
   glFlush ();
}

void init (void) 
{
/* 设置清除颜色	*/
   glClearColor (0.0, 0.0, 0.0, 0.0);

/* 初始化视景体*/
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(-100,100,-100,100,-100,100);
}

void main(void)
{

	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize (500, 500); 
   glutInitWindowPosition (200, 200);
   glutCreateWindow ("hello");

   init ();
   glutDisplayFunc(display);
   glutKeyboardFunc(myKeyboard);
   glutSpecialFunc(mySpecial);
  /* glutIdleFunc(myidle);*/
   glutMainLoop();
	getchar();
}




