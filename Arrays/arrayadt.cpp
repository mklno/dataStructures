#include<iostream>
using namespace std;

struct arrayadt
{
    /* data */
    int A[20];
    int size;
    int length;

    void display();
};

    void arrayadt::display(){
    int i;
    for(i=0; i<length;i++){
        cout<<A[i]<<endl;
    }
}


int main(){
    arrayadt A = {{1,2,3,4}, 20, 4};
    A.display();
    return 0;
}