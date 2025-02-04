#include "stdafx.h"
#include <iostream>
#include "glut.h"  
int fogmode=GL_EXP2;

void init(void)
{
   GLfloat ambient[] = { 0.0, 0.0, 0.0, 1.0 };
   GLfloat diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
   GLfloat position[] = { 0.0, 3.0, 2.0, 0.0 };
   GLfloat lmodel_ambient[] = { 0.4, 0.4, 0.4, 1.0 };
   GLfloat local_view[] = { 0.0 };

   glClearColor(0.5, 0.5, 0.5, 0.0);
   glEnable(GL_DEPTH_TEST);
   glShadeModel(GL_SMOOTH);

   glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
   glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
   glLightfv(GL_LIGHT0, GL_POSITION, position);
   glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
   glLightModelfv(GL_LIGHT_MODEL_LOCAL_VIEWER, local_view);

   glEnable(GL_LIGHTING);
   glEnable(GL_LIGHT0);

   
	GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
   GLfloat mat_ambient[] = { 0.7, 0.7, 0.7, 1.0 };
   GLfloat mat_ambient_color[] = { 0.8, 0.8, 0.2, 1.0 };
   GLfloat mat_diffuse[] = { 0.1, 0.5, 0.8, 1.0 };
   GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
   GLfloat no_shininess[] = { 0.0 };//没有高光
   GLfloat low_shininess[] = { 5.0 };//低光
   GLfloat high_shininess[] = { 100.0 };//高光
   GLfloat mat_emission[] = {0.3, 0.2, 0.2, 0.0};

   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

   
   
   glMaterialfv(GL_FRONT, GL_AMBIENT, no_mat);
   glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
   glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
   glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
   glMaterialfv(GL_FRONT, GL_EMISSION, no_mat);

}

void draw(float x,float y,float z)
{
	glPushMatrix(); 
   glTranslatef (x,y,z);
   /*glutSolidSphere(1, 16, 16);*/
   /*glutSolidTeapot(0.8);*/
   glutWireTorus(0.2,0.5,25,25);
   glPopMatrix();
}

//显示 回调函数  
void display(void)  
{  
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  
  
   
    glMatrixMode(GL_MODELVIEW);  
    glLoadIdentity();  
	/*gluLookAt(0,0,10,0,0,0,0,1,0);
	glEnable(GL_DEPTH_TEST);*/
	
	glEnable(GL_FOG);
	{
		
		glFogi(GL_FOG_MODE,fogmode);

		float color[]={0.5,0.5,0.5};
		glFogfv(GL_FOG_COLOR,color);
		glFogf(GL_FOG_DENSITY,0.35);
		glFogf(GL_FOG_START,1);
		glFogf(GL_FOG_END,5);
	}
	
	draw(-4,0,-1);
	draw(-2,0,-2);
	draw(0,0,-3);
	draw(2,0,-4);
	draw(4,0,-5);



 
  
  
    glutSwapBuffers();  //刷新
}  

//窗口尺寸变化后的回调函数  
void reshape(int w,int h)  
{  
    glViewport(0, 0, w, h);  
    glMatrixMode(GL_PROJECTION); //将当前矩阵指定为投影模式  
    glLoadIdentity();  
   
   glOrtho(-5,5,-5,5,-5,5);//设置裁剪窗口
	/*gluPerspective(90,w/h,1,200);
     */
}  
  
//键盘按键处理回调函数
void keyboard(unsigned char key,int x,int y)
{
	if(key==27)//ESC键退出程序
	{
		exit(0);
	}
	if(key=='l')
	{
		fogmode=GL_LINEAR;
	}
	else if(key=='e')
	{
		fogmode=GL_EXP;
	}
	else if(key=='f')
	{
		fogmode=GL_EXP2;
	}
	glutPostRedisplay();
}

void main()  
{  
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);  
    glutInitWindowSize(600, 600);  
    glutCreateWindow("OpenGL Program");  
  
	init();
    glutReshapeFunc(reshape);  
    glutDisplayFunc(display);  
	glutKeyboardFunc(keyboard);
    glutMainLoop();  
}
