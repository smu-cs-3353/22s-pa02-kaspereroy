//London Kasper, Hazel Eroy 22s-pa02-kaspereroy
//Research on QuickSort function done on GeeksForGeeks.com
#include <algorithm>
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
}

void sorting::runAlgorithms(){ // This function runs all of the datasets through each of the algorithms and records time data to an output csv
    ofstream outputInt;
    ofstream outputString;
    outputInt.open("../output/outputInt.csv");
    outputInt << "size,randQuickSort,insertion,merge,shell,tim,intro\n";
    outputString.open("../output/outputString.csv");
    outputString << "size,randQuickSort,insertion,merge,shell,tim,intro\n";
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

        duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
        cout << endl << "Insertion Sort Integer: " << " " << duration.count() << endl;
        outputInt<< duration.count()<<",";

        start = std::chrono::high_resolution_clock::now();
        insertionString();
        stop = std::chrono::high_resolution_clock::now();

        duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
        cout << endl << "Insertion Sort String: " << " " << duration.count() << endl;
        outputString << duration.count()<<",";

        //Merge sort
        dataSetString = tempString;
        dataSetInt = tempInt;

        start = std::chrono::high_resolution_clock::now();
        mergeInt();
        stop = std::chrono::high_resolution_clock::now();

        duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
        cout << endl << "Merge Sort Integer: " << " " << duration.count() << endl;
        outputInt<< duration.count()<<",";

        start = std::chrono::high_resolution_clock::now();
        mergeString();
        stop = std::chrono::high_resolution_clock::now();

        duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
        cout << endl << "Merge Sort String: " << " " << duration.count() << endl;
        outputString << duration.count()<<",";

        //shellsort
        dataSetString = tempString;
        dataSetInt = tempInt;

        start = std::chrono::high_resolution_clock::now();
        shellSortInt();
        stop = std::chrono::high_resolution_clock::now();

        duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
        cout << endl << "Shell Sort Integer: " << " " << duration.count() << endl;
        outputInt<< duration.count()<<",";

        start = std::chrono::high_resolution_clock::now();
        shellSortString();
        stop = std::chrono::high_resolution_clock::now();

        duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
        cout << endl << "Shell Sort String: " << " " << duration.count() << endl;
        outputString << duration.count()<<",";

        //timsort
        dataSetString = tempString;
        dataSetInt = tempInt;

        start = std::chrono::high_resolution_clock::now();
        timSortInt();
        stop = std::chrono::high_resolution_clock::now();

        duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
        cout << endl << "Tim Sort Integer: " << " " << duration.count() << endl;
        outputInt<< duration.count()<<',';

        start = std::chrono::high_resolution_clock::now();
        timSortString();
        stop = std::chrono::high_resolution_clock::now();

        duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
        cout << endl << "Tim Sort String: " << " " << duration.count() << endl;
        outputString << duration.count() << ',';

        //introSort
        dataSetString = tempString;
        dataSetInt = tempInt;

        start = std::chrono::high_resolution_clock::now();
        introSortCall();
        stop = std::chrono::high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
        cout << endl << "Intro Integer: " << " " << duration.count() << endl;
        outputInt << duration.count() << endl;

        start = std::chrono::high_resolution_clock::now();
        introSortCallStr();
        stop = std::chrono::high_resolution_clock::now();
        duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
        cout << endl << "Intro String: " << " " << duration.count() << endl;
        outputString << duration.count() <<endl;
    }
}


void sorting::insertionString() {  //Insertion sort for string vector

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
}

//---------------

void sorting::mergeString(){ //merge sort call for string vector
    MergeSortVString( 0, dataSetString.size()-1);
}
void sorting::mergeInt(){ //merge sort call for integer vector
    MergeSortVInt( 0, dataSetInt.size()-1);
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
}
void sorting::randQuickSortCallInt() {
    randQuickSortInt(dataSetInt, 0, dataSetInt.size()-1);
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
}