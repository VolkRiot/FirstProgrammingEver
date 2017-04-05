#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;
class Employee
{
protected:
string emp_id;
float hours;
float pay_rate;
float tax_rate;
float over_hours;
string emp_status;
float gross_pay;
float taxes;
float net_pay;

public:
Employee()
{
    emp_id = "N/A";
    hours = 0;
    pay_rate = 0;
    tax_rate = 0;
    over_hours = 0;
    emp_status = "N/A";
}
void SetID(string id) {emp_id = id;}
void SetHours(float h) {hours = h;}
void SetPay (float p) {pay_rate = p;}
void SetTaxRate (float tax){tax_rate = tax;}
void SetStatus (string status){emp_status = status;}
string getID(){return emp_id;}
float getHours(){return hours;}
float getPay(){return pay_rate;}
string getStatus(){return emp_status;}
virtual void CalculatePay() = 0;
};
class Hourly: public Employee
{
protected:
    float over_hours;
    float over_pay;
    float reg_hours;
    float reg_pay;
public:
    void CalculatePay()
    {
            if(hours <= 40)
            {
                reg_pay = hours * pay_rate;
                over_hours = 0;
                over_pay = 0;
                reg_hours = hours;
            }
            else
            {
                Overtime();
            }
            gross_pay = reg_pay + over_pay;
            taxes = tax_rate * gross_pay;
            net_pay = gross_pay - taxes;

    cout << "Employee ID: " << emp_id << endl;
    if(over_hours > 0)
    {
        cout << "Regular Hours: " << reg_hours << endl;
        cout << "Overtime Hours: " << over_hours << endl;
    }
    else
    {
        cout << "Total Hours: " << reg_hours << endl;

    }
    cout << "Pay Rate: $" << pay_rate << endl;
    cout << "Regular Pay: $" << reg_pay << endl;
    if(over_hours > 0)
    {
        cout << "Overtime Pay: $" << over_pay << endl;
    }
    cout << "Gross Pay: $" << gross_pay << endl;
    cout << "Taxes Withheld based on %" << (tax_rate * 100) << ": $" << taxes << endl;
    cout << "Net Pay: $" << net_pay << endl;
    cout << "\n\n";
    }
    void Overtime()
    {
        over_hours = hours - 40;
        reg_hours = hours - over_hours;
        reg_pay = reg_hours * pay_rate;
        over_pay = over_hours * pay_rate * 1.5;
    }
};

class Salaried: public Employee
{
public:
    float annual;
public:
    void CalculatePay()
    {
        gross_pay = pay_rate;
        taxes = gross_pay * tax_rate;
        net_pay = gross_pay - taxes;

        cout << "Employee ID: " << emp_id << endl;
        cout << "Annual Salary(Gross): $" << pay_rate << endl;
        cout << "Taxes Withheld based on %" << (tax_rate * 100) << ": $" << taxes << endl;
        cout << "Net Pay: $" << net_pay << endl;
        cout << "\n\n";
    }
};
class Contractor: public Employee
{
    public:
    void CalculatePay()
    {
        gross_pay = pay_rate * hours;
        cout << "Employee ID: " << emp_id << endl;
        cout << "Contractor Fee: $" << pay_rate << endl;
        cout << "Hours Worked: " << hours << endl;
        cout << "Gross Pay: $" << gross_pay << endl;

        cout << "\n\n";
    }
};

int main()
{
const int max = 3;
Hourly hourly[max];
Salaried  salaried[max];
Contractor contractor[max];
int selector = 0;
int count1 = 0, count2 = 0, count3 = 0;

string string_temp;
float float_temp;

bool again = true;
do
{
selector = 0;
while((selector < 1) || (selector > 7))
{
    system("CLS");
    cout << "1 - Enter record for Hourly Employee (up to 3 maximum)" << endl;
    cout << "2 - Enter record for Salaried Employee (up to 3 maximum)" << endl;
    cout << "3 - Enter record for Contractor Employee (up to 3 maximum)" << endl;
    cout << "4 - Display Hourly Employees" << endl;
    cout << "5 - Display Salaried Employees" << endl;
    cout << "6 - Display Contractor Workers" << endl;
    cout << "7 - Quit" << endl;
    cout << "Choice: ";
    cin >> selector;
}
switch(selector)
{
    case 1:
        system("CLS");
        if (count1 < max)
        {
        cin.ignore(1000, '\n');
        cout << "Enter Data for Hourly Employee" << endl;
        cout << "\nEmployee ID: ";
        getline(cin, string_temp);
        hourly[count1].SetID(string_temp);
        cout << "Total Hours Worked: ";
        cin >> float_temp;
        float_temp = fabs(float_temp);
        hourly[count1].SetHours(float_temp);
        cout << "Pay Rate: ";
        cin >> float_temp;
        float_temp = fabs(float_temp);
        hourly[count1].SetPay(float_temp);
        cout << "Income Tax Rate: ";
        cin >> float_temp;
        float_temp = fabs(float_temp);
        hourly[count1].SetTaxRate(float_temp);
        hourly[count1].SetStatus("Hourly");
        count1++;
        }
        else
        {
            cout << "There is a total of 3 Records already in this array" << endl;
            system("PAUSE");
        }
    break;
    case 2:
    system("CLS");
    if (count2 < max)
        {
        cin.ignore(1000, '\n');
        cout << "Enter Data for Salaried Employee" << endl;
        cout << "\nEmployee ID: ";
        getline(cin, string_temp);
        salaried[count2].SetID(string_temp);
        cout << "Annual Salary: ";
        cin >> float_temp;
        float_temp = fabs(float_temp);
        salaried[count2].SetPay(float_temp);
        cout << "Income Tax Rate: ";
        cin >> float_temp;
        float_temp = fabs(float_temp);
        salaried[count2].SetTaxRate(float_temp);
        salaried[count2].SetStatus("Salaried");
        count2++;
        }
        else
        {
            cout << "There is a total of 3 Records already in this array" << endl;
            system("PAUSE");
        }
    break;
    case 3:
 system("CLS");
    if (count3 < max)
        {
        cin.ignore(1000, '\n');
        cout << "Enter Data for Contractor Employee" << endl;
        cout << "\nEmployee ID: ";
        getline(cin, string_temp);
        contractor[count3].SetID(string_temp);
        cout << "Contractor Fee: ";
        cin >> float_temp;
        float_temp = fabs(float_temp);
        contractor[count3].SetPay(float_temp);
        cout << "Total Hours Worked: ";
        cin >> float_temp;
        float_temp = fabs(float_temp);
        contractor[count3].SetHours(float_temp);
        contractor[count3].SetStatus("Contractor");
        count3++;
        }
        else
        {
            cout << "There is a total of 3 Records already in this array" << endl;
            system("PAUSE");
        }
    break;
    case 4:
        system("CLS");
        if (count1 > 0)
        {
        cout << "Hourly Employees\n" << endl;
        for(int n = 0; n< count1; n++)
        {
            cout << "Employee #" << (n + 1) << endl;
            hourly[n].CalculatePay();
        }
        }
        else
        {
            cout << "No records currently entered for Contractor Employee" << endl;
        }
        system("PAUSE");
    break;
    case 5:
        system("CLS");
        if (count2 > 0)
        {
        cout << "Salaried Employees\n" << endl;
        for(int n = 0; n< count2; n++)
        {
            cout << "Employee #" << (n + 1) << endl;
            salaried[n].CalculatePay();
        }
        }
        else
        {
            cout << "No records currently entered for Salaried Employee" << endl;
        }
        system("PAUSE");
    break;
    case 6:
        system("CLS");
        if (count3 > 0)
        {
        cout << "Contractor Employees\n" << endl;
        for(int n = 0; n< count3; n++)
        {
            cout << "Contractor #" << (n + 1) << endl;
            contractor[n].CalculatePay();
        }
        }
        else
        {
            cout << "No records currently entered for Salaried Employee" << endl;
        }
        system("PAUSE");
    break;
    case 7:
        exit(0);
    break;
}

}while (again == true);
}
