#include "fwt/noise.h"

double* unirand(double *array, int N)
{
	double *local;
	local = malloc ( N * sizeof (double) );
	long int random;
	double drandom,max;

	srand((unsigned)time(NULL));

	for (int i=0; i<N; i++){
		random = rand();
		drandom = (double)random;
		max = (double) RAND_MAX;
		printf("Number %d, %lu, %u %le\n",i,random,RAND_MAX,drandom/max);
	}

	return local;
}

double* poisson(double *lambda,int LENGTH)
{ //Knuth's algorithm
	double *local;
	local = malloc ( LENGTH * sizeof (double) );
	long int random;
	double drandom,max,u;
	double L,p;
	int k ;
	srand((unsigned)time(NULL));

	for (int i=0; i<LENGTH; i++){
		L = exp(-lambda[i]);
		p = 1;
		k = 0;


		do {
			random = rand();
			drandom = (double)random;
			max = (double) RAND_MAX;
			u = drandom/max;
			p = p*u;
			k++;
		} while ( p >= L);

		local[i] = k - 1 ;
	}
	return local;
}

double* box_muller(double *sigma, int LENGTH)
{
	double *local;
	local = malloc ( LENGTH * sizeof (double) );
	long int random;
	double drandom,max,r1,r2;

	srand((unsigned)time(NULL));

	for (int i=0; i<LENGTH; i++){
		random = rand();
		drandom = (double)random;
		max = (double) RAND_MAX;
		r1 = drandom/max;
		random = rand();
		drandom = (double)random;
		max = (double) RAND_MAX;
		r2 = drandom/max;

		local[i] = sigma[i] * sqrt(-2*log( r1 ) )*cos(2*G_PI*r2 );
	}

	return local;
}
