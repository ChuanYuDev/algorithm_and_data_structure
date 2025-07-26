/* 
 * Add Two Numbers
 * 
 * Description:
 * You are given two non-empty linked lists representing two non-negative integers.
 * The digits are stored in reverse order and each of their nodes contain a single digit.
 * Add the two numbers and return it as a linked list.
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 * Example:
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 * Explanation: 342 + 465 = 807.
*/

# include <list>
# include <iostream>
typedef std::list<int>::iterator LIST_ITER;

std::list<int> two_sum(std::list<int> &lst1, std::list<int> &lst2){
    int sum, i = 0;
    LIST_ITER iter1 = lst1.begin(), iter2 = lst2.begin();
    LIST_ITER iter;
    std::list<int> ans;

    while ((iter1 != lst1.end()) && (iter2 != lst2.end())){
        sum = *iter1 + *iter2 + i;
        ans.push_back(sum % 10);
        i = sum / 10;
        ++iter1;
        ++iter2;
    }

    if (iter1 == lst1.end()){
        iter1 = iter2;
        iter = lst2.end();
    }
    else{
        iter = lst1.end();
    }

    while (iter1 != iter){
        sum = *iter1 + i;
        ans.push_back(sum % 10);
        i = sum / 10;
        ++iter1;
    }

    if (i != 0)
        ans.push_back(i);

    return ans;
}

int main(){
    std::list<int> lst2 = {2, 4, 3};
    std::list<int> lst1 = {5, 6, 4};
    std::list<int> ans = two_sum(lst1, lst2);

    for (LIST_ITER iter = ans.begin(); iter != ans.end(); ++iter){
        std::cout << *iter << " ";
    } 
    std::cout << std::endl;

    return 0; 
}