/*La lotería “5UP” saca 5 números de un bolillero con números del 1 al 100. 
Participarán del sorteo 10 personas que, para jugar, elijen 5 números sin repetir.
Las 5 bolillas ganadoras se almacenan en un vector de 5 enteros, 
generados aleatoriamente en el main una única vez.*/

#include <stdio.h>
#include <string.h>
#define N 10


struct apostadores {
	char nombre[20];
	int numeros[5]; //contendra 5 numeros del 1 al 100
};
 
void carga_inicial ( struct apostadores[]);
void imprimir ( struct apostadores[], int[]);
int participante_ganador (struct apostadores[], int[]);

int main()
{
	struct apostadores vector[N];
	int i, ganadoras[5], winner;
	srand(123);
	
	// Las 5 bolillas ganadoras se almacenan en un vector de 5 enteros
	// generados aleatoriamente en el main una �nica vez.
	for(i=0; i<5; i++)
		ganadoras[i] = 1+rand() % 100; 
	
	// carga nombre de los participantes y sus cinco numeros elegidos
	carga_inicial(vector);
	
	// imprime las bolillas ganadoras, los participantes y sus numeros elegidos
	imprimir(vector, ganadoras);
	
	// en caso de no tener ningun jugador con bolillas coincidentes
	// se da por ganador el primer jugador ingresado
	winner = participante_ganador(vector, ganadoras);
	
	// imprime el ganador o el primero cargado
	printf("\n\nLa persona con mas aciertos es: %s", vector[winner].nombre);
	
	return 0;
}

void carga_inicial( struct apostadores vec[])
{
	int i, j;
	
	for (i=0; i<N; i++)
	{
		printf("\nIngrese nombre:");
		fflush(stdin);
		gets(vec[i].nombre);
		printf("\nIngrese 5 bolillas SIN repetir numero:");
		for (j=0; j<5; j++)
		{
			printf("\nIngrese numero %d elegido:", j+1);
			scanf("%d", &vec[i].numeros[j]);
		}
	}
}

void imprimir ( struct apostadores vec[], int gan[])
{
	int i, j;
	
	//imprime bolillas sacadas del bolillero
	printf("\n BOLILLAS GANADORAS\n");
	for (i=0; i<5; i++)
		printf("%4d", gan[i]);
		
	//imprime nombre del participante y bolillas que eligio
	for (i=0; i<N; i++)
	{
		printf("\n\n");
		printf("\n Jugador: %s", vec[i].nombre);
		printf("\n Bolillas elegidas:");
		for (j=0; j<5; j++)
			printf("%3d", vec[i].numeros[j]);
	}	
}

int participante_ganador (struct apostadores vec[], int gan[])
{
	int i, j, k, contador[N], mayor=0, posicion;
	
	// inicializo contador
	for (i=0; i<N; i++)
		contador[i] = 0;	
	
	// pongo un contador para recaudar aciertos de cada jugador
	for (i=0; i<5; i++)
		for (j=0; j<N; j++)
			for (k=0; k<5; k++)
				if (gan[i] == vec[j].numeros[k])
					contador[j]++;
	
	// comparo cantidad de aciertos por jugador para sacar el que tuvo mas
	for	(i=0; i<N; i++)
		if (contador[i]>mayor)
		{
			mayor = contador[i];
			posicion = i;
		}
	return posicion;
}





