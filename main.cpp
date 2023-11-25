#include <iostream>
#include <string>
#include <limits> // used to deal with buffers
#include "Food.h"

// Function to get multiple foods with error handling
void getFoodItems(Food& food) {
    std::string item;
    char addItem = 'y';
    int itemCount = 1;

    // loop 1 to continue adding items
    while (addItem == 'y' || addItem == 'Y') {
        bool validItem = false;

        // loop 2 validate current item
        while (!validItem) {
            try {   //try 1
                std::cout << "Item " << itemCount << ": ";

                // read whole line for item (disregard whitespace)
                std::getline(std::cin >> std::ws, item);

                // Validate that the item name has no numbers
                for (char c : item) {
                    if (std::isdigit(c)) {
                        throw std::invalid_argument("Invalid input. Please enter letters for the item name.");
                    }
                }

                validItem = true; // Exit the loop if the item name is valid

                double cal, fat, prot, carbs;
                bool validInput = false;

                // loop 3 to validate macro info
                while (!validInput) {
                    try {   //try 2
                        std::cout << "Enter macros for " << item << " (calories, fats, protein, carbohydrates): \n";
                        std::cin >> cal >> fat >> prot >> carbs;

                        // Check if non-numerical
                        if (std::cin.fail()) {
                            throw std::invalid_argument("Invalid input. Please enter numbers for the macros.\n");
                        }

                        // Update total macros for current meal
                        food.setMacros(food.getCalories() + cal, food.getFats() + fat, food.getProtein() + prot, food.getCarbohydrates() + carbs);

                        // Add item to the current meal
                        food.addItem(item);

                        validInput = true; // Input is valid, exit the loop

                    } catch (const std::invalid_argument& e) {  //try 2
                        std::cerr << "Error: " << e.what() << std::endl;
                        std::cin.clear(); // clear the error flag
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
                    }
                }

            } catch (const std::invalid_argument& e) {  //try 1
                std::cerr << "Error: " << e.what() << std::endl;
                std::cin.clear(); // clear the error flag
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
            }
        }
        std::cout << "Do you want to add another food? (y/n): ";
        std::cin >> addItem;

        itemCount++;
    }
}

void displayTotalMacros(double cal, double fats, double prot, double carbs) {
    std::cout << "\nTotal macros for the day:\n";
    std::cout << "     Calories: " << std::setw(5) << cal << "\n";
    std::cout << "         Fats: " << std::setw(5) << fats << " g\n";
    std::cout << "      Protein: " << std::setw(5) << prot << " g\n";
    std::cout << "Carbohydrates: " << std::setw(5) << carbs << " g\n";
}

int main() {
    // Create instances for class Food
    Food breakfast, lunch, dinner;

    // Enter meal info
    std::cout << "Enter foods for breakfast:\n";
    getFoodItems(breakfast);
    std::cout << "-----------------------------------\n";
    std::cout << "Enter foods for lunch:\n";
    getFoodItems(lunch);
    std::cout << "-----------------------------------\n";
    std::cout << "Enter foods for dinner:\n";
    getFoodItems(dinner);
    std::cout << "-----------------------------------\n";

    // Display meal information
    std::cout << "\nFood Information\n";
    std::cout << "-----------------------------------\n";
    breakfast.displayFood("Breakfast");
    std::cout << "-----------------------------------\n";
    lunch.displayFood("Lunch");
    std::cout << "-----------------------------------\n";
    dinner.displayFood("Dinner");
    std::cout << "-----------------------------------\n";

    // Calculate total macros for the day
    double totalCalories = breakfast.getCalories() + lunch.getCalories() + dinner.getCalories();
    double totalFats = breakfast.getFats() + lunch.getFats() + dinner.getFats();
    double totalProtein = breakfast.getProtein() + lunch.getProtein() + dinner.getProtein();
    double totalCarbohydrates = breakfast.getCarbohydrates() + lunch.getCarbohydrates() + dinner.getCarbohydrates();

    // Show total macros
    displayTotalMacros(totalCalories, totalFats, totalProtein, totalCarbohydrates);
    std::cout << "-----------------------------------\n";

    return 0;
}