#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void print_y(double *y, double n_x, double delta_x);
void initial_condition(double *y, int n_x, double delta_x);
void update_y(double *y_present, double *y_past, double n_x, double c);
void print_y(double *y, double n_x, double delta_x);
void solucion(double *y, int x, int t, int c);

int main(){

	double x_f = 80;
	int n_x = 1000;
	double delta_x = x_f/n_x;

	double delta_t = 0.001;
	int n_t = 700;
	double c = 1.0;
	double r = c* delta_t/delta_x ;

	double *y_past = malloc(n_x*sizeof(double));
	double *y_present = malloc(n_x*sizeof(double));
	

	initial_condition(y_past, n_x, delta_x);
	print_y(y_past, n_x, delta_x);

	copy(y_present, y_past, n_x);
	/*print_u(u_present, n_x, delta_x);*/

int i;
	for(i=0;i<n_t;i++){
		update_y(y_present, y_past, n_x, r);
		solucion(y_present, n_x*i, n_t*i, c)
		copy(y_present, y_past, n_x);
	}
	/*print_u(u_present, n_x, delta_x);*/


return 0;
}

void initial_condition(double *y, int n_x, double delta_x){
	
	int i;
	for(i=0;i<n_x;i++){
		double x = i*delta_x;
		y[i] = exp(100.*pow(x[i],2))
	}

}
void copy(double *y_new, double *y_past, int n_x){
	int i;
	for(i=0;i<n_x;i++){
		y_past[i] = y_new[i];
	}
}
void update_y(double *y_present, double *y_past, double n_x, double c){
	int i;
	for(i=1;i<n_x-1;i++){
		y_present[i] = y_past[i] - r*(y_past[i]-y_past[i-1]);
	}
}

void solucion(double *y, int x, int t, int c){
int i;
	*y = exp(-100*(x + c*t));
}



void print_y(double *y, double n_x, double delta_x){
	for(i=0;i<n_x;i++){
		printf("%f %f\n", i*delta_x ,y[i]);
	}
}
