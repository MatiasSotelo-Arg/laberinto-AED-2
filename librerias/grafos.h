void inicializarGrafo( tGrafoNoPonderado *); 
void agregarVertice( tGrafoNoPonderado * , tVertice);
void agregarArco( tGrafoNoPonderado *, tArco ); 
bool existeVertice( tGrafoNoPonderado, tVertice );
void prenderVertice(tGrafoNoPonderado *);


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
	pGrafo->vertices[pVertice] = 1;
	
} 

void prenderVertice(tGrafoNoPonderado * pGrafo){
	int x;
	for (x=0; x<N; x++){
		
		agregarVertice( pGrafo, x );
		
	}
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

