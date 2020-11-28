/*El programa se utiliza para administrar la información de una ferretería. 
Cada producto cuenta con un nombre, un precio y un vector de 12 enteros 
en donde se encuentra la cantidad vendida de ese producto en cada mes 
del año (siendo 0 enero y 11 diciembre).
PUNTO 1: Mostrar las ventas que tuvo un producto en todo el año, dado su nombre.
PUNTO 2: Mostrar todos los productos en orden decreciente de precio.
PUNTO 3: Mostrar todos los productos en orden alfabético.
PUNTO 4: Calcular y retornar el dinero total vendido en el año.
PUNTO 5: Mostrar el nombre del producto más vendido (en cantidad) en el año
*/

#include <stdio.h>
#include <string.h>
struct producto { char nombre[40]; float precio; int ventas_mes[12]; };
#define CANT_PRODUCTOS 4

void inicializar (struct producto[], int);
void mostrar_ventas_anio(struct producto[], int, char[]);
void mostrar_precio (struct producto[], int);
void mostrar_alfabetico(struct producto[], int);
float calcular_ventas_totales(struct producto[], int);
void mostrar_mas_vendido(struct producto[], int);

int main() 
{
	struct producto ventas[CANT_PRODUCTOS];
	float aux = 0.0;
	/* Inicializar el vector de ventas_mes con ceros, para todos los productos */
	inicializar(ventas, CANT_PRODUCTOS); 
	/* ahora cargo algunos productos para poder trabajar, no modificar esto */
	strcpy(ventas[0].nombre, "Arandela");
	ventas[0].precio = 1.5;
	ventas[0].ventas_mes[0] = 300; /* cantidad de arandelas vendidas en enero */
	ventas[0].ventas_mes[5] = 100; /* cantidad de arandelas vendidas en junio */
	ventas[0].ventas_mes[11] = 50; /* cantidad de arandelas vendidas en diciembre */
	strcpy(ventas[1].nombre, "Tuerca");
	ventas[1].precio = 2.2;
	ventas[1].ventas_mes[0] = 200; ventas[1].ventas_mes[5] = 100; ventas[1].ventas_mes[11] = 50;
	strcpy(ventas[2].nombre, "Tornillo");
	ventas[2].precio = 3.5;
	ventas[2].ventas_mes[0] = 400; ventas[2].ventas_mes[5] = 200; ventas[2].ventas_mes[11] = 150;
	strcpy(ventas[3].nombre, "Tarugo");
	ventas[3].precio = 5.2;
	ventas[3].ventas_mes[0] = 500; ventas[3].ventas_mes[5] = 300; ventas[3].ventas_mes[11] = 250;
	/* PUNTO 1: Mostrar las ventas que tuvo un producto en todo el a�o, dado su nombre */
	/* Resultado esperado: Tornillo 750 unidades */
	mostrar_ventas_anio(ventas, CANT_PRODUCTOS, "Tornillo"); 
	/* PUNTO 2: Mostrar todos los productos en orden decreciente de precio (m�s caros primero). */
	/* Resultado esperado: Tarugo Tornillo Tuerca Arandela */
	mostrar_precio(ventas, CANT_PRODUCTOS);
	/* PUNTO 3: Mostrar todos los productos en orden alfab�tico. */
	/* Resultado esperado: Arandela Tarugo Tornillo Tuerca */
	mostrar_alfabetico(ventas, CANT_PRODUCTOS); 
	/* PUNTO 4: Calcular y retornar el dinero total vendido en el a�o */
	/* Resultado esperado: $ 9530.00 */
	aux = calcular_ventas_totales(ventas, CANT_PRODUCTOS);
	printf("$ %.2f", aux); 
	/* PUNTO 5: Mostrar el nombre del producto m�s vendido (en cantidad) en el a�o */
	/* Resultado esperado: Tarugo 1050 unidades */
	mostrar_mas_vendido(ventas, CANT_PRODUCTOS);
}

void inicializar (struct producto ven[], int cant_prod)
{
	int i, j;
	for (i=0; i<cant_prod; i++)
		for (j=0; j<12; j++)
			ven[i].ventas_mes[j] =0;
}

void mostrar_ventas_anio(struct producto ven[], int cant_prod, char nom[])
{
	int i, j, sumador=0;
	for (i=0; i<cant_prod; i++)
		if (stricmp(ven[i].nombre, nom) == 0)
			for (j=0; j<12; j++)
				sumador += ven[i].ventas_mes[j];
	printf("\n\n Las ventas que tuvo Tornillo en todo el a�o fue: %d", sumador);
}

void mostrar_precio (struct producto ven[], int cant_prod)
{
	int i, j;
	struct producto aux;
	for (i=0; i<cant_prod-1; i++)
		for (j=0; j<cant_prod-i-1; j++)
			if (ven[j].precio < ven[j+1].precio)
			{
				aux = ven[j];
				ven[j] = ven[j+1];
				ven[j+1] = aux;
			}
	printf("\n\nPRODUCTO \t PRECIO\n");
	for (i=0; i<cant_prod; i++)
		printf("%s\t%.2f\n", ven[i].nombre, ven[i].precio);
}

void mostrar_alfabetico(struct producto ven[], int cant_prod)
{
	int i, j;
	struct producto aux;
	for (i=0; i<cant_prod-1; i++)
		for (j=0; j<cant_prod-i-1; j++)
			if (strcmpi(ven[j].nombre, ven[j+1].nombre)>0)
			{
				aux = ven[j];
				ven[j] = ven[j+1];
				ven[j+1] = aux;
			}
	printf("\n\nPRODUCTO ORDENADO ALFABETICAMENTE");
	for (i=0; i<cant_prod; i++)
		printf("\n%s", ven[i].nombre);
	printf("\n\n");
}

float calcular_ventas_totales(struct producto ven[], int cant_prod)
{
	int i,j, sum_anual[cant_prod];
	float anual[cant_prod], sumador=0;
	// inicializo sumadores
	for (i=0; i<cant_prod;i++)
	{
		sum_anual[i]=0;
		anual[i]=0;
	}
	// calculo ventas anuales para cada producto
	for (i=0; i<cant_prod; i++)
		for (j=0; j<12; j++)
			sum_anual[i] += ven[i].ventas_mes[j];
	// calculo dinero acumulado anual para cada producto
	for (i=0; i<cant_prod; i++)
		anual[i] = sum_anual[i]*ven[i].precio;
	// sumo el dinero recaudado anualmente de cada producto
	for (i=0; i<cant_prod; i++)
		sumador += anual[i];
	
	return sumador;
}

// Mostrar el nombre del producto m�s vendido (en cantidad) en el a�o 
void mostrar_mas_vendido(struct producto ven[], int cant_prod)
{
	int i,j, sum_anual[cant_prod], ganador=0, posicion;
	// inicializo sumador de productos anualmente
	for (i=0; i<cant_prod;i++)
		sum_anual[i]=0;
	
	// calculo ventas anuales para cada producto
	for (i=0; i<cant_prod; i++)
		for (j=0; j<12; j++)
			sum_anual[i] += ven[i].ventas_mes[j];
	
	for (i=0; i<cant_prod; i++)
		if (sum_anual[i] > ganador)
		{
			ganador = sum_anual[i];
			posicion = i;
		}
		
	printf("\n\nEl producto mas vendido en el anio fue %s con %d unidades vendidas\n", ven[posicion].nombre, ganador);
}
