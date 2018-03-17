#include<iostream>
#include<cstdlib>
#include<cstring>
#include<new>
using namespace std;
const int FREE=0;
const int BUSY=1;
const int MAX=5;


class emp
{
    int sal;
    char name[];
public:
    emp()
    {
        sal=0;
        strcpy(name,"");

    }

    emp(char a[],int b)
    {
        strcpy(name,a);
        sal=b;
    }

    void setdata(char a[],int b)
    {
        strcpy(name,a);
        sal=b;
    }
    void display()
    {
        cout<<name;
        cout<<sal<<endl;
    }
    void * operator new(size_t sz);


    void operator delete(void *q);

};

struct pool
{
    emp e;
    int status;
};

struct pool *p=NULL;
int flag=0;

void memwarn()
{
    cout<<"Free store limit reached";
    exit(1);
}

 void * emp:: operator new(size_t sz)
    { int i;
        if(flag==0)
        {   p=(pool*)malloc(sz*MAX);
            if(p==NULL)
            memwarn();
            for(i=0;i<MAX;i++)
            {
                p[i].status=FREE;
            }
            p[0].status=BUSY;
            return &p[0].e;
        }
        else
        {
            for(i=0;i<MAX;i++)
            {
                if(p[i].status==FREE)
                {
                    p[i].status=BUSY;
                    return &p[i].e;
                }
            }
        }
        memwarn();
    }

    void emp::operator delete(void *q)
    {int i;
        if(q==NULL)
            memwarn();
            for(i=0;i<MAX;i++)
            {
                if(&p[i].e==q)
                {
                    p[i].status=FREE;
                    p[i].e.sal=0;
                    strcpy(p[i].e.name,"");
                }
            }
    }

int main()
{
    emp *e1,*e2,*e3,*e4,*e5;
    e1=new emp;
    e2=new emp;
    e3=new emp;
    e4=new emp;
    e5=new emp;
    e1->setdata("e1",10);
    e2->setdata("e2",20);
    e3->setdata("e3",30);
    e4->setdata("e4",40);
    e5->setdata("e5",50);
    e1->display();
    e2->display();
    e3->display();
    e4->display();
    e5->display();
return 0;
}





