#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> result;
        std::string current = "";
        backtrack(result, current, 0, 0, n);
        return result;
    }

private:
    void backtrack(std::vector<std::string>& result, std::string& current, int openCount, int closeCount, int n) {
        // Base case: the current string length reaches 2 * n
        if (current.length() == 2 * n) {
            result.push_back(current);
            return;
        }
        if (openCount < n) {
            current.push_back('(');
            backtrack(result, current, openCount + 1, closeCount, n);
            current.pop_back(); // Backtrack
        }

        if (closeCount < openCount) {
            current.push_back(')');
            backtrack(result, current, openCount, closeCount + 1, n);
            current.pop_back(); // Backtrack
        }
    }
};



// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna