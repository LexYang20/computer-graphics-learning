#include "stdafx.h"
#include <iostream>
#include <glaux.h>
#include "glut.h"  
float ay=0,sy=0;
float ex=0,ez=100;

void specialKey(int key,int x,int y)
{
	if(key==GLUT_KEY_UP)
	{
		ez-=3;
	}
	if(key==GLUT_KEY_DOWN)
	{
		ez+=3;
	}
	if(key==GLUT_KEY_LEFT)
	{
		ex-=3;
	}
	if(key==GLUT_KEY_RIGHT)
	{
		ex+=3;
	}
	glutPostRedisplay();
}

void myidle(){
	Sleep(100);
	ay+=2;
	sy+=3;
	glutPostRedisplay();
}

void draw(){
    glColor3f(0,0.5,0);
	glutWireTeapot(15);

	glPushMatrix();
		glColor3f(0.5,0.4,0.7);
		glRotatef(ay,0,1,0);
		glutWireTorus(7,40,30,30);
	glPopMatrix();

	glPushMatrix();
	glRotatef(ay,0,1,0);

	glTranslatef(33,0,0);
	glRotatef(sy,0,1,0);
	glTranslatef(-33,0,0);

	glTranslatef(55,0,0);
	glColor3f(0.1,0.5,0.2);
	glutWireSphere(5,30,30);
	glTranslatef(-55,0,0);

	
	glPopMatrix();

}
void ground(){
	int x,y,z;
	y=-100;
	for(x=-100;x<=100;x+=10)
	{
		for(z=-100;z<=100;z+=10)
		{
			glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
			glBegin(GL_QUADS);
				glVertex3f(x,y,z);
				glVertex3f(x,y,z+10);
				glVertex3f(x+10,y,z+10);
				glVertex3f(x+10,y,z);
			glEnd();
		
		}
	}

	y=100;
	for(x=-100;x<=100;x+=10)
	{
		for(z=-100;z<=100;z+=10)
		{
			glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
			glBegin(GL_QUADS);
				glVertex3f(x,y,z);
				glVertex3f(x,y,z+10);
				glVertex3f(x+10,y,z+10);
				glVertex3f(x+10,y,z);
				glEnd();
		}
	}

	x=-100;
	for(y=-100;y<=90;y+=10)
		for(z=-100;z<=100;z+=10)
		{
			glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
			glBegin(GL_QUADS);
				glVertex3f(x,y,z);
				glVertex3f(x,y+10,z);
				glVertex3f(x,y+10,z+10);
				glVertex3f(x,y,z+10);
				glEnd();
		
		}

	x=100;
	for(y=-90;y<=80;y+=10)
		for(z=-80;z<=80;z+=10)
		{
			glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
			glBegin(GL_QUADS);
				glVertex3f(x,y,z);
				glVertex3f(x,y+10,z);
				glVertex3f(x,y+10,z+10);
				glVertex3f(x,y,z+10);
			glEnd();
		
		}
}


//显示 回调函数  
void display(void)  
{  
	glClearColor(1,1,1,0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  
	
  
   
    glMatrixMode(GL_MODELVIEW);  
    glLoadIdentity(); 
	gluLookAt(ex,0,ez,0,0,0,0,1,0);

	draw();
	ground();

	

	

  
  
    glutSwapBuffers();  //刷新
}  

//窗口尺寸变化后的回调函数  
void reshape(int w,int h)  
{  
	
    glViewport(0, 0, w, h);  
    glMatrixMode(GL_PROJECTION); //将当前矩阵指定为投影模式  
    glLoadIdentity();  
	
   
    gluPerspective(90,w/h,1,200);//设置裁剪窗口
     
}  
  
//键盘按键处理回调函数
void keyboard(unsigned char key,int x,int y)
{
	if(key==27)//ESC键退出程序
	{
		exit(0);
	}
}

void main()  
{  
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);  
    glutInitWindowSize(600, 480);  
    glutCreateWindow("OpenGL Program");  
  
    glutReshapeFunc(reshape); 
	glutSpecialFunc(specialKey);
    glutDisplayFunc(display); 
	glutIdleFunc(myidle);
	
	glutKeyboardFunc(keyboard);
    glutMainLoop();  
}
