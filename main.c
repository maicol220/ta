#include <stdio.h>
#include "funciones.h" // Incluimos las funciones

int main()
{
    int tiempo_maximo, recursos_maximos;

    printf("Ingrese el tiempo maximo de produccion disponible en minutos: ");
    scanf("%d", &tiempo_maximo);

    printf("Ingrese la cantidad maxima de recursos disponibles: ");
    scanf("%d", &recursos_maximos);

    iniciar_sistema(tiempo_maximo, recursos_maximos);

}