#include <windows.h>
#include <stdlib.h>
#include<gl/glut.h>
#include <math.h>
#include <string.h>
#include <stdio.h>

float a=0.0,b=0.0;//oksigen 1;
int c=0,d=0;//oksigen 2;
float tiga=0,empat=0; //oksigen 3

float k1=0.0,k2=0.0; //karbon1
float k3=0.0,k4=0.0; //karbon2
float k5=0.0,k6=0.0; //karbon3
float k7=0.0,k8=0.0; //karbon4

int height,width;

int d1=0;

int e=0,f=0;//sinar1
float g=0.0,h=0.0;//sinar2
float i=0.0,j=0.0;//sinar3
float k=0.0,l=0.0;//sinar4
float m=0.0,n=0.0;//sinar5
float o=0.0,p=0.0;//sinar6
float q=0.0,r=0.0;//sinar7

void myTimeOut(int id)
{
    //oksigen
    a+=1;b+=0.4;
    c+=1;d+=1;
    tiga+=0.8;empat-=0.5;
    if(a==28)
    {
        a=0.0;b=0.0;
        c=0;d=0;
        tiga=0.0;empat=0.0;
    }
    //karbon
    k1-=0.2;k2-=1;
    k3-=1.2;k4-=0.8;
    k5-=1;k6-=0.5;
    k7-=0.8;k8+=0.3;
    if(k2==-26)
    {
        k1=0;k2=0;
        k3=0;k4=0;
        k5=0;k6=0;
        k7=0.0;k8=0.0;
        d1+=10;
    }
    //sinar
    e-=1;f-=0; //1
    g-=1;h-=0.2; //2
    i-=1;j-=0.4; //3
    k-=0.8;l-=0.6;
    m-=0.7;n-=0.7;
    o-=0.4;p-=0.8;
    q-=0.2;r-=0.9;
    if(e== -8)
    {
        e=0;f=0;
        g=0.0;h=0.0;
        i=0.0;j=0.0;
        k=0.0;l=0.0;
        m=0.0;n=0.0;
        o=0.0;p=0.0;
        q=0.0;r=0.0;
    }

    glutPostRedisplay();
    glutTimerFunc(100, myTimeOut,0);
}
void bitmap_output(float x,float y,char *string,void *font)
 {
   int len,i;
   glRasterPos2f(x,y);
   len=(int)strlen(string);
   for(i=0;i<len;i++)
   {
      glutBitmapCharacter(font,string[i]);
   }
   return;
}
void lingkaran(float xp, float yp, float r, float n)
{
    float a,x,y;
    glBegin(GL_POLYGON);
        a=6.28/n;
        for (int i=0; i<n; i++){
            x = xp+r * cos(i*a);
            y = yp+r * sin(i*a);
            glVertex2d(x,y);
        }
    glEnd();
}
void daun()
{
    glBegin(GL_TRIANGLES); //tangkai
    glColor3f(0.0,2.0,0.0); // warna hijau
        glVertex2f(-45.5,10.5);
        glColor3f(0.0,2.0,0.0); // warna hijau
        glVertex2f(-46,10);
        glColor3f(1.0,5.0,0.0); // warna kuning
        glVertex2f(-40,8.5);
    glEnd();
    glBegin(GL_POLYGON);//bidang 1
    glColor3f(0.0,1.0,0.0); //warna hijau
        glVertex2f(-33,10);
        glColor3f(0.0,1.0,0.0);//warna hijau
        glVertex2f(-36,10.5);
        glColor3f(0.0,1.0,0.0);//warna hijau
        glVertex2f(-39,10.5);
        glColor3f(1.0,1.0,0.0);//warna kuning
        glVertex2f(-42,9);
        glColor3f(1.0,1.0,0.0);//warna kuning
        glVertex2f(-39,8);
    glEnd();

    glBegin(GL_POLYGON);//bidang 2
        glColor3f(0.0,1.0,0.0); //warna hijau
        glVertex2f(-33,10);
        glColor3f(1.0,1.0,0.0); //warna kuning
        glVertex2f(-39,8);
        glColor3f(1.0,1.0,0.0); //warna kuning
        glVertex2f(-36,6);
        glColor3f(0.0,1.0,0.0); //warna hijau
        glVertex2f(-25,4);
        glColor3f(0.0,1.0,0.0); //warna hijau
        glVertex2f(-27,6.5);
        glColor3f(0.0,1.0,0.0); //warna hijau
        glVertex2f(-29,8);
    glEnd();

    glBegin(GL_POLYGON);//bidang 3
        glColor3f(1.0,1.0,0.0); //warna kuning
        glVertex2f(-36,6);
        glColor3f(1.0,1.0,0.0); //warna kuning
        glVertex2f(-30,0);
        glColor3f(0.0,1.0,0.0); //warna hijau
        glVertex2f(-22,-4);
        glColor3f(0.0,1.0,0.0); //warna hijau
        glVertex2f(-23,0);
        glColor3f(0.0,1.0,0.0); //warna hijau
        glVertex2f(-25,4);
    glEnd();

    glBegin(GL_POLYGON);//bidang 4
        glColor3f(1.0,1.0,0.0);//warna kuning
        glVertex2f(-30,0);
        glColor3f(1.0,1.0,0.0); //warna kuning
        glVertex2f(-27,-4);
        glColor3f(0.0,1.0,0.0); //warna hijau
        glVertex2f(-22,-7);
        glColor3f(0.0,1.0,0.0); //warna hijau
        glVertex2f(-22,-4);
    glEnd();

    glBegin(GL_POLYGON);//bidang 5
        glColor3f(1.0,1.0,0.0);//warna kuning
        glVertex2f(-27,-4);
        glColor3f(1.0,1.0,0.0); //warna kuning
        glVertex2f(-24,-9);
        glColor3f(0.0,1.0,0.0); //warna hijau
        glVertex2f(-23.5,-10);
        glColor3f(0.0,1.0,0.0); //warna hijau
        glVertex2f(-22,-7);
    glEnd();

    glBegin(GL_POLYGON);//bidang 6
        glColor3f(1.0,1.0,0.0);//warna kuning
        glVertex2f(-24,-9);
        glColor3f(0.0,1.0,0.0); //warna hijau
        glVertex2f(-23,-13);
        glColor3f(0.0,1.0,0.0); //warna hijau
        glVertex2f(-23.5,-10);
    glEnd();

    glBegin(GL_POLYGON);//bidang 7
        glColor3f(1.0,1.0,0.0);// warna kuning
        glVertex2f(-24,-9);
        glColor3f(0.0,1.0,0.0); //warna hijau
        glVertex2f(-24,-11);
        glColor3f(0.0,1.0,0.0); //warna hijau
        glVertex2f(-23,-13);
    glEnd();

    glBegin(GL_POLYGON);//bidang 8
        glColor3f(1.0,1.0,0.0);//warna kuning
        glVertex2f(-30,0);
        glColor3f(0.0,1.0,0.0); //warna hijau
        glVertex2f(-30,-8.5);
        glColor3f(0.0,1.0,0.0); //warna hijau
        glVertex2f(-24,-11);
        glColor3f(1.0,1.0,0.0); //warna kuning
        glVertex2f(-24,-9);
        glColor3f(1.0,1.0,0.0); //warna kuning
        glVertex2f(-27,-4);
    glEnd();

    glBegin(GL_POLYGON); //bidang 9
        glColor3f(1.0,1.0,0.0);//warna kuning
        glVertex2f(-39,8);
        glColor3f(0.0,1.0,0.0); //warna hijau
        glVertex2f(-38,-4);
        glColor3f(0.0,1.0,0.0); //warna hijau
        glVertex2f(-30,-8.5);
        glColor3f(1.0,1.0,0.0); //warna kuning
        glVertex2f(-30,0);
        glColor3f(1.0,1.0,0.0); //warna kuning
        glVertex2f(-36,6);
    glEnd();

    glBegin(GL_POLYGON); //bidang 10
        glColor3f(1.0,1.0,0.0);//warna kuning
        glVertex2f(-42,9);
        glColor3f(0.0,1.0,0.0); //warna hijau
        glVertex2f(-43,6);
        glColor3f(0.0,1.0,0.0); //warna hijau
        glVertex2f(-43,4);
        glColor3f(0.0,1.0,0.0); //warna hijau
        glVertex2f(-42,1);
        glColor3f(0.0,1.0,0.0); //warna hijau
        glVertex2f(-40,-2);
        glColor3f(0.0,1.0,0.0); //warna hijau
        glVertex2f(-38,-4);
        glColor3f(1.0,1.0,0.0); //warna kuning
        glVertex2f(-39,8);
    glEnd();

       //TULANG
    glBegin(GL_LINE_STRIP);//tulang tengah
        glColor3f(0.0,0.0,0.0);//warna hitam
        glVertex2f(-42,9.1);
        glVertex2i(-39,8);
        glVertex2i(-36,6);
        glVertex2i(-30,0);
        glVertex2i(-27,-4);
        glVertex2i(-24,-9);
        glVertex2i(-23,-13);
    glEnd();

    glBegin(GL_LINES);//tulang daun 1
        glColor3f(0.0,0.0,0.0);
        glVertex2f(-39,8);
        glVertex2f(-40,-2);
    glEnd();

    glBegin(GL_LINES);//tulang daun 2
        glColor3f(0.0,0.0,0.0);
        glVertex2f(-37.5,7);
        glVertex2f(-29,8);
    glEnd();

    glBegin(GL_LINES);//tulang daun 3
        glColor3f(0.0,0.0,0.0);
        glVertex2f(-35,5);
        glVertex2f(-34.6,-6);
    glEnd();

    glBegin(GL_LINES);//tulang daun 4
        glColor3f(0.0,0.0,0.0);
        glVertex2f(-33,3);
        glVertex2f(-24,2);
    glEnd();

    glBegin(GL_LINES);//tulang daun 5
        glColor3f(0.0,0.0,0.0);
        glVertex2f(-30,0);
        glVertex2f(-29,-9);
    glEnd();

       //TULANG
    glBegin(GL_LINE_STRIP);//tulang tengah
        glColor3f(0.0,0.0,0.0);//warna hitam
        glVertex2f(-42,9.1);
        glVertex2i(-39,8);
        glVertex2i(-36,6);
        glVertex2i(-30,0);
        glVertex2i(-27,-4);
        glVertex2i(-24,-9);
        glVertex2i(-23,-13);
    glEnd();

    glBegin(GL_LINES);//tulang daun 1
        glColor3f(0.0,0.0,0.0);
        glVertex2f(-39,8);
        glVertex2f(-40,-2);
    glEnd();

    glBegin(GL_LINES);//tulang daun 2
        glColor3f(0.0,0.0,0.0);
        glVertex2f(-37.5,7);
        glVertex2f(-29,8);
    glEnd();

    glBegin(GL_LINES);//tulang daun 3
        glColor3f(0.0,0.0,0.0);
        glVertex2f(-35,5);
        glVertex2f(-34.6,-6);
    glEnd();

    glBegin(GL_LINES);//tulang daun 4
        glColor3f(0.0,0.0,0.0);
        glVertex2f(-33,3);
        glVertex2f(-24,2);
    glEnd();

    glBegin(GL_LINES);//tulang daun 5
        glColor3f(0.0,0.0,0.0);
        glVertex2f(-30,0);
        glVertex2f(-29,-9);
    glEnd();

    glBegin(GL_LINES);//tulang daun 6
        glColor3f(0.0,0.0,0.0);
        glVertex2f(-28,-2.5);
        glVertex2f(-22,-4);
    glEnd();
    glFlush();
}
void batang ()
{
    glBegin(GL_QUADS);
    glColor3f(0.60,0.40,0.12);
        glVertex2f(-50,-30);
        glVertex2f(-49,-30);
        glVertex2f(-45.5,10);
        glVertex2f(-47,10);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.60,0.40,0.12);
        glVertex2f(-45.5,10);
        glVertex2f(-47,10);
        glVertex2f(-47,20);
        glVertex2f(-45.5,20);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.60,0.40,0.12);
        glVertex2f(-45.5,20);
        glVertex2f(-47,20);
        glVertex2f(-50,40);
        glVertex2f(-50,43);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.60,0.40,0.12);
        glVertex2f(-45.5,10);
        glVertex2f(-47,10);
        glVertex2f(-44,48);
        glVertex2f(-43,50);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.60,0.40,0.12);
        glVertex2f(-50,-30);
        glVertex2f(-49,-30);
        glVertex2f(-48.5,-50);
        glVertex2f(-50,-50);
    glEnd();
}
void oksigen()
{
    //oksigen 1
    glPushMatrix();
    glTranslatef(a,b,0.0);
    glColor3f(0.5,1.0,1.0);
    lingkaran(-15,0,3,25);
    glColor3f(0,0,0);
    bitmap_output(-15.8,-0.5,"O2",GLUT_BITMAP_HELVETICA_12);
    glPopMatrix();
    //oksigen2
    glPushMatrix();
    glTranslated(c,d,0.0);
    glColor3f(0.5,1.0,1.0);
    lingkaran(-18,5,3,25);
    glColor3f(0,0,0);
    bitmap_output(-18.8,4.5,"O2",GLUT_BITMAP_HELVETICA_12);
    glPopMatrix();
    //oksigen3
    glPushMatrix();
    glTranslatef(tiga,empat,0);
    glColor3f(0.5,1.0,1.0);
    lingkaran(-15,-7,3,25);
    glColor3f(0,0,0);
    bitmap_output(-15.8,-7.5,"O2",GLUT_BITMAP_HELVETICA_12);
    glPopMatrix();

}
void matahari()
{
    //matahari
    glColor3f(1.0,1.0,0.0);
    lingkaran(45,45,15,50);
    //sinar matahari
    glPushMatrix();
    glTranslated(e,f,0);
    glColor3f(1.0,1.0,0.0);
    glBegin(GL_LINES); //sinar 1
        glVertex2f(29,48);
        glVertex2f(25,48);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(g,h,0);
    glColor3f(1.0,1.0,0.0);
    glBegin(GL_LINES); //sinar 2
        glVertex2f(29,43);
        glVertex2f(25,42);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(i,j,0.0);
    glColor3f(1.0,1.0,0.0);
    glBegin(GL_LINES); //sinar 3
        glVertex2f(30,38);
        glVertex2f(26,36);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(k,l,0);
    glColor3f(1.0,1.0,0.0);
    glBegin(GL_LINES); //sinar 4
        glVertex2f(32,34);
        glVertex2f(29,30);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(m,n,0);
    glColor3f(1.0,1.0,0.0);
    glBegin(GL_LINES); //sinar 5
        glVertex2f(36,30);
        glVertex2f(34,26);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(o,p,0);
    glColor3f(1.0,1.0,0.0);
    glBegin(GL_LINES); //sinar 6
        glVertex2f(40,29);
        glVertex2f(39,24);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(q,r,0);
    glColor3f(1.0,1.0,0.0);
    glBegin(GL_LINES); //sinar 7
        glVertex2f(45,28);
        glVertex2f(44.5,23);
    glEnd();
    glPopMatrix();
}
void karbon()
{
    //karbon 1
    glPushMatrix();
    glTranslatef(k1,k2,0.0);
    glColor3f(0.85,0.85,0.85);
    lingkaran(-20,43,3,25);
    glColor3f(0,0,0);
    bitmap_output(-21,42.5,"CO2",GLUT_BITMAP_HELVETICA_12);
    glPopMatrix();
    //karbon 2
    glPushMatrix();
    glTranslatef(k3,k4,0.0);
    glColor3f(0.85,0.85,0.85);
    lingkaran(10,25,3,25);
    glColor3f(0,0,0);
    bitmap_output(9,24.5,"CO2",GLUT_BITMAP_HELVETICA_12);
    glPopMatrix();
    //karbon 3
    glPushMatrix();
    glTranslatef(k5,k6,0.0);
    glColor3f(0.85,0.85,0.85);
    lingkaran(15,5,3,25);
    glColor3f(0,0,0);
    bitmap_output(14,4.5,"CO2",GLUT_BITMAP_HELVETICA_12);
    glPopMatrix();
    //karbon 4
    glPushMatrix();
    glTranslatef(k7,k8,0.0);
    glColor3f(0.85,0.85,0.85);
    lingkaran(0,-20,3,25);
    glColor3f(0,0,0);
    bitmap_output(-1,-20.7,"CO2",GLUT_BITMAP_HELVETICA_12);
    glPopMatrix();
}
void display3()
{
    //gradien background
    glBegin(GL_QUADS);
    //white color
        glColor3f(1.0,1.0,1.0);
        glVertex2f(-50.0, -50.0);
        glVertex2f(50.0,-50.0);
    //black
        //glColor3f(0.75,0.75,0.75);
        glColor3f(0.0,0.0,1.0);
        glVertex2f(50.0, 50.0);
        glVertex2f(-50.0,50.0);
    glEnd();
    batang();
    daun();
    matahari();
    oksigen();

    glColor3f(0.0,0.0,0.0);
    bitmap_output(-45,-45,"Oksigen(O2) yang dihasilkan dilepaskan ke udara",GLUT_BITMAP_TIMES_ROMAN_24);
}
void display1()
{
    //gradien background
    glBegin(GL_QUADS);
    //white color
        glColor3f(1.0,1.0,1.0);
        glVertex2f(-50.0, -50.0);
        glVertex2f(50.0,-50.0);
    //black
        glColor3f(0.0,0.0,0.0);
        glVertex2f(50.0, 50.0);
        glVertex2f(-50.0,50.0);
    glEnd();
    batang();
    daun();
    matahari();
    karbon();

    glColor3f(0.0,0.0,0.0);
    bitmap_output(-45,-45,"Penyerapan CO2 sebagai salah satu bahan baku Fotosintesis oleh Tanaman",GLUT_BITMAP_TIMES_ROMAN_24);
}
void display2()
{
    glBegin(GL_QUADS);
    //white color
        glColor3f(1.0,1.0,1.0);
        glVertex2f(-50.0, -50.0);
        glVertex2f(50.0,-50.0);
    //black
        glColor3f(0.0,0.0,0.0);
        glVertex2f(50.0, 50.0);
        glVertex2f(-50.0,50.0);
    glEnd();
    glBegin(GL_TRIANGLES); //tangkai
    glColor3f(0.0,2.0,0.0); // warna hijau
        glVertex2f(-36.5,30.5);
        glColor3f(0.0,2.0,0.0); // warna hijau
        glVertex2f(-39,30);
        glColor3f(1.0,5.0,0.0); // warna kuning
        glVertex2f(-21,24.5);
    glEnd();
    glBegin(GL_POLYGON);//bidang 1
        glColor3f(0.0,1.0,0.0); //warna hijau
        glVertex2f(0,30);
        glColor3f(0.0,1.0,0.0);//warna hijau
        glVertex2f(-9,30.5);
        glColor3f(0.0,1.0,0.0);//warna hijau
        glVertex2f(-18,30.5);
        glColor3f(1.0,1.0,0.0);//warna kuning
        glVertex2f(-27,27);
        glColor3f(1.0,1.0,0.0);//warna kuning
        glVertex2f(-18,24);
    glEnd();
    glBegin(GL_POLYGON);//bidang 2
        glColor3f(0.0,1.0,0.0); //warna hijau
        glVertex2f(0,30);
        glColor3f(1.0,1.0,0.0); //warna kuning
        glVertex2f(-18,24);
        glColor3f(1.0,1.0,0.0); //warna kuning
        glVertex2f(-9,18);
        glColor3f(0.0,1.0,0.0); //warna hijau
        glVertex2f(24,12);
        glColor3f(0.0,1.0,0.0); //warna hijau
        glVertex2f(18,18.5);
        glColor3f(0.0,1.0,0.0); //warna hijau
        glVertex2f(12,24);
    glEnd();
    glBegin(GL_POLYGON);//bidang 3
        glColor3f(1.0,1.0,0.0); //warna kuning
        glVertex2f(-9,18);
        glColor3f(1.0,1.0,0.0); //warna kuning
        glVertex2f(9,0);
        glColor3f(0.0,1.0,0.0); //warna hijau
        glVertex2f(33,-12);
        glColor3f(0.0,1.0,0.0); //warna hijau
        glVertex2f(30,0);
        glColor3f(0.0,1.0,0.0); //warna hijau
        glVertex2f(24,12);
    glEnd();
    glBegin(GL_POLYGON);//bidang 4
        glColor3f(1.0,1.0,0.0);//warna kuning
        glVertex2f(9,0);
        glColor3f(1.0,1.0,0.0); //warna kuning
        glVertex2f(18,-12);
        glColor3f(0.0,1.0,0.0); //warna hijau
        glVertex2f(33,-21);
        glColor3f(0.0,1.0,0.0); //warna hijau
        glVertex2f(33,-12);
    glEnd();
    glBegin(GL_POLYGON);//bidang 5
        glColor3f(1.0,1.0,0.0);//warna kuning
        glVertex2f(18,-12);
        glColor3f(1.0,1.0,0.0); //warna kuning
        glVertex2f(27,-27);
        glColor3f(0.0,1.0,0.0); //warna hijau
        glVertex2f(30.5,-30);
        glColor3f(0.0,1.0,0.0); //warna hijau
        glVertex2f(33,-21);
    glEnd();
    glBegin(GL_POLYGON);//bidang 6
        glColor3f(1.0,1.0,0.0);//warna kuning
        glVertex2f(27,-27);
        glColor3f(0.0,1.0,0.0); //warna hijau
        glVertex2f(30,-39);
        glColor3f(0.0,1.0,0.0); //warna hijau
        glVertex2f(30.5,-30);
    glEnd();
    glBegin(GL_POLYGON);//bidang 7
        glColor3f(1.0,1.0,0.0);// warna kuning
        glVertex2f(27,-27);
        glColor3f(0.0,1.0,0.0); //warna hijau
        glVertex2f(27,-33);
        glColor3f(0.0,1.0,0.0); //warna hijau
        glVertex2f(30,-39);
    glEnd();
    glBegin(GL_POLYGON);//bidang 8
        glColor3f(1.0,1.0,0.0);//warna kuning
        glVertex2f(9,0);
        glColor3f(0.0,1.0,0.0); //warna hijau
        glVertex2f(9,-24.5);
        glColor3f(0.0,1.0,0.0); //warna hijau
        glVertex2f(27,-33);
        glColor3f(1.0,1.0,0.0); //warna kuning
        glVertex2f(27,-27);
        glColor3f(1.0,1.0,0.0); //warna kuning
        glVertex2f(18,-12);
    glEnd();
    glBegin(GL_POLYGON); //bidang 9
        glColor3f(1.0,1.0,0.0);//warna kuning
        glVertex2f(-18,24);
        glColor3f(0.0,1.0,0.0); //warna hijau
        glVertex2f(-15,-12);
        glColor3f(0.0,1.0,0.0); //warna hijau
        glVertex2f(9,-24.5);
        glColor3f(1.0,1.0,0.0); //warna kuning
        glVertex2f(9,0);
        glColor3f(1.0,1.0,0.0); //warna kuning
        glVertex2f(-9,18);
    glEnd();
    glBegin(GL_POLYGON); //bidang 10
        glColor3f(1.0,1.0,0.0);//warna kuning
        glVertex2f(-27,27);
        glColor3f(0.0,1.0,0.0); //warna hijau
        glVertex2f(-30,18);
        glColor3f(0.0,1.0,0.0); //warna hijau
        glVertex2f(-30,12);
        glColor3f(0.0,1.0,0.0); //warna hijau
        glVertex2f(-27,3);
        glColor3f(0.0,1.0,0.0); //warna hijau
        glVertex2f(-21,-6);
        glColor3f(0.0,1.0,0.0); //warna hijau
        glVertex2f(-15,-12);
        glColor3f(1.0,1.0,0.0); //warna kuning
        glVertex2f(-18,24);
    glEnd();

       //TULANG
    glBegin(GL_LINE_STRIP);//tulang tengah
        glColor3f(0.0,0.0,0.0);//warna hitam
        glVertex2f(-27,27.1);
        glVertex2i(-18,24);
        glVertex2i(-9,18);
        glVertex2i(9,0);
        glVertex2i(18,-12);
        glVertex2i(27,-27);
        glVertex2i(30,-39);
    glEnd();
    glBegin(GL_LINES);//tulang daun 1
        glColor3f(0.0,0.0,0.0);
        glVertex2f(-18,24);
        glVertex2f(-21,-6);
    glEnd();
    glBegin(GL_LINES);//tulang daun 2
        glColor3f(0.0,0.0,0.0);
        glVertex2f(-12.5,21);
        glVertex2f(12,24);
    glEnd();
    glBegin(GL_LINES);//tulang daun 3
        glColor3f(0.0,0.0,0.0);
        glVertex2f(-6,15);
        glVertex2f(-3.6,-18);
    glEnd();
    glBegin(GL_LINES);//tulang daun 4
        glColor3f(0.0,0.0,0.0);
        glVertex2f(0,9);
        glVertex2f(27,6);
    glEnd();
    glBegin(GL_LINES);//tulang daun 5
        glColor3f(0.0,0.0,0.0);
        glVertex2f(9,0);
        glVertex2f(12,-27);
    glEnd();
    glBegin(GL_LINES);//tulang daun 6
        glColor3f(0.0,0.0,0.0);
        glVertex2f(15,-6.5);
        glVertex2f(33,-12);
    glEnd();
        glBegin(GL_LINES);//tulang daun 7
        glColor3f(0.0,0.0,0.0);
        glVertex2f(21,-15.7);
        glVertex2f(24,-30.5);
    glEnd();
    glBegin(GL_LINES);//tulang daun 8
        glColor3f(0.0,0.0,0.0);
        glVertex2f(24,-21.4);
        glVertex2f(30.7,-27);
    glEnd();

    bitmap_output(-20,0,"6",GLUT_BITMAP_TIMES_ROMAN_24);
    glColor3f(-3.5,1.0,1.0);
    glBegin(GL_TRIANGLES);
        glVertex2f(-18,0);
        glVertex2f(-15.5,5);
        glVertex2f(-13,0);
    glEnd();
    lingkaran(-15.5,0,2.5,25);

    glColor3f(0.0,0.0,0.0);
    bitmap_output(-12,0,"+      6",GLUT_BITMAP_TIMES_ROMAN_24);

    glColor3f(0.85,0.85,0.85);
    lingkaran(-3,1,3,25);
    glColor3f(0,0,0);
    bitmap_output(-4,0.5,"CO2",GLUT_BITMAP_HELVETICA_12);


    bitmap_output(1,0,"+",GLUT_BITMAP_TIMES_ROMAN_24);

    glColor3f(1.0,0.5,0.0);
    bitmap_output(3,0,"Cahaya Matahari",GLUT_BITMAP_TIMES_ROMAN_24);

    matahari();

    glColor3f(1,1,1);
    bitmap_output(-48,45,"Proses Fotosintesis yang terjadi di Daun : ",GLUT_BITMAP_TIMES_ROMAN_24);
    glColor3f(0.0,0.0,0.0);
    bitmap_output(-48,-45,"Menghasilkan : C6H12O6(Glukosa) + 6O2(Oksigen)",GLUT_BITMAP_TIMES_ROMAN_24);

    glFlush();
}
void opening()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_LINES);//tulang daun 1
    glColor3f(0.0,2.0,0.0);
    for(int i=-50;i<=50;i+=10)
    {
        for(int j=50;j>=-50;j-=10)
        {
            glVertex2f(-50,i);
            glVertex2f(j,50);
        }
    }
    glColor3f(1.0,5.0,0.0);
    for(int i=-50;i<=50;i+=10)
    {
        for(int j=50;j>=-50;j-=10)
        {
            glVertex2f(i,-50);
            glVertex2f(50,j);
        }
    }
    glEnd();

    glColor3f(0,0,0);
    bitmap_output(-12,0,"FOTOSINTESIS PADA TANAMAN",GLUT_BITMAP_TIMES_ROMAN_24);

}
void myKeyboard(unsigned char key, int x, int y)
{
       if((key=='y')||(key=='Y')) d1=10;
       else if((key=='n')||(key=='N')) exit(1);
}

void myDisplay(){
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    opening();

    if(d1==10 || d1 == 20)
        display1();
    if(d1==30 || d1 == 40)
        display2();
    if(d1==50 || d1 == 60)
        display3();

    glutSwapBuffers();
}
void myinit()
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glViewport(0,0,width,height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-50.0, 50.0, -50.0, 50.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    return;
}
int main (int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(1240,680);
    glutCreateWindow("Fotosintesis");
    glutTimerFunc(100,myTimeOut,0);
    glutDisplayFunc(myDisplay);
    glutKeyboardFunc(myKeyboard);
    myinit();
    glutMainLoop();
    return 0;
}
