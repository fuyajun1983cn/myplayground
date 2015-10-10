#include <iostream>


using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

      if (l1 == NULL && l2 == NULL)
	return NULL;

      if (l1 == NULL)
	return l2;

      if (l2 == NULL)
	return l1;

      int carry = 0;
      ListNode *p = l1;
      ListNode *q = l2;

      int sum = p->val + q->val;
      carry = sum / 10;
      ListNode *answer = new ListNode(sum % 10);
      ListNode *k = answer;
      p = p->next;
      q = q->next;

      while (p != NULL && q != NULL) {

	sum = p->val + q->val;	
	sum += carry > 0 ? 1 : 0;
	carry = sum / 10;

	ListNode *node = new ListNode(sum%10);
	k->next = node;
	k = node;	

      }

      while (p != NULL) {
	ListNode *node = new ListNode(p->val);
	k->next = node;
	k = node;
	p = p->next;
      }

      while (q != NULL) {
	ListNode *node = new ListNode(q->val);
	k->next = node;
	k = node;
	q = q->next;
      }

      return answer;
      
    }

    ListNode* addTwoNumbers2(ListNode* l1, ListNode* l2) {

      if (l1 == NULL && l2 == NULL)
	return NULL;

      if (l1 == NULL)
	return l2;

      if (l2 == NULL)
	return l1;

      int carry = 0;
      ListNode *p = l1;
      ListNode *q = l2;

      int sum = p->val + q->val;
      carry = sum / 10;
      ListNode *answer = p;
      p->val = sum % 10;
      ListNode *pre = p;
      p = p->next;
      q = q->next;

      while (p != NULL && q != NULL) {

	sum = p->val + q->val;	
	sum += carry > 0 ? 1 : 0;
	carry = sum / 10;

	p->val = sum % 10;
	pre = p;
	p = p->next;
	q = q->next;

      }

      if (carry > 0) {

	if (p == NULL & q == NULL) {
	  ListNode *node = new ListNode(1);
	  pre->next = node;
	} else if (p != NULL) {
	  while (p != NULL) {
	    sum = p->val;
	    sum += carry > 0 ? 1 : 0;
	    carry = sum / 10;
	    p->val = sum % 10;
	    pre = p;
	    p = p->next;

	    if (carry == 0)
	      break;
	  }

	  if (carry > 0) {
	    ListNode *node = new ListNode(1);
	    pre->next = node;
	  }
	} else {
	  pre->next = q;  
	   while (q != NULL) {
	      sum = q->val;
	      sum += carry > 0 ? 1 : 0;
	      carry = sum / 10;
	      q->val = sum % 10;
	      pre = q;
	      q = q->next;

	      if (carry == 0)
	        break;
	   }

	  if (carry > 0) {
	    ListNode *node = new ListNode(1);
	    pre->next = node;
	  }
	}
      
      } else {

	if (q != NULL)
	  pre->next = q;

      }


      return answer;
      
    }
};


int main(int argc, char *argv[])
{

  Solution s;

  return 0;
}
