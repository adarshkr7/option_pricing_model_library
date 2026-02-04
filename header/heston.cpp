#include "heston.h"
#include <iostream>
#include <cmath>
#include <random>
#include <algorithm>

using namespace std;

double HestonModel::calculateOptionPriceMC(double S, double K, double r, double v0, double kappa, double theta, double sigma, double rho, double T, int simulations, int steps, bool isCall) {
    double dt = T / steps;
    double sqrt_dt = sqrt(dt);
    
    random_device rd;
    mt19937 gen(rd());
    normal_distribution<> d(0, 1);

    double payoffSum = 0.0;

    for (int i = 0; i < simulations; ++i) {
        double St = S;
        double vt = v0;

        for (int j = 0; j < steps; ++j) {
            double Z1 = d(gen);
            double Z2 = d(gen);
            
            // Correlated Brownian motions
            double ZS = Z1; 
            double ZV = rho * Z1 + sqrt(1 - rho * rho) * Z2;

            double vt_plus = max(vt, 0.0);
            
            // Log-price update for stability
            St *= exp((r - 0.5 * vt_plus) * dt + sqrt(vt_plus) * sqrt_dt * ZS);
            
            // Variance update
            vt += kappa * (theta - vt_plus) * dt + sigma * sqrt(vt_plus) * sqrt_dt * ZV;
        }

        if (isCall)
            payoffSum += max(St - K, 0.0);
        else
            payoffSum += max(K - St, 0.0);
    }

    return (payoffSum / simulations) * exp(-r * T);
}