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
    vector <string> dataSet;
public:
    void readFile(string fileName);

    void insertion();

    void merge();
    void MergeSortedIntervals( int s, int m, int e);
    void MergeSortV( int s, int e);

    void shellSort();

    void timSort();

    void  inst(int left, int right);
    void randQuickSortCall();
    void randQuickSort(vector<string>, int, int);
    int partition(vector<string>, int, int);
    int randomPartition(vector<string> v, int low, int high);

};


#endif //INC_22S_PA02_KASPEREROY_SORTING_H