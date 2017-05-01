#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159

const int ScreenWidth = 640;
const int ScreenHeight = 480;

//void reshape(int x, int y);


void myInit(void)
{
    glPointSize(1.0);
    glMatrixMode(GL_PROJECTION | GL_MODELVIEW);
    glLoadIdentity();
    gluOrtho2D(0.0, (GLdouble)ScreenWidth, 0.0, (GLdouble)ScreenHeight);
}


void man()
{

    glColor3f(0.9, 0.3, 0.2);

    glPushMatrix();
    glTranslatef(90.0,290.0,0.0);
   /*
   glScalef(1.0,1.0,1.0);
   glutSolidSphere(0.05,20,20);
   glutReshapeFunc(reshape);
   */
    glRectf(50.0f,50.00f, 0.00f, -0.75f);
    glPopMatrix();


   glPushMatrix();
   glTranslatef(160.0,90.0,0.0);
   glRectf(50.0f,50.00f, 0.00f, -0.75f);
   glPopMatrix();

   glPushMatrix();
   glTranslatef(400.0,90.0,0.0);
   glRectf(50.0f,50.00f, 0.00f, -0.75f);
   glPopMatrix();

   glPushMatrix();
   glTranslatef(490.0,290.0,0.0);
   glRectf(50.0f,50.00f, 0.00f, -0.75f);
   glPopMatrix();

   glPushMatrix();
   glTranslatef(290.0,415.0,0.0);
   glRectf(50.0f,50.00f, 0.00f, -0.75f);
   glPopMatrix();


 //glutSwapBuffers();
}

void fork()
{
  glLineWidth(4.0);
  glColor3f(0.0f,0.0f,0.0f);

  glBegin(GL_LINE_STRIP);
    //glVertex2f(195,235);
    glVertex2f(240,260);
    glVertex2f(195,240);
  glEnd();

  glBegin(GL_LINE_STRIP);
    glVertex2f(315,205);
    glVertex2f(315,155);
  glEnd();

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

/*

void reshape(int x, int y)
{
    if (y == 0 || x == 0) return;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(39.0,(GLdouble)x/(GLdouble)y,0.6,21.0);
    glMatrixMode(GL_MODELVIEW);
    glViewport(0,0,x,y);  //Use the whole window for rendering
}

*/



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

    //setup();
    //ellipse();

    drawFilledElipse(225,240,120);

    //Five circles
    drawFilledCircle(200,300,25);
    drawFilledCircle(315,365,25);
    drawFilledCircle(245,190,25);
    drawFilledCircle(380,190,25);
    drawFilledCircle(435,300,25);


    //main plate
    drawFilledCircle(315,270,45);

    man();
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
