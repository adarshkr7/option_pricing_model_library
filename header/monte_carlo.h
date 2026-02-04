#ifndef MONTE_CARLO_H
#define MONTE_CARLO_H

class MonteCarlo {
public:
    static double calculateOptionPrice(double strikePrice, double initialStockPrice, double rate, double volatility, double time, int simulations = 100000, bool isCall = true);
};

#endif