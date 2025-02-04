#include "stdafx.h"
#include <iostream>
#include <glut.h>
#include <glaux.h>
using namespace std;
//float x1=0,y1=0;                           //起点坐标
//float x2=0,y2=0;                       //终点坐标
int line[1000][4],n;
float hh;

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

   glBegin(GL_LINES);                      //画线
	//glVertex2d(x1,y1);
	//glVertex2d(x2,y2);
   for(int i=0;i<=n;i++)
   {
		glVertex2d(line[i][0],line[i][1]);
		glVertex2d(line[i][2],line[i][3]);

   }
   glEnd();

  

/* 程序刷新*/
   glFlush ();
}
void motion(int x,int y)
{
	line[n][2]=x;
	line[n][3]=hh-y;
	glutPostRedisplay();
}

void mouse(int button,int state,int x,int y)                                 //鼠标响应子函数
{
	if(button==GLUT_LEFT_BUTTON&&state==GLUT_DOWN)
	{
		line[n][0]=x;
		line[n][1]=hh-y; 
		line[n][2]=x;
		line[n][3]=hh-y;
	}
	if(button==GLUT_LEFT_BUTTON&&state==GLUT_UP)
	{
		line[n][2]=x;
		line[n][3]=hh-y;    
		n++;
	}

}

void init (void) 
{
/* 设置清除颜色	*/
   glClearColor (0.0, 0.0, 0.0, 0.0);

/* 初始化视景体*/
   
}

void reshape(int w,int h)
{
	glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
	glViewport(0,0,w,h);
   glOrtho(0,w,0,h,-50,50);
   hh=h;

}

void main(void)
{

	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize (500, 500); 
   glutInitWindowPosition (100, 100);
   glutCreateWindow ("hello");

   init ();
   glutReshapeFunc(reshape);                                //reshape函数需要在display函数前调用
   glutDisplayFunc(display); 
   glutIdleFunc(myidle);
   glutMouseFunc(mouse);
   glutMotionFunc(motion);
   glutKeyboardFunc(mykeyboard);
   glutMainLoop();
	getchar();
}
