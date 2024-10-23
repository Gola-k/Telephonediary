#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <iomanip>
#include <string.h>
#include <stdio.h>

using namespace std;
const char *fileName = "phone.dat";
class Person
{
private:
    int ID;
    char Name[20], Address[50], Phone[10], Mobile[10], Email[30];

public:
    void ReadData();
    int GetID();
    void DisplayRecord();
    char *GetMobile();
    char *GetName();
};
void Person::ReadData()
{
    cout << endl
         << "ID:";
    cin >> ID;
    cout << "Name:";
    cin >> Name;
    cout << "Address:";
    cin >> Address;
    cout << "Phone:";
    cin >> Phone;
    cout << "Mobile:";
    cin >> Mobile;
    cout << "Email:";
    cin >> Email;
}
void Person::DisplayRecord()
{
    cout << endl
         << "______________________________________________";
    cout << endl
         << setw(4) << ID << setw(10) << Name << setw(10) << Address << setw(10) << Phone << setw(10) << Mobile << setw(15) << Email;
}

int Person::GetID()
{
    return ID;
}

char *Person::GetMobile()
{
    return Mobile;
}

char *Person::GetName()
{
    return Name;
}

int main()
{
    Person p, p1, tempPerson, prs[100];  // Renamed 'temp' to 'tempPerson'
    char option, ch, Mobile[10], Name[10];
    int ID, isFound;
    fstream file;
    file.open(fileName, ios::ate | ios::in | ios::out | ios::binary);
    int counter = 0, recordNo = 0;
    char tempFile[15];        // Declare tempFile here
    fstream temp;             // Declare fstream temp here
    int location = 0;         // Declare location here

    do
    {
        cout << "****Welcome to telephone diary system****" << endl;
        cout << "**********Menu**********";
        cout << endl
             << "Enter your option";
        cout << endl
             << " 1 => Add a new contact";
        cout << endl
             << " 2 => Search contact information from name";
        cout << endl
             << " 3 => Search contact information form mobile";
        cout << endl
             << " 4 => Display all contact information";
        cout << endl
             << " 5 => Update particular contact on the basis of ID";
        cout << endl
             << " 6 => Delete contact on the basis of ID";
        cout << endl
             << " 7 => Exit from the program" << endl;
        cout << "********************" << endl;
        cin >> option;
        switch (option)
        {
        case '1':
            p.ReadData();
            file.seekg(0, ios::beg);
            isFound = 0;
            file.read((char *)&p1, sizeof(p1));
            while (!file.eof())
            {
                if (strcmp(p1.GetMobile(), p.GetMobile()) == 0)
                {
                    cout << "The contact having this mobile no. already exists.";
                    isFound = 1;
                    break;
                }
                file.read((char *)&p1, sizeof(p1));
            }
            if (isFound == 1)
                break;
            file.clear();
            file.seekp(0, ios::end);
            file.write((char *)&p, sizeof(p));
            cout << endl
                 << "New contact has been added successfully...";
            break;

        case '2':
            isFound = 0;
            cout << endl
                 << "Enter name to be searched:";
            cin >> Name;
            file.seekg(0, ios::beg);
            file.read((char *)&p1, sizeof(p1));
            while (!file.eof())
            {
                if (strcmp(p1.GetName(), Name) == 0)
                {
                    cout << setw(4) << "ID" << setw(10) << "Name" << setw(10) << "Address" << setw(10) << "Phone" << setw(10) << "Mobile" << setw(15) << "Email";
                    p1.DisplayRecord();
                    isFound = 1;
                    break;
                }
                file.read((char *)&p1, sizeof(p1));
            }
            file.clear();
            if (isFound == 0)
                cout << endl
                     << "Contact not found with the name " << Name;
            break;

        case '3':
            isFound = 0;
            cout << endl
                 << "Enter mobile number to know about this:";
            cin >> Mobile;
            file.seekg(0, ios::beg);
            file.read((char *)&p1, sizeof(p1));
            while (!file.eof())
            {
                if (strcmp(p1.GetMobile(), Mobile) == 0)
                {
                    cout << "The contact information for this mobile number";
                    cout << endl
                         << setw(4) << "ID" << setw(10) << "Name";
                    cout << setw(10) << "Address" << setw(10) << "Phone";
                    cout << setw(10) << "Mobile" << setw(15) << "Email";
                    p1.DisplayRecord();
                    isFound = 1;
                    break;
                }
                file.read((char *)&p1, sizeof(p1));
            }
            file.clear();
            if (isFound == 0)
                cout << endl
                     << "Contact not found for mobile number " << Mobile;
            break;

        case '4':
            cout << endl
                 << "*****All Contacts******";
            file.clear();
            file.seekg(0, ios::beg);
            counter = 0;
            file.read((char *)&p1, sizeof(p1));
            while (!file.eof())
            {
                prs[counter] = p1;
                counter++;
                if (counter == 1)
                {
                    cout << endl
                         << setw(4) << "ID" << setw(10) << "Name";
                    cout << endl
                         << setw(10) << "Address" << setw(10) << "Phone";
                    cout << endl
                         << setw(10) << "Mobile" << setw(15) << "Email";
                }
                file.read((char *)&p1, sizeof(p1));
            }
            for (int i = 0; i < counter; i++)
            {
                for (int j = i + 1; j < counter; j++)
                {
                    if (strcmp(prs[i].GetName(), prs[j].GetName()) > 0)
                    {
                        tempPerson = prs[i];  // Use tempPerson for swapping
                        prs[i] = prs[j];
                        prs[j] = tempPerson;
                    }
                }
            }
            for (int i = 0; i < counter; i++)
                prs[i].DisplayRecord();
            cout << endl
                 << counter << " record(s) found.....";
            file.clear();
            break;

        case '5':
            recordNo = 0;
            cout << endl
                 << "Enter ID of person to be updated:";
            cin >> ID;
            isFound = 0;
            file.seekg(0, ios::beg);
            file.read((char *)&p1, sizeof(p1));
            while (!file.eof())
            {
                recordNo++;
                if (p1.GetID() == ID)
                {
                    cout << endl
                         << "The old record of person having ID " << ID << " is:";
                    p1.DisplayRecord();
                    isFound = 1;
                    break;
                }
                file.read((char *)&p1, sizeof(p1));
            }

            if (isFound == 0)
            {
                cout << endl
                     << "Contact not found for ID#" << ID;
                break;
            }
            file.clear();
            location = (recordNo - 1) * sizeof(p1);  // Update location here
            file.seekp(location, ios::beg);
            cout << endl
                 << "Enter new record for person having ID " << ID;
            p1.ReadData();
            file.write((char *)&p1, sizeof(p1));
            break;

        case '6':
            recordNo = 0;
            cout << endl
                 << "Enter Person ID to be deleted:";
            cin >> ID;
            isFound = 0;
            file.seekg(0, ios::beg);
            file.read((char *)&p1, sizeof(p1));
            while (!file.eof())
            {
                recordNo++;
                if (p1.GetID() == ID)
                {
                    cout << endl
                         << "The old contact having ID " << ID << " is:";
                    p1.DisplayRecord();
                    isFound = 1;
                    break;
                }
                file.read((char *)&p1, sizeof(p1));
            }
            strcpy(tempFile, "temp.dat");  // Update tempFile here
            file.clear();
            temp.open(tempFile, ios::out | ios::binary);
            if (isFound == 0)
                cout << endl
                     << "Person not found for ID#" << ID;
            else
            {
                file.seekg(0, ios::beg);
                file.read((char *)&p1, sizeof(p1));
                while (!file.eof())
                {
                    if (p1.GetID() != ID)
                    {
                        temp.write((char *)&p1, sizeof(p1));  // Use fstream temp for file operations
                    }
                    file.read((char *)&p1, sizeof(p1));
                }
                file.close();
                temp.close();
                remove(fileName);
                rename(tempFile, fileName);
                file.open(fileName, ios::ate | ios::in | ios::out | ios::binary);
                cout << endl
                     << "The contact with ID " << ID << " has been deleted.";
            }
            break;

        case '7':
            exit(0);
        }

        cout << endl
             << "Press any key to continue...";
        cin >> ch;

    } while (1);
    file.close();
    return 0;
}
