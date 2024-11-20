//
// Created by Admin on 20.11.2024.
//

#ifndef LAB2_VECTOR_H
#define LAB2_VECTOR_H

void CreateVector(int n, int** vector);

int FillVectorRandom(int n, int** vector, int min, int max);

int FillVectorKeyboard(int n, int** vector);

void PrintVector(int n, int** vector);

void BubbleSort(int n, int** vector);

void SelectionSort(int n, int** vector);

void InsertionSort(int n, int** vector);

void MergeSort(int n, int** vector);

void QuickSort(int n, int** vector);

int FirstNorm(int n, int** vector);

int InfNorm(int n, int** vector);

double NthNorm(int n, int** vector, int k);

void Normalize(int n, int** vector, double** vectorResult);

void CreateVectorFromFile(int* n, int** vector, char* fileName);

void WriteVectorToFile(int n, int** vector, char* fileName);

#endif //LAB2_VECTOR_H