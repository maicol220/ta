#include <stdio.h>
#include <string.h>
#include "funciones.h"

// Implementación de las funciones

void agregar_producto(char nombres[][50], int tiempos[], int recursos[], int demandas[], int *cantidad)
{
    if (*cantidad >= 100)
    {
        printf("No se pueden agregar más productos.\n");
        return;
    }

    printf("Ingrese el nombre del producto: ");
    scanf("%s", nombres[*cantidad]);
    printf("Ingrese el tiempo de fabricación (en minutos): ");
    scanf("%d", &tiempos[*cantidad]);
    printf("Ingrese la cantidad de recursos necesarios: ");
    scanf("%d", &recursos[*cantidad]);
    printf("Ingrese la cantidad demandada: ");
    scanf("%d", &demandas[*cantidad]);
    (*cantidad)++;
    printf("Producto agregado correctamente.\n");
}

void editar_producto(char nombres[][50], int tiempos[], int recursos[], int demandas[], int cantidad)
{
    char nombre[50];
    printf("Ingrese el nombre del producto a editar: ");
    scanf("%s", nombre);

    for (int i = 0; i < cantidad; i++)
    {
        if (strcmp(nombres[i], nombre) == 0)
        {
            printf("Producto encontrado. Ingrese nuevos valores:\n");
            printf("Nuevo tiempo de fabricación: ");
            scanf("%d", &tiempos[i]);
            printf("Nueva cantidad de recursos: ");
            scanf("%d", &recursos[i]);
            printf("Nueva cantidad demandada: ");
            scanf("%d", &demandas[i]);
            printf("Producto actualizado.\n");
            return;
        }
    }
    printf("Producto no encontrado.\n");
}

void eliminar_producto(char nombres[][50], int tiempos[], int recursos[], int demandas[], int *cantidad)
{
    char nombre[50];
    printf("Ingrese el nombre del producto a eliminar: ");
    scanf("%s", nombre);

    for (int i = 0; i < *cantidad; i++)
    {
        if (strcmp(nombres[i], nombre) == 0)
        {
            for (int j = i; j < *cantidad - 1; j++)
            {
                strcpy(nombres[j], nombres[j + 1]);
                tiempos[j] = tiempos[j + 1];
                recursos[j] = recursos[j + 1];
                demandas[j] = demandas[j + 1];
            }
            (*cantidad)--;
            printf("Producto eliminado.\n");
            return;
        }
    }
    printf("Producto no encontrado.\n");
}

void calcular_produccion(char nombres[][50], int tiempos[], int recursos[], int demandas[], int cantidad, int tiempo_maximo, int recursos_maximos)
{
    int tiempo_total = 0;
    int recursos_totales = 0;

    for (int i = 0; i < cantidad; i++)
    {
        tiempo_total += tiempos[i] * demandas[i];
        recursos_totales += recursos[i] * demandas[i];
    }

    printf("\nTiempo total de fabricación requerido: %d minutos\n", tiempo_total);
    printf("Cantidad total de recursos necesarios: %d\n", recursos_totales);

    if (tiempo_total <= tiempo_maximo && recursos_totales <= recursos_maximos)
    {
        printf("La fabricación puede cumplir con la demanda.\n");
    }
    else
    {
        printf("La fabricación no puede cumplir con la demanda.\n");
    }
}

void iniciar_sistema(int tiempo_maximo, int recursos_maximos)
{
    char nombres[100][50];
    int tiempos[100];
    int recursos[100];
    int demandas[100];
    int cantidad = 0;
    int opcion;

    do
    {
        printf("\n--- Menú ---\n");
        printf("1. Agregar producto\n");
        printf("2. Editar producto\n");
        printf("3. Eliminar producto\n");
        printf("4. Calcular producción\n");
        printf("5. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            agregar_producto(nombres, tiempos, recursos, demandas, &cantidad);
            break;
        case 2:
            editar_producto(nombres, tiempos, recursos, demandas, cantidad);
            break;
        case 3:
            eliminar_producto(nombres, tiempos, recursos, demandas, &cantidad);
            break;
        case 4:
            calcular_produccion(nombres, tiempos, recursos, demandas, cantidad, tiempo_maximo, recursos_maximos);
            break;
        case 5:
            printf("Saliendo del programa. Gracias por usar el sistema.\n");
            break;
        default:
            printf("Opción inválida. Intente de nuevo.\n");
        }
    } while (opcion != 5);
}