#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159

const int ScreenWidth = 640;
const int ScreenHeight = 480;

const int n;

void reshape(int x, int y);


void myInit(void)
{
    glPointSize(1.0);
    glMatrixMode(GL_PROJECTION | GL_MODELVIEW);
    glLoadIdentity();
    gluOrtho2D(0.0, (GLdouble)ScreenWidth, 0.0, (GLdouble)ScreenHeight);
}


void printtext(int x, int y, char*String)
{
//(x,y) is from the bottom left of the window
    int i;
    glDisable(GL_TEXTURE_2D);
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    glOrtho(0, 640, 0,480, -1.0f, 1.0f);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    glPushAttrib(GL_DEPTH_TEST);
    glDisable(GL_DEPTH_TEST);
    glRasterPos2i(x,y);
    for (i=0; i<strlen(String); i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, String[i]);
    }
    glPopAttrib();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glEnable(GL_TEXTURE_2D);
    glPopMatrix();

}

void display2(void)
{
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glEnable(GL_DEPTH_TEST|GL_TEXTURE_2D);

    char string[64];
    glColor3f(0.0,1.0,0.0);
    sprintf(string, "Newton");
    printtext(320,420,string);

    sprintf(string, "Aristotle");
    printtext(510,260,string);
    sprintf(string,"Plato");
    printtext(170,60,string);
    //glColor3f(1.0,0.0,0.0);
    sprintf(string, "Schrodinger");
    printtext(20,260,string);
    sprintf(string, "Epicurus");
    printtext(360,60,string);
    glutSwapBuffers();
}


void draw_triangle()
{
    glColor3f(0.9, 0.3, 0.2);

    glBegin(GL_TRIANGLES);
    glVertex2f(-30.0f,0.0f);
    glVertex2f(0.0f,30.0f);
    glVertex2f(30.0f,0.0f);
    glEnd();

}

/* The five philosophers written as seperate functions
This is such a bad idea right now but i dunno how else can i make it work!! */
void philosopher1()
{
    glTranslatef(90.0,290.0,0.0);
    draw_triangle();
}

void philosopher2()
{
   glTranslatef(200.0,90.0,0.0);
   draw_triangle();
}

void philosopher3()
{
   glTranslatef(400.0,90.0,0.0);
   draw_triangle();
}

void philosopher4()
{
  glTranslatef(550.0,290.0,0.0);
  draw_triangle();
}

void philosopher5()
{
   glTranslatef(290.0,415.0,0.0);
   draw_triangle();
}

void man1()
{

   //glColor3f(0.9, 0.3, 0.2);

   glPushMatrix();
   philosopher1();
   glPopMatrix();

   glPushMatrix();
   philosopher2();
   glPopMatrix();

   glPushMatrix();
   philosopher3();
   glPopMatrix();

   glPushMatrix();
   philosopher4();
   glPopMatrix();

   glPushMatrix();
   philosopher5();
   glPopMatrix();

}


void fork1()
{
   glBegin(GL_LINE_STRIP);
     glVertex2f(240,260);
     glVertex2f(195,240);
   glEnd();
}

void fork2()
{
  glBegin(GL_LINE_STRIP);
    glVertex2f(315,205);
    glVertex2f(315,155);
  glEnd();
}


void fork5()
{
    glBegin(GL_LINE_STRIP);
        glVertex2f(260,330);
        glVertex2f(210,350);
    glEnd();
}

void fork4()
{

  glBegin(GL_LINE_STRIP);
    glVertex2f(370,330);
    glVertex2f(420,350);
  glEnd();
}

void fork3()
{
    glBegin(GL_LINE_STRIP);
        glVertex2f(440,230);
        glVertex2f(390,250);
    glEnd();
}

void fork()
{
  glLineWidth(5.0);
  glColor3f(0.0f,0.0f,0.0f);

  glPushMatrix();
  //glTranslatef(-105.0,-40.0,0.0f);
  fork1();
  glPopMatrix();


  glPushMatrix();
 // glTranslatef(0.0,-95.0,0.0);
  fork2();
  glPopMatrix();

  glPushMatrix();
 // glTranslatef(75.0,-60.0,0.0);
    fork3();
  glPopMatrix();

  glPushMatrix();
 // glTranslatef(55.0,40,0.0);
    fork4();
  glPopMatrix();

  glPushMatrix();
 // glTranslatef(-50.0,50.0,0.0);
  fork5();
  glPopMatrix();



  glutSwapBuffers();

}


void case1()
{
     glLineWidth(5.0);
     glColor3f(0.0f,0.0f,0.0f);

     glPushMatrix();
     glTranslatef(-105.0,-40.0,0.0f);
        fork1();
     glPopMatrix();

     glPushMatrix();
        glTranslatef(0.0,-95.0,0.0);
        fork2();
     glPopMatrix();

    fork3();
    fork4();
    fork5();
}


void case2()
{
  glLineWidth(5.0);
  glColor3f(0.0f,0.0f,0.0f);

  fork1();

  glPushMatrix();
  glTranslatef(0.0,-95.0,0.0);
  fork2();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(75.0,-60.0,0.0);
    fork3();
  glPopMatrix();

  fork4();
  fork5();

  glutSwapBuffers();

}

void case3()
{
  glLineWidth(5.0);
  glColor3f(0.0f,0.0f,0.0f);

  fork1();
  fork2();


  glPushMatrix();
  glTranslatef(75.0,-60.0,0.0);
    fork3();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(55.0,40,0.0);
    fork4();
  glPopMatrix();

  fork5();
  glutSwapBuffers();
}

void case4()
{
  glLineWidth(5.0);
  glColor3f(0.0f,0.0f,0.0f);


  fork1();
  fork2();
  fork3();

  glPushMatrix();
    glTranslatef(55.0,40,0.0);
    fork4();
  glPopMatrix();

  glPushMatrix();
    glTranslatef(-50.0,50.0,0.0);
    fork5();
  glPopMatrix();
  glutSwapBuffers();
}

void case5()
{
  glLineWidth(5.0);
  glColor3f(0.0f,0.0f,0.0f);

  glPushMatrix();
    glTranslatef(-105.0,-40.0,0.0f);
    fork1();
  glPopMatrix();

    fork2();
    fork3();
    fork4();

  glPushMatrix();
    glTranslatef(-50.0,50.0,0.0);
    fork5();
  glPopMatrix();

glutSwapBuffers();

}



//making the background White
void setup() {
       glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}



void drawFilledElipse(GLfloat x, GLfloat y, GLfloat radius)
{
    int i;
    int triangleAmount = 20; //# of triangles used to draw circle
    glColor3f(0.5f, 0.05f, 0.0f);
    GLfloat twicePi = 2.0f * PI;

    GLint x1 =320, y1 = 240, r1 = 75;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for (i = 0; i <= triangleAmount; i++) {
        glVertex2f(
            1.4   * ( x + (radius * cos(i *  twicePi / triangleAmount))),
            1.111 * (y + (radius * sin(i * twicePi / triangleAmount)))
        );
    }
    glEnd();
  // glutSwapBuffers();
}


void drawFilledCircle(GLfloat x, GLfloat y, GLfloat radius)
{
    int i;
    int triangleAmount = 20; //# of triangles used to draw circle

    GLfloat twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y); // center of circle
    for(i = 0; i <= triangleAmount;i++)
    {
        glVertex2f(
            (x + (radius * cos(i * twicePi / triangleAmount))),
            (y + (radius * sin(i * twicePi / triangleAmount)))
        );
    }
    glEnd();
    //glutSwapBuffers();
}


void displayCB(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   // glLoadIdentity();

    glPushMatrix();
    glColor3d(0.9,0.3,0.2);
    glPushMatrix();
    drawFilledCircle(550.0,330.0,10);
    glPopMatrix();
    glPushMatrix();
    drawFilledCircle(90.0,330.0,10);
    glPopMatrix();
    glPushMatrix();
    drawFilledCircle(400.0,130.0,10);
    glPopMatrix();
    glPushMatrix();
    drawFilledCircle(200.0,130.0,10);
    glPopMatrix();
    glPushMatrix();
    drawFilledCircle(290.0,455.0,10);
    glPopMatrix();
    glPopMatrix();

    //setup();

    drawFilledElipse(225,240,120);

    //Five circles
    glPushMatrix();
    glColor3f(255.0f,255.0f,0.0f);
    drawFilledCircle(200,300,25);
    drawFilledCircle(315,365,25);
    drawFilledCircle(245,190,25);
    drawFilledCircle(380,190,25);
    drawFilledCircle(435,300,25);
    glPopMatrix();


    //main plate
    glPushMatrix();
    glColor3f(1.0,1.0,0.0);
    drawFilledCircle(315,270,45);
    glPopMatrix();

    man1();
    //fork();

    display2();
    switch(n){

   case 0: fork();
   case 1: case1();
   case 2: case2();
   case 3: case3();
   case 4: case4();
   case 5: case5();

   glutSwapBuffers();

    }


    glEnd();
    glFlush();

}



void myDisplay(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    setup();

    glPushMatrix();
    glColor3d(0.9,0.3,0.2);
    glPushMatrix();
    drawFilledCircle(550.0,330.0,10);
    glPopMatrix();
    glPushMatrix();
    drawFilledCircle(90.0,330.0,10);
    glPopMatrix();
    glPushMatrix();
    drawFilledCircle(400.0,130.0,10);
    glPopMatrix();
    glPushMatrix();
    drawFilledCircle(200.0,130.0,10);
    glPopMatrix();
    glPushMatrix();
    drawFilledCircle(290.0,455.0,10);
    glPopMatrix();
    glPopMatrix();


    drawFilledElipse(225,240,120);

    //Five circles
    glPushMatrix();
    glColor3f(255.0f,255.0f,0.0f);
    drawFilledCircle(200,300,25);
    drawFilledCircle(315,365,25);
    drawFilledCircle(245,190,25);
    drawFilledCircle(380,190,25);
    drawFilledCircle(435,300,25);
    glPopMatrix();


    //main plate
    glPushMatrix();
    glColor3f(1.0,1.0,0.0);
    drawFilledCircle(315,270,45);
    glPopMatrix();

    display2();
    man1();
    fork();

    glRectf(80.0f,2.75f, 0.00f, -0.75f);
    glEnd();
    glFlush();
}



int main(int argc, char ** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glEnable(GL_DEPTH_TEST);

    printf("Enter the philosopher number: ");
    scanf("%d",&n);

    glutInitWindowSize(ScreenWidth, ScreenHeight);
    glutInitWindowPosition(100, 150);
    glutCreateWindow("Dining Philosopher's");

  //  glutDisplayFunc(myDisplay);
    glutDisplayFunc(displayCB);
    myInit();
    glutMainLoop();
    return 0;
}
