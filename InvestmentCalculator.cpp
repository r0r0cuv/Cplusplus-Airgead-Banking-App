#include "InvestmentCalculator.h"
#include <iostream>
#include <iomanip>
using namespace std;

// Constructor
InvestmentCalculator::InvestmentCalculator() {}

// Main program
void InvestmentCalculator::run() {
    double initialInvestment;
    double monthlyDeposit;
    double annualInterest;
    int years;

    cout << "********** Data Input **********" << endl;

    cout << "Initial Investment Amount: ";
    cin >> initialInvestment;

    cout << "Monthly Deposit: ";
    cin >> monthlyDeposit;

    cout << "Annual Interest (%): ";
    cin >> annualInterest;

    cout << "Number of Years: ";
    cin >> years;

    cout << "\n\n";

    displayWithoutMonthlyDeposit(initialInvestment, annualInterest, years);
    cout << "\n";
    displayWithMonthlyDeposit(initialInvestment, monthlyDeposit, annualInterest, years);
}

// Without monthly deposits
void InvestmentCalculator::displayWithoutMonthlyDeposit(double initial, double rate, int years) {
    double balance = initial;
    double yearlyInterest;

    cout << "Balance and Interest Without Additional Monthly Deposits" << endl;
    cout << "========================================================" << endl;

    cout << left << setw(6) << "Year"
        << setw(22) << "Year End Balance"
        << setw(25) << "Year End Earned Interest" << endl;

    for (int i = 1; i <= years; i++) {
        yearlyInterest = balance * (rate / 100);
        balance += yearlyInterest;

        cout << left << setw(6) << i
            << "$" << setw(21) << fixed << setprecision(2) << balance
            << "$" << setw(24) << yearlyInterest << endl;
    }
}

// With monthly deposits
void InvestmentCalculator::displayWithMonthlyDeposit(double initial, double monthly, double rate, int years) {
    double balance = initial;
    double monthlyRate = (rate / 100) / 12;
    double yearlyInterest;

    cout << "Balance and Interest With Additional Monthly Deposits" << endl;
    cout << "======================================================" << endl;

    cout << left << setw(6) << "Year"
        << setw(22) << "Year End Balance"
        << setw(25) << "Year End Earned Interest" << endl;

    for (int i = 1; i <= years; i++) {
        yearlyInterest = 0;

        for (int j = 0; j < 12; j++) {
            balance += monthly;

            double interest = balance * monthlyRate;
            yearlyInterest += interest;
            balance += interest;
        }

        cout << left << setw(6) << i
            << "$" << setw(21) << fixed << setprecision(2) << balance
            << "$" << setw(24) << yearlyInterest << endl;
    }
}