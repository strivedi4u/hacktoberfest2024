#include<bits/stdc++.h>
using namespace std;

struct Deque{

    int size, cap;
    int *arr;

    Deque(int c){

        cap = c;
        size = 0;
        arr = new int[cap];
    }
    // this function help us insert the element at the start of the deque
    void insertFront(int x){

        if(isFull()){

            cout<<"Deque is already Full!"<<endl;
            return;
        }
        else{

            for(int i = size-1; i >= 0; i--){

                arr[i+1] = arr[i];
            }
            arr[0] = x;
            size++;
        }
        
    }
    // this function would help us insert the element at the end of the deque
    void insertRear(int x){

        if(isFull()){

            cout<<"Deque is already Full!"<<endl;
            return;
        }
        else{

            arr[size] = x;
            size++;
        }
    }
    // this function would remove the first element of the deque upon calling
    void deleteFront(){

        if(isEmpty()){

            cout<<"Deque is already empty!"<<endl;
            return;
        }
        else{

            for(int i = 0; i < size-1; i++){

                arr[i] = arr[i+1];
            }
            size--;
        }
    }
    // this function would delete the last element of the deque on calling
    void deleteRear(){

        if(isEmpty()){

            cout<<"Deque is already empty!"<<endl;
            return;
        }
        else{

            size--;
        }
    }
    // This function would tell if the deque is full or not
    bool isFull(){

        return (size == cap);
    }
    // This function would tell us weather the deque is empty or not
    bool isEmpty(){

        return (size == 0);
    }
    // this function would give us the first element of the deque
    int front(){

        if(isEmpty()){

            return -1;
        }
        else{

            return arr[0];
        }
    }
    // This function would return us the last element of the deque
    int back(){

        if(isEmpty()){

            return -1;
        }
        else{

            return arr[size-1];
        }
    }
    // this function would print the whole deque
    void Print(){

        if(isEmpty()){

            cout<<"Deque is already empty!"<<endl;
        }
        else{

        for(int i = 0; i < size; i++){

            cout<<arr[i]<<" ";
        }
        cout<<endl;
        }
    }
    // this function would return us the size of the deque
    int getSize(){

        return size;
    }

};

int main(){

    struct Deque d(10);

    d.insertFront(23);
    d.insertFront(39);
    d.insertRear(56);
    d.insertRear(91);

    d.Print();

    cout<<d.getSize()<<endl;

    d.deleteFront();
    d.deleteRear();

    d.Print();

    cout<<d.getSize()<<endl;
    d.deleteFront();

    d.Print();
    d.deleteFront();

    d.Print();



}