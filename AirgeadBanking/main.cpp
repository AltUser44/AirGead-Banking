/*
 * Airgead Banking Investment App
 * Date: 10/02/2025
 * Author: Jaeyy Nkese
 *
 * This program simulates investment growth with and without monthly deposits.
 * It validates user input, calculates compound interest, and displays
 * yearly balances in two reports.
 *
 * Note: The InvestmentApp class is calculation-only (no cout/cin),
 * and main() handles all user interaction and printing.
 */

#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
#include <cctype>
#include <vector>
#include "InvestmentApp.h"

using std::cin;
using std::cout;
using std::endl;
using std::fixed;
using std::getline;
using std::left;
using std::right;
using std::setprecision;
using std::setw;
using std::string;
using std::numeric_limits;
using std::streamsize;
using std::vector;

// ------------------------- Input helpers (no while(true)) -------------------------

double getPositiveDouble(const string& prompt, bool allowZero = true) {
    double v = 0.0;
    bool ok = false;

    do {
        cout << prompt;
        if (cin >> v) {
            if (v < 0.0 || (!allowZero && v == 0.0)) {
                cout << "Error: value must be "
                    << (allowZero ? "non-negative (>= 0)." : "greater than zero (> 0).")
                    << endl;
            }
            else {
                ok = true;
            }
        }
        else {
            cout << "Error: please enter a numeric value." << endl;
            cin.clear();
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while (!ok);

    return v;
}

int getPositiveInt(const string& prompt, bool allowZero = false) {
    long long n = 0;
    bool ok = false;

    do {
        cout << prompt;
        if (cin >> n) {
            if (n < 0 || (!allowZero && n == 0)) {
                cout << "Error: value must be "
                    << (allowZero ? "non-negative (>= 0)." : "greater than zero (> 0).")
                    << endl;
            }
            else {
                ok = true;
            }
        }
        else {
            cout << "Error: please enter a whole number." << endl;
            cin.clear();
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while (!ok);

    return static_cast<int>(n);
}

bool askYesNo(const string& prompt) {
    string line;
    bool answered = false;
    bool yes = false;

    do {
        cout << prompt;
        getline(cin, line);
        if (!line.empty()) {
            char c = static_cast<char>(std::tolower(line[0]));
            if (c == 'y') { yes = true;  answered = true; }
            else if (c == 'n') { yes = false; answered = true; }
            else { cout << "Please enter Y or N." << endl; }
        }
    } while (!answered);

    return yes;
}

// ------------------------- Printing helpers -------------------------

void printInputs(double initial, double monthly, double rate, int years) {
    cout << "**********************************" << endl;
    cout << "********** Data Input ************" << endl;
    cout << "Initial Investment Amount: $" << initial << endl;
    cout << "Monthly Deposit: $" << monthly << endl;
    cout << "Annual Interest (%): " << rate << endl;
    cout << "Number of years: " << years << endl;
}

void printReport(const string& title, const vector<YearResult>& rows) {
    cout << endl << "  " << title << endl;
    cout << "======================================================================" << endl;
    cout << left << setw(6) << "Year"
        << right << setw(20) << "Year End Balance"
        << right << setw(28) << "Year End Earned Interest" << endl;
    cout << "----------------------------------------------------------------------" << endl;

    cout << fixed << setprecision(2);
    for (const auto& r : rows) {
        cout << left << setw(6) << r.year
            << right << setw(20) << r.endBalance
            << right << setw(28) << r.earnedInterest << endl;
    }
}

// ----------------------------- Program ------------------------------

int main() {
    bool again = true;

    while (again) {
        cout << "**********************************" << endl;
        cout << "********** AIRGEAD BANKING ************" << endl;

        // > 0 for initial & interest; >= 0 allowed for monthly deposit
        double initialInvestment = getPositiveDouble("Initial Investment Amount: $", /*allowZero=*/false);
        double monthlyDeposit = getPositiveDouble("Monthly Deposit: $",            /*allowZero=*/true);
        double annualInterest = getPositiveDouble("Annual Interest (%): ",         /*allowZero=*/false);
        int    numYears = getPositiveInt("Number of years: ",             /*allowZero=*/false);

        printInputs(initialInvestment, monthlyDeposit, annualInterest, numYears);

        cout << endl << "Press Enter to continue . . .";
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // in case nothing pending
        // (No extra wait needed—inputs already consumed.)

        InvestmentApp app(initialInvestment, monthlyDeposit, annualInterest, numYears);

        // Report 1: WITHOUT additional monthly deposits
        auto noDeposit = app.calculateResults(0.0);
        printReport("Balance and Interest Without Additional Monthly Deposits", noDeposit);

        // Report 2: WITH additional monthly deposits
        auto withDeposit = app.calculateResults(monthlyDeposit);
        printReport("Balance and Interest With Additional Monthly Deposits", withDeposit);

        cout << endl;
        again = askYesNo("Run another scenario? (Y/N): ");
        cout << endl;
    }

    return 0;
}
