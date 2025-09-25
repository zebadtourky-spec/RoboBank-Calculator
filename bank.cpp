
#include "source.h"
string name;
int phonenum;
float balance;
//Create Account
void CreateAccount(){

    cout<<"Enter your name "<<endl;
    cin>>name;
    cout<<"Enter your phonenum "<<endl;
    cin>>phonenum;

    do {
        cout <<"Enter balance(initial deposit must be at least 100)\n";
        cin >> balance;

    if (balance<100){
        cout<<"try again!(initial deposit must be at least 100)\n";
    }
    } while (balance < 100);

    cout<<"Account Created!"<<endl;
}
//deposit
void deposit (){
    float amount;
    cout<<"Enter the amount"<<endl;
    cin>>amount;
    balance+=amount;
    cout<< "your amount has been deposited,your current balance="<<balance <<endl;

}//withdraw
void withdraw (){
    float amount;
    cout<<"Enter the amount"<<endl;
    cin>>amount;
    if (amount <= balance){
    balance-=amount;
    cout<< "your amount has been withdrawn ,your current balance="<<balance <<endl;
}else {
cout <<"there is no enough balance"<<endl;
}
}
