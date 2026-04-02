#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main(){

	// Initialization of variables
	
	// Space steps are in mm, time steps are in ms.
	
	int length_space = 1;
	int length_time = 2;
	
	int space_steps = 1000*length_space;
	int time_steps = 1000*length_time;
	float c = 0.3;
	float C = c*(1.0/(float)time_steps)/(1.0/(float)space_steps);
	
	// printf("C = %f\n\n",C);
	
	// Initial Conditions
	
	float u_space_0[space_steps];
	for (int i = 0; i<=space_steps;i++){
		u_space_0[i] = sin(3.1415926535 * (float)i/(space_steps-1));
	}
	u_space_0[0] = 0;
	u_space_0[time_steps-1] = 0;
	
	float u_space_1[space_steps];
	
	// Finite differentials
	
	// First time iteration
	
	for (int i = 1; i<space_steps;i++){
		u_space_1[i] = u_space_0[i] + (C*C/2.0)*(u_space_0[i-1]-2*u_space_0[i]+u_space_0[i+1]);
	}
	u_space_1[0] = 0;
	u_space_1[space_steps-1] = 0;
	
	for (int i = 0; i<space_steps;i++){
		printf("%f,",u_space_0[i]);
	}
	// printf("\n 0 \n");
	printf("\n");
	for (int i = 0; i<space_steps;i++){
		printf("%f,",u_space_1[i]);
	}
	// printf("\n 1 \n");
	printf("\n");
	// Time iterations onwards
	
	float u_space_2[space_steps];
	
	for (int n = 2; n < time_steps; n++){
	//printf("%d\n",n);
		for (int i = 1; i < space_steps-1;i++){
			u_space_2[i] = -u_space_0[i] + 2.0*u_space_1[i] + (C*C)*(u_space_1[i-1]+u_space_1[i+1]-2.0*u_space_1[i]);
		}
		u_space_2[0] = 0;
		u_space_2[space_steps-1] = 0;
		
		for (int m = 0; m < space_steps;m++){
			printf("%f,",u_space_2[m]);
			u_space_0[m] = u_space_1[m];
			u_space_1[m] = u_space_2[m];
		}
		printf("\n");
	
	
	}
}	
// Source: https://hplgit.github.io/num-methods-for-PDEs/doc/pub/wave/pdf/wave-4print-A4-2up.pdf

