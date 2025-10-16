**Airgead Banking — Investment App**

A small console application that simulates the growth of an investment with and without monthly deposits. 
It calculates monthly-compounded interest and prints two yearly reports (one without monthly deposits and one with them).


<img width="860" height="572" alt="Screenshot 2025-10-15 205130" src="https://github.com/user-attachments/assets/fd86f6b7-0d5f-4d27-b403-c76c64a5e1f1" />

**Features**

Interactive console prompts for:
Initial investment amount
Monthly deposit
Annual interest rate (percent)
Number of years
Produces two reports (year-by-year):
Balance and interest without additional monthly deposits
Balance and interest with additional monthly deposits
Calculation logic encapsulated in InvestmentApp (no I/O), main.cpp handles UI and printing.


**Quick build (Windows)**

1) Visual Studio
Open AirgeadBanking.sln and build the solution (Debug or Release).

2) PowerShell + MinGW/g++
Compile both translation units into an executable. Adjust the g++ path if necessary.

& "C:/Users/User/Downloads/winlibs-x86_64-posix-seh-gcc-15.2.0-mingw-w64ucrt-13.0.0-r1/mingw64/bin/g++.exe" `
  -g `
  "C:/Users/User/Downloads/AirgeadBanking/AirgeadBanking/main.cpp" `
  "C:/Users/User/Downloads/AirgeadBanking/AirgeadBanking/InvestmentApp.cpp" `
  -o "C:/Users/User/Downloads/AirgeadBanking/x64/Debug/AirgeadBanking.exe"


**The program will prompt for the inputs interactively.**

Example inputs
Initial Investment Amount: $10000
Monthly Deposit: $500
Annual Interest (%): 5
Number of years: 10
You will see two tables showing year-end balances and interest earned per year.

**Implementation notes & behavior**

Monthly deposits are applied at the start of each month, then interest for that month is calculated on the new balance.
Monthly rate = (annualRatePercent / 100) / 12.
InvestmentApp::calculateResults(double monthlyDeposit) returns a std::vector<YearResult> with each YearResult containing { year, endBalance, earnedInterest }.
The calculation class has no console I/O (separation of concerns).
Edge cases & suggestions
Input validation is performed in main.cpp (non-negative and >0 checks as appropriate).
For very large balances or long durations, double precision may lose accuracy — consider fixed-point or a decimal library for financial precision.

**Suggested improvements:**

Add unit tests for InvestmentApp::calculateResults
Add a non-interactive CLI mode (flags) for automation
Add CI to build and run tests

**Contributing**

Fork the repo
Create a feature branch
Add tests where applicable and ensure the project builds
Open a PR with a clear description

**License**
Owner AltUser44
No license included. Add a LICENSE file (e.g., MIT) if you want to make one explicit.


