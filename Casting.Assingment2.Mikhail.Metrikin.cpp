#include <iostream>
#include <iomanip>
#include <stdfix.h>
#include <math.h>

using namespace std;

int main()
{
int number1, number2, mod1;
float decimal1, decimal2;
float sum1, difference1, difference2, product1, quotient1, quotient2, quotient3;

    cout << "\n 1 of 4: Enter the First Decimal Number: ";
    cin >> decimal1;
    cout << "\n 2 of 4: Enter the Second Decimal Number: ";
    cin >> decimal2;
    cout << "\n 3 of 4: Enter the First Integer Number: ";
    cin >> number1;
    cout << "\n 4 of 4: Enter the Second Integer Number: ";
    cin >> number2;

    sum1 = decimal1 + decimal2;
    difference1 = decimal1 - decimal2;
    product1 = decimal1 * decimal2;
    quotient1 = decimal1 / decimal2;
    mod1 = (int)decimal1 % (int)decimal2;
    quotient3 = quotient2 = (float)number1 / (float)number2;


    difference2 = (int)decimal1 - (int)decimal2;

cout << "\n" << "Calculation Output \n" << endl;
cout << decimal1 << " + " << decimal2 << " = " << sum1 << endl;
cout << decimal1 << " - " << decimal2 << " = " << difference1 << endl;
cout << decimal1 << " * " << decimal2 << " = " << product1 << endl;
cout << decimal1 << " / " << decimal2 << " = " << quotient1 << endl;

cout << "\n" << (int)decimal1 << " % " << (int)decimal2 << " is remainder " << mod1 << endl;
cout << number1 << " / " << number2 << " = " << (int)quotient2 << endl;
cout << number1 << " / " << number2 << " = " << quotient3 << endl;
cout << (int)decimal1 << " - " << (int)decimal2 << " = " << (difference2) << endl;

return 0;
}
