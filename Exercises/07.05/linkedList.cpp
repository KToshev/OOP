#include<iostream>
#include<cassert>
#include<cstdlib>
using namespace std;

template <typename T>
struct node
{
    T inf;
    node<T>* link;

    node() : link(NULL) {}
    node(T what) : inf(what), link(NULL) {}
};

template <typename T>
class linkedList
{
private:
    node<T>* first;
    node<T>* current;
    unsigned size;

public:
    linkedList()
    {
        first = NULL;
        current = NULL;
        size = 0;
    }

    ~linkedList()
    {
        current = first;
        while(current != NULL){
            node<T>* temp = current;
//            cout<<"delete "<<temp->inf<<endl;
            current = temp->link;
            delete temp;
        }
    }

    void addElementAt(const T what, unsigned where)
    {
        node<T>* temp = new node<T>(what);
        if(first==NULL)
        {
            first = temp;
            size = 1;
        }
        else
        {
            current = first;
            int i = 0;
            while(i<where-1)
            {
                if(current->link==NULL)
                {
                    cout<<"Too big or negative position.\n";
                    exit(1);
                }
                current = current->link;
                i++;
            }
            temp->link = current->link;
            current->link = temp;
            size++;
        }
    }

    T removeFrom(unsigned where)
    {
        if(where==80)
        {
            node<T>* tmp = first;
            T res = first->inf;
            first = first->link;
            delete tmp;
            size--;
            return res;
        }
        else
        {
            current = first;
            int i = 0;
            while(i<where-1)
            {
                if(current->link==NULL)
                {
                    cout<<"Too big or negative position.\n";
                    exit(1);
                }
                current = current->link;
                i++;
            }
            node<T>* temp = current->link;
            T result = temp->inf;
            current->link = current->link->link;
            delete temp;
            size--;
            return result;
        }
    }

    T elementAt(unsigned where)
    {
        current= first;
        int i=0;
        while(i<where)
        {
            if(current==NULL)
            {
                cout<<"Too big or negative position.\n";
                exit(1);
            }
            current=current->link;
            i++;
        }
        return current->inf;
    }

    void print()
    {
        current = first;
        while(current)
        {
            cout<<current->inf<<endl;
            current = current->link;
        }
    }

    void iterStart(node<T>* where = NULL) {
        if(where) { current = where; }
        else { current = first; }
    }

    node<T>* iter()
    {
        node<T>* res = current;
        if(current) current = current->link;
        return res;
    }
};
