#include<stdio.h>
#include<stdbool.h>
#include<windows.h>
#include <conio.h>

#include "librerias/estructuras.h"
#include "librerias/grafos.h"


//prototipos
void crearSolucion();
void crearPasillo();


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
	
	inicializarGrafo(&grafo);
	prenderVertice(&grafo);
	crearPasillo();

	char terminar = 'n';
	
	actual.x = inicio.x;
	actual.y = inicio.y;
	
	do {
		
		system("cls");
		
		printf("Mover hacia W A D S\n");
		imprimirLab(grafo);
		
		char direccion;
		
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

void crearPasilloFila(int colInicio, int colFin, int origen) {
    int j;
    tArco arco;

    for (j = colInicio; j <= colFin; j++) {
        arco.origen = origen;
        arco.destino = j;
        agregarArco(&grafo, arco);
    }
}

void crearPasillo() {
	crearPasilloFila(3, 19, 1);
	crearPasilloFila(3, 5, 2);
	crearPasilloFila(17, 19, 2);
	crearPasilloFila(3, 5, 3);
	crearPasilloFila(17, 19, 3);
    crearPasilloFila(0, 5, 4);   
    crearPasilloFila(10, 19, 4); 
    crearPasilloFila(10, 12, 5);
	crearPasilloFila(10, 12, 6); 
	crearPasilloFila(13, 25, 6);
}



//void crearPasillo( ){
//	
//	int i,j;
//	
//	for(j=3; j<19; j++){
//		
//		arco.origen = 1;
//		arco.destino = j;
//		agregarArco( &grafo, arco);
//		
//	}
//		
//	for(j=0; j<3; j++){
//	
//		arco.origen = 4;
//		arco.destino = j;
//		agregarArco( &grafo, arco);
//		
//	}
//	
//	for(i= 2; i< 5; i++ ){
//		for(j=3; j<6; j++){
//			
//			arco.origen = i;
//			arco.destino =j;
//			agregarArco( &grafo, arco);
//		}
//	}
//	
//	for(i= 1; i< 8; i++ ){
//		for(j=18; j<21; j++){
//			
//			arco.origen = i;
//			arco.destino = j;
//			agregarArco( &grafo, arco);
//		}
//	}
//	
//	
//	for(i=4 ; i<8 ; i++ ){
//		for(j=6; j<9; j++){
//			
//			arco.origen= i;
//			arco.destino=j;
//			agregarArco(&grafo, arco);
//			
//		}
//	}
//	
//	for(j=21; j<26; j++){
//	
//		arco.origen = 7;
//		arco.destino = j;
//		agregarArco( &grafo, arco);
//	}
//	
//	for(j=3; j<9; j++){
//		
//		arco.origen = 13;
//		arco.destino = j;
//		agregarArco( &grafo, arco);
//	}
//	
//	for(j=12; j<24; j++){
//		
//		arco.origen = 13;
//		arco.destino = j;
//		agregarArco( &grafo, arco);
//	}
//	
//	for(i= 11; i< 14; i++ ){
//		for(j=21; j<24; j++){
//			
//			arco.origen = i;
//			arco.destino =j;
//			agregarArco( &grafo, arco);
//		}
//	}
//	
//	for(i= 8; i< 12; i++ ){
//		for(j=18; j<21; j++){
//			
//			arco.origen = i;
//			arco.destino =j;
//			agregarArco( &grafo, arco);
//		}
//	}
//	
//	for(i=7; i<14; i++){
//		for(j=3; j<6; j++){
//		
//			arco.origen = i;
//			arco.destino =j;
//			agregarArco( &grafo, arco);
//		}
//	}
//	
//	for(j=6; j<15; j++){
//		
//		arco.origen = 10;
//		arco.destino = j;
//		agregarArco( &grafo, arco);
//	}
//	
//	for(i=10; i<14; i++){
//		for(j=12; j<15; j++){
//		
//			arco.origen = i;
//			arco.destino =j;
//			agregarArco( &grafo, arco);
//		
//		}
//	}
//	
//}

