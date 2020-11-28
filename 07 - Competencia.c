/* En una competencia de paracaidismo de precisión se arrojan competidores a un campo demarcado. La zona de
aterrizaje es la que se muestra a continuación, con sus correspondientes puntajes:
Area 0 (central): 50 puntos
Area 1: 40 puntos
Area 2: 30 puntos
Area 3: 0 puntos
Fuera del área: 0 puntos
1) Realizar la función ZONA que reciba las coordenadas enteras (X, Y), medidas en metros desde el punto
central, de un punto de la zona de aterrizaje y retorne el número del área que corresponde a ese
punto (0 para área central, 1, 2 ó 3).
2) Hacer un programa que permita el ingreso de los datos de varios paracaidistas, de esta forma:
- código de competidor (número entero)
- sus coordenadas de aterrizaje (dos números enteros)
- cantidad de penalizaciones (número entero entre 0 y 2 inclusive).
- el ingreso finaliza con un numero de competidor negativo.
Se debe calcular el puntaje recibido según la zona donde cayó (ver tabla). Además, según la cantidad
de penalizaciones que tuvo se descontará del puntaje final lo siguiente: 0 sin descuento, 1 descuenta
25%, 2 descuenta 50%.
Una vez finalizado el ingreso, el programa debe informar en pantalla el código del competidor ganador
y su puntaje final, siendo el ganador aquel que mayor puntaje final tiene.
Es posible que un competidor se arroje varias veces, pero sus puntajes NO se suman.

*/
#include <stdio.h>
#include <math.h>

int ZONA (int, int);
float PUNTAJE (int, int);

int main()
{
	int codigo, x, y, PENA, AREA, cod_win=0;
	float PUNTOS, puntos_win;
	
	printf("\nIngrese codigo de competidor:"); // primer ingreso
	scanf("%d", &codigo);
	while (codigo > 0)
	{
		printf("\nIngrese coordenadas en X y en Y:"); 
		scanf("%d %d", &x, &y);
		printf("\nIngrese penalizacion entre 0 y 2:");
		scanf("%d", &PENA);
		AREA = ZONA(x, y);
		PUNTOS = PUNTAJE(AREA, PENA);
		printf("\nCODIGO %d \t PUNTOS: %.2f", codigo, PUNTOS);
		if (PUNTOS > puntos_win)
		{
			puntos_win = PUNTOS;
			cod_win = codigo;
		}
		printf("\n\nIngrese codigo de competidor:");
		scanf("%d", &codigo);
	}
	
	printf("El codigo del ganador es: %d y su puntaje es de %.2f", cod_win, puntos_win);
		
	return 0;
}

int ZONA (int X, int Y)
{
	float distancia;
	distancia = sqrt((float) X*X + Y*Y);
	
	if (distancia > 15 )
		return 3;
	if (distancia > 7.5 && distancia <=15)
		return 2;
	if (distancia > 5 && distancia <= 7.5 )
		return 1;
	if (distancia <= 5 )	
		return 0;
}

float PUNTAJE (int area, int pena)
{
	int puntos;
	float puntaje;
	
	if(area == 0)
		puntos = 50;
	if(area == 1)
		puntos = 40;
	if(area == 2)
		puntos = 30;
	if(area == 3)
		puntos = 0;

	if(pena == 0)
		puntaje = (float)puntos;
	if(pena == 1)
		puntaje = puntos - ((puntos*25)/100.00);	
	if(pena == 2)
		puntaje = puntos - ((puntos*50)/100.00);
		
	return puntaje;	
}











