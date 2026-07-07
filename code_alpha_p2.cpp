#include<iostream>
#include<fstream>
#include<string>

using namespace std;

//registration function
void registerUser(){
    string username,password;
    cout<<"\nEnter Username:";
    cin>>username;

    cout<<"Enter Password:";
    cin>>password;
    ifstream checkFile(username + ".txt");
    if (checkFile)
    {
        cout<<"Username already exists! \n";
        checkFile.close();
        return;
    }
    checkFile.close();

    ofstream file(username +".txt");
    file << username << endl;
    file << password << endl;
    file.close();

    cout<<"Regitration Successful!\n";
}

// Login Function
void LoginUser(){
    string username,password;
    string storedUsername,storedPassword;

    cout<<"\nEnter Username:";
    cin>>username;

    cout<<"Enter Password:";
    cin >> password;

    ifstream file(username + ".txt");

    if(!file){
        cout<<"User not found!\n";
        return;
    }

    getline(file,storedUsername);
    getline(file,storedPassword);

    file.close();

    if(username == storedUsername && password == storedPassword){
        cout<<"Login Successful!\n";
    }
    else
    {
       cout<<"Incorrect Password!\n";       
    }
}

int main(){
 
    int choice;
    do{
        cout<<"\n=====LOGIN SYSTEM =====\n";
        cout<<"1.Register\n";
        cout <<"2.Login\n";
        cout<<"3.Exit\n";
        cout<<"Enter Choice:";
        cin>>choice;

        switch(choice){
            case 1:
            registerUser();
            break;

            case 2:
            LoginUser();
            break;

            case 3:
            cout<<"Thank You!\n";
            break;

            default:
            cout<<"Invalid Choice!\n";

        }
    }while(choice !=3);

    return 0;
}