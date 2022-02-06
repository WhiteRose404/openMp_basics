#include <stdio.h>
#include <omp.h>
/*
	calculting the value of PI using the following appr intergal(4/(1+x^2)) = PI
				using of cours openmp
*/


int main(){
	int num_steps = 10000;
	double step = 1.0 /( (double) num_steps),sum = 0;
	#pragma omp parallel num_threads(5)
	{
		int id = omp_get_thread_num();
		int size = omp_get_num_threads();
		double psum=0;
		for(int i=id;i<num_steps;i+=size){
			double x = (0.5+i)*step;
			double f = 4.0 /( (double) 1+x*x);
			psum+=f;
		}
		printf("thread %d: has %lf\n",id,psum*step);
		sum+=psum;
	}
	sum = sum*step;
	printf("PI=%lf\n",sum);
	return 0;
}
