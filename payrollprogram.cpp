#include <iostream>
#include <iomanip>
#include <conio.h>

using namespace std;

char last_name[15], first_name[12], id_number[5];
float reg_hours, over_hours=0, total_hours, hourly_rate;
float reg_pay, over_pay, gross_pay, net_pay;
float fed_tax, state_tax;

int main()
{
//char last_name[15], first_name[12], id_number[5];
//float reg_hours, over_hours=0, total_hours, hourly_rate;
//float reg_pay, over_pay, gross_pay, net_pay;
//float fed_tax, state_tax;

cout.precision(2);
cout.setf(ios::fixed, ios::floatfield);
cout.setf(ios::showpoint);

cout << "\n1 of 5: Enter the employee's LAST name: ";
cin >> last_name;

cout << "\n2 of 5: Enter the employee's FIRST name: ";
cin >> first_name;

cout << "\n3 of 5: Enter the employee's ID number: ";
cin >> id_number;

cout << "\n4 of 5: Enter the employee's Total hours worked (up to a maximum of 60): ";
cin >> total_hours;
    if (total_hours < 0)
{
    total_hours = total_hours * -1;
}
    if (total_hours > 60)
{
    total_hours = 60;
    cout << "\nYou cannot enter more than 60 hours total!" << "\n Hours are automatically defaulted to " << (int)total_hours << endl;
}
    if (total_hours > 40)
{
    reg_hours = 40;
    over_hours = total_hours - 40;
}
    if (total_hours < 40)
{

    reg_hours = total_hours;
    over_hours = 0;
}

cout << "\n5 of 5: Enter the employee's Pay Per Hour: $";
cin >> hourly_rate;
    if (hourly_rate < 0)
{
    hourly_rate = hourly_rate * -1;
}
reg_pay = reg_hours * hourly_rate;
over_pay = over_hours * (hourly_rate * 2);
gross_pay = reg_pay + over_pay;
total_hours = reg_hours + over_hours;

fed_tax = gross_pay * .2;
state_tax = gross_pay * .05;
net_pay = gross_pay - fed_tax - state_tax;

cout << "\nFor Employee: " << last_name << ", " << first_name << endl;
cout << "Customer ID: " << id_number << endl;
cout << "\nTotal Hours = " << total_hours << endl;
cout << reg_hours <<  " Regular hours @ $" << hourly_rate << " = $" << reg_pay << endl;

    if (over_hours > 0)
{
    cout << over_hours << " Overtime hours @ $" << hourly_rate * 2 << " = $" << over_pay <<endl;
}
cout << "\nTotal Gross Pay = $" << gross_pay << endl;
cout << "Federal Tax Withheld = $" << fed_tax << endl;
cout << "State Tax Withheld = $" << state_tax << endl;
cout << "\nNet Pay = $" << net_pay << endl;
return 0;
}
