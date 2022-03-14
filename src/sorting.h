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

    void swapValueInt(int* a, int* b);
    void InsertionSortInt(int arr[], int* begin, int* end);
    int* PartitionInt(int arr[], int low, int high);
    int* MedianOfThreeInt(int* a, int* b, int* c);
    void IntrosortUtilInt(int arr[], int* begin, int* end,
                       int depthLimit);
    void IntrosortInt(int arr[], int* begin, int* end);
    void printArrayInt(int arr[], int n);

    void heapMakerInt(int n, int i);
    void heapSortInt(int* begin, int*end);

    void swapValueStr(string* a, string* b);
    void InsertionSortStr(string arr[], string* begin, string* end);
    string* PartitionStr(string arr[], int low, int high);
    string* MedianOfThreeStr(string* a, string* b, string* c);
    void IntrosortUtilStr(string arr[], string* begin, string* end, int depthLimit);
    void IntrosortStr(string arr[], string* begin, string* end);
    void printArrayStr(int n);
    void heapMakerStr(string n, int i);
    void heapSortStr(string* begin, string* end);

    void callIntroSortInt();
    void callIntroSortStr();

    int partition(vector<int> v, int low, int high);

    void introSortCall();

    void quickSort(vector<int>&v, int low, int high);

    void heapSort(vector<int>&v, int size);

    void heapify(vector<int>& v, int size, int root);

    void InsertionSort(vector<int> &v);

    void introSort(vector<int> &v, int depthMax);

    void InsertionSortStr(vector<string> &v);

    void heapifyStr(vector<string> &v, int size, int root);

    void introSortCallStr();

    void introSortStr(vector<string> &v, int depthMax);

    int partitionStr(vector<string> v, int low, int high);

    void quickSortStr(vector<string> &v, int low, int high);

    void heapSortStr(vector<string> &v, int size);
};


#endif //INC_22S_PA02_KASPEREROY_SORTING_H