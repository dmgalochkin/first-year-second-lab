#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"


void ClearScreen()
{
  /*
  int i;
  for (i = 0; i < 50; ++i)
  {
    printf("\n");
  }
   */
  system("cls");
}

void ReadString(char** s)
{
  int i;
  char* temp = (char*) calloc(30, sizeof(char));
  char c = 0;
  int p = 0;
  while (c != '\n')
  {
    scanf("%c", &c);
    temp[p++] = c;
  }

  (*s) = (char*) calloc(p + 1, sizeof(char));

  for (i = 0; i <= p; ++i)
  {
    (*s)[i] = temp[i];
  }
  free(temp);
}

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

  int n = 0;
  int* vector;

  char* f;

  while (1)
  {
    ClearScreen();
    printf("Current vector:\n");
    if (n == 0)
    {
      printf("Empty\n");
    }
    else
    {
      PrintVector(n, vector);
    }

    printf("1 - Create vector randomly\n");
    printf("2 - Create vector from keyboard\n");
    printf("3 - Create vector from file\n");
    printf("4 - Write vector to file\n");
    printf("5 - Sort current vector\n");
    printf("6 - Free current vector\n");
    printf("7 - Exit\n");

    int t;
    scanf("%d", &t);

    if (t == 1)
    {
      ClearScreen();
      printf("n = ");
      scanf("%d", &n);
      CreateVector(n, &vector);
      int min, max;
      printf("min = ");
      scanf("%d", &min);
      printf("max = ");
      scanf("%d", &max);
      FillVectorRandom(n, vector, min, max);
    }
    else if (t == 2)
    {
      scanf("%d", &n);
      CreateVector(n, &vector);
      FillVectorKeyboard(n, vector);
    }
    else if (t == 3)
    {
      char* fName;
      ReadString(&fName);
      CreateVectorFromFile(&n, &vector, fName);
    }
    else if (t == 4)
    {
      char* fName;
      ReadString(&fName);
      WriteVectorToFile(n, vector, fName);
    }
    else if (t == 5)
    {

    }
    else if (t == 6)
    {
      n = 0;
      free(vector);
    }
    else if (t == 7)
    {
      break;
    }
    system("pause");
  }

  return 0;
}
