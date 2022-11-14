#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

char getYorN()
{
    char YorN;

    cin >> YorN;
    YorN = toupper(YorN);
    while ((YorN != 'Y') && (YorN != 'N'))
    {
        cout << "Please Enter Y or N: ";
        cin >> YorN;
        YorN = toupper(YorN);
    }

    return YorN;
}

int unitNumber()
{
    int numberOfUnits;
    cin >> numberOfUnits;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(70, '\n');
        cout << "Please enter a number: ";
        cin >> numberOfUnits;
    }
    while (numberOfUnits <= 0)
    {
        cout << "Cannot have 0 or negative units" << endl;
        // cin.ignore(70, '\n');
        cout << "Please enter number of units: ";
        cin >> numberOfUnits;
    }
    while (numberOfUnits > 17)
    {
        cout << "Cannot take more than 17 units" << endl;
        // cin.ignore(70, '\n');
        cout << "Please enter number of units: ";
        cin >> numberOfUnits;
    }

    return numberOfUnits;
}

int main()
{

    const double UNIT_RATE = 36.0;
    const double OUT_OF_STATE_RATE = UNIT_RATE * 2;
    const double HEALTH_FEE = 18.0;
    const double PARKING_FEE = 25.00;
    const double APPLICATION_FEE = 80.0;

    string studentName = "Diego Hernandez";
    char isResident = 'Y';
    int numUnits = 10;
    double costOfUnits;
    char isDisabled = 'Y';
    char isVeteran = 'Y';
    double totalCost;
    double parkingFee;

    cout << "WELCOME TO COLLEGE ! " << endl;
    cout << "Please answer the following information: " << endl;
    cout << "What is your name?: " << studentName;
    // getline(cin, studentName);
    cout << "Are you a California resident? (Y/N): " << isResident << endl;
    // isResident = getYorN();
    //  if (isResident == 'Y' || isResident == 'N')
    //  {
    cout << "How many units will you be taking?: " << numUnits << endl;
    // numUnits = unitNumber();
    cout << "Are you disabled? (Y/N): " << isDisabled << endl;
    // isDisabled = getYorN();
    cout << "Are you a veteran? (Y/N): " << isVeteran << endl;
    // isVeteran = getYorN();
    // }

    costOfUnits = numUnits * UNIT_RATE;
    totalCost = costOfUnits + HEALTH_FEE + PARKING_FEE + APPLICATION_FEE;

    cout << setprecision(2) << fixed << showpoint;
    cout << "\nStudent's name: " << setw(1) << studentName << endl
         << "State Resident: " << setw(4) << isResident << endl
         << "Number of Units: " << setw(4) << numUnits << endl
         << "Application Fee: " << setw(3) << "$" << setw(6) << APPLICATION_FEE << endl
         << "Cost of " << numUnits << " Units: " << setw(2) << "$" << setw(6) << costOfUnits << endl
         << "Parking Fee: " << setw(7) << "$" << setw(6) << PARKING_FEE << endl
         << "Health Fee: " << setw(8) << "$" << setw(6) << HEALTH_FEE << endl
         << "Total Cost: " << setw(8) << "$" << setw(6) << totalCost << endl;

    return 0;
}
