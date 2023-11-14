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
