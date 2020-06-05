#include <stdio.h>
#include <stdlib.h>

int main(void) {
  FILE *archivo;
  FILE *nuevoArchivo;
  int caracter;

  printf("Transferencia de imagen a traves de pipies\n");

  archivo = fopen("typeR.jpg", "r");
  nuevoArchivo=fopen("typeRhijo.jpg", "w+");

 	if (archivo == NULL)
 		exit(1);
 	else{
 	  printf("\nEl contenido del archivo de prueba es \n\n");printf("\nEl contenido del archivo de prueba es \n\n");
    while (feof(archivo) == 0){
 		  caracter=(int)fgetc(archivo);

 		  printf("%c",caracter);
      //fseek(nuevoArchivo,0,SEEK_END);
      fprintf(nuevoArchivo,"%c",caracter);
      //fputc(caracter, nuevoArchivo );
    }
    system("PAUSE");
  }

  fclose(nuevoArchivo);
  fclose(archivo);
	return 0;
}


int n = something();
write(pipe_w, &n, sizeof(n));

int n;
read(pipe_r, &n, sizeof(n));


255 216 255 226 11 248 73 67 67 95 80 82 79 70 73 76 69 0 1 1 0 0 11 232 0 0 0 0 2 0 0 0 109 110 116 114 82 71 66 32 88 89 90 32 7 217 0 3 0 27 0 21 0 36 0 31 97 99 115 112 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 246 214 0 1 0 0 0 0 211 45 

0 0 0 0 41 248 61 222 175 242 85 174 120 66 250 228 202 131 57 13 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 16 100 101 115 99 0 0 1 68 0 0 0 121 98 88 89 90 0 0 1 192 0 0 0 20 98 84 82 67 0 0 1 212 0 0 8 12 100 109 100 100 0 0 9 224 0 0 0 136 