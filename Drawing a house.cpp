#include "stdafx.h"
#include <iostream>
#include "glut.h"  
int flag=0;

void keyboard(unsigned char key,int x,int y)
{
	if(key==27)
	{
		exit(0);
	}
	
	if(key=='0')
	{
		flag=0;
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
	if(key=='4')
	{
		flag=4;
	}
	
	glutPostRedisplay();
}

//��ʾ �ص�����  
void display(void)  
{  
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  
  
   
    glMatrixMode(GL_MODELVIEW);  
    glLoadIdentity();  


	if(flag==0)
	{
		goto l;
	}
	glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
	glColor3f(0,1,1);
	glRectf(-50,-50,50,50);
	if(flag==1)
	{
		goto l;
	}

	glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
	glColor3f(1,0,1);
	glRectf(-50,-50,50,50);
	if(flag==2)
	{
		goto l;
	}

	glColor3f(0.4,0.2,0.6);
	glBegin(GL_TRIANGLES);
		glVertex2f(-50,50);
		glVertex2f(50,50);
		glVertex2f(0,90);
	glEnd();
	if(flag=3)
	{
		goto l;
	}

	glColor3f(1,1,0);
	glRectf(-10,-10,10,10);
	if(flag==4)
	{
		goto l;
	}
  
	
l:
	glutSwapBuffers();  //ˢ��
}  

//���ڳߴ�仯��Ļص�����  
void reshape(int w,int h)  
{  
    glViewport(0, 0, w, h);  
    glMatrixMode(GL_PROJECTION); //����ǰ����ָ��ΪͶӰģʽ  
    glLoadIdentity();  
   
    glOrtho(-100,100,-100,100,-100,100);//���òü�����
     
}  
  
//���̰�������ص�����


void main()  
{  
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);  
    glutInitWindowSize(600, 480);  
    glutCreateWindow("OpenGL Program");  
  
    glutReshapeFunc(reshape);  
    glutDisplayFunc(display);  
	glutKeyboardFunc(keyboard);
    glutMainLoop();  
}
