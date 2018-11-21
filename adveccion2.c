#include <stdlib.h>
#include <math.h>
#include <stdio.h>

void printU(double *u, int N, double dx);
void copy(double *uN, double *uA, int N);

int main()
{
	int N = 1000;
	int nT = 600;
	double c = 0.5;
	double *uActual = malloc(N*sizeof(double));
	double *uNueva = malloc(N*sizeof(double)); 
	double dx = 2.0/1000.0;
	double dt = 0.001;
	double r = dt/dx;
	double C = (r*c)/2.0;
	
	
	/* A cada u de mi arreglo actual, le pongo las condiciones iniciales */
	int i;
	for(i=0;i<N;i++){
		double x = i*dx;
		if(x<1.125 && x>0.875) {
			uActual[i]=2.0;
		}else  {
			uActual[i]=0.0;
			}
	}
printU(uActual, N, dx);/*, se  puso en eje1.x > dotostiempoNT.txt*/
		
	/* ahora aplico la adveccion en ese arreglo y se lo agrego a la uNueva

lo empiezo en 1 y termino en N-1 para dejar los bordes estables.

*/
	
	int k,j;
	for(k=0;k<nT;k++){
		for (j=0;j<N;j++){
			if(j!=N){
			uNueva[j+1] = uActual[j+1]- C*(uActual[j+1] - uActual[j]);
	/* le asigno condiciones de frontera  */
                          }
        /* debo copiar la funcion para que le haga lo mismo a cada una */	 
			}
	    copy(uNueva, uActual, N);
	    
                
	}
//printU(uNueva, N, dx);

return 0;
 		
}

void copy(double *uN, double *uA, int N){
	int i;
	for(i=0;i<N;i++){
		uA[i] = uN[i];
	}
}

void printU(double *u, int N, double dx){
	int i;
	for(i=0;i<N;i++){
		printf("%f\n" ,u[i]);
	}
}
	




