**Airgead Banking — Investment App**

A small console application that simulates the growth of an investment with and without monthly deposits. 
It calculates monthly-compounded interest and prints two yearly reports (one without monthly deposits and one with them).


<img width="860" height="572" alt="Screenshot 2025-10-15 205130" src="https://github.com/user-attachments/assets/fd86f6b7-0d5f-4d27-b403-c76c64a5e1f1" />


**Features**

- Interactive console prompts for:
- Initial investment amount
- Monthly deposit
- Annual interest rate (percent)
- Number of years
- Produces two reports (year-by-year):
- Balance and interest without additional monthly deposits
- Balance and interest with additional monthly deposits
- Calculation logic encapsulated in InvestmentApp (no I/O), main.cpp handles UI and printing.



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
- Initial Investment Amount: $10000
- Monthly Deposit: $500
- Annual Interest (%): 5
- Number of years: 10

You will see two tables showing year-end balances and interest earned per year.


**Implementation notes & behavior**

- Monthly deposits are applied at the start of each month, then interest for that month is calculated on the new balance.
- Monthly rate = (annualRatePercent / 100) / 12.
- InvestmentApp::calculateResults(double monthlyDeposit) returns a std::vector<YearResult> with each YearResult containing { year, endBalance, earnedInterest }.
- The calculation class has no console I/O (separation of concerns).
- Edge cases & suggestions
- Input validation is performed in main.cpp (non-negative and >0 checks as appropriate).
- For very large balances or long durations, double precision may lose accuracy — consider fixed-point or a decimal library for financial precision.


**Suggested improvements:**

- Add unit tests for InvestmentApp::calculateResults
- Add a non-interactive CLI mode (flags) for automation
- Add CI to build and run tests


**Contributing**

- Fork the repo
- Create a feature branch
- Add tests where applicable and ensure the project builds
- Open a PR with a clear description



**License**

Owner AltUser44
No license included. Add a LICENSE file (e.g., MIT) if you want to make one explicit.




**Project Summary** 

The Airgead Banking Investment App demonstrates how an investment increases over time, both with additional funds deposited monthly and without reinvesting funds.  
A user may enter the initial sum of money they would like to invest, the number of monthly contributions, an annual interest rate, and the length of time to 'invest' in years. 
The program will then calculate and report on a year-by-year basis, the end-of-year balances and interest earned while utilizing monthly compounding techniques.  
The project showcases my understanding of control structures, mathematical modeling, file organization, and user interaction on the interactive console.


**What I Did Well**

With respect to design, I clearly separated concerns for the program (as much as I could, given the limited scope of the project):
- The InvestmentApp class acquires financial calculations.
- The main.cpp file deals with user input, validation, data storage, and output formatting.
This separation of concerns improved readability, maintainability, and testability, all important elements of good programming style. Furthermore, I followed best practices by making my variable names meaningful, using in-line comments, and being consistent with formatting.


**Areas For Improvement**

In terms of updates, I could improve precision and automation:
Leverage fixed-point arithmetic or a financial library for improved accuracy around numeric values.
Add unit tests to automatically check the output of interest calculations.
Include a non-interactive CLI mode for testing in batches or integration with other systems.


**Most Difficult Aspect**

One of the most difficult aspects of the project was designing a correct interest calculation that applied monthly deposits before monthly compounding. 
I managed this by breaking this problem into smaller steps and checking each piece of the calculation manually using spreadsheets. 
This exercise taught me the value of debugging piecewise and output checks in early development.


**Transferable Skills**

This project consolidated skills related to:
Using object-oriented principles.
Adding input validation and error handling to enhance the security of a program.
Working with modularized code that separates data and the user interface.
Such skills will be transferable into both Python and Java, as well as other languages, and naturally into the development environment of real software.


**Maintainability and Readability**

I made the program as maintainable as possible by using a renaming convention, clear functions, and a modular structure. 
The InvestmentApp class can be fairly easily modified to add new features, such as deposits that occur at variable timeframes, or compounding at alternate intervals, without reworking or re-writing the majority of the program.



