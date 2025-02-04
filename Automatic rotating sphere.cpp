// 20.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <glut.h>
#include <glaux.h>
using namespace std;
float thera;

void myidle()
{
	Sleep(100);
	thera+=3;
	if(thera>360)
	{
		thera-=360;
	}
	glutPostRedisplay();

}


void display(void)
{
/* 清楚所有像素*/
   glClear (GL_COLOR_BUFFER_BIT);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glColor3f(0.5,0.4,0.7);
   glutWireSphere(40,25,25);
   glRotatef(thera,1,0,1);

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
   glutIdleFunc(myidle);
   glutMainLoop();
	getchar();
}




