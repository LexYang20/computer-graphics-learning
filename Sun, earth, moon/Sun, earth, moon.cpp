#include "stdafx.h"
#include <iostream>
#include "glut.h"  
#include <glaux.h>
float as;
float ae;
void drawSphere(int x,int y,int z,int r)
{
	glPushMatrix();
		glTranslatef(x,y,z);
		glutSolidSphere(r,30,30);
	glPopMatrix();
}

void ground()
{	
	GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
   GLfloat mat_ambient[] = { 0.7, 0.7, 0.7, 1.0 };
   GLfloat mat_ambient_color[] = { 0.8, 0.8, 0.2, 1.0 };
   GLfloat mat_diffuse[] = { 0.1, 0.5, 0.8, 1.0 };
   GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
   GLfloat no_shininess[] = { 0.0 };//没有高光
   GLfloat low_shininess[] = { 5.0 };//低光
   GLfloat high_shininess[] = { 100.0 };//高光
   GLfloat mat_emission[] = {0.3, 0.2, 0.2, 0.0};

   glMaterialfv(GL_FRONT, GL_AMBIENT, no_mat);
   glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
   glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
   glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
   glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);

	glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
	int x,y,z;
	for(x=-100,y=-100;x<=100;x+=10)
	{
		for(z=-100;z<=100;z+=10)
		{
			glBegin(GL_QUADS);
				glVertex3f(x,y,z);
				glVertex3f(x,y,z+10);
				glVertex3f(x+10,y,z+10);
				glVertex3f(x+10,y,z);
			glEnd();
		}
	}
	
	 glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
   glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
   glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);
   glMaterialfv(GL_FRONT, GL_SHININESS, no_shininess);
   glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
	for(x=-100,y=100;x<=100;x+=10)
	{
		for(z=-100;z<=100;z+=10)
		{
			glBegin(GL_QUADS);
				glVertex3f(x,y,z);
				glVertex3f(x,y,z+10);
				glVertex3f(x+10,y,z+10);
				glVertex3f(x+10,y,z);
			glEnd();
		}
	}

	for(y=-100,x=100;y<=100;y+=10)
	{
		for(z=-100;z<=100;z+=10)
		{
			glBegin(GL_QUADS);
				glVertex3f(x,y,z);
				glVertex3f(x,y,z+10);
				glVertex3f(x,y+10,z+10);
				glVertex3f(x,y+10,z);
			glEnd();
		}
	}

	for(y=-100,x=-100;y<=100;y+=10)
	{
		for(z=-100;z<=100;z+=10)
		{
			glBegin(GL_QUADS);
				glVertex3f(x,y,z);
				glVertex3f(x,y,z+10);
				glVertex3f(x,y+10,z+10);
				glVertex3f(x,y+10,z);
			glEnd();
		}
	}


	

}
void init()
{
	glClearColor(1,1,1,0);
	float pos[]={-10,10,10,0};
	glLightfv(GL_LIGHT0,GL_POSITION,pos);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);

}

void idle()
{
	Sleep(50);
	as+=1;
	ae+=2;
	glutPostRedisplay();
}

//显示 回调函数  
void display(void)  
{  
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  
  
   
    glMatrixMode(GL_MODELVIEW);  
    glLoadIdentity();  
	gluLookAt(0,0,-100,0,0,0,0,1,0);
	GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
   GLfloat mat_ambient[] = { 0.7, 0.7, 0.7, 1.0 };
   GLfloat color1[]={1,0.1,0.2};
   GLfloat mat_ambient_color[] = { 0.8, 0.8, 0.2, 1.0 };
   GLfloat mat_diffuse[] = { 0.1, 0.5, 0.8, 1.0 };
   GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
   GLfloat no_shininess[] = { 0.0 };//没有高光
   GLfloat low_shininess[] = { 5.0 };//低光
   GLfloat high_shininess[] = { 100.0 };//高光
   GLfloat mat_emission[] = {0.3, 0.2, 0.2, 0.0};

	glPushMatrix();
		glMaterialfv(GL_FRONT, GL_AMBIENT, color1);//环境光
	   glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);//散射光
	   glMaterialfv(GL_FRONT, GL_SPECULAR, no_mat);//反射光
	   glMaterialfv(GL_FRONT, GL_SHININESS, no_shininess);//镜面反射指数
	   glMaterialfv(GL_FRONT, GL_EMISSION, color1); //材质的发射光
		drawSphere(0,0,0,25);
	glPopMatrix();

	glPushMatrix();
		glMaterialfv(GL_FRONT, GL_AMBIENT, no_mat);
	   glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	   glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	   glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
	   glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
	   glRotatef(as,0,0,1);
	   drawSphere(50,0,0,15);
	glPopMatrix();

	glPushMatrix();
		glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_color);
	   glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	   glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	   glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
	   glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);
	   glRotatef(as,0,0,1);
	   glTranslatef(50,0,0);
	   glRotatef(ae,0,0,1);
	   glTranslatef(-50,0,0);
		drawSphere(80,0,0,7);
	glPopMatrix();
  ground();
  
    glutSwapBuffers();  //刷新
}  

//窗口尺寸变化后的回调函数  
void reshape(int w,int h)  
{  
    glViewport(0, 0, w, h);  
    glMatrixMode(GL_PROJECTION); //将当前矩阵指定为投影模式  
    glLoadIdentity();  
   
    //glOrtho(-100,100,-100,100,-100,100);//设置裁剪窗口
	gluPerspective(90,w/h,1,200);
     
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
	init();
	glutIdleFunc(idle);
    glutDisplayFunc(display);  
	glutKeyboardFunc(keyboard);
    glutMainLoop();  
}
