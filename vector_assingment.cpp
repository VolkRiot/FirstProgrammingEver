#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <strings.h>
#include <math.h>

using namespace std;
struct Employees
{
    char emp_id[6];
    char last_name[20];
    char first_name[30];
    float hours;
    float pay_rate;
    float tax;
    int dependents;
};
void Display (Employees);
void ChangeFields (Employees& , int);

int Menu()
{
    int selection = 0;

    while((selection < 1) || (selection > 7))
          {
            system("CLS");
            cout << "1 - Display all Records" << endl;
            cout << "2 - Find a record based on Employee ID " << endl;
            cout << "3 - Sort the records based on Last Name " << endl;
            cout << "4 - Delete a record based on Employee ID " << endl;
            cout << "5 - Change one or more of the fields (found with Employee ID) " << endl;
            cout << "6 - Add a new record to the vector" << endl;
            cout << "7 - Quit" << endl;
            cout << "Choice: ";
            cin >> selection;
          }
        system("CLS");
    return selection;

}
void DatatoVector (vector<Employees>& emp_array)
{
    ifstream inFile("personnel.dat", ios::in);
    Employees temp;

    if(!inFile)
    {
        system("CLS");
        cout << "Sorry but personnel.dat was not found..." << endl;
        system("PAUSE");
    }
    else
    {
        while(!inFile.eof())
        {
            temp.hours = -9;
            inFile >> temp.emp_id >> temp.last_name >> temp.first_name >> temp.hours >> temp.pay_rate >> temp.tax >> temp.dependents;
            if (temp.hours != -9)
            {
            emp_array.push_back(temp);
            }
        }
    }
    inFile.close();
}
int Find_ID (vector<Employees>& emp_array, string search_str, bool& confirmed)
{
    char tofind[6];
    int n;

    for (n=0; n<6; n++)
    {
        tofind[n] = toupper(search_str[n]);
    }

    for (n=0; n < emp_array.size(); n++)
    {
        string char_array = emp_array[n].emp_id;
        string searching = tofind;

        if (char_array == searching)
        {
            confirmed = true;
            return n;
        }
    }
    return 0;
}
void SelectFields (Employees& emp, bool& confirmed)
{
    int choice;

    choice = 0;
    while ((choice < 1) || (choice > 9))
           {
                cout << "\n1 - Change Employee ID" << endl;
                cout << "2 - Change Last Name" << endl;
                cout << "3 - Change First Name" << endl;
                cout << "4 - Change Hours" << endl;
                cout << "5 - Change Pay Rate" << endl;
                cout << "6 - change Income Tax" << endl;
                cout << "7 - Change Number of Dependents" << endl;
                cout << "8 - Change ALL" << endl;
                cout << "9 - Exit back to Main Menu" << endl;
                cout << "Choice: ";
                cin >> choice;
                system("CLS");
           }
    if (choice == 9)
    {
        confirmed = false;
    }
    if (choice == 8)
    {
        for (int n = 1; n <=8; n++)
        {
            ChangeFields(emp, n);
        }
    }
    else
    {
        ChangeFields(emp, choice);
    }


}
void ChangeFields (Employees& emp, int choice)
{
    char temp_char[30];
    float temp_float;
    int temp_int;
    string temp_string = "";

  switch (choice)
    {
    case 1:
        while (temp_string.length() != 5)
        {
            system("CLS");
            cin.ignore(1000, '\n');
            cout << "Enter new Employee ID (5 characters): ";
            cin >> temp_char;

            temp_string = temp_char;
        }
        for (int n=0; n<5; n++)
        {
            temp_char[n] = toupper(temp_char[n]);
        }
        strcpy(emp.emp_id, temp_char);
    break;
    case 2:
        do
        {
            system("CLS");
            cin.ignore(1000, '\n');
            cout << "Enter new Last Name (20 characters max): ";
            cin >> temp_char;

            temp_string = temp_char;
        } while (temp_string.length() > 20);
        strcpy(emp.last_name, temp_char);
    break;
    case 3:
        do
        {
            system("CLS");
            cin.ignore(1000, '\n');
            cout << "Enter new First Name (20 characters max): ";
            cin >> temp_char;

            temp_string = temp_char;
        } while (temp_string.length() > 30);
        strcpy(emp.first_name, temp_char);
    break;
    case 4: //Change Hours:
        cout << "New Employee Hours: ";
        cin >> temp_float;
        temp_float = fabs(temp_float);
        emp.hours = temp_float;
    break;
    case 5: //Change Pay Rate
        cout << "New Employee Pay Rate: ";
        cin >> temp_float;
        temp_float = fabs(temp_float);
        emp.pay_rate = temp_float;
    break;
    case 6: //Change Income Tax
        cout << "New Employee Income Tax: ";
        cin >> temp_float;
        temp_float = fabs(temp_float);
        if (temp_float >= 1)
        {
            temp_float /= 100;
        }
        emp.tax = temp_float;
    break;
    case 7: // Change Dependents
        cout << "New Employee Dependents: ";
        cin >> temp_int;
        temp_int = abs(temp_int);
        emp.dependents = temp_int;
    break;
    system("CLS");
    }
}

void Display (Employees emp) //Display Record based on feed
{
    cout << "Employee ID: " << emp.emp_id << endl;
    cout << emp.last_name << ", " << emp.first_name << endl;
    cout << "Hours: " << emp.hours << endl;
    cout << "Pay Rate: " << emp.pay_rate <<endl;
    cout << "Tax Rate: " << emp.tax * 100 << "%" << endl;
    cout << "Dependents: " << emp.dependents << "\n" << endl;
}
int main()
{
    vector<Employees> emp_array;
    string temp_string;
    bool again = true;
    bool confirmed = false;
    //char temp_char[6];

    DatatoVector(emp_array);
do
{
    switch(Menu())
    {
    case 1:
        for (int n = 0; n < emp_array.size(); n++)
        {
            Display(emp_array[n]);
        }
        system("PAUSE");
    break;
    case 2:
        //Find record based on Emp_ID
        system("CLS");
        cin.ignore(1000, '\n');
        cout << "Enter Employee ID: ";
        cin >> temp_string;

        Find_ID(emp_array, temp_string, confirmed);

        if(confirmed == true)
        {
            system("CLS");
            cout << "Employee ID Discovered\n" << endl;
            Display(emp_array[Find_ID(emp_array, temp_string, confirmed)]);
            system("PAUSE");
        }
        else
        {
            cout << "Sorry, but " << temp_string << " could not be found in the array... " << endl;
            system("PAUSE");
        }
        confirmed = false;
    break;
    case 3:
        //Sort the records based on Last Name
    bool swapped;

    do
    {
        swapped = false;
        for (int n = 0; n < emp_array.size() - 1; n++)
        {
            int x = 0;
            while ((emp_array[n].last_name[x] == emp_array[n + 1].last_name[x]) && (x < 20))
            {
                x++;
            }
            if (emp_array[n].last_name[x] > emp_array[n + 1].last_name[x])
            {
                swap(emp_array[n], emp_array[n + 1]);
                swapped = true;
            }
        }
    }while (swapped == true);
    for (int n = 0; n < emp_array.size(); n++)
        {
            Display(emp_array[n]);
        }
        system("PAUSE");
    break;
    case 4:
        system("CLS");
        cin.ignore(1000, '\n');
        cout << "Enter Employee ID to Delete: ";
        cin >> temp_string;

        Find_ID(emp_array, temp_string, confirmed);

        if(confirmed == true)
        {
            system("CLS");
            cout << "Employee ID Discovered and deleted\n" << endl;
            Display(emp_array[Find_ID(emp_array, temp_string, confirmed)]);
            emp_array.erase(emp_array.begin() + Find_ID(emp_array, temp_string, confirmed));
            system("PAUSE");
        }
        else
        {
            cout << "Sorry, but " << temp_string << " could not be found in the array... " << endl;
            system("PAUSE");
        }
        confirmed = false;
    break;
    case 5:
        //Change one or more of the fields (found with Employee ID)
        system("CLS");
        cin.ignore(1000, '\n');
        cout << "Enter Employee ID to Change Values: ";
        cin >> temp_string;

        Find_ID(emp_array, temp_string, confirmed);
        if(confirmed == true)
        {
            int x = Find_ID(emp_array, temp_string, confirmed);
            do
            {
            system("CLS");
            Display(emp_array[x]);
            SelectFields(emp_array[x], confirmed);

            }while (confirmed == true);
        }
        else
        {
            cout << "Sorry, but " << temp_string << " could not be found in the array... " << endl;
            system("PAUSE");
        }
        //confirmed = false;
    break;
    case 6:
        //Add a new record to the vector
        Employees temp;

        for (int n = 1; n<=8; n++)
        {
            ChangeFields(temp, n);
        }
        emp_array.push_back(temp);
    break;
    case 7:
        //Exit and re-Write File
        ofstream outFile("personnel.dat", ios::out);
        for (int n = 0; n < emp_array.size(); n++)
        {
            outFile << emp_array[n].emp_id << " " << emp_array[n].last_name << " " << emp_array[n].first_name << " " << emp_array[n].hours << " " << emp_array[n].pay_rate << " "  <<emp_array[n].tax << " "  <<emp_array[n].dependents << "\n";
        }
        outFile.close();
        exit(0);
    break;
    }
}while(again == true);
}
