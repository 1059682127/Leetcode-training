//lt面试题18

/*
删除链表的节点

给定单向链表的头指针和一个要删除的节点的值，定义一个函数删除该节点。

返回删除后的链表的头节点。

注意：此题对比原题有改动

示例 1:

输入: head = [4,5,1,9], val = 5
输出: [4,1,9]
解释: 给定你链表中值为 5 的第二个节点，那么在调用了你的函数之后，该链表应变为 4 -> 1 -> 9.


示例 2:

输入: head = [4,5,1,9], val = 1
输出: [4,5,9]
解释: 给定你链表中值为 1 的第三个节点，那么在调用了你的函数之后，该链表应变为 4 -> 5 -> 9.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shan-chu-lian-biao-de-jie-dian-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

版本1：val: int 解法O(N)/O(1)
版本2：val: ListNode 解法：信息交换法O(1)/O(1)

//技巧：头结点的使用
*/

class Solution {
public:
	//使用头结点，万一要删除第一结点n

	ListNode* deleteNode(ListNode* head, int val) {
		ListNode* dummyNode = new ListNode(0);
		dummyNode->next = head;
		ListNode* cur = dummyNode;
		while (cur != NULL && cur->next != NULL) {  //注意先判断cur != NULL,再判断cur->next != NULL
			//遇到则删除该结点
			if (cur->next->val == val) {
				cur->next = cur->next->next;
			}
			cur = cur->next;
		}
		return dummyNode->next;
	}
	//val: ListNode 解法：信息交换法
	//当输入参数为删除的结点时，可以采用信息交换，即deleteNode->val = deleteNode->next->val; deleteNode->next = deleteNode->next->next;
	//当删除结点不在尾结点时，可以实现常数时间删除
	//当删除结点是尾结点，无法找到尾结点的后一元素，所以需要从头遍历
	//时间复杂度:(O(1)*(N - 1) + 0(N))/N = O(1)

	ListNode* deleteNode2(ListNode* head, ListNode* deleteNode) {
		if (head == NULL || deleteNode == NULL) return NULL;
		if (deleteNode->next != NULL) {
			deleteNode->val = deleteNode->next->val;
			deleteNode->next = deleteNode->next->next;
		}
		//头尾结点相同
		else if (head == deleteNode) return NULL;
		else {
			ListNode* cur = head;
			//找到倒数第二结点
			while (cur->next != NULL && cur->next->next != NULL) {
				cur = cur->next;
			}
			cur->next = NULL;
		}
		return head;
	}
};