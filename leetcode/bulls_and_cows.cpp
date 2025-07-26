#include <string>
#include <unordered_map>
#include <iostream>

class Solution
{
public:
    std::string getHint(std::string secret, std::string guess)
    {
        int bull = 0, cow = 0;
        std::unordered_map<char, int> digits;

        for (std::size_t i = 0; i < secret.size(); ++i)
        {
            if (secret[i] == guess[i])
                ++bull;
            
            else
            {
                ++digits[secret[i]];
            }
        }

        for (std::size_t i = 0; i < guess.size(); ++i)
        {
            if ((secret[i] != guess[i]) && (digits.find(guess[i]) != digits.end()) && (digits[guess[i]] > 0))
            {
                ++cow;
                --digits[guess[i]];
            }
        }

        return std::to_string(bull) + 'A' + std::to_string(cow) + 'B';
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    std::string secret, guess;

    secret = "1807", guess = "7810";
    std::cout << "Answer: " << "1A3B" << std::endl;
    std::cout << "Output: " << sol.getHint(secret, guess) << std::endl;

    secret = "1123", guess = "0111";
    std::cout << "Answer: " << "1A1B" << std::endl;
    std::cout << "Output: " << sol.getHint(secret, guess) << std::endl;

    return 0;
}