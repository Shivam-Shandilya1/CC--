#include <iostream>
#include <limits.h>
#include<bits/stdc++.h>

using namespace std;



class ArrayVector {
    public:
        ArrayVector();				            // constructor
        int size() const;				        // number of elements
        bool empty() const;				        // is vector empty?
        int& operator[](int i);			        // element at index
        int at(int i);                          // element at index
        void erase(int i);				        // remove element at index
        void insert(int i, const int& e);		// insert element at index
        void reserve(int N);			        // reserve at least N spots

    private:
        int capacity;				            // current array size
        int n;					                // number of elements in vector
        int* A;					                // array storing the elements
};

ArrayVector::ArrayVector()			            // constructor
: capacity(0), n(0), A(NULL) { }

int ArrayVector::size() const			        // number of elements
{ return n; }

bool ArrayVector::empty() const		            // is vector empty?
{ return size() == 0; }

int& ArrayVector::operator[](int i)		        // element at index
{ return A[i]; }
  						                        // element at index (safe)
int ArrayVector::at(int i) {
    if (i < 0 || i >= n){
        cout<<"Error : Terminating";
        return INT_MIN;
    }
    return A[i];
}

void ArrayVector::reserve(int N) {		        // reserve at least N spots
    if (capacity >= N) return;			        // already big enough
    int* B = new int[N];			            // allocate bigger array
    for (int j = 0; j < n; j++)			        // copy contents to new array
      B[j] = A[j];
    if (A != NULL) delete [] A;			        // discard old array
    A = B;					                    // make B the new array
    capacity = N;				                // set new capacity
}

void ArrayVector::insert(int i, const int& e) {
    if (n >= capacity)				            // overflow?
        reserve(max(1, 2 * capacity));		    // double array size
    for (int j = n - 1; j >= i; j--)		    // shift elements up
        A[j+1] = A[j];
    A[i] = e;					                // put in empty slot
    n++;					                    // one more element
}

void ArrayVector::erase(int i) {		        // remove element at index
    for (int j = i+1; j < n; j++)		        // shift elements down
        A[j - 1] = A[j];
    n--;					                    // one fewer element
}

void printOptions(){
    cout<<"1 : Insert\n";
    cout<<"2 : Erase\n";
    cout<<"3 : Get element at index i\n";
    cout<<"4 : Get size\n";
    cout<<"5 : Check if vector is empty\n";
    cout<<"6 : Exit\n";
}

int main() {
    printOptions();
    ArrayVector a = ArrayVector();
    int opt = -1;
    while(opt != 6){
        cin>>opt;
        switch(opt){
            case 1:{
                int elem,loc;
                cout<<"Enter index and element : \n";
                cin>>loc>>elem;
                a.insert(loc,elem);
                break;
            }
            case 2:{
                int loc;
                cout<<"Enter index : \n";
                cin>>loc;
                a.erase(loc);
                break;
            }
            case 3:{
                int loc;
                cout<<"Enter index : \n";
                cin>>loc;
                int res = a.at(loc);
                if(res == INT_MIN){
                    cout<<"Index out of bounds\n";
                }
                else{
                    cout<<res<<endl;
                }
                break;
            }
            case 4:{
                cout<<"Getting size\n";
                cout<<a.size()<<endl;
                break;
            }
            case 5:{
                cout<<"Vector is "<<(a.empty()?"":"not")<<" empty\n";
                break;
            }
            case 6:{
                break;
            }
        }
    }
    return 0;
}