#define N 26


typedef int tVertice;

typedef struct {
	
	tVertice origen;
	tVertice destino;
		
} tArco;

typedef int conjuntoVertices[N];

typedef int conjuntoArcos[N][N];

typedef struct {
	
	conjuntoVertices vertices;
	conjuntoArcos arcos;
	
} tGrafoNoPonderado;

typedef struct {
	
    int x;
    int y;
    
    bool primerEjecucion;
    
} tCordenadas;
