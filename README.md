# Projects
starting out c++

when given the loan amount, annual interest rate and number of years of a loan, the program determines 
and display the monthly amount. It then creates and displays an amortization that lists the following information
for each month of the loan:

    - payment number
    - amount of that month's payment was applied to interest
    - amount of that month's payment that was applied to principal
    - balance after that payment

    Calculations:

    Payment = (Load * Rate/12 * Term) / (Term - 1)
    where:
        Loan = the amount of the loan
        Rate = the annual interest rate
        Term = (1+Rate/12) ^ (years*12)
