////
////  DCallback.c
////  OpenGL
////
////  Created by SeoKangjung on 2015. 10. 12..
////  Copyright © 2015년 Roadmaps. All rights reserved.
////
//
//#include <stdio.h>
//#include "dot.h"
//
//GLint TopLeftX, TopLeftY, BottomRightX, BottomRightY;
//
//void MyDisplay(void) {
//    glViewport(0, 0, 500, 500);
//    glClear(GL_COLOR_BUFFER_BIT);
//    glColor3f(0.5, 0.5, 0.5);
//    glBegin(GL_POLYGON);
////    glVertex3f(-0.5, -0.5, 0.0);
////    glVertex3f(0.5, -0.5, 0.0);
////    glVertex3f(0.5, 0.5, 0.0);
////    glVertex3f(-0.5, 0.5, 0.0);
//    
//    glVertex3f(TopLeftX / 500.0f, (500 - TopLeftY) / 500.0f, 0.0f);
//    glVertex3f(TopLeftX / 500.0f, (500 - BottomRightY) / 500.0f, 0.0f);
//    glVertex3f(BottomRightX / 500.0f, (500 - BottomRightY) / 500.0f, 0.0f);
//    glVertex3f(BottomRightX / 500.0f, (500 - TopLeftY) / 500.0f, 0.0f);
//    
//    glEnd();
//    glFlush();
//}
//
//void MyMouseClick(GLint Button, GLint State, GLint X, GLint Y) {
//    if (Button == GLUT_LEFT_BUTTON && State == GLUT_DOWN) {
//        TopLeftX = X;
//        TopLeftY = Y;
//    }
//}
//
//void MyMouseMove(GLint X, GLint Y) {
//    BottomRightX = X;
//    BottomRightY = Y;
//    glutPostRedisplay();
//}
//
//void MyReshape(int NewWidth, int NewHeight) {
//    glViewport(0, 0, NewWidth, NewHeight);
//    GLfloat WidthFactor = (GLfloat)NewWidth / (GLfloat)300;
//    GLfloat HeightFactor = (GLfloat)NewHeight / (GLfloat)300;
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    glOrtho(-1.0 * WidthFactor, 1.0 * WidthFactor, -1.0 * HeightFactor, 1.0 * HeightFactor, -1.0, 1.0);
//}
//
//void MyKeyboard(unsigned char key, int x, int y) {
//    switch (key) {
//        case 'Q':
//        case 'q':
//        case 27:
//            exit(0);
//        break; }
//    glutPostRedisplay(); }
//void MySpecial(int key, int x, int y) {
//    switch (key) {
//        case GLUT_KEY_F1: case GLUT_KEY_LEFT:
//            break; default:
//        break; }
//}
//
//void MyInit() {
//    glClearColor(1.0, 1.0, 1.0, 1.0); glMatrixMode(GL_PROJECTION); glLoadIdentity();
//    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
//}
//
//int main(int argc, char** argv) {
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_RGB);
//    glutInitWindowSize(500, 500);
//    glutInitWindowPosition(0, 0);
//    glutCreateWindow("Keyboard Callback");
////    glutDisplayFunc(MyDisplay);
////    glutReshapeFunc(MyReshape);
//    MyInit();
////    glutDisplayFunc(MyDisplay);
////    glutKeyboardFunc(MyKeyboard);
////    glutSpecialFunc(MySpecial);
//    glutDisplayFunc(MyDisplay);
//    glutMouseFunc(MyMouseClick);
//    glutMotionFunc(MyMouseMove);
//    
//    
//    glutMainLoop();
//    
//    return 0;
//}
//
//#include <GLUT/GLUT.h>
//#include <OpenGL/OpenGL.h>

//GLboolean IsSphere = 1;
//
//void MyDisplay() { glClear(GL_COLOR_BUFFER_BIT); glColor3f(0.0, 0.5, 0.5);
//    if (IsSphere)
//        glutWireSphere(0.5, 30, 30);
//    else glutWireTorus(0.1, 0.3, 40, 20); glFlush();
//}
//void MyMainMenu(int entryID) {
//    if (entryID == 1) {
//        IsSphere = 1;
//
//    }
//    else if (entryID == 2) {
//        IsSphere = 0;
//    }
//    else if (entryID == 3) {
//        exit(0);
//    }
//        glutPostRedisplay();
//}
//void MyInit() {
//    glClearColor(1.0, 1.0, 1.0, 1.0); glMatrixMode(GL_PROJECTION); glLoadIdentity();
//    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
//    GLint MyMainMenuID = glutCreateMenu(MyMainMenu); glutAddMenuEntry("Draw Sphere", 1); glutAddMenuEntry("Draw Torus", 2); glutAddMenuEntry("Exit", 3); glutAttachMenu(GLUT_RIGHT_BUTTON);
//}
//int main(int argc, char** argv) { glutInit(&argc, argv); glutInitDisplayMode(GLUT_RGB); glutInitWindowSize(500, 500); glutInitWindowPosition(0, 0); glutCreateWindow("Menu Callback"); MyInit(); glutDisplayFunc(MyDisplay);
//    glutMainLoop();
//    return 0; }

#include <GLUT/GLUT.h>
#include <OpenGL/OpenGL.h>

GLfloat Delta = 0.0;
void MyDisplay( ) { glClear(GL_COLOR_BUFFER_BIT); glBegin(GL_POLYGON);
    glColor3f(0.0, 0.5, 0.8); glVertex3f(-1.0 + Delta, -0.5, 0.0); glVertex3f(0.0 + Delta, -0.5, 0.0); glVertex3f(0.0 + Delta, 0.5, 0.0); glVertex3f(-1.0 + Delta, 0.5, 0.0);
    glEnd( );
    glutSwapBuffers( );
}
void MyIdle( ) {
    Delta = Delta + 0.001;
    glutPostRedisplay( );
}
void MyInit() {
    glClearColor (1.0, 1.0, 1.0, 1.0); glMatrixMode(GL_PROJECTION); glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, 1.0, -1.0); }
int main(int argc, char** argv) {
    glutInit(&argc,argv); glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE); glutInitWindowSize(300, 300); glutInitWindowPosition(0, 0);
    glutCreateWindow("Idle Callback"); MyInit(); glutDisplayFunc(MyDisplay); glutIdleFunc(MyIdle);
    glutMainLoop( );
    return 0; }
