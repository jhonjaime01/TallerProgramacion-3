#include <stdio.h>
#include <string.h>
#include <ctype.h>
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

char* borrarEspacios(char* frase) {
    char* src = frase;
    char* dst = frase;

    while (*src) {
        if (!isspace((unsigned char)*src)) {
            *dst++ = *src;
        }
        src++;
    }
    *dst = '\0';

    return frase;
}

void menuDeleteSpaces() {
    char frase[100];
    printf("Digite una cadena para eliminar los espacios:\n");
    printf("Cadena: ");
    fgets(frase, sizeof(frase), stdin);
    frase[strcspn(frase, "\n")] = '\0';  // Eliminar el salto de línea del final

    borrarEspacios(frase);
    printf("Cadena sin espacios adicionales: %s\n", frase);
}
//-----------------------------------------------------------------------
void egolatra(char cadena[]) {
    int numero = atoi(cadena);
    int i = 0, auxNum = 0, potencia = strlen(cadena);
    int *numCadena = (int*)malloc(potencia * sizeof(int));

    for (i = 0; i < potencia; i++) {
        numCadena[i] = cadena[i] - '0';
        auxNum += pow(numCadena[i], potencia);
    }
    if (auxNum == numero) {
        printf("El numero %d SI es egolatra\n", numero);
    } else {
        printf("El numero %d NO es egolatra\n", numero);
    }
}


int validarNumeros(char cadena[]) {
    for (int i = 0; i < strlen(cadena) - 1; i++) {
        if (!isdigit((unsigned char)cadena[i])) {
            return 0;
        }
    }
    return 1;
}

void menuEgolatra() {
    char cadena[30];
    printf("Digite un numero para verificar si es o no egolatra:\n");
    printf("Numero: ");
    fgets(cadena, sizeof(cadena), stdin);
    cadena[strcspn(cadena, "\n")] = '\0';  // Eliminar el salto de línea del final

    if (validarNumeros(cadena) != 0) {
        egolatra(cadena);
    } else {
        printf("Error al digitar el numero\n\n");
    }
}
//-----------------------------------------------------------------------


void imprimirMatriz(int** matriz, int orden) {
    for (int i = 0; i < orden; i++) {
        for (int j = 0; j < orden; j++) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
}

int** generarMatrizMagica(int orden) {
    int** matriz = (int**)malloc(orden * sizeof(int*));
    for (int i = 0; i < orden; i++) {
        matriz[i] = (int*)malloc(orden * sizeof(int));
        for (int j = 0; j < orden; j++) {
            matriz[i][j] = 0;
        }
    }

    int numElementos = orden * orden;
    int fila = 0;
    int col = orden / 2;

    for (int num = 1; num <= numElementos; num++) {
        matriz[fila][col] = num;
        fila--;
        col++;

        if (fila < 0) {
            fila = orden - 1;
        }
        if (col == orden) {
            col = 0;
        }
        if (matriz[fila][col] != 0) {
            fila += 2;
            col--;

            if (fila >= orden) {
                fila -= orden;
            }
            if (col < 0) {
                col = orden - 1;
            }
        }
    }

    return matriz;
}

void menuMatrizMagica() {
    int orden;
    while (1) {
        printf("Digite un numero impar para generar una matriz magica\nNumero: ");
        scanf("%d", &orden);
        if (orden % 2 != 0) {
            int** matrizMagica = generarMatrizMagica(orden);
            printf("Matriz Magica de orden %d:\n", orden);
            imprimirMatriz(matrizMagica, orden);

            for (int i = 0; i < orden; i++) {
                free(matrizMagica[i]);
            }
            free(matrizMagica);

            break;
        } else {
            printf("El numero debe ser impar.\n");
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
                menuDeleteSpaces();
                break;
            case 4:
                menuEgolatra();
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
                menuMatrizMagica();
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

