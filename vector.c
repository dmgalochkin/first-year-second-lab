#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "vector.h"

void swap(int *i, int *j)
{
  int t = (*i);
  (*i) = (*j);
  (*j) = t;
}

void CreateVector(int n, int** vector)
{
  (*vector) = (int*) malloc(n * sizeof(int));
}

int FillVectorRandom(int n, int** vector, int min, int max)
{
  int i;
  if ((*vector) == 0 || min > max)
    return 1;

  for (i = 0; i < n; ++i)
  {
    (*vector)[i] = min + rand() % (min - max + 1);
  }

  return 0;
}

int FillVectorKeyboard(int n, int** vector)
{
  int i;
  if ((*vector) == 0)
    return 1;

  printf("Enter values of vector: ");
  for (i = 0; i < n; ++i)
  {
    scanf("%d", &((*vector)[i]));
  }
  printf("\n");

  return 0;
}

void PrintVector(int n, int** vector)
{
  int i;
  for (i = 0; i < n; ++i)
  {
    printf("%d ", (*vector)[i]);
  }
  printf("\n");
}

void BubbleSort(int n, int** vector)
{
  int i, j;

  for (i = 0; i < n - 1; ++i)
    for (j = 0; j < n - i - 1; ++j)
      if ((*vector)[j] > (*vector)[j + 1])
        swap(&((*vector)[j]), &((*vector)[j + 1]));
}

void SelectionSort(int n, int** vector)
{
  int i, j, min;
  for (i = 0; i < n - 1; ++i)
  {
    min = i;
    for (j = i + 1; j < n; ++j)
      if ((*vector)[j] < (*vector)[min])
        min = j;
    swap(&((*vector)[i]), &((*vector)[min]));
  }
}

void InsertionSort(int n, int** vector)
{
  int i, j;
  for (i = 0; i < n - 1; ++i)
    for (j = i - 1; j >= 0 && (*vector)[j] > (*vector)[j + 1]; --j)
      swap(&((*vector)[j]), &((*vector)[j + 1]));
}

void Merge(int l, int r, int mid, int n, int** vector, int** auxVector)
{
  int i;
  int p = l;
  int pl = l;
  int pr = mid;
  for (pl, pr; pl < mid || pr < r;) {
    if (pr == r || (*vector)[pl] < (*vector)[pr])
      (*auxVector)[p++] = (*vector)[pl++];
    else
      (*auxVector)[p++] = (*vector)[pr++];
  }

  for (i = l; i < r; ++i)
  {
    (*vector)[i] = (*auxVector)[i];
  }
}

void MergeRecursive(int l, int r, int n, int** vector, int** auxVector)
{
  int mid;
  if (r - l == 1)
    return;

  mid = (l + r) >> 1;
  MergeRecursive(l, mid, n, vector, auxVector);
  MergeRecursive(mid, r, n, vector, auxVector);

  Merge(l, r, mid, n, vector, auxVector);
}

void MergeSort(int n, int** vector)
{
  int* auxVector = (int*) malloc(n * sizeof(int));

  MergeRecursive(0, n, n, vector, &auxVector);

  free(auxVector);
}

int Partition(int l, int r, int n, int** vector)
{
  int mid = (l + r) >> 1;
  int pivot = (*vector)[mid];
  int i = l;
  int j = r;

  while (i <= j) {
    while ((*vector)[i] < pivot)
      ++i;
    while ((*vector)[j] > pivot)
      --j;
    if (i >= j)
      break;
    swap(&((*vector)[i]), &((*vector)[j]));
    ++i;
    --j;
  }
  return j;
}

void Qsort(int n, int** vector, int l, int r)
{
  if (l >= r) return;
  int split = Partition(l, r, n, vector);
  Qsort(n, vector, l, split);
  Qsort(n, vector, split + 1, r);
}

void QuickSort(int n, int** vector)
{
  Qsort(n, vector, 0, n - 1);
}

int FirstNorm(int n, int** vector)
{
  int i;
  int x = 0;
  for (i = 0; i < n; ++i)
    x += abs((*vector)[i]);
  return x;
}

int InfNorm(int n, int** vector)
{
  int i;
  int x = 0;
  for (i = 0; i < n; ++i)
    if (abs((*vector)[i]) > x)
      x = abs((*vector)[i]);
  return x;
}

double NthNorm(int n, int** vector, int k)
{
  int i;
  double x = 0;
  for(i = 0; i < n; ++i)
    x += pow(abs((*vector)[i]), k);
  return pow(x, 1.0 / k);
}

void Normalize(int n, int** vector, double** vectorResult)
{
  int i;
  double len = NthNorm(n, vector, 2);
  for (i = 0; i < n; ++i)
  {
    (*vectorResult)[i] = (*vector)[i] / len;
  }
}