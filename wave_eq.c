#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main(){

	// Initialization of variables
	
	// Space steps are in mm, time steps are in ms.
	
	int length_space = 1; // In meters
	int length_time = 2; // In seconds
	
	int space_steps = 1000*length_space;
	int time_steps = 1000*length_time;
	float c = 0.3;
	float C = c*c; // Here C^2 technically has a dx/dt (literal division, not differential), but as dx = 0,001 m (1 millimiter), and dt = 0.001 s (1 millisecond), it gives C in units of meters per second, exactly as we want.
	
	// printf("C = %f\n\n",C);
	
	// Initial Conditions
	
	float u_space_0[space_steps];
	for (int i = 0; i<=space_steps;i++){
		u_space_0[i] = sin(3.1415926535 * (float)i/(space_steps-1));
	}
	u_space_0[0] = 0;
	u_space_0[space_steps-1] = 0;
	
	float u_space_1[space_steps];
	
	// Finite differentials
	
	// First time iteration
	
	for (int i = 1; i<space_steps;i++){
		u_space_1[i] = u_space_0[i] + (C/2.0)*(u_space_0[i-1]-2*u_space_0[i]+u_space_0[i+1]);
	}
	u_space_1[0] = 0;
	u_space_1[space_steps-1] = 0;

	// Output of first moment of the wave.

	// printf("d%: ",0)
	for (int i = 0; i<space_steps;i++){
		printf("%f,",u_space_0[i]);
	}
	printf("\n");
	
	// Output of the second moment of the wave.

	// printf("d%: ",1)
	for (int i = 0; i<space_steps;i++){
		printf("%f,",u_space_1[i]);
	}
	// printf("\n 1 \n");
	printf("\n");
	
	// Time iterations onwards
	
	float u_space_2[space_steps];
	
	for (int n = 2; n < time_steps; n++){
	// printf("%d\n",n);
		
		u_space_2[0] = 0;
		u_space_2[space_steps-1] = 0;
		
		for (int i = 1; i < space_steps-1;i++){
			u_space_2[i] = -u_space_0[i] + 2.0*u_space_1[i] + (C)*(u_space_1[i-1]+u_space_1[i+1]-2.0*u_space_1[i]);
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

