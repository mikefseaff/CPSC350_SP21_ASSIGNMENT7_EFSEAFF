#ifndef SORT_H
#define SORT_H
#include <iostream>
#include <fstream>
#include <chrono>
#include <random>
using namespace std;
//class containging the different functions for sorting and creating the file
class Sort{
    public:
        //default constructor
        Sort();
        //overloaded constructor for create mode
        Sort(string FileName, int numDoubles);
        //overloaded constructor for sort mode
        Sort(string FileName);
        //destructor
        ~Sort();
        //creates the file with random doubles
        void CreateFile(string FileName, int numDoubles);
        //sets the array based on contents of file
        void SetArray(string FileName);
        //bubble sort the array
        void BubbleSort();
        //insertion sort the array
        void InsertionSort();
        //selection sort the array
        void SelectionSort();
        //creates sub arrays for merge sort
        void MergeSubArrays(double unsortedArray[], int leftIndex, int midPoint, int rightIndex);
        //calls MergeSubArrays recursivly and then merges the arrays to combine back into one
        void RecursiveMergeSort(double unsortedArray[], int leftIndex, int rightIndex);
        //Merge sorts the array
        void RunMergeSort();
        //creates partitions in the array
        int QuickSortPartition(double unsortedArray[], int lowIndex, int highIndex);
        //recursivly calls QuickSortPartition until array is ordered
        void QuickSort(double unsortedArray[], int lowIndex, int highIndex);
        //Quick sorts the array
        void RunQuickSort();
        //Shell sorts the array
        void ShellSort();
        //calls all the sort methods on the array
        void SortAll();
        

    private:
        //array of unsorted numbers from the file
        double *UnsortedNumbers;
        //total numbers/ size of the array
        int totalNumbers;
        //bool for error checking in some parts of the code
        bool isError = false;

};
#endif
