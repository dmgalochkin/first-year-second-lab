#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "vector.h"

int main(int agrc, char* argv[])
{

  srand(time(0));

  int* vector;

  int n = 5;
  CreateVector(n, &vector);
  FillVectorRandom(n, &vector, 0, 10);
  PrintVector(n, &vector);
  QuickSort(n, &vector);
  PrintVector(n, &vector);

  return 0;
}
