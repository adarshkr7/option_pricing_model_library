#ifndef HESTON_H
#define HESTON_H

class HestonModel {
public:
    static double calculateOptionPriceMC(double S, double K, double r, double v0, double kappa, double theta, double sigma, double rho, double T, int simulations, int steps, bool isCall);
};

#endif