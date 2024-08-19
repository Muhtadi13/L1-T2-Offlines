#include <bits/stdc++.h>
#include "LRUCache.cpp"

using namespace std;

int main()
{
    ifstream instream("lru_input.txt");
    ofstream outstream("lru_output.txt");

    int cap,que;
    instream>>cap>>que;

    LRUcache<int,int> lru(cap);

    while(que--)
    {
        int opt=0;
        instream>>opt;
        if(opt==1)
        {
            int key;
            instream>>key;
            outstream<<lru.get(key)<<endl;


        }
        else if(opt==2)
        {
            int key,val;
            instream>>key>>val;
            lru.put(key,val);
        }
    }
    instream.close();
    outstream.close();
    
    

}