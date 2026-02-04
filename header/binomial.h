#ifndef BINOMIAL_H
#define BINOMIAL_H

class BinomialModel {
public:
    static double calculateOptionPrice(double S, double K, double r, double sigma, double T, int steps, bool isCall, bool isAmerican);
};

#endif