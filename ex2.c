#include <stdio.h>
#include <omp.h>
#include <stdlib.h>
#define THREADS 5

/*
	calculting the value of PI using the following appr intergal(4/(1+x^2)) = PI
				using of cours openmp
*/


int main(){
	int num_steps = 10000,tsize;
	double step = 1.0 /( (double) num_steps),PI = 0;
	double* psum = malloc(sizeof(double)*THREADS);
	double start = omp_get_wtime();
	#pragma omp parallel num_threads(THREADS)
	{
		int id = omp_get_thread_num();
		int size = omp_get_num_threads();
		if(id == 0)	tsize=size;
		for(int i=id;i<num_steps;i+=size){
			double x = (0.5+i)*step;
			double f = 4.0 /( (double) 1+x*x);
			psum[id]+=f;
		}
	}
	double time = omp_get_wtime()-start;
	for(int i=0;i<tsize;i++) PI+=psum[i];
	PI*=step;
	printf("PI=%lf took around %lf\n",PI,time);
	return 0;
}

