#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

//-------------------------------------------------------

void menuNumeroMagico();

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

void menuFactoresPrimos() {


    int n, i, count;
    int vecto_lenth=0;
    int numbers[1000];
    int exp[1000];

    printf("Ingrese un numero entero positivo: ");
    scanf("%d", &n);
    printf("Los factores primos de %d son: ", n);
    for (i = 2; i <= n; i++)
    {
        count = 0;
        while (n % i == 0)
        {
            count++;
            n /= i;
        }
        if (count != 0)
        {
            numbers[vecto_lenth]=i;
            exp[vecto_lenth]=count;
            vecto_lenth++;
        }
    }
    printf("\n");

    for (int j = (vecto_lenth-1); j >=0 ; --j) {
        printf("%d^%d ",numbers[j],exp[j]);
    }
}

//-------------------------------------------------------

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

int cantDigits(int num) {
    int count = 0;
    while (num != 0) {
        num /= 10;
        count++;
    }
    return count;
}

int magicNumber(int num, int s) {
    int upward[s];
    int falling[s];
    int dig;

    int i = 0;
    while (num > 0) {
        dig = num % 10;
        upward[i] = dig;
        falling[i] = dig;
        num = num / 10;
        i++;
    }

    int size = sizeof(falling) / sizeof(falling[0]);

    for (int j = 0; j < size; ++j) {
        for (int k = j; k < size - 1; ++k) {
            if (falling[j] < falling[k + 1]) {
                int aux = falling[j];
                falling[j] = falling[k + 1];
                falling[k + 1] = aux;
            }
        }
    }

    for (int j = 0; j < size - 1; ++j) {
        for (int k = j; k < size - 1; ++k) {
            if (upward[j] > upward[k + 1]) {
                int aux = upward[j];
                upward[j] = upward[k + 1];
                upward[k + 1] = aux;
            }
        }
    }

    int numFall = 0;
    for (int j = 0; j < size; ++j) {
        numFall = (numFall * 10) + falling[j];
    }

    int numUp = 0;
    for (int j = 0; j < size; ++j) {
        numUp = (numUp * 10) + upward[j];
    }

    return numFall - numUp;
}
void menuNumeroMagico() {
    int num;

    do {
        printf("Ingrese un numero para comprobar (debe tener mas de un digito): ");
        scanf("%d", &num);
    } while (cantDigits(num) <= 1);

    if (magicNumber(num, cantDigits(num)) == num) {
        printf("El numero, %d es un numero magico!\n", num);
    } else {
        printf("El numero, %d no es un numero magico.\n", num);
    }

}

//-----------------------------------------------------------------------

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

void menuProductoPunto() {

    int n1,n2,i;
    float result = 0.0;
    printf("Ingrese la dimension del primer vector: ");
    scanf("%d", &n1);

    printf("Ingrese la dimension del segundo vector: ");
    scanf("%d", &n2);

    float vec1[n1],vec2[n2];

    printf("Ingrese los elementos del primer vector:\n");
    for (i = 0; i < n1; i++)
    {
        printf("=> ");
        scanf("%f", &vec1[i]);
    }

    printf("Ingrese los elementos del segundo vector:\n");

    for (i = 0; i < n2; i++)
    {
        printf("=> ");
        scanf("%f", &vec2[i]);
    }

    for (i = 0; i < n1; i++)
    {
        result += vec1[i] * vec2[i];
    }

    printf("[");
    for (i = 0; i < n1; ++i) {
        printf("(%f * %f)",vec1[i],vec2[i]);

        if(i<(n1-1)){
            printf(" + ");
        }
    }
    printf("] = %f \n\n",result);

    printf("El producto punto de los vectores es: %f\n", result);

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
                menuFactoresPrimos();
                break;
            case 3:
                menuDeleteSpaces();
                break;
            case 4:
                menuEgolatra();
                break;
            case 5:
                menuNumeroMagico();
                break;
            case 6:
                menuFechas();
                break;
            case 7:
                menuProductoPunto();
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

