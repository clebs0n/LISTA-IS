#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

int * votos;
int cont, numArq;
pthread_mutex_t * mutexCdt = NULL; 
pthread_mutex_t fileFlag = PTHREAD_MUTEX_INITIALIZER;

void * funcao(void * args){
  char voto[10];
  int n=0, i=0;

  FILE ** archive = (FILE**) args;
 while(cont < numArq){
    
    pthread_mutex_lock(&fileFlag);
    i=cont;
    cont++;
    pthread_mutex_unlock(&fileFlag);
    n=0;

  while (fscanf(archive[i], "%s", voto) != -1) {
    if(voto[0]!=48){
      pthread_mutex_lock(&mutexCdt[n]);
      votos[n]++;
      pthread_mutex_unlock(&mutexCdt[n]);
      }
      //printf("%s", voto);
      n++;
    }
  }
  pthread_exit(NULL);
  }

void changeName(char * fileName, int n){
  sprintf(fileName, "../candidatos/%d.in.txt", n);
}

int main(){
  int arq, trd, cdt, n=1;
  char file[22];
  scanf("%d %d %d", &arq, &trd, &cdt);
  votos = (int*)malloc(sizeof(int)*cdt);
  mutexCdt= (pthread_mutex_t*)malloc(sizeof(pthread_mutex_t)*cdt);

  
  for(int i=0;i<cdt;i++){
    mutexCdt[i] = PTHREAD_MUTEX_INITIALIZER;
  }
  
  cont = 0;
  numArq = arq;

  FILE *arqvs[arq];
  for(int i=1, count=0;i<=arq;i++, count++){
    changeName(file, i);
    //printf("-%s-\n", file);
    arqvs[count] = fopen(file, "r");
    
    if(arqvs[count]==NULL){
      printf("Erro ao abrir arquivo:(\n");
      exit(1);
    }
  }

  pthread_t thread[trd];
  for(int i=0;i<trd; i++){
    pthread_create(&thread[i], NULL, funcao, &arqvs);
  }

  for(int i = 0; i < trd; i++){
        pthread_join(thread[i], NULL);
  }
  //funcao(&arqvs);
  printf("ba");
 for(int i=0;i<cdt;i++){
    printf("%d", votos[i]);
  }
  
  return 0;
}