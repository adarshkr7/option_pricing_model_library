#ifndef BLACK_SCHOLES_H
#define BLACK_SCHOLES_H

class BlackScholes {
public:
    static double calculateCallOptionPrice(double S, double K, double r, double sigma, double T);
    static double calculatePutOptionPrice(double S, double K, double r, double sigma, double T);
private:
    static double normalCDF(double value);
};

#endif