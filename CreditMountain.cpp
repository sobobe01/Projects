#include <iostream>
#include <cmath>
#include <vector>
#include <ctime>
#include <iomanip>
#include <string>
#include <numeric>
#include <stdio.h>
using namespace std;


int main()
{
    double loan,                //Loan amount
            rate,               //Annual interest rate
            moInterestRate,     //Monthly interest rate
            years,              //Years of loan
            balance,            //Monthly balance
            term,               //Used to calculate payment
            payment;            //Monthly payment
    int     numPayments;        //Number of payment


    //Get loan information
    cout << "Loan amount: $";
    cin  >> loan;
    while ( loan < 0)
    {
        cout << "Invalid loan, enter a valid loan" << endl;
        cin >> loan;
    }
    cout << "Annual interest rate (entered as a decimal): ";
    cin  >> rate;
    while (rate < 0)
    {
        cout << "Invalid rate, enter a valid rate" << endl;
        cin >> rate;
    }
    cout << "Years of loan: ";
    cin  >> years;
    while (years < 0)
    {
        cout <<"Invalid year, enter a valid year" << endl;
    }


    // Calculate monthly payment
    numPayments = static_cast<int>(12 * years);
    moInterestRate = rate / 12.0;
    term = pow ((1 + moInterestRate), numPayments);
    payment = (loan * moInterestRate * term) / (term - 1.0);

    // Display monthly payment
    cout << fixed << showpoint << setprecision(2);
    cout << "Monthly payment: $" << payment << endl;

    //display report header
    cout << endl;
    cout << setw(5) << "Month"  << setw(10) << "Interest";
    cout << setw(10) << "Principal" << setw(9) << "Balance" << endl;
    cout << "------------------------------------\n";

    balance = loan;   //Remaining balance starts out as full loan amount

    //Produce a listing for each month
    for (int month = 1; month <= numPayments; month++)
    {
        double moInterest,          //Amount of pmt that pays interest
               principal;           //Amount of pmt that lowers the balance

        // Calculate amount paid for this month's interest and principal
        moInterest = moInterestRate * balance;  //Calculate interest first
        if (month != numPayments)               //if not the final month
            principal = payment - moInterest;   //rest of pmt goes to principal
        
        else                                    //It's the last month so
        {
            principal = balance;                //pay exact final balance
            payment   = balance + moInterest;
        }
        // Calculate new loan balance           //only principal reduces the balance, not the whole pmt
        balance -= principal;

        //Display this month's payment figures
        cout << setw(4) << month << setw(10) << moInterest;
        cout << setw(10) << principal << setw(10) << balance << endl;
        
    }
    return 0;
}





