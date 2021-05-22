#include "Sort.h"

//default constructor
Sort::Sort(){
    
    UnsortedNumbers = new double[5];
}
//overloaded constructor for create mode
Sort::Sort(string FileName, int numDoubles){
    CreateFile(FileName,numDoubles);
}
//overloaded constructor for sort mode
Sort::Sort(string FileName){
    SetArray(FileName);
}
//destructor
Sort::~Sort(){
    delete [] UnsortedNumbers;
}
//creates the file with random doubles
void Sort::CreateFile(string FileName, int numDoubles){
    UnsortedNumbers = new double[5];
    if(numDoubles > 500000){
        cout << "please enter an amount of doubles less than 500,000" << endl;
        return;
    }
    if(numDoubles <= 0){
        cout << "please enter an amount of doubles greater than 0" << endl;
        return;
    }
    ofstream randomDoublesFile (FileName);
    double tmpRandomNumber = 0;
    if(randomDoublesFile.is_open() && numDoubles > 0){
        randomDoublesFile << to_string(numDoubles) + '\n';
        srand (time(NULL));
        for (int i = 0; i < numDoubles; ++i){
            tmpRandomNumber = (500000 - 0) * ( (double)rand() / (double)RAND_MAX ) + 0;
            randomDoublesFile << to_string(tmpRandomNumber) + '\n';
        }
        
    }
    else{
        cout << "Cannot create file or number of doubles needs to be greater than 0" << endl;
        randomDoublesFile.close();
        return;
    }
    cout << "File made successfully please run again in sort mode to see sorting statistcs of the algorithms" << endl;
    randomDoublesFile.close();
}
//sets the array based on contents of file
void Sort::SetArray(string FileName){
    ifstream randomDoublesFile (FileName);
    string lineData;
    double tmpDouble;
    if(randomDoublesFile.is_open()){
        getline(randomDoublesFile,lineData);
        totalNumbers = stoi(lineData);
        UnsortedNumbers = new double[totalNumbers];
        for (int i = 0; i < totalNumbers; ++i){
            getline(randomDoublesFile,lineData);
            tmpDouble = stod(lineData);
            UnsortedNumbers[i] = tmpDouble;
        }

    }
    else{
        cout << "given file name does not exist" << endl;
        UnsortedNumbers = new double[5];
        isError = true;
    }
    randomDoublesFile.close();
    
}

//bubble sort the array
void Sort::BubbleSort(){

    double tmpArray[totalNumbers];
    for (int i = 0; i < totalNumbers; ++i){
        tmpArray[i] = UnsortedNumbers[i];
    }
    auto startTime = chrono::high_resolution_clock::now();
    for(int i = 0; i < totalNumbers; ++i){
        for(int j = 0; j < totalNumbers - i;++j){
            if(tmpArray[j] > tmpArray[j+1]){
                double tmp = tmpArray[j];
                tmpArray[j] = tmpArray[j+1];
                tmpArray[j+1] = tmp;
            }
        }
    }
    auto endTime = chrono::high_resolution_clock::now();
    cout.precision(12);
    cout << "Bubble Sort:" << endl;
    cout << "   Start time: " << chrono::duration_cast<chrono::microseconds>(startTime.time_since_epoch()).count()* 1e-6 << " Seconds" << endl;
    cout << "   End time: " << chrono::duration_cast<chrono::microseconds>(endTime.time_since_epoch()).count()* 1e-6 << " Seconds" <<endl;
    cout << "   Total Time: " << chrono::duration_cast<chrono::microseconds>(endTime - startTime).count() * 1e-6 << " Seconds" << endl;

}
//insertion sort the array
void Sort::InsertionSort(){
    double curr;
    int prevIndex;
    double tmpArray[totalNumbers];
    for (int i = 0; i < totalNumbers; ++i){
        tmpArray[i] = UnsortedNumbers[i];
    }
    auto startTime = chrono::high_resolution_clock::now();
    for (int i = 1; i < totalNumbers; ++i)
    {
        curr = tmpArray[i];
        prevIndex = i - 1;
 
        while (prevIndex >= 0 && tmpArray[prevIndex] > curr)
        {
            tmpArray[prevIndex + 1] = tmpArray[prevIndex];
            prevIndex = prevIndex - 1;
        }
        tmpArray[prevIndex + 1] = curr;
    }
    auto endTime = chrono::high_resolution_clock::now();
    cout << "Insertion Sort:" << endl;
    cout << "   Start time: " << chrono::duration_cast<chrono::microseconds>(startTime.time_since_epoch()).count()* 1e-6 << " Seconds" << endl;
    cout << "   End time: " << chrono::duration_cast<chrono::microseconds>(endTime.time_since_epoch()).count()* 1e-6 << " Seconds" <<endl;
    cout << "   Total Time: " << chrono::duration_cast<chrono::microseconds>(endTime - startTime).count() * 1e-6 << " Seconds" << endl;
}
//selection sort the array
void Sort::SelectionSort(){
    double tmpArray[totalNumbers];
    for (int i = 0; i < totalNumbers; ++i){
        tmpArray[i] = UnsortedNumbers[i];
    }
    auto startTime = chrono::high_resolution_clock::now();
    for (int i = 0; i < totalNumbers; ++i){
        int smallIndex = i;
        for (int j = i+1; j < totalNumbers; ++j){
            if(tmpArray[j] < tmpArray[smallIndex]){
                smallIndex = j;
            }
        }

        double tmp = tmpArray[i];
        tmpArray[i] = tmpArray[smallIndex];
        tmpArray[smallIndex] = tmp;
    }
    auto endTime = chrono::high_resolution_clock::now();
    cout << "Selection Sort:" << endl;
    cout << "   Start time: " << chrono::duration_cast<chrono::microseconds>(startTime.time_since_epoch()).count()* 1e-6 << " Seconds" << endl;
    cout << "   End time: " << chrono::duration_cast<chrono::microseconds>(endTime.time_since_epoch()).count()* 1e-6 << " Seconds" <<endl;
    cout << "   Total Time: " << chrono::duration_cast<chrono::microseconds>(endTime - startTime).count() * 1e-6 << " Seconds" << endl;
}
//creates sub arrays for merge sort
void Sort::MergeSubArrays(double unsortedArray[], int leftIndex, int midPoint, int rightIndex){
    int leftSize = midPoint - leftIndex + 1;
    int rightSize = rightIndex - midPoint;
    int initialLeftIndex = 0; 
    int initialRightIndex = 0;
    int initialMergedIndex = leftIndex;
    double leftArray[leftSize]; 
    double rightArray[rightSize];
 
    // Copy data to temp arrays leftArray[] and rightArray[]
    for (int i = 0; i < leftSize; ++i){
        leftArray[i] = unsortedArray[leftIndex + i];
    }
        
    for (int j = 0; j < rightSize; ++j){
        rightArray[j] = unsortedArray[midPoint + 1 + j];
    }
        
    //sort data in the original array
    while (initialLeftIndex < leftSize && initialRightIndex < rightSize) {
        if (leftArray[initialLeftIndex] <= rightArray[initialRightIndex]) {
            unsortedArray[initialMergedIndex] = leftArray[initialLeftIndex];
            initialLeftIndex++;
        }
        else {
            unsortedArray[initialMergedIndex] = rightArray[initialRightIndex];
            initialRightIndex++;
        }
        initialMergedIndex++;
    }
 
   //additional checks for to make sure it was all sorted
    while (initialLeftIndex < leftSize) {
        unsortedArray[initialMergedIndex] = leftArray[initialLeftIndex];
        initialLeftIndex++;
        initialMergedIndex++;
    }
 

    while (initialRightIndex < rightSize) {
        unsortedArray[initialMergedIndex] = rightArray[initialRightIndex];
        initialRightIndex++;
        initialMergedIndex++;
    }
}
//calls MergeSubArrays recursivly and then merges the arrays to combine back into one
void Sort::RecursiveMergeSort(double unsortedArray[], int leftIndex, int rightIndex){
    //if leftindex is >= rightindex then it reached array size of 1
    if(leftIndex>=rightIndex){
        return;
    }
    //calc mid point of the array
    int tmpMidPoint = leftIndex + (rightIndex-leftIndex)/2;
    //break down the left half of the array
    RecursiveMergeSort(unsortedArray,leftIndex,tmpMidPoint);
    //break down right half of the array
    RecursiveMergeSort(unsortedArray,tmpMidPoint+1,rightIndex);
    //merge and sort arrays
    MergeSubArrays(unsortedArray,leftIndex,tmpMidPoint,rightIndex);
}
//Merge sorts the array
void Sort::RunMergeSort(){
    double tmpArray[totalNumbers];
    for (int i = 0; i < totalNumbers; ++i){
        tmpArray[i] = UnsortedNumbers[i];
    }
    auto startTime = chrono::high_resolution_clock::now();
    RecursiveMergeSort(tmpArray,0,totalNumbers-1);
    auto endTime = chrono::high_resolution_clock::now();
    cout << "Merge Sort:" << endl;
    cout << "   Start time: " << chrono::duration_cast<chrono::microseconds>(startTime.time_since_epoch()).count()* 1e-6 << " Seconds" << endl;
    cout << "   End time: " << chrono::duration_cast<chrono::microseconds>(endTime.time_since_epoch()).count()* 1e-6 << " Seconds" <<endl;
    cout << "   Total Time: " << chrono::duration_cast<chrono::microseconds>(endTime - startTime).count() * 1e-6 << " Seconds" << endl;
}
//creates partitions in the array
int Sort::QuickSortPartition(double unsortedArray[], int lowIndex, int highIndex){
    int pivotPoint = unsortedArray[highIndex]; //initial pivot point
    int smallIndex = (lowIndex - 1); //small index for finding correct pivot point
    

    for (int currElement = lowIndex; currElement < highIndex; ++currElement)
    {
        // If current element is smaller than the pivot low index is found
        if (unsortedArray[currElement] < pivotPoint)
        {
            // increment index of smaller element and swap the current point with the small index
            smallIndex++; 
            double tmp = unsortedArray[smallIndex];
            unsortedArray[smallIndex] = unsortedArray[currElement];
            unsortedArray[currElement] = tmp;
        }
    }
    //swap point after small index with the high index
    double tmp = unsortedArray[smallIndex+1];
    unsortedArray[smallIndex + 1] = unsortedArray[highIndex];
    unsortedArray[highIndex] = tmp;
    //return the now found partition point index
    return (smallIndex + 1);
}

void Sort::QuickSort(double unsortedArray[], int lowIndex, int highIndex){
    //as long as not sorted
    if (lowIndex < highIndex)
    {
        //gets the partition point
        int PartitionIndex = QuickSortPartition(unsortedArray, lowIndex, highIndex);
 
        //partition and sort both halves on the opposite sides of the partition point
        QuickSort(unsortedArray, lowIndex, PartitionIndex - 1);
        QuickSort(unsortedArray, PartitionIndex + 1, highIndex);
    }
}
//Quick sorts the array
void Sort::RunQuickSort(){
    double tmpArray[totalNumbers];
    for (int i = 0; i < totalNumbers; ++i){
        tmpArray[i] = UnsortedNumbers[i];
    }
    auto startTime = chrono::high_resolution_clock::now();
    QuickSort(tmpArray,0,totalNumbers-1);
    auto endTime = chrono::high_resolution_clock::now();
    cout << "Quick Sort:" << endl;
    cout << "   Start time: " << chrono::duration_cast<chrono::microseconds>(startTime.time_since_epoch()).count()* 1e-6 << " Seconds" << endl;
    cout << "   End time: " << chrono::duration_cast<chrono::microseconds>(endTime.time_since_epoch()).count()* 1e-6 << " Seconds" <<endl;
    cout << "   Total Time: " << chrono::duration_cast<chrono::microseconds>(endTime - startTime).count() * 1e-6 << " Seconds" << endl;
}
//Shell sorts the array
void Sort::ShellSort(){
    double tmpArray[totalNumbers];
    for (int i = 0; i < totalNumbers; ++i){
        tmpArray[i] = UnsortedNumbers[i];
    }
    auto startTime = chrono::high_resolution_clock::now();
    int gapPoint;
    //decided to reduce the gap by 2 each time for simplicity 
    for (gapPoint = totalNumbers/2; gapPoint > 0; gapPoint /= 2)
    {
        for (int i = gapPoint; i < totalNumbers; i += 1)
        {
            int temp = tmpArray[i];
            int swapPoint;           
            for (swapPoint = i; swapPoint >= gapPoint && tmpArray[swapPoint - gapPoint] > temp; swapPoint -= gapPoint){
                 tmpArray[swapPoint] = tmpArray[swapPoint - gapPoint];
            } 
            tmpArray[swapPoint] = temp;
        }
    }
    auto endTime = chrono::high_resolution_clock::now();
    cout << "Shell Sort:" << endl;
    cout << "   Start time: " << chrono::duration_cast<chrono::microseconds>(startTime.time_since_epoch()).count()* 1e-6 << " Seconds" << endl;
    cout << "   End time: " << chrono::duration_cast<chrono::microseconds>(endTime.time_since_epoch()).count()* 1e-6 << " Seconds" <<endl;
    cout << "   Total Time: " << chrono::duration_cast<chrono::microseconds>(endTime - startTime).count() * 1e-6 << " Seconds" << endl;
}

//calls all the sort methods on the array
void Sort::SortAll(){
    //dont run if there was an error somewhere earlier
    if(!isError){
        BubbleSort();
        InsertionSort();
        SelectionSort();
        RunMergeSort();
        RunQuickSort();
        ShellSort();
    }
    
}