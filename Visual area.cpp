// 20.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <glut.h>
#include <glaux.h>
using namespace std;

void triangle(int mode)
{
	switch(mode)
	{
	case 1:
		glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
		break;
	case 2:
		glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
		break;	
	}
	glBegin(GL_POLYGON);
		glVertex2f(-5,-5);
		glVertex2f(5,-5);
		glVertex2f(0,5);
	glEnd();


}


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
	glutPostRedisplay();
}
void display(void)
{
/* 清楚所有像素*/
   glClear (GL_COLOR_BUFFER_BIT);

   glMatrixMode(GL_MODELVIEW);//世界坐标系
   glLoadIdentity();
   glColor3f(1,0,0);
   glViewport(0,100,300,300);
   triangle(1);
   glColor3f(0,1,0);
   glViewport(200,0,200,200);
   triangle(2);

   
   
 

  

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
  

   glOrtho(-10,10,-10,10,-5,5);
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
