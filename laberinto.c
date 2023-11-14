#include<stdio.h>
#include<stdbool.h>
#include<windows.h>
#include <conio.h>

#define N 26


typedef int tVertice;

typedef struct {
	
	tVertice origen;
	tVertice destino;
		
} tArco;

typedef bool conjuntoVertices[N];

typedef bool conjuntoArcos[N][N];

typedef struct {
	
	conjuntoVertices vertices;
	conjuntoArcos arcos;
	
} tGrafoNoPonderado;

typedef struct {
	
    int x;
    int y;
    bool primerEjecucion;
    
} tCordenadas;

//prototipo 

void crearSolucion();
void crearPasillo();

void inicializarGrafo( tGrafoNoPonderado * );
void agregarVertice( tGrafoNoPonderado * , tVertice);
void prenderVertice(); 
void agregarArco( tGrafoNoPonderado *, tArco ); 
bool existeVertice( tGrafoNoPonderado, tVertice );

void imprimirLab( tGrafoNoPonderado );


//variables
tVertice vertice;
tArco arco;
tGrafoNoPonderado grafo;
tCordenadas inicio,fin, actual;

//funcion principal
int main(){
	
	
	inicio.x = 4;
	inicio.y = 1;
	fin.x = 7;
	fin.y = 25;
	inicio.primerEjecucion = true;
	
	inicializarGrafo( &grafo );
	prenderVertice();
	crearPasillo();	

	char terminar = 'n';
	
	actual.x = inicio.x;
	actual.y = inicio.y;
	
	do {
		
		system("cls");
		
		printf("Mover hacia W A D S\n");
		imprimirLab(grafo);
		
		char direccion;

//		fflush(stdin);
		
//		scanf("%c",&direccion);
		
		direccion = _getch();
		
		switch( direccion ){
			
			case 'w':
				actual.x--;
				break;
			
			case 'a':
				actual.y--;
				break;
				
			case 'd':
				actual.y++;
				break;
			
			case 's':
				actual.x++;
				break; 
				
		}
	}
	while(terminar != 's'); 
	


	return 0;
}

//implementacion

void inicializarGrafo( tGrafoNoPonderado * pGrafo ) {
	int x, y;
	
	for( x=0; x<=N; x++ ) {
		pGrafo->vertices[x]= 0;		
					
		for( y=0; y<=N; y++ ) {
			pGrafo->arcos[x][y] = 0;
		}
	}
}


void agregarVertice( tGrafoNoPonderado * pGrafo, tVertice pVertice ) {
	// ( *pGrafo ).vertices[pVertice] = 1;
	pGrafo->vertices[pVertice] = 1;//
	
} 


void prenderVertice(){
	int x;
	for (x=0; x<N; x++){
		
		agregarVertice( &grafo, x );
		
	}
}


void imprimirLab(tGrafoNoPonderado pGrafo) {
    int x, y;
    bool existeArista = false;

    for (x = 0; x <15; x++) {
        for (y = 0; y < N; y++) {
            existeArista = (pGrafo.arcos[x][y] == 1) && existeVertice(pGrafo, x) && existeVertice(pGrafo, y);

            if (existeArista) {
                if (inicio.primerEjecucion) {
                    if (x == inicio.x && y == inicio.y) {
                        inicio.primerEjecucion = false;
                        printf("X");
                    } else {
                        printf(" ");
                    }
                } else {
                    if (x == actual.x && y == actual.y) {
                        printf("X");
                    } else {
                        printf(" ");
                    }
                }
				
            } else {
                printf("%C", 178);
            }
        }
        printf("\n");
    }
}

void crearPasillo( ){
	
	int i,j;
	
	for(j=3; j<19; j++){
		
		arco.origen = 1;
		arco.destino = j;
		agregarArco( &grafo, arco);
		
	}
		
	for(j=0; j<3; j++){
	
		arco.origen = 4;
		arco.destino = j;
		agregarArco( &grafo, arco);
		
	}
	
	for(i= 2; i< 5; i++ ){
		for(j=3; j<6; j++){
			
			arco.origen = i;
			arco.destino =j;
			agregarArco( &grafo, arco);
		}
	}
	
	for(i= 1; i< 8; i++ ){
		for(j=18; j<21; j++){
			
			arco.origen = i;
			arco.destino = j;
			agregarArco( &grafo, arco);
		}
	}
	
	
	for(i=4 ; i<8 ; i++ ){
		for(j=6; j<9; j++){
			
			arco.origen= i;
			arco.destino=j;
			agregarArco(&grafo, arco);
			
		}
	}
	
	for(j=21; j<26; j++){
	
		arco.origen = 7;
		arco.destino = j;
		agregarArco( &grafo, arco);
	}
	
	for(j=3; j<9; j++){
		
		arco.origen = 13;
		arco.destino = j;
		agregarArco( &grafo, arco);
	}
	
	for(j=12; j<24; j++){
		
		arco.origen = 13;
		arco.destino = j;
		agregarArco( &grafo, arco);
	}
	
	for(i= 11; i< 14; i++ ){
		for(j=21; j<24; j++){
			
			arco.origen = i;
			arco.destino =j;
			agregarArco( &grafo, arco);
		}
	}
	
	for(i= 8; i< 12; i++ ){
		for(j=18; j<21; j++){
			
			arco.origen = i;
			arco.destino =j;
			agregarArco( &grafo, arco);
		}
	}
	
	for(i=7; i<14; i++){
		for(j=3; j<6; j++){
		
			arco.origen = i;
			arco.destino =j;
			agregarArco( &grafo, arco);
		}
	}
	
	for(j=6; j<15; j++){
		
		arco.origen = 10;
		arco.destino = j;
		agregarArco( &grafo, arco);
	}
	
	for(i=10; i<14; i++){
		for(j=12; j<15; j++){
		
			arco.origen = i;
			arco.destino =j;
			agregarArco( &grafo, arco);
		
		}
	}
	
}


void crearSolucion(tGrafoNoPonderado pGrafo){


	
	
}


void agregarArco(tGrafoNoPonderado * pGrafo, tArco pArco){


	if(pGrafo->vertices[pArco.origen]==1 && pGrafo->vertices[pArco.destino]==1){
	
		( * pGrafo ).arcos[pArco.origen][pArco.destino]=1;		
		

	}else{
			
		printf( "No se pudo agregar - Alguno de los vertices no se encuentra activo\n" );
	
	}
		
}
 	
 	
bool existeVertice( tGrafoNoPonderado pGrafo, tVertice pVertice ) {
	return pGrafo.vertices[pVertice] == 1;
}


/*void crearLab(tGrafoNoPonderado pGrafo){
	
	bool existeArista = false;
	int i,j,x,y;
	
	// Imprimir la parte superior del marco
	for ( i = 0; i < N + 2; i++) {
        
		printf("  %c",126);
        
    }
    
    printf("\n");
    
    //paredes del laberinto
    crearParedes();
	
    // Imprimir el contenido de la matriz con los bordes
    for ( i = 0; i < N; i++) {
    	// Borde izquierdo
		if(i==4){
    		printf("E"); 
			
    	}else{
    		
    		printf("  |");
    	}
    	
        //contenido
        for(x=1; x<=N; x++){
			for(y=1; y<=N; y++){
			
				existeArista  ( pGrafo.arcos[x][y]==1 ) && existeVertice(pGrafo , x ) && existeVertice (pGrafo, y); 
			
				if(existeArista){
				 
					printf(" ");
			
				}else{
				
					printf("%c",219);
				
			}
		}
		printf("\n");
	}	
        
        
        // Borde derecho y nueva línea
        if(i==7 ){
        	
    		printf("  S\n"); 

    	}else{
    		
    		printf("|\n");
    	} 
	
	}

    // Imprimir la parte inferior del marco
    
	for ( i = 0; i < N + 2; i++) {
        
		printf("  %c",126);
        
    }
    
    printf("\n");
    

}
    
*/



    
