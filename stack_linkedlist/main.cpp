#include <iostream>

using namespace std;

template<class t>
class stack {
    struct node{
        t item;
        node *next;
    };
    node*top,*cur;
public:
    stack(){
        top = NULL;
    }


    void push(t newItem){
        node *newItemPtr = new node;
        if(newItemPtr == NULL)
                cout<<"Stack push cannot allocate memory";
                else{
        newItemPtr->item= newItem;

        newItemPtr->next = top;
        top = newItemPtr;
                }

    }

    bool isEmpty(){
        return top ==NULL;
    }

    void pop(){

        if(isEmpty())
            cout<<"Stack empty on pop";

        else{

            node*temp =top;
            top = top->next;
            temp= temp->next = NULL;
            delete temp;
        }
    }

    void pop(t&stackTop){

        if(isEmpty())
            cout<<"Stack empty on pop";

        else{
            stackTop = top->item;
            node*temp =top;
            top = top->next;
            temp= temp->next = NULL;
            delete temp;
        }
    }

    void getTop(t&stackTop){

        if(isEmpty())
            cout<<"Stack empty on getTop";

        else{
            stackTop = top->item;

        }
    }

    void display(){
        cur =top;
        cout<<"\nItems in tes stack : [";
        while(cur != NULL){

                cout<<cur->item<<"  ";
                cur = cur->next;
        }
        cout<<"]\n";
    }

};


int main()
{

    stack<int>s;
    s.push(5);
    s.push(3);
    s.push(4);
    s.push(1);
    s.display();

    return 0;
}
