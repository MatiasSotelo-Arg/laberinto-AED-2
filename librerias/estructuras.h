#define N 26

typedef int tVertice;

typedef char tString[10];
typedef char tChar[2];

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
    bool ganaste;

} tCordenadas;

typedef struct {
	tString nombre; 
	int movimientos;
	float tiempo;
}tUsuario;

FILE * archivo; 
tUsuario usuario; 
