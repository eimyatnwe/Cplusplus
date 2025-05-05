#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

class Mapper {
public:
    static std::vector<std::pair<std::string, int>> map(const std::string& filename) {
        std::ifstream inputFile(filename);
        std::vector<std::pair<std::string, int>> wordCounts;

        if (!inputFile.is_open()) {
            std::cerr << "Failed to open the file." << std::endl;
            return wordCounts;
        }

        std::vector<std::pair<std::string, int>> wordMap;
        std::string line;
        while (std::getline(inputFile, line)) {
            std::string word;
            std::string::size_type start = 0;
            std::string::size_type end = 0;
            while ((end = line.find_first_of(" \t\n", start)) != std::string::npos) {
                word = line.substr(start, end - start);
                start = line.find_first_not_of(" \t\n", end);
                word.erase(std::remove_if(word.begin(), word.end(), ispunct), word.end());
                if (!word.empty()) {
                    auto it = std::find_if(wordMap.begin(), wordMap.end(),
                        [&word](const std::pair<std::string, int>& element) { return element.first == word; });
                    if (it != wordMap.end()) {
                        it->second++;
                    } else {
                        wordMap.push_back({ word, 1 });
                    }
                }
            }
            if (start < line.length()) {
                word = line.substr(start);
                word.erase(std::remove_if(word.begin(), word.end(), ispunct), word.end());
                if (!word.empty()) {
                    auto it = std::find_if(wordMap.begin(), wordMap.end(),
                        [&word](const std::pair<std::string, int>& element) { return element.first == word; });
                    if (it != wordMap.end()) {
                        it->second++;
                    } else {
                        wordMap.push_back({ word, 1 });
                    }
                }
            }
        }

        inputFile.close();

        for (const auto& pair : wordMap) {
            wordCounts.push_back(pair);
        }

        return wordCounts;
    }
};

class Reducer {
public:
    static void reduce(const std::vector<std::pair<std::string, int>>& wordCounts, const std::string& outputFilename) {
        std::ofstream outputFile(outputFilename);
        if (!outputFile.is_open()) {
            std::cerr << "Failed to create output file." << std::endl;
            return;
        }

        std::vector<std::pair<std::string, int>> sortedWordCounts = wordCounts;
        std::sort(sortedWordCounts.begin(), sortedWordCounts.end(),
            [](const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
                return a.second > b.second; // Sort in descending order
            });

        for (const auto& pair : sortedWordCounts) {
            outputFile << pair.first << " " << pair.second << std::endl;
            std::cout << pair.first << " " << pair.second << std::endl;
        }

        outputFile.close();
    }
};

int main() {
    std::string inputFilename;
    std::cout << "Enter the name of the input text file: ";
    std::cin >> inputFilename;

    std::ifstream fileCheck(inputFilename);
    if (!fileCheck.is_open()) {
        std::cerr << "File does not exist." << std::endl;
        return 1;
    }
    fileCheck.close();

    std::vector<std::pair<std::string, int>> wordCounts = Mapper::map(inputFilename);
    std::sort(wordCounts.begin(), wordCounts.end());

    std::string outputFilename = inputFilename.substr(0, inputFilename.find_last_of('.')) + "_mr.txt";
    Reducer::reduce(wordCounts, outputFilename);

    return 0;
}
