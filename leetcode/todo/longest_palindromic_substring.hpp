#ifndef LEETCODE_LONGEST_PALINDROMIC_SUBSTRING
#define LEETCODE_LONGEST_PALINDROMIC_SUBSTRING

namespace leetcode
{
#include <string>

class Solution
{
public:
	void centerExpand(std::string_view s, int size, int i, int &min_id, int &length)
	{
		int max_id = 0;

		if (i <= size - 1)
		{
			min_id = i;
			max_id = i;
		}
		else
		{
			min_id = i - size;
			max_id = i - size + 1;

			if (s[min_id] != s[max_id])
			{
				length = 0;
				return;
			}
		}

		int j = 1;
		while (min_id - j >= 0 && max_id + j <= size - 1)
		{
			if (s[min_id - j] == s[max_id + j])
				j++;
			else
				break;
		}
		j--;
		length = max_id - min_id + 2 * j + 1;
		min_id -= j;
	}

	std::string longestPalindrome(std::string s)
	{
		int longest_min_id = 0, longest_length = 0, min_id = 0, length = 0;
		int size = s.size();

		for (int i = 0; i <= 2 * size - 2; ++i)
		{
			centerExpand(s, size, i, min_id, length);

			if (length > longest_length)
			{
				longest_min_id = min_id;
				longest_length = length;
			}
		}

		return s.substr(longest_min_id, longest_length);
	}

};

} // namespace leetcode

#endif // LEETCODE_LONGEST_PALINDROMIC_SUBSTRING