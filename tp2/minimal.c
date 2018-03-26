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

int newPrimitivePressed;
GLenum newPrimitiveType;

typedef struct Point{
	float x,y;
	unsigned char r,v,b;
	struct Point *suiv;
} Point, *PointList;

Point* allocPoint(float x, float y){
	Point* tmp = (Point*) malloc(sizeof(Point));
	if (tmp==NULL){
        printf("l'allocation n'a pas foncionnée\n");
        return NULL;
    }
	tmp->x = x;
    tmp->y = y;
    tmp->suiv = NULL;
	return tmp;
}

typedef struct Primitive{
    GLenum primitiveType;
    PointList points;
    struct Primitive* suiv;
} Primitive, *PrimitiveList;


void drawPoints(PointList liste){
	printf("debut drawpoint\n");
	while (liste!=NULL){
		glVertex2f(liste->x,liste->y);
		liste=liste->suiv;
		printf("1 vertex effectué\n");
	}
}


Primitive* allocPrimitive(GLenum primitiveType) {
    /*
    On alloue un espace mémoire suffisant pour pouvoir stocker une primitive
    Attention : la fonction malloc() renvoie un void* qu'il faut impérativement caster en Primitive*.
    */
    Primitive* primitive = (Primitive*) malloc(sizeof(Primitive));
    if (!primitive) {
        return NULL;
    }
    primitive->primitiveType = primitiveType;
    primitive->points = NULL;
    primitive->suiv = NULL;
    return primitive;
}

void deletePoints(PointList* list) {
    assert(list);
    while (*list) {
        Point* suiv = (*list)->suiv;
        free(*list);
        *list = suiv;
    }
}

void addPrimitive(Primitive* primitive, PrimitiveList* list) {
    assert(primitive);
    assert(list);
    if (*list == NULL) {
        // Si le pointeur sur la liste est vide, on le modifie pour le faire pointer sur la primitive donnée en paramètre
        *list = primitive;
    } else {
        primitive->suiv=*list;
	*list=primitive;
    }
}

void drawPrimitives(PrimitiveList list) {
    while(list) {
        glBegin(list->primitiveType);
        drawPoints(list->points);
        glEnd();
        list = list->suiv;
    }
}

void deleteLastPrimitive(PrimitiveList* list) {
    assert(list);
    Primitive* suiv = (*list)->suiv;
    deletePoints(&(*list)->points);
    free(*list);
    *list = suiv;
}

void addPointToList(Point *point, PointList * liste){
    assert(point);
    assert(liste);
	if (*liste==NULL){ 
		*liste=point;
	}
	else{
		//PointList tmp=*liste;
		addPointToList(point, &((*liste)->suiv));
	}
}

void resizeViewport() {
    glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1., 1., -1., 1.);
    SDL_SetVideoMode(WINDOW_WIDTH, WINDOW_HEIGHT, BIT_PER_PIXEL, SDL_OPENGL | SDL_RESIZABLE);
}


void ComptePrim(Primitive* liste){
	int c=0;
	while(liste!=NULL){
		c++;
		liste=liste->suiv;
	}
	printf("%d primitives affichées\n",c);
}

void drawLandmark(){
	glColor3f(255,0,0);
	glBegin(GL_LINES);
        glVertex2f(0, 0),
        glVertex2f(0.1,0);
        glEnd();
	glColor3f(0,255,0);	
	glBegin(GL_LINES);
        glVertex2f(0,0);
	glVertex2f(0,0.1);
        glEnd();
}

void drawSquare(float r){
	glBegin(GL_LINE_LOOP);
	glVertex2f(-r/800,-r/800);
	glVertex2f(-r/800,r/800);
	glVertex2f(r/800,r/800);
	glVertex2f(r/800,-r/800);
	glEnd();
}

void drawCircle(float r){
	float x1=0,y1=r/800,x2,y2;
	
	glBegin(GL_LINE_LOOP);
	glVertex2f(x1,y1);
	for (int i=0; i<30; i++){
		x2=x1*cos(2*PI/20)-y1*sin(2*PI/20);
		y2=x1*sin(2*PI/20)+y1*cos(2*PI/20);
		glVertex2f(x2,y2);
		x1=x2; y1=y2;
	}
	glEnd();
}

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

    /* On créé une première primitive par défaut */
    PrimitiveList primitives = NULL;
    PrimitiveList lastPrim; 

    /* Boucle d'affichage */
    int loop = 1;
    float x,y;


    while(loop) {

        /* Récupération du temps au début de la boucle */
        Uint32 startTime = SDL_GetTicks();
        
        /*on clear la fenetre*/
        glClear(GL_COLOR_BUFFER_BIT);

        /* Placer ici le code de dessin */
	drawLandmark();
	glColor3f(255,255,255);
	drawPrimitives(primitives);

	drawSquare(10);
	drawCircle(150);

        

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

			if (e.button.button == SDL_BUTTON_RIGHT){
				newPrimitivePressed=0;
				lastPrim->primitiveType=GL_LINE_LOOP;
				
			}
			else{
				if (newPrimitivePressed==0){
					newPrimitivePressed=1;
					newPrimitiveType=GL_LINE_STRIP;
					lastPrim = allocPrimitive(newPrimitiveType);
					addPrimitive(lastPrim, &primitives);
				}
			}


		        x = -1 + 2. * e.button.x / WINDOW_WIDTH;
		        y = -(-1 + 2. * e.button.y / WINDOW_HEIGHT);
			addPointToList(allocPoint(x,y), &(primitives->points));
			

			ComptePrim(primitives);


			/*if (newPrimitivePressed==0 && currentPrimitiveType != newPrimitiveType) {
			        deleteLastPrimitive(&primitives);

				prim = allocPrimitive(newPrimitiveType);
			        lastPrim = prim;
			        addPrimitive(lastPrim, &primitives);
			        currentPrimitiveType = newPrimitiveType;
			}*/
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
