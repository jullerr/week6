#include <iostream>
#include <string>
#include <vector>
#include <filesystem>
#include <fstream>

namespace fs = std::filesystem;

class Application {
    public:
    int run() {
    std::string directory;
    std::string searchTerm;

    std::cout << "Введите путь к директории: ";
    std::cin >> directory;

    std::cout << "Введите название файла или содержимое для поиска: ";
    std::cin.ignore();
    std::getline(std::cin, searchTerm);

    searchFiles(directory, searchTerm);

return 0;
}

    private:
        void searchFiles(const std::string& directory, const std::string& searchTerm) {
        std::vector<std::string> foundFiles;

    for (const auto& entry : fs::recursive_directory_iterator(directory)) {
        if (entry.is_regular_file()) {
            if (searchByFilename(entry.path().filename().string(), searchTerm) ||
                searchByContent(entry.path().string(), searchTerm)) {
                foundFiles.push_back(entry.path().string());
        }
    }
}

            if (foundFiles.empty()) {
                std::cout << "Файлов, соответствующих поиску, не найдено.\n";
}       else {
            std::cout << "Найденные файлы:\n";
        for (const auto& file : foundFiles) {
            std::cout << file << std::endl;
        }
    }
}

    bool searchByFilename(const std::string& filename, const std::string& searchTerm) {
        return filename.find(searchTerm) != std::string::npos;
}

    bool searchByContent(const std::string& filePath, const std::string& searchTerm) {
        std::ifstream file(filePath);
        std::string line;

            while (std::getline(file, line)) {
                if (line.find(searchTerm) != std::string::npos) {
                    return true;
}
}

                return false;
}
};

int main() {
Application application;
return application.run();
}
