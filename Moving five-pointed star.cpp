// 20.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <glut.h>
#include <glaux.h>
using namespace std;

float a=5;
float bx=4.5,by=2;
float cx=3,cy=-4.8;
int ax=0,ay=0;

void myidle()
{
	Sleep(100);
	ax+=1;
	if(ax>8)
	{
		ax-=15;
	}
	ay+=0.4;
	if(ay>8)
	{
		ay-=15;
	}
	glutPostRedisplay();

}

void display(void)
{
/* �����������*/
   glClear (GL_COLOR_BUFFER_BIT);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glColor3f(0.5,0.4,0.7);
   glTranslatef(ax,ay,0);
   glPushMatrix();
	   glBegin(GL_LINE_LOOP);
	   glVertex2f(-bx,by);
	   glVertex2f(bx,by);
	   glVertex2f(-cx,cy);
	   glVertex2f(0,a);
	   glVertex2f(cx,cy);
	   glEnd();
	glPopMatrix();
	glTranslatef(-ax,-ay,0);
	


   
   
   /*glutWireSphere(5,25,25);
   glRotatef(30,1,1,0);
   glRotatef(a,0,1,0);
	*/

/* ����ˢ��*/
   glFlush ();
}

void init (void) 
{
/* ���������ɫ	*/
   glClearColor (0.0, 0.0, 0.0, 0.0);

/* ��ʼ���Ӿ���*/
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(-10,10,-10,10,-5,5);
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


