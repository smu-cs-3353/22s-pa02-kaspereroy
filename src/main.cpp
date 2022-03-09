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
    //merge sort -- done
    //shellsort -- done
    //introsort
    //timsort -- 

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

    sorting test;
    test.readFile("int-60.csv");
    //test.readFileInt("int-60.csv");
    //test.merge();
    //test.timSortString();
    cout <<"Testing string call" << endl;
    test.randQuickSortCallString();
    cout << "Testing integer call" << endl;
    test.randQuickSortCallInt();



 return 0;

}
