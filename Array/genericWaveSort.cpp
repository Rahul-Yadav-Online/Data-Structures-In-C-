/**
 * Program to create a generic wave sort function and use it to sort an vector/array 
 * Author: Rahul Yadav
*/

#include <iostream>
#include <vector>

template <typename T>
void wave_sort( T &arr, const int size ){
    // Wave Sort function for vectors type data
    for(int i = 0; i<size; i+=2){
        // Run loop for even positions only 
        if(i>0 && arr[i]<arr[i-1]){
            std::swap(arr[i], arr[i-1]);
        }
        else if(i<size-1 && arr[i]<arr[i+1]){
            std::swap(arr[i], arr[i+1]);
        }
    }
}

template <typename T>
void wave_sort( T arr[], const int size ){
    // Wave Sort function for array type data
    for(int i = 0; i<size; i+=2){
        // Run loop for even positions only 
        if(i>0 && arr[i]<arr[i-1]){
            std::swap(arr[i], arr[i-1]);
        }
        else if(i<size-1 && arr[i]<arr[i+1]){
            std::swap(arr[i], arr[i+1]);
        }
    }
}


int main(){
    std::vector<int> arr = {0,5,4,3,1};
    int arr2[10] = {0,5,4,3,1};
    wave_sort(arr2, 10);
    wave_sort(arr, int(arr.size()));
    for(int i: arr){
        std::cout << i << " | ";
    }
    std::cout<<std::endl;
    for(int i=0; i<10; i++){
        std::cout << arr2[i] << " | ";
    }
    std::cout<<std::endl;
    return 0;
 }