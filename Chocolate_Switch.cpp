#include <iostream>
#include <conio.h>
#include <iomanip>

using namespace std;

float milk_pounds, dark_pounds, white_pounds, euro_pounds;
double milk_sub, dark_sub, white_sub, euro_sub;
double milk_price = 8.50, dark_price = 9.75, white_price = 10.50, euro_price = 12.50;
double gross_total, net_total, discount, ship_h, discounted_total;
int percent_equivalent;
int choice;

int main()
{

cout.setf(ios::fixed|ios::showpoint);
cout << setprecision(2) << endl;

cout << "1 of 4 Enter number of pounds of Milk Chocolate @ $8.50 per pound: " ;
cin >> milk_pounds;

if (milk_pounds < 0)
{
    milk_pounds = milk_pounds * -1;
}

milk_sub = milk_pounds * milk_price;

cout << "\n2 of 4 Enter number of pounds of Dark European Chocolate @ $9.75 per pound: ";
cin >> dark_pounds;

if (dark_pounds < 0)
{
    dark_pounds=dark_pounds*-1;
}

dark_sub = dark_pounds * dark_price;

cout << "\n3 of 4 Enter number of pounds of White Chocolate @ $10.50 per pound: ";
cin >> white_pounds;

if (white_pounds < 0)
{
    white_pounds=white_pounds*-1;
}

white_sub = white_pounds * white_price;

cout << "\n4 of 4 Enter number of pounds of European Truffles @ $12.50 per pound: ";
cin >> euro_pounds;
if (euro_pounds < 0)
{
    euro_pounds=euro_pounds*-1;
}
euro_sub = euro_pounds * euro_price;
gross_total = euro_sub + white_sub + dark_sub + milk_sub;

if ((gross_total > 20.00) && (gross_total < 39.99))
{
    choice = 1;
}
if ((gross_total >40.00) && (gross_total < 59.99))
{
    choice = 2;
}
if ((gross_total > 60.00) && (gross_total < 79.99))
{
    choice = 3;
}
if (gross_total > 80.00)
{
    choice = 4;
}
 switch (choice)
{
 case 1:
    discount = gross_total * .10;
    percent_equivalent = 10;
    break;
 case 2:
    discount = gross_total * .15;
    percent_equivalent = 15;
    break;
 case 3:
    discount = gross_total * .20;
    percent_equivalent = 20;
    break;
 case 4:
    discount = gross_total * .25;
    percent_equivalent = 25;
    break;
 default:
    discount = 0;

}

cout.setf(ios::fixed|ios::showpoint);
cout << setprecision(2) << endl;




if (milk_pounds > 0)
{
    cout << "\n\n"<< milk_pounds << " pounds of Milk Chocolate Ordered @ $" << milk_price << " per pound: $" << milk_sub << endl;
}
if (dark_pounds > 0)
{
    cout << "\n" << dark_pounds << " pounds of Dark European Chocolate @ $" << dark_price << " per pound: $" << dark_sub << endl;
}
if (white_pounds > 0)
{
    cout << "\n" << white_pounds << " pounds of White Chocolate @ $" << white_price << " per pound: $" << white_sub << endl;
}
if (euro_pounds > 0)
{
    cout << "\n" << euro_pounds << " pounds of European Truffles @ $" << euro_price << " per pound: $" << euro_sub << endl;
}

discounted_total = gross_total - discount;
ship_h = discounted_total * .1;
net_total = discounted_total + ship_h;

cout << "\nGross Order Total "<< setw(15) << "$" << gross_total << endl;
cout << "Less: " << percent_equivalent << "% Discount ";
cout << setw(14) << "$" << discount << endl;
cout << "\nTotal " << setw(27) << "$" << discounted_total << endl;
cout << "Shipping and Handling 10% ";
cout << setw(7) << "$" << ship_h << endl;
cout << "\nTotal Owed " << setw(22) << "$" << net_total << endl;

    return 0;
}
