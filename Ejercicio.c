#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
 
char Texto[100];
 
void IngresarTexto() {
    printf("Ingrese una cadena de Texto: ");
    scanf(" %[^\n]", Texto);
}
 
void ArchivoBin() {
    FILE *miPuntero = fopen("mi_archivo.bin", "wb");
 
    if (miPuntero == NULL) {
        printf("Error al abrir el archivo\n");
        return 1;
    }
 
    fwrite(Texto, sizeof(char), strlen(Texto), miPuntero);
    printf("Texto escrito en el archivo .bin exitosamente\n");
    fclose(miPuntero);
}
 
void ArchivoTxt() {
    FILE *archivo_1 = fopen("archivo.txt", "w");
 
    if (archivo_1 == NULL) {
        printf("Error al abrir el archivo\n");
        return 1;
    }
 
    fprintf(archivo_1, "%s", Texto);
    printf("Texto escrito en el archivo .txt exitosamente\n");
    fclose(archivo_1);
}
 
int main() {
    int opcion;
 
    do {
        printf("\nElija la opcion que guste\n");
        printf("1. Escribir una cadena de Texto\n");
        printf("2. Guardar la cadena de Texto en formato '.bin'\n");
        printf("3. Guardar la cadena de Texto en formato '.txt'\n");
        printf("4. Salir\n");
 
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        getchar(); // Para capturar el salto de línea dejado por scanf
 
        switch (opcion) {
            case 1:
                IngresarTexto();
                break;
            case 2:
                ArchivoBin();
                break;
            case 3:
                ArchivoTxt();
                break;
            case 4:
                printf("Saliendo...\n");
                break;
            default:
                printf("No valido...ERROR...\n");
        }
    } while (opcion != 4);
 
}