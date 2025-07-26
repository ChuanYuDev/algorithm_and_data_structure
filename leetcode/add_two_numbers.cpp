#include <iostream>
#include <vector>

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
 	ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
	{
		ListNode *prev_result = new ListNode();
		ListNode *p = prev_result;

		ListNode *p1 = l1, *p2 = l2;
		
		int carry = 0, temp;
		// Loop p1 and p2 until both are nullptr
		
		while (p1 != nullptr || p2 != nullptr)
		{
			// If one of them is nullptr, we can assume it as 0
			//		5 -> 0
			//		1 -> 6
			//		6 -> 6
			int d1 = (p1 != nullptr) ? p1->val : 0;
			int d2 = (p2 != nullptr) ? p2->val : 0;

			// Add two corresponding digits (d1, d2) of p1 and p2 and carry
			temp = d1 + d2 + carry;
			carry = temp / 10;
			temp = temp % 10;

			// Save the temp result to the singly linked list
			p->next = new ListNode(temp);
			p = p->next;

			// Increase p1 and p2
			// 		If p1 or p2 is nullptr, skip the increase
			if (p1 != nullptr) p1 = p1->next;
			if (p2 != nullptr) p2 = p2->next;
		}

		// If the carry is not 0, we need to add one more node
		//		5 -> 6
		//		3 -> 5
		//		8 -> 1 -> 1
		if (carry != 0) {
			p->next = new ListNode(carry);
		}

		return prev_result->next;
	}
};

// Create List Node of l1 based on l1_list 
ListNode* createList(std::vector<int> &l1_list)
{
	ListNode *prev_l1 = new ListNode();
	ListNode *p = prev_l1;

	for (std::vector<int>::size_type i = 0; i < l1_list.size(); i++)
	{
		p->next = new ListNode(l1_list[i]);
		p = p->next;
	}

	return prev_l1->next;
}

void printList(ListNode* p)
{
	while (p != nullptr)
	{
		std::cout << p->val << " ";
		p = p->next;
	}

	std::cout << std::endl;
}

int main()
{
	Solution solution;
	std::vector<int> l1_list, l2_list;
	ListNode *l1, *l2, *result;

	// Example 1
	l1_list = {2, 4, 3};
	l2_list = {5, 6, 4};

	l1 = createList(l1_list);
	l2 = createList(l2_list);

	result = solution.addTwoNumbers(l1, l2);

	std::cout << "Answer: 7 0 8" << std::endl;
	std::cout << "Output: ";
	printList(result);

	// Example 2
	l1_list = {0};
	l2_list = {0};

	l1 = createList(l1_list);
	l2 = createList(l2_list);

	result = solution.addTwoNumbers(l1, l2);

	std::cout << "Answer: 0" << std::endl;
	std::cout << "Output: ";
	printList(result);

	// Example 3
	l1_list = {9,9,9,9,9,9,9};
	l2_list = {9,9,9,9};

	l1 = createList(l1_list);
	l2 = createList(l2_list);

	result = solution.addTwoNumbers(l1, l2);

	std::cout << "Answer: 8 9 9 9 0 0 0 1" << std::endl;
	std::cout << "Output: ";
	printList(result);

	// Free l1, l2 and result
	// To do

    return 0;
}

