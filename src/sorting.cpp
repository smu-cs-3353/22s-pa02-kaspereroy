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
#include <chrono>

using namespace std;

void sorting::readFile(string fileName){
    ifstream file("../input/"+fileName);

    if(!file.is_open()){ // Check to see if file is not open
        cout << "File did not open" << endl;
    }
    else{ // If file is open, begin reading in data
        string fullLine; // Will hold an entire line of the csv file
        string delimiter = ",";
        string temp;
        size_t pos = 0;
        getline(file, fullLine);

        while(!file.eof()){
            vector <string> tempString;
            vector <int> tempInt;
            // Read an entire line into fullLine (AKA an entire dataset)
            while((pos = fullLine.find(delimiter))!= string::npos){
                temp = fullLine.substr(0, pos); // Isolate an element of that dataset
                tempString.push_back(temp); // Add that element to the temp vectors to later be pushed back into the full data vectors
                tempInt.push_back(stoi(temp));
                fullLine.erase(0, pos + delimiter.length());
            }
            temp = fullLine.substr(0, pos);
            temp.erase(remove(temp.begin(), temp.end(), '\r'), temp.end());
            tempString.push_back(temp); // Make sure to get the last element of that line
            tempInt.push_back(stoi(temp));
            fullDataString.push_back(tempString);
            fullDataInt.push_back(tempInt);
            getline(file, fullLine, '\n');
        }

    }
    cout << "The size of fullDataString: " << fullDataString.size() << endl;
    cout << "The size of fullDataInt: " << fullDataInt.size() << endl;
    for(int i = 0; i < fullDataInt[0].size(); i++){
        cout << fullDataInt[0][i] << " ";
    }
    cout << endl;
}

void sorting::runAlgorithms(){ // This function runs all of the datasets through each of the algorithms and records time data to an output csv
    ofstream outputInt;
    ofstream outputString;
    outputInt.open("../output/outputInt.csv");
    outputInt << "size,randQuickSort,insertion,merge,shell,intro,tim\n";
    outputString.open("../output/outputString.csv");
    outputString << "size,randQuickSort,insertion,merge,shell,intro,tim\n";
    // output header of all sorting algorithms in order that they go
    for(int i = 0; i < fullDataString.size(); i++){
        outputString << fullDataString[i].size()<<',';
        outputInt << fullDataInt[i].size()<<',';
        vector<int>  tempInt = fullDataInt[i];
        vector<string> tempString = fullDataString[i];
        dataSetString = tempString;
        dataSetInt = tempInt;
//run all of the algorithms for both data types while timing each algorithm (and don't forget to output the time data to a csv)

        //Randomized Quick Sorting
        auto start = std::chrono::high_resolution_clock::now();
        randQuickSortCallInt();
        auto stop = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
        cout << endl << "Rando QuickSort Integer: " << " " << duration.count() << endl;
        outputInt<< duration.count()<<",";

        start = std::chrono::high_resolution_clock::now();
        randQuickSortCallString();
        stop = std::chrono::high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
        cout << endl << "Rando QuickSort String: " << " " << duration.count() << endl;
        outputString << duration.count()<<",";

        //Insertion Sort

        dataSetString = tempString;
        dataSetInt = tempInt;

        start = std::chrono::high_resolution_clock::now();
        insertionInt();
        stop = std::chrono::high_resolution_clock::now();

//        dataSetString.clear();
//        dataSetInt.clear();

        duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
        cout << endl << "Insertion Sort Integer: " << " " << duration.count() << endl;
        outputInt<< duration.count()<<",";

        dataSetString = tempString;
        dataSetInt = tempInt;

        start = std::chrono::high_resolution_clock::now();
        insertionString();
        stop = std::chrono::high_resolution_clock::now();

//        dataSetString.clear();
//        dataSetInt.clear();

        duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
        cout << endl << "Insertion Sort String: " << " " << duration.count() << endl;
        outputString << duration.count()<<",";

        //Merge sort
        dataSetString = tempString;
        dataSetInt = tempInt;

        start = std::chrono::high_resolution_clock::now();
        mergeInt();
        stop = std::chrono::high_resolution_clock::now();

//        dataSetString.clear();
//        dataSetInt.clear();

        duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
        cout << endl << "Merge Sort Integer: " << " " << duration.count() << endl;
        outputInt<< duration.count()<<",";

        dataSetString = tempString;
        dataSetInt = tempInt;

        start = std::chrono::high_resolution_clock::now();
        mergeString();
        stop = std::chrono::high_resolution_clock::now();

//        dataSetString.clear();
//        dataSetInt.clear();

        duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
        cout << endl << "Merge Sort String: " << " " << duration.count() << endl;
        outputString << duration.count()<<",";

        //shellsort
        dataSetString = tempString;
        dataSetInt = tempInt;

        start = std::chrono::high_resolution_clock::now();
        shellSortInt();
        stop = std::chrono::high_resolution_clock::now();
//
//        dataSetString.clear();
//        dataSetInt.clear();

        duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
        cout << endl << "Shell Sort Integer: " << " " << duration.count() << endl;
        outputInt<< duration.count()<<",";

        dataSetString = tempString;
        dataSetInt = tempInt;

        start = std::chrono::high_resolution_clock::now();
        shellSortString();
        stop = std::chrono::high_resolution_clock::now();

//        dataSetString.clear();
//        dataSetInt.clear();

        duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
        cout << endl << "Shell Sort String: " << " " << duration.count() << endl;
        outputString << duration.count()<<",";

        //introsort
        //timsort
        dataSetString.clear();
        dataSetInt.clear();
        dataSetString = tempString;
        dataSetInt = tempInt;

        start = std::chrono::high_resolution_clock::now();
        timSortInt();
        stop = std::chrono::high_resolution_clock::now();

        duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
        cout << endl << "Tim Sort Integer: " << " " << duration.count() << endl;
        outputInt<< duration.count();

        start = std::chrono::high_resolution_clock::now();
        timSortString();
        stop = std::chrono::high_resolution_clock::now();

        duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
        cout << endl << "Tim Sort String: " << " " << duration.count() << endl;
        outputString << duration.count();

//        dataSetString.clear();
//        dataSetInt.clear();

        dataSetString = tempString;
        dataSetInt = tempInt;


        start = std::chrono::high_resolution_clock::now();
        introSortCall();
        stop = std::chrono::high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
        cout << endl << "Intro Integer: " << " " << duration.count() << endl;
        outputString << duration.count() << endl;
//        for(int j = 0; j < dataSetInt.size(); j++){
//            cout << dataSetInt[j] << ' ';
//        }
//
        start = std::chrono::high_resolution_clock::now();
        introSortCallStr();
        stop = std::chrono::high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
        cout << endl << "Intro String: " << " " << duration.count() << endl;
        outputString << duration.count() <<endl;
//        for(int j = 0; j < dataSetString.size(); j++){
//            cout << dataSetString[j] << ' ';
//        }
//        start = std::chrono::high_resolution_clock::now();
//        callIntroSortInt();
//        stop = std::chrono::high_resolution_clock::now();
//        duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
//        cout << endl << "Intro Integer: " << " " << duration.count() << endl;
//
//        start = std::chrono::high_resolution_clock::now();
//        callIntroSortStr();
//        stop = std::chrono::high_resolution_clock::now();
//        duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
//        cout << endl << "Intro String: " << " " << duration.count() << endl;

    }
}


void sorting::insertionString() {  //vector <string> arrstr, int k

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
//    for (z = 0; z < k; z++)
//        cout << dataSetString[z] << " ";
//    cout << endl;


}

void sorting::insertionInt() {  //vector <string> arrstr, int k
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
//    for (z = 0; z < k; z++)
//        cout << dataSetInt[z] << " ";
//    cout << endl;

}

//---------------

void sorting::mergeString(){
    MergeSortVString( 0, dataSetString.size()-1);
//    for (int i = 0; i < dataSetString.size(); ++i) {
//        cout << dataSetString[i] << ' ';
//    }
}
void sorting::mergeInt(){
    MergeSortVInt( 0, dataSetInt.size()-1);
//    for (int i = 0; i < dataSetInt.size(); ++i) {
//        cout << dataSetInt[i] << ' ';
//    }
}

void sorting::MergeSortedIntervalsString(int s, int m, int e) {

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
void sorting::MergeSortedIntervalsInt(int s, int m, int e) {

    // temp is used to temporary store the vector obtained by merging
    // elements from [s to m] and [m+1 to e] in v
    vector<int> temp;

    int i, j;
    i = s;
    j = m + 1;

    while (i <= m && j <= e) {

        if (dataSetInt[i] <= dataSetInt[j]) {
            temp.push_back(dataSetInt[i]);
            ++i;
        }
        else {
            temp.push_back(dataSetInt[j]);
            ++j;
        }

    }

    while (i <= m) {
        temp.push_back(dataSetInt[i]);
        ++i;
    }

    while (j <= e) {
        temp.push_back(dataSetInt[j]);
        ++j;
    }

    for (int i = s; i <= e; ++i)
        dataSetInt[i] = temp[i - s];


}
void sorting::MergeSortVString( int s, int e) {
    if (s < e) {
        int m = (s + e) / 2;
        MergeSortVString( s, m);
        MergeSortVString(m + 1, e);
        MergeSortedIntervalsString( s, m, e);
    }

}
void sorting::MergeSortVInt( int s, int e) {
    if (s < e) {
        int m = (s + e) / 2;
        MergeSortVInt( s, m);
        MergeSortVInt(m + 1, e);
        MergeSortedIntervalsInt( s, m, e);
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

//    for (int i=0; i<n; i++)
//        cout << dataSetString[i] << " ";

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

//    for (int i=0; i<n; i++)
//        cout << dataSetInt[i] << " ";

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
//    for(int i = 0; i < dataSetString.size(); i++){
//        cout << dataSetString[i] << " ";
//    }
//    cout << endl;
}
void sorting::randQuickSortCallInt() {
    randQuickSortInt(dataSetInt, 0, dataSetInt.size()-1);
//    for(int i = 0; i < dataSetInt.size(); i++){
//        cout << dataSetInt[i] << " ";
//    }
}


//-----
void sorting::timSortInt()
{
    int n = dataSetInt.size();
    int RUN = pow(dataSetInt.size(), 2);

    // Sort individual subarrays of size RUN
    for (int i = 0; i < n; i+=RUN)
        instInt(i, min((i+RUN-1),
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
                MergeSortedIntervalsInt(left, mid, right);
        }
    }

//    for (int i=0; i<n; i++)
//        cout << dataSetInt[i] << " ";
}

void sorting::timSortString()
{
    int n = dataSetInt.size();
    int RUN = pow(dataSetInt.size(), 2);

    // Sort individual subarrays of size RUN
    for (int i = 0; i < n; i+=RUN)
        instString(i, min((i+RUN-1),
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
                MergeSortedIntervalsString(left, mid, right);
        }
    }
//
//    for (int i=0; i<n; i++)
//        cout << dataSetString[i] << " ";
}

//-----

int sorting::partition(vector<int> v, int low, int high){
    int pivot = v[high];
    int smaller = low-1;
    for(int i = low; i<= high-1; i++){
        if(v[i] <=pivot){
            smaller++;
            swap(v[smaller], v[i]);
        }
    }
    swap(v[smaller+1],v[high]);
    return smaller+1;
}
void sorting::introSortCall(){
    introSort(dataSetInt, dataSetInt.size());
}
void sorting::introSort(vector<int>& v, int depthMax){
    int size = partition(v, 0, depthMax -1);
    if(size < 16){
        InsertionSort(v);
    }
    else if(size > (2*log(depthMax))){
        heapSort(v, depthMax);
    }
    else{
        quickSort(v, 0, depthMax-1);
    }
}
void sorting::quickSort(vector<int>& v, int low, int high){
    if(low < high){
        int partIndex = partition(v, low, high);
        quickSort(v, low, partIndex -1);
        quickSort(v, partIndex + 1, high);
    }

}
void sorting::heapSort(vector<int>& v, int size){
    for(int i = size/2-1; i>=0; i--){
        heapify(v, size, i);
    }
    for(int i = size - 1; i >= 0; i--){
        swap(v[0], v[i]);
        heapify(v, i, 0);
    }
}
void sorting::heapify(vector<int>&v, int size, int root){
    int biggest = root;//biggest = root
    int left = (2*root)+1;
    int right = (2*root)+2;
    if(left<size &&v[left]>v[biggest]){ //left bigger than root
        biggest = left;
    }
    if(right < size && v[right]>v[biggest]){//right bigger than root
        biggest = right;
    }
    if(biggest != root){
        swap(v[root], v[biggest]);
        heapify(v, size, biggest);//heapify the new subtree
    }
}
void sorting::InsertionSort(vector<int>&v){
    long k = v.size();
    int i, j, key;
    for (i = 1; i < k; i++)
    {
        key = v[i];
        j = i - 1;

        while (j >= 0 && v[j] > key)
        {
            v[j + 1] = v[j];
            j = j - 1;
        }
        v[j + 1] = key;
    }
//
//    int z;
//    for (z = 0; z < k; z++)
//        cout << v[z] << " ";
//    cout << endl;
}
int sorting::partitionStr(vector<string> v, int low, int high){
    string pivot = v[high];
    int smaller = low-1;
    for(int i = low; i<= high-1; i++){
        if(v[i] <=pivot){
            smaller++;
            swap(v[smaller], v[i]);
        }
    }
    swap(v[smaller+1],v[high]);
    return smaller+1;
}
void sorting::introSortCallStr(){
    introSortStr(dataSetString, dataSetString.size());
}
void sorting::introSortStr(vector<string>& v, int depthMax){
    int size = partitionStr(v, 0, depthMax -1);
    if(size < 16){
        InsertionSortStr(v);
    }
    else if(size > (2*log(depthMax))){
        heapSortStr(v, depthMax);
    }
    else{
        quickSortStr(v, 0, depthMax-1);
    }
}
void sorting::quickSortStr(vector<string>& v, int low, int high){
    if(low < high){
        int partIndex = partitionStr(v, low, high);
        quickSortStr(v, low, partIndex -1);
        quickSortStr(v, partIndex + 1, high);
    }

}
void sorting::heapSortStr(vector<string>& v, int size){
    for(int i = size/2-1; i>=0; i--){
        heapifyStr(v, size, i);
    }
    for(int i = size - 1; i >= 0; i--){
        swap(v[0], v[i]);
        heapifyStr(v, i, 0);
    }
}
void sorting::heapifyStr(vector<string>&v, int size, int root){
    int biggest = root;//biggest = root
    int left = (2*root)+1;
    int right = (2*root)+2;
    if(left<size &&v[left]>v[biggest]){ //left bigger than root
        biggest = left;
    }
    if(right < size && v[right]>v[biggest]){//right bigger than root
        biggest = right;
    }
    if(biggest != root){
        swap(v[root], v[biggest]);
        heapifyStr(v, size, biggest);//heapify the new subtree
    }
}
void sorting::InsertionSortStr(vector<string>&v){
    long k = v.size();
    int i, j;
    string key;
    for (i = 1; i < k; i++)
    {
        key = v[i];
        j = i - 1;

        while (j >= 0 && v[j] > key)
        {
            v[j + 1] = v[j];
            j = j - 1;
        }
        v[j + 1] = key;
    }
//
//    int z;
//    for (z = 0; z < k; z++)
//        cout << v[z] << " ";
//    cout << endl;
}



//void sorting::callIntroSortInt(){
//    int n = dataSetInt.size();
//    int arr[n];
//    for (int i = 0; i < dataSetInt.size(); i++){
//        arr[i] = dataSetInt[i];
//    }
//
//    IntrosortInt(arr, arr, arr + n - 1);
//
//    for (int u = 0; u < n; u++){
//        cout << arr[u] << " ";
//    }
//}
//
//void sorting::swapValueInt(int* a, int* b)
//{
//    int* temp = a;
//    a = b;
//    b = temp;
//    return;
//}
//
//void sorting::InsertionSortInt(int arr[], int* begin, int* end)
//{
//    int left = begin - arr;
//    int right = end - arr;
//
//    for (int i = left + 1; i <= right; i++) {
//        int key = arr[i];
//        int j = i - 1;
//
//        while (j >= left && arr[j] > key) {
//            arr[j + 1] = arr[j];
//            j = j - 1;
//        }
//        arr[j + 1] = key;
//    }
//
//    return;
//}
//
//
//int* sorting::PartitionInt(int arr[], int low, int high)
//{
//    int pivot = arr[high];
//    int i = (low - 1);
//
//    for (int j = low; j <= high - 1; j++) {
//
//        if (arr[j] <= pivot) {
//            i++;
//
//            swap(arr[i], arr[j]);
//        }
//    }
//    swap(arr[i + 1], arr[high]);
//    return (arr + i + 1);
//}
//
//
//int* sorting::MedianOfThreeInt(int* a, int* b, int* c)
//{
//    if (*a < *b && *b < *c)
//        return (b);
//
//    if (*a < *c && *c <= *b)
//        return (c);
//
//    if (*b <= *a && *a < *c)
//        return (a);
//
//    if (*b < *c && *c <= *a)
//        return (c);
//
//    if (*c <= *a && *a < *b)
//        return (a);
//
//    if (*c <= *b && *b <= *a)
//        return (b);
//}
//
//
//void sorting::IntrosortUtilInt(int arr[], int* begin, int* end, int depthLimit)
//{
//    int size = end - begin;
//
//    if (size < 16) {
//        InsertionSortInt(arr, begin, end);
//        return;
//    }
//
//    if (depthLimit == 0) {
//        heapSortInt(begin, end+1);
//        return;
//    }
//
//    int* pivot = MedianOfThreeInt(begin, begin + size / 2, end);
//
//    swapValueInt(pivot, end);
//
//    int* partitionPoint = PartitionInt(arr, begin - arr, end - arr);
//    IntrosortUtilInt(arr, begin, partitionPoint - 1,depthLimit - 1);
//    IntrosortUtilInt(arr, partitionPoint + 1, end,depthLimit - 1);
//
//    return;
//}
//
//
//void sorting::IntrosortInt(int arr[], int* begin, int* end)
//{
//    int depthLimit = 2 * log(end - begin);
//
//    IntrosortUtilInt(arr, begin, end, depthLimit);
//
//    return;
//}
//
//
//void sorting::printArrayInt(int arr[], int n)
//{
//    for (int i = 0; i < n; i++)
//        cout << arr[i] << " \n"[i + 1 == n];
//}
//
//void sorting::heapMakerInt(int n, int i)
//{
//    int largest = i;
//    int l = 2 * i + 1;
//    int r = 2 * i + 2;
//
//    if (l < n && dataSetInt[l] > dataSetInt[largest])
//        largest = l;
//
//    if (r < n && dataSetInt[r] > dataSetInt[largest])
//        largest = r;
//
//    if (largest != i) {
//        swap(dataSetInt[i], dataSetInt[largest]);
//
//        heapMakerInt(n, largest);
//    }
//}
//
//void sorting::heapSortInt(int* begin, int*end)
//{
//    int n = dataSetInt.size();
//    int x = *begin;
//
//
//    for (int i = n / 2 - 1; i >= 0; i--)
//        heapMakerInt(x, i);
//
//    for (int i = n - 1; i > 0; i--) {
//        swap(dataSetInt[0], dataSetInt[i]);
//
//        heapMakerInt(i, 0);
//    }
//}
//
////-----
//void sorting::callIntroSortStr(){
//    int n = dataSetString.size();
//    string arr[n];
//    for (int i = 0; i < dataSetString.size(); i++){
//        arr[i] = dataSetString[i];
//    }
//
//    IntrosortStr(arr, arr, arr + n - 1);
//
//    for (int u = 0; u < n; u++){
//        cout << arr[u] << " ";
//    }
//}
//
//
//
//void sorting::swapValueStr(string* a, string* b)
//{
//    string* temp = a;
//    a = b;
//    b = temp;
//    return;
//}
//
///* Function to sort an array using insertion sort*/
//void sorting::InsertionSortStr(string arr[], string* begin, string* end)
//{
//
//    int left = begin - arr;
//    int right = end - arr;
//
//    for (int i = left + 1; i <= right; i++) {
//        string key = arr[i];
//        int j = i - 1;
//
//
//        while (j >= left && arr[j] > key) {
//            arr[j + 1] = arr[j];
//            j = j - 1;
//        }
//        arr[j + 1] = key;
//    }
//
//    return;
//}
//
//// A function to partition the array and return
//// the partition point
//string* sorting::PartitionStr(string arr[], int low, int high)
//{
//    string pivot = arr[high];
//    int i = (low - 1);
//
//    for (int j = low; j <= high - 1; j++) {
//
//        if (arr[j] <= pivot) {
//            i++;
//
//            swap(arr[i], arr[j]);
//        }
//    }
//    swap(arr[i + 1], arr[high]);
//    return (arr + i + 1);
//}
//
//
//string* sorting::MedianOfThreeStr(string* a, string* b, string* c)
//{
//    if (*a < *b && *b < *c)
//        return (b);
//
//    if (*a < *c && *c <= *b)
//        return (c);
//
//    if (*b <= *a && *a < *c)
//        return (a);
//
//    if (*b < *c && *c <= *a)
//        return (c);
//
//    if (*c <= *a && *a < *b)
//        return (a);
//
//    if (*c <= *b && *b <= *a)
//        return (b);
//}
//
//// A Utility function to perform intro sort
//void sorting::IntrosortUtilStr(string arr[], string* begin, string* end, int depthLimit)
//{
//    // Count the number of elements
//    int size = end - begin;
//
//    // If partition size is low then do insertion sort
//    if (size < 16) {
//        InsertionSortStr(arr, begin, end);
//        return;
//    }
//
//    // If the depth is zero use heapsort
//    if (depthLimit == 0) {
//        heapSortStr(begin, end+1);
//        return;
//    }
//
//    // Else use a median-of-three concept to
//    // find a good pivot
//    string* pivot = MedianOfThreeStr(begin, begin + size / 2, end);
//
//    // Swap the values pointed by the two pointers
//    swapValueStr(pivot, end);
//
//    // Perform Quick Sort
//    string* partitionPoint = PartitionStr(arr, begin - arr, end - arr);
//    IntrosortUtilStr(arr, begin, partitionPoint - 1, depthLimit - 1);
//    IntrosortUtilStr(arr, partitionPoint + 1, end, depthLimit - 1);
//
//    return;
//}
//
//void sorting::IntrosortStr(string arr[], string* begin, string* end)
//{
//    int depthLimit = 2 * log(end - begin);
//
//    IntrosortUtilStr(arr, begin, end, depthLimit);
//
//    return;
//}
//
//// A utility function ot print an array of size n
//void sorting::printArrayStr(int n)
//{
//    for (int i = 0; i < n; i++)
//        cout << dataSetString[i] << " \n"[i + 1 == n];
//}
//
//void sorting::heapMakerStr(string n, int i)
//{
//    int largest = i;
//    int l = 2 * i + 1;
//    int r = 2 * i + 2;
//
//    if (l < stoi(n) && dataSetString[l] > dataSetString[largest])
//        largest = l;
//
//    if (r < stoi(n) && dataSetString[r] > dataSetString[largest])
//        largest = r;
//
//    if (largest != i) {
//        swap(dataSetString[i], dataSetString[largest]);
//
//        heapMakerStr(n, largest);
//    }
//}
//
//void sorting::heapSortStr(string* begin, string* end)
//{
//    int n = dataSetString.size();
//    string x = *begin;
//
//
//    for (int i = n / 2 - 1; i >= 0; i--)
//        heapMakerStr(x, i);
//
//    for (int i = n - 1; i > 0; i--) {
//        swap(dataSetString[0], dataSetString[i]);
//
//        heapMakerStr(to_string(i), 0);
//    }
//}
