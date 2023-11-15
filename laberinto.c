#include<stdio.h>
#include<stdbool.h>
#include<windows.h>
#include <conio.h>
#include <time.h>

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
	fin.x = 6;
	fin.y = 25;
	
	inicio.primerEjecucion = true;
	
	int contMovimientos = 0;
	
	inicializarGrafo(&grafo);
	prenderVertice(&grafo);
	crearPasillo();

	char terminar = 'n';
	bool salir = false;
	
	actual.x = inicio.x;
	actual.y = inicio.y;
	
	clock_t inicio, fin;
    double tiempo;
    
    inicio = clock();
    
    actual.ganaste = false;
	
	do {
			
		system("cls");
		
		if(actual.ganaste == true) {
			printf("ganaste");
		}  else {
				printf("Mover hacia W A D S\n");
		printf("x para salir\n");
		
		imprimirLab(grafo);
		printf("Movimientos: %d",contMovimientos);
		}
		
	
		
		char direccion;
		fflush(stdin);
		direccion = _getch();
			
		bool movimiento; 
			
		switch( direccion ){
			
			case 'w':
				
				actual.x--;
				
				movimiento = evaluarMovimiento(&grafo, actual);
				
				
				if(!movimiento) {
					actual.x++;
				} else {
					contMovimientos++;
				}
				
				break;
			
			case 'a':
				actual.y--;
				
				movimiento = evaluarMovimiento(&grafo, actual);
				
				if(!movimiento) {
					actual.y++;
				} else {
					contMovimientos++;
				}
				break;
				
			case 'd':
				actual.y++;
				
				movimiento = evaluarMovimiento(&grafo, actual);
				
				if(!movimiento) {
					actual.y--;
				} else {
					contMovimientos++;
				}
				break;
			
			case 's':
				actual.x++;
				
				movimiento = evaluarMovimiento(&grafo, actual);
				
				if(!movimiento) {
					actual.x--;
				} else {
					contMovimientos++;
				} 
				break; 
			
			case 'x': 
				system("cls");
				printf("Se salio\n");
				terminar = 's';
				tiempo = ((double)(fin - inicio)) / CLOCKS_PER_SEC;
				printf("Tiempo: %f",tiempo);
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
                        actual.x = x;
                        actual.y = y;
                        
                        //evaluar si gana
                        if(actual.x == fin.x && actual.y == fin.y) {
                        	actual.ganaste = true;
                        }
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



