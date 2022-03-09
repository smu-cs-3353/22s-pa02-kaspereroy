//Research on QuickSort function done on GeeksForGeeks.com
#include <algorithm>
//
// Created by Hazel Eroy on 3/2/22.
//

#include "sorting.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <math.h>
using namespace std;

void sorting::readFileString(string fileName) {
    cout << "reading file" << endl;
    string parameter = "../inputs/" + fileName;
    ifstream file ( parameter);
    if (!file.is_open()){
        cout << "not open" << endl;
    }else{
        string line;
        while (!file.eof()){
            getline(file, line, ',');
            dataSetString.push_back(line);
        }
    }

    cout << "file read" << endl;
};
void sorting::readFileInt(string fileName) {
    cout << "reading file" << endl;
    string parameter = "../inputs/" + fileName;
    ifstream file ( parameter);
    if (!file.is_open()){
        cout << "not open" << endl;
    }else{
        string line;
        while (!file.eof()){
            getline(file, line, ',');
            dataSetInt.push_back(stoi(line));
        }
    }
    cout << "file read" << endl;
};
//FIXME need functionality with strings here

void sorting::insertionString() {  //vector <string> arrstr, int k
    cout << "in insertion" << endl;
    long k = dataSetString.size();
    int i, j;
    string key;
    for (i = 1; i < k; i++)
    {
        key = dataSetString[i];
        j = i - 1;

        while (j >= 0 && dataSetString[j] > key)
        {
            dataSetString[j + 1] = dataSetString[j];
            j = j - 1;
        }
        dataSetString[j + 1] = key;
    }

    int z;
    for (z = 0; z < k; z++)
        cout << dataSetString[z] << " ";
    cout << endl;

    cout << "done insertion String" << endl;
}

void sorting::insertionInt() {  //vector <string> arrstr, int k
    cout << "in insertion" << endl;
    long k = dataSetInt.size();
    int i, j, key;
    for (i = 1; i < k; i++)
    {
        key = dataSetInt[i];
        j = i - 1;

        while (j >= 0 && dataSetInt[j] > key)
        {
            dataSetInt[j + 1] = dataSetInt[j];
            j = j - 1;
        }
        dataSetInt[j + 1] = key;
    }

    int z;
    for (z = 0; z < k; z++)
        cout << dataSetInt[z] << " ";
    cout << endl;

    cout << "done insertion int" << endl;
}

//---------------

void sorting::mergeString(){
    MergeSortV( 0, dataSetString.size()-1);
    for (int i = 0; i < dataSetString.size(); ++i) {
        cout << dataSetString[i] << ' ';
    }
}
void sorting::mergeInt(){
    MergeSortV( 0, dataSetInt.size()-1);
    for (int i = 0; i < dataSetInt.size(); ++i) {
        cout << dataSetInt[i] << ' ';
    }
}

void sorting::MergeSortedIntervals(int s, int m, int e) {

    // temp is used to temporary store the vector obtained by merging
    // elements from [s to m] and [m+1 to e] in v
    vector<string> temp;

    int i, j;
    i = s;
    j = m + 1;

    while (i <= m && j <= e) {

        if (dataSetString[i] <= dataSetString[j]) {
            temp.push_back(dataSetString[i]);
            ++i;
        }
        else {
            temp.push_back(dataSetString[j]);
            ++j;
        }

    }

    while (i <= m) {
        temp.push_back(dataSetString[i]);
        ++i;
    }

    while (j <= e) {
        temp.push_back(dataSetString[j]);
        ++j;
    }

    for (int i = s; i <= e; ++i)
        dataSetString[i] = temp[i - s];


}
void sorting::MergeSortedIntervals(int s, int m, int e) {

    // temp is used to temporary store the vector obtained by merging
    // elements from [s to m] and [m+1 to e] in v
    vector<string> temp;

    int i, j;
    i = s;
    j = m + 1;

    while (i <= m && j <= e) {

        if (dataSetString[i] <= dataSetString[j]) {
            temp.push_back(dataSetString[i]);
            ++i;
        }
        else {
            temp.push_back(dataSetString[j]);
            ++j;
        }

    }

    while (i <= m) {
        temp.push_back(dataSetString[i]);
        ++i;
    }

    while (j <= e) {
        temp.push_back(dataSetString[j]);
        ++j;
    }

    for (int i = s; i <= e; ++i)
        dataSetString[i] = temp[i - s];


}
void sorting::MergeSortV( int s, int e) {
    if (s < e) {
        int m = (s + e) / 2;
        MergeSortV( s, m);
        MergeSortV(m + 1, e);
        MergeSortedIntervals( s, m, e);
    }

}

//---------------

void sorting::shellSortString()
{
    int n = dataSetString.size();

    for (int gap = n/2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i += 1)
        {
            string temp = dataSetString[i];

            int j;
            for (j = i; j >= gap && dataSetString[j - gap] > temp; j -= gap)
                dataSetString[j] = dataSetString[j - gap];

            dataSetString[j] = temp;
        }
    }

    for (int i=0; i<n; i++)
        cout << dataSetString[i] << " ";

}
void sorting::shellSortInt()
{
    int n = dataSetInt.size();

    for (int gap = n/2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i += 1)
        {
            int temp = dataSetInt[i];

            int j;
            for (j = i; j >= gap && dataSetInt[j - gap] > temp; j -= gap)
                dataSetInt[j] = dataSetInt[j - gap];

            dataSetInt[j] = temp;
        }
    }

    for (int i=0; i<n; i++)
        cout << dataSetInt[i] << " ";

}
//------

void sorting :: instString(int left, int right)
{
    for (int i = left + 1; i <= right; i++)
    {
        string temp = dataSetString[i];
        int j = i - 1;
        while (j >= left && dataSetString[j] > temp)
        {
            dataSetString[j+1] = dataSetString[j];
            j--;
        }
        dataSetString[j+1] = temp;
    }
}
void sorting :: instInt(int left, int right)
{
    for (int i = left + 1; i <= right; i++)
    {
        int temp = dataSetInt[i];
        int j = i - 1;
        while (j >= left && dataSetInt[j] > temp)
        {
            dataSetInt[j+1] = dataSetInt[j];
            j--;
        }
        dataSetInt[j+1] = temp;
    }
}
//----

    void sorting::timSortString()
    {
        int n = dataSetString.size();
        int RUN = pow(dataSetString.size(), 2);

        // Sort individual subarrays of size RUN
        for (int i = 0; i < n; i+=RUN)
            inst(i, min((i+RUN-1),
                                      (n-1)));

        for (int size = RUN; size < n;
             size = 2*size)
        {

            for (int left = 0; left < n;
                 left += 2*size)
            {

                int mid = left + size - 1;
                int right = min((left + 2*size - 1),
                                (n-1));

                if(mid < right)
                    MergeSortedIntervals(left, mid, right);
            }
        }

        for (int i=0; i<n; i++)
            cout << dataSetString[i] << " ";
    }
void sorting::timSortInt()
{
    int n = dataSetInt.size();
    int RUN = pow(dataSetInt.size(), 2);

    // Sort individual subarrays of size RUN
    for (int i = 0; i < n; i+=RUN)
        inst(i, min((i+RUN-1),
                    (n-1)));

    for (int size = RUN; size < n;
         size = 2*size)
    {

        for (int left = 0; left < n;
             left += 2*size)
        {

            int mid = left + size - 1;
            int right = min((left + 2*size - 1),
                            (n-1));

            if(mid < right)
                MergeSortedIntervals(left, mid, right);
        }
    }

    for (int i=0; i<n; i++)
        cout << dataSetInt[i] << " ";
}

void sorting::randQuickSortString(vector <string> &v, int low, int high){
    if(low<high){
        int pi = randomPartitionString(v, low, high);
        randQuickSortString(v, low, pi-1);
        randQuickSortString(v, pi+1, high);
    }
}
void sorting::randQuickSortInt(vector <int> &v, int low, int high){
    if(low<high){
        int pi = randomPartitionInt(v, low, high);
        randQuickSortInt(v, low, pi-1);
        randQuickSortInt(v, pi+1, high);
    }
}
int sorting::partitionString(vector <string> &v,int low, int high ){
    string pivot= v[high];
    int i = low-1;

    for (int j = low; j<=high-1; j++){
        if(v[j]<=pivot){
            i++;
            swap(v[i], v[j]);
        }
    }
    swap(v[i+1], v[high]);
    return (i+1);
}
int sorting::partitionInt(vector <int> &v,int low, int high ){
    int pivot= v[high];
    int i = low-1;

    for (int j = low; j<=high-1; j++){
        if(v[j]<=pivot){
            i++;
            swap(v[i], v[j]);
        }
    }
    swap(v[i+1], v[high]);
    return (i+1);
}
int sorting::randomPartitionString(vector <string>& v, int low, int high){
    srand(time(NULL));
    int random = low + rand() % (high - low);
    swap(v[random], v[high]);
    return partitionString(v, low, high);
}
int sorting::randomPartitionInt(vector <int>& v, int low, int high){
    srand(time(NULL));
    int random = low + rand() % (high - low);
    swap(v[random], v[high]);
    return partitionInt(v, low, high);
}
void sorting::randQuickSortCallString() {
    randQuickSortString(dataSetString, 0, dataSetString.size()-1);
    for(int i = 0; i < dataSetString.size(); i++){
        cout << dataSetString[i] << " ";
    }
}
void sorting::randQuickSortCallInt() {
    randQuickSortInt(dataSetInt, 0, dataSetInt.size()-1);
    for(int i = 0; i < dataSetInt.size(); i++){
        cout << dataSetInt[i] << " ";
    }
}