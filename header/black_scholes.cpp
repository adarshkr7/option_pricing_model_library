#include "black_scholes.h"
#include <cmath>
#include <iostream>

using namespace std;

double BlackScholes::normalCDF(double value) {
    return 0.5 * erfc(-value * 0.707106781186547524);
}

double BlackScholes::calculateCallOptionPrice(double S, double K, double r, double sigma, double T) {
    double d1 = (log(S / K) + (r + 0.5 * sigma * sigma) * T) / (sigma * sqrt(T));
    double d2 = d1 - sigma * sqrt(T);
    return S * normalCDF(d1) - K * exp(-r * T) * normalCDF(d2);
}

double BlackScholes::calculatePutOptionPrice(double S, double K, double r, double sigma, double T) {
    double d1 = (log(S / K) + (r + 0.5 * sigma * sigma) * T) / (sigma * sqrt(T));
    double d2 = d1 - sigma * sqrt(T);
    return K * exp(-r * T) * normalCDF(-d2) - S * normalCDF(-d1);
}