/*
Max Heap / Min Heap

Max Heap
→ CBT
→ Parent node should be greater than or equal to child node.
→ For all node, it should be valid.
Min Heap
→ CBT
→ Parent node should be less than or equal to its child node.
→ For all node, it should be valid.

*/   
#include <iostream>
using namespace std;
class maxheap{
    int *arr;
    int size; //total element in heap
    int total_size; //total size of array
    public:
    maxheap(int n){
        arr=new int[n];
        size=0;
        total_size=n;
    }
    //insert into heap
    void insert(int value){
        //if heap size is available or not
        if(size==total_size){
            cout<<"heap overflow\n";
            return;
        }
        arr[size]=value;
        int index=size;
        size++;
        //compare it with its parent
        while(index>0 && arr[(index-1)/2] <arr[index]){
            swap(arr[index], arr[(index-1)/2]);
            index=(index-1)/2;
        }

        cout<<arr[index]<<" is inserted into the heap\n ";
    }

    void print(){
        for(int i=0;i<size;i++){
           cout<<arr[i]<<" ";
        }
    }
    void heapify(int index){
        int largest=index;
        int left=2*index+1;
        int right=2*index+2;
        /*
        largest will store the index of the element which
        is greater between parent,left child and right child
         */

         if(left<size &&arr[left]>arr[largest]){
            largest=left;
         }
         if (right<size && arr[right]>arr[largest])
         {
            largest=right;
         }
         if(largest!=index){
            swap(arr[index],arr[largest]);
            heapify(largest);
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
int main() {
    maxheap h1(6);
    h1.insert(4);
    h1.insert(14);
    h1.insert(11);
    h1.insert(4);
    h1.insert(14);
    h1.Delete();
    h1.print();

    return 0;
}   