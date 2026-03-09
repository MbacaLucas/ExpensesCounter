#include <iostream>
#include <string>
#include <vector>

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
    std::vector<Category> categories{{1, "Food"}, {2, "transport"}, {3, "services"}};

    // Ledger to store all user-created expenses
    std::vector<Expense> expenses{};

    int optionNumber{};
    bool isValid{false};

    // Validation loop: ensures the user selects an existing category ID
    do
    {
        std::cout << "\n--- Available Categories ---\n";

        // Print all categories using a range-based for loop (read-only)
        for (const auto &category : categories)
        {
            std::cout << "[" << category.id << "]" << category.categoryName << " ";
        }

        std::cout << "\nSelect one category & add a new expense: ";
        std::cin >> optionNumber;

        // Check if the input ID matches any category in the catalog
        for (const auto &category : categories)
        {
            if (category.id == optionNumber)
            {
                isValid = true;
                break; // Exit search loop once found
            }
        }

        if (!isValid)
        {
            std::cout << "Error: ID " << optionNumber << " not found. Try again.\n";
        }

    } while (!isValid);

    // Proceed only if the category ID was successfully validated
    if (isValid)
    {
        Expense newEntry{}; // Temporary object to hold the new record
        newEntry.categoryId = optionNumber;

        std::cout << "Enter description: ";
        // Using std::ws to consume leading whitespace/newlines before getline
        std::getline(std::cin >> std::ws, newEntry.description);

        std::cout << "Enter amount: ";
        std::cin >> newEntry.amount;

        // Auto-increment ID based on current vector size
        newEntry.id = expenses.size() + 1;

        // Commit the new expense to the ledger
        expenses.push_back(newEntry);
        std::cout << "\n[System]: Expense added successfully.\n";
    }

    return 0;
}