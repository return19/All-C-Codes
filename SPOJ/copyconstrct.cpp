#include<iostream>
using namespace std;

class first
{
 int i,j,k;
 public:
 first()
 {
   i=j=k=0;
 }

 first(int i,int j,int k)
 {
     this->i=i;
     this->j=j;
     this->k=k;
 }

 first(first& c)
 {  cout<<"\nCopy constrctr called\n";
     i=c.i;
     j=c.j;
     k=c.k;
 }

 first& operator=(first &a)
 {
     cout<<"\nequal invoked\n";
     i=a.i;
     j=a.j;
     k=a.k;
     return *this;
 }

 void display()
 {
     cout<<"\n"<<i<<" "<<j<<" "<<k<<endl;
 }
};

int main()
{
  first a(1,2,3),x(3,6,1);
  first b=a=x;
  b.display();
  a.display();




  return 0;

}




