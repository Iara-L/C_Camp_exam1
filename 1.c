#include <stdio.h>
#include <math.h>
#define PI 3.1415

int cylinder(double r, double h, double* V, double* S);

int main() {
	double r, h;
	double V = 0;
	double S = 0;
	int result;

	scanf("%lf", &r);
	scanf("%lf", &h);

	result = cylinder(r, h, &V, &S);

	if (result == 0) {
		printf("\nV = : %lf", V);
		printf("\nS = : %lf", S);
	}
	else {
		fprintf(stderr, "\nInvalid data");
	}


	return 0;
}

int cylinder(double r, double h, double* V, double* S) {
	if (r < 0 || h < 0) {
		return -1;
	}

	*V = PI * pow(r, 2) * h;
	*S = 2 * PI * r * h + 2 * PI * pow(r, 2);

	return 0;
}