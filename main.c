#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"

int main(int argc, char* argv[])
{
  if (argc == 4) {
    int n;
    int* vector;
    char* inputName = argv[1];
    char* outputName = argv[2];
    char* sortName = argv[3];

    CreateVectorFromFile(&n, &vector, inputName);

    if (strcmp(sortName, "bubble") == 0)
      BubbleSort(n, vector);
    if (strcmp(sortName, "selection") == 0)
      SelectionSort(n, vector);
    if (strcmp(sortName, "insertion") == 0)
      InsertionSort(n, vector);
    if (strcmp(sortName, "quick") == 0)
      QuickSort(n, vector);
    if (strcmp(sortName, "merge") == 0)
      MergeSort(n, vector);

    WriteVectorToFile(n, vector, outputName);
    return 0;
  }

  int n;
  int* vector;

  while (1)
  {
    printf("Current vector:\n");
    if (vector == 0)
    {
      printf("Empty\n");
    }
    else
    {
      PrintVector(n, vector);
    }

    printf("1 - Create Vector Random\n");
    printf("2 - Create Vector Random\n");
  }

  return 0;
}
