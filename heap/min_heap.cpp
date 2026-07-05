/*
Min Heap

→ CBT
→ Parent node should be less than or equal to child node.
→ For all nodes, it should be valid.
*/

#include <iostream>
using namespace std;

class minheap{
    int *arr;
    int size;        // total elements in heap
    int total_size;  // total size of array

public:
    minheap(int n){
        arr = new int[n];
        size = 0;
        total_size = n;
    }

    // Insert into heap
    void insert(int value){
        if(size==total_size){
            cout<<"heap is overflow\n";
            return;
        }
        arr[size]=value;
        int index=size;
        size++;
        while(index>0 && arr[(index-1)/2]>arr[index]){
            swap(arr[index],arr[(index-1)/2]);
            index=(index-1)/2;
        }
        cout<<arr[index]<<" is inserted into the heap\n";
         }

    void print(){
        for(int i = 0; i < size; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void heapify(int index){
      int smallest=index;
      int left=2*index+1;
      int right= 2*index+2;

       /*
        smallest will store the index of the element
        which is smaller between parent, left child,
        and right child.
        */
       if(left < size && arr[left] < arr[smallest]){
            smallest = left;
        }

        if(right < size && arr[right] < arr[smallest]){
            smallest = right;
        }

        if(smallest != index){
            swap(arr[index], arr[smallest]);
            heapify(smallest);
        }
    }

    void Delete(){
       if(size==0){
        cout<<"heap underflow\n";
        return;
       }
       cout<<arr[0]<<" deleted from the heap\n";
       arr[0]=arr[size-1];
       size--;
       if(size==0){
        return;
       }
       heapify(0);
      
    }
};

int main(){

    minheap h1(6);

    h1.insert(4);
    h1.insert(14);
    h1.insert(11);
    h1.insert(4);
    h1.insert(14);

    h1.Delete();

    h1.print();

    return 0;
}