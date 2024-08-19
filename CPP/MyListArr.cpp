#include <bits/stdc++.h>

using namespace std;

template <class T>
class MyList_Arr
{
    int len;
    T *arr;
    int pos;
    int max_size;

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

        // cout<<max_size<<" size"<<endl;

        T *tmp = new T[max_size];

        for (int i = 0; i < len; i++)
        {
            tmp[i] = arr[i];
        }
        delete[] arr;
        arr = tmp;
    }

public:
    MyList_Arr(int sz = 10)
    {
        len = 0;
        max_size = sz;
        pos = 0;
        arr = new T[max_size];
    }

    ~MyList_Arr()
    {
        delete[] arr;
    }

    int size()
    {
        return len;
    }

    void push(T element)
    {
        // cout<<len<<" length"<<endl;
        // cout<<currPos()<<endl;
        // cout<<"max"<<max_size<<endl;
        if (len == max_size)
        {
            grow();
        }
        for (int j = len; j > pos; j--)
        {
            arr[j] = arr[j - 1];
        }
        arr[pos] = element;
        len++;
        // cout<<len<<"hshshs"<<endl;
    }

    void pushBack(T element)
    {
        if (len == max_size)
        {
            grow();
        }
        arr[len] = element;
        len++;
        // cout<<len<<"hahaha"<<endl;
    }

    void setToBegin()
    {
        pos = 0;
    }

    void setToEnd()
    {
        if (len > 0)
            pos = len - 1;
        else
            pos=0;
    }

    void prev()
    {
        if (pos > 0)
            pos--;
    }

    void next()
    {
        if (pos < len - 1)
            pos++;
    }

    int currPos()
    {
        return pos;
    }

    void setToPos(int position)
    {
        if (position < len)
        {
            pos = position;
        }
    }

    T getValue()
    {
        return arr[pos];
    }

    int find(T item)
    {
        int ans = -1;
        for (int j = 0; j < len; j++)
        {
            if (arr[j] == item)
            {
                ans = j;
                break;
            }
        }
        return ans;
    }

    void clear()
    {

        max_size = 3;
        pos = 0;
        len = 0;
        // T *tmp=;
        // cout<<"pre"<<endl;
        delete[] arr;
        arr = new T[max_size];
        // cout<<"last"<<endl;
        // arr=tmp;
    }

    T erase()
    {
        if (len > 0)
        {
            T el = arr[pos];

            for (int i = pos; i < len - 1; i++)
            {

                arr[i] = arr[i + 1];
            }
            arr[len - 1] = 0;

            if (pos == len - 1 && len > 1)
                pos--;

            len--;
            if (len == max_size / 2 && max_size > 2)
            {
                shrink();
            }

            return el;
        }

        else
            return -1;
    }

    void print(ofstream &out)
    {

        out << "<";
        // cout<<-3<<endl;
        if (len > 0)
        {

            for (int i = 0; i < pos; i++)
            {
                out << arr[i] << " ";
            }
            out << "|"
                << " ";
            for (int i = pos; i < len; i++)
            {
                out << arr[i] << " ";
            }
            // if(p<marray.size())
            //  out<<arr[len-1];
        }

        out << ">" << endl;
    }
};