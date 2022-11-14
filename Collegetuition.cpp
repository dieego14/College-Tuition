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
    const double OUT_OF_STATE_RATE = UNIT_RATE * 2.5;
    const double HEALTH_FEE = 18.0;
    const double PARKING_FEE = 25.00;
    const double APPLICATION_FEE = 80.0;

    string studentName;
    char isResident;
    int numUnits;
    double costOfUnits;
    char isDisabled;
    char isVeteran;
    double totalCost;
    double applicationFee;
    double parkingFee;
    double healthFee;
    string parkingStatus, veteranStatus, partTime;

    cout << "WELCOME TO COLLEGE ! " << endl;
    cout << "Please answer the following information: " << endl;
    cout << "What is your name?: " << studentName;
    getline(cin, studentName);
    cout << "Are you a California resident? (Y/N): " << isResident;
    isResident = getYorN();
    if (isResident == 'Y' || isResident == 'N')
    {
        cout << "How many units will you be taking?: " << numUnits;
        numUnits = unitNumber();
        cout << "Are you disabled? (Y/N): " << isDisabled;
        isDisabled = getYorN();
        cout << "Are you a veteran? (Y/N): " << isVeteran;
        isVeteran = getYorN();
    }

    costOfUnits = numUnits * UNIT_RATE;

    if (isResident == 'N')
    {
        costOfUnits = numUnits * UNIT_RATE;
    }
    else
    {
        costOfUnits = numUnits * OUT_OF_STATE_RATE;
    }
    if (isVeteran == 'Y')
    {
        applicationFee = 0;
        veteranStatus = " (Waived: Is a Veteran)";
    }
    else
    {
        applicationFee = APPLICATION_FEE;
        veteranStatus = " ";
    }
    if (isDisabled == 'Y')
    {
        parkingFee = 0;
        parkingStatus = " (Waived: Is Disabled)";
    }
    else
    {
        parkingFee = PARKING_FEE;
        parkingStatus = " ";
    }

    if (numUnits < 10)
    {
        healthFee = 0;
        partTime = " (Waived: Is Part Time)";
    }
    else
    {
        healthFee = HEALTH_FEE;
        partTime = " ";
    }
    totalCost = costOfUnits + healthFee + parkingFee + applicationFee;

    cout << setprecision(2) << fixed << showpoint;
    cout << "\nStudent's name:" << setw(4) << " " << studentName << endl
         << "State Resident: " << setw(4) << isResident << endl
         << "Number of Units: " << setw(2) << " " << numUnits << endl
         << "Application Fee: " << setw(3) << "$" << setw(6) << applicationFee << veteranStatus << endl
         << "Cost of " << numUnits << " Units: " << setw(2) << " "
         << "$" << setw(6) << costOfUnits << endl
         << "Parking Fee: " << setw(7) << "$" << setw(6) << parkingFee << parkingStatus << endl
         << "Health Fee: " << setw(8) << "$" << setw(6) << healthFee << partTime << endl
         << "Total Cost: " << setw(8) << "$" << setw(6) << totalCost << endl;

    return 0;
}
