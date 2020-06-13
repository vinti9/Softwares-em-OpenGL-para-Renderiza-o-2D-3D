#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include "image.h"
#define TEXTURA_DO_PLANO "flamengo.rgb"

static int shoulder = 0, elbow = 0, elbow2 = 0;
GLuint  textura_plano;

/*GLfloat planotext[4][2]={
  {-1,-1},
  {+1,-1},
  {+1,+1},
  {-1,+1}
};*/

GLfloat planotext[4][2]={
  {0,0},
  {+1,0},
  {+1,+1},
  {0,+1}
};

void display(void){

  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
  glClearColor (0.0, 0.0, 0.0, 0.0);
  glPushMatrix();

  glRotatef ((GLfloat) shoulder, 0.0, 1.0, 0.0);

  glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_DECAL);
  glBindTexture(GL_TEXTURE_2D,textura_plano);
   
  /* Chao - textura*/

  glEnable(GL_TEXTURE_2D);  
  glBegin(GL_QUADS);
  glTexCoord2fv(planotext[0]);  glVertex3f(-5,-3.4,-5);
  glTexCoord2fv(planotext[1]);  glVertex3f(5,-3.4,-5);
  glTexCoord2fv(planotext[2]);  glVertex3f(5,3.4,-5);
  glTexCoord2fv(planotext[3]);  glVertex3f(-5,3.4,-5);
  glEnd();
  glDisable(GL_TEXTURE_2D);


  glColor3f(1.0,1.0,0.0);
  glPointSize(8.0);
   /* linha*/
  glBegin(GL_LINES);
  glVertex3f(-3.0, 1.5,-4.5);  glVertex3f(4.0,1.0,-4.5);    // coordenadas inicial e final da linha
  glEnd();
  
  glBegin(GL_POINTS);
  glVertex3f(-3.0, 1.5,-4.5);  glVertex3f(4.0,1.0,-4.5);    // coordenadas inicial e final da linha
  glEnd();
  
  /* Chao*/
  glColor3f(0.0,0.0,1.0);
  glPushMatrix();
  glTranslatef (0.0, -3.6, 0.0);
  glScalef (10.0, 0.2, 10.0);
  glutSolidCube (1.0);
  glPopMatrix();
  
  /* armario 
  glColor3f(1.0,0.0,1.0);
  glPushMatrix();
  glScalef (4.0, 6.0, 2.0);
  glutSolidCube (1.0);
  glPopMatrix();



  glColor3f(1.0,1.0,0.0);
  glPushMatrix();
  glTranslatef (-2.0, 0.0, 1.1);
  glRotatef ((GLfloat) elbow, 0.0, 1.0, 0.0);
  glTranslatef (2.0, 0.0, -1.1);
  glTranslatef (-1.0, 0.0, 1.0);
  glScalef (2.0, 6.0, 0.2);
  glutSolidCube (1.0);
  glColor3f(1.0,0.0,0.0);
  glPushMatrix();    
  glTranslatef (0.4, 0.0, 1.1);
  glScalef (0.2, 0.2, 0.2);
  glutSolidCube (1.0);
  glPopMatrix();
  glPopMatrix();



  glColor3f(1.0,1.0,0.0);
  glPushMatrix();
  glTranslatef (2.0, 0.0, 1.1);
  glRotatef ((GLfloat) elbow2, 0.0, 1.0, 0.0);
  glTranslatef (-2.0, 0.0, -1.1);
  glTranslatef (1.0, 0.0, 1.0);
  glScalef (2.0, 6.0, 0.2);
  glutSolidCube (1.0);
  glColor3f(1.0,0.0,0.0);
  glPushMatrix();    
  glTranslatef (-0.4, 0.0, 1.1);
  glScalef (0.2, 0.2, 0.2);
  glutSolidCube (1.0);
  glPopMatrix();
  glPopMatrix();*/

  /* origem volta para o sistema de coordenadas original */
  glPopMatrix();
  glutSwapBuffers();
}

void reshape (int w, int h){
  glViewport (0, 0, (GLsizei) w, (GLsizei) h);
  glMatrixMode (GL_PROJECTION);
  glLoadIdentity ();
  gluPerspective(65.0, (GLfloat) w/(GLfloat) h, 1.0, 30.0);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glTranslatef (0.0, 0.0, -15.0);
}

void keyboard (unsigned char key, int x, int y){
  switch (key) {
  case 's':
    shoulder = (shoulder + 5) % 360;
    glutPostRedisplay();
    break;
  case 'S':
    shoulder = (shoulder - 5) % 360;
    glutPostRedisplay();
    break;
  case 'e':
    elbow = (elbow + 5) % 360;
    glutPostRedisplay();
    break;
  case 'E':
    elbow = (elbow - 5) % 360;
    glutPostRedisplay();
    break;
  case 'p':
    elbow2 = (elbow2 + 5) % 360;
    glutPostRedisplay();
    break;
  case 'P':
    elbow2 = (elbow2 - 5) % 360;
    glutPostRedisplay();
    break;
  case 27:
    exit(0);
    break;
  default:
    break;
  }
}

void carregar_texturas(void){
  IMAGE *img;
  GLenum gluerr;

  /* textura do plano */
  glGenTextures(1, &textura_plano);
  glBindTexture(GL_TEXTURE_2D, textura_plano);
  
  if(!(img=ImageLoad(TEXTURA_DO_PLANO))) {
    fprintf(stderr,"Error reading a texture.\n");
    exit(-1);
  }

  gluerr=gluBuild2DMipmaps(GL_TEXTURE_2D, 3, 
			   img->sizeX, img->sizeY, 
			   GL_RGB, GL_UNSIGNED_BYTE, 
			   (GLvoid *)(img->data));
  if(gluerr){
    fprintf(stderr,"GLULib%s\n",gluErrorString(gluerr));
    exit(-1);
  }

  glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
  glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
  glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_LINEAR);
  glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
  glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_DECAL);

}

void init(void){

  glClearColor (0.0, 0.0, 0.0, 0.0);
  carregar_texturas();
  glShadeModel(GL_FLAT);
  glEnable(GL_DEPTH_TEST);
}

int main(int argc, char** argv){
  glutInit(&argc, argv);
  glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize (500, 500);
  glutInitWindowPosition (100, 100);
  glutCreateWindow (argv[0]);
  init ();
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutKeyboardFunc(keyboard);
  glutMainLoop();
  return 0;
}
 
