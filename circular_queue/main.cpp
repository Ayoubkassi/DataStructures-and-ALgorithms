#include <iostream>
#include <cassert>
using namespace std;
const int max_length=100;

class arrayQueue
{
    int rear;
    int Front;
    int length;
    int arr[max_length];
public:
    arrayQueue(){
        Front =0;
        rear = max_length - 1;
        length = 0;

    }

    int isEmpty(){
        return length == 0;

    }

    bool isFull(){
        return length == max_length;
    }

    void addQueue(int element){
        if(isFull())
            cout<<"Queue full can't enqueue...!";
        else{
            rear = (rear+1) % max_length;
            arr[rear] = element;
            length++;
        }
    }

    void deleteQueue(){
        if(isEmpty()){
            cout<<"Empty queue can't dequeue";
        }
        else{
        Front = (Front + 1) % max_length;
        --length;
    }

    }

    int frontQueue(){
        assert(!isEmpty());
        return arr[Front];
    }
    int rearQueue(){
        assert(!isEmpty());
        return arr[rear];
    }

    void printQueue(){
        if(!isEmpty()){
        for(int i=Front;i != rear;i=(i+1)%max_length){
            cout<<arr[i]<<" ";

        }
        cout<<arr[rear]; //or we could delete this and in the condition do i!=rear+1
    }
    else
        cout<<"Empty queue";


    }

};




int main()
{

    arrayQueue q1;
    q1.addQueue(2);
    q1.deleteQueue();
    q1.addQueue(45);
    q1.addQueue(76);
    q1.addQueue(8);
    q1.printQueue();
    return 0;
}
