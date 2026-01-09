#include ".\header\binomial.h"
#include ".\header\black_scholes.h"
#include ".\header\heston.h"
#include ".\header\monte_carlo.h"

#include <iostream>
using namespace std;

void binomial() {
    // Implementation of Binomial model goes here
    return;
}

void blackScholes() {
    // Implementation of Black-Scholes model goes here
    return;
}

void heston() {
    // Implementation of Heston model goes here
    return;
}

void monteCarlo() {
    // Implementation of Monte Carlo simulation goes here
    return;
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
            monteCarlo();
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