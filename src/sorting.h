//London Kasper, Hazel Eroy 22s-pa02-kaspereroy
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

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

    //insertion
    void insertionInt();
    void insertionString();


    //merge sort
    void mergeString();
    void MergeSortedIntervalsString( int s, int m, int e);
    void MergeSortedIntervalsInt( int s, int m, int e);
    void mergeInt();
    void MergeSortVInt( int s, int e);
    void MergeSortVString( int s, int e);

    //shellSort
    void shellSortString();
    void shellSortInt();

    //randQuickSort
    void randQuickSortCallInt();
    void randQuickSortInt(vector<int>&, int, int);
    int partitionInt(vector<int>&, int, int);
    int randomPartitionInt(vector<int>&, int, int );
    void randQuickSortCallString();
    void randQuickSortString(vector<string>&, int, int);
    int partitionString(vector<string>&, int, int);
    int randomPartitionString(vector<string>&, int, int );

    //Functions required for timSort
    void timSortInt();
    void timSortString();
    void instInt(int left, int right);
    void  instString(int left, int right);


// All of the many functions required for introSort
    void introSortCall();
    void introSortCallStr();
    void introSort(vector<int> &v, int depthMax);
    void introSortStr(vector<string> &v, int depthMax);
    void heapSort(vector<int>&v, int size);
    void heapSortStr(vector<string> &v, int size);
    void heapify(vector<int>& v, int size, int root);
    void heapifyStr(vector<string> &v, int size, int root);
    void InsertionSort(vector<int> &v);         //<<Needed overloaded insertion, partition and quicksort functions for introSort
    void InsertionSortStr(vector<string> &v);
    int partition(vector<int> v, int low, int high);
    int partitionStr(vector<string> v, int low, int high);
    void quickSort(vector<int>&v, int low, int high);
    void quickSortStr(vector<string> &v, int low, int high);
};


#endif //INC_22S_PA02_KASPEREROY_SORTING_H