#include<iostream>
#include<cstring>
using namespace std;

class Vector
{
    char *name;
    int x,y,z;
public:
    Vector(char *n)
    {
        int l = strlen(n);
        name = new char[l+1];
        strcpy(name,n);
        x=0;
        y=0;
        z=0;
    }
    Vector(char *n, int a, int b, int c)
    {
        int l = strlen(n);
        name = new char[l+1];
        strcpy(name,n);
        x=a;
        y=b;
        z=c;
    }

    int setX(int a)
    {
        x=a;
    }

    int setY(int b)
    {
        y=b;
    }
    int setZ(int c)
    {
        z=c;
    }

    void setName(char *n)
    {
        int l = strlen(n);
        name = new char[l+1];
        strcpy(name,n);
    }

    int getX()
    {
        return x;
    }

    int getY()
    {
        return y;
    }

    int getZ()
    {
        return z;
    }

    char *getName()
    {
        return name;
    }

    ~Vector()
    {
        delete []name;
    }




    Vector operator ^(Vector & v)
    {
        Vector temp("temp");

        temp.setX( y*v.getZ() - z*v.getY() );
        temp.setY( z*v.getX() - x*v.getZ() );
        temp.setZ( x*v.getY() - y*v.getX() );


        return temp;

    }

    void operator =(Vector  v)
    {

        x=v.getX();
        y=v.getY();
        z=v.getZ();

    }


    bool operator ==(Vector & v)
    {
        return (x==v.getX())&&(y==v.getY())&&(z==v.getZ());
    }

    Vector operator *(int n)
    {
        Vector temp("temp");
        temp.setX(n*x);
        temp.setY(n*y);
        temp.setZ(n*z);

        return temp;
    }

    Vector operator *(Vector & v)
    {
        Vector temp("temp");
        temp.setX(v.getX()*x);
        temp.setY(v.getY()*y);
        temp.setZ(v.getZ()*z);

        return temp;
    }

    friend ostream & operator <<(ostream & out,Vector & v);
    friend Vector operator *(int n,Vector & v);

};

ostream & operator <<(ostream & out,Vector & v)
{
    out<<v.getName()<<": "<<v.getX()<<"x"<<showpos<<v.getY()<<"y"<<v.getZ()<<"z"<<noshowpos<<endl;
    return out;
}

Vector operator *(int n,Vector & v)
{
    Vector temp("temp");
    temp.setX( n*v.getX() );
    temp.setY( n*v.getY() );
    temp.setZ( n*v.getZ() );

    return temp;
}


int main()
{
    Vector v1("v1", 1,2,3), v2("v2", 4, 5, -6), v3("Result1"),v4("Result2",-27,18,-3);

    cout << v1;     //Print the components of vector v1
    cout << v2;     //Print the components of vector v2

    v3=v1^v2;       //Calculate the cross product of vector v1 and vector v2 (Consider ^ as cross product for this assignment)
    cout << v3;     //Print the modified components of vector v3 (Name: Result1)

    if(v3==v4)      //Check for equality; if two vectors contain equal component values (x, y, z), then they are equal
        cout<<"Vectors are equal"<<endl;
    else
        cout<<"Vectors are not equal"<<endl;

    v1= v1*2;       //Multiply each component of vector v1 with the given value
    cout << v1;     //Print the modified components of vector v1

    v2=2*v2;        //Multiply each component of vector v2 with the given value
    cout << v2;     //Print the modified components of vector v2

    v3=v1*v2;       //Multiply each component of vector v1 with the corresponding component of vector v2
    cout << v3;     //Print the modified components of vector v3 (Name: Result1)

    if(v3==v4)      //Check for equality; if two vectors contain equal component values (x, y, z), then they are equal
        cout<<"Vectors are equal"<<endl;
    else
        cout<<"Vectors are not equal"<<endl;

    return 0;
}

/* Output:
v1: 1x+2y+3z
v2: 4x+5y-6z
Result1: -27x+18y-3z
Vectors are equal
v1: 2x+4y+6z
v2: 8x+10y-12z
Result1: 16x+40y-72z
Vectors are not equal
*/
