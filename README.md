# 💰 Personal Finance Tracker (C++ & Web)

A bridge between a high-performance **C++ Backend** and a clean **Web Frontend**. This project allows users to manage their budget through a CLI engine and visualize the data via a dynamic web dashboard.

## 🚀 Key Features

- **C++ Core:** Built using **OOP principles** (Inheritance, Polymorphism, Abstraction).
- **Smart Data Export:** Converts C++ objects into valid **JSON** for web integration.
- **Robust Logic:** Handles input buffer issues (like spaces in names) and validates currency data.
- **Dynamic Dashboard:** A JavaScript frontend that fetches JSON data and calculates totals in real-time.

## 🛠️ Tech Stack

- **Backend:** C++ (Standard Library, File I/O)
- **Frontend:** HTML5, CSS3 (Google Fonts), JavaScript (Async/Fetch API)

## 📖 How to Run

1. Compile the C++ code: `g++ main.cpp transaction.cpp -o BudgetApp`
2. Run the app: `./BudgetApp`
3. Add your transactions and select "Save".
4. Open `index.html` (using Live Server) to see your dashboard!
