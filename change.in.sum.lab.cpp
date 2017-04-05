#include <iostream>
#include <conio.h>
#include <iomanip>

using namespace std;

float twenty_b, ten_b, five_b, one_b, fifty_c, quarter_c;
float dimes_c, nickels_c, pennies_c;
float entered_amount, converted_amount;
long mod_20s, mod_10s, mod_5s, mod_1s, mod_half, mod_quart, mod_dime, mod_nickel, mod_penny;

int main()
{

cout << "Please Enter a dollar amount (i.e. $37.21, $.77): ";
cin >> entered_amount;

if (entered_amount < 0)
{
    entered_amount = entered_amount * -1;
}

converted_amount = entered_amount * 100;
mod_20s = (int)converted_amount % 2000;

if (mod_20s > 0)
{
   twenty_b = (converted_amount - mod_20s) / 2000;
}
else
{
    twenty_b = converted_amount / 2000;
}
mod_10s = mod_20s % 1000;

if (mod_10s > 0)
{
    ten_b = (mod_20s - mod_10s) / 1000;
}
else
{
    ten_b = mod_20s / 1000;
}
mod_5s = mod_10s % 500;

if (mod_5s > 0)
{
    five_b = (mod_10s - mod_5s) / 500;
}
else
{
    five_b = mod_10s / 500;
}
mod_1s = mod_5s % 100;

if (mod_1s > 0)
{
    one_b = (mod_5s - mod_1s) / 100;
}
else
{
    one_b = mod_5s / 100;
}
mod_half = mod_1s % 50;

if (mod_half > 0)
{
    fifty_c = (mod_1s - mod_half) / 50;
}
else
{
    fifty_c = mod_1s / 50;
}
mod_quart = mod_half % 25;

if (mod_quart > 0)
{
    quarter_c = (mod_half - mod_quart) / 25;
}
else
{
    quarter_c = mod_half / 25;
}
mod_dime = mod_quart % 10;

if (mod_dime > 0)
{
    dimes_c = (mod_quart - mod_dime) / 10;
}
else
{
    dimes_c = mod_quart / 10;
}
mod_nickel = mod_dime % 5;

if (mod_nickel > 0)
{
    nickels_c = (mod_dime - mod_nickel) / 5;
}
else
{
    nickels_c = mod_dime / 5;
}

mod_penny = mod_nickel % 1;

if (mod_penny > 0)
{
    pennies_c = (mod_nickel - mod_penny) / 1;
}
else
{
    pennies_c = mod_nickel / 1;
}
cout << "\n$" << entered_amount << " in pennies is " << converted_amount << " pennies." <<endl;
if (twenty_b > 0)
{
    cout << "\n" << twenty_b << " Twenty Dollar bills" << endl;

}
if (ten_b > 0)
{
    cout << ten_b << " Ten Dollar bills" << endl;
}
if (five_b > 0)
{
    cout << five_b << " Five Dollar bills" << endl;
}
if (one_b > 0)
{
    cout << one_b << " One Dollar bills" << endl;
}
if (fifty_c > 0)
{
   cout << fifty_c << " Fifty Cent pieces" << endl;
}
if (quarter_c > 0)
{
    cout << quarter_c << " Quarters" << endl;
}
if (dimes_c > 0)
{
    cout << dimes_c << " Dimes" << endl;
}
if (nickels_c > 0)
{
    cout << nickels_c << " Nickels" << endl;
}
if (pennies_c > 0)
{
    cout << (int)pennies_c << " Pennies in $" << entered_amount << endl;
}
    return 0;
}
