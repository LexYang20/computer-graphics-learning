#include "stdafx.h"
#include <iostream>
#include <glut.h>
#include <glaux.h>
using namespace std;
//float x1=0,y1=0;                           //�������
//float x2=0,y2=0;                       //�յ�����
int line[1000][4],n;
float hh;

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
	glutPostRedisplay();
}
void display(void)
{
/* �����������*/
   glClear (GL_COLOR_BUFFER_BIT);

   glMatrixMode(GL_MODELVIEW);//��������ϵ
   glLoadIdentity();

   glBegin(GL_LINES);                      //����
	//glVertex2d(x1,y1);
	//glVertex2d(x2,y2);
   for(int i=0;i<=n;i++)
   {
		glVertex2d(line[i][0],line[i][1]);
		glVertex2d(line[i][2],line[i][3]);

   }
   glEnd();

  

/* ����ˢ��*/
   glFlush ();
}
void motion(int x,int y)
{
	line[n][2]=x;
	line[n][3]=hh-y;
	glutPostRedisplay();
}

void mouse(int button,int state,int x,int y)                                 //�����Ӧ�Ӻ���
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
/* ���������ɫ	*/
   glClearColor (0.0, 0.0, 0.0, 0.0);

/* ��ʼ���Ӿ���*/
   
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
   glutReshapeFunc(reshape);                                //reshape������Ҫ��display����ǰ����
   glutDisplayFunc(display); 
   glutIdleFunc(myidle);
   glutMouseFunc(mouse);
   glutMotionFunc(motion);
   glutKeyboardFunc(mykeyboard);
   glutMainLoop();
	getchar();
}
