#include <iostream>
#include <string>
#include <fstream>
#include "sorting.h"
using namespace std;
int main(){
    sorting test;
    test.readFile("int-60.csv");
    //test.readFile("input.csv");
    test.runAlgorithms();

 return 0;

}
