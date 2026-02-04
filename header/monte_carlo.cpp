#include "monte_carlo.h"
#include <random>
#include <cmath>
#include <algorithm>

using namespace std;

double MonteCarlo::calculateOptionPrice(double strikePrice, double initialStockPrice, double rate, double volatility, double time, int simulations, bool isCall) {
    
    random_device rd;
    mt19937 gen(rd());
    normal_distribution<> normal(0.0, 1.0);

    double payoffSum = 0.0;
    
    // Pre-calculate constants
    double drift = (rate - 0.5 * volatility * volatility) * time;
    double volSqrtTime = volatility * sqrt(time);

    for(int i = 0; i < simulations; i++) {
        double Z = normal(gen);
        double ST = initialStockPrice * exp(drift + volSqrtTime * Z);
        if (isCall) {
            payoffSum += max(ST - strikePrice, 0.0);
        } else {
            payoffSum += max(strikePrice - ST, 0.0);
        }
    }

    return (exp(-rate * time) * (payoffSum / simulations));
}