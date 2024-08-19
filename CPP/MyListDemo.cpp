#include<bits/stdc++.h>
#include "MyListLinked.cpp"
#include "MyListArr.cpp"


using namespace std;


int main()
{
    ifstream instream("list_input.txt");
    ofstream outstream("list_output.txt");
    
    int k,x;
    instream>>k>>x;

    //MyList_Arr<int> myarray(x);
    MyList_Linked<int> myarray;

    while(k--)
    {
        int num;
        instream>>num;
        myarray.pushBack(num);

    }

    myarray.setToPos(myarray.size()/2);

    int q;
    instream>>q;

    //print(myarray,outstream);
    myarray.print(outstream);


    while(q--)
    {
        int op,param;
        instream>>op>>param;

        switch(op)
        {
            case 1:
            //print(myarray,outstream);
            myarray.print(outstream);
            outstream<<myarray.size()<<endl;
            break;

            case 2:
            myarray.push(param);
            //print(myarray,outstream);
            myarray.print(outstream);
            outstream<<-1<<endl;
            break;

            case 3:
            myarray.pushBack(param);
            //print(myarray,outstream);
            myarray.print(outstream);
            outstream<<-1<<endl;
            break;

            case 4:
            int v;
            v=myarray.erase();
            //print(myarray,outstream);
            myarray.print(outstream);
            outstream<<v<<endl;
            break;

            case 5:
            myarray.setToBegin();
               //print(myarray,outstream);
            myarray.print(outstream);
            outstream<<-1<<endl;
            break;

            case 6:
            myarray.setToEnd();
              //print(myarray,outstream);
            myarray.print(outstream);
            outstream<<-1<<endl;
            break;

            case 7:
            myarray.prev();
             //print(myarray,outstream);
            myarray.print(outstream);
            outstream<<-1<<endl;
            break;

            case 8:
            myarray.next();
             //print(myarray,outstream);
            myarray.print(outstream);
            outstream<<-1<<endl;
            break;

            case 9:
           //print(myarray,outstream);
            myarray.print(outstream);
            outstream<<myarray.currPos()<<endl;
            break;

            case 10:
            myarray.setToPos(param);
              //print(myarray,outstream);
            myarray.print(outstream);
            outstream<<-1<<endl;
            break;

            case 11:
             //print(myarray,outstream);
            myarray.print(outstream);
            outstream<<myarray.getValue()<<endl;
            break;

            case 12:
              //print(myarray,outstream);
            myarray.print(outstream);
            outstream<<myarray.find(param)<<endl;
            //cout<<-2<<endl;
            break;

            case 13:
            myarray.clear();
           //print(myarray,outstream);
            myarray.print(outstream);
            outstream<<-1<<endl;
            //cout<<-1<<endl;
            break;


        }

        


    }

    instream.close();
    outstream.close();
}