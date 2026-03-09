#include <iostream>
#include <string>
#include <vector>

struct Category
{
    int id;
    std::string categoryName;
};

struct Expense
{
    int id;
    int categoryId;
    std::string description;
    double amount;
};

int main()
{

    std::vector<Category> categories{{1, "Food"}, {2, "transport"}, {3, "services"}};
    std::vector<Expense> expenses{};
    int optionNumber{};
    bool isValid{false};

    do
    {
        std::cout << "\n--- Available Categories ---\n";
        // Display category list for user selection
        for (const auto &category : categories)
        {

            std::cout << "[" << category.id << "]" << category.categoryName << " ";
        }

        std::cout << "\nSelect one category & add a new expense: ";
        std::cin >> optionNumber;

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

    } while (!isValid);

    if (isValid)
    {
        Expense newEntry{};
        newEntry.categoryId = optionNumber;

        std::cout << "Enter description: ";
        std::getline(std::cin >> std::ws, newEntry.description);

        std::cout << "Enter amount: ";
        std::cin >> newEntry.amount;

        newEntry.id = expenses.size() + 1;

        expenses.push_back(newEntry);
        std::cout << "\n[System]: Expense added successfully.\n";
    }

    return 0;
}