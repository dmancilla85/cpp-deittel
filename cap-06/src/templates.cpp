/* Ejemplo de una plantilla de función. DAM */
#pragma once

template <class T>

T maximo(T vector[], int size)
{
	T max;

	for(int i = 0; i < size; i++)
	{
		if(i == 0 || vector[i] > max )
			max = vector[i];
	}

	return max;
}