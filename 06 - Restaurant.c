/* Construya una función que reciba un vector de platos e imprima en pantalla todas 
las combinaciones posibles. La combinación resulta de mostrar una entrada, con un 
plato y principal y un postre. Además de mostrarse todas las combinaciones, debe 
informarse cuántas calorías totales tiene cada menú armado.
*/
#include <stdio.h>
#include <string.h>
#define N 6

struct plato {
	char nombre[40];
	char es_entrada;
	char es_plato_ppal;
	char es_postre;
	int calorias;
};

void cargar (struct plato[], int);
void combinaciones (struct plato[], int);

int main()
{
	struct plato vector[N];
	cargar(vector, N);
	combinaciones (vector, N);
	return 0;
}

void cargar (struct plato vec[], int n)
{
	int i;
	char nombres[6][40] = {"ENSALADA", "EMPANADA", "MILANESA", "SPAGHETTI", "HELADO", "FLAN"};
	for (i=0; i<n; i++)
		strcpy(vec[i].nombre, nombres[i]);
	
	for (i=0; i<n; i++)
	{
		if (strcmp(vec[i].nombre, "ENSALADA")==0)
		{
			vec[i].es_entrada = 'V';
			vec[i].es_plato_ppal = 'F';
			vec[i].es_postre = 'F';
			vec[i].calorias = 280;
		}
		if (strcmp(vec[i].nombre, "EMPANADA")==0)
		{
			vec[i].es_entrada = 'V';
			vec[i].es_plato_ppal = 'F';
			vec[i].es_postre = 'F';
			vec[i].calorias = 335;
		}
		if (strcmp(vec[i].nombre, "MILANESA")==0)
		{
			vec[i].es_entrada = 'F';
			vec[i].es_plato_ppal = 'V';
			vec[i].es_postre = 'F';
			vec[i].calorias = 265;
		}
		if (strcmp(vec[i].nombre, "SPAGHETTI")==0)
		{
			vec[i].es_entrada = 'F';
			vec[i].es_plato_ppal = 'V';
			vec[i].es_postre = 'F';
			vec[i].calorias = 158;
		}
		if (strcmp(vec[i].nombre, "HELADO")==0)
		{
			vec[i].es_entrada = 'F';
			vec[i].es_plato_ppal = 'F';
			vec[i].es_postre = 'V';
			vec[i].calorias = 207;
		}
		if (strcmp(vec[i].nombre, "FLAN")==0)
		{
			vec[i].es_entrada = 'F';
			vec[i].es_plato_ppal = 'F';
			vec[i].es_postre = 'V';
			vec[i].calorias = 146;
		}
	}
	
	printf("\n\nPLATO \t CALORIAS");
	for (i=0; i<n; i++)
		printf("\n%s \t %d", vec[i].nombre, vec[i].calorias);
}

void combinaciones (struct plato vec[], int n)
{
	int i, j, k;
	
	printf("\n\nENTRADA \t PLATO \t POSTRE ");
	for (i=0; i<2; i++)
		for(j=2; j<4; j++)
			for (k=4; k<6; k++)
				printf("\n\t %s \t %s \t %s \t %d", vec[i].nombre, vec[j].nombre, vec[k].nombre, vec[i].calorias+vec[j].calorias+vec[k].calorias);
	
}



