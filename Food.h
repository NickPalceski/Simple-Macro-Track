//
// Created by nicho on 11/11/2023.
//
#include <iostream>
#include <vector>   //track items
#include <iomanip>
#ifndef MACROPROJECT_FOOD_H
#define MACROPROJECT_FOOD_H

// Class to represent a meal with macro info
class Food {
public:
    Food() : calories(0.0), fats(0.0), protein(0.0), carbohydrates(0.0) {}

    void setMacros(double cal, double fat, double prot, double carbs) {
        calories = cal;
        fats = fat;
        protein = prot;
        carbohydrates = carbs;
    }

    // Add an item to the item vector
    void addItem(const std::string& itemName) {
        items.push_back(itemName);
    }

    // Display the food for the current meal (breakfast, lunch, dinner)
    void displayFood(const std::string& foodName) const {
        std::cout << "Food for " << foodName << ":\n";

        for (const auto& item : items) {
            std::cout << "- " << item << "\n";
        }
        // Displays macros for the current meal (breakfast, lunch, dinner)
        std::cout << "\nTotal macros for " << foodName << ":\n";
        std::cout << "     Calories: " << std::setw(5) << getCalories() << "\n";
        std::cout << "         Fats: " << std::setw(5) << getFats() << " g\n";
        std::cout << "      Protein: " << std::setw(5) << getProtein() << " g\n";
        std::cout << "Carbohydrates: " << std::setw(5) << getCarbohydrates() << " g\n";
        std::cout << std::endl;
    }

    // Getter functions
    [[nodiscard]] double getCalories() const { return calories; }
    [[nodiscard]] double getFats() const { return fats; }
    [[nodiscard]] double getProtein() const { return protein; }
    [[nodiscard]] double getCarbohydrates() const { return carbohydrates; }

private:
    std::vector<std::string> items;
    double calories;
    double fats;
    double protein;
    double carbohydrates;
};

#endif //MACROPROJECT_FOOD_H
