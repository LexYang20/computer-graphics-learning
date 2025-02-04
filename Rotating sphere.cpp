// 20.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <glut.h>
#include <glaux.h>
float theta=20;
using namespace std;

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
	theta+=3;
	glutPostRedisplay();
}
void display(void)
{
/* 清楚所有像素*/
   glClear (GL_COLOR_BUFFER_BIT);

   glMatrixMode(GL_MODELVIEW);//世界坐标系
   glLoadIdentity();

   glPointSize(5);
   glBegin(GL_POINTS);
   glVertex2f(0,0);
   glEnd();

   glPushMatrix();
   glColor3f(0.4,0.2,0.7);
   glRotatef(theta,0,0,1);
   glTranslatef(50,10,0);
   glutWireSphere(30,30,30);
   glTranslatef(-50,-10,0);
   glPopMatrix();
   
 

  

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
