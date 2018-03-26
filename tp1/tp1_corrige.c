#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

/* Dimensions de la fenêtre */
static unsigned int WINDOW_WIDTH = 400;
static unsigned int WINDOW_HEIGHT = 400;

/* Nombre de bits par pixel de la fenêtre */
static const unsigned int BIT_PER_PIXEL = 32;

/* Nombre minimal de millisecondes separant le rendu de deux images */
static const Uint32 FRAMERATE_MILLISECONDS = 1000 / 60;

typedef struct Point{
	float x,y;
	unsigned char r,v,b;
	struct Point *suiv;
} Point, *PointList;

typedef struct Line{
	float x1,y1,x2,y2;
	unsigned char r,v,b;
	struct Point *suiv;
} Line, *LineList;

typedef struct Triangle{
	float x1,y1,x2,y2,x3,y3;
	unsigned char r,v,b;
	struct Point *suiv;
} Triangle, *TriangleList;

Point * allocPoint(float x, float y, unsigned char r, unsigned char v,
unsigned char b){
	PointList tmp=malloc(sizeof(Point));
	if (tmp==NULL){printf("l'allocation n'a pas foncionnée\n");}
	tmp->x=x; tmp->y=y;
	tmp->r=r; tmp->v=v; tmp->b=b;
	return tmp;
}

void addPointToList(Point *point, PointList * liste){
	if (*liste==NULL){ printf("1ere cell\n");
		*liste=point;
	}
	else{
		//PointList tmp=*liste;
		addPointToList(point, &(*liste)->suiv);
	}
}

void drawPoints(PointList liste){
	while (liste!=NULL){
		glColor3ub(liste->r,liste->v,liste->b);
		glVertex2f(-1+2.*liste->x/WINDOW_WIDTH,-(-1+2.*liste->y/WINDOW_HEIGHT));
		liste=liste->suiv;
	}
}

void deletePoints(PointList* list) {
    assert(list);
    while (*list) {
        Point* suiv = (*list)->suiv;
        free(*list);
        *list = suiv;
    }
}

typedef struct Primitive{
    GLenum primitiveType;
    PointList points;
    struct Primitive* suiv;
} Primitive, *PrimitiveList;

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

void addPrimitive(Primitive* primitive, PrimitiveList* list) {
    assert(primitive);
    assert(list);
    if (*list == NULL) {
        // Si le pointeur sur la liste est vide, on le modifie pour le faire pointer sur la primitive donnée en paramètre
        *list = primitive;
    } else {
        // Sinon, on réapplique la même fonction mais sur le point suivant
        addPrimitive(primitive, &(*list)->suiv);
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

void deletePrimitive(PrimitiveList* list) {
    assert(list);
    while(*list) {
        Primitive* suiv = (*list)->suiv;
        deletePoints(&(*list)->points);
        free(*list);
        *list = suiv;
    }
}

void resizeViewport() {
    glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1., 1., -1., 1.);
    SDL_SetVideoMode(WINDOW_WIDTH, WINDOW_HEIGHT, BIT_PER_PIXEL, SDL_OPENGL | SDL_RESIZABLE);
}

void affichePalette(){
	glColor3ub(255,255,255);
    glBegin(GL_QUADS); 
	glVertex2f(-1+2.*0/WINDOW_WIDTH,-(-1+2.*0/WINDOW_HEIGHT));
	glVertex2f(-1+2.*50/WINDOW_WIDTH,-(-1+2.*0/WINDOW_HEIGHT));
	glVertex2f(-1+2.*50/WINDOW_WIDTH,-(-1+2.*400/WINDOW_HEIGHT));
	glVertex2f(-1+2.*0/WINDOW_WIDTH,-(-1+2.*400/WINDOW_HEIGHT));
	glEnd();

	glColor3ub(0,0,0);
	glBegin(GL_QUADS); 
	glVertex2f(-1+2.*50/WINDOW_WIDTH,-(-1+2.*0/WINDOW_HEIGHT));
	glVertex2f(-1+2.*100/WINDOW_WIDTH,-(-1+2.*0/WINDOW_HEIGHT));
	glVertex2f(-1+2.*100/WINDOW_WIDTH,-(-1+2.*400/WINDOW_HEIGHT));
	glVertex2f(-1+2.*50/WINDOW_WIDTH,-(-1+2.*400/WINDOW_HEIGHT));
	glEnd();

	glColor3ub(255,0,0);
	glBegin(GL_QUADS); 
	glVertex2f(-1+2.*100/WINDOW_WIDTH,-(-1+2.*0/WINDOW_HEIGHT));
	glVertex2f(-1+2.*150/WINDOW_WIDTH,-(-1+2.*0/WINDOW_HEIGHT));
	glVertex2f(-1+2.*150/WINDOW_WIDTH,-(-1+2.*400/WINDOW_HEIGHT));
	glVertex2f(-1+2.*100/WINDOW_WIDTH,-(-1+2.*400/WINDOW_HEIGHT));
	glEnd();

	glColor3ub(0,255,0);
	glBegin(GL_QUADS); 
	glVertex2f(-1+2.*150/WINDOW_WIDTH,-(-1+2.*0/WINDOW_HEIGHT));
	glVertex2f(-1+2.*200/WINDOW_WIDTH,-(-1+2.*0/WINDOW_HEIGHT));
	glVertex2f(-1+2.*200/WINDOW_WIDTH,-(-1+2.*400/WINDOW_HEIGHT));
	glVertex2f(-1+2.*150/WINDOW_WIDTH,-(-1+2.*400/WINDOW_HEIGHT));
	glEnd();

	glColor3ub(0,0,255);
	glBegin(GL_QUADS); 
	glVertex2f(-1+2.*200/WINDOW_WIDTH,-(-1+2.*0/WINDOW_HEIGHT));
	glVertex2f(-1+2.*250/WINDOW_WIDTH,-(-1+2.*0/WINDOW_HEIGHT));
	glVertex2f(-1+2.*250/WINDOW_WIDTH,-(-1+2.*400/WINDOW_HEIGHT));
	glVertex2f(-1+2.*200/WINDOW_WIDTH,-(-1+2.*400/WINDOW_HEIGHT));
	glEnd();

	glColor3ub(255,255,0);
	glBegin(GL_QUADS); 
	glVertex2f(-1+2.*250/WINDOW_WIDTH,-(-1+2.*0/WINDOW_HEIGHT));
	glVertex2f(-1+2.*300/WINDOW_WIDTH,-(-1+2.*0/WINDOW_HEIGHT));
	glVertex2f(-1+2.*300/WINDOW_WIDTH,-(-1+2.*400/WINDOW_HEIGHT));
	glVertex2f(-1+2.*250/WINDOW_WIDTH,-(-1+2.*400/WINDOW_HEIGHT));
	glEnd();

	glColor3ub(0,255,255);
	glBegin(GL_QUADS); 
	glVertex2f(-1+2.*300/WINDOW_WIDTH,-(-1+2.*0/WINDOW_HEIGHT));
	glVertex2f(-1+2.*350/WINDOW_WIDTH,-(-1+2.*0/WINDOW_HEIGHT));
	glVertex2f(-1+2.*350/WINDOW_WIDTH,-(-1+2.*400/WINDOW_HEIGHT));
	glVertex2f(-1+2.*300/WINDOW_WIDTH,-(-1+2.*400/WINDOW_HEIGHT));
	glEnd();

	glColor3ub(255,0,255);
	glBegin(GL_QUADS); 
	glVertex2f(-1+2.*350/WINDOW_WIDTH,-(-1+2.*0/WINDOW_HEIGHT));
	glVertex2f(-1+2.*400/WINDOW_WIDTH,-(-1+2.*0/WINDOW_HEIGHT));
	glVertex2f(-1+2.*400/WINDOW_WIDTH,-(-1+2.*400/WINDOW_HEIGHT));
	glVertex2f(-1+2.*350/WINDOW_WIDTH,-(-1+2.*400/WINDOW_HEIGHT));
	glEnd();
}

int main(int argc, char** argv) {

    /* Initialisation de la SDL */
    if(-1 == SDL_Init(SDL_INIT_VIDEO)) {
        fprintf(stderr, "Impossible d'initialiser la SDL. Fin du programme.\n");
        return EXIT_FAILURE;
    }
    
    /* Ouverture d'une fenêtre et création d'un contexte OpenGL */
    if(NULL == SDL_SetVideoMode(WINDOW_WIDTH, WINDOW_HEIGHT, BIT_PER_PIXEL, SDL_OPENGL | SDL_GL_DOUBLEBUFFER)) {
        fprintf(stderr, "Impossible d'ouvrir la fenetre. Fin du programme.\n");
        return EXIT_FAILURE;
    }
    
    /* Titre de la fenêtre */
    SDL_WM_SetCaption("TD1 OpenGL", NULL);

    glClearColor(0.1, 0.1, 0.1, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    /* On créé une première primitive par défaut */
    PrimitiveList primitives = NULL;
    Primitive* prim = allocPrimitive(GL_POINTS);
    PrimitiveList lastPrim = prim;
    addPrimitive(prim, &primitives);
    
    /* Boucle d'affichage */
    int loop = 1;
    int Palette=0; /*Booléen pour afficher ou non la palette de couleurs*/ 
    float r=255,v=255,b=255;
    GLenum currentPrimitiveType = GL_POINTS;

    while(loop) {

        /* Récupération du temps au début de la boucle */
        Uint32 startTime = SDL_GetTicks();
        
        /*on clear la fenetre*/
        glClear(GL_COLOR_BUFFER_BIT);

        /* Placer ici le code de dessin */
        if (Palette==0){
        	drawPrimitives(primitives);
        }

		if (Palette==1){
			affichePalette();
		}
			         	
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

	            /* Clic souris */
	            case SDL_MOUSEBUTTONUP:
	            	if (Palette==0){
	            		/* Transformation des coordonnées du clic souris en coordonnées OpenGL */
                        float x = -1 + 2. * e.button.x / WINDOW_WIDTH;
                        float y = -(-1 + 2. * e.button.y / WINDOW_HEIGHT);
		            	addPointToList(allocPoint(x,y,r,v,b), &lastPrim->points);

		
			        }
			        if (Palette==1){
			        	if (0<=e.button.x && e.button.x<50){r=255; v=255; b=255;}
			        	if (50<=e.button.x && e.button.x<100){r=0; v=0; b=0;}
			        	if (100<=e.button.x && e.button.x<150){r=255; v=0; b=0;}
			        	if (150<=e.button.x && e.button.x<200){r=0; v=255; b=0;}
			        	if (200<=e.button.x && e.button.x<250){r=0; v=0; b=255;}
			        	if (250<=e.button.x && e.button.x<300){r=255; v=255; b=0;}
			        	if (300<=e.button.x && e.button.x<350){r=0; v=255; b=255;}
			        	if (350<=e.button.x && e.button.x<400){r=255; v=0; b=255;}
			        	Palette=0;
			        }
                    //glClearColor(r,v,b,a);
                    printf("clic en (%d, %d)\n", e.button.x, e.button.y);
                    break;

                /*case SDL_MOUSEMOTION:
                    glColor3ub(255,255,255);
                    break;*/

                /* Touche clavier */
                case SDL_KEYDOWN:
                    printf("touche pressée (code = %d)\n", e.key.keysym.sym);
                    if (e.key.keysym.sym=='q'){
                        loop=0;
                    }

                    int newPrimitivePressed = 0;
                    GLenum newPrimitiveType;

                    if (e.key.keysym.sym=='p'){
                    	newPrimitivePressed = 1;
                        newPrimitiveType = GL_POINTS;
                    	break;
                    }
                    if (e.key.keysym.sym=='t'){
                    	newPrimitivePressed = 1;
                            newPrimitiveType = GL_TRIANGLES;
                    	break;
                    }
                    if (e.key.keysym.sym=='l'){
                    	newPrimitivePressed = 1;
                            newPrimitiveType = GL_LINES;
                    	break;
                    }
                    if (e.key.keysym.sym=='c'){
                        deletePrimitive(&primitives); // on supprime les primitives actuelles
                        addPrimitive(allocPrimitive(currentPrimitiveType), &primitives); // on réinitialise à la primitive courante
                        break;
                    }
                    if (e.key.keysym.sym==' '){
                        Palette=1;
                        break;
                    }

                if (newPrimitivePressed && currentPrimitiveType != newPrimitiveType) {
                        prim = allocPrimitive(newPrimitiveType);
                        lastPrim = prim;
                        addPrimitive(prim, &primitives);
                        currentPrimitiveType = newPrimitiveType;
                }
                break;

                default:
                    break;
            }
        }

        /* Echange du front et du back buffer : mise à jour de la fenêtre */
        SDL_GL_SwapBuffers();

        /* Calcul du temps écoulé */
        Uint32 elapsedTime = SDL_GetTicks() - startTime;

        /* Si trop peu de temps s'est écoulé, on met en pause le programme */
        if(elapsedTime < FRAMERATE_MILLISECONDS) {
            SDL_Delay(FRAMERATE_MILLISECONDS - elapsedTime);
        }
    }

	deletePrimitive(&primitives);

    /* Liberation des ressources associées à la SDL */ 
    SDL_Quit();

    return EXIT_SUCCESS;
}
