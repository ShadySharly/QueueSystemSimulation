// ######################################################################################################################################################
// ################################################################ DIRECTIVES ##########################################################################
// ######################################################################################################################################################
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mm1.h"
#include "structs.h"

double * addArray(int len, double * array, double element){
  double* newArray = (double*)malloc(sizeof(double)*len+1);
  int i =0;
  for ( i=0; i < len; i++)
  {
    newArray[i] = array[i];
  }
  newArray[i] = element;
  free(array);
  return newArray;
}

void simulator(double aRate,double dRate,double endTime){
  double timeActual=initArrivals(aRate) ;
  double departureActual= initDepartures(dRate);
  double * arrivalArray = (double*)malloc(sizeof(double));
  int lenArrival= 1;
  double * departureArray = (double*)malloc(sizeof(double));
  int lenDeparture=1;
  arrivalArray[lenArrival-1]=timeActual;
  departureArray[lenDeparture-1]=departureActual;
  double arriveAux;
  double departureAux;
  int posActual=0;
  int maximo=0;
  double timeArrive, timeDeparture;
  while (timeActual < endTime){
    arriveAux= initArrivals(aRate);
    timeArrive= timeActual + arriveAux ;
    arrivalArray=addArray(lenArrival,arrivalArray,timeArrive);
    lenArrival+=1;
    departureAux = initDepartures(dRate);
    timeDeparture = timeActual + departureAux;
    departureArray= addArray(lenDeparture,departureArray,timeDeparture);
    lenDeparture+=1;
    if(maximo<lenArrival+1-posActual){
      maximo = lenArrival+1-posActual;
    }
    if (timeArrive>departureArray[posActual]){
      posActual+=1;
      timeActual=arrivalArray[posActual];
    }

  }
  printf("\n-------------------------RESULTADOS------------------------------------------\n");
  printf("Numero de cliente que llegaron=%i\nNumero de clientes que salieron=%i\nTiempo Total de cola vacia=%f\nLargo maximo de la cola=%i\nTiempo total de cola largo maximo=%f\nUtilizacion=%f\nLargo promedio de la cola=%f,Tiempo promedio de residencia=%f\n",lenArrival,posActual+1,timeActual,maximo,timeActual,timeActual,timeActual,timeActual);
  free(arrivalArray);
  free(departureArray);
  return; 

}


// ######################################################################################################################################################
// ################################################################### MAIN #############################################################################
// ######################################################################################################################################################
// - INPUTS:
// - OUTPUTS:
// - DESCRIPTION:
int main(int argc, char** argv) {
  char* aValue = (char*)malloc(sizeof(char));
  char* dValue = (char*)malloc(sizeof(char));
  char* tValue = (char*)malloc(sizeof(char));
  double aRate, dRate, endTime, newArrival, newDeparture;
  Data* data = initData();

  getParams(argc, argv, aValue, dValue, tValue);

  aRate = atof(aValue);
  dRate = atof(dValue);
  endTime = atof(tValue);

  newArrival = initArrivals(aRate);
  newDeparture = initDepartures(dRate);
  printf("seded");
  simulator(aRate, dRate,endTime);
  
  return 0;
}

// ######################################################################################################################################################
