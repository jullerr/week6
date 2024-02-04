#include <iostream>
#include <unordered_map>

class Application {
    public:
        void findMostFrequentChar(const std::string& s) {
        std::unordered_map<char, int> charCount;

        for(char c : s) {
        charCount[c]++;
}

        char mostFrequentChar;
        int maxCount = 0;

            for(auto it : charCount) {
                if(it.second > maxCount) {
                maxCount = it.second;
                mostFrequentChar = it.first;
}
}

        std::cout << "Most frequent character: " << mostFrequentChar << std::endl;
        std::cout << "Count: " << maxCount << std::endl;
}

int run() {
std::string s = "hello world";
findMostFrequentChar(s);

return 0;
}
};

int main() {
Application application;
return application.run();
}
