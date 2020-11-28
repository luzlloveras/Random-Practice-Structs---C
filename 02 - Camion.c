/*
a) Realice una función que recibe un vector de camiones y una patente, y muestra
en pantalla la distancia total recorrida. Informe si la patente no existe.

b) Realice una función que recibe el vector de camiones y muestra las patentes
en pantalla, ordenadas por cantidad de viajes realizados de mayor a menor. No se
puede modificar la estructura. Considere crear funciones auxiliares para mejorar
la claridad de su programa.

*/

#include <stdio.h>
#include <string.h>
#define N 4
#define V 100

struct camion {
	char patente[8];
	float viajes[100];
};

void cargar (struct camion[]);
void imprime_distancia (struct camion[], char[]);
void imprime_patentes (struct camion[]);

int main()
{
	struct camion viajes[N];
	char aux[8] = "AXN-808";
	cargar (viajes);
	imprime_distancia (viajes, aux);
	imprime_patentes(viajes);
	return 0;
}

void cargar (struct camion via[])
{
	int i, j;
	srand(time(0));
	char pat[5][8] = {"AXN-808", "LMA-909", "PLO-934", "SOA-123"};
	for (i=0; i<N; i++)
	{
		strcpy(via[i].patente, pat[i]); // cargo las patentes a cada camion
		via[i].viajes[0] = -1; // inicializo los viajes de cada camion en -1
	}
	
	for (i=0; i<N; i++)
		for (j=0; j<V; j++)
			if (rand()%2 == 1)
				via[i].viajes[j] = (float)(5+rand() % 50); // agrego kilometros por viaje
}

void imprime_distancia (struct camion via[], char a[])
{
	int i, j, flag=0;
	float distancia=0;
	
	for (i=0; i<N; i++)
		if (strcmp(via[i].patente, a) == 0)
		{
			for (j=0; j<V; j++)
				distancia += via[i].viajes[j];
			flag = 1;
			printf("\n\nLa patente %s ha sido encontrada", a);	
			printf("\nLa distancia total recorrida es de: %.2f km", distancia);
		}
	if (flag == 0)
		printf("\n\nLa patente %s no ha sido encontrada", a);
}

void imprime_patentes (struct camion via[])
{
	int i, j, contador[N], aux_contador;
	struct camion aux;

	for (i=0; i<N; i++)
		contador[i] = 0;	

	for (i=0; i<N; i++)												
		for (j=0; j<100; j++)
			if (via[i].viajes[j] > 0)
				contador[i]++;

	for (i=0; i<N-1; i++)
		for (j=0; j<N-i-1; j++)
			if (contador[j] < contador[j+1])
			{
				aux_contador = contador[j];
				contador[j] = contador[j+1];
				contador[j+1] = aux_contador;
				
				aux = via[j];
				via[j] = via[j+1];
				via[j+1] = aux;
			}

	printf("\n\nPATENTE \t\t CANTIDAD DE VIAJES REALIZADOS");
	for (i=0; i<N; i++)
		printf("\n %s \t\t %d", via[i].patente, contador[i]);
}

