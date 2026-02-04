#include ".\header\binomial.h"
#include ".\header\black_scholes.h"
#include ".\header\heston.h"
#include ".\header\monte_carlo.h"

#include <iostream>
using namespace std;

void binomial() {
    double S, K, r, sigma, T;
    int steps;
    
    cout << "Enter Stock Price: ";
    cin >> S;
    cout << "Enter Strike Price: ";
    cin >> K;
    cout << "Enter Risk-Free Rate: ";
    cin >> r;
    cout << "Enter Volatility: ";
    cin >> sigma;
    cout << "Enter Time (in years): ";
    cin >> T;
    cout << "Enter Number of Steps: ";
    cin >> steps;
    
    double callPrice = BinomialModel::calculateOptionPrice(S, K, r, sigma, T, steps, true, false);
    double putPrice = BinomialModel::calculateOptionPrice(S, K, r, sigma, T, steps, false, false);
    
    cout << "\nBinomial Model Results:\n";
    cout << "European Call Price: " << callPrice << "\n";
    cout << "European Put Price: " << putPrice << "\n";
}

void blackScholes() {
    double S, K, r, sigma, T;
    
    cout << "Enter Stock Price: ";
    cin >> S;
    cout << "Enter Strike Price: ";
    cin >> K;
    cout << "Enter Risk-Free Rate: ";
    cin >> r;
    cout << "Enter Volatility: ";
    cin >> sigma;
    cout << "Enter Time (in years): ";
    cin >> T;
    
    double callPrice = BlackScholes::calculateCallOptionPrice(S, K, r, sigma, T);
    double putPrice = BlackScholes::calculatePutOptionPrice(S, K, r, sigma, T);
    
    cout << "\nBlack-Scholes Model Results:\n";
    cout << "Call Option Price: " << callPrice << "\n";
    cout << "Put Option Price: " << putPrice << "\n";
}

void heston() {
     double S, K, r, v0, kappa, theta, sigma, rho, T;
    int simulations, steps;
    
    cout << "Enter Stock Price: ";
    cin >> S;
    cout << "Enter Strike Price: ";
    cin >> K;
    cout << "Enter Risk-Free Rate: ";
    cin >> r;
    cout << "Enter Initial Variance (v0): ";
    cin >> v0;
    cout << "Enter Mean Reversion Speed (kappa): ";
    cin >> kappa;
    cout << "Enter Long-term Variance (theta): ";
    cin >> theta;
    cout << "Enter Volatility of Volatility (sigma): ";
    cin >> sigma;
    cout << "Enter Correlation (rho): ";
    cin >> rho;
    cout << "Enter Time (in years): ";
    cin >> T;
    cout << "Enter Number of Simulations: ";
    cin >> simulations;
    cout << "Enter Number of Steps: ";
    cin >> steps;
    
    double callPrice = HestonModel::calculateOptionPriceMC(S, K, r, v0, kappa, theta, sigma, rho, T, simulations, steps, true);
    double putPrice = HestonModel::calculateOptionPriceMC(S, K, r, v0, kappa, theta, sigma, rho, T, simulations, steps, false);
    
    cout << "\nHeston Model Results:\n";
    cout << "Call Option Price: " << callPrice << "\n";
    cout << "Put Option Price: " << putPrice << "\n";
}

void monteCarloMenu() {
    double strikePrice, initialStockPrice, rate, volatility, time;
    cout << "Enter Strike Price: ";
    cin >> strikePrice;
    cout << "Enter Initial Stock Price: ";
    cin >> initialStockPrice;
    cout << "Enter Risk-Free Rate: ";
    cin >> rate;
    cout << "Enter Volatility: ";
    cin >> volatility;
    cout << "Enter Time (in years): ";
    cin >> time;
    double price = MonteCarlo::calculateOptionPrice(strikePrice, initialStockPrice, rate, volatility, time);
    cout << "\nMonte Carlo Price: " << price << "\n";
}

void displayMenu() {
    cout << "\n--------------Option Pricing Model Library--------------\n\n";
    cout << "Choose a model to proceed:\n";
    cout << "1. Binomial Model\n";
    cout << "2. Black-Scholes Model\n";
    cout << "3. Heston Model\n";
    cout << "4. Monte Carlo Simulation\n";
    cout << "\nEnter your choice (1 - 4): ";
}

void choose() {
    int choice;
    cin >> choice;
    switch (choice) {
        case 1:
            cout << "\n--------------------------------------------------------";
            cout << "\nYou selected Binomial Model.\n";
            binomial();
            break;
        case 2:
            cout << "\n--------------------------------------------------------";
            cout << "\nYou selected Black-Scholes Model.\n";
            blackScholes();
            break;
        case 3:
            cout << "\n--------------------------------------------------------";
            cout << "\nYou selected Heston Model.\n";
            heston();
            break;
        case 4:
            cout << "\n--------------------------------------------------------";
            cout << "\nYou selected Monte Carlo Simulation.\n";
            monteCarloMenu();
            break;
        default:
            cout << "\nInvalid choice. Please select a valid option (1 - 4): ";
            choose();
            break;
    }
}

int main() {
    displayMenu();
    choose();
    return 0;
}