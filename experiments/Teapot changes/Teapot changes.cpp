#include "stdafx.h"
#include <iostream>

 #include "glaux.h"  
 
#include "glut.h"  
float ax=0,ay=0;
float eyex=0,eyez=100;
float posx=0,posz=0;
float flag=1;

//显示 回调函数  
//void mouse()
//{
//	flag=(flag+1)%2;
//	if(flag==0)
//	{
//		
//	}
//}
void display(void)  
{  
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  
  
    glEnable(GL_DEPTH_TEST); //启用深度检测  
  
    glMatrixMode(GL_MODELVIEW);  
    glLoadIdentity();  
	glTranslatef(posx,0,posz);
	gluLookAt(eyex,0,eyez,0,0,0,0,1,0);//设置观察点以能够观察到对象,所画物体大小以此观察点为根据
	/*glRotatef(ax,1,0,0);
	glRotatef(ay,0,1,0);*/
	
	glColor3f(0.5,0.4,0.7);
	glutSolidTeapot(30);
	
	glColor3f(1,0,0);
	glutWireTeapot(30);
    glTranslatef(-posx,0,posz);
  
    glutSwapBuffers();  //刷新
}  
void special(int key,int x,int y)
{
	if(key==GLUT_KEY_UP)
	{
		eyez+=5;
	}
	if(key==GLUT_KEY_DOWN)
	{
		eyez-=5;
	}
	if(key==GLUT_KEY_LEFT)
	{
		eyex+=1;
	}
	if(key==GLUT_KEY_RIGHT)
	{
		eyex-=1;
	}
	glutPostRedisplay();
}

	

void myidle()
{
	Sleep(100);
	ax+=3;
	ay+=2;
	glutPostRedisplay();
}

//窗口尺寸变化后的回调函数  
void reshape(int w,int h)  
{  
    glViewport(0, 0, w, h);  
    glMatrixMode(GL_PROJECTION); //将当前矩阵指定为投影模式  
    glLoadIdentity();  
    if (0 != h)  
    {  
        GLfloat aspect =(float)w / (float)h;  
  
        gluPerspective(90.0f, aspect, 1.0f, 200.0f); //透视投影  
    }  
}  
  
//特殊按键处理回调函数  
 
void keyboard(unsigned char key,int x,int y)
{
	if(key==27)
	{
		exit(0);
	}
	if(key=='a')
	{
		posx+=3;
	}
	if(key=='d')
	{
		posx-=3;
	}
	if(key=='w')
	{
		posz-=3;
	}
	if(key=='s')
	{
		posz+=3;
	}
	glutPostRedisplay();

}

void main(int argc, char* argv[])  
{  
    glutInit(&argc, argv);  
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);  
    glutInitWindowSize(600, 480);  
    glutCreateWindow("OpenGL透视投影");  
  
    glutReshapeFunc(reshape); 
	glutSpecialFunc(special);
	glutKeyboardFunc(keyboard);
    glutDisplayFunc(display); 
	glutIdleFunc(myidle);
	
    glutMainLoop();  
}
