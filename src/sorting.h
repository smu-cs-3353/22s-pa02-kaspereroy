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

    void timSortString();

    void  instString(int left, int right);
    void randQuickSortCallString();
    void randQuickSortString(vector<string>&, int, int);
    int partitionString(vector<string>&, int, int);
    int randomPartitionString(vector<string>&, int, int );

    void insertionInt();

    void mergeInt();
    void MergeSortVInt( int s, int e);
    void MergeSortVString( int s, int e);
    void shellSortInt();

    void timSortInt();

    void instInt(int left, int right);
    void randQuickSortCallInt();
    void randQuickSortInt(vector<int>&, int, int);
    int partitionInt(vector<int>&, int, int);
    int randomPartitionInt(vector<int>&, int, int );

};


#endif //INC_22S_PA02_KASPEREROY_SORTING_H