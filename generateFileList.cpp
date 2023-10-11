#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <filesystem>

namespace fs = std::filesystem;

bool isIgnored(const std::string& fileName, const std::vector<std::string>& ignorePatterns) {
    // Check if the file name matches any ignore pattern
    return std::any_of(ignorePatterns.begin(), ignorePatterns.end(), [&fileName](const std::string& pattern) {
        // Use simple pattern matching (you can implement more complex matching logic if needed)
        size_t wildcardPos = pattern.find('*');
        if (wildcardPos != std::string::npos) {
            // Handle patterns with wildcard (*)
            size_t fileNameWildCardPos = fileName.find('.');
            if (fileNameWildCardPos != std::string::npos) {
                std::string suf = fileName.substr(fileNameWildCardPos);
                return suf == pattern.substr(wildcardPos + 1);
            }
        }
        // Exact match
        return fileName == pattern;
    });
}

std::string getPath(std::string s) {
    s = s.substr(1);
    for (int i = 0; i < s.size(); i++) if (s[i] == '\\') s[i] = '/';
    return s;
}

void generateMarkdownFileList(const std::string& directory, const std::vector<std::string>& ignorePatterns, std::ofstream& outputFile, int depth = 0) {
    for (const auto& entry : fs::directory_iterator(directory)) {
        const auto& path = entry.path();
        std::string indentation(depth * 2, ' '); // Adjust the indentation based on depth
        std::string fileName = path.filename().string();
        if (fileName != ".git" && fileName != ".gitignore" && !isIgnored(fileName, ignorePatterns) && !isIgnored(path.string(), ignorePatterns)) {
            if (fs::is_directory(path)) {
                outputFile << indentation << "- **" << fileName << "**" << std::endl;
                generateMarkdownFileList(path.string(), ignorePatterns, outputFile, depth + 1); // Recursive call for subdirectories
            } else if (fs::is_regular_file(path)) {
                outputFile << indentation << "- [" << fileName << "](" << getPath(path.string()) << ")" << std::endl;
            }
        }
    }
}

int main() {
    std::string gitignorePath = ".gitignore"; // Path to .gitignore file
    std::ifstream gitignoreFile(gitignorePath);
    std::vector<std::string> ignorePatterns;

    if (gitignoreFile.is_open()) {
        std::string pattern;
        while (std::getline(gitignoreFile, pattern)) {
            // Exclude empty lines and comments in .gitignore file
            if (!pattern.empty() && pattern[0] != '#') {
                ignorePatterns.push_back(pattern);
            }
        }
        gitignoreFile.close();

        std::ofstream outputFile("README.md");
        if (outputFile.is_open()) {
            outputFile << "# File List\n\n";
            generateMarkdownFileList(".", ignorePatterns, outputFile);
            outputFile.close();
        } else {
            std::cerr << "Cannot open output file." << std::endl;
        }
    } else {
        std::cerr << "Cannot open .gitignore." << std::endl;
    }

    return 0;
}
