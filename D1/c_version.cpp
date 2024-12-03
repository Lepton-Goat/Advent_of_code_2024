#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <sstream>
#include <chrono> // For timing

int main() {
    using namespace std::chrono;

    // Start timing
    auto start = high_resolution_clock::now();

    // File path
    std::string filePath = "input.csv";

    // Data storage
    std::vector<int> id1, id2;

    // Read the CSV file
    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file " << filePath << std::endl;
        return 1;
    }

    std::string line;
    // Skip header line if there is one
    std::getline(file, line);

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string item;
        int a, b;

        if (std::getline(ss, item, ',')) {
            a = std::stoi(item);
        }
        if (std::getline(ss, item, ',')) {
            b = std::stoi(item);
        }

        id1.push_back(a);
        id2.push_back(b);
    }
    file.close();

    // Count occurrences of each number in id2
    std::unordered_map<int, int> countMap;
    for (int num : id2) {
        countMap[num]++;
    }

    // Calculate the score
    long long score = 0;
    for (int num : id1) {
        if (countMap.find(num) != countMap.end()) {
            score += static_cast<long long>(num) * countMap[num];
        }
    }

    // End timing
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end - start);

    // Output the score and runtime
    std::cout << "Score: " << score << std::endl;
    std::cout << "Execution Time: " << duration.count() << " microseconds" << std::endl;

    return 0;
}
