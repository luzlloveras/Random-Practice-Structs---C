/* En una fábrica se somete mensualmente a pruebas de calidad el  lote de piezas fabricadas por las maquinas A y B. 
Cada lote solo tiene 1000 piezas. 

El control de calidad consiste en la revisión ocular de 3 operadores, que asignan cada uno un puntaje de 0 a 100 a cada pieza.
Si las piezas tienen en promedio general menos de 50 puntos son descartadas. 
Si tienen entre 50 y 70 se clasifican de 2ªmano, 
y si tienen entre 70 y 100 son de primera calidad.

1)Permitir el ingreso de los datos del control de calidad del último mes.
2)Ordenar según maquina A o B, y a la vez por promedio general
3)Indicar cuantas piezas son descartadas, cuantas clasifican como 1ª calidad y cuantas como 2ª.
4)Buscar la pieza de mayor promedio general e indicar su código y de que maquina proviene.
NOTA: No se puede modificar la estructura original. Agregar cualquier variable o vector auxiliar que considere necesario.

*/
#include <stdio.h>
#include <string.h>
#define N 30
#define P 3

struct pieza {
	char codigo[30];
	char maquina;
	int puntaje[P];
};

void cargar (struct pieza[], int);
//void ingreso_control (struct pieza[], int);
void ordenar_prom_a_b (struct pieza[], int);
void imprimir (struct pieza[], int);
void calificacion (struct pieza[], int);
void mayor_promedio (struct pieza[], int);

int main()
{
	struct pieza vector[N];
	srand(time(0));
	cargar(vector, N);
//	ingreso_control(vector, N);
	imprimir(vector, N);
//	ordenar_prom_a_b (vector, N);
	calificacion (vector, N);
	mayor_promedio (vector, N);
	return 0;
}

// carga automatica
void cargar (struct pieza vec[], int n)
{
	int i, j;
	char nombres[6][30] = {"TARUGO", "CANIO", "FLEX", "CLAVO", "TARUGO", "TUERCA"};
	char letra[2] = {'A', 'B'};

	for (i=0; i<n; i++)
	{
		strcpy(vec[i].codigo,nombres[rand()%6]);
		vec[i].maquina = letra[rand()%2];
		for (j=0; j<P; j++)
			vec[i].puntaje[j] = rand() % 101;
	}
}
/*	CARGA CON INGRESO POR TECLADO
void ingreso_control (struct pieza vec[], int n)
{
	int i, j;
	for (i=0; i<n; i++)
		for (j=0; j<P; j++)
		{
			printf("\nOperador %d, ingrese puntaje de la pieza:", j+1);
			scanf("%d", &vec[i].puntaje[j]);
		}
}
*/	

void imprimir (struct pieza vec[], int n)
{
	int i, j, contador=0, sumador=0;
	float promedio[n];
	
	// saco promedios
	for (i=0; i<n; i++)
	{
		for(j=0; j<P; j++)
		{
			sumador += vec[i].puntaje[j];
			contador++;
		}
		promedio[i] = (float)sumador/contador;
	}
	
	printf("\n\nCODIGO\tMAQUINA\tPUNT 1\tPUNT 2\tPUNT 3\t PROMEDIO:");
	for (i=0; i<n; i++)
	{
		printf("\n");
		printf("%s", vec[i].codigo);
		printf("	");
		printf("%c", vec[i].maquina);
		printf("	");
		printf("%d", vec[i].puntaje[0]);
		printf("	");
		printf("%d", vec[i].puntaje[1]);
		printf("	");
		printf("%d", vec[i].puntaje[2]);
		printf("	");
		printf("%.2f", promedio[i]);
	}
}

// ordenamiento por burbujeo (por tipo y por promedio)
void ordenar_prom_a_b (struct pieza vec[], int n)
{

	int i, j, contador=0, sumador=0;
	float promedio[n], prom_aux;
	struct pieza aux;
	
	// saco promedios
	for (i=0; i<n; i++)
	{
		for(j=0; j<P; j++)
		{
			sumador += vec[i].puntaje[j];
			contador++;
		}
		promedio[i] = (float)sumador/contador;
	}
	
	// ordeno por promedio y tipo de maquina 'A' o 'B'
	for (i=0; i<n-1; i++)
		for (j=0; j<n-i-1; j++)
			if (vec[j].maquina>vec[j+1].maquina || vec[j].maquina == vec[j+1].maquina && promedio[j]<promedio[j+1])
			{
				prom_aux = promedio[j];
				promedio[j] = promedio[j+1];
				promedio[j+1] = prom_aux;
								
				aux = vec[j];
				vec[j] = vec[j+1];
				vec[j+1] = aux;
			}
}

void calificacion (struct pieza vec[], int n)
{
	int i, j, contador=0, sumador=0, descartadas=0, primer_calidad=0, segunda_mano=0;
	float promedio[n];
	struct pieza aux;
	
	// saco promedios
	for (i=0; i<n; i++)
	{
		for(j=0; j<P; j++)
		{
			sumador += vec[i].puntaje[j];
			contador++;
		}
		promedio[i] = (float)sumador/contador;
	}
	
	for (i=0; i<n; i++)
	{
		if (promedio[i] < 50)
			descartadas++;
		if (promedio[i] > 50 && promedio[i] < 70)
			segunda_mano++;
		if (promedio[i] > 70)
			primer_calidad++;
	}
	
	printf("\n\nSe encontraron %d piezas descartadas", descartadas);
	printf("\nSe encontraron %d piezas de segunda mano", segunda_mano);
	printf("\nSe encontraron %d piezas de primer calidad", primer_calidad);
}

// ordenamiento por busqueda
void mayor_promedio (struct pieza vec[], int n)
{
	int i, j, contador=0, sumador=0, posicion;
	float promedio[n], prom_mayor=0;
	
	// saco promedios
	for (i=0; i<n; i++)
	{
		for(j=0; j<P; j++)
		{
			sumador += vec[i].puntaje[j];
			contador++;
		}
		promedio[i] = (float)sumador/contador;
	}
	
	for (i=0; i<n; i++)
		if (promedio[i] > prom_mayor)
		{
			prom_mayor = promedio[i];
			posicion = i;
		}	
	printf("\n\nEl codigo de la pieza con mayor promedio es %s y proviene de la maquina %c", vec[posicion].codigo, vec[posicion].maquina);
}




