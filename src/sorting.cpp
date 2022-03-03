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
    cout << dataSet[2];
}

/*void sorting::insertion(vector <string> arrstr, int k) { //vector <string> arrstr, int k
    cout << "in insertion" << endl;
    int k = arrstr.size();
    int i, j;
    string key="";
    for (i = 1; i < k; i++)
    {
        key = arrstr[i];
        j = i - 1;

        while (j >= 0 && arrstr[j] > key)
        {
            arrstr[j + 1] = arrstr[j];
            j = j - 1;
        }
        arrstr[j + 1] = key;
    }

    int z;
    for (z = 0; z < k; z++)
        cout << dataSet[z] << " ";
    cout << endl;

    cout << "done insertion" << endl;

}*/


/*
void sorting::printArray(vector <string> arr, int n) {
    int i;
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
*/

