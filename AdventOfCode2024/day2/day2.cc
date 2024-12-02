#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath> // For abs()

// Function to check if the sequence is strictly increasing or strictly decreasing
bool isValid(const std::vector<int>& row) {
    bool increasing = row[0] < row[1];  // Assume the sequence is increasing
    for (size_t i = 0; i < row.size() - 1; ++i) {
        int a = row[i], b = row[i + 1];

        // Check if the difference between adjacent values is within the allowed range
        if (abs(a - b) < 1 || abs(a - b) > 3) {
            return false; // Difference is out of range
        }

        // Check if it's consistently increasing or decreasing
        if ((increasing && a >= b) || (!increasing && a <= b)) {
            return false; // Violates the increasing or decreasing rule
        }
    }
    return true;
}

// Function to try removing one element and check if the row becomes valid
bool isSafeWithOneRemoval(const std::vector<int>& row) {
    // Try removing one element from the row
    for (size_t i = 0; i < row.size(); ++i) {
        std::vector<int> newRow;
        for (size_t j = 0; j < row.size(); ++j) {
            if (j != i) {
                newRow.push_back(row[j]);
            }
        }
        // Check if the row is valid after removing the element
        if (isValid(newRow)) {
            return true;
        }
    }
    return false;
}

int main() {
    std::ifstream file("input.txt");
    if (!file.is_open()) {
        std::cerr << "Cannot open file" << std::endl;
        return 1;
    }

    std::vector<std::vector<int>> matrix;
    std::string line;

    // Read input into matrix
    while (std::getline(file, line)) {
        std::vector<int> row;
        std::istringstream iss(line);
        int value;
        while (iss >> value) {
            row.push_back(value);
        }
        matrix.push_back(row);
    }
    file.close();

    int count = 0;

    // Process each row
    for (const auto& row : matrix) {
        // First check if the row is valid (safe)
        if (isValid(row) || isSafeWithOneRemoval(row)) {
            count++;
        }
    }

    std::cout << count << std::endl;
    return 0;
}
