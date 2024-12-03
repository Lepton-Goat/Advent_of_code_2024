#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <chrono> // For timing

int main() {
    using namespace std::chrono;

    // Start timing
    auto start_time = high_resolution_clock::now();

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

    int a, b;
    char comma;

    // Read the file directly into the vectors
    while (file >> a >> comma >> b) {
        id1.push_back(a);
        id2.push_back(b);
    }
    file.close();

    // Count occurrences in id2
    std::unordered_map<int, int> countMap;
    for (int num : id2) {
        countMap[num]++;
    }

    // Calculate the score directly
    long long score = 0;
    for (int num : id1) {
        auto it = countMap.find(num);
        if (it != countMap.end()) {
            score += static_cast<long long>(num) * it->second;
        }
    }

    // End timing
    auto end_time = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(end_time - start_time);

    // Output the score and runtime
    std::cout << "Score: " << score << std::endl;
    std::cout << "Execution Time: " << duration.count() << " µs" << std::endl;

    return 0;
}
