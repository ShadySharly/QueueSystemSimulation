// ######################################################################################################################################################
// ################################################################ DIRECTIVES ##########################################################################
// ######################################################################################################################################################
#include "mm1.h"

#include <ctype.h>
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// ######################################################################################################################################################
// ################################################################# FUNCTIONS ##########################################################################
// ######################################################################################################################################################

// - INPUTS: - argc: Numero de argumentos introducidos por consola
//           - argv: Arreglo de punteros a caracteres correspondiente a los argumentos ingresados
//           - cValue: Puntero que almacena la cantidad de imagenes a leer
//           - mValue: Puntero que almacena el nombre del archivo que contiene la matriz (mascara) para la convolucion
//           - nValue: Puntero que almacena el umbral de "negrura" para la clasificacion "nearly black"
//           - bValue: Puntero que almacena la opcion de mostrar o no por consola los resultados obtenidos
// - OUTPUTS: -
// - DESCRIPTION: Obtiene los valores ingresados por consola verificando la validez de cada una de las banderas (flags) y los valores
//                por los que estan acompañadas, almacenandolas en las variables de entrada pasadas por referencia. Si no se cumplen algunas de
//                las condiciones necesarias respetando la estructura de entrada y los tipos de datos el programa es abortado y no continua su ejecucion.
void getParams(int argc, char **argv, char *aValue, char *dValue, char *tValue) {
  int c;

  // c: Cantidad de Imagenes (int)
  // m: Archivo con la mascara o kernel (string)
  // n: Umbral de negrura (nearly black) (porcentaje int)
  // b: Bandera (Mostrar resultados por pantalla (1) o no (0)) (binario)
  // Ejecutar como:
  //      ./pipeline -c (cValue) -m (mValue) -n (nValue) -b

  if ((aValue != NULL) && (dValue != NULL) && (tValue != NULL)) {
    while ((c = getopt(argc, argv, "a:d:t:")) != -1) {
      switch (c) {
        case 'a':
          strcpy(aValue, optarg);
          // Tasa de arribos
          if (!isInteger(aValue) || (strcmp(aValue, "0") == 0)) {
            printf("%s\n", "-------------------------------------------------------------------------");
            printf(" => El argumento de -%c debe ser un ENTERO POSITIVO MAYOR A 0.\n", c);
            printf(" => Programa abortado\n");
            printf("%s\n", "-------------------------------------------------------------------------");
            exit(EXIT_FAILURE);
          }

          printf(" => Tasa de arribos (-a): %d\n", atoi(aValue));
          break;

        case 'd':
          strcpy(dValue, optarg);
          // Tasa de despachos
          if (!isInteger(dValue) || (strcmp(dValue, "0") == 0)) {
            printf("%s\n", "-------------------------------------------------------------------------");
            printf(" => El argumento de -%c debe ser un ENTERO POSITIVO MAYOR A 0.\n", c);
            printf(" => Programa abortado\n");
            printf("%s\n", "-------------------------------------------------------------------------");
            exit(EXIT_FAILURE);
          }

          printf(" => Tasa de despachos (-d): %d\n", atoi(dValue));
          break;

        case 't':
          strcpy(tValue, optarg);
          // Tiempo de salida
          if (!isInteger(tValue) || (strcmp(tValue, "0") == 0)) {
            printf("%s\n", "-------------------------------------------------------------------------");
            printf(" => El argumento de -%c debe ser un ENTERO POSITIVO MAYOR A 0.\n", c);
            printf(" => Programa abortado\n");
            printf("%s\n", "-------------------------------------------------------------------------");
            exit(EXIT_FAILURE);
          }

          printf(" => Tiempo de salida (-t): %d\n", atoi(tValue));
          break;

        case '?':
          // Verificacion de existencia de argumentos
          if ((optopt == 'a') || (optopt == 'd') || (optopt == 't')) {
            printf("%s\n", "-------------------------------------------------------------------------");
            printf(" => La opcion -%c requiere un argumento.\n", optopt);
            printf(" => Programa abortado\n");
            printf("%s\n", "-------------------------------------------------------------------------");
            exit(EXIT_FAILURE);
          }
          // VErificacion de la validez de las banderas
          else if (isprint(optopt)) {
            printf("%s\n", "-------------------------------------------------------------------------");
            printf(" => Opcion -%c desconocida.\n", optopt);
            printf(" => Programa abortado\n");
            printf("%s\n", "-------------------------------------------------------------------------");
            exit(EXIT_FAILURE);
          }

        default:
          break;
      }
    }
  }

  else {
    printf("ERROR AL ALOJAR MEMORIA PARA LOS PARAMETROS DE ENTRADA\n");
    printf(" => Programa abortado\n");
    exit(EXIT_FAILURE);
  }
}

// ######################################################################################################################################################
// - INPUTS: - input: Cadena de caracteres a evaluar si corresponde a un numero entero positivo o no
// - OUTPUTS: Valor booleano 1 si es entero positivo, 0 en caso contrario
// - DESCRIPTION: Verifica si una cadena de caracteres de entrada posee en cada una de sus posiciones un caracter que es
//                digito y es positivo

int isInteger(char *input) {
  int c;

  for (c = 0; c < strlen(input); c++) {
    if (!isdigit(input[c]))
      return 0;
  }

  return 1;
}
// ######################################################################################################################################################
// - INPUTS: - input: Cadena de caracteres a evaluar si corresponde a un numero entero positivo o no
// - OUTPUTS: Valor booleano 1 si es entero positivo, 0 en caso contrario
// - DESCRIPTION: Verifica si una cadena de caracteres de entrada posee en cada una de sus posiciones un caracter que es
//                digito y es positivo

Data *initData() {
  Data *newData = (Data *)malloc(sizeof(Data));

  if (newData != NULL) {
    newData->numArrivals = 0;
    newData->numDepartures = 0;
    newData->simTime = 0;
    newData->utilization = 0;
    newData->queueMeanLength = 0;
    newData->resMeanTime = 0;
    return newData;
  }

  else {
    printf("%s\n", "-------------------------------------------------------------------------");
    printf(" => Error al alojar memoria para Data");
    printf(" => Programa abortado\n");
    printf("%s\n", "-------------------------------------------------------------------------");
    exit(EXIT_FAILURE);
  }
}
// ######################################################################################################################################################
// - INPUTS: - input: Cadena de caracteres a evaluar si corresponde a un numero entero positivo o no
// - OUTPUTS: Valor booleano 1 si es entero positivo, 0 en caso contrario
// - DESCRIPTION: Verifica si una cadena de caracteres de entrada posee en cada una de sus posiciones un caracter que es
//                digito y es positivo
double *initArrivals(int arrivalRate) {
  double *array = (double *)malloc(sizeof(double));
  return array;
}

// ######################################################################################################################################################
// - INPUTS: - input: Cadena de caracteres a evaluar si corresponde a un numero entero positivo o no
// - OUTPUTS: Valor booleano 1 si es entero positivo, 0 en caso contrario
// - DESCRIPTION: Verifica si una cadena de caracteres de entrada posee en cada una de sus posiciones un caracter que es
//                digito y es positivo

double *initDepartures(int departureRate) {
  double *array = (double *)malloc(sizeof(double));
  return array;
}

// ######################################################################################################################################################
// #################################################################### END #############################################################################
// ######################################################################################################################################################
