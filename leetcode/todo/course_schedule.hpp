#ifndef LEETCODE_COURSE_SCHEDULE_HPP_
#define LEETCODE_COURSE_SCHEDULE_HPP_

#include <vector>
#include <queue>

namespace leetcode
{
class Solution
{
public:
    bool canFinish(int num_courses, std::vector<std::vector<int>>& prerequisites)
    {
        std::vector<std::vector<int>> adjs(num_courses);
        std::vector<int> in_degrees(num_courses);

        for (const auto &prerequisite: prerequisites)
        {
            adjs[prerequisite[0]].push_back(prerequisite[1]);
            in_degrees[prerequisite[1]]++;
        }

        std::vector<int> sort;

        std::queue<int> queue;

        for (int i = 0; i < num_courses; ++i)
        {
            if (in_degrees[i] == 0)
                queue.push(i);
        }

        int top = 0;

        while (!queue.empty())
        {
            top = queue.front();
            queue.pop();
            sort.push_back(top);

            for (auto &adj_vertex: adjs[top])
            {
                --in_degrees[adj_vertex];

                if (in_degrees[adj_vertex] == 0)
                    queue.push(adj_vertex);
            }
        }

        return (static_cast<std::size_t>(num_courses) == sort.size())? true: false;
    }
};

} // namespace leetcode

#endif // LEETCODE_COURSE_SCHEDULE_HPP_