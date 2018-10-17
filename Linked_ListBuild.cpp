#include <iostream>
#include <stdlib.h>
#include <math.h>

using namespace std;
void InputValues();
void SetAll(string, float, float);
void DisplayAll(int);

struct Node
{
  Node *Next;
  string emp_id;
  float hours;
  float pay;
  Node *Previous;
};

Node *P;
Node *Last = NULL;
Node *First = NULL;
Node *Middle;
Node *TempPrev;
Node *TempNext;

int index = 0;

void InputValues()
{
    string temp_id;
    float temp_pay, temp_hours;
    int n;

    cin.ignore(1000, '\n');

    cout << "Enter Employee ID: ";
    getline(cin, temp_id);
    for(n = 0; n < temp_id.length(); n++)
    {
        temp_id[n] = toupper(temp_id[n]);
    }
    cout << "Enter Employee's Pay Rate: ";
    cin >> temp_pay;
    temp_pay = fabs(temp_pay);
    cout << "Enter Employee's Hours: ";
    cin >> temp_hours;
    temp_hours = fabs(temp_hours);

    SetAll(temp_id, temp_hours, temp_pay);
}

void SetAll(string emp, float h, float payrt)
{
    P ->emp_id = emp;
    P ->hours = h;
    P ->pay = payrt;
}

Node* Search(Node* P, string temp_id)
{

P = First;
bool done = false;
index = 0;

    while (done == false)
    {
        index++;
            if (P->emp_id == temp_id)
            {
                done = true;
                return P;
            }
            else if ((!(P->emp_id == temp_id)) && (P == Last))
            {
                return NULL;
                done = true;
                break;
            }
        P = P ->Next;
    }
    return NULL;
}

void DisplayAll(int total_nodes)
{
    P = First;
    if (total_nodes == 0)
    {
        cout << "Currently No Nodes to Display Here\n" << endl;
    }
    else
    {
    cout << "The Linked List Contains the following Nodes\n" << endl;

        for(int x = 1; x <= total_nodes; x++)
        {
            cout << "Employee ID: " << P->emp_id << endl;
            cout << "Hours Worked: " << P->hours << endl;
            cout << "Pay Rate: $" << P->pay << "\n" << endl;
            P = P->Next;
        }
    cout << "\n\n";
    }
    system("PAUSE");
}

int main()
{
  string temp_id;
  int selection, n;
  bool again = true;
  int total_nodes = 0;
  float temp_float;

do
{
 selection = 0;
    while((selection < 1) || (selection > 8))
    {
    system("CLS");
    cout << "1 - Insert new Node at the START of the List" << endl;
    cout << "2 - Insert new Node at the END of the List" << endl;
    cout << "3 - Add Node to the Middle of the list" << endl;
    cout << "4 - Display all Nodes" << endl;
    cout << "5 - Search for Node using Employee ID" << endl;
    cout << "6 - Change Values of Nodes" << endl;
    cout << "7 - Delete a Node" << endl;
    cout << "8 - Quit" << endl;
    cout << "Choice: ";
    cin >> selection;
    }
    system("CLS");
    switch (selection)
    {
    case 1:
            P = new Node;
            total_nodes++;

            P -> Previous = NULL;

            InputValues();

            P -> Next = First;
            First = P;

            if(total_nodes == 1)
                {
                    Last = P;
                }
            else
                {
                    P = P -> Next;
                    P -> Previous = First;
                }
    break;
    case 2:
            P = new Node;
            total_nodes++;
            InputValues();
            P -> Next = NULL;
            P -> Previous = Last;
            Last = P;

        if (total_nodes == 1)
        {
            First = P;
        }
        else
        {
            P = P -> Previous;
            P -> Next = Last;
        }
    break;
    case 3:
    if (total_nodes >= 2)
    {
        P = First;

        if(total_nodes%2 == 0)
        {
            for (int n=1; n < total_nodes/2; n++)
            {
                P = P->Next;
            }
        }
        else
        {
            for (int n=1; n< (total_nodes+1)/2; n++)
            {
                P = P->Next;
            }
        }

        Middle = new Node;
        Middle -> Previous = P;
        P = P->Next;
        Middle -> Next = P;
        P->Previous = Middle;
        P = Middle ->Previous;
        P->Next = Middle;
        P = P->Next;

        InputValues();
        total_nodes++;
    }
    else
    {
        cout << "There are only " << total_nodes << " available " << endl;
        cout << "Cannot add a Middle Node without at least 2" << endl;
        system("PAUSE");
    }
    break;
    case 4:
        DisplayAll(total_nodes);
    break;
    case 5:
        if (total_nodes > 0)
            {
                cin.ignore(1000, '\n');
                cout << "Search for which Employee ID: ";
                getline(cin, temp_id);

                for(int n = 0; n < temp_id.length(); n++)
                {
                    temp_id[n] = toupper(temp_id[n]);
                }

                if (!(Search(P, temp_id)== NULL))
                {
                    P = Search(P, temp_id);
                    cout << "\nEmployee ID: " << P->emp_id << endl;
                    cout << "Hours Worked: " << P->hours << endl;
                    cout << "Pay Rate: $" << P->pay << "\n" << endl;
                    system("PAUSE");
                }
                else
                {
                    cout << "Sorry, but no Node was found to contain: " << temp_id << endl;
                    system("PAUSE");
                }
            }
            else
            {
                cout << "There are currently no Nodes. Please Create one before searching for a value..." << endl;
                system("PAUSE");
            }
    break;
    case 6:
        if (total_nodes > 0)
            {
                cin.ignore(1000, '\n');
                cout << "Search for which Employee ID: ";
                getline(cin, temp_id);

                for(int n = 0; n < temp_id.length(); n++)
                {
                    temp_id[n] = toupper(temp_id[n]);
                }
                if (!(Search(P, temp_id) == NULL))
                {
                    P = Search(P, temp_id);
                    cout << "\nEmployee ID: " << P->emp_id << endl;
                    cout << "Hours Worked: " << P->hours << endl;
                    cout << "Pay Rate: $" << P->pay << "\n" << endl;

                    selection = 0;

                while ((selection < 1) || (selection > 4))
                {
                    cout << "Change" << endl;
                    cout << "1 - Employee ID " << endl;
                    cout << "2 - Hours Worked " << endl;
                    cout << "3 - Pay Rate" << endl;
                    cout << "4 - Change ALL values" << endl;
                    cout << "Choice: ";
                    cin >> selection;
                }
                system("CLS");
                switch (selection)
                {
                case 1:
                    cin.ignore(1000, '\n');
                    cout << "Enter Employee ID: ";
                    getline(cin, temp_id);
                    for(n = 0; n < temp_id.length(); n++)
                    {
                        temp_id[n] = toupper(temp_id[n]);
                    }
                    P->emp_id = temp_id;
                break;
                case 2:
                    cout << "Enter Employee's Hours: ";
                    cin >> temp_float;
                    temp_float = fabs(temp_float);
                    P->hours = temp_float;
                break;
                case 3:
                    cout << "Enter Employee's Pay Rate: ";
                    cin >> temp_float;
                    temp_float = fabs(temp_float);
                    P->pay = temp_float;
                break;
                case 4:
                    InputValues();
                break;
                }

                }
                else
                {
                    cout << "Sorry, but no Node was found to contain: " << temp_id << endl;
                    system("PAUSE");
                }

            }
            else
            {
                cout << "There are currently no Nodes. Please Create one before searching for a value to change..." << endl;
                system("PAUSE");
            }
    break;
    case 7:
        if (total_nodes > 0)
            {
                cin.ignore(1000, '\n');
                cout << "Search for which Employee ID: ";
                getline(cin, temp_id);
                for(n = 0; n < temp_id.length(); n++)
                {
                   temp_id[n] = toupper(temp_id[n]);
                }
                if (Search(P, temp_id) != NULL)
                {
                    P = Search(P, temp_id);
                    TempPrev = P->Previous;
                    TempNext = P->Next;
                    total_nodes--;

                    if (total_nodes == 0)
                    {
                        delete P;
                        First = NULL;
                        Last = NULL;
                    }
                    else
                    {
                        if((TempPrev != NULL) && (TempNext != NULL))
                        {

                            delete P;

                            P = TempNext;
                            P->Previous = TempPrev;
                            P = P->Previous;
                            P->Next = TempNext;
                        }
                        if (TempPrev == NULL)
                        {
                            P = TempNext;
                            P->Previous = NULL;
                            First = P;

                        }
                        if (TempNext == NULL)
                        {
                            P = TempPrev;
                            P->Next = NULL;
                            Last = P;
                        }
                    }

                }
                else
                {
                    system("CLS");
                    cout << "Sorry, but no Node was found to contain: " << temp_id << endl;
                    system("PAUSE");
                }

            }
            else
            {
                system("CLS");
                cout << "Please create at least one Node before attempting to delete one" << endl;
                system("PAUSE");
            }
    break;
    case 8:
        exit(0);
    break;
    }

    }while (again == true);
}
