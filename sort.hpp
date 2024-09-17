#ifndef SORT_H
#define SORT_H

#include <iostream>
#include <vector>
#include <initializer_list>
#include <algorithm>
#include <random>

template<typename T>
class Array
{
public:
    Array(std::vector<T> arr);
    Array(std::initializer_list<T> init);
    void shuffleArray();
    void printArray();
    void BubbleSort();
    void SelectionSort();
    void InsertionSort();
    void MergeSort();
    void QuickSort();
    void CountingSort();
    void RadixSort();
    void BucketSort();
    int upper_bound(int target);
    int lower_bound(int target);
    ~Array();

private:
    void mergesort(std::vector<T>& arr, int start, int end);
    void Merge(std::vector<T>& arr, int start, int mid, int end);
    void quicksort(std::vector<T>& arr, int start, int end);
    int partition(std::vector<T>& arr, int start, int end);
    void counting(std::vector<T>& arr, int exp);
    void insertion(std::vector<T>& arr);
    std::vector<T> m_arr;
};

#include "sort.cpp"
#endif // SORT_H