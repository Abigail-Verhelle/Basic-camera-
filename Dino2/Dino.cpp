// Abi Verhelle
#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <cmath>

void axis(double length)
{
    glPushMatrix();
    glBegin(GL_LINES);
    glVertex3d(0, 0, 0); glVertex3d(0, 0, length); //z-axis
    glEnd();
    glTranslated(0, 0, length - 0.2);
    glutWireCone(0.04, 0.2, 12, 9);
    glPopMatrix();
}

void displayWire(void)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-2.0 * 64 / 48.0, 2.0 * 64 / 48.0, -2.0, 2.0, 0.1, 100);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(2.0, 2.0, 2.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3d(0, 0, 0);
    
    glPushMatrix();
    glTranslated(0, 0, 0); //dodecahedron at (1, 0, 0)
    glScaled(0.30, 0.30, 0.30);
    glutWireDodecahedron();
    glPopMatrix();
    
    glRasterPos3d(0, 0.20, 0);
    glutBitmapCharacter( GLUT_BITMAP_HELVETICA_18 , '1' );
    
    glRasterPos3d(0.25, 0.15, 0);
    glutBitmapCharacter( GLUT_BITMAP_HELVETICA_18 , '2' );
    
    glRasterPos3d(-0.30, 0, 0);
    glutBitmapCharacter( GLUT_BITMAP_HELVETICA_18 , '3' );
    
    glFlush();
}

// main
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("basic cam");
    glutDisplayFunc(displayWire);
    glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
    glViewport(0, 0, 640, 480);
    glutMainLoop();
}

