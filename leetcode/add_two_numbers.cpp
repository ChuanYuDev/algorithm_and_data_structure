#include <iostream>
#include <fstream>

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
		ListNode *prefirst = new ListNode(0);
		ListNode *p = prefirst;
		ListNode *p1 = l1, *p2 = l2;
		
		int carry = 0, tmp;
		while (p1 != nullptr || p2 != nullptr)
		{
			int n1 = (p1 != NULL) ? p1->val : 0;
			int n2 = (p2 != NULL) ? p2->val : 0;
			tmp = n1 + n2 + i;
			i = tmp / 10;
			tmp %= 10;
			p->next = new ListNode(tmp);
			p = p->next;
			if (p1 != NULL) p1 = p1->next;
			if (p2 != NULL) p2 = p2->next;
		}
		if (i != 0) {
			p->next = new ListNode(i);
		}
		return prefirst->next;
	}
};

//make list
ListNode* makeList(int* a, int num) {
	ListNode* first= new ListNode(a[0]);
	ListNode* p1, * p2;
	p1 = first;
	for (int i = 1; i < num; i++) {
		p2 = new ListNode(a[i]);
		p1->next = p2;
		p1 = p2;
	}
	return first;
}

void print_list(ListNode* p)
{
	while (p != NULL)
	{
		std::cout << p->val << " ";
		p = p->next;
	}

	std::cout << std::endl;
}


int main()
{
	Data data;
	char filename[] = "2_test.txt";
	inputData(filename, data);
	data.readData();
	Solution solution;
	cout << endl << "result: " << endl;
	for (int i = 0; i < data.lineNum / 2; i++) {
		ListNode* p1 = makeList(data.a[2 * i], data.b[2 * i]);
		ListNode* p2 = makeList(data.a[2 * i + 1], data.b[2 * i + 1]);
		outputList(p1);
		outputList(p2);
		ListNode* result = solution.addTwoNumbers(p1, p2);
		outputList(result);
	}
    return 0;
}

