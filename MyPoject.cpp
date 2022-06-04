#include <iostream>
#include <vector>
#include <stdlib.h>
#include <windows.h>
using namespace std;
int counter = 0;
void MainMenu();

class contact
{

    vector<string> name;
    vector<string> phoneNumber;
    vector<string> email;
    vector<string> address;
    vector<string> fname;
    vector<string> fphoneNumber;
    vector<string> femail;
    vector<string> faddress;

public:
    void addContact() //for add  contact number
    {
        string num, ph, mail, adr;
        cout << "\n\t\t\tName        : ";
        fflush(stdin);
        getline(cin, num);
        name.push_back(num);
        cout << "\n\t\t\tPhone Number: ";
        fflush(stdin);
        getline(cin, ph);
        phoneNumber.push_back(ph);
        cout << "\n\t\t\tEmail       : ";
        fflush(stdin);
        getline(cin, mail);
        email.push_back(mail);
        cout << "\n\t\t\tAddress     : ";
        fflush(stdin);
        getline(cin, adr);
        address.push_back(adr);
        counter++;
        cout << "\n\t\t\tSaved!!" << endl;
        Sleep(1000);
        char a;
        cout << "\n\t\t\tIf you want to save it as Favourite Press -Y/N :  ";
        cin >> a;
        if (a == 'y' || a == 'Y')
        {
            fname.push_back(num);
            fphoneNumber.push_back(ph);
            femail.push_back(mail);
            faddress.push_back(adr);
            cout << "\n\t\t\tSave it as Favourite";
        }
        Sleep(1000);
        system("CLS");
        MainMenu();
    }

    void showAllContact() //For show contact
    {
        int c = 0;
        cout << "\n\t\t-------------All Contact List----------------" << endl
             << endl;
        for (int i = 0; i < name.size(); i++)
        {
            c++;
            cout << "\n\t\t\tName         : " << name[i] << endl;
            cout << "\n\t\t\tPhone Number : " << phoneNumber[i] << endl;
            cout << "\n\t\t\tEmail        : " << email[i] << endl;
            cout << "\n\t\t\tAddress      : " << address[i] << endl;
            cout << "\n\n";
        }
        if (c == 0)
            cout << "\n\t\t\t There is no contact !!!" << endl;

        MainMenu();
    }
    void showFavourite() // for show only favourite conatact number
    {
        int c = 0;
        cout << "\n\t\t----------Favourite Contact List----------------" << endl
             << endl;
        for (int i = 0; i < fname.size(); i++)
        {
            c++;
            cout << "\n\t\t\tName         : " << fname[i] << endl;
            cout << "\n\t\t\tPhone Number : " << fphoneNumber[i] << endl;
            cout << "\n\t\t\tEmail        : " << femail[i] << endl;
            cout << "\n\t\t\tAddress      : " << faddress[i] << endl;

            cout << "\n\n";
        }
        if (c == 0)
        {
            cout << "\n\t\t\t There is no favourite contact !!!" << endl;
        }

        MainMenu();
    }
    void search() //for search a contact number
    {
        string check, ch;
        cout << "\n\t\t\tEnter Name = ";
        fflush(stdin);
        cin >> ch;
        check = ch;
        int ct = 0;
        for (int i = 0; i < name.size(); i++)
        {
            if (check == name[i])
            {
                cout << "\n\t\t-------------Its found---------------- " << endl;
                cout << "\n\t\t\tName         : " << name[i] << endl;
                cout << "\n\t\t\tPhone Number : " << phoneNumber[i] << endl;
                cout << "\n\t\t\tEmail        : " << email[i] << endl;
                cout << "\n\t\t\tAddress      : " << address[i] << endl;
                ct++;
            }
        }
        if (ct == 0)
            cout << "\n\t\t\tIts not Found !!" << endl;
        MainMenu();
        exit(1);
    }

    void edit() //for edit contact number
    {
        fflush(stdin);     
        string check, ch, newName, newPhoneNumber, newEmail, newAddress;

        int ct = 0;
        if (counter != 0)
        {
            cout << "\n\t\t\tEnter Name = ";
            fflush(stdin);
            getline(cin,ch);
            check = ch;

            for (int i = 0; i < name.size(); i++)
            {

                if (check == name[i])
                {

                    cout << "\n\t\t\tIts Found !!" << endl;
                    cout << "\n\t\t\tNow You Can Edit!!" << endl;
                    cout << "\n\t\t\tName         : ";
                    fflush(stdin);
                    getline(cin, newName);
                    cout << "\n\t\t\tPhone Number : ";
                    fflush(stdin);
                    getline(cin, newPhoneNumber);
                    cout << "\n\t\t\tEmail        : ";
                    fflush(stdin);
                    getline(cin, newEmail);
                    cout << "\n\t\t\tAddress      : ";
                    fflush(stdin);
                    getline(cin, newAddress);
                    ct++;
                    name[i] = newName;
                    phoneNumber[i] = newPhoneNumber;
                    email[i] = newEmail;
                    address[i] = newAddress;
                    for (int i = 0; i < fname.size(); i++) //if the Edited iteam is also a favourite number then favourite is also editable
                    {
                        if (check == fname[i])
                        {
                            fname[i] = newName;
                            fphoneNumber[i] = newPhoneNumber;
                            femail[i] = newEmail;
                            faddress[i] = newAddress;
                        }
                    }
                }
            }
            if (ct == 0)
                cout << "\n\t\t\tIts not Found !!" << endl;
            else
                cout << "\n\t\t\tSuccessfuly Edited";

            Sleep(3000);

            system("CLS");
            MainMenu();
        }
        else
        {

            cout << "\n\t\t\tCan not edit there is no contact Number !" << endl;
            Sleep(2000);
            MainMenu();
        }
    }

    void Delete() //for delete a contact number
    {
        
        if (counter != 0)
        {
            string ch;
            cout << "\n\t\t\tEnter Name = ";
            fflush(stdin);
            getline(cin,ch);
            int ct = 0;
            for (int i = 0; i < name.size(); i++)
            {
                
                if (name[i] == ch)
                {
                    name.erase(name.begin() + i);
                    phoneNumber.erase(phoneNumber.begin() + i);
                    email.erase(email.begin() + i);
                    address.erase(address.begin() + i);
                    ct++;
                    counter--;
                }
            }
            for (int i = 0; i < fname.size(); i++) //If the delete contact is also a favourite conatct thats why
                                                   //i used to delete this loop for delte favourite
            {
                if (fname[i] == ch)
                {
                    fname.erase(name.begin() + i);
                    fphoneNumber.erase(phoneNumber.begin() + i);
                    femail.erase(email.begin() + i);
                    faddress.erase(address.begin() + i);
                }
            }
            if (ct != 0)
                cout << "\n\t\t\tThis is deleted successfuly !!" << endl;
            else
                cout << "\n\t\t\tIts not found" << endl;

            Sleep(3000);
            // exit();
            system("CLS");
            MainMenu();
        }
        else
            cout << "\n\t\t\tIts UnderFlow there is no cantact so you can not delete" << endl;
        MainMenu();
    }

    void DeleteAll() //for delete all contact numnber
    {
        while (!name.empty())
        {
            name.pop_back();
            phoneNumber.pop_back();
            email.pop_back();
            address.pop_back();
        }
        counter = 0;
        cout << "\n\t\t------Delete All Conatct successfuly----!!" << endl;
        //Sleep(5000);
        MainMenu();
    }
    void totalNumber()
    {
        cout << "\n\t\t\tThe Totall Contact Number is = " << counter << endl;
        MainMenu();
    }
};
contact ob;

void MainMenu() //Main Menu for Dispaly
{

    cout << "\n\n\n\t\t**Welcome to contact management system***" << endl;
    cout << "\n\t\t\t 1: Add Contact" << endl;
    cout << "\n\t\t\t 2: Show All Contact" << endl;
    cout << "\n\t\t\t 3: Show Favourite Contact list" << endl;
    cout << "\n\t\t\t 4: Search a Contact" << endl;
    cout << "\n\t\t\t 5: Edit Contact" << endl;
    cout << "\n\t\t\t 6: Delete Contact" << endl;
    cout << "\n\t\t\t 7: Delete All Contact" << endl;
    cout << "\n\t\t\t 8: Show totall Numbber of Contact" << endl;
    cout << "\n\t\t\t 9: Exit" << endl;
    cout << "\n\t\t\tPress Some one : ";
    short int a;

    cin >> a;
    switch (a)
    {
    case 1:
        ob.addContact();
        break;
    case 2:
        ob.showAllContact();
        break;
    case 3:
        ob.showFavourite();
    case 4:
        ob.search();
        break;
    case 5:
        ob.edit();
        break;
    case 6:
        ob.Delete();
        break;
    case 7:
        ob.DeleteAll();
        break;
    case 8:
        ob.totalNumber();
        break;
    case 9:
        cout << "\n\t\t\tThank you for Using !" << endl;
        break;
    default:
        cout << "\n\t\t\tYou Type Wrong " << endl;
        cout << "\n\t\t\tPlease Enter Valid Number !" << endl;
        MainMenu();
        break;
    }
}

int main()
{
    system("color 3F");
    cout << "\n\n\n\t\t loaading please wait...\t"; //for loading bar
    char x = 219;
    for (int i = 0; i <= 60; i++)
    {
        if (i < 20)
        {
            cout << x;
            Sleep(200);
        }
        else if (i > 20 && i <= 40)
        {
            cout << x;
            Sleep(100);
        }
        else if (i > 40 && i <= 40)
        {
            cout << x;
        }
    }
    system("CLS");

    MainMenu();
}