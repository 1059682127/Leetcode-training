//lt160


/*
 相交链表

编写一个程序，找到两个单链表相交的起始节点。

//思路1：哈希表:O(m+n)/O(m)
//思路2：双指针
*/

class Solution {
public:
	//思路1：哈希表:O(m+n)/O(m)
	//遍历链表A，将A的每个节点记录在哈希表中，然后遍历链表B，看B中的节点是否在哈希表中，在的话为相交
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		if (headA == NULL || headB == NULL) return NULL;
		map<ListNode*, bool> isExisted;
		ListNode* cur = headA;
		while (cur != NULL) {
			isExisted[cur] = true;
			cur = cur->next;
		}
		//遍历链表B
		cur = headB;
		while (cur != NULL) {
			if (isExisted.count(cur)) return cur;
			else cur = cur->next;
		}
		return NULL;
	}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	//思路1：双指针
	//A和B两个链表长度可能不同，但是A+B和B+A的长度是相同的，所以遍历A+B和遍历B+A一定是同时结束。 
	//如果A,B相交的话A和B有一段尾巴是相同的，所以两个遍历的指针一定会同时到达交点 
	//如果A,B不相交的话两个指针就会同时到达A+B（B+A）的尾节点

	//pA初始化指向A的头结点，pB指向B的头结点，然后遍历，pA走到尾结点之后重定位指向链表B头结点，pB走到尾结点之后重定位指向链表A头结点
	//由于A+B= B+A,pA,pB最终会同时走到尾结点，如果中间相交，则pA会和pB提前相遇
	//return pA,pB初次相遇的节点,
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		if (headA == NULL || headB == NULL) return NULL;
		ListNode* pA = headA;
		ListNode* pB = headB;
		while (pA != pB) {
			pA = pA->next;
			pB = pB->next;
			//如果双双走到末尾还没相遇
			if (pA == NULL && pB == NULL) return NULL;
			if (pA == NULL) pA = headB;
			if (pB == NULL) pB = headA;
		}
		return pA;
	}
};