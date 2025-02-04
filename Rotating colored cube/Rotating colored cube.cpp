// 5.19 lex.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include <iostream>
#include <glut.h>
#include <glaux.h>
using namespace std;

float ax=0,ay=0;


float vindex[][3]={{-50,-50,-50},{50,-50,-50},{50,50,-50},{-50,50,-50},{-50,-50,50},{50,-50,50},{50,50,50},{-50,50,50}};//按照顺序就可以,点1到点8 
float colorindex[][3]={{1,0,0},{0,1,0},{0,0,1},{0,1,1},{1,0,1},{1,1,0},{0.1,0.5,1},{1,0.5,0.2}};//按照顺序就可以,点1到点8 

void polygon(int a,int b,int c,int d)
{
	glBegin(GL_POLYGON);
	 glColor3f(colorindex[a][0],colorindex[a][1],colorindex[a][2]);
	 glVertex3f(vindex[a][0],vindex[a][1],vindex[a][2]);

	 glColor3f(colorindex[b][0],colorindex[b][1],colorindex[b][2]);
	 glVertex3f(vindex[b][0],vindex[b][1],vindex[b][2]);

	glColor3f(colorindex[c][0],colorindex[c][1],colorindex[c][2]);
	 glVertex3f(vindex[c][0],vindex[c][1],vindex[c][2]);


	 glColor3f(colorindex[d][0],colorindex[d][1],colorindex[d][2]);
	 glVertex3f(vindex[d][0],vindex[d][1],vindex[d][2]);

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
	ax+=3;
	ay+=3;
	//变化变量
	glutPostRedisplay();
}
void display(void)
{
/* 清楚所有像素*/
   glClear (GL_COLOR_BUFFER_BIT);

   glMatrixMode(GL_MODELVIEW);//世界坐标系
   glLoadIdentity();
   
 glRotatef(ax,1,0,0);
 glRotatef(ay,0,1,0);
polygon(0,1,2,3);//每个面要连在一起,一个的方向是所有的方向(比如,一个顺时针都是顺时针) 
	polygon(0,3,7,4);
		polygon(4,5,6,7);
			polygon(1,2,6,5);
				polygon(2,3,7,6);
					polygon(0,1,5,4);
  

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


 /*  glPolygon	*/



   init ();
   glutDisplayFunc(display); 
   glutIdleFunc(myidle);
   glutKeyboardFunc(mykeyboard);
   glutMainLoop();
	getchar();
}
