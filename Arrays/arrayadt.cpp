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
    return 0;
}