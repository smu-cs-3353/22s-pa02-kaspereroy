#include <algorithm>
//
// Created by Hazel Eroy on 3/2/22.
//

#include "sorting.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
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
   /* int z;
    for (z = 0; z < dataSet.size(); z++)
        cout << dataSet[z] << " ";
    cout << endl;*/

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

void sorting::merge(int array[], int const left, int const mid, int const right){
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;

    auto *leftArray = new int[subArrayOne],
            *rightArray = new int[subArrayTwo];

    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];

    auto indexOfSubArrayOne = 0,
    indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;

    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }

    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }

    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
}

void sorting::mergeSort(int array[], int const begin, int const end)
{
    if (begin >= end)
        return; // Returns recursively

    auto mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}


void sorting::printArray(int A[], int size)
{
    for (auto i = 0; i < size; i++)
        cout << A[i] << " ";
}


