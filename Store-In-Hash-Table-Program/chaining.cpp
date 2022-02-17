#include <iostream>//declare library

using namespace std;

template <typename Z>//template to pass parameter

struct mNode{//declaring node
    Z info;
    mNode<Z> *next;
};

template <typename Z>

class chaining{
    mNode<Z> *start;//declaring a new {START} as a pointer
    
    public:
        int size = 0;
        chaining(){
            start = NULL;
        }
        ~chaining(){
            genEmpty();
        }

        void insertFront(Z & element){
            mNode<Z> *newmNode = new mNode<Z>;
            newmNode->info = element;
            newmNode->next = start;
            start = newmNode;
                ++size;
        }

        int search(Z & target){
            bool found = false;
            int index = -1;
            mNode<Z> *ptr = start;
            while(ptr != NULL && !found){
                if(ptr->info == target){
                    found = true;
                    index++;
                }else{
                    ptr = ptr->next;
                    ++index;
                }
            }
            return index;

        }

        Z getLast(){
            mNode<Z> *ptr = start;
            while(ptr->next!=NULL){
                ptr = ptr->next;
            }
            return ptr->info;
        }

        bool isEmpty(){
            return start == NULL;
        }

        void genEmpty(){
            while(start != NULL){
                mNode<Z> *ptr = start;
                start = start->next;
                delete ptr;
            }
        }

        friend ostream& operator << (ostream& os, chaining<Z>& list){
            mNode<Z> *ptr = list.start;
            while(ptr != NULL){
                os << ptr->info << " ";
                ptr = ptr -> next;
            }
            return os;
        }


};