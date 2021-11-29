#include <stdio.h>
#include <omp.h>
#define SIZE 10
#define CHUNK 2


int main () {
  int tid;
  int A[SIZE][SIZE], B[SIZE][SIZE], C[SIZE][SIZE];
  int sum;
  sum = 0;

printf("***********************\n");
  int l = 1;
  for (size_t i = 0; i < SIZE; i++) {
    for (size_t j = 0; j < SIZE; j++) {
        A[i][j] = 1;
        B[i][j] = 1;
        l += 1;

      }
    }

   printf(" >>>>>>>>>>>>>> A <<<<<<<<<<<<<<<\n");
  for (size_t i = 0; i < SIZE; i++) {
  	printf("\t");
    for (size_t j = 0; j < SIZE; j++) {
        printf(" %d ", A[i][j]);
      }
      printf("\n");
    }
    printf("===================================\n");


    printf(" >>>>>>>>>>>>>> B <<<<<<<<<<<<<<<\n");
  for (size_t i = 0; i < SIZE; i++) {
  	printf("\t");
    for (size_t j = 0; j < SIZE; j++) {
        printf(" %d ", B[i][j]);
      }
      printf("\n");
    }
    printf("===================================\n");


  #pragma omp parallel num_threads(4) 
  {
  	#pragma omp for schedule(dynamic, CHUNK) reduction(+:sum)
    for (size_t i = 0; i < SIZE; i++) {
      	for (size_t j = 0; j < SIZE; j++) {
        	
           	for (size_t k = 0; k < SIZE; k++)
           		sum += A[i][k] * B[k][j];

          	C[i][j] = sum;
          	sum = 0;
          	//printf("%d \n", C[i][j]);
        }
      }

    }


  printf(" >>>>>>>>>>>>>> C <<<<<<<<<<<<<<<\n");
  for (size_t i = 0; i < SIZE; i++) {
  	printf("\t");
    for (size_t j = 0; j < SIZE; j++) {
        printf(" %d ", C[i][j]);
      }
      printf("\n");
    }
    printf("===================================\n");



return 0;
}
