#include <stdio.h>
#include <string.h>
#include "funciones.h"
 

void ingresarDatos(char nombres[5][50], int cantidades[5], int tiempos[5], int recursos[5]) {
    for (int i = 0; i < 5; i++) {
        printf("\nProducto %d:\n", i + 1);
        printf("Nombre: ");
        getchar(); 
        fgets(nombres[i], 50, stdin);
        nombres[i][strcspn(nombres[i], "\n")] = '\0';
 
        printf("Cantidad demandada: ");
        scanf("%d", &cantidades[i]);
 
        printf("Tiempo de fabricación por unidad (en horas): ");
        scanf("%d", &tiempos[i]);
 
        printf("Recursos necesarios por unidad: ");
        scanf("%d", &recursos[i]);
    }
}


void mostrarResumen(char nombres[5][50], int cantidades[5], int tiempos[5], int recursos[5]) {
    int tiempoTotal = 0, recursosTotales = 0;
    printf("\nResumen de producción:\n");
    for (int i = 0; i < 5; i++) {
        if (cantidades[i] > 0) {
            int tiempoProducto = tiempos[i] * cantidades[i];
            int recursosProducto = recursos[i] * cantidades[i];
            printf("Producto: %s | Tiempo total: %d horas | Recursos totales: %d\n",
                   nombres[i], tiempoProducto, recursosProducto);
            tiempoTotal += tiempoProducto;
            recursosTotales += recursosProducto;
        }
    }
    printf("Tiempo total: %d horas | Recursos totales: %d\n", tiempoTotal, recursosTotales);
}
 

void editarProducto(char nombres[5][50], int cantidades[5], int tiempos[5], int recursos[5]) {
    int posicion;
 
    
    printf("\nNumero del producto a editar (1-5): ");
    scanf("%d", &posicion);
 
    
    if (posicion < 1 || posicion > 5) {
        printf("Posicion invalida. Debe ser un numero entre 1 y 5.\n");
        return;
    }
 
    
    int i = posicion - 1;
 
    
    printf("\nProducto actual: %s\n", nombres[i]);
    

    printf("Nuevo nombre (actual: %s): ", nombres[i]);
    getchar(); 
    fgets(nombres[i], 50, stdin);
    nombres[i][strcspn(nombres[i], "\n")] = '\0'; 

    printf("Nueva cantidad demandada (actual: %d): ", cantidades[i]);
    scanf("%d", &cantidades[i]);
 
    printf("Nuevo tiempo de fabricacion (actual: %d): ", tiempos[i]);
    scanf("%d", &tiempos[i]);
 
    printf("Nuevos recursos necesarios (actual: %d): ", recursos[i]);
    scanf("%d", &recursos[i]);
 
    printf("Producto actualizado.\n");
}
 

void eliminarProducto(char nombres[5][50], int cantidades[5], int tiempos[5], int recursos[5]) {
    int posicion;
 
    
    printf("\nNumero del producto a eliminar (1-5): ");
    scanf("%d", &posicion);
 
    
    if (posicion < 1 || posicion > 5) {
        printf("Posicion invalida. Debe ser un numero entre 1 y 5.\n");
        return;
    }
 
    
    int i = posicion - 1;


    nombres[i][0] = '\0'; 
    cantidades[i] = 0;    
    tiempos[i] = 0;       
    recursos[i] = 0;      
 
    printf("Producto en la posicion %d eliminado.\n", posicion);
}
 

void verificarFactibilidad(int tiempoDisponible, int recursosDisponibles, int cantidades[5], int tiempos[5], int recursos[5], char nombres[5][50]) {
    printf("\nFactibilidad por Producto:\n");
    for (int i = 0; i < 5; i++) {
        if (cantidades[i] > 0) {
            int tiempoRequerido = tiempos[i] * cantidades[i];
            int recursosRequeridos = recursos[i] * cantidades[i];
 
            printf("Producto: %s\n", nombres[i]);
 
            
            if (tiempoRequerido <= tiempoDisponible && recursosRequeridos <= recursosDisponibles) {
                printf("   Cumple con el tiempo y los recursos disponibles.\n");
            } else {
                if (tiempoRequerido > tiempoDisponible) {
                    printf("   No cumple con el tiempo disponible. Se necesitan %d horas mas.\n", tiempoRequerido - tiempoDisponible);
                } else {
                    printf("   Cumple con el tiempo disponible.\n");
                }
 
                if (recursosRequeridos > recursosDisponibles) {
                    printf("   No cumple con los recursos disponibles. Se necesitan %d recursos mas.\n", recursosRequeridos - recursosDisponibles);
                } else {
                    printf("   Cumple con los recursos disponibles.\n");
                }
            }
        } else {
            printf("Producto: %s no tiene demanda.\n", nombres[i]);
        }
    }
}