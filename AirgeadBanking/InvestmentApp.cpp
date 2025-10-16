#include "InvestmentApp.h"

// NOTE: No iostream here. This class only does calculations.

InvestmentApp::InvestmentApp(double initial,
    double defaultMonthly,
    double annualRatePercent,
    int years)
    : m_initial(initial),
    m_defaultMonthly(defaultMonthly),
    m_annualRatePercent(annualRatePercent),
    m_years(years) {
}

// Calculate a yearly schedule with the specified monthly deposit.
// If monthlyDeposit == 0.0, this naturally becomes the "no deposits" case.
std::vector<YearResult> InvestmentApp::calculateResults(double monthlyDeposit) const {
    std::vector<YearResult> out;
    out.reserve(static_cast<std::size_t>(m_years));

    double balance = m_initial;
    const double rMonth = (m_annualRatePercent / 100.0) / 12.0;

    for (int y = 1; y <= m_years; ++y) {
        double yearInterest = 0.0;

        for (int m = 0; m < 12; ++m) {
            balance += monthlyDeposit;           // deposit for the month (0 if none)
            const double interest = balance * rMonth;
            yearInterest += interest;
            balance += interest;
        }

        out.push_back(YearResult{ y, balance, yearInterest });
    }

    return out;
}
