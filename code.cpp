#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;

void login();
void signup();

int main()
{
    int a;
    cout<<"---------------------------------------------------------------------------------\n"<<endl;
    cout<<"\t\t\t Welcome to the Login Page \n"<<endl;
    cout<<"---------------------------------------------------------------------------------\n\n"<<endl;
    cout<<"Select from the following: \n"<<endl;
    cout<<"1. Login"<<endl;
    cout<<"2. Sign up"<<endl;
    cout<<"3. Exit"<<endl;
    cout<<"\nPlease enter your choice: "<<endl;
    cin>>a;
    cout<<endl;

    switch(a)
    {
        case 1:
            login();
            break;

        case 2:  
            signup();
            break;

        case 3:
            cout<<"Thankyou!"<<endl;
            break; 
        default:
            system("cls");
            cout<<"Please select from the options given below\n"<<endl;
            main();
    }
}
void login()
{
    int count;
    string UID, PW, id, pass;
    system("cls");
    cout<<"Enter your username and password\n"<<endl;
    cout<<"\nUsername: "<<endl;
    cin>>UID;
    cout<<"\nPassword"<<endl;
    cin>>PW;

    ifstream input ("details.txt");

    while (input>>id>>pass)
    {
        if (id==UID && pass == PW)
        {
            count=1;
            system("cls");
        }
    }
    input.close();
        if (count == 1)
        {
            cout<<UID<<"\n\nLogin Successful!"<<endl;
        }
        else 
        {
            cout<<"Incorrect username or password"<<endl;
        }
}

void signup()
{
    string rUID, rPW, rid, rpass;
    system("cls");
    cout<<"\nCreate your username: "<<endl;
    cin>>rUID;
    cout<<"\nCreate your password: "<<endl;
    cin>>rPW;

    ofstream file("details.txt", ios::app);
    file<<rUID<<' '<<rPW<<endl;
    system("cls");
    cout<<"\nAccount created successfully!"<<endl;
    main();
}
