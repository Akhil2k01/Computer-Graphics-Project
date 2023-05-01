#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <GL/glut.h>

float k,x,y,d=0,v,db,bd,r=0,sh=0,go=0;
int delay=0,count=0,shake=0,fetch=0,last=0,read;
void *font;

void setFont(void *getfont)
{
	font=getfont;
}

void output(float x,float y,float z,char *str)
{
	int len = strlen(str);
	int i;
	glRasterPos3f(x,y,z);
	for(i=0;i<len;i++)
	{
		glColor3f(0.0,0.0,0.0);
		glutBitmapCharacter(font,str[i]);
	}
}

void background()
{
	glPushMatrix();
	glColor3f(0.713, 0.807, 0.984);
	glTranslatef(680,800,0);
	glutSolidSphere(430,100,100);
	glPopMatrix();
	
	glPushMatrix();
	glColor3f(0.713, 0.807, 0.984);
	glTranslatef(200,300,0);
	glutSolidSphere(450,100,100);
	glPopMatrix();
	
	glBegin(GL_POLYGON);
		glColor3f(0.996, 0.8, 0.447);
		glVertex2i(0,700);
		glColor3f(0.984, 0.698, 0.176);
		glVertex2i(300,1000);
		glColor3f(0.996, 0.8, 0.447);
		glVertex2i(1000,500);
		glColor3f(0.984, 0.698, 0.176);
		glVertex2i(600,0);
	glEnd();
	
	glLineWidth(100);
	glBegin(GL_LINE_LOOP);
		glColor3f(0, 0, 0);
		glVertex2i(0,700);
		glVertex2i(300,1000);
		glVertex2i(1000,500);
		glVertex2i(600,0);
	glEnd();
	
	glLineWidth(5);
	glBegin(GL_LINE_LOOP);
		glColor3f(1, 0.647, 0);
		glVertex2i(0,700);
		glVertex2i(300,1000);
		glVertex2i(1000,500);
		glVertex2i(600,0);
	glEnd();
}

void frontscr(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	background();
	
	setFont(GLUT_BITMAP_TIMES_ROMAN_24);
	
	glColor3f(0.003, 0.219, 0.615);
	output(230.0,800.0,0.0,"MANGALORE INSTITUTE OF TECHNOLOGY AND ENGINEERING");
	glColor3f(0.011, 0.282, 0.788);
	output(250.0,750.0,0.0,"DEPARTMENT OF COMPUTER SCIENCE AND ENGINEERING");
	glColor3f(0.003, 0.219, 0.615);
	output(330.0,550.0,0.0,"COMPUTER GRAPHICS MINI PROJECT");
	glColor3f(0.450, 0.478, 0.529);
	output(420.0,500.0,0.0,"A GREEDY DOG");
	glColor3f(1,1,1);
	output(700.0,350.0,0.0,"BY:");
	glColor3f(1.0,1.0,1.0);
	output(730,300,0.0,"AKHIL			4MT19CS016");
	glColor3f(1.0,1.0,1.0);
	output(730,250,0.0,"ANISH A HEGDE	4MT19CS022");
	glColor3f(0,0,0);
	
	setFont(GLUT_BITMAP_HELVETICA_18);
	output(420,150,0.0,"PRESS S TO START");
	output(425,100,0.0,"PRESS Q TO OUIT");
	
	glutSwapBuffers();
	glFlush();
}

void timer(int e)
{
	k -= 0.2;
	if(k==20) k=0;
	v += 0.5;
	bd -= 1.5;
	r += 2;
	if(r == 50) r=0;
	glutPostRedisplay();
	glutTimerFunc(10000,timer,0);
}

void timerdog(int e)
{
	d += 1.5;db += 2.0;sh += 0.5;
	if(sh == 1) sh=-1;
	glutPostRedisplay();
	glutTimerFunc(10000,timer,0);
}

void rings()
{
	count++;
	glPushMatrix();
	glColor3f(0,0,0);
	glTranslatef(900,170,0);
	glutSolidSphere(r,100,100);
	glPopMatrix();
	glPushMatrix();
	glColor3f(0.043, 0.023, 0.498);
	glTranslatef(900,170,0);
	glutSolidSphere(r-5,100,100);
	glPopMatrix();
	glPushMatrix();
	glColor3f(0.239, 0.215, 0.764);
	glTranslatef(900,170,0);
	glutSolidSphere(r-10,100,100);
	glPopMatrix();
	glPushMatrix();
	glColor3f(0.498, 0.482, 0.917);
	glTranslatef(900,170,0);
	glutSolidSphere(r-20,100,100);
	glPopMatrix();
	glPushMatrix();
	glColor3f(0.560, 0.541, 0.976);
	glTranslatef(900,170,0);
	glutSolidSphere(r-25,100,100);
	glPopMatrix();
	glPushMatrix();
	glColor3f(0,1,1);
	glTranslatef(900,170,0);
	glutSolidSphere(r-30,100,100);
	glPopMatrix();
	last=1;
}

void sky()
{
	glBegin(GL_POLYGON);
		glColor3f(0.396078431372549,0.7607843137254902,0.9607843137254902);
		glVertex2i(0,650);
		glColor3f(0.0156862745098039,0.5294117647058824,0.8862745098039216);
		glVertex2i(0,1000);
		glColor3f(1.0,0.8705882352941176,0.5176470588235294);
		glVertex2i(700,1000);
		glVertex2i(1000,1000);
		glColor3f(1.0,0.8705882352941176,0.5176470588235294);
		glVertex2i(1000,900);
		glColor3f(0.396078431372549,0.7607843137254902,0.9607843137254902);
		glVertex2i(1000,650);
	glEnd();
}

void ground()
{
	glBegin(GL_POLYGON);
		glColor3f(0.0,1.0,0.0);
		glVertex2i(0,0);
		glVertex2i(0,650);
		glVertex2i(1000,650);
		glVertex2i(1000,0);
	glEnd();		
}
void eroad()
{
	glColor3f(0.6509803921568627,0.6352941176470588,0.007843137254902);
	glBegin(GL_POLYGON);
		glVertex2i(0,100);
		glVertex2i(0,250);
		glVertex2i(670,250);
		glVertex2i(670,100);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex2i(650,250);
		glVertex2i(730,320);
		glVertex2i(830,270);
		glVertex2i(780,160);
		glVertex2i(670,100);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex2i(720,300);
		glVertex2i(750,650);
		glVertex2i(810,650);
		glVertex2i(830,270);
	glEnd();
}

void lake()
{
	glColor3f(0.0,0.0,0.5);
	glBegin(GL_POLYGON);
		glVertex2i(830,650);
		glVertex2i(860,240);
		glVertex2i(1000,240);
		glVertex2i(1000,650);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex2i(860,240);
		glVertex2i(780,0);
		glVertex2i(1000,0);
		glVertex2i(1000,240);
	glEnd();	
}

void sroad()
{
	glColor3f(0.6509803921568627,0.6352941176470588,0.007843137254902);
	glBegin(GL_POLYGON);
		glVertex2i(0,100);
		glVertex2i(0,250);
		glVertex2i(1000,250);
		glVertex2i(1000,100);
	glEnd();
}

void road()
{
	glColor3f(0.6509803921568627,0.6352941176470588,0.007843137254902);
	glBegin(GL_POLYGON);
		glVertex2i(0,100);
		glVertex2i(0,250);
		glVertex2i(1000,250);
		glVertex2i(1000,100);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex2i(670,250);
		glVertex2i(730,290);
		glVertex2i(770,290);
		glVertex2i(830,250);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex2i(730,290);
		glVertex2i(730,700);
		glVertex2i(770,700);
		glVertex2i(770,290);
	glEnd();
}

void sun()
{
	glColor3f(1.0,0.792156862745098,0.3098039215686275);
	glPushMatrix();
	glTranslatef(800,920,0);
	glutSolidSphere(80,10,15);
	glPopMatrix();
	glColor3f(1.0,0.694117647,0.0);
	glPushMatrix();
	glTranslatef(800,920,0);
	glutSolidSphere(55,120,120);
	glPopMatrix();
}

void cloud(float x, float y)
{
	glColor3f(1.0,1.0,1.0);	
	glPushMatrix();
	glTranslatef(x,y,0);
	glutSolidSphere(40,100,100);
	glPopMatrix();	
	glPushMatrix();
	glTranslatef(x-50,y,0);
	glutSolidSphere(40,100,100);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(x+50,y+10,0);
	glutSolidSphere(40,100,100);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(x-10,y+40,0);
	glutSolidSphere(50,100,100);
	glPopMatrix();
}

void bush()
{
	glColor3f(0.0,0.5019607843137255,0.0);	
	glPushMatrix();
	glTranslatef(180,260,0);
	glutSolidSphere(40,100,100);
	glPopMatrix();	
	glPushMatrix();
	glTranslatef(220,290,0);
	glutSolidSphere(40,100,100);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(240,260,0);
	glutSolidSphere(50,100,100);
	glPopMatrix();
}

void tree1(int a)
{	
	glBegin(GL_POLYGON);
		glColor3f(0.1647058823529412,0.0901960784313725,0.0431372549019608);
		glVertex2f(110.0,450.0);
		glVertex2f(110.0,580.0);
		glVertex2f(150.0,580.0);
		glVertex2f(150.0,450.0);
	glEnd();
	glColor3f(0.0,0.5019607843137255,0.0);
	glPushMatrix();
	glTranslatef(110,610,0);
	glutSolidSphere(50,100,100);
	glPopMatrix();	
	glPushMatrix();
	glTranslatef(150,610,0);
	glutSolidSphere(50,100,100);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(120,665,0);
	glutSolidSphere(45,100,100);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(140,665,0);
	glutSolidSphere(45,100,100);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(130,720,0);
	glutSolidSphere(40,100,100);
	glPopMatrix();
	glPointSize(3);
	if(a==1)
	{
		glBegin(GL_POINTS);
			glColor3f(1.0,1.0,0.0);
			glVertex2i(100,610);
			glVertex2i(130,610);
			glVertex2i(110,650);
			glVertex2i(140,700);
			glVertex2i(150,630);
			glVertex2i(120,690);
			glVertex2i(80,610);
			glVertex2i(170,610);
			glVertex2i(140,750);
			glVertex2i(120,720);
			glVertex2i(90,690);
			glVertex2i(160,640);
		glEnd();
	}
	else{
		glBegin(GL_POINTS);
			glColor3f(0.0,1.0,1.0);
			glVertex2i(100,610);
			glVertex2i(130,610);
			glVertex2i(110,650);
			glVertex2i(140,700);
			glVertex2i(150,630);
			glVertex2i(120,690);
			glVertex2i(80,610);
			glVertex2i(170,610);
			glVertex2i(140,750);
			glVertex2i(120,720);
			glVertex2i(90,690);
			glVertex2i(160,640);
		glEnd();
	}
}

void tree2()
{
	glBegin(GL_POLYGON);
		glColor3f(0.270588235,0.137254902,0.0);
		glVertex2f(45.0,450.0);
		glVertex2f(45.0,700.0);
		glVertex2f(75.0,700.0);
		glVertex2f(75.0,450.0);
	glEnd();
	glBegin(GL_POLYGON);
		glColor3f(0.058823529,0.184313725,0.003921569);
		glVertex2f(0.0,600.0);
		glVertex2f(120.0,600.0);
		glVertex2f(60.0,800.0);
	glEnd();
	glBegin(GL_POLYGON);
		glColor3f(0.058823529,0.184313725,0.003921569);
		glVertex2f(0.0,700.0);
		glVertex2f(120.0,700.0);
		glVertex2f(60.0,850.0);
	glEnd();
}

void window()
{
	glVertex2i(640,590);
	glVertex2i(640,630);
	glVertex2i(690,630);
	glVertex2i(690,590);	
}
void door()
{
	glVertex2i(730,550);
	glVertex2i(730,650);
	glVertex2i(770,650);
	glVertex2i(770,550);
}
void hbody()
{
	glVertex2i(600,700);
	glVertex2i(600,550);
	glVertex2i(800,550);
	glVertex2i(800,700);
}
void roof()
{
	glVertex2i(550,700);
	glVertex2i(600,770);
	glVertex2i(800,770);
	glVertex2i(850,700);
}
void house()
{
	glPolygonMode(GL_FRONT,GL_LINE);
	glBegin(GL_POLYGON);		//body
		glColor3f(0.0,0.0,0.0);
		hbody();
	glEnd();
	glPolygonMode(GL_FRONT,GL_FILL);
	glBegin(GL_POLYGON);		//body
		glColor3f(0.909, 0.368, 0.290);
		hbody();
	glEnd();
	glBegin(GL_LINE_LOOP);		//roof
		glColor3f(0.0,0.0,0.0);
		roof();
	glEnd();
	glBegin(GL_POLYGON);		//roof
		glColor3f(0.549, 0.490, 0.431);
		roof();
	glEnd();
	glBegin(GL_POLYGON);		//door
		glColor3f(0.992, 0.733, 0.545);
		door();
	glEnd();
	glBegin(GL_POLYGON);		//window
		glColor3f(1.0,0.0,1.0);
		window();
	glEnd();
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_LINE_LOOP);		//door
		door();
	glEnd();
	glBegin(GL_LINE_LOOP);		//window
		window();
	glEnd();
	glBegin(GL_LINES);
		x=650;
		for(int i=0;i<5;i++){
		glVertex2i(x,590);
		glVertex2i(x,630);
		x+=10;
		}
		glVertex2i(750,550);
		glVertex2i(750,650);
	glEnd();
}

void bone()
{
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
		glVertex2i(590,210);
		glVertex2i(600,220);
		glVertex2i(550,240);
		glVertex2i(540,230);
	glEnd();
	glPushMatrix();
	glTranslatef(590,210,0);
	glutSolidSphere(8,100,100);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(600,220,0);
	glutSolidSphere(8,100,100);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(550,240,0);
	glutSolidSphere(8,100,100);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(540,230,0);
	glutSolidSphere(8,100,100);
	glPopMatrix();	
}

void tail()
{
	glColor3f(1, 0.592, 0.2);
	glBegin(GL_POLYGON);				
		glVertex2i(34,58);
		glVertex2f(25,58.5);
		glVertex2i(24,54);
		glVertex2i(25,53);
		glVertex2i(34,48);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex2f(25,58.5);
		glVertex2i(24,62);
		glVertex2i(21,61);
		glVertex2i(24,54);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex2i(24,62);
		glVertex2i(25,68);
		glVertex2i(22,68);
		glVertex2i(21,61);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex2i(25,68);
		glVertex2i(27,71);
		glVertex2i(22,68);
	glEnd();
	
}

void legb1()
{
	glColor3f(1, 0.592, 0.2);
	glVertex2i(33,44);
	glVertex2i(35,32);
	glColor3f(0.945, 0.737, 0.533);
	glVertex2i(34,15);
	glVertex2i(39,15);
	glVertex2i(37,16);
	glColor3f(1, 0.592, 0.2);
	glVertex2i(38,32);
	glVertex2i(42,40);
}
void legb2()
{
	glColor3f(1, 0.592, 0.2);
	glVertex2i(38,40);
	glVertex2i(40,32);
	glColor3f(0.945, 0.737, 0.533);
	glVertex2i(39,15);
	glVertex2i(44,15);
	glVertex2i(42,16);
	glColor3f(1, 0.592, 0.2);
	glVertex2i(43,32);
	glVertex2i(45,40);
}
void legf1()
{
	glColor3f(1, 0.592, 0.2);
	glVertex2i(50,40);
	glVertex2i(52,32);
	glColor3f(0.945, 0.737, 0.533);
	glVertex2i(51,15);
	glVertex2i(56,15);
	glVertex2i(54,16);
	glColor3f(1, 0.592, 0.2);
	glVertex2i(55,32);
	glVertex2i(57,40);
}
void legf2()
{
	glColor3f(1, 0.592, 0.2);
	glVertex2i(55,40);
	glVertex2i(57,32);
	glColor3f(0.945, 0.737, 0.533);
	glVertex2i(56,15);
	glVertex2i(61,15);
	glVertex2i(59,16);
	glColor3f(1, 0.592, 0.2);
	glVertex2i(60,32);
	glVertex2i(62,40);
}

void neck()
{
	glBegin(GL_POLYGON);				//neck
		glVertex2i(68,60);
		glColor3f(0.980, 0.694, 0.419);
		glVertex2i(70,77);
		glVertex2i(65,77);
		glVertex2i(60,60);
	glEnd();
	glBegin(GL_POLYGON);			
		glVertex2i(62,63);
		glVertex2i(58,60);
		glVertex2i(60,60);
	glEnd();
}

void dog()
{
	glBegin(GL_POLYGON);					//body
		glColor3f(1, 0.592, 0.2);
		glVertex2i(30,58);
		glVertex2i(34,60);
		glVertex2i(58,60);
		glColor3f(0.980, 0.694, 0.419);
		glVertex2i(68,60);
		glColor3f(1, 0.592, 0.2);
		glVertex2i(62,40);
		glVertex2i(35,40);
	glEnd();
	
	glPushMatrix();							//back
	glColor3f(1, 0.592, 0.2);
	glTranslatef(40,54,0);
	glutSolidSphere(9,25,25);
	glColor3f(1, 0.592, 0.2);
	glTranslatef(5,-1,0);
	glutSolidSphere(9,25,25);
	glTranslatef(6,-1,0);
	glutSolidSphere(9,25,25);
	glTranslatef(3,-5,0);
	glutSolidSphere(9,25,25);
	glPopMatrix();
	
	glColor3f(1, 0.592, 0.2);				//stomach
	glPushMatrix();				
	glTranslatef(40.5,49,0);
	glutSolidSphere(9,25,25);
	glPopMatrix();
	glColor3f(1, 0.592, 0.2);
	glPushMatrix();				
	glTranslatef(45,44,0);
	glutSolidSphere(9,25,25);
	glPopMatrix();
	
	if(shake == 0)	tail();
	else if(shake == 1)
	{
		glPushMatrix();
		glTranslatef(sh,sh,0);
		tail();
		glPopMatrix();
	}
	
	glBegin(GL_POLYGON);				//legs	
		legb1();
	glEnd();
	glBegin(GL_POLYGON);			
		legb2();
	glEnd();
	glBegin(GL_POLYGON);			
		legf1();
	glEnd();
	glBegin(GL_POLYGON);			
		legf2();
	glEnd();
	
	glColor3f(0.945, 0.737, 0.533);
	neck();
	
	glColor3f(0.945, 0.737, 0.533);
	glBegin(GL_POLYGON);				//mouth
		glVertex2i(72,70);
		glVertex2i(78,70);
		glColor3f(1, 0.592, 0.2);
		glVertex2i(79,74);
		glVertex2i(72,76);
	glEnd();
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_LINES);
		glVertex2f(78.25,71);
		glVertex2f(75.5,72);
	glEnd();
	
	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);				//nose
		glVertex2f(77.5,74.5);
		glVertex2i(79,74);
		glVertex2f(78.65,72.5);
	glEnd();
	
	glColor3f(1, 0.615, 0.321);
	glBegin(GL_POLYGON);				//ear1
		glVertex2f(71,78);
		glVertex2f(71.5,86);
		glVertex2f(69,78);
	glEnd();
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_LINES);
		glVertex2f(71,78);
		glVertex2f(71.4,83);
	glEnd();
	
	glColor3f(0.980, 0.694, 0.419);
	glPushMatrix();						//head
	glTranslatef(69,74,0);
	glutSolidSphere(5,25,25);
	glPopMatrix();
	
	glColor3f(1.0,1.0,1.0);	
	glPushMatrix();						//eye
	glTranslatef(71,76,0);
	glutSolidSphere(1,25,25);
	glPopMatrix();
	glColor3f(0.0,0.0,0.0);	
	glPushMatrix();						
	glTranslatef(71.5,76,0);
	glutSolidSphere(0.5,25,25);
	glPopMatrix();
	
	glColor3f(1, 0.615, 0.321);
	glBegin(GL_POLYGON);				//ear2
		glVertex2f(69,78);
		glVertex2f(69.5,86);
		glVertex2f(67,78);
	glEnd();
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_LINES);
		glVertex2f(69,78);
		glVertex2f(69.4,83);
	glEnd();
}

void halfbone()
{
	glColor3f(1.0,1.0,1.0);
	glBegin(GL_POLYGON);
		glVertex2i(592,422);
		glVertex2i(600,420);
		glVertex2i(590,400);
		glVertex2i(582,402);
	glEnd();
	glPushMatrix();
	glTranslatef(590,400,0);
	glutSolidSphere(5,100,100);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(582,402,0);
	glutSolidSphere(5,100,100);
	glPopMatrix();
}

void createCloud(int k,int x,int y)
{
	glPushMatrix();
	glTranslatef(k,0,0);
	cloud(x,y);
	cloud(x-400,y+80);
	cloud(x-200,y);
	glScalef(0.8,1.0,1.0);
	glTranslatef(k+1500,0,0);
	cloud(x,y);
	cloud(x-400,y+80);
	cloud(x+800,y+100);
	glScalef(1.2,1.0,1.0);
	glTranslatef(k+1500,0,0);
	cloud(x,y);
	cloud(x-400,y+80);
	cloud(x+800,y+100);
	glTranslatef(k+1500,0,0);
	cloud(x,y);
	cloud(x-400,y+80);
	cloud(x+800,y+100);
	glPopMatrix();
}

void grass()
{
	glBegin(GL_POLYGON);
	glColor3f(0.058823529,0.184313725,0.003921569);
	glVertex2f(20,50);
	glVertex2f(50,50);
	glVertex2f(35,130);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(20,50);
	glVertex2f(50,50);
	glVertex2f(28,125);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(20,50);
	glVertex2f(50,50);
	glVertex2f(42,125);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(20,50);
	glVertex2f(50,50);
	glVertex2f(56,125);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex2f(20,50);
	glVertex2f(50,50);
	glVertex2f(14,125);
	glEnd();
}
void home2()
{
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_POLYGON);
		glVertex2i(680,600);
		glVertex2i(680,700);
		glVertex2i(550,700);
		glVertex2i(550,600);
	glEnd();
	glColor3f(1.0,1.0,0.0);
	glBegin(GL_POLYGON);
		glVertex2i(700,700);
		glVertex2i(700,730);
		glVertex2i(530,730);
		glVertex2i(530,700);
	glEnd();
	glColor3f(1.0,0.0,1.0);
	glBegin(GL_POLYGON);
		glVertex2i(700,730);
		glVertex2i(700,740);
		glVertex2i(530,740);
		glVertex2i(530,730);
	glEnd();
	glColor3f(0.0,1.0,1.0);
	glBegin(GL_POLYGON);
		glVertex2i(660,640);
		glVertex2i(660,680);
		glVertex2i(620,680);
		glVertex2i(620,640);
		glEnd();
	glColor3f(0.0,0.0,0.0);
	glLineWidth(1);
	glBegin(GL_LINE_LOOP);
		glVertex2i(660,640);
		glVertex2i(660,680);
		glVertex2i(620,680);
		glVertex2i(620,640);
	glEnd();
	glColor3f(0.0,0.0,0.0);
	glLineWidth(1);
	glBegin(GL_LINES);
		glVertex2i(650,640);
		glVertex2i(650,680);
		glVertex2i(640,680);
		glVertex2i(640,640);
		glVertex2i(630,680);
		glVertex2i(630,640);
	glEnd();
	glColor3f(0.6509803921568627,0.6352941176470588,0.007843137254902);
	glBegin(GL_POLYGON);
		glVertex2i(680,610);
		glVertex2i(680,640);
		glVertex2i(750,640);
		glVertex2i(750,610);
	glEnd();
}

void homeline()
{
	//glLineWidth(1);
	glBegin(GL_LINE_LOOP);		//body1
		glColor3f(0, 0, 0);
		glVertex2i(600,650);
		glVertex2i(800,650);
		glVertex2i(800,450);
		glVertex2i(600,450);
	glEnd();
	glBegin(GL_LINE_LOOP);		//roof1
		glColor3f(0, 0, 0);
		glVertex2i(550,650);
		glVertex2i(600,770);
		glVertex2i(800,770);
		glVertex2i(850,650);
	glEnd();
	glBegin(GL_LINE_LOOP);		//body2
		glColor3f(0, 0, 0);
		glVertex2i(100,450);
		glVertex2i(250,450);
		glVertex2i(250,650);
		glVertex2i(100,650);
	glEnd();
	glBegin(GL_LINE_LOOP);		//roof2
		glColor3f(0, 0, 0);
		glVertex2i(90,650);
		glVertex2i(175,800);
		glVertex2i(260,650);
	glEnd();
	glBegin(GL_LINE_LOOP);		//door1
		glColor3f(0, 0, 0);
		glVertex2i(680,590);
		glVertex2i(680,450);
		glVertex2i(720,450);
		glVertex2i(720,590);
	glEnd();
	glBegin(GL_LINE_LOOP);		//window11
		glColor3f(0, 0, 0);
	    glVertex2i(610,530);
		glVertex2i(660,530);
		glVertex2i(660,580);
		glVertex2i(610,580);
	glEnd();
	glBegin(GL_LINE_LOOP);		//window12
		glColor3f(0, 0, 0);
	    glVertex2i(740,530);
		glVertex2i(790,530);
		glVertex2i(790,580);
		glVertex2i(740,580);
	glEnd();
	glBegin(GL_LINE_LOOP);		//door2
		glColor3f(0, 0, 0);
		glVertex2i(190,450);
		glVertex2i(240,450);
		glVertex2i(240,580);
		glVertex2i(190,580);
	glEnd();
	glBegin(GL_LINE_LOOP);		//window21
		glColor3f(0, 0, 0);
	    glVertex2i(120,500);
		glVertex2i(170,500);
		glVertex2i(170,570);
		glVertex2i(120,570);
	glEnd();
	
	glBegin(GL_LINES);
		glVertex2i(130,500);glVertex2i(130,570);		//window21
		glVertex2i(140,500);glVertex2i(140,570);
		glVertex2i(150,500);glVertex2i(150,570);
		glVertex2i(160,500);glVertex2i(160,570);
		
		glVertex2i(620,530);glVertex2i(620,580);		//window11
		glVertex2i(630,530);glVertex2i(630,580);
		glVertex2i(640,530);glVertex2i(640,580);
		glVertex2i(650,530);glVertex2i(650,580);
		
		glVertex2i(750,530);glVertex2i(750,580);		//window12
		glVertex2i(760,530);glVertex2i(760,580);
		glVertex2i(770,530);glVertex2i(770,580);
		glVertex2i(780,530);glVertex2i(780,580);
	glEnd();
}

void home()
{
	glBegin(GL_POLYGON);	//body1
		glColor3f(0.635, 0.450, 0.988);
		glVertex2i(600,650);
		glVertex2i(800,650);
		glVertex2i(800,450);
		glVertex2i(600,450);
	glEnd();
	glBegin(GL_POLYGON);	//roof1
		glColor3f(0.549, 0.490, 0.431);
		glVertex2i(550,650);
		glColor3f(0.509, 0.458, 0.407);
		glVertex2i(600,770);
		glColor3f(0.780, 0.729, 0.682);
		glVertex2i(800,770);
		glColor3f(0.509, 0.458, 0.407);
		glVertex2i(850,650);
	glEnd();
	glBegin(GL_POLYGON);    //body2
		glColor3f(0.921, 0.925, 0.454);
		glVertex2i(100,450);
		glVertex2i(100,650);
		glColor3f(0.921, 0.925, 0.454);
		glVertex2i(250,650);
		glVertex2i(250,450);
	glEnd();
	glBegin(GL_POLYGON);	//roof2
		glColor3f(0.650, 0.478, 0.356);
		glVertex2i(90,650);
		glVertex2i(175,800);
		glVertex2i(260,650);
	glEnd();
	glPushMatrix();
	glColor3f(0, 0, 0);
	glTranslatef(175,700,0);
	glutSolidSphere(30,100,100);
	glPopMatrix();
	glPushMatrix();
	glColor3f(1, 0.670, 0.341);
	glTranslatef(175,700,0);
	glutSolidSphere(28,100,100);
	glPopMatrix();
	glBegin(GL_POLYGON);	//door1
		glColor3f(0.509, 0.286, 0.043);
		glVertex2i(680,590);
		glVertex2i(680,450);
		glColor3f(0.717, 0.435, 0.125);
		glVertex2i(720,450);
		glVertex2i(720,590);
	glEnd();
	glBegin(GL_POLYGON);	//window11
		glColor3f(1.0,0.694117647,0.0);
	    glVertex2i(610,530);
		glVertex2i(660,530);
		glVertex2i(660,580);
		glVertex2i(610,580);
	glEnd();
	glBegin(GL_POLYGON);	//window12
		glColor3f(1.0,0.694117647,0.0);
	    glVertex2i(740,530);
		glVertex2i(790,530);
		glVertex2i(790,580);
		glVertex2i(740,580);
	glEnd();
	glBegin(GL_POLYGON);	//door2
		glColor3f(0.0,1.0,1.0);
		glColor3f(0.509, 0.286, 0.043);
		glVertex2i(190,450);
		glVertex2i(190,580);
		glColor3f(0.717, 0.435, 0.125);
		glVertex2i(240,580);
		glVertex2i(240,450);
	glEnd();
	glBegin(GL_POLYGON);	//window21
		glColor3f(0.811, 0.549, 0.725);
	    glVertex2i(120,500);
	    glVertex2i(120,570);
	    glColor3f(0.992, 0.607, 0.870);
		glVertex2i(170,570);
		glVertex2i(170,500);
	glEnd();
	homeline();
}

void imagine(int delay)
{
	glColor3f(0.0,1.0,1.0);
	glPushMatrix();
	glTranslatef(880,500,0);
	glutSolidSphere(5,100,100);
	glPopMatrix();	
	if(delay>=130){
	glPushMatrix();
	glTranslatef(890,550,0);
	glutSolidSphere(10,100,100);
	glPopMatrix();	
	glPushMatrix();	

	glTranslatef(880,630,0);
	glutSolidSphere(30,100,100);
	glPopMatrix();	
	glPushMatrix();
	glTranslatef(900,600,0);
	glutSolidSphere(20,100,100);
	glPopMatrix();
	glPushMatrix();	
	glTranslatef(930,600,0);
	glutSolidSphere(20,100,100);
	glPopMatrix();	
	glPushMatrix();	
	glTranslatef(950,620,0);
	glutSolidSphere(20,100,100);
	glPopMatrix();	
	glPushMatrix();	
	glTranslatef(920,650,0);
	glutSolidSphere(25,100,100);
	glPopMatrix();	
	glPushMatrix();	
	glTranslatef(890,660,0);
	glutSolidSphere(20,100,100);
	glPopMatrix();	
	glPushMatrix();	
	glTranslatef(940,640,0);
	glutSolidSphere(20,100,100);
	glPopMatrix();	
	glPushMatrix();	
	glTranslatef(920,630,0);
	glutSolidSphere(30,100,100);
	glPopMatrix();	

	glPushMatrix();
	glRotatef(40,0,0,1);
	glTranslatef(760.0,-210.0,0.0);
	glScalef(0.6,0.6,0.0);
	bone();
	glTranslatef(30.0,-100.0,0.0);
	bone();
	glPopMatrix();
	
	glColor3f(0.0,0.0,0.0);
	glLineWidth(2);
	glBegin(GL_LINES);
		glVertex2i(915,620);
		glVertex2i(915,640);
		glVertex2i(908,630);
		glVertex2i(922,630);
	glEnd();
	}
}

void moralscr()
{
	printf("Started Moral Screen\n");
	
	glClear(GL_COLOR_BUFFER_BIT);
	
	background();
	
	setFont(GLUT_BITMAP_TIMES_ROMAN_24);
	glColor3f(0,0,0);
	output(370,750,0.0,"MORAL OF THE STORY");
	glColor3f(1,0,0);
	output(200,600,0.0,"The dog lost the bone because of his greediness and had to go back home hungry.");
	glColor3f(1,0,0);
	output(350,550,0.0,"The greedy dog had learned his lesson.");
	glColor3f(1,0,0);
	output(200,480,0.0,"From this we understood not become to greedy and be happy want we have in our life. ^_^ ");
	
	setFont(GLUT_BITMAP_TIMES_ROMAN_24);
	glColor3f(1,0,0);
	output(400,350,0.0,"THANK YOU >.<");
	
	setFont(GLUT_BITMAP_HELVETICA_18);
	output(390,150,0.0,"PRESS ENTER TO RESTART");
	output(420,100,0.0,"PRESS Q TO OUIT");
	
	glutSwapBuffers();
	glFlush();
}

void display5()
{
	printf("Started 5th Screen\n");
	
	glClear(GL_COLOR_BUFFER_BIT);
	
	glLineWidth(1);
	
	shake=0;
	ground();
	
	eroad();
	
	lake();
	
	sky();
	sun();
	
	timer(0);
	x=640;y=820;
	createCloud(k,x,y);
	
	home2();
	
	tree1(1);
	tree2();
	
	glPushMatrix();
	glTranslatef(200,0,0);
	tree2();
	glTranslatef(200,0,0);
	tree2();
	glTranslatef(30,-100,0);
	tree1(1);
	glTranslatef(-200,50,0);
	tree1(0);
	glPopMatrix();
	
	db=770;
	glPushMatrix();
	glTranslatef(db,0,0);
	glTranslatef(-220.0,100.0,0.0);
	glScalef(4.5,4.5,0.0);
	dog();
	glPopMatrix();	
	
	setFont(GLUT_BITMAP_TIMES_ROMAN_24);
	glColor3f(0,0,0);
	output(50,950,0.0,"As he opened his mouth to bark at him, his own bone fell down into the water.");
	glColor3f(0,0,0);
	output(50,900,0.0,"The greedy dog lost his own bone.");
	
	if(last == 1)
	{
		glColor3f(1,1,1);
		output(50,150,0.0,"PRESS M TO CONTINUE");
	}
	
	glPushMatrix();
	glTranslatef(500,245,0);
	glScalef(0.7,0.7,0.0);
	glTranslatef(0,bd,0);
	if(bd>=-300){
		bone();
	}
	glPopMatrix();
	if(bd<-300 && count <= 50){
		rings();
	}
	
	glFlush();
	
	glutSwapBuffers();
}

void display4()
{
	printf("Started 4th Screen\n");
	
	glClear(GL_COLOR_BUFFER_BIT);
	
	glLineWidth(1);
	
	ground();
	shake = 1;
	eroad();
	
	lake();
	sky();
	sun();
	
	timer(0);
	x=640;y=820;
	createCloud(k,x,y);
	
	home2();
	
	tree1(1);
	tree2();
	
	glPushMatrix();
	glTranslatef(200,0,0);
	tree2();
	glTranslatef(200,0,0);
	tree2();
	glTranslatef(30,-100,0);
	tree1(1);
	glTranslatef(-200,50,0);
	tree1(0);
	glPopMatrix();
	
	setFont(GLUT_BITMAP_TIMES_ROMAN_24);
	glColor3f(0,0,0);
	output(50,950,0.0,"On the way back to his home he stoped by the river.");
	glColor3f(0,0,0);
	output(50,900,0.0,"He saw his own reflection and thought that there is another dog with a bone in the water.");
	
	timerdog(0);
	glPushMatrix();
	glTranslatef(db,0,0);
	if(db>770)
	{
		db=770;
		delay++;
	}
	glTranslatef(-220.0,100.0,0.0);
	glScalef(4.5,4.5,0.0);
	dog();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(db,0,0);
	glTranslatef(-470.0,0.0,0.0);
	halfbone();
	glPopMatrix();
	
	if(delay >= 100)
	{
		glColor3f(0,0,0);
		output(50,850,0.0,"He wanted to snatch that bone from him. So he started barking at his own reflection.");
		imagine(delay);
	}	
	
	if(delay == 200){
		db=0;k=10;bd=0;
		glutDisplayFunc(display5);
	}
	
	glFlush();
	
	glutSwapBuffers();
}

void display3(void)
{
	printf("Started 3rd Screen\n");
	
	glClear(GL_COLOR_BUFFER_BIT);
	
	glLineWidth(1);
	
	shake = 1;
	sky();
	
	ground();
	bush();
	road();
	sun();
	house();
	
	timer(0);
	timerdog(0);
	
	x=640;y=820;
	createCloud(k,x,y);
	
	glPushMatrix();
	for(int i=0;i<=1000;i=i+30){
		glTranslatef(10+i,0,0);
		grass();
	}
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0,0,0);
	tree2();
	glTranslatef(100,50,0);
	tree1(1);
	glTranslatef(200,-70,0);
	tree2();
	glTranslatef(60,100,0);
	tree1(1);
	glTranslatef(-330,-150,0);
	tree1(0);
	glScalef(1.0,1.5,1.0);
	glTranslatef(830,-238,0);
	tree2();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(db,0,0);
	glTranslatef(-220.0,100.0,0.0);
	glScalef(4.5,4.5,0.0);
	dog();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(db,0,0);
	glTranslatef(-470.0,0.0,0.0);
	halfbone();
	glPopMatrix();
	
	setFont(GLUT_BITMAP_TIMES_ROMAN_24);
	glColor3f(0,0,0);
	output(50,900,0.0,"He picked the bone and was very happy.");
	
	if(db==800)
	{
		db=-100;k=50;
		glutDisplayFunc(display4);
	}
	
	glFlush();
	
	glutSwapBuffers();
}

void display2(void)
{
	printf("Started 2nd Screen\n");
	
	glClear(GL_COLOR_BUFFER_BIT);
	
	glLineWidth(1);
	
	sky();
	
	ground();
	bush();
	road();
	sun();
	house();
	
	timer(0);
	timerdog(0);
	
	x=640;y=820;
	createCloud(k,x,y);
	
	glPushMatrix();
	for(int i=0;i<=1000;i=i+30){
		glTranslatef(10+i,0,0);
		grass();
	}
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0,0,0);
	tree2();
	glTranslatef(100,50,0);
	tree1(1);
	glTranslatef(200,-70,0);
	tree2();
	glTranslatef(60,100,0);
	tree1(1);
	glTranslatef(-330,-150,0);
	tree1(0);
	glScalef(1.0,1.5,1.0);
	glTranslatef(830,-238,0);
	tree2();
	glPopMatrix();

	bone();
	
	setFont(GLUT_BITMAP_TIMES_ROMAN_24);
	glColor3f(0,0,0);
	output(50,900,0.0,"While roaming in the neighbourhood, he found a bone lying in the way. ");
	
	glPushMatrix();
	glTranslatef(d,0,0);
	if(d>470){
		d=470;
	}
	glTranslatef(-250.0,100.0,0.0);
	glScalef(4.5,4.5,0.0);
	dog();
	glPopMatrix();
	
	if(d == 470) fetch++;
	
	if(fetch == 50)
	{
		db=470;k-=150;
		glutDisplayFunc(display3);
	}
	
	glFlush();
	
	glutSwapBuffers();
}

void display1(void)
{
	printf("Started 1st Screen\n");
	
	glClear(GL_COLOR_BUFFER_BIT);
	
	glLineWidth(1);
	
	sky();
	
	ground();
	sun();
	
	bush();
	glPushMatrix();
	glTranslatef(400,10,0);
	bush();
	glPopMatrix();
	sroad();
	
	glPushMatrix();
	for(int i=0;i<=1000;i=i+30){
		glTranslatef(15+i,0,0);
		grass();
	}
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0,200,0);
	for(int i=0;i<=1000;i=i+20){
		if(i>=20 && i<=120) continue;
		else{
		glTranslatef(10+i,0,0);
		grass();
		}
	}
	glPopMatrix();
	
	timer(0);
	timerdog(0);
	
	x=640;y=820;
	createCloud(k,x,y);

	glPushMatrix();
	glTranslatef(0,0,0);
	tree2();
	glTranslatef(150,50,0);
	tree1(1);
	glTranslatef(200,-70,0);
	tree2();
	glTranslatef(60,100,0);
	tree1(1);
	glTranslatef(500,-70,0);
	tree2();
	glPopMatrix();
	
	home();
	
	setFont(GLUT_BITMAP_TIMES_ROMAN_24);
	glColor3f(0,0,0);
	output(50,950,0.0,"Once there was a dog. He was very hungry.");
	glColor3f(0,0,0);
	output(50,900,0.0,"He wandered here and there in search of food.");
	
	glPushMatrix();
	glTranslatef(d,0,0);
	glTranslatef(-220.0,100.0,0.0);
	glScalef(4.5,4.5,0.0);
	go++;
	dog();
	glPopMatrix();
	
	if(go == 600){
		d=0;k=0;
		glutDisplayFunc(display2);
	}
	
	glFlush();

	glutSwapBuffers();
}

void abtscr()
{
	printf("Started About Screen\n");
	
	glClear(GL_COLOR_BUFFER_BIT);

	background();
	
	setFont(GLUT_BITMAP_TIMES_ROMAN_24);
	glColor3f(0,0,0);
	output(400,750,0.0,"ABOUT THE STORY");
	glColor3f(1,0,0);
	output(220,550,0.0,"This is one of the most amzing short moral story.The story of a greedy dog.");
	glColor3f(1,0,0);
	output(220,500,0.0,"It conveys how a greedy dog had to face the consequences of his greediness.");
	glColor3f(1,0,0);
	output(400,400,0.0,"We hope you enjoy ^o^");
	
	glColor3f(0,0,0);
	setFont(GLUT_BITMAP_HELVETICA_18);
	output(410,150,0.0,"PRESS A TO CONTINUE");
	glutSwapBuffers();
	glFlush();
}

void myKey(unsigned char key, int x, int y)
{
	if(key == 'q' || key == 'Q')	exit(0);
	else if(key == 's' || key == 'S')	
	{
		printf("Started About Screen\n");
		glutDisplayFunc(abtscr);
	}
	else if(key == 'a' || key == 'A')	
	{
		printf("Started 1st Screen\n");
		d=0;k=0;
		glutDisplayFunc(display1);
	}
	else if(key == 'b' || key == 'B')	{
		printf("Started 2nd Screen\n");
		d=0;k=0;
		glutDisplayFunc(display2);
	}
	else if(key == 'c' || key == 'C')	{
		printf("Started 3rd Screen\n");
		db=470;k=0;
		glutDisplayFunc(display3);
	}
	else if(key == 'd' || key == 'D')	{
		printf("Started 4th Screen\n");
		db=0;k=0;
		glutDisplayFunc(display4);
	}
	else if(key == 'e' || key == 'E')	{
		printf("Started 5th Screen\n");
		db=0;k=0;bd=0;
		glutDisplayFunc(display5);
	}
	else if(key == 'm' || key == 'M')	{
		printf("Started Moral Screen\n");
		db=0;k=0;bd=0;
		glutDisplayFunc(moralscr);
	}
	else{
		glutDisplayFunc(frontscr);
	}
}

int main(int argc, char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(2000,2800);			
	glutInitWindowPosition(0,0);			
	glutCreateWindow("GREEDY DOG");
	glClearColor(0.243, 0.309, 0.439, 0.0);	
	glMatrixMode(GL_PROJECTION);				
	glLoadIdentity();					
	glOrtho(0.0,1000.0,0.0,1000.0,-500,+500);
	glutKeyboardFunc(myKey);				
	glutDisplayFunc(frontscr);
	glutMainLoop();
}
