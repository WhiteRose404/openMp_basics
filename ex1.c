#include <stdio.h>
#include <omp.h>
/*
	calculting the value of PI using the following appr intergal(4/(1+x^2)) = PI
				using of cours openmp
*/


int main(){
	int num_steps = 100;
	double step = 1.0 /( (double) num_steps),sum = 0;
	for(int i=0;i<num_steps;i++){
		double x = (0.5+i)*step;
		double f = 4.0 /( (double) 1+x*x);
		sum+=f;
	}
	sum = sum*step;
	printf("PI=%lf\n",sum);
	return 0;
}
