#include <iostream>
#include <string>
#include <fstream>
#include "sorting.h"
using namespace std;
int main(){
    sorting test;
    test.readFile("input.csv");
    test.runAlgorithms();
    //test.print();
    //test.callIntroSortInt();

    //test.readFile("input.csv");
    //test.runAlgorithms();

        int arr[] = {2, 10, 24, 2, 10, 11, 27, 4, 2, 4,
                     28, 16, 9, 8, 28, 10, 1000, 13, 24, 22, 28,
                     0, 13, 27, 13, 3, 23, 18, 22, 8, 8};
        int n = sizeof(arr) / sizeof(arr[0]);

        // Pass the array, the pointer to the first element and
        // the pointer to the last element
        //test.IntrosortInt(arr, arr, arr + n - 1);

        //test.printArrayInt(arr, n);

 return 0;
}
