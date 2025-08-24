#include <stdio.h>

int main()
{
  int array1 [] = {1 , 2 , 3 , 4 , 5};
  int array2 [] = {5 , 4 , 3 , 2 , 1};
  int resultado [5];
  int tamanho = 5;

  int * p1 = array1 ;
  int * p2 = array2 ;
  int * pResultado = resultado ;
  
  for (int i=0; i<tamanho; i++){
      *pResultado= *p1 + *p2;
      *pResultado++;
      *p2++;
      *p1++;
  }
  
  printf("Array resultante: ");
  for (int i=0; i<tamanho; i++){
      printf("[%i] ", resultado [i]);
  }
}
