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

void sorting::readFile(string fileName) {
    cout << "reading file" << endl;
    string parameter = "../inputs/" + fileName;
    ifstream file ( parameter);
    if (!file.is_open()){
        cout << "not open" << endl;
    }else{
        string line;
        while (!file.eof()){
            getline(file, line, ',');
            dataSet.push_back(line);
        }
    }

    cout << "file read" << endl;
};


void sorting::insertion() { //vector <string> arrstr, int k
    cout << "in insertion" << endl;
    int k = dataSet.size();
    int i, j, key;
    for (i = 1; i < k; i++)
    {
        key = stoi(dataSet[i]);
        j = i - 1;

        while (j >= 0 && stoi(dataSet[j]) > key)
        {
            dataSet[j + 1] = dataSet[j];
            j = j - 1;
        }
        dataSet[j + 1] = to_string(key);
    }

    int z;
    for (z = 0; z < k; z++)
        cout << dataSet[z] << " ";
    cout << endl;

    cout << "done insertion" << endl;
}

//---------------

void sorting::merge(){
    MergeSortV( 0, dataSet.size()-1);
    for (int i = 0; i < dataSet.size(); ++i) {
        cout << dataSet[i] << ' ';
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

        if (stoi(dataSet[i]) <= stoi(dataSet[j])) {
            temp.push_back(dataSet[i]);
            ++i;
        }
        else {
            temp.push_back(dataSet[j]);
            ++j;
        }

    }

    while (i <= m) {
        temp.push_back(dataSet[i]);
        ++i;
    }

    while (j <= e) {
        temp.push_back(dataSet[j]);
        ++j;
    }

    for (int i = s; i <= e; ++i)
        dataSet[i] = temp[i - s];


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

void sorting::shellSort()
{
    int n = dataSet.size();

    for (int gap = n/2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i += 1)
        {
            int temp = stoi(dataSet[i]);

            int j;
            for (j = i; j >= gap && stoi(dataSet[j - gap]) > temp; j -= gap)
                dataSet[j] = dataSet[j - gap];

            dataSet[j] = to_string(temp);
        }
    }

    for (int i=0; i<n; i++)
        cout << dataSet[i] << " ";

}

//------

void sorting :: inst(int left, int right)
{
    for (int i = left + 1; i <= right; i++)
    {
        int temp = stoi(dataSet[i]);
        int j = i - 1;
        while (j >= left && stoi(dataSet[j]) > temp)
        {
            dataSet[j+1] = dataSet[j];
            j--;
        }
        dataSet[j+1] = to_string(temp);
    }
}


void sorting::timSort()
{
    int n = dataSet.size();
    int RUN = pow(dataSet.size(), 2);

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
        cout << dataSet[i] << " ";
}

