#ifndef INVESTMENTCALCULATOR_H
#define INVESTMENTCALCULATOR_H

class InvestmentCalculator {
public:
    InvestmentCalculator();
    void run();

    void displayWithoutMonthlyDeposit(double initial, double rate, int years);
    void displayWithMonthlyDeposit(double initial, double monthly, double rate, int years);
};

#endif