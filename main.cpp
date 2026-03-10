#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // Required for std::find_if
#include <iomanip>   // Required for std::setw and std::setprecision
#include <numeric>

// Blueprint for expense categories
struct Category
{
    int id;
    std::string categoryName;
};

// Blueprint for a single expense transaction
struct Expense
{
    int id;
    int categoryId; // Foreign Key: Links to Category.id
    std::string description;
    double amount;
};

int main()
{
    // Initial catalog of available categories
    std::vector<Category> categories{{1, "Food"}, {2, "Transport"}, {3, "Services"}};

    // Ledger to store all user-created expenses
    std::vector<Expense> expenses{};

    char answerReset{};
    bool keepRunning{true}; // Controls the application main loop

    // --- MAIN INPUT LOOP ---
    while (keepRunning)
    {
        int optionNumber{};
        bool isValid{false};

        // VALIDATION LOOP: Ensures the user selects an existing category ID
        do
        {
            std::cout << "\n--- Available Categories ---\n";

            for (const auto &category : categories)
            {
                std::cout << "[" << category.id << "] " << category.categoryName << " ";
            }

            std::cout << "\nChoice: ";
            std::cin >> optionNumber;

            // Manual ID existence check
            for (const auto &category : categories)
            {
                if (category.id == optionNumber)
                {
                    isValid = true;
                    break;
                }
            }

            if (!isValid)
            {
                std::cout << "Error: ID " << optionNumber << " not found. Try again.\n";
            }

        } while (!isValid); // Remains in loop until ID is valid

        // Expense data capture
        Expense newEntry{};
        newEntry.categoryId = optionNumber;

        std::cout << "Enter description: ";
        // Using std::ws to consume leading whitespace/newlines before getline
        std::getline(std::cin >> std::ws, newEntry.description);

        std::cout << "Enter amount: ";
        std::cin >> newEntry.amount;

        // Auto-increment ID based on current vector size and commit to ledger
        newEntry.id = expenses.size() + 1;
        expenses.push_back(newEntry);

        // Exit control for the Main Loop
        std::cout << "\nAdd another expense? (y/n): ";
        std::cin >> answerReset;

        if (answerReset == 'n' || answerReset == 'N')
        {
            keepRunning = false;
        }
    }

    // --- FINAL REPORT GENERATION ---
    std::cout << "\n"
              << std::string(60, '-') << "\n";
    std::cout << std::left << std::setw(5) << "ID"
              << std::setw(15) << "Category"
              << std::setw(25) << "Description"
              << "Amount\n";
    std::cout << std::string(60, '-') << "\n";

    for (const auto &item : expenses)
    {
        // Using std::find_if to link the category name via its ID
        // [item] captures the current expense, (const Category &c) represents each element in 'categories'
        auto it = std::find_if(categories.begin(), categories.end(), [item](const Category &c)
                               { return c.id == item.categoryId; });

        // Safety check: verify the iterator before accessing members
        if (it != categories.end())
        {
            std::cout << std::left << std::setw(5) << item.id
                      << std::setw(15) << it->categoryName
                      << std::setw(25) << item.description
                      << "$" << std::fixed << std::setprecision(2) << item.amount << "\n";
        }
    }

    double totalSum = std::accumulate(expenses.begin(), expenses.end(), 0.0,
                                      [](double currentTotal, const Expense &e)
                                      {
                                          return currentTotal + e.amount;
                                      });

    std::cout << std::right << std::setw(45) << "TOTAL: "
              << "$" << std::fixed << std::setprecision(2) << totalSum << "\n";
    std::cout << std::string(60, '=') << "\n";
    std::cout << std::string(60, '-') << "\n";

    return 0;
}