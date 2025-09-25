#include <iostream>
#include "source.h"
#include <string>
using namespace std;
int main()
{ int Choice;
 CreateAccount();
 cout<<"Enter your Choice"<<endl;
 cout<<"1:deposit\n";
 cout <<"2:withdraw\n";
 cout<<"3:Exit\n";
 cin>>Choice;
 if (Choice==1){
    deposit();
 }
 else if (Choice==2){
    withdraw();
 }
 else if (Choice==3){
   cout<<"Exiting program";
 }
 else {
    cout <<"invalid choice"<<endl;
 }
    return 0;
}
