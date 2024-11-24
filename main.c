#include <stdio.h>
#include "funciones.h"
 
int main() {
    // Arreglos para almacenar los datos de los productos
    char nombres[5][50];
    int cantidades[5];    
    int tiempos[5];      
    int recursos[5];      
 
    int tiempoDisponible, recursosDisponibles;
    int opcion;                                       
 
    do {
        // Menú principal
        printf("\n--- Menu de opciones ---\n");
        printf("1. Ingresar datos\n");
        printf("2. Mostrar resumen de produccion\n");
        printf("3. Editar producto\n");
        printf("4. Eliminar producto\n");
        printf("5. Verificar factibilidad por producto\n");
        printf("6. Salir\n");
        printf("Opcion: ");
        scanf("%d", &opcion);
 
        switch (opcion) {
            case 1:
                // Ingresar datos de los productos
                ingresarDatos(nombres, cantidades, tiempos, recursos);
                break;
 
            case 2:
                // Mostrar el resumen de producción
                mostrarResumen(nombres, cantidades, tiempos, recursos);
                break;
 
            case 3:
                // Editar un producto específico
                editarProducto(nombres, cantidades, tiempos, recursos);
                break;
 
            case 4:
                // Eliminar un producto específico
                eliminarProducto(nombres, cantidades, tiempos, recursos);
                break;
 
            case 5:
                // Verificar la factibilidad por producto
                printf("\nTiempo disponible (horas): ");
                scanf("%d", &tiempoDisponible);
                printf("Recursos disponibles: ");
                scanf("%d", &recursosDisponibles);
                verificarFactibilidad(tiempoDisponible, recursosDisponibles, cantidades, tiempos, recursos, nombres);
                break;
 
            case 6:
                // Salir del programa
                printf("Saliendo del programa...\n");
                break;
 
            default:
                // Manejo de opción no válida
                printf("Opcion invalida. Por favor intente nuevamente.\n");
        }
    } while (opcion != 6);
 
    return 0;
}