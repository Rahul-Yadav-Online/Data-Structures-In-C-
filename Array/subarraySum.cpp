/**
 * Program to find the index of subarray with sum as given by the user
 * Author : Rahul Yadav
 * 
 * Example : 
 * ----------------------------------------------------------------
 * User Input :
 * Size : 5
 * Sum : 12
 * Array : 1 2 3 7 5
 * 
 * Output :
 * 2 4
 * ---- 
 * sum of elements of the array from index 2-1 to 4-1
 * 2+3+7 = 12 = sum
 *  
*/

#include <iostream>
#include <vector>

template <typename T>
void sub_array_sum(T &ar, const long sum){
    long sm = 0;
    for(int i = 0; i < ar.size(); i++){
        sm = 0;
        for(int j = i; j < ar.size(); j++){
            sm += ar[j];
            if(sm == sum){
                std::cout << i+1 <<" " << j+1 << std::endl;
                return;
            }
        }
    }
    std::cout << "-1"<< std::endl;
}


int main(){
    int size{};
    long sum{};
    std::cin>>size >> sum;
    std::vector<int> arr(size);
    for(int i = 0; i < size; i++){
        std::cin >> arr[i];
    }
    sub_array_sum(arr,sum);

}