#include "monte_carlo.h"
#include <random>

using namespace std;

double monteCarlo(double strikePrice, double initialStockPrice, double rate, double volatility, double time, int simulations) {

    random_device rd;
    mt19937 gen(rd());
    normal_distribution<> normal(0.0, 1.0);

    double payoffSum = 0.0;

    for(int i = 0; i < simulations; i++) {
        double Z = normal(gen);
        double ST = initialStockPrice * exp((rate - 0.5 * (volatility * volatility)) * time + volatility * sqrt(time) * Z);
        payoffSum += max(ST - strikePrice, 0.0);
    }

    return (exp(- rate * time) * (payoffSum / simulations));
}