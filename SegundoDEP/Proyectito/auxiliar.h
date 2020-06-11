
//MEMORIA//
#define TAM_MEM 10
int *Memoria;

int CreaLigaMemoria( void );
void DestruyeMemoria( int id_Memoria , int *buffer );
sem_t * CrearSemaforo(  char *name , int val );
void produce(int num,int id_mem,int stopDatos);
void consume(int id_mem, int id);
void LimpiaArchivos();
void meteValorArchivo(int i);
void unlinkSemaforos();
void stopProces(int id_mem);

        /* NOMBRE SEMAFOROS */
char 
/*bloque 1*/
*name_sem_p1_z1="name_sem_p1_z1",*name_sem_c1_z1="name_sem_c1_z1",
*name_sem_p2_z1="name_sem_p2_z1",*name_sem_c2_z1="name_sem_c2_z1",
*name_sem_p3_z1="name_sem_p3_z1",*name_sem_c3_z1="name_sem_c3_z1",
*name_sem_p4_z1="name_sem_p4_z1",*name_sem_c4_z1="name_sem_c4_z1",
*name_sem_p5_z1="name_sem_p5_z1",*name_sem_c5_z1="name_sem_c5_z1",
/*bloque 2*/
*name_sem_p1_z2="name_sem_p1_z2",*name_sem_c1_z2="name_sem_c1_z2",
*name_sem_p2_z2="name_sem_p2_z2",*name_sem_c2_z2="name_sem_c2_z2",
*name_sem_p3_z2="name_sem_p3_z2",*name_sem_c3_z2="name_sem_c3_z2",
*name_sem_p4_z2="name_sem_p4_z2",*name_sem_c4_z2="name_sem_c4_z2",
*name_sem_p5_z2="name_sem_p5_z2",*name_sem_c5_z2="name_sem_c5_z2",
//archivos//
*name_sem_f1="file1",*name_sem_f2="file2",
*name_sem_f3="file3",*name_sem_f4="file4",
//bloque
*name_b1_p="bloque_1_prod",*name_b1_c="bloque_1_cons",
*name_b2_p="bloque_2_prod",*name_b2_c="bloque_2_cons";
    /* DECLARACION DE SEMAOFOROS*/
sem_t 
/*zona 1*/
*sem_p1_z1 , *sem_c1_z1,
*sem_p2_z1 , *sem_c2_z1,
*sem_p3_z1 , *sem_c3_z1,
*sem_p4_z1 , *sem_c4_z1,
*sem_p5_z1 , *sem_c5_z1,
/*zona 2*/
*sem_p1_z2 , *sem_c1_z2,
*sem_p2_z2 , *sem_c2_z2,
*sem_p3_z2 , *sem_c3_z2,
*sem_p4_z2 , *sem_c4_z2,
*sem_p5_z2 , *sem_c5_z2,
//semaforos archivos//
*sem_f1,*sem_f2 ,*sem_f3, *sem_f4,
//bloque_1_cons
*sem_p_b1,*sem_c_b1,
*sem_p_b2,*sem_c_b2;

void produce(int num,int id_mem,int stopDatos){
    /*>>>>>>>>>>>>>>>>productor1<<<<<<<<<<<<<<<*/
    id_mem=CreaLigaMemoria();
    //PRODUCE 1
    int i,j;
    int value1_z1,value2_z1,value3_z1,value4_z1,value5_z1;
    int value1_z2,value2_z2,value3_z2,value4_z2,value5_z2;
    i=j=0;
    while(1){
        if(i <= stopDatos){
            sem_wait(sem_p_b1);
            ////>>> BLOQUE CRITICO 1 <<<////
            sem_getvalue(sem_p1_z1, &value1_z1);
            sem_getvalue(sem_p2_z1, &value2_z1);
            sem_getvalue(sem_p3_z1, &value3_z1);
            sem_getvalue(sem_p4_z1, &value4_z1);
            sem_getvalue(sem_p5_z1, &value5_z1);
            if(value1_z1 == 1 && i <= stopDatos){
                if(i>=stopDatos){
                    sem_wait( sem_p1_z1 );
                    Memoria[0] = -num;
                    printf(">>limite<<\n");
                    i++;
                    sem_post( sem_c1_z1 );
                }else{
                    sem_wait( sem_p1_z1 );
                    Memoria[0] = num;
                    //printf("Prod %d: zc=1  Bc=1: %d\n",num,i);
                    i++;
                    sem_post( sem_c1_z1 );
                }
            }else if(value2_z1 == 1 && i <= stopDatos){
                if(i>=stopDatos){
                    sem_wait( sem_p2_z1 );
                    Memoria[1] = -num;
                    printf(">>limite<<\n");
                    i++;
                    sem_post( sem_c2_z1 );
                }else{
                    sem_wait( sem_p2_z1 );
                    Memoria[1] = num;
                    //printf("Prod %d: zc=2  Bc=1: %d\n",num,i);
                    i++;
                    sem_post( sem_c2_z1 );
                }
            }else if(value3_z1 == 1 && i <= stopDatos){
                if(i>=stopDatos){
                    sem_wait( sem_p3_z1 );
                    Memoria[2] = -num;
                    printf(">>limite<<\n");
                    i++;
                    sem_post( sem_c3_z1 );
                }else{
                    sem_wait( sem_p3_z1 );
                    Memoria[2] = num;
                    //printf("Prod %d: zc=3  Bc=1: %d\n",num,i);
                    i++;
                    sem_post( sem_c3_z1 );
                }
            }else if(value4_z1 == 1 && i <= stopDatos){
                if(i>=stopDatos){
                    sem_wait( sem_p4_z1 );
                    Memoria[3] = -num;
                    printf(">>limite<<\n");
                    i++;
                    sem_post( sem_c4_z1 );
                }else{
                    sem_wait( sem_p4_z1 );
                    Memoria[3] = num;
                    //printf("Prod %d: zc=4  Bc=1: %d\n",num,i);
                    i++;
                    sem_post( sem_c4_z1 );
                }
            }else if(value5_z1 == 1 &&  i <= stopDatos){
                if(i>=stopDatos){
                    sem_wait( sem_p5_z1 );
                    Memoria[4] = -num;
                    printf(">>limite<<\n");
                    i++;
                    sem_post( sem_c5_z1 );
                }else{
                    sem_wait( sem_p5_z1 );
                    Memoria[4] = num;
                    //printf("Prod %d: zc=5  Bc=1: %d\n",num,i);
                    i++;
                    sem_post( sem_c5_z1 );
                }
            }
            ///*/*/*/*/*/*/*/
            sem_post( sem_c_b1 );
        }
        if(j <= stopDatos){
            sem_wait(sem_p_b2);
            ////>>> BLOQUE CRITICO 2 <<<////
            sem_getvalue(sem_p1_z2, &value1_z2);
            sem_getvalue(sem_p2_z2, &value2_z2);
            sem_getvalue(sem_p3_z2, &value3_z2);
            sem_getvalue(sem_p4_z2, &value4_z2);
            sem_getvalue(sem_p5_z2, &value5_z2);
            if(value1_z2 == 1 && j <= stopDatos){
                if(j>=stopDatos){
                    sem_wait( sem_p1_z2 );
                    Memoria[5] = -num;
                    printf("\t\t\t>>limite<<\n");
                    j++;
                    sem_post( sem_c1_z2 );
                }else{
                    sem_wait( sem_p1_z2 );
                    Memoria[5] = num;
                    //printf("\t\t\tProd %d: zc=1  Bc=2: %d\n",num,j);
                    j++;
                    sem_post( sem_c1_z2 );
                }
            }else if(value2_z2 == 1 && j <= stopDatos){
                if(j>=stopDatos){
                    sem_wait( sem_p2_z2 );
                    Memoria[6] = -num;
                    printf("\t\t\t>>limite<<\n");
                    j++;
                    sem_post( sem_c2_z2 );
                }else{
                    sem_wait( sem_p2_z2 );
                    Memoria[6] = num;
                    //printf("\t\t\tProd %d: zc=2  Bc=2: %d\n",num,j);
                    j++;
                    sem_post( sem_c2_z2 );
                }
            }else if(value3_z2 == 1 && j <= stopDatos){
                if(j>=stopDatos){
                    sem_wait( sem_p3_z2 );
                    Memoria[7] = -num;
                    //printf("\t\t\t>>limite<<\n");
                    j++;
                    sem_post( sem_c3_z2 );
                }else{
                    sem_wait( sem_p3_z2 );
                    Memoria[7] = num;
                    //printf("\t\t\tProd %d: zc=3  Bc=2: %d\n",num,j);
                    j++;
                    sem_post( sem_c3_z2 );
                }
            }else if(value4_z2 == 1 && j <= stopDatos){
                if(j>=stopDatos){
                    sem_wait( sem_p4_z2 );
                    Memoria[8] = -num;
                    printf("\t\t\t>>limite<<\n");
                    j++;
                    sem_post( sem_c4_z2 );
                }else{
                    sem_wait( sem_p4_z2 );
                    Memoria[8] = num;
                    //printf("\t\t\tProd %d: zc=4  Bc=2: %d\n",num,j);
                    j++;
                    sem_post( sem_c4_z2 );
                }
            }else if(value5_z2 == 1 && j <= stopDatos){
                if(j>=stopDatos){
                    sem_wait( sem_p5_z2 );
                    Memoria[9] = -num;
                    //printf("\t\t\t>>limite<<\n");
                    j++;
                    sem_post( sem_c5_z2 );
                }else{
                    sem_wait( sem_p5_z2 );
                    Memoria[9] = num;
                    //printf("\t\t\tProd %d: zc=5  Bc=2: %d\n",num,j);
                    j++;
                    sem_post( sem_c5_z2 );
                }
            }

            ///*/*/*/*/*/*/*/
            sem_post( sem_c_b2 );
        }
        if(j>stopDatos && i>stopDatos){
            break;
        }
    }
    
    unlinkSemaforos();
    _exit(0);
}
void consume(int id_mem, int id){
    //All
        id_mem = CreaLigaMemoria();
        int value1_z1,value2_z1,value3_z1,value4_z1,value5_z1;
        int value1_z2,value2_z2,value3_z2,value4_z2,value5_z2;
        int tmp1,tmp2;
        tmp1=tmp2=3;
        while(1){
            if(tmp1>0){
                sem_wait(sem_c_b1);
                //Bloque 1
                sem_getvalue(sem_c1_z1, &value1_z1);
                sem_getvalue(sem_c2_z1, &value2_z1);
                sem_getvalue(sem_c3_z1, &value3_z1);
                sem_getvalue(sem_c4_z1, &value4_z1);
                sem_getvalue(sem_c5_z1, &value5_z1);
                //Zona critica
                if(value1_z1 == 1){
                    sem_wait( sem_c1_z1 );
                    tmp1=Memoria[0];
                    if(tmp1>0){
                        printf("Cons %d zc=1 bc=1: %d\n",id,tmp1);
                        meteValorArchivo(tmp1);
                        sem_post( sem_p1_z1 );
                    }else{
                        sem_post( sem_p1_z1 );
                    }
                }else if(value2_z1 == 1 ){
                    sem_wait( sem_c2_z1 );
                    tmp1=Memoria[1];
                    if(tmp1>0){
                        printf("Cons %d zc=2 bc=1: %d\n",id,tmp1);
                        meteValorArchivo(tmp1);
                        sem_post( sem_p2_z1 );
                    }else{
                        sem_post( sem_p2_z1 );
                    }
                    
                }else if(value3_z1 == 1 ){
                    sem_wait( sem_c3_z1 );
                    tmp1=Memoria[2];
                    if(tmp1>0){
                        printf("Cons %d zc=3 bc=1: %d\n",id,tmp1);
                        meteValorArchivo(tmp1);
                        sem_post( sem_p3_z1 );
                    }else{
                        sem_post( sem_p4_z1 );
                    }
                    
                }else if(value4_z1 == 1 ){
                    sem_wait( sem_c4_z1 );
                    tmp1=Memoria[3];
                    if(tmp1>0){
                        printf("Cons %d zc=4 bc=1: %d\n",id,tmp1);
                        meteValorArchivo(tmp1);
                        sem_post( sem_p4_z1 );
                    }else{
                        sem_post( sem_p4_z1 );
                    }
                }else if(value5_z1 == 1 ){
                    sem_wait( sem_c5_z1 );
                    tmp1=Memoria[4];
                    if(tmp1>0){
                        printf("Cons %d zc=5 bc=1: %d\n",id,tmp1);
                        meteValorArchivo(tmp1);
                        sem_post( sem_p5_z1 );
                    }else{
                        sem_post( sem_p5_z1 );
                    }
                }
                sem_post(sem_p_b1);
            }
            if(tmp2>0){
                sem_wait(sem_c_b2);
                //Bloque 2
                sem_getvalue(sem_c1_z2, &value1_z2);
                sem_getvalue(sem_c2_z2, &value2_z2);
                sem_getvalue(sem_c3_z2, &value3_z2);
                sem_getvalue(sem_c4_z2, &value4_z2);
                sem_getvalue(sem_c5_z2, &value5_z2);
                //Zona critica
                if(value1_z2 == 1 ){
                    sem_wait( sem_c1_z2 );
                    tmp2=Memoria[5];
                    if(tmp2>0){
                        printf("\t\t\tCons %d zc=1 bc=2: %d\n",id,tmp2);
                        meteValorArchivo(tmp2);
                        sem_post( sem_p1_z2 );
                    }else{
                        sem_post( sem_p1_z2 );
                    }
                }else if(value2_z2 == 1 ){
                    sem_wait( sem_c2_z2 );
                    tmp2=Memoria[6];
                    if(tmp2<0){
                        printf("\t\t\tCons %d zc=2 bc=2: %d\n",id,tmp2);
                        meteValorArchivo(tmp2);
                        sem_post( sem_p2_z2 );
                    }else{
                        sem_post( sem_p2_z2 );
                    }
                }else if(value3_z2 == 1 ){
                    sem_wait( sem_c3_z2 );
                    tmp2=Memoria[7];
                    if(tmp2>0){
                        printf("\t\t\tCons %d zc=3 bc=2: %d\n",id,tmp2);
                        meteValorArchivo(tmp2);
                        sem_post( sem_p3_z2 );
                    }else{
                        sem_post( sem_p3_z2 );
                    }
                }else if(value4_z2 == 1 ){
                    sem_wait( sem_c4_z2 );
                    tmp2=Memoria[8];
                    if(tmp2>0){
                        printf("\t\t\tCons %d zc=4 bc=2: %d\n",id,tmp2);
                        meteValorArchivo(tmp2);
                        sem_post( sem_p4_z2 );
                    }else{
                        sem_post( sem_p4_z2 );
                    }
                }else if(value5_z2 == 1 ){
                    sem_wait( sem_c5_z2 );
                    tmp2=Memoria[9];
                    if(tmp2>0){
                        printf("\t\t\tCons %d zc=5 bc=2: %d\n",id,tmp2);
                        meteValorArchivo(tmp2);
                        sem_post( sem_p5_z2 );
                    }else{
                        sem_post( sem_p5_z2 );
                    }
                }
                sem_post(sem_p_b2);
            }
            if(tmp1<0 && tmp2<0){
                break;
            }
        }

        unlinkSemaforos();
        if(id!=4){
            _exit(0);
        }
}
void LimpiaArchivos(){
    FILE *f1,*f2,*f3,*f4;
    char *name1="1.txt",*name2="2.txt",*name3="3.txt",*name4="4.txt";
    f1=fopen(name1, "w+");
    f2=fopen(name2, "w+");
    f3=fopen(name3, "w+");
    f4=fopen(name4, "w+");
    fclose(f1);fclose(f2);fclose(f3);fclose(f4);
}

void meteValorArchivo(int i){
    //archivos//
    FILE *f1,*f2,*f3,*f4;
    char *name1="1.txt",*name2="2.txt",*name3="3.txt",*name4="4.txt";
     if(i==1){
        sem_wait(sem_f1);
        f1=fopen(name1,"a+t");
        fseek(f1, 0, SEEK_END); 
        fprintf(f1,"1\n");
        fclose(f1);
        sem_post(sem_f1);
    }else if(i==2){
        sem_wait(sem_f2);
        f2=fopen(name2,"a+t");
        fseek(f2, 0, SEEK_END); 
        fprintf(f2,"2\n");
        fclose(f2);
        sem_post(sem_f2);
    }else if(i==3){
        sem_wait(sem_f3);
        f3=fopen(name3,"a+t");
        fseek(f3, 0, SEEK_END); 
        fprintf(f3,"3\n");
        fclose(f3);
        sem_post(sem_f3);
    }else if(i==4){
        sem_wait(sem_f4);
        f4=fopen(name4,"a+t");
        fseek(f4, 0, SEEK_END); 
        fprintf(f4,"4\n");
        fclose(f4);
        sem_post(sem_f4);
    }
}
void unlinkSemaforos(){
    //semaforos bloques
    sem_unlink( name_b1_c );
    sem_unlink( name_b1_p );
    sem_unlink( name_b2_c );
    sem_unlink( name_b2_p );
    //archivos
    sem_unlink( name_sem_f1 );
    sem_unlink( name_sem_f2 );
    sem_unlink( name_sem_f3 );
    sem_unlink( name_sem_f4 );
    //BLOQUE1//
    sem_unlink( name_sem_c1_z1 );
    sem_unlink( name_sem_c2_z1 );
    sem_unlink( name_sem_c3_z1 );
    sem_unlink( name_sem_c4_z1 );
    sem_unlink( name_sem_c5_z1 );
    sem_unlink( name_sem_p1_z1 );
    sem_unlink( name_sem_p2_z1 );
    sem_unlink( name_sem_p3_z1 );
    sem_unlink( name_sem_p4_z1 );
    sem_unlink( name_sem_p5_z1 );
    //BLOQUE2//
    sem_unlink( name_sem_c1_z2 );
    sem_unlink( name_sem_c2_z2 );
    sem_unlink( name_sem_c3_z2 );
    sem_unlink( name_sem_c4_z2 );
    sem_unlink( name_sem_c5_z2 );
    sem_unlink( name_sem_p1_z2 );
    sem_unlink( name_sem_p2_z2 );
    sem_unlink( name_sem_p3_z2 );
    sem_unlink( name_sem_p4_z2 );
    sem_unlink( name_sem_p5_z2 );
}

void stopProces(int id_mem){
    DestruyeMemoria(id_mem, Memoria);//Desyruye la memoria
    unlinkSemaforos();//UnlinkSemaforos
    //semaforos bloques
    sem_close( sem_c_b1 );
    sem_destroy( sem_c_b1 );
    sem_close( sem_c_b2 );
    sem_destroy( sem_c_b2 );
    sem_close( sem_p_b1 );
    sem_destroy( sem_p_b1 );
    sem_close( sem_p_b2 );
    sem_destroy( sem_p_b2 );
    /*semaforos arhivos*/
    sem_close( sem_f1 );
    sem_destroy( sem_f1 );
    sem_close( sem_f2 );
    sem_destroy( sem_f2 );
    sem_close( sem_f3 );
    sem_destroy( sem_f3 );
    sem_close( sem_f4 );
    sem_destroy( sem_f4 );
    //BLOQUE1
    sem_close( sem_c1_z1 );
    sem_destroy( sem_c1_z1 );
    sem_close( sem_c2_z1 );
    sem_destroy( sem_c2_z1 );
    sem_close( sem_c3_z1 );
    sem_destroy( sem_c3_z1 );
    sem_close( sem_c4_z1 );
    sem_destroy( sem_c4_z1 );
    sem_close( sem_c5_z1 );
    sem_destroy( sem_c5_z1 );
    sem_close( sem_p1_z1 );
    sem_destroy( sem_p1_z1 );
    sem_close( sem_p2_z1 );
    sem_destroy( sem_p2_z1 );
    sem_close( sem_p3_z1 );
    sem_destroy( sem_p3_z1 );
    sem_close( sem_p4_z1 );
    sem_destroy( sem_p4_z1 );
    sem_close( sem_p5_z1 );
    sem_destroy( sem_p5_z1 );
    //BLOQUE2
    sem_close( sem_c1_z2 );
    sem_destroy( sem_c1_z2 );
    sem_close( sem_c2_z2 );
    sem_destroy( sem_c2_z2 );
    sem_close( sem_c3_z2 );
    sem_destroy( sem_c3_z2 );
    sem_close( sem_c4_z2 );
    sem_destroy( sem_c4_z2 );
    sem_close( sem_c5_z2 );
    sem_destroy( sem_c5_z2 );
    sem_close( sem_p1_z2 );
    sem_destroy( sem_p1_z2 );
    sem_close( sem_p2_z2 );
    sem_destroy( sem_p2_z2 );
    sem_close( sem_p3_z2 );
    sem_destroy( sem_p3_z2 );
    sem_close( sem_p4_z2 );
    sem_destroy( sem_p4_z2 );
    sem_close( sem_p5_z2 );
    sem_destroy( sem_p5_z2 );
}






int CreaLigaMemoria( void ){
    int key2,shmid;
    key2 = ftok("/bin/ls",3);
    //Verifica si existe la zona de memoria
    if( ( shmid = shmget( key2 , sizeof( int ) * TAM_MEM , IPC_CREAT|IPC_EXCL|0666) ) == -1 ){
        // Si existe obtiene la memoria 
        if( ( shmid = shmget( key2 , sizeof( int ) * TAM_MEM , 0 ) ) == -1 ){
            perror("shmget \n");
            exit(1);
        }
        else
            printf("Se ligo a la memoria con id: %d\n",shmid);
    }else
        printf("Creo la memoria con id: %d\n",shmid);
    //Se liga a la zona de memoria compartida
    if( ( Memoria = (int*)shmat( shmid , (int*) 0 , 0 ) ) == (void*)-1 ){
        perror("shmat \n");
        exit(1);
    }
    return shmid; //Descriptos de la memoria
}


void DestruyeMemoria( int id_Memoria , int *buffer ){
    if( id_Memoria != 0 || id_Memoria != -1 ){ //Valida si ya se destruyo
        shmdt( buffer );                       //Quita la liga hacia la memoria
        shmctl( id_Memoria , IPC_RMID , (struct shmid_ds *) NULL ); //Destruye la zona de memoria
        printf("Se destruyo la memoria\n");
    }else{
        shmdt( buffer );
        printf("Se desligo la memoria\n");
    }
}

sem_t * CrearSemaforo( char *name , int val){
    sem_t *mut;
    if( ( mut = sem_open( name , O_CREAT | O_EXCL , 0666 , val ) ) == SEM_FAILED ){
        if( ( mut = sem_open( name , 0 ) ) == SEM_FAILED )
            printf("Error al abrir el semaforo\n");
        else
            printf("Ligado al semaforo correctamente %p\n", mut);
    }else{
        printf("Semaforo creado: %p\n",mut);
        sem_init( mut , 1 , val );
    }
    return mut;
}
