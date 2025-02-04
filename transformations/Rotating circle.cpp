// 11.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <glut.h>
#include <glaux.h>
using namespace std;

int a;

void myidle()
{
  Sleep(100);
  a+=3;
  glutPostRedisplay();
}

void display(void)
{
/* 清楚所有像素*/

   glClear (GL_COLOR_BUFFER_BIT);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
	glColor3f(0.1,0.0,0.7);
	glRotatef(30,1,0,1);
	glRotatef(a,1,1,0);
	glutWireSphere(50,25,25);



/* 程序刷新*/
   glFlush ();
}

void init (void) 
{
/* 设置清除颜色	*/
   glClearColor (0.2, 0.5, 0.8, 0.5);

/* 初始化视景体*/
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(-100,100,-100,100,-50,50);
}

void main(void)
{

	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize (250, 250); 
   glutInitWindowPosition (100, 100);
   glutCreateWindow ("hello");

   init ();
   glutDisplayFunc(display); 
   glutIdleFunc(myidle);
   glutMainLoop();
	getchar();
}
