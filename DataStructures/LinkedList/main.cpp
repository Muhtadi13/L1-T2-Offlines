#include<iostream>
#include<bits/stdc++.h>
#include "arr.cpp"
#include "linked.cpp"
using namespace std;


int main()
{
    ifstream inf("list_input.txt");

    int n,x,element,Q,a,b,z;
    inf>>n>>x;
    int array[n];

    //ArrayList<int> *m=new ArrayList<int>(x);
    LinkedList<int> *m=new LinkedList<int>();
    for(int i=0; i<n; i++)
    {
        inf>>element;
        m->pushBack(element);
    }
    inf>>Q;

    m->printf();
    for(int i=0; i<Q; i++)
    {
        inf>>a>>b;
        if(a==1)
        {
            z=m->size();
            m->printf();
            m->printff(z);
        }
        else if(a==2)
        {
            m->push(b);
            m->printf();
            m->printff();
        }
        else if(a==3)
        {
            m->pushBack(b);
            m->printf();
            m->printff();
        }
        else if(a==4)
        {
            int element =m->erase();
            m->printf();
            m->printfT(element);

        }
        else if(a==5)
        {
            m->setToBegin();
            m->printf();
            m->printff();
        }
        else if(a==6)
        {
            m->setToEnd();
            m->printf();
            m->printff();
        }
        else if(a==7)
        {
            m->prev();
            m->printf();
            m->printff();
        }
        else if(a==8)
        {
            m->next();
            m->printf();
            m->printff();
        }
        else if(a==9)
        {
            z=m->currPos();
            m->printf();
            m->printff(z);
        }
        else if(a==10)
        {
            m->setToPos(b);
            m->printf();
            m->printff();
        }
        else if(a==11)
        {
            z=m->getValue();
            m->printf();
            m->printff(z);
        }
        else if(a==12)
        {
            z=m->find(b);
            m->printf();
            m->printff(z);
        }
        else if(a==13)
        {
            m->clear();
            m->printf();
            m->printff();
        }

    }
    m->closef();

}
