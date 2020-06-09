#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define LEER		0
#define ESCRIBIR	1
#define tamBuffer  300   //<---- EL valor de buffer se cambia aqui

int main(int arc, char const *argv[]) {
  FILE *archivo;
  FILE *nuevoArchivo;
  int descr[2];	/* Descriptores de E y S de la turbería */
  int caracter[tamBuffer],auxcaracter[tamBuffer];
  printf("Transferencia de imagen a traves de pipies\n");

  if(arc!=3){
    printf("Error revisar entrada:\nprograma.exe ArchivoOrigen NombreCopia\n");
    exit(1);
  }
  
  archivo = fopen(argv[1], "r");
  nuevoArchivo=fopen(argv[2], "w+");
  printf("ArchivoEntrada:%s\n",argv[1]);
  printf("ArchivoSalida:%s\n",argv[2]);
  printf("Buffer:%d\n",tamBuffer);

 	if (archivo == NULL){
    printf("Error al abrir archivo origen\n");
    fclose(nuevoArchivo);
    fclose(archivo);
 		exit(1);
 	}else{
    pipe (descr);
    if (fork () == 0){
      //ESTA ES LA CONFIGURACION DE LAS TUBERIAS
      //tuberia del padre hacia hijo
      close (descr[ESCRIBIR]);
      do{
        //ESTA ES LA PARTE DE LA COMUNICACION DE LAS TUBERIAS
        //tuberia del padre hacia hijo
        read (descr[LEER], &auxcaracter, sizeof(auxcaracter[0])*tamBuffer);
        printf("Recibi:\n");
        for(int i=0;i<tamBuffer;i++){
            //Revisa la condicion de parada si esta se cumple finaliza el programa
            if(auxcaracter[i]==-1){
                //CERRADO DE LAS TUBERIAS
                close (descr[LEER]);
                printf("\nFinalizado hijo\n");
                //CERRADO ARCHIVO
                fclose(nuevoArchivo);
                fclose(archivo);
                exit(0);
            }
            fprintf(nuevoArchivo,"%c",auxcaracter[i]);
            printf("%d|",auxcaracter[i]);
        }
        printf("\n");
      }while(1);
    }else{
      //ESTA ES LA CONFIGURACION DE LAS TUBERIAS
      //tuberia del padre hacia hijo
      close (descr[LEER]);
      //ESTA ES LA PARTE DE LA COMUNICACION DE LAS TUBERIAS
      //tuberia del padre hacia hijo
      for(int i=0;i<tamBuffer;i++){
        caracter[i]=-1;
      }
      int i=0;
      do{
        caracter[i%tamBuffer]=(int)fgetc(archivo);  
        i++;
        if( ( (i%tamBuffer)==0 && i>0) || feof(archivo)!=0){

            printf("Mande:\n");
            for(int z=0;z<tamBuffer;z++){
                printf("%d|",caracter[z]);
            }
            printf("\n");

            write (descr[ESCRIBIR], &caracter, sizeof(caracter[0])*tamBuffer);
            for(int j=0;j<tamBuffer;j++){
                caracter[j]=-1;
            }
        }
      }while (feof(archivo) == 0);
      //CERRADO DE LAS TUBERIAS
      close (descr[ESCRIBIR]);
      printf("\nYa mande todo\nFinalizado padre\n");
    }
  }
  wait(NULL);
  //CERRADO ARCHIVO
  fclose(nuevoArchivo);
  fclose(archivo);
	return 0;
}