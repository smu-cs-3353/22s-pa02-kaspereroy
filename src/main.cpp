#include <iostream>
#include <string>
#include <fstream>
#include "sorting.h"
using namespace std;
int main(){
    cout << "Hello world" << endl;


    //The sorting algorithms that you will implement are:
    //insertion sort -- done
    //randomized quicksort
    //merge sort
    //shellsort
    //introsort
    //timsort

    //Also need to construct separate categories of data sets: integer based, string based
    // Generate at least 6 dataset sizes.  More precisely:
//    for each category of data (int vs string):
//    for s in [list of sizes you have decided to use]:
//    generate a randomized dataset of size s with 0% duplicates
//    generate a dataset of size s with 0% duplicates that is sorted in ascending order
//    generate a dataset of size s with 0% duplicates such that 60% of the array is already sorted ascending.  One way to interpret this is to count the number of elements in each range of elements in the array that are already sorted.
//            generate a randomized dataset of size s with 20% duplicates (in other words, if you removed all the elements that appear somewhere else in the array, 20% of the total elements would be removed)
//    generate a randomized dataset of size s with 40% duplicates (in other words, if you removed all the elements that appear somewhere else in the array, 40% of the total elements would be removed)

    vector <string> vectstr = {"3","1","4","2","6","5","18"};
    //string arrstr[] = {"b","a","d","e","c","f"};
    //string arrstr[] = {"3","1","4","2","6","5"};
    //int arr[] = { 12, 11, 13, 5, 6 };
    //int n = sizeof(arr) / sizeof(arr[0]);
/*
    int k = sizeof(arrstr) / sizeof(arrstr[0]);

    sorting test;
    test.insertion(arrstr, k);
    test.printArray(arrstr, k);*/



sorting test;
test.readFile("int-6.csv");
test.mergeSort();
//test.insertion();
//test.insertion(vectstr, vectstr.size());
//test.printArray(vectstr, vectstr.size());


 /*   int arr[] = { 12, 11, 13, 5, 6, 7 };
    auto arr_size = sizeof(arr) / sizeof(arr[0]);

    cout << "Given array is \n";
    test.printArray(arr, arr_size);

    test.mergeSort(arr, 0, arr_size - 1);

    cout << "\nSorted array is \n";
    test.printArray(arr, arr_size);*/

    return 0;

}