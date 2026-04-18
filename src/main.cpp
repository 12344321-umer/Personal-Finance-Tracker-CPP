#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "transaction.h"

// I'm using the standard namespace to keep the logic focused and clean.
using namespace std;

int main() {
    // I’m using a vector of base-class pointers. This is a classic 
    // example of Polymorphism—storing different derived objects 
    // (Income/Expense) in a single list.
    vector<Transaction*> myLedger;
    int menuChoice = 0;

    cout << "========================================" << endl;
    cout << "      PERSONAL FINANCE TRACKER (C++)    " << endl;
    cout << "========================================" << endl;
    cout << "   Logic Engine for my Web Dashboard    " << endl;
    cout << "========================================" << endl;

    while (true) {
        cout << "\n[MAIN MENU]" << endl;
        cout << "1. Record an Income" << endl;
        cout << "2. Record an Expense" << endl;
        cout << "3. Save and Update Dashboard" << endl;
        cout << "4. Quit Without Saving" << endl;
        cout << "What would you like to do? ";
        
        // Error Handling: Ensuring the user enters a valid number for the menu.
        if (!(cin >> menuChoice)) {
            cout << "Oops! That's not a number. Please enter 1, 2, 3, or 4." << endl;
            cin.clear(); 
            cin.ignore(1000, '\n'); 
            continue;
        }

        // I need to clear the newline character left by 'cin >>' 
        // so that the 'getline' below doesn't get skipped.
        cin.ignore(1000, '\n');

        if (menuChoice == 3) break; // Exit loop to save
        if (menuChoice == 4) {
            // Memory Management: Clean up before closing without saving.
            for (auto t : myLedger) delete t;
            return 0;
        }

        string userCategory, userDate;
        double userAmount;

        // Using getline so categories can have spaces (e.g., "Trip to North").
        cout << "Category (e.g. Food, Salary, Bill): ";
        getline(cin, userCategory);

        cout << "Amount (Rs.): ";
        // Validation: Making sure the amount is a valid positive number.
        while (!(cin >> userAmount) || userAmount < 0) {
            cout << "Invalid amount. Please enter a positive number: ";
            cin.clear();
            cin.ignore(1000, '\n');
        }

        cout << "Date (YYYY-MM-DD): ";
        cin >> userDate;

        if (menuChoice == 1) {
            myLedger.push_back(new Income(userCategory, userAmount, userDate));
            cout << "Successfully added Income!" << endl;
        } else if (menuChoice == 2) {
            myLedger.push_back(new Expense(userCategory, userAmount, userDate));
            cout << "Successfully added Expense!" << endl;
        } else {
            cout << "Invalid selection. Please try again." << endl;
        }
    }

    // --- DATA EXPORT ---
    // Here, I'm writing the data to a JSON file. This acts as the 
    // "database" for my Web Dashboard.
    ofstream budgetFile("data.json");
    
    if (budgetFile.is_open()) {
        budgetFile << "[\n";
        for (size_t i = 0; i < myLedger.size(); ++i) {
            budgetFile << "  " << myLedger[i]->getJson();
            // JSON requires a comma between items, but NOT after the last one.
            if (i != myLedger.size() - 1) {
                budgetFile << ",";
            }
            budgetFile << "\n";
        }
        budgetFile << "]";
        budgetFile.close();
        
        cout << "\n[SYSTEM] Data saved successfully." << endl;
        cout << "[INFO] Refresh your web browser to see the updated dashboard!" << endl;
    } else {
        cerr << "\n[ERROR] Could not open data.json for writing. Check folder permissions." << endl;
    }

    // --- CLEANUP ---
    // Since I used 'new', I'm manually deleting these objects to 
    // demonstrate good memory management and avoid leaks.
    for (auto t : myLedger) {
        delete t;
    }
    myLedger.clear();

    return 0;
}