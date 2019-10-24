#include <stdio.h>

int encriptar(int x[], int n)
{
	int y = 0;
	int clave = 7;
	int aux;

	if(n <= 0)
		return -1;

	for(int i = 0; i < n; i++)
	{
		if( x[i] > 9)
			return -1;

		x[i] += clave;
		x[i] %= 10;
	}

	for(int i = 0; i < (n/2); i++)
	{
		aux = x[i];
		x[(n - 1) - i] = aux; 
	}

	for(int i = 0; i < n; i++)
	{
		y += x[i] * (10 * ((n - 1) - i));
	}

	return y;
}