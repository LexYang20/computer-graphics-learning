#include "stdafx.h"
#include <iostream>

 #include "glaux.h"  
 
#include "glut.h"  
float ax=0,ay=0;
float eyex=0,eyez=100;
float posx=0,posz=0;
float flag=1;

//��ʾ �ص�����  
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
  
    glEnable(GL_DEPTH_TEST); //������ȼ��  
  
    glMatrixMode(GL_MODELVIEW);  
    glLoadIdentity();  
	glTranslatef(posx,0,posz);
	gluLookAt(eyex,0,eyez,0,0,0,0,1,0);//���ù۲�����ܹ��۲쵽����,���������С�Դ˹۲��Ϊ����
	/*glRotatef(ax,1,0,0);
	glRotatef(ay,0,1,0);*/
	
	glColor3f(0.5,0.4,0.7);
	glutSolidTeapot(30);
	
	glColor3f(1,0,0);
	glutWireTeapot(30);
    glTranslatef(-posx,0,posz);
  
    glutSwapBuffers();  //ˢ��
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

//���ڳߴ�仯��Ļص�����  
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
}  
  
//���ⰴ������ص�����  
 
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
    glutCreateWindow("OpenGL͸��ͶӰ");  
  
    glutReshapeFunc(reshape); 
	glutSpecialFunc(special);
	glutKeyboardFunc(keyboard);
    glutDisplayFunc(display); 
	glutIdleFunc(myidle);
	
    glutMainLoop();  
}
