#include<omp.h>
//cc omp_tp1_exo1.c -o omp_tp1_exo1 -fopenmp

#include <stdio.h>

static long num_steps = 1000000;
double pi;

int main()
{
	int a;
	int num_threads = 4;
	omp_set_num_threads(num_threads);
	a = 10;
	printf("Avant la zone parallel, A : %d\n", a);

		#pragma omp parallel for firstprivate(a)
		for (int i = 0; i < 5; i++)
		{
			a = i*50;
			printf("\n");
		}
		
		printf("Dans la zone parallel, A : %d\n", a);
	
	
	printf("Apres la zone parallel, A : %d\n", a);
}
