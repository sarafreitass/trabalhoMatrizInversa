#include <stdio.h>
#include <math.h>
#define N 10
#define A 10
int main() {

  int matriz_entrada[N][N]; //sempre quadrada
  int coluna;
  int X; //fator de correção
  int i, j; //referentes as posiçoes linha e coluna da matriz
  int positions [A][A]; //vetor para armazenar as posições a sempre percorridas
  int matriz_saida[N][N]; //matriz corrigida
  int l,c; //parametro para trocar as posições da matriz e depois para fazer o calculo do desvio
  int v=0; //receberá o valor momentâneo de positions
  int positions_transposta[A][A];
  int l1,c1; //parametro para a matriz positions transposta
  float soma=0; //soma da região
  float media[N]; //valor da media aritmetica da região
  float soma_desvio=0; //desvio padrão de cada região
  float desvio=0; //desvio padrão de cada região
  scanf ("%d", &coluna);
  scanf ("%d", &X);

  //ENTRADA MATRIZ DE AREAS DESMATADAS
  
  for (i=0; i<coluna; i++){
    for (j=0; j<coluna; j++) {
      scanf ("%d", &matriz_entrada[i][j]);
    }
  }

  //ENTRADA MATRIZ POSIÇÕES A SEREM PERCORRIDAS
  for (l=0; l<coluna; l++){
  for (c=0;c<coluna; c++){
    scanf ("%d", &positions[l][c]);
  }
  }

//CORRIGINDO O PRIMEIRO ERRO - multiplicação escalar

  for (i=0; i<coluna; i++){
    for (j=0; j<coluna; j++) {
      matriz_entrada[i][j] = matriz_entrada[i][j] * X;
      matriz_saida[i][j]=matriz_entrada[i][j];
    } }

//CORRIGINDO O SEGUNDO ERRO  - arrumar posições

//os numeros inseridos pelo usuario são referentes as colunas, as linhas aumentam automaticamente e sequencialmente de acordo com a passagem de numeros
//os numeros só mudam de coluna e nunca mudam de linha
//transpor a matriz positions para poder usar seus valores de forma prática, tornando a ordem das colunas mais claras por já estarem na sequência certa

for (l1=0, c=l1; l1<coluna; l1++, c++) { 
		for(c1=0, l=c1; c1<coluna; c1++, l++) {

    positions_transposta[l1][c1]=positions[l][c]; //o que é linha vira coluna o que é coluna vira linha
    }
}

printf ("Matriz corrigida\n");
  for (l1=0, i=0; i<coluna; l1++, i++) {
  for (c1=0, j=0; j<coluna; c1++, j++){ 

   v=positions_transposta[l1][c1];//o da direita passa o valor para o da esquerda; essa comparação está correta

  matriz_saida[i][j]=matriz_entrada[i][v];
   //a matriz_saida sempre vai ser um valor da linha da matriz de entrada com a coluna alterada de acordo com a posição
      printf ("%d\t", matriz_saida[i][j]);
    }
    printf ("\n");
  }
//SOMA

  printf ("Somas::");
  for (j=0; j<coluna; j++) {
    for (i=0; i<coluna; i++){
      soma=soma + matriz_saida[i][j];
    }
  printf ("%.2f\t", soma);
  soma=0;
  }
  printf("\n");

//MEDIAS

  printf ("Medias::");
  for (j=0; j<coluna; j++) {
    for (i=0; i<coluna; i++){
      soma=soma + matriz_saida[i][j];
    }
  media[j]=soma/i;
  printf ("%.2f\t", media[j]);
  soma=0;
  }
  printf ("\n");
  
//DESVIOS

  printf ("Desvios::");
  for (j=0; j<coluna; j++) {
    for (i=0; i<coluna; i++){
      soma=soma + matriz_saida[i][j];
    }
  media[j]=soma/coluna;
  soma=0; }
  for (c=0; c<coluna; c++,l=0) {
    for (l=0; l<coluna; l++){
  soma_desvio=soma_desvio + pow(matriz_saida[l][c]-media[c],2);
    }
  desvio=sqrt(soma_desvio/coluna);
  printf ("%.2f\t", desvio); 
  soma_desvio=0;
  }
  
  printf ("\n");

return 0;
}
