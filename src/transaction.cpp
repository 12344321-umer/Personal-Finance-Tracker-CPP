#include "transaction.h"
#include <sstream>

using namespace std;

/**
 * I'm using a Member Initializer List here. 
 * It's faster than assigning values inside the curly braces because it 
 * initializes the variables at the same time they are created.
 */
Transaction::Transaction(string cat, double amt, string dt) 
    : category(cat), amount(amt), date(dt) {}

/**
 * For the Expense and Income classes, I don't need to rewrite the 
 * initialization logic. I just pass the data up to the base 
 * Transaction constructor—this keeps my code DRY (Don't Repeat Yourself).
 */
Expense::Expense(string cat, double amt, string dt) 
    : Transaction(cat, amt, dt) {}

/**
 * I decided to build the JSON string manually. 
 * This shows how I'm bridging the gap between C++ data types 
 * and a format that my JavaScript frontend can easily understand.
 */
string Expense::getJson() const {
    return "{\"type\": \"Expense\", \"category\": \"" + category + 
           "\", \"amount\": " + to_string(amount) + 
           ", \"date\": \"" + date + "\"}";
}

Income::Income(string cat, double amt, string dt) 
    : Transaction(cat, amt, dt) {}

/**
 * Same logic here for Income. 
 * By using the 'const' keyword at the end of these functions, 
 * I'm promising the compiler that this method won't accidentally 
 * change any of my object's data.
 */
string Income::getJson() const {
    return "{\"type\": \"Income\", \"category\": \"" + category + 
           "\", \"amount\": " + to_string(amount) + 
           ", \"date\": \"" + date + "\"}";
}