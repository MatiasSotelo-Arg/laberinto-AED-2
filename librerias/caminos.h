void crearPasillo(tGrafoNoPonderado *, tArco, int, int);

void crearPasillo(tGranoNoPonderado * pGrafo, tArco pArco, int pInicio, int pFin) {
	
	int i,j;
	
	for(j=pInicio; j<pFin; j++){
		
		pArco.origen = pInicio;
		pArco.destino = pFin;
		agregarArco( pGrafo, pArco);
		
	}
	
}


