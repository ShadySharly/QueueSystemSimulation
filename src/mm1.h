// ######################################################################################################################################################
// ################################################################ DIRECTIVES ##########################################################################
// ######################################################################################################################################################
#ifndef _MM1_H_
#define _MM1_H_

#include "structs.h"

// ######################################################################################################################################################
// ################################################################ DEFINITIONS #########################################################################
// ######################################################################################################################################################

void getParams(int argc, char** argv, char* aValue, char* dValue, char* tValue);

int isInteger(char* input);

Data* initData();

double initArrivals(double arrivalRate);

double initDepartures(double departureRate);

int main(int argc, char** argv);

// ######################################################################################################################################################
#endif