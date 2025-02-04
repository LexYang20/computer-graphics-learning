#include "stdafx.h"
#include <iostream>
#include "glut.h"  

//显示 回调函数  
void display(void)  
{  
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  
	float mcolor1[]={1,0.38,0,1};
	float mocolor2[]={1,0,1,1};
	float ambcolor[]={1,1,0,1};
	float ambcolor2[]={0,0.5,0.65};
	float scolor[]={0,1,0,1};
	float pos1[]={-10,5,-30,0};
	float pos2[]={10,5,-30,0};
	   
    glMatrixMode(GL_MODELVIEW);  
    glLoadIdentity();  
  
    gluLookAt(0,0,100,0,0,0,0,1,0);

	glLightfv(GL_LIGHT0,GL_POSITION,pos1);
	glLightfv(GL_LIGHT0,GL_AMBIENT,ambcolor);
	/*glLightfv(GL_LIGHT0,GL_DIFFUSE,mcolor1);
	glLightfv(GL_LIGHT0,GL_SPECULAR,scolor);*/

	glLightfv(GL_LIGHT0,GL_POSITION,pos2);
	glLightfv(GL_LIGHT0,GL_AMBIENT,ambcolor2);
	/*glLightfv(GL_LIGHT0,GL_DIFFUSE,mocolor2);*/

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glTranslatef(5,10,0);
	glutSolidSphere(30,25,25);
	glTranslatef(-5,-10,0);

	glTranslatef(-5,10,10);
	glutSolidSphere(30,25,25);
	glTranslatef(5,-10,0);

  
    glutSwapBuffers();  //刷新
}  

//窗口尺寸变化后的回调函数  
void reshape(int w,int h)  
{  
    glViewport(0, 0, w, h);  
    glMatrixMode(GL_PROJECTION); //将当前矩阵指定为投影模式  
    glLoadIdentity();  
   
    /*glOrtho(-100,100,-100,100,-100,100);*///设置裁剪窗口
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
    glutDisplayFunc(display);  
	glutKeyboardFunc(keyboard);
    glutMainLoop();  
}
