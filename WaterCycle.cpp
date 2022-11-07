#include<stdio.h>
#include<GL/glut.h>
#include <GL/gl.h>
#include <stdlib.h>
#define SPEED 30.0

float i=0.0,m=0.0,n=0.0,o=0.0,c=0.0,b=0.0,arx=0.0,ary=0.0,fsx=0.0,fsy=0.0,fx=0.0,fy=0.0;
float p=0.75,q=0.47,r=0.14,ra=0.0;
float e=0.90,f=0.91,g=0.98;
int count=0,xm=900;
char ch;

void drawstring(float x,float y,float z,char *string, int f)
{
    char *c;
    glRasterPos3f(x,y,z);
    for(c=string;*c!='\0';c++){
        if(f==0)
            glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,*c);
        else
            glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,*c);
    }
}

void screen()
{
    glClear(GL_COLOR_BUFFER_BIT);
		glColor3f(1.0,0.0,0.0);
	drawstring(210,425,0.0,"GOVERNMENT ENGINEERING COLLEGE, HASSAN",1);
		glColor3f(0.0,0.0,0.0);
	drawstring(245,385,0.0,"DEPARTMENT OF COMPUTER SCIENCE AND ENGINEERING",1);
		glColor3f(0.6,1.0,0.0);
	drawstring(210,350,0.0,"A MINI PROJECT ON COMPUTER GRAPHICS AND VISUALIZATION",1);
		glColor3f(1.0,1.0,0.0);
	drawstring(440,300,0.0,"WATER CYCLE",1);
	 	glColor3f(1.0,0.0,0.0);
	  drawstring(135,205,0.0," STUDENT NAME:",0);
	  	glColor3f(0.0,0.0,0.0);
	drawstring(140,170,0.0,"SUHA KULSUM",0);
		glColor3f(1.0,0.0,0.0);
	drawstring(710,205,0.0,"Under the Guidance of",0);
		glColor3f(0.0,0.0,0.0);
	drawstring(720,170,0.0,"Prof VASANTHA KUMARA M",0);
		glColor3f(1.0,1.0,0.0);
	drawstring(406,95,0.0,"Academic Year 2021-22",0);
glFlush();
 glutSwapBuffers();
}

void draw_pixel(GLint cx, GLint cy)
{

	glBegin(GL_POINTS);
		glVertex2i(cx,cy);
	glEnd();
}

void plotpixels(GLint h,GLint k, GLint x,GLint y)
{
	draw_pixel(x+h,y+k);
	draw_pixel(-x+h,y+k);
	draw_pixel(x+h,-y+k);
	draw_pixel(-x+h,-y+k);
	draw_pixel(y+h,x+k);
	draw_pixel(-y+h,x+k);
	draw_pixel(y+h,-x+k);
	draw_pixel(-y+h,-x+k);
}


void draw_circle(GLint h, GLint k, GLint r)
{
	GLint d=1-r, x=0, y=r;
	while(y>x)
	{
		plotpixels(h,k,x,y);
		if(d<0) d+=2*x+3;
		else
		{
			d+=2*(x-y)+5;
			--y;
		}
		++x;
	}
	plotpixels(h,k,x,y);
}

void draw_object()
{
int l;

//sky
glColor3f(0.0,0.9,0.9);
glBegin(GL_POLYGON);
glVertex2f(0,380);
glVertex2f(0,700);
glVertex2f(1100,700);
glVertex2f(1100,380);
glEnd();

//sun
	for(l=0;l<=35;l++)
{
		glColor3f(1.0,0.9,0.0);
		draw_circle(100,625,l);
}

//cloud1
	for(l=0;l<=20;l++)
	{
		glColor3f(1.0,1.0,1.0);
		draw_circle(160+m,625,l);

	}

	for(l=0;l<=35;l++)
	{
		glColor3f(1.0,1.0,1.0);
		draw_circle(200+m,625,l);
		draw_circle(225+m,625,l);
	}

	for(l=0;l<=20;l++)
	{
		glColor3f(1.0,1.0,1.0);
		draw_circle(265+m,625,l);
	}

//cloud2
	for(l=0;l<=20;l++)
	{
		glColor3f(1.0,1.0,1.0);
		draw_circle(370+m,615,l);
    }

	for(l=0;l<=35;l++)
	{

		glColor3f(1.0,1.0,1.0);
		draw_circle(410+m,615,l);
		draw_circle(435+m,615,l);
		draw_circle(470+m,615,l);
	}

for(l=0;l<=20;l++)
	{
		glColor3f(1.0,1.0,1.0);
		draw_circle(500+m,615,l);
    }

//cloud3
	for(l=0;l<=20;l++)
	{
		glColor3f(1.0,1.0,1.0);
		draw_circle(610+m,600,l);

	}

	for(l=0;l<=35;l++)
	{
		glColor3f(1.0,1.0,1.0);
		draw_circle(650+m,600,l);
		draw_circle(675+m,600,l);
	}

	for(l=0;l<=20;l++)
	{
		glColor3f(1.0,1.0,1.0);
		draw_circle(715+m,600,l);
	}

//cloud4
	for(l=0;l<=20;l++)
	{
		glColor3f(1.0,1.0,1.0);
		draw_circle(810+m,580,l);
    }

	for(l=0;l<=35;l++)
	{

		glColor3f(1.0,1.0,1.0);
		draw_circle(850+m,580,l);
		draw_circle(875+m,580,l);
		draw_circle(910+m,580,l);
	}

for(l=0;l<=20;l++)
	{
		glColor3f(1.0,1.0,1.0);
		draw_circle(940+m,580,l);
    }

//grass
glColor3f(0.6,0.8,0.196078);
glBegin(GL_POLYGON);
glVertex2f(0,160);
glVertex2f(0,380);
glVertex2f(1100,380);
glVertex2f(1100,160);
glEnd();

//Ground
glColor3f(0.0,0.3,0.0);
glBegin(GL_POLYGON);
		glVertex2f(-600,0);
		glVertex2f(-600,185);
		glVertex2f(1100,185);
		glVertex2f(1100,0);
glEnd();

//tree 1
glColor3f(0.9,0.2,0.0);
glBegin(GL_POLYGON);
glVertex2f(280,185);
glVertex2f(280,255);
glVertex2f(295,255);
glVertex2f(295,185);
glEnd();

for(l=0;l<=30;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(270,250,l);
		draw_circle(310,250,l);
	}

for(l=0;l<=25;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(280,290,l);
		draw_circle(300,290,l);
	}

for(l=0;l<=20;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(290,315,l);
	}

//tree 2
glColor3f(0.9,0.2,0.0);
glBegin(GL_POLYGON);
glVertex2f(100,135);
glVertex2f(100,285);
glVertex2f(140,285);
glVertex2f(140,135);
glEnd();

for(l=0;l<=40;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(40,280,l);
		draw_circle(90,280,l);
		draw_circle(150,280,l);
		draw_circle(210,280,l);
		draw_circle(65,340,l);
		draw_circle(115,340,l);
		draw_circle(175,340,l);

	}

for(l=0;l<=55;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(115,360,l);


	}

//lake
for(l=0;l<=230;l++)
{
		glColor3f(0.0,0.6,0.9);
		draw_circle(900,110,l);
}
glBegin(GL_POLYGON);
glColor3f(0.0,0.6,0.9);
glVertex2f(920,220);
glVertex2f(920,340);
glVertex2f(1100,340);
glVertex2f(1100,220);
glEnd();


//arrow1
glPushMatrix();
glTranslated(arx,ary,0.0);
glBegin(GL_POLYGON);        //tail
glColor3f(0.1,0.1,0.1);
glVertex2f(850+arx,250+ary);
glVertex2f(850+arx,400+ary);
glVertex2f(860+arx,400+ary);
glVertex2f(860+arx,250+ary);
glEnd();

glBegin(GL_TRIANGLES);     //head
glColor3f(0.1,0.1,0.1);
glVertex2d(840+arx,400+ary);
glVertex2d(855+arx,415+ary);
glVertex2d(870+arx,400+ary);
glEnd();

//arrow2
glBegin(GL_POLYGON);        //tail
glColor3f(0.1,0.1,0.1);
glVertex2f(880+arx,250+ary);
glVertex2f(880+arx,400+ary);
glVertex2f(890+arx,400+ary);
glVertex2f(890+arx,250+ary);
glEnd();

glBegin(GL_TRIANGLES);      //head
glColor3f(0.1,0.1,0.1);
glVertex2d(870+arx,400+ary);
glVertex2d(885+arx,415+ary);
glVertex2d(900+arx,400+ary);
glEnd();
ary+=0.2;
glLoadIdentity();
glPopMatrix();

//fish 1
glPushMatrix();
glBegin(GL_POLYGON);        //body
glColor3f(0.9,0.0,0.0);
glVertex2f(800+fsx,150+fsy);
glVertex2f(780+fsx,170+fsy);
glVertex2f(800+fsx,200+fsy);
glVertex2f(820+fsx,170+fsy);
glEnd();

glBegin(GL_TRIANGLES);      //tail
glColor3f(0.9,0.0,0.0);
glVertex2d(760+fsx,200+fsy);
glVertex2d(780+fsx,170+fsy);
glVertex2d(760+fsx,150+fsy);
glEnd();

for(l=0;l<=2;l++)          //eye
{
		glColor3f(0.1,0.1,0.1);
		draw_circle(805+fsx,175+fsy,l);
}
fsx+=0.2;
glLoadIdentity();
glPopMatrix();

//fish 2
glPushMatrix();
glBegin(GL_POLYGON);        //body
glColor3f(0.9,0.0,0.0);
glVertex2f(1000+fx,100+fy);
glVertex2f(980+fx,120+fy);
glVertex2f(1000+fx,140+fy);
glVertex2f(1020+fx,120+fy);
glEnd();

glBegin(GL_TRIANGLES);      //tail
glColor3f(0.9,0.0,0.0);
glVertex2d(1040+fx,140+fy);
glVertex2d(1020+fx,120+fy);
glVertex2d(1040+fx,100+fy);
glEnd();

for(l=0;l<=2;l++)          //eye
{
		glColor3f(0.1,0.1,0.1);
		draw_circle(995+fx,120+fy,l);
}
fx-=0.2;
glLoadIdentity();
glPopMatrix();

glFlush();
glutSwapBuffers();
}

void draw_object2()
{
int l;
//sky
glColor3f(0.0,0.0,1.9);
glBegin(GL_POLYGON);
glVertex2f(0,380);
glVertex2f(0,700);
glVertex2f(1100,700);
glVertex2f(1100,380);
glEnd();

//cloud1
	for(l=0;l<=20;l++)
	{
		glColor3f(0.658824,0.658824,0.658824);
		draw_circle(160+m,625,l);

	}

	for(l=0;l<=35;l++)
	{
		glColor3f(0.658824,0.658824,0.658824);
		draw_circle(200+m,625,l);
		draw_circle(225+m,625,l);
	}

	for(l=0;l<=20;l++)
	{
		glColor3f(0.658824,0.658824,0.658824);
		draw_circle(265+m,625,l);
	}

//cloud2
	for(l=0;l<=20;l++)
	{
		glColor3f(0.658824,0.658824,0.658824);
		draw_circle(370+m,615,l);
    }

	for(l=0;l<=35;l++)
	{

		glColor3f(0.658824,0.658824,0.658824);
		draw_circle(410+m,615,l);
		draw_circle(435+m,615,l);
		draw_circle(470+m,615,l);
	}

for(l=0;l<=20;l++)
	{
		glColor3f(0.658824,0.658824,0.658824);
		draw_circle(500+m,615,l);
    }

//cloud3
	for(l=0;l<=20;l++)
	{
		glColor3f(0.658824,0.658824,0.658824);
		draw_circle(610+m,600,l);

	}

	for(l=0;l<=35;l++)
	{
		glColor3f(0.658824,0.658824,0.658824);
		draw_circle(650+m,600,l);
		draw_circle(675+m,600,l);
	}

	for(l=0;l<=20;l++)
	{
		glColor3f(0.658824,0.658824,0.658824);
		draw_circle(715+m,600,l);
	}

//cloud4
	for(l=0;l<=20;l++)
	{
		glColor3f(0.658824,0.658824,0.658824);
		draw_circle(810+m,580,l);
    }

	for(l=0;l<=35;l++)
	{

		glColor3f(0.658824,0.658824,0.658824);
		draw_circle(850+m,580,l);
		draw_circle(875+m,580,l);
		draw_circle(910+m,580,l);
	}

for(l=0;l<=20;l++)
	{
		glColor3f(0.658824,0.658824,0.658824);
		draw_circle(940+m,580,l);
    }

//Extraclouds
for(l=0;l<=20;l++)
	{
		glColor3f(0.658824,0.658824,0.658824);
		draw_circle(50,625,l);

	}

for(l=0;l<=35;l++)
	{
		glColor3f(0.658824,0.658824,0.658824);
		draw_circle(90,625,l);
		draw_circle(125,625,l);
	}

for(l=0;l<=20;l++)
	{
		glColor3f(0.658824,0.658824,0.658824);
		draw_circle(160,625,l);
	}
//
for(l=0;l<=20;l++)
	{
		glColor3f(0.658824,0.658824,0.658824);
		draw_circle(200,555,l);

	}

for(l=0;l<=35;l++)
	{
		glColor3f(0.658824,0.658824,0.658824);
		draw_circle(240,555,l);
		draw_circle(265,555,l);
	}

for(l=0;l<=20;l++)
	{
		glColor3f(0.658824,0.658824,0.658824);
		draw_circle(300,555,l);
	}
//
for(l=0;l<=20;l++)
	{
		glColor3f(0.658824,0.658824,0.658824);
		draw_circle(700,555,l);

	}

for(l=0;l<=35;l++)
	{
		glColor3f(0.658824,0.658824,0.658824);
		draw_circle(740,555,l);
		draw_circle(765,555,l);
	}

for(l=0;l<=20;l++)
	{
		glColor3f(0.658824,0.658824,0.658824);
		draw_circle(800,555,l);
	}
//
for(l=0;l<=20;l++)
	{
		glColor3f(0.658824,0.658824,0.658824);
		draw_circle(300,555,l);

	}

for(l=0;l<=35;l++)
	{
		glColor3f(0.658824,0.658824,0.658824);
		draw_circle(340,555,l);
		draw_circle(365,555,l);
	}

for(l=0;l<=20;l++)
	{
		glColor3f(0.658824,0.658824,0.658824);
		draw_circle(400,555,l);
	}
//
for(l=0;l<=20;l++)
	{
		glColor3f(0.658824,0.658824,0.658824);
		draw_circle(500,600,l);

	}

for(l=0;l<=35;l++)
	{
		glColor3f(0.658824,0.658824,0.658824);
		draw_circle(540,600,l);
		draw_circle(565,600,l);
	}

for(l=0;l<=20;l++)
	{
		glColor3f(0.658824,0.658824,0.658824);
		draw_circle(600,600,l);
	}
//
for(l=0;l<=20;l++)
	{
		glColor3f(0.658824,0.658824,0.658824);
		draw_circle(800,650,l);

	}

for(l=0;l<=35;l++)
	{
		glColor3f(0.658824,0.658824,0.658824);
		draw_circle(840,650,l);
		draw_circle(865,650,l);
	}

for(l=0;l<=20;l++)
	{
		glColor3f(0.658824,0.658824,0.658824);
		draw_circle(900,650,l);
	}

//grass
glColor3f(0.0,0.4,0.0);
glBegin(GL_POLYGON);
glVertex2f(0,160);
glVertex2f(0,380);
glVertex2f(1100,380);
glVertex2f(1100,160);
glEnd();

//Ground
glColor3f(0.0,0.3,0.0);
glBegin(GL_POLYGON);
		glVertex2f(-600,0);
		glVertex2f(-600,185);
		glVertex2f(1100,185);
		glVertex2f(1100,0);
glEnd();

//tree 1
glColor3f(0.9,0.2,0.0);
glBegin(GL_POLYGON);
glVertex2f(280,185);
glVertex2f(280,255);
glVertex2f(295,255);
glVertex2f(295,185);
glEnd();

for(l=0;l<=30;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(270,250,l);
		draw_circle(310,250,l);
	}

for(l=0;l<=25;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(280,290,l);
		draw_circle(300,290,l);
	}

for(l=0;l<=20;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(290,315,l);
	}

//tree 2
glColor3f(0.9,0.2,0.0);
glBegin(GL_POLYGON);
glVertex2f(100,135);
glVertex2f(100,285);
glVertex2f(140,285);
glVertex2f(140,135);
glEnd();

for(l=0;l<=40;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(40,280,l);
		draw_circle(90,280,l);
		draw_circle(150,280,l);
		draw_circle(210,280,l);
		draw_circle(65,340,l);
		draw_circle(115,340,l);
		draw_circle(175,340,l);

	}

for(l=0;l<=55;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(115,360,l);


	}

//lake
for(l=0;l<=230;l++)
{
		glColor3f(0.0,0.6,0.9);
		draw_circle(900,110,l);
}
glBegin(GL_POLYGON);
glColor3f(0.0,0.6,0.9);
glVertex2f(920,220);
glVertex2f(920,340);
glVertex2f(1100,340);
glVertex2f(1100,220);
glEnd();

//fish 1
glPushMatrix();
glBegin(GL_POLYGON);        //body
glColor3f(0.9,0.0,0.0);
glVertex2f(800+fsx,150+fsy);
glVertex2f(780+fsx,170+fsy);
glVertex2f(800+fsx,200+fsy);
glVertex2f(820+fsx,170+fsy);
glEnd();

glBegin(GL_TRIANGLES);      //tail
glColor3f(0.9,0.0,0.0);
glVertex2d(760+fsx,200+fsy);
glVertex2d(780+fsx,170+fsy);
glVertex2d(760+fsx,150+fsy);
glEnd();

for(l=0;l<=2;l++)          //eye
{
		glColor3f(0.1,0.1,0.1);
		draw_circle(805+fsx,175+fsy,l);
}
fsx+=0.2;
glLoadIdentity();
glPopMatrix();

//fish 2
glPushMatrix();
glBegin(GL_POLYGON);        //body
glColor3f(0.9,0.0,0.0);
glVertex2f(1000+fx,100+fy);
glVertex2f(980+fx,120+fy);
glVertex2f(1000+fx,140+fy);
glVertex2f(1020+fx,120+fy);
glEnd();

glBegin(GL_TRIANGLES);      //tail
glColor3f(0.9,0.0,0.0);
glVertex2d(1040+fx,140+fy);
glVertex2d(1020+fx,120+fy);
glVertex2d(1040+fx,100+fy);
glEnd();

for(l=0;l<=2;l++)          //eye
{
		glColor3f(0.1,0.1,0.1);
		draw_circle(995+fx,120+fy,l);
}
fx-=0.2;
glLoadIdentity();
glPopMatrix();

glFlush();
glutSwapBuffers();
}

void draw_object3()
{
int l;
//sky
glColor3f(0.0,0.0,2.0);
glBegin(GL_POLYGON);
glVertex2f(0,380);
glVertex2f(0,700);
glVertex2f(1100,700);
glVertex2f(1100,380);
glEnd();

//cloud1
	for(l=0;l<=20;l++)
	{
		glColor3f(0.658824,0.658824,0.658824);
		draw_circle(160,625,l);

	}

	for(l=0;l<=35;l++)
	{
		glColor3f(0.658824,0.658824,0.658824);
		draw_circle(200,625,l);
		draw_circle(225,625,l);
	}

	for(l=0;l<=20;l++)
	{
		glColor3f(0.658824,0.658824,0.658824);
		draw_circle(265,625,l);
	}

//cloud2
	for(l=0;l<=20;l++)
	{
		glColor3f(0.658824,0.658824,0.658824);
		draw_circle(370,615,l);
    }

	for(l=0;l<=35;l++)
	{

		glColor3f(0.658824,0.658824,0.658824);
		draw_circle(410,615,l);
		draw_circle(435,615,l);
		draw_circle(470,615,l);
	}

for(l=0;l<=20;l++)
	{
		glColor3f(0.658824,0.658824,0.658824);
		draw_circle(500,615,l);
    }

//cloud3
	for(l=0;l<=20;l++)
	{
		glColor3f(0.658824,0.658824,0.658824);
		draw_circle(610,600,l);

	}

	for(l=0;l<=35;l++)
	{
		glColor3f(0.658824,0.658824,0.658824);
		draw_circle(650,600,l);
		draw_circle(675,600,l);
	}

	for(l=0;l<=20;l++)
	{
		glColor3f(0.658824,0.658824,0.658824);
		draw_circle(715,600,l);
	}

//cloud4
	for(l=0;l<=20;l++)
	{
		glColor3f(0.658824,0.658824,0.658824);
		draw_circle(810,580,l);
    }

	for(l=0;l<=35;l++)
	{

		glColor3f(0.658824,0.658824,0.658824);
		draw_circle(850,580,l);
		draw_circle(875,580,l);
		draw_circle(910,580,l);
	}

for(l=0;l<=20;l++)
	{
		glColor3f(0.658824,0.658824,0.658824);
		draw_circle(940,580,l);
    }

//extraclouds
for(l=0;l<=20;l++)
	{
		glColor3f(0.658824,0.658824,0.658824);
		draw_circle(50,555,l);

	}

for(l=0;l<=35;l++)
	{
		glColor3f(0.658824,0.658824,0.658824);
		draw_circle(90,555,l);
		draw_circle(130,555,l);
	}

for(l=0;l<=20;l++)
	{
		glColor3f(0.658824,0.658824,0.658824);
		draw_circle(170,555,l);
	}
//
for(l=0;l<=20;l++)
	{
		glColor3f(0.658824,0.658824,0.658824);
		draw_circle(320,555,l);

	}

for(l=0;l<=35;l++)
	{
		glColor3f(0.658824,0.658824,0.658824);
		draw_circle(360,555,l);
		draw_circle(405,555,l);
	}

for(l=0;l<=20;l++)
	{
		glColor3f(0.658824,0.658824,0.658824);
		draw_circle(440,555,l);
	}

//
for(l=0;l<=20;l++)
	{
		glColor3f(0.658824,0.658824,0.658824);
		draw_circle(940,650,l);

	}

for(l=0;l<=35;l++)
	{
		glColor3f(0.658824,0.658824,0.658824);
		draw_circle(980,650,l);
		draw_circle(1000,650,l);
	}

for(l=0;l<=20;l++)
	{
		glColor3f(0.658824,0.658824,0.658824);
		draw_circle(1040,650,l);
	}
//
for(l=0;l<=20;l++)
	{
		glColor3f(0.658824,0.658824,0.658824);
		draw_circle(600,525,l);

	}

for(l=0;l<=35;l++)
	{
		glColor3f(0.658824,0.658824,0.658824);
		draw_circle(640,525,l);
		draw_circle(680,525,l);
	}

for(l=0;l<=20;l++)
	{
		glColor3f(0.658824,0.658824,0.658824);
		draw_circle(720,525,l);
	}


//grass
glColor3f(0.0,0.4,0.0);
glBegin(GL_POLYGON);
glVertex2f(0,160);
glVertex2f(0,380);
glVertex2f(1100,380);
glVertex2f(1100,160);
glEnd();

//Ground
glColor3f(0.0,0.3,0.0);
glBegin(GL_POLYGON);
		glVertex2f(-600,0);
		glVertex2f(-600,185);
		glVertex2f(1100,185);
		glVertex2f(1100,0);
glEnd();

//tree 1
glColor3f(0.9,0.2,0.0);
glBegin(GL_POLYGON);
glVertex2f(280,185);
glVertex2f(280,255);
glVertex2f(295,255);
glVertex2f(295,185);
glEnd();

for(l=0;l<=30;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(270,250,l);
		draw_circle(310,250,l);
	}

for(l=0;l<=25;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(280,290,l);
		draw_circle(300,290,l);
	}

for(l=0;l<=20;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(290,315,l);
	}

//tree 2
glColor3f(0.9,0.2,0.0);
glBegin(GL_POLYGON);
glVertex2f(100,135);
glVertex2f(100,285);
glVertex2f(140,285);
glVertex2f(140,135);
glEnd();

for(l=0;l<=40;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(40,280,l);
		draw_circle(90,280,l);
		draw_circle(150,280,l);
		draw_circle(210,280,l);
		draw_circle(65,340,l);
		draw_circle(115,340,l);
		draw_circle(175,340,l);

	}

for(l=0;l<=55;l++)
	{
		glColor3f(0.0,0.5,0.0);
		draw_circle(115,360,l);


	}

//lake
for(l=0;l<=230;l++)
{
		glColor3f(0.0,0.6,0.9);
		draw_circle(900,110,l);
}
glBegin(GL_POLYGON);
glColor3f(0.0,0.6,0.9);
glVertex2f(920,220);
glVertex2f(920,340);
glVertex2f(1100,340);
glVertex2f(1100,220);
glEnd();

//arrow1
glPushMatrix();
glTranslated(arx,ary,0.0);
glBegin(GL_POLYGON);        //tail
glColor3f(0.1,0.1,0.1);
glVertex2f(850+arx,250+ary);
glVertex2f(850+arx,400+ary);
glVertex2f(860+arx,400+ary);
glVertex2f(860+arx,250+ary);
glEnd();

glBegin(GL_TRIANGLES);     //head
glColor3f(0.1,0.1,0.1);
glVertex2d(840+arx,250+ary);
glVertex2d(855+arx,240+ary);
glVertex2d(870+arx,250+ary);
glEnd();

//arrow2
glBegin(GL_POLYGON);        //tail
glColor3f(0.1,0.1,0.1);
glVertex2f(880+arx,250+ary);
glVertex2f(880+arx,400+ary);
glVertex2f(890+arx,400+ary);
glVertex2f(890+arx,250+ary);
glEnd();

glBegin(GL_TRIANGLES);      //head
glColor3f(0.1,0.1,0.1);
glVertex2d(870+arx,250+ary);
glVertex2d(880+arx,240+ary);
glVertex2d(900+arx,250+ary);
glEnd();
ary-=0.2;
glLoadIdentity();
glPopMatrix();


//fish 1
glPushMatrix();
glBegin(GL_POLYGON);        //body
glColor3f(0.9,0.0,0.0);
glVertex2f(800+fsx,150+fsy);
glVertex2f(780+fsx,170+fsy);
glVertex2f(800+fsx,200+fsy);
glVertex2f(820+fsx,170+fsy);
glEnd();

glBegin(GL_TRIANGLES);      //tail
glColor3f(0.9,0.0,0.0);
glVertex2d(760+fsx,200+fsy);
glVertex2d(780+fsx,170+fsy);
glVertex2d(760+fsx,150+fsy);
glEnd();

for(l=0;l<=2;l++)          //eye
{
		glColor3f(0.1,0.1,0.1);
		draw_circle(805+fsx,175+fsy,l);
}
fsx+=0.2;
glLoadIdentity();
glPopMatrix();

//fish 2
glPushMatrix();
glBegin(GL_POLYGON);        //body
glColor3f(0.9,0.0,0.0);
glVertex2f(1000+fx,100+fy);
glVertex2f(980+fx,120+fy);
glVertex2f(1000+fx,140+fy);
glVertex2f(1020+fx,120+fy);
glEnd();

glBegin(GL_TRIANGLES);      //tail
glColor3f(0.9,0.0,0.0);
glVertex2d(1040+fx,140+fy);
glVertex2d(1020+fx,120+fy);
glVertex2d(1040+fx,100+fy);
glEnd();

for(l=0;l<=2;l++)          //eye
{
		glColor3f(0.1,0.1,0.1);
		draw_circle(995+fx,120+fy,l);
}
fx-=0.2;
glLoadIdentity();
glPopMatrix();

//rain
for(l=0;l<=2;l++)
	{
	    glPushMatrix();
		glColor3f(0.0,0.9,0.9);
		draw_circle(250,400+ra,l);
		draw_circle(250,300+ra,l);
		draw_circle(250,200+ra,l);

		draw_circle(270,400+ra,l);
		draw_circle(270,300+ra,l);
		draw_circle(270,200+ra,l);

		draw_circle(300,400+ra,l);
		draw_circle(300,300+ra,l);
		draw_circle(300,200+ra,l);

		draw_circle(330,450+ra,l);
		draw_circle(330,350+ra,l);
		draw_circle(330,250+ra,l);

		draw_circle(360,450+ra,l);
		draw_circle(360,350+ra,l);
		draw_circle(360,250+ra,l);

		draw_circle(390,450+ra,l);
		draw_circle(390,300+ra,l);
		draw_circle(390,200+ra,l);

		draw_circle(420,350+ra,l);
		draw_circle(420,250+ra,l);

		glColor3f(0.0,0.7,0.9);
		draw_circle(550,400+ra,l);
		draw_circle(550,300+ra,l);
		draw_circle(550,200+ra,l);

		draw_circle(570,400+ra,l);
		draw_circle(570,300+ra,l);
		draw_circle(570,200+ra,l);

		draw_circle(600,400+ra,l);
		draw_circle(600,300+ra,l);
		draw_circle(600,200+ra,l);

		draw_circle(630,450+ra,l);
		draw_circle(630,350+ra,l);
		draw_circle(630,250+ra,l);

		draw_circle(660,450+ra,l);
		draw_circle(660,350+ra,l);
		draw_circle(660,250+ra,l);

		draw_circle(690,450+ra,l);
		draw_circle(690,300+ra,l);
		draw_circle(690,200+ra,l);

		draw_circle(720,350+ra,l);
		draw_circle(720,250+ra,l);

        glColor3f(0.0,0.9,0.9);
		draw_circle(850,400+ra,l);
		draw_circle(850,300+ra,l);
		draw_circle(850,200+ra,l);

		draw_circle(870,400+ra,l);
		draw_circle(870,300+ra,l);
		draw_circle(870,200+ra,l);

		draw_circle(900,400+ra,l);
		draw_circle(900,300+ra,l);
		draw_circle(900,200+ra,l);

		draw_circle(930,450+ra,l);
		draw_circle(930,350+ra,l);
		draw_circle(930,250+ra,l);

		draw_circle(960,450+ra,l);
		draw_circle(960,350+ra,l);
		draw_circle(960,250+ra,l);

		draw_circle(990,450+ra,l);
		draw_circle(990,300+ra,l);
		draw_circle(990,200+ra,l);

		draw_circle(1020,350+ra,l);
		draw_circle(1020,250+ra,l);

        glColor3f(0.0,0.9,0.9);
		draw_circle(50,400+ra,l);
		draw_circle(50,300+ra,l);
		draw_circle(50,200+ra,l);

		draw_circle(70,400+ra,l);
		draw_circle(70,300+ra,l);
		draw_circle(70,200+ra,l);

		draw_circle(100,400+ra,l);
		draw_circle(100,300+ra,l);
		draw_circle(100,200+ra,l);

		draw_circle(130,450+ra,l);
		draw_circle(130,350+ra,l);
		draw_circle(130,250+ra,l);

		draw_circle(160,450+ra,l);
		draw_circle(160,350+ra,l);
		draw_circle(160,250+ra,l);

		draw_circle(190,450+ra,l);
		draw_circle(190,300+ra,l);
		draw_circle(190,200+ra,l);

		draw_circle(220,350+ra,l);
		draw_circle(220,250+ra,l);

		ra-=0.02;
        glLoadIdentity();
        glPopMatrix();
	}

glFlush();
glutSwapBuffers();
}

void idle()
{
if(count<=3)
{
glClearColor(1.0,1.0,1.0,1.0);

     i+=SPEED/10;
     b+=SPEED/10;
     m+=SPEED/150;
	n-=2;
	 o+=0.2;
	c+=2;
}
if(i>1900)
	 i=800.0;
if(m>1100)
	 m=0.0;
if(b>500)
{
	b=0.0;
	i=800.0;
	count=count+1;
}
glutPostRedisplay();
}

void mouse(int btn,int state,int x,int y)
{
	if(btn==GLUT_LEFT_BUTTON && state==GLUT_UP)
exit(0);
}

void main_menu(int index)
{
    if(index==1)
    {
        glutDisplayFunc(display());
    }
    else if(index==2)
    {
        glutDisplayFunc(display2());
    }
    else if(index==3)
    {
        glutDisplayFunc(display3());
    }
    else exit(0);
}

void myinit()
{
glClearColor(1.0,1.0,1.0,1.0);
glColor3f(0.0,0.0,1.0);
glPointSize(2.0);
glShadeModel(GL_FLAT);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0,1100.0,0.0,700.0);
}

void display()
{
glClear(GL_COLOR_BUFFER_BIT);
draw_object();
glutPostRedisplay();
glFlush();
}

void display2()
{
glClear(GL_COLOR_BUFFER_BIT);
draw_object2();
glutPostRedisplay();
glFlush();
}

void display3()
{
glClear(GL_COLOR_BUFFER_BIT);
draw_object3();
glutPostRedisplay();
glFlush();
}

int main(int argc,char** argv)
{
    printf("Project by CSE MiniProjects.com\n");
    printf("----------------------------------------------------");
    printf("WATER CYCLE");
    printf("--------------------------------------------------------\n\n");
    printf("Press RIGHT MOUSE BUTTON to display menu. \n\n");
	printf("Press LEFT MOUSE BUTTON to quit the program. \n\n\n");
    printf("Press any key and Hit ENTER.\n");
	scanf("%s",&ch);

    glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
	glutInitWindowSize(1300.0,700.0);
	glutInitWindowPosition(0,0);
	glutCreateWindow("WATER CYCLE");
	glutDisplayFunc(screen);
	glutIdleFunc(idle);
	glutMouseFunc(mouse);
	myinit();
	glutCreateMenu(main_menu);
	glutAddMenuEntry("EVAPORATION",1);
	glutAddMenuEntry("CONDENSATION",2);
	glutAddMenuEntry("PRECIPITATION",3);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	glutMainLoop();
	return 0;
}
