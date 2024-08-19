#include <bits/stdc++.h>

using namespace std;

class SymbolInfo
{
private:
    string name;
    string type;
    SymbolInfo *nextSymbolPointer;

public:
    SymbolInfo(){}
    // SymbolInfo(const SymbolInfo &s){
    //     name=s.name;
    //     type=s.type;
    //     nextSymbolPointer=new SymbolInfo;
    // }
    ~SymbolInfo(){
        nextSymbolPointer=NULL;
    }
    string getName()
    {
        return name;
    }
    string getType()
    {
        return type;
    }
    SymbolInfo *getNextSymbolPointer()
    {
        return nextSymbolPointer;
    }

    void setName(string nm)
    {
        name = nm;
    }
    void setType(string tp)
    {
        type = tp;
    }
    void setNextSymbolPointer(SymbolInfo *ptr)
    {
        nextSymbolPointer = ptr;
    }
    bool operator==(const SymbolInfo &sInfo)
    {
        if ((this->name) == (sInfo.name))
            return true;

        return false;
    }
};

class MyLinkedList
{
    SymbolInfo *head;
    SymbolInfo *tail;
    SymbolInfo *curr;

    int len;
    int cur_pos; // positioned exactly before curr pointer
                 // but if curr is NULL then cur_pos if after curr

public:
    MyLinkedList()
    {
        len = 0;
        cur_pos = 0;
        head = NULL;
        tail = NULL;
        curr = NULL;
    }

    ~MyLinkedList()
    {
        delete head;
        delete tail;
        delete curr;
    }

    int size()
    {
        return len;
    }

    int setToPos(int x)
    {
        // 1 based
        if (x < len && x > -1)
        {
            curr = head;
            int count = 0;
            while (curr != NULL)
            {
                if (count == x)
                {
                    cur_pos = count;
                    return cur_pos;
                }
                count++;
                curr = curr->getNextSymbolPointer();
            }
        }
    }

    void push(SymbolInfo &item)
    {
        // pushes just before the curr pointer ,in position of cur_pos
        // does not change value of cur_pos .but changes curr ( pretty obvious )

        if (head == NULL)
        {
            head = new SymbolInfo;
            head->setName(item.getName());
            head->setType(item.getType());
            tail = head;
            curr = head;
            tail->setNextSymbolPointer(NULL);
            cur_pos = 0;
            len++;
        }
        else if (head && cur_pos == 0)
        {
            SymbolInfo *nd = new SymbolInfo;
            nd->setName(item.getName());
            nd->setType(item.getType());
            nd->setNextSymbolPointer(head);
            head = nd;
            curr = nd;
            cur_pos = 0;
            len++;
        }
        else
        {
            SymbolInfo *node = new SymbolInfo;
            int ind = setToPos(cur_pos - 1);
            node->setName(item.getName());
            node->setType(item.getType());
            node->setNextSymbolPointer(curr->getNextSymbolPointer());
            curr->setNextSymbolPointer(node);
            curr = node;
            cur_pos++;
            len++;
        }
    }

    void pushBack(SymbolInfo &item)
    {
        if (head == NULL)
        {
            head = new SymbolInfo;
            head->setName(item.getName());
            head->setType(item.getType());
            tail = head;
            curr = head;
            tail->setNextSymbolPointer(NULL);
            cur_pos = 0;
            len++;
        }
        else
        {
            SymbolInfo *node = new SymbolInfo;
            node->setName(item.getName());
            node->setType(item.getType());
            tail->setNextSymbolPointer(node);
            tail = node;
            tail->setNextSymbolPointer(NULL);
            len++;
        }
    }

    bool erase()
    {
        // deletes the curr pointer.sets cur_pos and curr exacty before the old curr pointer
        if (head)
        {
            SymbolInfo *temp = new SymbolInfo;
            SymbolInfo *prev = new SymbolInfo;
            temp = head;
            prev = head;
            if (cur_pos == 0)
            {
                SymbolInfo* val;
                val->setName(temp->getName());
                val->setType(temp->getType());

                len--;

                if (len > 0)
                {
                    head = head->getNextSymbolPointer();
                }
                else
                {
                    head = NULL;
                    tail = NULL;
                }

                curr = head;
                free(temp);
                return true;
            }
            else
            {
                for (int i = 0; i <= cur_pos; i++)
                {

                    if (i == cur_pos && temp)
                    {
                        SymbolInfo* val;
                        val->setName(curr->getName());
                        val->setType(curr->getType());
                        prev->setNextSymbolPointer(temp->getNextSymbolPointer());
                        curr = temp->getNextSymbolPointer();

                        if (cur_pos == len - 1 && len > 1)
                            int x = setToPos(cur_pos - 1);

                        len--;
                        free(temp);
                        return true;
                    }
                    else
                    {
                        prev = temp;
                        if (prev == NULL)
                            break;
                        temp = temp->getNextSymbolPointer();
                    }
                }
            }
        }
        return false;
    }

    void setToBegin()
    {
        cur_pos = 0;
        curr = head;
    }

    void setToEnd()
    {
        curr = tail;
        cur_pos = len - 1;
    }

    void prev()
    {
        if (cur_pos > 0)
            int x = setToPos(cur_pos - 1);
    }

    void next()
    {
        if (cur_pos < len - 1)
            int x = setToPos(cur_pos + 1);
    }

    int currPos()
    {
        return cur_pos;
    }

    SymbolInfo getValue()
    {
        SymbolInfo sm;
        sm.setName(curr->getName());
        sm.setType(curr->getType());
        return sm;
    }

    int find(SymbolInfo& x)
    {
        int count = 0;
        SymbolInfo *temp = head;

        while (temp != NULL)
        {
            if (temp->getName() == x.getName() && temp->getType() == x.getType())
                return count;
            count++;
            temp = temp->getNextSymbolPointer();
        }
        return -1;
    }

    void clear()
    {

        while (head != NULL)
        {
            curr = head;
            head = head->getNextSymbolPointer();
            free(curr);
        }

        curr = NULL;
        head = NULL;
        tail = NULL;

        len = 0;
        cur_pos = 0;
    }
    SymbolInfo* getCurrent(){
        return curr;
    }
    void print(ofstream &out)
    {
        out << "-->> ";

        SymbolInfo *tmp = head;

        for (int i = 0; i < len; i++)
        {
            out << "<" << tmp->getName() << "," << tmp->getType() << "> ";
            tmp = tmp->getNextSymbolPointer();
        }

        out << endl;
    }
};