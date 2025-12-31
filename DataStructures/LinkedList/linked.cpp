#include<bits/stdc++.h>
using namespace std;
template<class T>
class LinkedList
{

    T x;
    LinkedList  *head,*tail,*nextt;
    int cur_pos=1,length;
    ofstream outf;
public:
    LinkedList()
    {
        head=NULL;
        tail=NULL;
        nextt=NULL;
        outf.open("list_output.txt",std::fstream::out);
        length=0;
        cur_pos=2;
    }
    int size()
    {
        return length;

    }
    pushBack(T item)
    {
        LinkedList *p;
        p = new LinkedList<T>;
        p->x= item;

        if(!head)
        {
            head=p;
            tail=p;
        }
        else
        {
            tail->nextt=p;
            tail=p;
        }
        length++;
    }
    void push(T item)
    {
        LinkedList *p, *temp_head;
        p = new LinkedList<T>;
        p->x= item;
        if(cur_pos==0)
        {
            p->nextt=head;
            head=p;
        }
        else
        {
            temp_head=head;
            for(int i=0; i<cur_pos-1; i++)
            {
                temp_head=temp_head->nextt;
            }
            p->nextt=temp_head->nextt;
            temp_head->nextt=p;
        }
        length++;
    }
    T erase()
    {
        T element;
        if(cur_pos==0)
        {
            element=head->x;
            head=head->nextt;
        }
        else
        {
            LinkedList * temp_head1, *temp_head2;
            temp_head1=head;
            for(int i=0; i<cur_pos-1; i++)
            {
                temp_head1=temp_head1->nextt;
            }
            temp_head2=temp_head1->nextt;
            element=temp_head2->x;
            temp_head1->nextt=temp_head2->nextt;
        }
        length--;
        return element;

    }
    void setToBegin()
    {
        cur_pos=0;
    }
    void setToEnd()
    {
        cur_pos=length-1;
    }
    void prev()
    {
        if(cur_pos)
            cur_pos--;
    }
    void next()
    {
        if(cur_pos+1<length)
            cur_pos++;
    }
    int currPos()
    {
        return cur_pos;
    }
    setToPos(int pos)
    {
        cur_pos=pos;
    }
    T getValue()
    {
        LinkedList *p;
        p=head;
        for(int i=0; i<cur_pos; i++)
        {
            p=p->nextt;
        }
        return p->x;
    }
    int find(T item)
    {
        LinkedList *p=head;
        //p=head;
        for(int i=0; i<length; i++)
        {
            if(p->x==item)
            {
                return i;
            }
            p = p->nextt;
        }

        return -1;
    }
    int clear()
    {

        head=NULL;
    }


    void printf()
    {
        outf<<"<";
        LinkedList * p;
        p=head;
        for(int i=0; i<length; i++)
        {
            if(i==cur_pos)
                outf<<"| ";
            outf<<p->x<<" ";
            p=p->nextt;
        }
        outf<<">\n";
    }
    void printff(int z=-1)
    {
        outf<<z<<"\n";
    }
    void printfT(T x)
    {
        outf<<x<<"\n";
    }
    void closef()
    {
        outf.close();
    }
    ~LinkedList(){
        LinkedList *temp;
        while(head!=NULL)
        {
            temp=head;
            head=head->next;
            delete temp;
        }
    }
};
