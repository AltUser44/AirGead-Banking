#ifndef INVESTMENTAPP_H
#define INVESTMENTAPP_H

#include <vector>

// Holds one year's results for reporting
struct YearResult {
    int    year;
    double endBalance;
    double earnedInterest;
};

// Encapsulates investment parameters and performs calculations.
// This class does NOT print or read from the console.
class InvestmentApp {
public:
    // Construct with starting values
    InvestmentApp(double initial, double defaultMonthly, double annualRatePercent, int years);

    // Calculates yearly results for the given monthly deposit (use 0.0 for "no deposits").
    // Returns a vector of YearResult (one entry per year).
    std::vector<YearResult> calculateResults(double monthlyDeposit) const;

    // Accessors (optional if you want them)
    double getInitial()        const { return m_initial; }
    double getAnnualRatePct()  const { return m_annualRatePercent; }
    double getDefaultMonthly() const { return m_defaultMonthly; }
    int    getYears()          const { return m_years; }

private:
    double m_initial;
    double m_defaultMonthly;
    double m_annualRatePercent;
    int    m_years;
};

#endif // INVESTMENTAPP_H
