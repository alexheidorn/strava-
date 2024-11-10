//
// Created by alexh on 11/10/2024.
//

#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

int main() {
    // Open example JSON file
    std::ifstream file("JSONs/example.json");
    if (!file.is_open())
    {
        std::cerr << "Failed to open file" << std::endl;
        return 1;
    }
    
    json data = json::parse(file);

    std::cout << data << std::endl;

    file.close();
    
    return 0;
}