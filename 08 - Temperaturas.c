/* En una estructura así podríamos tener, por ejemplo, que el 17/11/2020 a las 19hs hicieron 23.2 grados
de temperatura. El campo “hora” puede valer entre 0 y 23.
a) Construya una función que reciba un vector de struct clima y retorne cuál fue el día que tuvo la
temperatura más alta de todas. Se retorna una struct fecha.
El prototipo es: struct fecha temp_mayor (struct clima [], int);
b) Construya una función que reciba un vector de struct clima y retorne cuál es la hora del día que
tiene, en promedio, la temperatura más baja según todos los registros que se le envían a la
función. Deberá calcular el promedio “por hora”, y utilizar algún tipo de almacenamiento
temporal, para luego encontrar el promedio menor.
El prototipo es: int hora_promedio_menor (struct clima[], int);
Retornará un número entre 0 y 23.
c) Hacer un programa principal de ejemplo para verificar el correcto funcionamiento de los puntos
a y b.
*/
#include <stdio.h>
#include <string.h>
#define N 5

struct fecha { int dia; int mes; int anio; };

struct clima {
	struct fecha fecha_registro;
	int hora;
	float temperatura;
};

void cargar (struct clima[], int);
struct fecha temp_mayor (struct clima [], int);
int hora_promedio_menor (struct clima[], int);

int main()
{
	int hora_baja;
	struct clima vector[N];
	struct fecha aux;
	srand(time(0));
	cargar (vector, N);
	aux = temp_mayor (vector, N);
	printf("\nEl dia mas caluroso fue: %d/%d/%d", aux.dia, aux.mes, aux.anio);
	hora_baja = hora_promedio_menor(vector, N);
	printf("\nLa hora mas fria es: %02d\n", hora_baja);
	return 0;
}

void cargar (struct clima vec[], int n)
{ 
	int i;
	for (i=0; i<n; i++)
	{
		vec[i].fecha_registro.dia = 1+rand()%29;
		vec[i].fecha_registro.mes = 1+rand()%13;
		vec[i].fecha_registro.anio = 2000+rand()%20;
		vec[i].hora = rand()%24;
		vec[i].temperatura = (float)(1+rand()%40);
	}
	for (i=0; i<n; i++)
		printf("\n Fecha: %d/%d/%d	Hora: %02d  Temperatura: %.2f\n", vec[i].fecha_registro.dia, vec[i].fecha_registro.mes, vec[i].fecha_registro.anio, vec[i].hora, vec[i].temperatura);
}

struct fecha temp_mayor (struct clima vec[], int n)
{
	int i, pos_t;
	float t_alta = 0;
	for (i=0; i<n; i++)
		if (vec[i].temperatura>t_alta)
		{
			t_alta = vec[i].temperatura;
			pos_t = i;
		}
	return vec[pos_t].fecha_registro;
}


int hora_promedio_menor (struct clima vec[], int n)
{
	int i, j, sum[24], cont[24], pos;
	float prom[24], prom_baja=100;
	
	//inicializo
	for (i=0; i<24; i++)
	{
		sum[i]=0;
		cont[i]=0;
		prom[i]=0;
	}
	// acumulo temperaturas en cada hora de cada fecha
	for (i=0; i<24; i++)
		for (j=0; j<n; j++)
			if (vec[j].hora == i)
			{
				sum[i] += vec[j].temperatura;
				cont[i]++;
			}
	
	// saco promedio
	for (i=0; i<24; i++)
		prom[i] = (float)sum[i]/cont[i];
	
	// saco la hora con la temperatura mas baja en promedio
	for (i=0; i<24; i++)
		if (prom[i]<prom_baja)
		{
			prom_baja = prom[i];
			pos = i;
		}
		
	return pos;
}




