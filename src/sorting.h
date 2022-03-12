#include <algorithm>
#include <string>
#include <vector>
using namespace std;
//
// Created by Hazel Eroy on 3/2/22.
//

#ifndef INC_22S_PA02_KASPEREROY_SORTING_H
#define INC_22S_PA02_KASPEREROY_SORTING_H


class sorting {
private:
    vector <vector<string>> fullDataString;
    vector <vector<int>> fullDataInt;
    vector <string> dataSetString;
    vector <int> dataSetInt;
public:
    void readFile(string fileName);
    void runAlgorithms();

    void insertionString();

    void mergeString();
    void MergeSortedIntervalsString( int s, int m, int e);
    void MergeSortedIntervalsInt( int s, int m, int e);
    void MergeSortV( int s, int e);

    void shellSortString();


    void randQuickSortCallString();
    void randQuickSortString(vector<string>&, int, int);
    int partitionString(vector<string>&, int, int);
    int randomPartitionString(vector<string>&, int, int );

    void insertionInt();

    void mergeInt();
    void MergeSortVInt( int s, int e);
    void MergeSortVString( int s, int e);
    void shellSortInt();

    void randQuickSortCallInt();
    void randQuickSortInt(vector<int>&, int, int);
    int partitionInt(vector<int>&, int, int);
    int randomPartitionInt(vector<int>&, int, int );

    void timSortInt();
    void timSortString();
    void instInt(int left, int right);
    void  instString(int left, int right);

    void swapValue(int* a, int* b);
    void InsertionSort(int arr[], int* begin, int* end);
    int* Partition(int arr[], int low, int high);
    int* MedianOfThree(int* a, int* b, int* c);
    void IntrosortUtil(int arr[], int* begin, int* end,
                       int depthLimit);
    void Introsort(int arr[], int* begin, int* end);
    void printArray(int arr[], int n);

    void heapify(int arr[], int n, int i);
    void heapSort(int arr[], int n);

};


#endif //INC_22S_PA02_KASPEREROY_SORTING_H