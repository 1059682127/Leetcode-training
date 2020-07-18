//lt141

/*
环形链表

给定一个链表，判断链表中是否有环。
为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。

//思路1：遍历+哈希O(N)/O(N)
//思路2：快慢指针O(N)/O(1)
*/



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
	//思路1：遍历+哈希
	//用哈希表记录已经遍历过的节点，如果指向遍历过的节点，即成环

	//知识点，如果没用到cur->next的成员，不用判断cur->next != NULL, 已经判断了cur != NULL, 所以可以访问cur的成员next
	bool hasCycle(ListNode *head) {
		map<ListNode*, bool> isVisted;
		ListNode* cur = head;
		while (cur != NULL) {
			if (cur->next != NULL) {
				//判断指向的节点是否遍历过
				if (isVisted.count(cur->next)) return true;
				else {
					isVisted[cur->next] = true;
				}

			}
			cur = cur->next;
		}
		return false;
	}
};


//执行用时:16 ms, 在所有 C++ 提交中击败了52.79%的用户
//内存消耗 :9.8 MB, 在所有 C++ 提交中击败了40.91%的用户
class Solution {
public:
	//思路2：快慢指针O(N)/O(1)
	//速度不同的指针前进（类似与两个运动员在跑道上跑步），快指针每次移动两步，慢指针每次移动一步
	//如果不成环，快指针优先到达尾部
	//如果成环，快指针在第二圈的时候会追上快指针，如果差一步，再迭代一次就刚好追上；差两步，迭代两次就追上。。。反正成环的话两指针最终会重叠

	//知识点：
	bool hasCycle(ListNode *head) {
		if (head == NULL || head->next == NULL) return false;

		ListNode* fast = head->next;  //为了进入while循环，让fast指针先走一步
		ListNode* slow = head;
		while (fast != slow) {
			if (fast == NULL || fast->next == NULL) return false; //如果fast指针先走到末尾,且判断fast->next是否为NULL，是的话五无路可走
			//前进
			fast = fast->next->next;
			slow = slow->next;
		}
		return true;
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
        if(headA == NULL || headB == NULL) return NULL;
        ListNode* pA = headA;
        ListNode* pB = headB;
        while(pA != pB){
            pA = pA->next;
            pB = pB->next;
            //如果双双走到末尾还没相遇
            if(pA == NULL && pB == NULL) return NULL;
            if(pA == NULL) pA = headB;
            if(pB == NULL) pB = headA;
        }
        return pA;
    }
};