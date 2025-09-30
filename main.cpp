#include <iostream>
#include <string>
#include <map>
#include "cal.h"
using namespace std;

int main() { char continu;
    map<string,double> fx_table = { {"USD",1.0}, {"EUR",0.91}, {"GBP",0.78}, {"EGP",30.0} };
    bool Rounding;

    do { int choice;

        cout << "========= RoboBank Calculator========"<<endl;
        cout << "1)Deposit\n2)Withdrawal\n3)Fee\n4)Simple Interest\n5)Compound Interest\n6)Currency Conversion\n7)Utilities\n";
        cout << "Enter your choice:";
         cin >> choice;

        int balance,base, principal, days, years, compounds_per_year,fee, converted;
        double rate, apr,interest,amount, portion;
        string  from_currency, to_currency;

        switch(choice) {
    //================Deposit=================//
            case 1:
                cout << " Enter Balance: ";
                cin >> balance;
                cout << "Enter Amount: ";
                 cin >> amount;
                if(validate_non_negative(amount)){
               balance=apply_deposit(balance,amount );
                cout << "Balance after Deposit:" << balance <<endl;}
                else cout << "Invalid amount!(Enter a positive amount)"<<endl;
                break;
    //==================== Withdrawal==================//
            case 2:
                cout << "Balance: ";
                cin >> balance;
                cout << "Withdrawal amount: ";
                cin >> amount;
                if(validate_non_negative(amount)){
               balance= apply_withdrawal(balance,amount);

                    cout << "Balance after Withdrawal:" << balance <<endl;}
                else cout << "Invalid amount!(Enter a positive amount)\n";
                break;
    //=====================Fee====================//
            case 3:
                cout << "Enter Balance:";
                cin >> balance;
                cout << "Enter Fee:";
                cin >> fee;
               balance=apply_fee(balance,fee);
                cout << "Balance after fee: " <<balance <<endl;
                break;
    //======================Simple Interest===============//
            case 4:
                cout << "Enter Base: ";
                cin >> base;
                cout << "Enter Apr from (0 to 1): ";
                cin >> apr;
                if(!validate_rate(apr))
                { cout << "Invalid Apr!\n";
                break;}
                cout << "Enter Days: ";
                cin >> days;
                cout<<"enter [1] for a Half Up or [0] for a Half Even"<<endl;
                cin>>Rounding;

               interest = simple_interest(base, apr, days, 365, Rounding);
                    cout << "Interest: " << interest <<endl;

                break;
    //====================== Compound Interest=============//
            case 5:
                cout << "Principal:";
                cin >> principal;
                cout << "Apr:";
                 cin >> apr;
                 if(!validate_rate(apr)){ cout << "Invalid Apr!\n";

                break;}
                cout << "Years:";
                cin >> years;
                cout << " Enter Compounds_per_year: ";
                cin >> compounds_per_year;
               cout<<"enter [1] for a Half Up or [0] for a Half Even"<<endl;
                cin>>Rounding;
               amount= compound_amount(principal, apr, years, compounds_per_year, Rounding);

                    cout << "Total amount after " << years << " years=" << amount <<endl;

                break;
    //================== Currency Conversion================//
            case 6:
                cout << "Amount: ";
                cin >> amount;
                cout << "From_currency (USD, EUR, GBP, EGP): ";
                 cin >> from_currency;
                cout << "To_currency: ";
                cin >> to_currency;
                 cout<<"enter [1] for a Half Up or [0] for a Half Even"<<endl;
                cin>>Rounding;
                if(validate_non_negative(amount)) {
                  converted= fx_convert(amount, from_currency, to_currency, fx_table,Rounding );
                    if(converted==0)
                    cout << "Currency not found!\n";
                    else cout << "Converted amount=" << converted<<endl;
                } else cout << "Invalid amount! Try again\n";
                break;
    //=====================Utilities=================//
                case 7:

              cout << "Enter amount: "<<endl;
              cin >> amount;
                          if(!validate_non_negative(amount)) {
   cout << "Invalid amount!(Enter a positive amount)\n";
   break;
}
               cout << "Enter rate: "<<endl;
               cin >> rate;
           if(!validate_rate(rate)){
                cout<<"Invalid Rate! Try again\n"<<endl;
                  break;}

                cout<<"enter [1] for a Half Up or [0] for a Half Even"<<endl;
                cin>>Rounding;


        portion = percent_of(amount, rate, Rounding);
         cout << "Percent of " << amount << "@" << rate*100 << "% = " <<portion<<endl;
         break;

            default:
                cout << "Invalid choice! Try again\n";}

        cout << "IF you want to continue Enter c:";
        cin >> continu;

    } while(continu=='c');

    cout << "Thanks for using RoboBank Calculator!"<<endl;
    return 0;
}
