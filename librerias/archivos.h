//prototipo de funciones
FILE * abrirArchivo(tString, tChar);
tUsuario leerRegistro(FILE *);
void cerrarArchivo(FILE *);

FILE * abrirArchivo(tString pNombreArchivo, tChar pModo) {
     archivo = fopen(pNombreArchivo, pModo);
    
    if (archivo != NULL) {
        return archivo;
    } else {
        return NULL;
    }
}

tUsuario leerRegistro(FILE * pArchivo) {
	
	fread(&usuario,sizeof(tUsuario),1,pArchivo);
	
	return usuario;
}

void cerrarArchivo(FILE * pArchivo) {
	fclose(pArchivo);
}
