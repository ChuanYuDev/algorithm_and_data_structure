#ifndef LEETCODE_BULLS_AND_COWS_HPP_
#define LEETCODE_BULLS_AND_COWS_HPP_

#include <string>
#include <unordered_map>

namespace leetcode
{
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
} // namespace leetcode

#endif // LEETCODE_BULLS_AND_COWS_HPP_