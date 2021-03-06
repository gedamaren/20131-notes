#include <iostream>
using namespace std;

class Base{
  int
    data;
public:
  Base(int data = 0){
    this->data = data;
    cout<<"Creating Base with "<<data<<endl;
  }
  void Act(void){
    cout<<"Acts like a Base"<<endl;
  }
  int Data(){
    return data;
  }
  ostream &print(ostream &os){
    return os<<"Printing: "<<data;
  }
  ~Base(){
    cout<<"Base is gone..."<<endl;
  }
};

ostream &operator<<(ostream &os, Base &B){
  return B.print(os);
}

class Derived:public Base{
public:
  Derived(int data):Base(data*100){
    cout<<"Creating Derived with "<<Data()<<endl;
  }
  void Act(void){
    cout<<"Acts like a Derived."<<endl;   
  }
  ~Derived(){
    cout<<"Derived with "<<Data()<<" is gone."<<endl;
  }
};
int main(void){
  Derived d(100);
  d.Act();
  cout<<d<<endl;

  Base* bp = new Derived(10);
  bp->Act();
  cout<<(*bp)<<endl;
  delete bp;
  return 0;
}
