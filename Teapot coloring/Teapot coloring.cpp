#include "stdafx.h"
#include <iostream>
#include "glut.h"  

//显示 回调函数  
void display(void)  
{  
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  
  
   
    glMatrixMode(GL_MODELVIEW);  
    glLoadIdentity();  
	gluLookAt(0,0,100,0,0,0,0,1,0);
	float shinness1=0;
	float shinness2=50;
	float shinness3=100;

	float color[]={0.5,0.4,0.7};
	float color3[]={0,1,0,0};
	
	float color4[]={0.5,0.5,0.5,0};
	glMaterialfv(GL_FRONT,GL_AMBIENT,color);
	glMaterialfv(GL_FRONT,GL_DIFFUSE,color3);
	glMaterialfv(GL_FRONT,GL_SPECULAR,color4);
	glMaterialf(GL_FRONT,GL_SHININESS,shinness1);

	glutSolidTeapot(30);
  
  
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
void init()
{
	/*float color1[]={1,1,0,0};
	float color2[]={1,0.38,0,0};*/
	
	float pos[]={30,10,70};

	glLightfv(GL_LIGHT0,GL_POSITION,pos);
	/*glLightfv(GL_LIGHT0,GL_AMBIENT,color1);*/
	/*glLightfv(GL_LIGHT0,GL_DIFFUSE,color2);*/

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);


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
	init();
	glutKeyboardFunc(keyboard);
    glutMainLoop();  
}
