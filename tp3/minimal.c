#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <math.h>

#define PI 3.14159

static unsigned int WINDOW_WIDTH = 800;
static unsigned int WINDOW_HEIGHT = 800;
static const unsigned int BIT_PER_PIXEL = 32;
static const Uint32 FRAMERATE_MILLISECONDS = 1000 / 60;

void resizeViewport() {
    glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-4., 4., -4., 4.);
    SDL_SetVideoMode(WINDOW_WIDTH, WINDOW_HEIGHT, BIT_PER_PIXEL, SDL_OPENGL | SDL_RESIZABLE);
}

void drawSquare(){
	glBegin(GL_POLYGON);
	glVertex2f(-1/800.0,-1/800.0);
	glVertex2f(-1/800.0,1/800.0);
	glVertex2f(1/800.0,1/800.0);
	glVertex2f(1/800.0,-1/800.0);
	glEnd();
}

void drawCircle(){
	float x1=0.0,y1=1/800.0,x2,y2;
	
	glBegin(GL_POLYGON);
	glVertex2f(x1,y1);
	for (int i=0; i<30; i++){
		x2=x1*cos(2*PI/30)-y1*sin(2*PI/30);
		y2=x1*sin(2*PI/30)+y1*cos(2*PI/30);
		glVertex2f(x2,y2);
		x1=x2; y1=y2;
	}
	glEnd();
}

void drawRoundedSquare(){
	glPushMatrix();
		glScalef(0.5,1,0);
		drawSquare();
	glPopMatrix();
	glPushMatrix();
		glScalef(1,0.5,0);
		drawSquare();
	glPopMatrix();
	glPushMatrix();
		glScalef(.5,.5,0);
		glTranslatef(-1/800.0,-1/800.0,0);
		drawCircle();
		glTranslatef(2/800.0,0,0);
		drawCircle();
		glTranslatef(0,2/800.0,0);
		drawCircle();
		glTranslatef(-2/800.0,0,0);
		drawCircle();
	glPopMatrix();
}



GLuint createFirstArmIDList(){
	//Liste d'instruction objet1
	GLuint id1 = glGenLists(1);
	glNewList(id1, GL_COMPILE);

	glPushMatrix();
	glTranslatef(30/800.0,0,0);
		glPushMatrix();
			glTranslatef(-30/800.0,0,0);
			glScalef(20,20,0);
			drawCircle();
		glPopMatrix();
		glPushMatrix();
			glTranslatef(+30/800.0,0,0);
			glScalef(10,10,0);
			drawCircle();
		glPopMatrix();
		glBegin(GL_LINE_LOOP);
			glVertex3f(-30/800.0,20/800.0,0);
			glVertex3f(30/800.0,10/800.0,0);
			glVertex3f(30/800.0,-10/800.0,0);
			glVertex3f(-30/800.0,-20/800.0,0);
		glEnd();
	glTranslatef(-30/800.0,0,0);
	glPopMatrix();

	glEndList();

	return id1;
}

GLuint createSecondArmIDList(){
	//Liste d'instruction objet2
	GLuint id2 = glGenLists(1);
	glNewList(id2, GL_COMPILE);

		glPushMatrix();
		glTranslatef(20/800.0,0,0);
			glColor3f(255,255,255);
			glPushMatrix();
				glTranslatef(-20/800.0,0,0);
				glScalef(5,5,0);
				drawRoundedSquare();
			glPopMatrix();
			glPushMatrix();
				glTranslatef(+20/800.0,0,0);
				glScalef(5,5,0);
				drawRoundedSquare();
			glPopMatrix();
			glColor3f(0,255,100);
			glPushMatrix();
				glScalef(23,3,0);
				drawSquare();
			glPopMatrix();
			glColor3f(255,255,255);
		glTranslatef(20/800.0,0,0);
		glPopMatrix();

	glEndList();

	return id2;
}

GLuint createThirdArmIDList(){
	//Liste d'instruction objet 3
	GLuint id3 = glGenLists(1);
	glNewList(id3, GL_COMPILE);

		glColor3f(255,255,255);
		glPushMatrix();
			glScalef(3,3,0);
			drawRoundedSquare();
		glPopMatrix();
		glColor3f(0,0,255);
		glPushMatrix();
			glTranslatef(38/800.0,0,0);
			glScalef(4,4,0);
			drawCircle();
		glPopMatrix();
		glPushMatrix();
			glTranslatef(18/800.0,0,0);
			glScalef(20,2,0);
			drawSquare();
		glPopMatrix();

		glColor3f(255,255,255);

	glEndList();

	return id3;
}


float t;

int main(int argc, char** argv) {
    /* Initialisation de la SDL */
    if(-1 == SDL_Init(SDL_INIT_VIDEO)) {
        fprintf(stderr, "Impossible d'initialiser la SDL. Fin du programme.\n");
        return EXIT_FAILURE;
    }
    
    /* Ouverture d'une fenêtre et création d'un contexte OpenGL */
    if(NULL == SDL_SetVideoMode(WINDOW_WIDTH, WINDOW_HEIGHT, BIT_PER_PIXEL, SDL_OPENGL | SDL_GL_DOUBLEBUFFER| SDL_RESIZABLE)) {
        fprintf(stderr, "Impossible d'ouvrir la fenetre. Fin du programme.\n");
        return EXIT_FAILURE;
    }
    
    /* Titre de la fenêtre */
    SDL_WM_SetCaption("TD2 OpenGL", NULL);

    glClearColor(0.1, 0.1, 0.1, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);


    /* Boucle d'affichage */
    int loop = 1;
    GLuint id1 = createFirstArmIDList();
    GLuint id2 = createSecondArmIDList();
    GLuint id3 = createThirdArmIDList();


    while(loop) {

        /* Récupération du temps au début de la boucle */
        Uint32 startTime = SDL_GetTicks();
        
        /*on clear la fenetre*/
        glClear(GL_COLOR_BUFFER_BIT);

        /* Placer ici le code de dessin */

	glColor3f(255,255,255);
	glPushMatrix();	
		glScalef(4,4,0);
		glRotatef(45+0.1*t,0,0,1.0);
		glCallList(id1);
		glTranslatef(60/800.0,0,0);
		glRotatef(-10+0.5*t,0,0,1.0);
		glCallList(id2);
		glTranslatef(40/800.0,0,0);
		glRotatef(35+0.7*t,0,0,1.0);
		glCallList(id3);
		glRotatef(-30,0,0,1.0);
		glCallList(id3);
		glRotatef(60,0,0,1.0);
		glCallList(id3);
	glPopMatrix();
        

	

	t++;

        /* Echange du front et du back buffer : mise à jour de la fenêtre */
        SDL_GL_SwapBuffers();

        /* Boucle traitant les evenements */
        SDL_Event e;
        while(SDL_PollEvent(&e)) {

            /* L'utilisateur ferme la fenêtre : */
            if(e.type == SDL_QUIT) {
                loop = 0;
                break;
            }
            
            /* Quelques exemples de traitement d'evenements : */
            switch(e.type) {
            	case SDL_VIDEORESIZE:
                    WINDOW_WIDTH = e.resize.w;
                    WINDOW_HEIGHT = e.resize.h;
                    resizeViewport();
		break;

	    /* Clic souris */
		    case SDL_MOUSEBUTTONUP:
			/* Transformation des coordonnées du clic souris en coordonnées OpenGL */			
			break;

		        default:
		    break;
		    }
		}

        /* Echange du front et du back buffer : mise à jour de la fenêtre */
        SDL_GL_SwapBuffers();

        /* Calcul du temps écoulé */
        Uint32 elapsedTime = SDL_GetTicks() - startTime;

        if(elapsedTime < FRAMERATE_MILLISECONDS) {
            SDL_Delay(FRAMERATE_MILLISECONDS - elapsedTime);
        }
    }

    /* Liberation des ressources associées à la SDL */ 
    SDL_Quit();

    return EXIT_SUCCESS;
}


