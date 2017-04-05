#include <iostream>
#include <iomanip>
#include <conio.h>

using namespace std;

int main()
{
    char cid[6]; // Defining the variables involved in the program
    int wh, gi, wi, wa, el;
    float wh_sub, gi_sub, wi_sub, wa_sub, el_sub;
    float ship_h, sales_t, grand_sub, grand_total;

    cout << " This program allows you to place an order from Shodd Dee Manufacturing." << endl; // Displaying formatted questions to collect input from the user
    cout << "\n Enter your Customer Account ID: ";
    cin >> cid;
    cout << "\n 1 of 5 Enter the number of Whizbangs: ";
    cin  >> wh;
    cout << " 2 of 5 Enter the number of Gizmos: ";
    cin  >> gi;
    cout << " 3 of 5 Enter the number of Widgets: ";
    cin >> wi;
    cout << " 4 of 5 Enter the number of Wabbits: ";
    cin >> wa;
    cout << " 5 of 5 Enter the number of Elmers: ";
    cin >> el;

    wh_sub = wh * 5.00; // Defining the value of each item's sub total as input * price, and saving in variable
    gi_sub = gi * 10.15;
    wi_sub = wi * 5.99;
    wa_sub = wa * 7.75;
    el_sub = el * 9.50;

    grand_sub = wh_sub + gi_sub + wi_sub + wa_sub + el_sub ;
    ship_h = grand_sub * .10 ;
    sales_t = grand_sub *.075 ;
    grand_total = grand_sub + sales_t + ship_h ;

cout.precision(2); // Set precision of the numerical display to two decimal points.
cout.setf(ios::fixed, ios::floatfield);
cout.setf(ios::showpoint);

    cout << "\n " << setw(5) << wh << " Whizbangs @ $5.00 each = $" << wh_sub << endl ; // Create the output formatting for the itemized display.
    cout << setw(6) << gi << " Gizmos @ $10.15 each = $" << gi_sub << endl ;
    cout << setw(6) << wi << " Widgets @ $5.99 each = $" << wi_sub << endl ;
    cout << setw(6) << wa << " Wabbits @ $7.75 each = $" << wa_sub << endl ;
    cout << setw(6) << el << " Elmers @ $9.50 each = $" << el_sub << endl ;

    cout << "\n Sub Total = $" << grand_sub << endl ;
    cout << " Sales Tax @ 7.5% of " << grand_sub << " = $" << sales_t << endl;
    cout << " Shipping & Handling @ 10% of $" << grand_sub << " = $" << ship_h << endl;
    cout << " Grand Total = $" << grand_total << endl;

    return 0;
}
