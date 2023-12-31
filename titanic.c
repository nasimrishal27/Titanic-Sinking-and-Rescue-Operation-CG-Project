#include<stdio.h>
#include<GL/glut.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<string.h>
#define SPEED 10.0

float tm = 0.0f; // Variable to track the animation time

void rock();
void display1();
void display2();
void display3();
void display4();
void display5();
void display6();
void ship();
void water();
void water2();
void stars();
void drawCircle(float cx, float cy, float radius, int num_segments);
void head1();
void head2();
void head3();
void boat();
void renderSemiCircle(float centerX, float centerY, float radius);


// struct timespec jmp, jmp2;
GLint a=0,b=0,c=0,d=0,e=0,f=0,g=500,h=600,i=0,s=0,xm=900,ea=0;
GLfloat theta=0.0;
float da=1,db=1,x=0,wa=0;
void update(int value)
{
	tm += 0.1f; // Increment the animation time
    glutPostRedisplay(); // Call display function to update the screen
    glutTimerFunc(16, update, 0); // Set the next update call after 16 milliseconds (60 frames per second)
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	display1();
	if(s>1100){
		b+=1.5;
		display2();
	}
	if(b>900){
		c+=1;
		wa+=0.2;
		display3();
	}
	if (c>=1300){
        d+=1;
        display4();
    }
    if(d>=200){
        ea+=1;
        if(ea<850)
            e+=1;
        if(ea>=880 && ea<1200)
            e+=1;
        if(ea>=1230)
            e+=1;
        display5();
    }
    if (e>=3150){
        display6();
    }
    

	glFlush();
	glutSwapBuffers();
}


void display1()
{
    // ship2();
	glPushMatrix();
	glTranslated(s*1.5-600,75,0.0);
	ship();
	// boat();
	glPopMatrix();
	water();
}

void display2()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
    stars();
	rock();
	glPushMatrix();
    if(b<850)
	    glTranslated(b-600,75,0.0);
    else
        glTranslated(800-600,75,0.0);
	ship();
	glPopMatrix();
	water();
    
}

void display3()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	x+=0.2;
    stars();
	rock();
	glPushMatrix();
	glTranslated(c*0.2+100,200-x*1.2,0.0);
	glRotated(-45,0,0,1);
	ship();
	glPopMatrix();
	if(wa<=100)
	{
	glPushMatrix();
	glTranslated(0,-100+wa,0);
	water2();
	glPopMatrix();
	}
	else
		water2();
	water();
    


}
void display4()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
	water();
    stars();
    head1();
	head2();
	head3();
    
}

void display5()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
	glTranslated((e-1200)*0.5,75,0.0);
	boat();
	glPopMatrix();
	water();
    stars();
	head3();
    if(da==1)
	    head1();
	if(db==1)
		head2();

}

void display6()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    water();
    stars();
	glColor3f(1,1,1);
	char st[10000]={"             The Titanic tragedy refers to the sinking of the RMS Titanic, a luxurious British passenger liner,on April 15, 1912"};
	char rt[8000]={" during its maiden voyage from Southampton,England,to New York City.The ship,which was proclaimed unsinkable,struck "};
	char tt[8000]={" an iceberg in the North Atlantic Ocean, leading to one of the most infamous maritime disasters in history."};

    char ut[8000]={"             The Titanic was designed to be the largest and most opulent ship of its time, accommodating over 2,200 passengers"};
    char vt[8000]={" and crew members.However, during the late evening hours of April 14, the ship collided However, during the late evening "};
    char wt[8000]={" hours of April 14,the ship collided with an iceberg,causing significant damage to its hull.Despite efforts to save the ship,"};
    char xt[8000]={" it gradually filled with water and ultimately sank in the early hours of April 15."};

    char yt[8000]={"             The disaster resulted in the loss of more than 1,500 lives, primarily due to a shortage of lifeboats and the inadequate"};
    char zt[8000]={" evacuation procedures. The tragedy shocked the world and led to substantial improvements in maritime safety regulations, "};
    char at[8000]={" such as increasing the number  of lifeboats required on ships and implementing better wireless communication systems."};

    char bt[8000]={"            The sinking of the Titanic highlighted the vulnerability of even the most advanced technology and emphasized the "};
    char ct[8000]={" importance of safety measures at sea.It remains a poignant reminder of the human cost of overconfidence and a testament "};
    char dt[8000]={" to the bravery and sacrifice exhibited by many passengers and crew members during the tragic event."};

	glColor3f(1,1,1);
    glPushMatrix();
    glTranslated(110,0,0);
	glRasterPos3f(4,700,0);
	for(int i=0;i<strlen(st);i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,st[i]);
	glColor3f(1,1,1);
	glRasterPos3f(4,675,0);
	for(int i=0;i<strlen(rt);i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,rt[i]);
		glRasterPos3f(4,650,0);
	for(int i=0;i<strlen(tt);i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,tt[i]);
		glRasterPos3f(4,615,0);
	for(int i=0;i<strlen(ut);i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,ut[i]);
		glRasterPos3f(4,590,0);
	for(int i=0;i<strlen(vt);i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,vt[i]);
		glRasterPos3f(4,565,0);
	for(int i=0;i<strlen(wt);i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,wt[i]);
		glRasterPos3f(4,540,0);
	for(int i=0;i<strlen(xt);i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,xt[i]);
		glRasterPos3f(4,505,0);
	for(int i=0;i<strlen(yt);i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,yt[i]);
		glRasterPos3f(4,480,0);
	for(int i=0;i<strlen(zt);i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,zt[i]);
        glRasterPos3f(4,455,0);
	for(int i=0;i<strlen(at);i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,at[i]);
        glRasterPos3f(4,420,0);
	for(int i=0;i<strlen(bt);i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,bt[i]);
        glRasterPos3f(4,395,0);
	for(int i=0;i<strlen(ct);i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,ct[i]);
        glRasterPos3f(4,370,0);
	for(int i=0;i<strlen(dt);i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,dt[i]);
    glPopMatrix();
}

void renderText(float x, float y, const char* text) {
    glRasterPos2f(x, y);

    for (int i = 0; text[i] != '\0'; ++i) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
    }
}

void renderSemiCircle(float centerX, float centerY, float radius) {
   const int numSegments = 100;  // Number of line segments to approximate the semi-circle
   
   glBegin(GL_POLYGON);
   glColor3f(1.0, 0.0, 0.0);  // Set fill color to red (modify as desired)
   
   glVertex2f(centerX, centerY);  // Center point
   
   for (int i = 0; i <= numSegments; ++i) {
      float theta = 3.14159 * i / numSegments;  // Angle of each line segment
      float x = radius * cos(theta) + centerX;
      float y = radius * sin(theta) + centerY;
      glVertex2f(x, y);
   }
   glEnd();
}


void boat()
{

    glScaled(20,24,0);

    glColor3f(0.0f, 0.0f, 1.0f); // Blue color
	glBegin(GL_POLYGON);
		glVertex2f(3,3.0);
		glVertex2f(3,1);
		glVertex2f(22,1);
		glVertex2f(24.0,3.0);
	glEnd();

	glColor3f(0.3f, 0.3f, 0.5f); //motor
	glBegin(GL_POLYGON);
	glVertex2f(2,3);
	glVertex2f(2,5.5);
	glVertex2f(2.5,6);
	glVertex2f(4.5,6);
	glVertex2f(5,5.5);
	glVertex2f(5,3);
	glEnd();

	glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
		glVertex2f(2,3.5);
		glVertex2f(2,5);
		glVertex2f(5.0,5);
		glVertex2f(5,3.5);
	glEnd();

	glColor3f(1.0f, 1.0f, 1.0f);
    renderText(2.25, 4, "Motor");

	glColor3f(0.647, 0.165, 0.165); //operator
    glBegin(GL_POLYGON);
		glVertex2f(6,3);
		glVertex2f(6,6);
		glVertex2f(8.0,6);
		glVertex2f(8,3);
	glEnd();
	glColor3f(0.89, 0.73, 0.59); //hand
	glBegin(GL_POLYGON); 
		glVertex2f(5.5,5.6);
		glVertex2f(5.5,4.6);
		glVertex2f(5,4.2);
		glVertex2f(5,5.2);
	glEnd();
	glColor3f(0.647, 0.165, 0.165);
	glBegin(GL_POLYGON); //hand
		glVertex2f(6,6);
		glVertex2f(6,5);
		glVertex2f(5.5,4.5);
		glVertex2f(5.3,5.5);
	glEnd();

	glBegin(GL_POLYGON); //hand
		glVertex2f(7,6.7);
		glVertex2f(8,5.5);
		glVertex2f(9,5);
		glVertex2f(8.5,6);
	glEnd();

	glColor3f(0.89, 0.73, 0.59); //hand
	glBegin(GL_POLYGON); 
		glVertex2f(8.5,6);
		glVertex2f(8.2,7.5);
		glVertex2f(8.4,7.5);
		glVertex2f(9,5);
	glEnd();

	glColor3f(1,0,0); //speaker
	glBegin(GL_POLYGON); 
		glVertex2f(8.3,7.5);
		glVertex2f(10,9);
		glVertex2f(10,6);
	glEnd();

	glColor3f(1,1,1); 
	glBegin(GL_POLYGON); 
		glVertex2f(10,8);
		glVertex2f(10,7);
		glVertex2f(11,7.3);
		glVertex2f(11,7.7);
	glEnd();

	glColor3f(0.89, 0.73, 0.59); 
    glBegin(GL_POLYGON);
		glVertex2f(6.5,6);
		glVertex2f(6.5,8);
		glVertex2f(7.5,8);
		glVertex2f(7.5,6);
	glEnd();
	glColor3f(0.647, 0.165, 0.165);
	drawCircle(7.0f, 6.0f, 1.0f, 100);
	glColor3f(0.89, 0.73, 0.59);
	drawCircle(7.0f, 8.0f, 1.0f, 100);

	glColor3f(0,0,0);
    glBegin(GL_POLYGON);
		glVertex2f(5,8.5);
		glVertex2f(7,8.5);
		glVertex2f(7,8);
		glVertex2f(6.8,8.5);
		glVertex2f(6,6.5);
	glEnd();
	renderSemiCircle(7,8.5,1);
	
    glColor3f(1.0f, 0.0f, 0.0f); //red
    glBegin(GL_POLYGON);
		glVertex2f(3,1);
		glVertex2f(22,1);
		glVertex2f(24.0,3.0);
	glEnd();

    glColor3f(0.329412,0.329412,0.329412); //base
	glBegin(GL_POLYGON);
		glVertex2f(21.0,3.0);
		glVertex2f(21.0,4.0);
		glVertex2f(24.5,4.0);
		glVertex2f(24.0,3.0);
	glEnd();

	
	glColor3f(1,1,1); // pole
	glBegin(GL_POLYGON);
		glVertex2f(24.3,4.0);
		glVertex2f(24.3,5.0);
		glVertex2f(24.5,5.0);
		glVertex2f(24.5,4.0);
	glEnd();

    glColor3f(0.90, 0.90, 0.25); // Yellow color
    glBegin(GL_POLYGON);
    glVertex2f(24.5,5.0);
    glVertex2f(32,7.0);
    glVertex2f(32,1.0);
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f);
    renderText(17, 1.5, "Coast Guard");

    if (ea>=860)
    {
        da=0;
		
		glColor3f(1.0, 0.71, 0.75); //p1
		glBegin(GL_POLYGON);
			glVertex2f(12,3);
			glVertex2f(12,6);
			glVertex2f(14.0,6);
			glVertex2f(14,3);
		glEnd();
		glColor3f(0.89, 0.73, 0.59); 
    glBegin(GL_POLYGON);
		glVertex2f(12.5,6);
		glVertex2f(12.5,8);
		glVertex2f(13.5,8);
		glVertex2f(13.5,6);
	glEnd();
		glColor3f(1.0, 0.71, 0.75);
		drawCircle(13.0f, 6.0f, 1.0f, 100);
		glColor3f(0.89, 0.73, 0.59);
		drawCircle(13.0f, 8.0f, 1.0f, 100);

		
		glLineWidth(15.0);
		glBegin(GL_LINES);
    glVertex2f(13.0f, 6.0f);
    glVertex2f(13.0f, 4.0f);
    glEnd();
	glColor3f(0,0,0);
    glBegin(GL_POLYGON);
		glVertex2f(11,11);
		glVertex2f(14,8.5);
		glVertex2f(13,8);
		glVertex2f(12.8,8.5);
		glVertex2f(12,6.5);
	glEnd();

		glColor3f(0.53, 0.81, 0.92); //p2
		glBegin(GL_POLYGON);
			glVertex2f(15,3);
			glVertex2f(15,6);
			glVertex2f(17.0,6);
			glVertex2f(17,3);
		glEnd();
		glColor3f(0.89, 0.73, 0.59); 
    glBegin(GL_POLYGON);
		glVertex2f(15.5,6);
		glVertex2f(15.5,8);
		glVertex2f(16.5,8);
		glVertex2f(16.5,6);
	glEnd();
		glColor3f(0.53, 0.81, 0.92);
		drawCircle(16.0f, 6.0f, 1.0f, 100);
		glColor3f(0.89, 0.73, 0.59);
		drawCircle(16.0f, 8.0f, 1.0f, 100);
		
		glLineWidth(15.0);
		glBegin(GL_LINES);
    glVertex2f(16.0f, 6.0f);
    glVertex2f(16.0f, 4.0f);
    glEnd();
	glColor3f(0,0,0);
    glBegin(GL_POLYGON);
		glVertex2f(14,11);
		glVertex2f(17,8.5);
		glVertex2f(16,8);
		glVertex2f(15.8,8.5);
		glVertex2f(15,6.5);
	glEnd();
    }
	if(ea>=1210)
	{
		db=0;
		glColor3f(0.50, 0.50, 0.0); //p3
		glBegin(GL_POLYGON);
			glVertex2f(18,3);
			glVertex2f(18,6);
			glVertex2f(20.0,6);
			glVertex2f(20,3);
		glEnd();
		glColor3f(0.89, 0.73, 0.59); 
    glBegin(GL_POLYGON);
		glVertex2f(18.5,6);
		glVertex2f(18.5,8);
		glVertex2f(19.5,8);
		glVertex2f(19.5,6);
	glEnd();
		glColor3f(0.50, 0.50, 0.0);
		drawCircle(19.0f, 6.0f, 1.0f, 100);
		glColor3f(0.89, 0.73, 0.59);
		drawCircle(19.0f, 8.0f, 1.0f, 100);
		
		glLineWidth(15.0);
		glBegin(GL_LINES);
    glVertex2f(19.0f, 6.0f);
    glVertex2f(19.0f, 4.0f);
    glEnd();
	glColor3f(0,0,0);
    glBegin(GL_POLYGON);
		glVertex2f(17,11);
		glVertex2f(20,8.5);
		glVertex2f(19,8);
		glVertex2f(18.8,8.5);
		glVertex2f(18,6.5);
	glEnd();
	}
    
}
void head1()
{

    // Call the drawCircle function with desired parameters

	glColor3f(0.96, 0.76, 0.69); //neck
    glBegin(GL_POLYGON);
		glVertex2f(90,40);
		glVertex2f(90,70);
		glVertex2f(110,70);
		glVertex2f(110,40);
	glEnd();
	glLineWidth(8.0);
	glColor3f(0.0, 0.0, 0.0);
	drawCircle(100.0f, 70.0f, 20.0f, 100);
	glColor3f(0.94, 0.77, 0.62);
	glBegin(GL_LINES);
    glVertex2f(70.0f, 70.0f);
    glVertex2f(60.0f, 100.0f);
    glEnd();
	glBegin(GL_LINES);
    glVertex2f(130.0f, 70.0f);
    glVertex2f(140.0f, 100.0f);
    glEnd();

	glColor3f(0.96, 0.76, 0.69); //neck
    glBegin(GL_POLYGON);
		glVertex2f(190,5);
		glVertex2f(190,30);
		glVertex2f(210,30);
		glVertex2f(210,5);
	glEnd();
	glColor3f(0.0, 0.0, 0.0);
	drawCircle(200.0f, 30.0f, 20.0f, 100);
	glColor3f(0.94, 0.77, 0.62);
	glBegin(GL_LINES);
    glVertex2f(170.0f, 30.0f);
    glVertex2f(160.0f, 60.0f);
    glEnd();
	glBegin(GL_LINES);
    glVertex2f(230.0f, 30.0f);
    glVertex2f(240.0f, 60.0f);
    glEnd();

	glFlush(); // Flush the OpenGL pipeline

}
void head2()
{
	glPushMatrix();
	glTranslated(300,-20,0);
	head1();
	glPopMatrix();
	
	glFlush(); // Flush the OpenGL pipeline
}
void head3()
{
	glPushMatrix();
	glTranslated(500,-10,0);
	head1();
	glPopMatrix();

	glPushMatrix();
	glTranslated(700,0,0);
	head1();
	glPopMatrix();
	
	glFlush(); // Flush the OpenGL pipeline
}
void stars()
{
    
    glColor3f(1.0f, 1.0f, 1.0f); // Set color to white
	glPointSize(2.0f); // Set point size for stars
    glBegin(GL_POINTS);
	glVertex2f(100.0f, 400.0f); 
	glVertex2f(200.0f, 450.0f);
    glVertex2f(300.0f, 500.0f); 
	glVertex2f(400.0f, 650.0f);
    glVertex2f(500.0f, 700.0f); 
	glVertex2f(600.0f, 450.0f);
    glVertex2f(700.0f, 800.0f); 
	glVertex2f(750.0f, 850.0f);
    glVertex2f(650.0f, 600.0f); 
	glVertex2f(550.0f, 650.0f);
    glVertex2f(150.0f, 700.0f); 
	glVertex2f(250.0f, 950.0f);
    glVertex2f(350.0f, 500.0f); 
	glVertex2f(450.0f, 850.0f);

    glVertex2f(1000.0f, 400.0f); 
	glVertex2f(900.0f, 750.0f);
    glVertex2f(800.0f, 600.0f); 
	glVertex2f(850.0f, 650.0f);
    glVertex2f(570.0f, 700.0f); 
	glVertex2f(880.0f, 450.0f);
    glVertex2f(990.0f, 800.0f); 
	glVertex2f(790.0f, 850.0f);
    glVertex2f(950.0f, 600.0f); 
	glVertex2f(1000.0f, 650.0f);
    glVertex2f(960.0f, 700.0f); 
	glVertex2f(900.0f, 950.0f);
    glVertex2f(940.0f, 500.0f); 
	glVertex2f(890.0f, 850.0f);

	glEnd();
}

void water()
{
    
	glColor3f(0.196078,0.6,0.8);
	glBegin(GL_POLYGON);
		glVertex2f(0,0);
		glVertex2f(1000,0);
		glVertex2f(1000,100);
		glVertex2f(0,100);
	glEnd();
    

    // Draw water waves
    glLineWidth(2);
    glColor3f(0.529, 0.808, 0.922); // Light blue color
    glBegin(GL_LINE_STRIP);
    for (float x = 0; x <= 1000; x += 10) {
        float y = 10 * sin((x / 30)+tm); // Adjust the wave's amplitude and frequency
        glVertex2f(x, y + 30); // Shift the wave vertically by 50 units
    }
    glEnd();
    glBegin(GL_LINE_STRIP);
    for (float x = 0; x <= 1000; x += 10) {
        float y = 10 * sin((x / 30)+tm); // Adjust the wave's amplitude and frequency
        glVertex2f(x, y + 55); // Shift the wave vertically by 50 units
    }
    glEnd();
    glBegin(GL_LINE_STRIP);
    for (float x = 0; x <= 1000; x += 10) {
        float y = 10 * sin((x / 30)+tm); // Adjust the wave's amplitude and frequency
        glVertex2f(x, y + 75); // Shift the wave vertically by 50 units
    }
    glEnd();

}

void water2()
{
    glColor3f(0.196078,0.6,0.8);
	glBegin(GL_POLYGON);
		glVertex2f(0,100);
		glVertex2f(0,200);
		glVertex2f(500,100);
	glEnd();
    glBegin(GL_POLYGON);
		glVertex2f(500,100);
		glVertex2f(1000,100);
		glVertex2f(1000,200);
	glEnd();
}
void drawCircle(float cx, float cy, float radius, int num_segments) {
    // glColor3f(0.94, 0.77, 0.62);
	// glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy); // Center of the circle
    for (int i = 0; i <= num_segments; i++) {
        float theta = 2.0f * 3.1415926f * i / num_segments; // Angle in radians
        float x = radius * cosf(theta); // Calculate the x-coordinate
        float y = radius * sinf(theta); // Calculate the y-coordinate
        glVertex2f(cx + x, cy + y); // Define the vertex
    }
    glEnd();
}
void ship()
{

	glScaled(20,24,0);
	
	glColor3f(0.329412,0.329412,0.329412); //base
	glBegin(GL_POLYGON);
		glVertex2f(0.5,5.0);
		glVertex2f(3,1);
		glVertex2f(22,1);
		glVertex2f(24.0,5.0);
	glEnd();
	
	glColor3f(1.0,1.0,1.0); //ring
	glBegin(GL_POLYGON);
		glVertex2f(1.35,3.5);
		glVertex2f(1.6,3.2);
		glVertex2f(23.2,3.2);
		glVertex2f(23.35,3.5);
	glEnd();
	
	glColor3f(0.329412,0.329412,0.329412); //base
	glBegin(GL_POLYGON);
		glVertex2f(21.0,5.0);
		glVertex2f(21.0,6.0);
		glVertex2f(24.5,6.0);
		glVertex2f(24.0,5.0);
	glEnd();
	
	glColor3f(0.74902,0.847059,0.847059); //top-mid
	glBegin(GL_POLYGON);
		glVertex2f(2.0,5.0);
		glVertex2f(2.0,12.0);
		glVertex2f(15.0,12.0);
		glVertex2f(19.5,5.0);
	glEnd();
	
	glColor3f(0.137255,0.137255,0.556863); //ring
	glBegin(GL_POLYGON);
		glVertex2f(2.0,8.2);
		glVertex2f(2.0,8.8);
		glVertex2f(17.1,8.8);
		glVertex2f(17.5,8.2);
	glEnd();
	
	glColor3f(0.90,0.91,0.98); //window
	glBegin(GL_POLYGON);
		glVertex2f(3.0,6.0);
		glVertex2f(3.0,7.2);
		glVertex2f(4.0,7.2);
		glVertex2f(4.0,6.0);
	glEnd();
	
	glBegin(GL_POLYGON);
		glVertex2f(4.7,6.0);
		glVertex2f(4.7,7.2);
		glVertex2f(5.7,7.2);
		glVertex2f(5.7,6.0);
	glEnd();
	
	glBegin(GL_POLYGON);
		glVertex2f(8.1,6.0);
		glVertex2f(8.1,7.2);
		glVertex2f(9.1,7.2);
		glVertex2f(9.1,6.0);
	glEnd();
	
	glBegin(GL_POLYGON);
		glVertex2f(9.8,6.0);
		glVertex2f(9.8,7.2);
		glVertex2f(10.8,7.2);
		glVertex2f(10.8,6.0);
	glEnd();
	
	glBegin(GL_POLYGON);
		glVertex2f(6.4,6.0);
		glVertex2f(6.4,7.2);
		glVertex2f(7.4,7.2);
		glVertex2f(7.4,6.0);
	glEnd();
	
	glBegin(GL_POLYGON);
		glVertex2f(11.5,6.0);
		glVertex2f(11.5,7.2);
		glVertex2f(12.5,7.2);
		glVertex2f(12.5,6.0);
	glEnd();
	
	glBegin(GL_POLYGON);
		glVertex2f(13.3,6.0);
		glVertex2f(13.3,7.2);
		glVertex2f(14.3,7.2);
		glVertex2f(14.3,6.0);
	glEnd();
	
	glBegin(GL_POLYGON);
		glVertex2f(15.1,6.0);
		glVertex2f(15.1,7.2);
		glVertex2f(16.1,7.2);
		glVertex2f(16.1,6.0);
	glEnd();
	
	glBegin(GL_POLYGON);
		glVertex2f(16.9,6.0);
		glVertex2f(16.9,7.2);
		glVertex2f(17.9,7.2);
		glVertex2f(17.9,6.0);
	glEnd();

	
	glColor3f(0.90,0.91,0.98); //window
	glBegin(GL_POLYGON);
		glVertex2f(3.0,9.8);
		glVertex2f(3.0,11.0);
		glVertex2f(4.0,11.0);
		glVertex2f(4.0,9.8);
	glEnd();
	
	glBegin(GL_POLYGON);
		glVertex2f(4.7,9.8);
		glVertex2f(4.7,11.0);
		glVertex2f(5.7,11.0);
		glVertex2f(5.7,9.8);
	glEnd();
	
	glBegin(GL_POLYGON);
		glVertex2f(8.1,9.8);
		glVertex2f(8.1,11.0);
		glVertex2f(9.1,11.0);
		glVertex2f(9.1,9.8);
	glEnd();
	
	glBegin(GL_POLYGON);
		glVertex2f(9.8,9.8);
		glVertex2f(9.8,11.0);
		glVertex2f(10.8,11.0);
		glVertex2f(10.8,9.8);
	glEnd();
	
	glBegin(GL_POLYGON);
		glVertex2f(6.4,9.8);
		glVertex2f(6.4,11.0);
		glVertex2f(7.4,11.0);
		glVertex2f(7.4,9.8);
	glEnd();
	
	glBegin(GL_POLYGON);
		glVertex2f(11.5,9.8);
		glVertex2f(11.5,11.0);
		glVertex2f(12.5,11.0);
		glVertex2f(12.5,9.8);
	glEnd();
	
	glBegin(GL_POLYGON);
		glVertex2f(13.3,9.8);
		glVertex2f(13.3,11.0);
		glVertex2f(14.3,11.0);
		glVertex2f(14.3,9.8);
	glEnd();
	
	glColor3f(0.329412,0.329412,0.329412); //top-cover
	glBegin(GL_POLYGON);
		glVertex2f(1.5,12.0);
		glVertex2f(1.5,12.5);
		glVertex2f(16.0,12.5);
		glVertex2f(16.0,12.0);
	glEnd();
	
	glColor3f(0.0,0.0,0.0); //chim
	glBegin(GL_POLYGON);
		glVertex2f(2.5,12.5);
		glVertex2f(2.5,16.0);
		glVertex2f(5.0,16.0);
		glVertex2f(5.0,12.5);
	glEnd();
	
	glColor3f(1.0,0.25,0.0); //ring
	glBegin(GL_POLYGON);
		glVertex2f(2.5,12.5);
		glVertex2f(2.5,13.5);
		glVertex2f(5.0,13.5);
		glVertex2f(5.0,12.5);
	glEnd();
	
	glColor3f(1.0,0.25,0.0); //ring
	glBegin(GL_POLYGON);
		glVertex2f(2.5,14.5);
		glVertex2f(2.5,15.5);
		glVertex2f(5.0,15.5);
		glVertex2f(5.0,14.5);
	glEnd();
	
	glColor3f(0.0,0.0,0.0); //chim
	glBegin(GL_POLYGON);
		glVertex2f(6.0,12.5);
		glVertex2f(6.0,16.0);
		glVertex2f(8.5,16.0);
		glVertex2f(8.5,12.5);
	glEnd();
	
	glColor3f(1.0,0.25,0.0); //ring
	glBegin(GL_POLYGON);
		glVertex2f(6.0,14.5);
		glVertex2f(6.0,15.5);
		glVertex2f(8.5,15.5);
		glVertex2f(8.5,14.5);
	glEnd();
	
	glColor3f(1.0,0.25,0.0); //ring
	glBegin(GL_POLYGON);
		glVertex2f(6.0,12.5);
		glVertex2f(6.0,13.5);
		glVertex2f(8.5,13.5);
		glVertex2f(8.5,12.5);
	glEnd();
	
	if(b>850)
	{
	// Draw a vertical zigzag line
	glLineWidth(6.0);
    glColor3f(0.0, 0.0, 0.0); // Set color to red (you can change the color as desired)
    glBegin(GL_LINE_STRIP);
    float x = 12.0; // X-coordinate of the zigzag line
    float y = 0.0; // Starting Y-coordinate of the zigzag line
    float gap = 1.0; // Gap between each segment of the zigzag line

    // Draw zigzag line segments
    for (int i = 0; i < 14; i++) {
        if (i % 2 == 0) {
            glVertex2f(x, y);
            y += gap;
            glVertex2f(x + 0.5, y);
        }
        else {
            glVertex2f(x + 0.5, y);
            y += gap;
            glVertex2f(x, y);
        }
    }
    glEnd();
	}
    
}

void rock()
{
	glPushMatrix();
	glTranslated(450,50,0.0);
	glScaled(10,10,0);
	glColor3f(0.8, 0.9, 1.0);

	
	if(c>0)
	{
		glPushMatrix();
		glTranslated(0,-x,0);
		glPushMatrix();
		glTranslated(7,2,0.0);
		glRotated(-x,0,0,1);
		glTranslated(-7,-2,0.0);
		
		glBegin(GL_POLYGON);
		glVertex2f(8.1,1);
		glVertex2f(7.89,1.23);
		glVertex2f(11.26,18);
		glVertex2f(13.23,21.33);
		glVertex2f(14.23,2.53);
		glEnd();
		
		glPopMatrix();
		glPushMatrix();

		glTranslated(12,3,0.0);
		glRotated(x,0,0,1);
		glTranslated(-12,-3,0.0);
		
		glBegin(GL_POLYGON);
		glVertex2f(11.1,3.5);
		glVertex2f(13.2,18.7);
		glVertex2f(16.4,18.5);
		glVertex2f(18.12,3.65);
		glVertex2f(19.21,1.25);
		glEnd();
		
		glPopMatrix();
		glPopMatrix();
	}
	else
	{
		glBegin(GL_POLYGON);
		glVertex2f(8.1,1);
		glVertex2f(7.89,1.23);
		glVertex2f(11.26,18);
		glVertex2f(13.23,21.33);
		glVertex2f(14.23,2.53);
		glEnd();
		glBegin(GL_POLYGON);
		glVertex2f(11.1,3.5);
		glVertex2f(13.2,18.7);
		glVertex2f(16.4,18.5);
		glVertex2f(18.12,3.65);
		glVertex2f(19.21,1.25);
		glEnd();
	}


	glPopMatrix();

}

void idle()
{
glClearColor(1.0,1.0,1.0,1.0);

s+=SPEED/10;
if(s>3500)
	 s=0.0;

glutPostRedisplay();

}

void myinit()
{
	glClearColor(1.0f,1.0f,1.0f,1.0f);
	glColor3f(1.0,0.0,0.0);
	glPointSize(1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,999.0,0.0,799.0);
}

int main(int argc, char* argv[])

{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(1024.0,768.0);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Climax of Titanic");
	glutDisplayFunc(display);
    glutIdleFunc(idle);
	myinit();
	glutTimerFunc(0, update, 0); // Start the animation timer
	glutMainLoop();
	return 0;
}