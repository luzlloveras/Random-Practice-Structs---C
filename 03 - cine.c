/* Un complejo de cine cuenta con 4 salas, de 24 butacas.
Donde cada BUTACA tiene 0 si el asiento esta vacio, y 1 si está ocupado; CODIGO es el
nro de sala y PELI el nombre de la película que se está proyectando (una película
distinta en cada sala).
1) Hacer la función (int) MAS_VISTA (struct SALA VEC[4])
Que recibe un vector de 4 salas y retorna el CODIGO de sala más concurrida en este
momento.
2) Hacer la función (int) BUSCAR_PELI( struct SALA VEC [4], char TITULO [30])
Que recibe un vector de 4 salas y un título, y retorna el CODIGO de la sala en la que se
está proyectando, o bien -1 si no está.
*/
#include <stdio.h>
#include <string.h>
#define N 4

struct SALA { 
	int CODIGO;
	int BUTACA [4][6];
	char PELI [30];
};

void cargar (struct SALA[], int);
int MAS_VISTA (struct SALA[]);
int BUSCAR_PELI(struct SALA[4], char[30]);

int main()
{
	struct SALA vector[N];
	int mas_vista, proyectando;
	char TITULO[30]= "CATS";
	srand(time(0));
	cargar (vector, N);
	mas_vista = MAS_VISTA(vector);
	printf("\n\nLa pelicula mas vista fue en la sala %d", mas_vista);
	proyectando = BUSCAR_PELI(vector, TITULO);
	if (proyectando>0)
		printf("\n\nLa pelicula %s se proyecta en sala %d", TITULO, proyectando);
	else
		printf("\n\nLa pelicula %s no se esta proyectando", TITULO);
	return 0;
}

void cargar (struct SALA vec[], int n)
{
	int i, j, k;
	char pelis[4][30] = {"ROCKY", "CATS", "JUMANJI", "MONSTER INC"};
	for (i=0; i<n; i++)
	{
		vec[i].CODIGO = i+1;
		strcpy(vec[i].PELI, pelis[i]);
		for (j=0; j<4; j++)
			for (k=0; k<6; k++)
				vec[i].BUTACA[j][k] = rand()%2;
	}
	for (i=0; i<n; i++)
	{
		printf("\nSALA: %d		PELICULA: %s\n\n", vec[i].CODIGO, vec[i].PELI);
		for (j=0; j<n; j++)
		{
			for (k=0; k<6; k++)
				printf("%2d", vec[i].BUTACA[j][k]);
			printf("\n");
		}
		printf("\n");
	}
}

int MAS_VISTA (struct SALA vec[4])
{
	int i,j,k, sumador[4]={0,0,0,0}, mayor=0, pos;
	
	for (i=0; i<4; i++)
		for (j=0; j<4; j++)
			for (k=0; k<6; k++)
				sumador[i] += vec[i].BUTACA[j][k];
	
	for (i=0; i<4; i++)
		if (sumador[i]>mayor)
		{
			mayor = sumador[i];
			pos = i;
		}
	return vec[pos].CODIGO;
}

int BUSCAR_PELI(struct SALA vec[4], char titu[30])
{
	int i;
	for (i=0; i<4; i++)
		if (strcmpi(vec[i].PELI, titu)==0)
			return vec[i].CODIGO;
	return -1;
}



