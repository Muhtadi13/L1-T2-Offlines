#include <bits/stdc++.h>
using namespace std;

template <class T>
class Stack_Array
{
    int tos;
    int max_size;
    T *arr;

    void grow()
    {

        T *tmp = new T[max_size * 2];

        for (int i = 0; i < max_size; i++)
        {
            tmp[i] = arr[i];
        }
        delete[] arr;

        arr = tmp;
        max_size = max_size * 2;
    }

    void shrink()
    {
        if (max_size > 1)
            max_size /= 2;

        T *tmp = new T[max_size];

        for (int i = 0; i < len; i++)
        {
            tmp[i] = arr[i];
        }
        delete[] arr;
        arr = tmp;
    }

public:
    Stack_Array(int sz = 100)
    {
        
        tos = 0;
        max_size = sz;
        arr = new T[max_size];
    }


    void enqueue(T item)
    {
        if (tos == max_size)
        {
            grow();
        }
        arr[tos] = element;
        tos++;
    }

    


     void clear()
    {

        max_size = 3;
        tos = 0;
       
        delete[] arr;
        arr = new T[max_size];
        
    }
};

int main()
{
}