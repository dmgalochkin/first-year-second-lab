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


#endif //LAB2_VECTOR_H
