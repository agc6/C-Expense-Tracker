#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

struct Expense {
    string date;
    string category;
    double amount;
};

//Categories for the added expense
void addExpense(vector<Expense> &expenses) {
    Expense newExpense;
    cout << "Enter date (MM/DD/YYYY): ";
    cin >> newExpense.date;
    cout << "Enter category: ";
    cin >> newExpense.category;
    cout << "Enter amount: ";
    cin >> newExpense.amount;
    expenses.push_back(newExpense);
}

//Formatted Date
void viewExpenses(const vector<Expense> &expenses) {
    cout << "Date\t\tCategory\tAmount" << endl;
    for (const Expense &exp : expenses) {
        cout << exp.date << "\t" << exp.category << "\t\t$" << exp.amount << endl;
    }
}

double calculateTotalExpenses(const vector<Expense> &expenses) {
    double total = 0;
    for (const Expense &exp : expenses) {
        total += exp.amount;  //Calculate the total amount of expenses by summing up the amount attribute 
    }
    return total;
}

//Open a file with the specified filename
//Write each Expense object's date, category, and amount to the file
void saveExpenses(const vector<Expense> &expenses, const string &filename) {
    ofstream file(filename);
    if (file.is_open()) {
        for (const Expense &exp : expenses) {
            file << exp.date << "," << exp.category << "," << exp.amount << endl;
        }
        file.close();
        cout << "Expenses saved to " << filename << endl;
    } else {
        cout << "Unable to open file for saving expenses." << endl;
    }
}

//Expense objects are then added to the vector
void loadExpenses(vector<Expense> &expenses, const string &filename) {
    ifstream file(filename);
    if (file.is_open()) {
        Expense exp;
        while (getline(file, exp.date, ',') && getline(file, exp.category, ',') && file >> exp.amount) {
            expenses.push_back(exp);
        }
        file.close();
        cout << "Expenses loaded from " << filename << endl;
    } else {
        cout << "No previous expenses found." << endl;
    }
}

int main() {
    vector<Expense> expenses;
    string filename = "expenses.txt";
    loadExpenses(expenses, filename);


    //Menu choices for user
    int choice;
    do {
        cout << "\nExpense Tracker Menu:\n";
        cout << "1. Add Expense\n";
        cout << "2. View Expenses\n";
        cout << "3. Calculate Total Expenses\n";
        cout << "4. Save Expenses\n";
        cout << "5. Quit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addExpense(expenses);
                break;
            case 2:
                viewExpenses(expenses);
                break;
            case 3:
                cout << "Total Expenses: $" << calculateTotalExpenses(expenses) << endl;
                break;
            case 4:
                saveExpenses(expenses, filename);
                break;
            case 5:
                cout << "Exiting...";
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
