#include<iostream>
#include<stdio.h>
using namespace std;

struct arrayadt
{
    /* data */
    int *A;
    int size;
    int length;

    void display();
    void append(int num);
    void insert(int index, int num);
    void delet(int index);
    int linearSearch(int key); //returns the index of the given number
    int binarySearch(int key); //valid only for sorted arr
    int rBinarySearch(int key, int low, int high); //valid only for sorted arr
    int get(int index);
    void set(int index, int key);
    int max();
    int min();
    int sum();
    int recursiveSum(int *A, int length);
    float average();
    int* reverse();
};
// display all th elements in arr
    void arrayadt::display(){
    int i;
    printf("Element in the arr are \n"); 
    for(i=0; i<length;i++){
        cout<<A[i]<<endl;
    }
}
// add an element at the end of the arr
    void arrayadt::append(int num){
        if (length < size){
            A[length] = num;
            length++;
        }
    }
// insert an element at a given index
    void arrayadt::insert(int index, int num){
        if (length < size){
        for(int j = length; j>index; j--){
            A[j] = A[j-1];
        }
        A[index] = num;
        length++;
    }
}
// delete an element at a given index
    void arrayadt::delet(int index){
        if (index > 0 && index < length){
            for(int i = index; i < length-1; i++){
            A[i]= A[i+1];
        }
        length--;
        }
        
    }
// returns the index of the given number if present
    int arrayadt::linearSearch(int key){  
        for(int i=0;i<length;i++){
            if (A[i] == key){
                return i;
            }
        }
        return -1;
    }
// returns the index of the given number if present efficiently
    int arrayadt::binarySearch(int key){
        int low = 0;
        int high = length-1;
        int mid = (low+high)/2;
        while(low <= high){
            if (key < A[mid]){
            high = mid -1;
        }
        else if (key > A[mid]){
            low = mid +1;
        }
        else{
            return A[mid];
        }
        }        
        return -1;
    }
// returns the index of the given number if present using recursion
    int arrayadt::rBinarySearch(int key, int low, int high){
        if(low <= high){
            int mid = (low+high)/2;
            if (key == A[mid]){
                return mid;
            }else if(key < A[mid]){
                return rBinarySearch(key, low, mid-1);
            }else{
                return rBinarySearch(key, mid+1, high);
            }
       }
       return -1;
    }
// returns the element at the given given index if the index is present
    int arrayadt::get(int index){
        if (index < length && index > 0){
            return A[index];
        }
        return -1; 
    }
// replace the value of the element at the given index
    void arrayadt::set(int index, int key){
        if (index > 0 && index < length){
            A[index] = key;
        }   
    }
// returns the max element in the arr
    int arrayadt::max(){
        int max = A[0];
        for(int i=0;i < length; i++){
            if (A[i] > max){
                max = A[i];
            }
        }
        return max;
    }
// returns the min element in the arr
    int arrayadt::min(){
        int min = A[0];
        for(int i = 0; i < length; i++){
            if (A[i] < min ){
                min = A[i];
            }
        }
        return min;
    }
// returns the total sum of all the elements in the arr
    int arrayadt::sum(){
        int sum = 0;
        for (int i =0; i < length; i++){
            sum += A[i];
        }
        return sum;
    }
// returns the total sum of all the elements in the arr using recursion
    int arrayadt::recursiveSum(int *A,int length){
        int n = length -1;
        if (length < 0){
            return 0;
        }
        else{
            return arrayadt::recursiveSum(A, n-1) + A[n];
        }
    }
// returns the average of the arr
    float arrayadt::average(){
        int sum = arrayadt::sum();
        int average = sum/length;
        return average;
    }

int main(){
    arrayadt arr;
    int i, n;
  
    printf("Enter the size of the array\n");
    scanf("%d", &arr.size);
    arr.A = (int *)malloc(arr.size*sizeof(int)); 
    arr.length = 0;

    printf("Enter the number of numbers\n");
    scanf("%d", &n);
    printf("Enter the all the numbers\n");
    // Reading all the elements of an arr
    for(i=0; i<n; i++){
        scanf("%d", &arr.A[i]);
        arr.length++;

    }
    arr.display(); 
    arr.append(10);
    arr.display();
    arr.insert(5,6);
    arr.display();
    arr.delet(3);
    arr.display();
    printf("%d\n", arr.linearSearch(5));
    printf("%d\n", arr.binarySearch(3));
    return 0;
}