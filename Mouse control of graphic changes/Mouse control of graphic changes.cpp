// 11.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <glut.h>
using namespace std;
float x1=-50,y1=-20;
float x2=30,y2=40;
float x3=-20,y3=40;
int flag=0;


void mouse(int button,int state,int x,int y)
{
	if(button==GLUT_LEFT_BUTTON&&state==GLUT_DOWN)
	{
		flag=flag%3+1;
	}
	glutPostRedisplay();

}

void myKeyBoard(unsigned char key,int x,int y)
{
	if(key==27)
	{
		exit(0);
	}
	if(key=='1')
	{
		flag=1;
	}
	if(key=='2')
	{
		flag=2;
	}
	if(key=='3')
	{
		flag=3;
	}
	glutPostRedisplay();
}

void display(void)
{
/* 清楚所有像素*/
   glClear (GL_COLOR_BUFFER_BIT);
	switch (flag)
	{case 1:
			glColor3f(0.2,0.5,0.8);
			glRectf(x1,y1,x2,y2);
			break;
	case 2:
			glColor3f(0.9,0.0,0.0);
			glBegin(GL_LINES);
			glVertex2f(x1,y1);
			glVertex2f(x2,y2);
			glEnd();
			break;
	case 3:
			glColor3f(0.0,1.0,0.0);
			glBegin(GL_LINE_LOOP);
				glVertex2f(x1,y1);
				glVertex2f(x2,y2);
				glVertex2f(x3,y3);
				glEnd();
	}



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
   glutInitWindowPosition (100, 100);
   glutCreateWindow ("hello");

   init ();
   glutDisplayFunc(display); 
   glutKeyboardFunc(myKeyBoard);
   glutMouseFunc(mouse);
   glutMainLoop();
	getchar();
}