

#include <iostream>
#include <iomanip>  // For setting precision
using namespace std;

// get a valid loan amount from the user
double getValidLoan() {
    double loan;
    while (true) {
        cout << "Please enter the loan amount ($1 - $1000): ";
        cin >> loan;
        if (loan >= 1 && loan <= 1000) {
            return loan;
        }
        cout << "That is an invalid value. Please enter a value between $1 and $1000." << endl;
    }
}

// get a valid interest rate from the user
double getValidInterestRate() {
    double rate;
    while (true) {
        cout << "Please enter the interest rate percentage (1.0% - 100.0%): ";
        cin >> rate;
        if (rate >= 1.0 && rate <= 100.0) {
            return rate / 100;  // Convert percentage to decimal
        }
        cout << "That is an invalid value. Please enter a percentage between 1.0% and 100.0%." << endl;
    }
}

// get a valid monthly payment from the user
double getValidPayment(double loanBalance) {
    double payment;
    while (true) {
        cout << "How much do you want to pay each month? (0 - " << fixed << setprecision(2) << loanBalance << "): ";
        cin >> payment;
        if (payment >= 0 && payment <= loanBalance) {
            return payment;
        }
        cout << "That is an invalid value. Please enter a value between $0 and $" << loanBalance << "." << endl;
    }
}

// display the loan repayment table
void displayLoanTable(double loan, double interestRate, double monthlyPayment) {
    cout << endl;
    cout << "Month   Balance        Payment        Interest       New Balance" << endl;
    cout << "----------------------------------------------------------------------" << endl;

    double totalInterest = 0;
    double totalPayments = 0;

    for (int month = 1; month <= 12; ++month) {
        double interest = (loan > 0) ? loan * interestRate : 0;  // No interest if loan is 0
        double newBalance = loan + interest - monthlyPayment;

        // If the loan is paid off early, reset values
        if (loan <= 0) {
            monthlyPayment = 0;
            interest = 0;
            newBalance = 0;
        }

        // Display current month, loan, payment, interest, and new balance
        cout << setw(4) << month << setw(14) << fixed << setprecision(2) << loan
            << setw(14) << monthlyPayment << setw(14) << interest
            << setw(16) << newBalance << endl;

        totalInterest += interest;
        totalPayments += monthlyPayment;

        // Update the loan balance for the next month
        loan = newBalance;
    }

    // Display total payments and interest
    cout << "----------------------------------------------------------------------" << endl;
    cout << "Total                 " << setw(10) << fixed << setprecision(2) << totalPayments
        << setw(14) << totalInterest << endl;
}

// Main function to run the loan calculator
int main() {
    // Get valid inputs from the user
    double loan = getValidLoan();
    double interestRate = getValidInterestRate();
    double monthlyPayment = getValidPayment(loan);

    // Display the loan repayment table
    displayLoanTable(loan, interestRate, monthlyPayment);

    return 0;
}
