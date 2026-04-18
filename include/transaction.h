#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>

using namespace std;

/**
 * I designed this base class to act as a blueprint for any financial movement.
 * By making 'getJson' a pure virtual function, I'm forcing any new type of 
 * transaction (like a Refund or Investment in the future) to provide its 
 * own JSON format. This is the core of Abstraction in my project.
 */
class Transaction {
protected:
    // I used 'protected' so that my child classes (Income/Expense) 
    // can access these variables directly without needing extra getters.
    string category;
    double amount;
    string date;

public:
    Transaction(string cat, double amt, string dt);

    // I added a virtual destructor here to ensure that when I delete 
    // a Transaction pointer, the memory for the derived classes is 
    // cleaned up properly—preventing memory leaks!
    virtual ~Transaction() {} 
    
    // This makes the class 'Abstract'. I don't want anyone to create 
    // a generic "Transaction" object; it has to be either Income or Expense.
    virtual string getJson() const = 0; 
};

/**
 * Expense Class: Inherits from Transaction.
 * I'm using this to specifically handle money going out.
 */
class Expense : public Transaction {
public:
    Expense(string cat, double amt, string dt);

    // 'override' tells the compiler I'm intentionally replacing the base 
    // behavior. This helps catch errors if I mistype the function signature.
    string getJson() const override;
};

/**
 * Income Class: Inherits from Transaction.
 * Same logic as Expense, but it represents money coming in.
 */
class Income : public Transaction {
public:
    Income(string cat, double amt, string dt);
    string getJson() const override;
};

#endif