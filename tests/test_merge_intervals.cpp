#include "leetcode/merge_intervals.hpp"
#include "utils/output.hpp"

int main()
{
    leetcode::Solution sol;
    std::vector<std::vector<int>> intervals;

    using leetcode::operator<<;

    intervals = {{1,3},{8,10},{2,6},{15,18}};
    std::cout << sol.merge(intervals) << std::endl;

    intervals = {{1,4},{4,5}};
    std::cout << sol.merge(intervals) << std::endl;

    intervals = {{74,78},{61,63},{46,50},{51,54}};
    std::cout << sol.merge(intervals) << std::endl;

    return 0;
}
