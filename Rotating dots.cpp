// 11.cpp : �������̨Ӧ�ó������ڵ㡣
//
#include "stdafx.h"
#include <iostream>
#include <glut.h>
#include <glaux.h>
#include <math.h>
#define pi 3.14

float r=30;
float z; 
float ax=0,ay=0; 
using namespace std;


void mykeyboard(unsigned char key,int x,int y)
{
		if(key==27)//esc�˳�
		{
			exit(0);
		}
}
void myidle()
{
	Sleep(100);
	//�仯����
	ax+=1;
	ay+=1;
	glutPostRedisplay();
}
void display(void)
{
/* �����������*/
   glClear (GL_COLOR_BUFFER_BIT);

   glMatrixMode(GL_MODELVIEW);//��������ϵ
   glLoadIdentity();

   gluLookAt(0,30,-100,0,0,0,0,1,0);
   int flag=0;

   glRotatef(ay,0,1,0);
   glRotatef(ax,1,0,0);
   z=0;
   glBegin(GL_LINES);
		for(float n=0;n<2*pi*4;n+=pi/20)
		{
			if(flag==1)
			{
				glColor3f(0,1,1);
			}
			else
			{
				glColor3f(1,1,0);
			}
			glVertex3f(r*cos(n),r*sin(n),z);
			glVertex3f(0,0,0);
			flag=(flag+1)%2;
		}
		glEnd();
		{
			glVertex3f(r*cos(i),r*sin(i),z);
			z+=0.5;
		}
	glEnd();
  

/* ����ˢ��*/
   glFlush ();
}

void init (void) 
{
/* ���������ɫ	*/
   glClearColor (0.0, 0.1, 0.6, 0.0);

/* ��ʼ���Ӿ���*/
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
   glutIdleFunc(myidle);
   glutKeyboardFunc(mykeyboard);
   glutMainLoop();
	getchar();
}
