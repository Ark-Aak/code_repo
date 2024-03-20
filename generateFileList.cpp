#include <bits/stdc++.h>
#include <comdef.h>
#include <comutil.h>
#include <windows.h>

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
    for (int i = 0; i < (int) s.size(); i++) if (s[i] == '\\') s[i] = '/';
    return s;
}

std::wstring to_wide_string(const std::string &input) {
    std::wstring_convert<std::codecvt_utf8<wchar_t>> converter;
    return converter.from_bytes(input);
}

std::string urlEncode(std::string s) {
    std::string res;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') res += "%20";
        else res += s[i];
    }
    return res;
}

void generateMarkdownFileList(const std::string& directory, const std::vector<std::string>& ignorePatterns, std::ofstream& outputFile, int depth = 0) {
    std::cout << directory << std::endl;
    for (const auto& entry : fs::directory_iterator(to_wide_string(directory))) {
        const auto& path = entry.path();
        std::string indentation(depth * 2, ' '); // Adjust the indentation based on depth
        std::string fileName = path.filename().string();
        if (fileName[0] != '.' && fileName != ".git" && fileName != "$RECYCLE.BIN" && fileName != ".gitignore" && !isIgnored(fileName, ignorePatterns) && !isIgnored(path.string(), ignorePatterns)) {
            if (fs::is_directory(path)) {
                outputFile << indentation << "- **" << fileName << "**" << std::endl;
                generateMarkdownFileList(path.string(), ignorePatterns, outputFile, depth + 1); // Recursive call for subdirectories
            } else if (fs::is_regular_file(path)) {
                outputFile << indentation << "- [" << fileName << "](" << urlEncode(getPath(path.string())) << ")" << std::endl;
            }
        }
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
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
