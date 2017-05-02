#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159

const int ScreenWidth = 640;
const int ScreenHeight = 480;

void reshape(int x, int y);


void myInit(void)
{
    glPointSize(1.0);
    glMatrixMode(GL_PROJECTION | GL_MODELVIEW);
    glLoadIdentity();
    gluOrtho2D(0.0, (GLdouble)ScreenWidth, 0.0, (GLdouble)ScreenHeight);
}



void spheres()
{

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

}


void man1()
{
    glColor3f(0.9, 0.3, 0.2);

   glPushMatrix();
   glTranslatef(90.0,290.0,0.0);
   glBegin(GL_TRIANGLES);
   glVertex2f(-30.0f,0.0f);
   glVertex2f(0.0f,30.0f);
   glVertex2f(30.0f,0.0f);
   glEnd();
   glPopMatrix();

   glPushMatrix();
   glTranslatef(200.0,90.0,0.0);
   glBegin(GL_TRIANGLES);
   glVertex2f(-30.0f,0.0f);
   glVertex2f(0.0f,30.0f);
   glVertex2f(30.0f,0.0f);
   glEnd();
   glPopMatrix();

   glPushMatrix();
   glTranslatef(400.0,90.0,0.0);
   glBegin(GL_TRIANGLES);
   glVertex2f(-30.0f,0.0f);
   glVertex2f(0.0f,30.0f);
   glVertex2f(30.0f,0.0f);
   glEnd();
   glPopMatrix();

   glPushMatrix();
   glTranslatef(550.0,290.0,0.0);
   glBegin(GL_TRIANGLES);
   glVertex2f(-30.0f,0.0f);
   glVertex2f(0.0f,30.0f);
   glVertex2f(30.0f,0.0f);
   glEnd();
   glPopMatrix();

   glPushMatrix();
   glTranslatef(290.0,415.0,0.0);
   glBegin(GL_TRIANGLES);
   glVertex2f(-30.0f,0.0f);
   glVertex2f(0.0f,30.0f);
   glVertex2f(30.0f,0.0f);
   glEnd();
   glPopMatrix();

}

void fork()
{
  glLineWidth(4.0);
  glColor3f(0.0f,0.0f,0.0f);

  glPushMatrix();
  glBegin(GL_LINE_STRIP);
    glVertex2f(240,260);
    glVertex2f(195,240);
  glEnd();
  glPopMatrix();


  glPushMatrix();
  glBegin(GL_LINE_STRIP);
    glVertex2f(315,205);
    glVertex2f(315,155);
  glEnd();
  glPopMatrix();

  glBegin(GL_LINE_STRIP);
    glVertex2f(260,330);
    glVertex2f(210,350);
  glEnd();

  glBegin(GL_LINE_STRIP);
    glVertex2f(370,330);
    glVertex2f(420,350);
  glEnd();

  glBegin(GL_LINE_STRIP);

    glVertex2f(440,230);
    glVertex2f(390,250);
  glEnd();


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
  //  glColor3f(0.0f, 255.0f, 255.0f);
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
    glColor3f(255.0f, 255.0f, 0.0f);

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


void myDisplay(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    GLfloat mat_ambient[]={0.7f,0.7f,0.7f,1.0f};
    GLfloat mat_diffuse[]={0.5f,0.5f,0.5f,1.0f};
    GLfloat mat_specular[]={1.0f,1.0f,1.0f,1.0f};
    GLfloat mat_shininess[]={50.0f};
    GLfloat lightIntensity[]={0.7f,0.7f,0.7f,1.0f};
    GLfloat light_position[]={0.0f,0.0f,0.0f,1.0f};

    glMaterialfv(GL_FRONT,GL_AMBIENT,mat_ambient);
    glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse);
    glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular);
    glMaterialfv(GL_FRONT,GL_SHININESS,mat_shininess);

    glLightfv(GL_LIGHT0,GL_POSITION,light_position);
    glLightfv(GL_LIGHT0,GL_DIFFUSE,lightIntensity);



   // glPushMatrix();
    drawFilledCircle(550.0,330.0,10);
    //glPopMatrix();
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


    //setup();

    drawFilledElipse(225,240,120);

    //Five circles
    drawFilledCircle(200,300,25);
    drawFilledCircle(315,365,25);
    drawFilledCircle(245,190,25);
    drawFilledCircle(380,190,25);
    drawFilledCircle(435,300,25);


    //main plate
    drawFilledCircle(315,270,45);

    man1();
    spheres();
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
    glutInitWindowSize(ScreenWidth, ScreenHeight);
    glutInitWindowPosition(100, 150);
    glutCreateWindow("Dining Philosopher's");
    glutDisplayFunc(myDisplay);
    myInit();
    glutMainLoop();
    return 0;
}
