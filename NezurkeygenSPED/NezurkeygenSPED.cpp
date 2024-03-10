#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

std::string generateRandomString() {
    const std::string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    const int length = 6;
    std::string randomString;

    for (int i = 0; i < length; ++i) {
        randomString += characters[rand() % characters.length()];
    }

    return randomString;
}

std::string generateFormattedString(int count) {
    std::string formattedString = "nezur-";
    for (int i = 0; i < count; ++i) {
        formattedString += generateRandomString();
        if (i != count - 1)
            formattedString += "-";
    }
    return formattedString;
}

int main() {
    int numberOfStrings;
    std::cout << "How many keys u want? :3 ";
    std::cin >> numberOfStrings;

    srand(static_cast<unsigned int>(time(0)));

    std::ofstream outputFile("KeysUwU.txt");
    if (!outputFile) {
        std::cerr << "Error making key file" << std::endl;
        return 1;
    }

    for (int i = 0; i < numberOfStrings; ++i) {
        std::string randomString = generateFormattedString(6);
        outputFile << randomString << std::endl;

        // Print progress percentage
        float progress = (static_cast<float>(i + 1) / numberOfStrings) * 100;
        std::cout << "\rProgress: " << progress << "%";
        std::cout.flush();
    }

    outputFile.close();
    std::cout << "\nkeys made check output file :3'." << std::endl;

    return 0;
}
