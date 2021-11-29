#include<omp.h>
//cc omp_tp1_exo1.c -o omp_tp1_exo1 -fopenmp

#include <stdio.h>

static long num_steps = 1000000;
double pi;

int main()
{
	int num_threads = 4;
	double x, sum = 0;
	int i;
	omp_set_num_threads(num_threads);
	printf("threads number : %d\n", omp_get_num_threads());
	double somme, step = 1/(double)num_steps;

	#pragma omp parallel num_threads(4)
	{
		printf("threads number : %d\n", omp_get_thread_num());
		#pragma omp for reduction(+:sum)
			for(i = 0; i < num_steps; i++)
			{
				x = (i + 0.5) * step;
				sum += 4.0/(1+x*x);
			}

	}
	pi = step * sum;

	printf("\nla valeur est : %f\n", pi);
}
