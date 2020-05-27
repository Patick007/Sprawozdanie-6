#include <math.h>
#include <stdio.h>
#include "winbgi2.h"
#include <stdlib.h>
#include "gauss.h"
void HilbertMatrix(int N, double **H);
void displayMatrix(int N, double **H);
void computeVec(int N, double **H, double *b);
void plotVec(int N, double *b);
void wynik(int N, double *x);
void gauss(int N, double**H, double *x, double *b);

void main()
{
	int N;
	printf("Podaj N:");
	scanf("%d", &N);
	double **H=(double**)malloc(N*sizeof(double*));
	double *b, *x;
	b = (double*)malloc(N*sizeof(double));
	x = (double*)malloc(N*sizeof(double));
	for(int i=0; i<N; i++)
	{
		H[i] = (double*)malloc(N*sizeof(double));
	}
	HilbertMatrix(N,H);
	displayMatrix(N,H);
	computeVec(N,H,b);
	plotVec(N,b);
	gauss(N,H,x,b);
	wynik(N,x);
	wait();
}
void HilbertMatrix(int N, double **H)
{
	for(int i=0 ; i<N; i++)
	{
		for(int j = 0; j<N; j++)
		{
			H[i][j] = 1./(1.+i+j);
		}
	}
}
void displayMatrix(int N, double **H)
{
	for(int i = 0; i<N; i++)
	{
		for(int j = 0; j<N; j++)
		{
			printf("%lf\n", H[i][j]);
		}
	}
}
void computeVec(int N, double **H, double *b)
{
	for(int i = 0; i<N; i++)
	{
		b[i] = 0;
		for(int j = 0; j<N; j++)
		{
			b[i]= b[i] + H[i][j];
		}
	}
}
void plotVec(int N, double *b)
{
	for(int i = 0; i<N; i++)
	{
		printf("%lf\n", b[i]);
	}
}
void wynik(int N, double *x)
{
	for(int i = 0; i<N; i++)
	{
		printf("%lf\n", x[i]);
	}
}
