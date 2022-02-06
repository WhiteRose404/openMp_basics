#include <stdio.h>
#include <assert.h>
#include <omp.h>
/*
	calculting the value of PI using the following appr intergal(4/(1+x^2)) = PI
				using of cours openmp
*/


int main(int argc,char* argv[]){
	int num_steps = 100000000,gsize;
	double step = 1.0 /((double)num_steps),sum = 0, start = omp_get_wtime();
	#pragma omp parallel num_threads(20)
	{
		int id = omp_get_thread_num();
		int size = omp_get_num_threads();
		if(!id)	gsize = size;
		double psum=0;
		for(int i=id;i<num_steps;i+=size){
			double x = (0.5+i)*step;
			double f = 4.0 /( (double) 1+x*x);
			psum+=f;
		}
		#pragma omp atomic
			sum+=psum;
	}
	double time = omp_get_wtime()-start;
	sum = sum*step;
	printf("PI=%.13lf took around %lf using %d threads\n",sum,time,gsize);
	return 0;
}
