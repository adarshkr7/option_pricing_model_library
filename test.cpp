#include ".\header\binomial.h"
#include ".\header\black_scholes.h"
#include ".\header\heston.h"
#include ".\header\monte_carlo.h"

#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
using namespace std;

void testBlackScholesModel() {
    cout << "\n========== BLACK-SCHOLES MODEL TESTS ==========\n";
    cout << fixed << setprecision(4);
    
    // Test parameters
    double S = 100.0;      // Current stock price
    double K = 100.0;      // Strike price
    double r = 0.05;       // Risk-free rate (5%)
    double sigma = 0.2;    // Volatility (20%)
    double T = 1.0;        // Time to expiration (1 year)
    
    cout << "\nTest Parameters:\n";
    cout << "  Stock Price (S): " << S << "\n";
    cout << "  Strike Price (K): " << K << "\n";
    cout << "  Risk-Free Rate (r): " << r << "\n";
    cout << "  Volatility (sigma): " << sigma << "\n";
    cout << "  Time to Expiration (T): " << T << " years\n";
    
    // Test Call Option
    double callPrice = BlackScholes::calculateCallOptionPrice(S, K, r, sigma, T);
    cout << "\nCall Option Price: " << callPrice << "\n";
    
    // Test Put Option
    double putPrice = BlackScholes::calculatePutOptionPrice(S, K, r, sigma, T);
    cout << "Put Option Price: " << putPrice << "\n";
    
    // Verify put-call parity: C - P = S - K*e^(-rT)
    double parity = S - K * exp(-r * T);
    double difference = callPrice - putPrice;
    cout << "\nPut-Call Parity Check:\n";
    cout << "  Call - Put = " << difference << "\n";
    cout << "  S - K*e^(-rT) = " << parity << "\n";
    cout << "  Difference: " << abs(difference - parity) << "\n";
}

void testBinomialModel() {
    cout << "\n========== BINOMIAL MODEL TESTS ==========\n";
    cout << fixed << setprecision(4);
    
    // Test parameters
    double S = 100.0;      // Current stock price
    double K = 100.0;      // Strike price
    double r = 0.05;       // Risk-free rate (5%)
    double sigma = 0.2;    // Volatility (20%)
    double T = 1.0;        // Time to expiration (1 year)
    int steps = 100;       // Number of binomial steps
    
    cout << "\nTest Parameters:\n";
    cout << "  Stock Price (S): " << S << "\n";
    cout << "  Strike Price (K): " << K << "\n";
    cout << "  Risk-Free Rate (r): " << r << "\n";
    cout << "  Volatility (sigma): " << sigma << "\n";
    cout << "  Time to Expiration (T): " << T << " years\n";
    cout << "  Number of Steps: " << steps << "\n";
    
    // Test European Call Option
    double europeanCallPrice = BinomialModel::calculateOptionPrice(S, K, r, sigma, T, steps, true, false);
    cout << "\nEuropean Call Option Price: " << europeanCallPrice << "\n";
    
    // Test European Put Option
    double europeanPutPrice = BinomialModel::calculateOptionPrice(S, K, r, sigma, T, steps, false, false);
    cout << "European Put Option Price: " << europeanPutPrice << "\n";
    
    // Test American Call Option
    double americanCallPrice = BinomialModel::calculateOptionPrice(S, K, r, sigma, T, steps, true, true);
    cout << "American Call Option Price: " << americanCallPrice << "\n";
    
    // Test American Put Option
    double americanPutPrice = BinomialModel::calculateOptionPrice(S, K, r, sigma, T, steps, false, true);
    cout << "American Put Option Price: " << americanPutPrice << "\n";
    
    cout << "\nNote: American options should be >= European options\n";
    cout << "  American Call >= European Call: " << (americanCallPrice >= europeanCallPrice ? "PASS" : "FAIL") << "\n";
    cout << "  American Put >= European Put: " << (americanPutPrice >= europeanPutPrice ? "PASS" : "FAIL") << "\n";
}

void testMonteCarloModel() {
    cout << "\n========== MONTE CARLO SIMULATION TESTS ==========\n";
    cout << fixed << setprecision(4);
    
    // Test parameters
    double initialStockPrice = 100.0;  // Current stock price
    double strikePrice = 100.0;        // Strike price
    double rate = 0.05;                // Risk-free rate (5%)
    double volatility = 0.2;           // Volatility (20%)
    double time = 1.0;                 // Time to expiration (1 year)
    int simulations = 100000;          // Number of Monte Carlo simulations
    
    cout << "\nTest Parameters:\n";
    cout << "  Initial Stock Price: " << initialStockPrice << "\n";
    cout << "  Strike Price: " << strikePrice << "\n";
    cout << "  Risk-Free Rate (r): " << rate << "\n";
    cout << "  Volatility (sigma): " << volatility << "\n";
    cout << "  Time to Expiration: " << time << " years\n";
    cout << "  Number of Simulations: " << simulations << "\n";
    
    // Test Call Option
    double callPrice = MonteCarlo::calculateOptionPrice(strikePrice, initialStockPrice, rate, volatility, time, simulations, true);
    cout << "\nCall Option Price: " << callPrice << "\n";
    
    // Test Put Option
    double putPrice = MonteCarlo::calculateOptionPrice(strikePrice, initialStockPrice, rate, volatility, time, simulations, false);
    cout << "Put Option Price: " << putPrice << "\n";
}

void testHestonModel() {
    cout << "\n========== HESTON MODEL TESTS ==========\n";
    cout << fixed << setprecision(4);
    
    // Test parameters
    double S = 100.0;          // Current stock price
    double K = 100.0;          // Strike price
    double r = 0.05;           // Risk-free rate (5%)
    double v0 = 0.04;          // Initial variance (volatility^2 = 0.2^2 = 0.04)
    double kappa = 2.0;        // Mean reversion speed
    double theta = 0.04;       // Long-term variance
    double sigma = 0.3;        // Volatility of volatility
    double rho = -0.5;         // Correlation between price and volatility
    double T = 1.0;            // Time to expiration (1 year)
    int simulations = 100000;  // Number of simulations
    int steps = 252;           // Number of time steps (daily)
    
    cout << "\nTest Parameters:\n";
    cout << "  Stock Price (S): " << S << "\n";
    cout << "  Strike Price (K): " << K << "\n";
    cout << "  Risk-Free Rate (r): " << r << "\n";
    cout << "  Initial Variance (v0): " << v0 << "\n";
    cout << "  Mean Reversion Speed (kappa): " << kappa << "\n";
    cout << "  Long-term Variance (theta): " << theta << "\n";
    cout << "  Volatility of Volatility (sigma): " << sigma << "\n";
    cout << "  Price-Volatility Correlation (rho): " << rho << "\n";
    cout << "  Time to Expiration (T): " << T << " years\n";
    cout << "  Number of Simulations: " << simulations << "\n";
    cout << "  Time Steps: " << steps << "\n";
    
    // Test Call Option
    double callPrice = HestonModel::calculateOptionPriceMC(S, K, r, v0, kappa, theta, sigma, rho, T, simulations, steps, true);
    cout << "\nCall Option Price: " << callPrice << "\n";
    
    // Test Put Option
    double putPrice = HestonModel::calculateOptionPriceMC(S, K, r, v0, kappa, theta, sigma, rho, T, simulations, steps, false);
    cout << "Put Option Price: " << putPrice << "\n";
}

void testOutOfTheMoneyOptions() {
    cout << "\n========== OUT-OF-THE-MONEY OPTIONS TEST ==========\n";
    cout << fixed << setprecision(4);
    
    // Out-of-the-money option (Call with K > S)
    double S = 100.0;
    double K = 110.0;
    double r = 0.05;
    double sigma = 0.2;
    double T = 1.0;
    
    cout << "\nTest Parameters (Call with K > S - Out-of-the-Money):\n";
    cout << "  Stock Price (S): " << S << "\n";
    cout << "  Strike Price (K): " << K << "\n";
    cout << "  Risk-Free Rate (r): " << r << "\n";
    cout << "  Volatility (sigma): " << sigma << "\n";
    cout << "  Time to Expiration (T): " << T << " years\n";
    
    double callPrice = BlackScholes::calculateCallOptionPrice(S, K, r, sigma, T);
    cout << "\nBlack-Scholes Call Option Price: " << callPrice << "\n";
    cout << "Intrinsic Value (S - K): " << max(0.0, S - K) << "\n";
    cout << "Time Value: " << callPrice - max(0.0, S - K) << "\n";
}

void testInTheMoneyOptions() {
    cout << "\n========== IN-THE-MONEY OPTIONS TEST ==========\n";
    cout << fixed << setprecision(4);
    
    // In-the-money option (Call with K < S)
    double S = 120.0;
    double K = 100.0;
    double r = 0.05;
    double sigma = 0.2;
    double T = 1.0;
    
    cout << "\nTest Parameters (Call with K < S - In-the-Money):\n";
    cout << "  Stock Price (S): " << S << "\n";
    cout << "  Strike Price (K): " << K << "\n";
    cout << "  Risk-Free Rate (r): " << r << "\n";
    cout << "  Volatility (sigma): " << sigma << "\n";
    cout << "  Time to Expiration (T): " << T << " years\n";
    
    double callPrice = BlackScholes::calculateCallOptionPrice(S, K, r, sigma, T);
    cout << "\nBlack-Scholes Call Option Price: " << callPrice << "\n";
    cout << "Intrinsic Value (S - K): " << max(0.0, S - K) << "\n";
    cout << "Time Value: " << callPrice - max(0.0, S - K) << "\n";
}

int main() {
    cout << "========================================================\n";
    cout << "OPTION PRICING MODELS - COMPREHENSIVE TEST SUITE\n";
    cout << "========================================================\n";
    
    // Run all tests
    testBlackScholesModel();
    testBinomialModel();
    testMonteCarloModel();
    testHestonModel();
    testOutOfTheMoneyOptions();
    testInTheMoneyOptions();
    
    cout << "\n========================================================\n";
    cout << "ALL TESTS COMPLETED\n";
    cout << "========================================================\n";
    
    return 0;
}
