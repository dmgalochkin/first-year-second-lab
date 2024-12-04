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

void Pause()
{
  system("pause");
}

void ReadString(char** s)
{
  int i;
  int len;
  char buf[256];
  scanf("%s", buf);

  len = strlen(buf);

  (*s) = (char*) calloc(len + 1, sizeof(char));

  for (i = 0; i < len; ++i)
  {
    (*s)[i] = buf[i];
  }
  (*s)[len] = 0;
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

  int i;
  int n = 0;
  int* vector = 0;
  int t;
  int v;
  int k;
  clock_t start;
  clock_t end;

  while (1)
  {
    ClearScreen();

    printf("1 - Create vector randomly\n");
    printf("2 - Create vector from keyboard\n");
    printf("3 - Create vector from file\n");
    printf("4 - Write vector to file\n");
    printf("5 - Sort vector\n");
    printf("6 - Get norm of vector\n");
    printf("7 - Normalize vector\n");
    printf("8 - Free vector\n");
    printf("9 - Print vector\n");
    printf("10 - Exit\n");

    scanf("%d", &t);

    if (t == 1)
    {
      ClearScreen();
      printf("Enter value n:\n");
      scanf("%d", &n);
      CreateVector(n, &vector);
      int min, max;
      printf("Enter value min:\n");
      scanf("%d", &min);
      printf("Enter value max:\n");
      scanf("%d", &max);
      FillVectorRandom(n, vector, min, max);
    }
    else if (t == 2)
    {
      ClearScreen();
      printf("Enter value n:\n");
      scanf("%d", &n);
      CreateVector(n, &vector);
      FillVectorKeyboard(n, vector);
    }
    else if (t == 3)
    {
      ClearScreen();
      char* fName;
      printf("Enter filename:\n");
      ReadString(&fName);
      CreateVectorFromFile(&n, &vector, fName);
    }
    else if (t == 4)
    {
      ClearScreen();
      char* fName;
      printf("Enter filename:\n");
      ReadString(&fName);
      WriteVectorToFile(n, vector, fName);
    }
    else if (t == 5)
    {
      ClearScreen();
      printf("1 - Bubble sort\n");
      printf("2 - Selection sort\n");
      printf("3 - Insertion sort\n");
      printf("4 - Merge sort\n");
      printf("5 - Quick sort\n");
      printf("6 - Shell sort\n");
      printf("7 - Count sort\n");
      scanf("%d", &v);
      start = clock();
      if (v == 1)
        BubbleSort(n, vector);
      else if (v == 2)
        SelectionSort(n, vector);
      else if (v == 3)
        InsertionSort(n, vector);
      else if (v == 4)
        MergeSort(n, vector);
      else if (v == 5)
        QuickSort(n, vector);
      else if (v == 6)
        SelectionSort(n, vector);
      else if (v == 7)
        SelectionSort(n, vector);
      end = clock();
      printf("Execution time %.9lfs\n", (double) (end - start) / CLOCKS_PER_SEC);
      Pause();
    }
    else if (t == 6)
    {
      ClearScreen();
      printf("1 - First norm\n");
      printf("2 - Second norm\n");
      printf("3 - N-th norm\n");
      printf("4 - Infinity norm\n");
      printf("5 - K-th norm\n");

      scanf("%d", &v);

      if (v == 1)
        printf("%d\n", FirstNorm(n, vector));
      else if (v == 2)
        printf("%lf\n", NthNorm(n, vector, 2));
      else if (v == 3)
        printf("%lf\n", NthNorm(n, vector, n));
      else if (v == 4)
        printf("%d\n", InfNorm(n, vector));
      else if (v == 5)
      {
        scanf("%d", &k);
        printf("%lf\n", NthNorm(n, vector, k));
      }
      Pause();
    }
    else if (t == 7)
    {
      ClearScreen();
      double* normalizedVector;
      Normalize(n, vector, &normalizedVector);
      printf("Values of normalized vector:\n");
      for (i = 0; i < n; ++i)
      {
        printf("%lf ", normalizedVector[i]);
      }
      printf("\n");
      free(normalizedVector);
      Pause();
    }
    else if (t == 8)
    {
      FreeVector(&n, vector);
    }
    else if (t == 9)
    {
      ClearScreen();
      PrintVector(n, vector);
      Pause();
    }
    else if (t == 10)
    {
      break;
    }
  }

  return 0;
}