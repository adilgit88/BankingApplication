#include <iostream>
#include <iomanip>  

using namespace std;

int main() {
    // Declare variables for user input
    double initialInvestment, monthlyDeposit, annualInterestRate;
    int years;

    // Display input prompt and get user input
    cout << "*********** Data Input ***********" << endl;
    cout << "Initial Investment Amount: ";
    cin >> initialInvestment;
    cout << "Monthly Deposit: ";
    cin >> monthlyDeposit;
    cout << "Annual Interest: ";
    cin >> annualInterestRate;
    cout << "Number of years: ";
    cin >> years;
    cout << "Press any key to continue . . ." << endl;
    cin.ignore(); 

    // Validate input
    if (initialInvestment <= 0 || monthlyDeposit < 0 || annualInterestRate <= 0 || years <= 0) {
        cout << "Invalid input. Please ensure all values are positive." << endl;
        return 1;  
    }

    // Calculate compound interest without monthly deposits
    double balanceWithoutDeposits = initialInvestment;
    double totalInterestWithoutDeposits = 0;

    cout << "\nBalance and Interest Without Additional Monthly Deposits" << endl;
    cout << "=====================================================" << endl;
    cout << "Year\tYear End Balance\tYear End Earned Interest" << endl;

    for (int year = 1; year <= years; year++) {
        // Apply compound interest formula compounded annually 
        balanceWithoutDeposits = balanceWithoutDeposits * (1 + (annualInterestRate / 100));
        totalInterestWithoutDeposits = balanceWithoutDeposits - initialInvestment;

        // Output year end balance and earned interest
        cout << year << "\t$" << fixed << setprecision(2) << balanceWithoutDeposits
            << "\t\t$" << fixed << setprecision(2) << totalInterestWithoutDeposits << endl;
    }

    // Calculate compound interest with monthly deposits
    double balanceWithDeposits = initialInvestment;
    double totalInterestWithDeposits = 0;

    cout << "\nBalance and Interest With Additional Monthly Deposits" << endl;
    cout << "=====================================================" << endl;
    cout << "Year\tYear End Balance\tYear End Earned Interest" << endl;

    for (int year = 1; year <= years; year++) {
        for (int month = 1; month <= 12; month++) {
            balanceWithDeposits += monthlyDeposit;  // Add monthly deposit
            balanceWithDeposits *= (1 + (annualInterestRate / 100) / 12);  // Apply monthly compounding interest
        }
        totalInterestWithDeposits = balanceWithDeposits - (initialInvestment + monthlyDeposit * 12 * year);

        // Output year end balance and earned interest
        cout << year << "\t$" << fixed << setprecision(2) << balanceWithDeposits
            << "\t\t$" << fixed << setprecision(2) << totalInterestWithDeposits << endl;
    }

    return 0;
}
