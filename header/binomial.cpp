#include "binomial.h"
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

double BinomialModel::calculateOptionPrice(double S, double K, double r, double sigma, double T, int steps, bool isCall, bool isAmerican) {
    double dt = T / steps;
    double u = exp(sigma * sqrt(dt));
    double d = 1.0 / u;
    double p = (exp(r * dt) - d) / (u - d);

    vector<double> optionValues(steps + 1);

    // Initialize option values at maturity
    for (int i = 0; i <= steps; i++) {
        double assetPrice = S * pow(u, steps - i) * pow(d, i);
        if (isCall) {
            optionValues[i] = max(0.0, assetPrice - K);
        } else {
            optionValues[i] = max(0.0, K - assetPrice);
        }
    }

    // Iterate backwards
    for (int i = steps - 1; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            optionValues[j] = exp(-r * dt) * (p * optionValues[j] + (1 - p) * optionValues[j + 1]);
            
            if (isAmerican) {
                double currentAssetPrice = S * pow(u, i - j) * pow(d, j);
                double intrinsicValue = isCall ? max(0.0, currentAssetPrice - K) : max(0.0, K - currentAssetPrice);
                optionValues[j] = max(optionValues[j], intrinsicValue);
            }
        }
    }

    return optionValues[0];
}
