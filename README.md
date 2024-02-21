# Expense Tracker

## Description
Command-line program written in C++ that allows users to manage their expenses efficiently. Users can add expenses, view existing expenses, calculate the total expenses, save expenses to a file, and load previously saved expenses from a file.

## Features
Add Expense: Users can add new expenses by providing the date, category, and amount.

View Expenses: View a list of all recorded expenses including the date, category, and amount.

Calculate Total Expenses: Calculate and display the total amount of all expenses.

Save Expenses: Save the recorded expenses to a file for future reference.

Load Expenses: Load previously saved expenses from a file into the program.

## Usage
Adding Expenses: Choose option 1 from the menu and input the date (in MM/DD/YYYY format), category, and amount of the expense.

Viewing Expenses: Select option 2 from the menu to see a list of all recorded expenses, including their dates, categories, and amounts.

Calculating Total Expenses: Option 3 calculates the total amount spent across all expenses and displays it to the user.

Saving Expenses: Option 4 allows users to save all recorded expenses to a file named expenses.txt.

Loading Expenses: Upon starting the program, previously saved expenses from expenses.txt are automatically loaded into the program.

Quitting: Select option 5 to exit the program.

### File Structure
expenses.txt: This file stores the recorded expenses in a comma-separated format (date, category, amount).

## How to Run
To run the program, compile the source code (expense.cpp) using a C++ compiler, then execute the compiled binary.

g++ expense.cpp -o expense_tracker

./expense

### Technology Used
C++
