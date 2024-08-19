#include <bits/stdc++.h>
#include "MyListLinked.cpp"
#include "MyListArr.cpp"

using namespace std;

template <class T, class V>
class LRUcache
{
    int capacity;
    MyList_Arr<T> listofkey;
    MyList_Arr<V> listofvalue;

    // MyList_Linked<T> listofkey;
    // MyList_Linked<V> listofvalue;

    int len;

public:
    LRUcache(int cap = 100)
    {
        capacity = cap;
        len = 0;

        //   listofkey=new MyList_Arr<T>(cap);
        //   listofvalue=new MyList_Arr<V>(cap);
    }
    void put(T key, V val)
    {
        if (len < capacity)
        {
            int ind = listofkey.find(key);
            if (ind != -1)
            {
                listofkey.setToPos(ind);
                listofvalue.setToPos(ind);
                listofkey.erase();
                listofvalue.erase();
                len--;
            }

            // listofkey.setToBegin();
            // listofvalue.setToBegin();

            listofkey.pushBack(key);
            listofvalue.pushBack(val);
            len++;
        }

        else
        {
            int ind = listofkey.find(key);
            if (ind == -1)
            {
                listofkey.setToBegin();
                listofkey.erase();
                listofkey.pushBack(key);

                listofvalue.setToBegin();
                listofvalue.erase();
                listofvalue.pushBack(val);
            }
            else
            {
                listofkey.setToPos(ind);
                listofvalue.setToPos(ind);
                listofkey.erase();
                listofvalue.erase();

                listofkey.pushBack(key);
                listofvalue.pushBack(val);
            }
        }
    }

    V get(T key)
    {
        int ind = listofkey.find(key);

        if (ind == -1)
            return -1;

        listofvalue.setToPos(ind);
        listofkey.setToPos(ind);

        V value = listofvalue.getValue();

        listofkey.erase();
        listofvalue.erase();

        listofkey.pushBack(key);
        listofvalue.pushBack(value);
        return value;
    }
};