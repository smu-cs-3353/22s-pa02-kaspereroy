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
    //void insertion(vector <string> arrstr, int k);
    //void printArray(vector <string> arr, int n);
};


#endif //INC_22S_PA02_KASPEREROY_SORTING_H
