#include <iostream>
#include <cstring>
#include <cstdlib>


using namespace std;

class Student
{
private:
    char *name ;
    int id;
    float credit ;
    float cgpa;

public:
    Student(char *s,int roll, float cr, float cg);
    ~Student ();

    void showInfo();
    void change(int num);
    void change(char *nm);
    void addTermResult(float crdt,float gp);


};


class Batch
{
private:
    int n;
    Student *stud;


public:
    Batch();
    ~Batch();

    void addStudent(Student &ss);
    void showAllStudents();




};


Student::Student(char *s, int roll, float cr, float cg)
{
    name=(char *)malloc((strlen(s)+1)*sizeof(char));

    strcpy(name,s);
    id=roll;
    credit=cr;
    cgpa=cg;


}


Student::~Student ()
{
    free(name);

}




void Student::showInfo()
{
    cout<<"Name:"<<name<<", ";
    cout<<"Id:"<<id<<", ";
    cout<<"Credit completed:"<<credit<<", ";
    cout<<"Cgpa:"<<cgpa<<endl;
}


void Student::change(int num)
{
    id=num;
}


 void Student::change(char *nm)
 {
     free(name);

     name=(char *)malloc((strlen(nm)+1)*sizeof(char));

     strcpy(name,nm);
 }


void Student::addTermResult(float crdt,float gp)
{

    cgpa=(cgpa*credit+gp*crdt)/(credit+crdt);
    credit+=crdt;


}
Batch::Batch()
{
    stud=(Student *)malloc(1200*sizeof(Student));
    n=0;


}



Batch::~Batch()
{
    free(stud);

}



void Batch::addStudent(Student &ss)
{

    *(stud+n)=ss;
    n++;
}


void Batch::showAllStudents()
{
    for(int i=0;i<n;i++)
       (stud+i)->showInfo();


}


int main()
{
 // Part 1
 /*A student class holds the information of the
 student name, id, credit earned so far, and
 cumulative gpa (cgpa)*/
 /*The name of a student is stored using malloc,
 which will be freed during destruction*/
 Student s1("Tamim Iqbal", 1905131, 39, 3.56);
 Student s2("Liton Das", 1905150, 39, 3.52);
 s1.showInfo();
 cout<<"Changing the name of s1"<<endl;
 /*During changing the name, you should reallocate
 memory of the new name and free the previously
 allocated memory*/
 s1.change("Tamim Iqbal Khan");
 s1.showInfo();
 cout<<"Changing the id of s2"<<endl;
 s2.change(1905149);
 s2.showInfo();
 cout<<"Adding a term result of s1"<<endl;
 /*The first argument of addTermResult is the credit
 earned in a term and second one is the gpa obtained
 in that term*/
 s1.addTermResult(19, 3.85);
 s1.showInfo();
 // Part 2
 /*Batch contains a list of students*/
 /*During construction, a Batch object allocates dynamic
 memory for 1200 students using malloc. The memory will
 be freed during destruction*/
 Batch b;
 b.addStudent(s1);
 b.addStudent(s2);
 cout<<"Printing the list of students of the batch b"<<endl;
 b.showAllStudents();
}







