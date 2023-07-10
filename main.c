#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>

//-------------------------------------------------------

int valorR(char c) {
    switch (c) {
        case 'I' :
            return 1;
        case 'V' :
            return 5;
        case 'X' :
            return 10;
        case 'L' :
            return 50;
        case 'C' :
            return 100;
        case 'D' :
            return 500;
        case 'M' :
            return 1000;
        default :
            return 0;
    }
}

double f_numRomano(char *roman) {
    int decimal = 0;
    int i;

    for (int i = 0; roman[i] != '\0'; ++i) {
        int valor1 = valorR(roman[i]);
        if (roman[i + 1] != '\0') {
            int valor2 = valorR(roman[i + 1]);
            if (valor1 >= valor2) {
                decimal += valor1;
            } else {
                decimal -= valor1;
            }
        } else {
            decimal += valor1;
        }
    }
    return decimal;
}


void menuNumRoman() {
    char numRoman[12];
    int i = 0;
    printf("---Menu Romano---\n"
           "Por favor ingrese un numero romano: ");
    scanf("%s", numRoman);

    while (numRoman[i] != '\0') {
        numRoman[i] = toupper(numRoman[i]);
        i++;
    }

    int decimal = f_numRomano(numRoman);

    printf("El numero romano: %s en decimales es: %d\n", numRoman, decimal);

}

//-------------------------------------------------------

bool validarDate(char *fecha, int dia, int mes) {
    if (strlen(fecha) != 10) {
        return 0;
    }
    for (int i = 0; i < 2; ++i) {
        if (!isdigit(fecha[i])) {
            return 0;
        }
    }
    if (fecha[2] != '/') {
        return 0;
    }
    for (int i = 3; i < 5; ++i) {
        if (!isdigit(fecha[i])) {
            return 0;
        }
    }
    if (fecha[5] != '/') {
        return 0;
    }
    for (int i = 6; i < 10; ++i) {
        if (!isdigit(fecha[i])) {
            return 0;
        }
    }
    if (dia > 31 || dia < 01) {
        return 0;
    }
    if (mes > 12 || mes < 01) {
        return 0;
    }
    return 1;
}

void menuFechas() {
    char fecha[11];
    int dia, mes, año;
    const char *nameMes[] = {"", "Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio",
                             "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre"};

    printf("---Menu Fechas---\n"
           "Por favor ingrese una fecha en formato dd/mm/aaaa (Nota: los dias 1 se excriben 01): ");
    scanf("%10s", fecha);

    sscanf(fecha, "%d/%d/%d", &dia, &mes, &año);

    if (validarDate(fecha, dia, mes)) {
        printf("Ingreso una fecha valida\n");
        printf("%d de %s de %d\n", dia, nameMes[mes], año);
    } else {
        printf("El formato de la fecha ingresado es invalido;");
    }
}
//-------------------------------------------------------


void menuMultArrays() {
    int rows1, rows2, columns1, columns2;

    printf("---Menu multiplicar matrices---\n Ingrese las filas de la primera matriz:");
    scanf("%d", &rows1);

    printf("- \nIngrese las columnas de la primera matriz:");
    scanf("%d", &columns1);

    printf("- \nIngrese las filas de la segunda matriz:");
    scanf("%d", &rows2);

    printf("- \nIngrese las columnas de la segunda matriz:");
    scanf("%d", &columns2);

    if (columns1 != rows2) {
        printf("Error: No se pueden multiplicar las matrices con las dimensiones proporcionadas.\n");
    } else{
        int matriz1[rows1][columns1];
        int matriz2[rows2][columns2];
        int resultado[rows1][columns2];

        printf("Ingrese los elementos de la matriz 1:\n");
        for (int i = 0; i < rows1; i++) {
            for (int j = 0; j < columns1; j++) {
                printf("Elemento (%d, %d): ", i + 1, j + 1);
                scanf("%d", &matriz1[i][j]);
            }
        }

        printf("Ingrese los elementos de la matriz 2:\n");
        for (int i = 0; i < rows2; i++) {
            for (int j = 0; j < columns2; j++) {
                printf("Elemento (%d, %d): ", i + 1, j + 1);
                scanf("%d", &matriz2[i][j]);
            }
        }

        for (int i = 0; i < rows1; i++) {
            for (int j = 0; j < columns2; j++) {
                resultado[i][j] = 0;
                for (int k = 0; k < columns1; k++) {
                    resultado[i][j] += matriz1[i][k] * matriz2[k][j];
                }
            }
        }

        printf("El resultado de la multiplicación de matrices es:\n");
        for (int i = 0; i < rows1; i++) {
            for (int j = 0; j < columns2; j++) {
                printf("[%d]", resultado[i][j]);
            }
            printf("\n");
        }

    }

}

//-----------------------------------------------------------------------

void menuPrincipal() {
    int option = 0;

    while (option != 10) {
        printf("\n-------------------------------Bienvenido al Menu-------------------------------\n"
               "Seleccione una de las siguientes opciones:\n"
               "1.Numero Romano.\n"
               "2.Factores Primos.\n"
               "3.Borrar Espacios.\n"
               "4.Numeros Egolatras.\n"
               "5.Numero Magico.\n"
               "6.Fechas.\n"
               "7.Producto Punto.\n"
               "8.Multiplicacion de Matrices.\n"
               "9.Matriz Magica.\n"
               "10.Salir.\n"
               "-->");
        scanf("%i", &option);
        fflush(stdin);

        switch (option) {
            case 1:
                menuNumRoman();
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                menuFechas();
                break;
            case 7:
                break;
            case 8:
                menuMultArrays();
                break;
            case 9:
                break;
            case 10:
                printf("Gracias por utilizar nuestros servicios :).\n");
                break;
            default:
                printf("Opcion no valida.\n");
        }
    }

}

int main() {
    menuPrincipal();
    return 0;
}
