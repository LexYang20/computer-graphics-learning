#include "stdafx.h"
#include <iostream>
#include <math.h>
#include <glut.h>
#include <glaux.h>
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
	gluLookAt(0,-30,100,0,0,0,0,1,0);

   glRotatef(ax,1,0,0);
   /*glRotatef(ay,0,1,0);*/
   glColor3f(1,1,0);
   int flag=0;
   z=0;
   glBegin(GL_LINES);
	for(float i=0;i<2*pi*4;i+=pi/20)
	{

		if(flag==1)
		{
			glColor3f(1,1,0);
		}
		if(flag==0)
		{
			glColor3f(0,1,1);
		}

		glVertex3f(r*cos(i),r*sin(i),z);
		glVertex3f(0,0,0);
		z+=0.5;
		flag=(flag+1)%2;
	}
   glEnd();
   
 

  

/* ����ˢ��*/
   glutSwapBuffers();                 //����1
}

void init (void)                        //����2
{
 //���������ɫ	
   glClearColor (0, 0.1, 0.6, 0.0);    

/* ��ʼ���Ӿ���*/
   
}

void reshape(int w,int h)  
{  
    glViewport(0, 0, w, h);  
    glMatrixMode(GL_PROJECTION); //����ǰ����ָ��ΪͶӰģʽ  
    glLoadIdentity();  
    if (0 != h)  
    {  
        GLfloat aspect =(float)w / (float)h;  
  
        gluPerspective(90.0f, aspect, 1.0f, 200.0f); //͸��ͶӰ  
    }  
}                                                      //����3
void main(void)
{

	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB|GLUT_DEPTH);         //����4
   glutInitWindowSize (500, 500); 
   glutInitWindowPosition (100, 100);
   glutCreateWindow ("hello");

   init ();
   glutReshapeFunc(reshape);
   glutDisplayFunc(display); 
   glutIdleFunc(myidle);
   glutKeyboardFunc(mykeyboard);
   glutMainLoop();
	getchar();
}
