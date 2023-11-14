#include<stdio.h>
#include<stdbool.h>
#include<windows.h>
#include <conio.h>

#include "librerias/estructuras.h"
#include "librerias/grafos.h"


//prototipos
void crearSolucion();
void crearPasillo();
bool evaluarMovimiento(tGrafoNoPonderado *,tCordenadas);


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
		
		bool movimiento; 
		
		switch( direccion ){
			
			case 'w':
				
				actual.x--;
				
				movimiento = evaluarMovimiento(&grafo, actual);
				
				if(!movimiento) {
					actual.x++;
				}
				
				break;
			
			case 'a':
				actual.y--;
				
				movimiento = evaluarMovimiento(&grafo, actual);
				
				if(!movimiento) {
					actual.y++;
				}
				break;
				
			case 'd':
				actual.y++;
				
				movimiento = evaluarMovimiento(&grafo, actual);
				
				if(!movimiento) {
					actual.y--;
				}
				break;
			
			case 's':
				actual.x++;
				
				movimiento = evaluarMovimiento(&grafo, actual);
				
				if(!movimiento) {
					actual.x--;
				}
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

bool evaluarMovimiento(tGrafoNoPonderado * pGrafo, tCordenadas pCordenada) {
	if(pGrafo->arcos[pCordenada.x][pCordenada.y] == 1) {
		return true;	
	} else {
		return false;
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
	crearPasilloFila(6, 8, 4);
	crearPasilloFila(6, 8, 5);
	crearPasilloFila(6, 8, 6);
	crearPasilloFila(6, 8, 7);
	crearPasilloFila(3, 5, 7);
	crearPasilloFila(3, 5, 8);
	crearPasilloFila(3, 5, 9);
	crearPasilloFila(3, 5, 10);
	crearPasilloFila(3, 5, 11);
	crearPasilloFila(6,15 , 11);
	crearPasilloFila(13, 15, 12);
	crearPasilloFila(13, 15, 13);
	crearPasilloFila(16, 23, 13);
	crearPasilloFila(3, 19, 1);
	crearPasilloFila(3, 5, 2);
	crearPasilloFila(17, 19, 2);
	crearPasilloFila(3, 5, 3);
	crearPasilloFila(17, 19, 3);
    crearPasilloFila(0, 5, 4);   
    crearPasilloFila(13, 19, 4); 
    crearPasilloFila(13, 15, 5);
	crearPasilloFila(13, 25, 6);
	crearPasilloFila(21, 23, 12);
	crearPasilloFila(21, 23, 11);
	crearPasilloFila(21, 23, 10);
	crearPasilloFila(21, 23, 9);
	crearPasilloFila(6, 8, 7);
	
	crearPasilloFila(18,20,9);
	crearPasilloFila(18,20,8);
	crearPasilloFila(18,20,7);
}



