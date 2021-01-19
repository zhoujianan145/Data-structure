```
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode ListNode;
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
      ListNode* dummy=(ListNode*)malloc(sizeof(ListNode));
      ListNode* prev=dummy;
      //两个链表长度都要判断，假如一个走完了，我们还继续访问就异常了
      while(l1&&l2)
      {
          //prev的next始终指向小的那一个节点
          //prev要等于小的那一个节点
          //小的那个节点变成自己链表的下一个节点
      if(l1->val<=l2->val)
      {
         prev->next=l1;
         prev=l1;
         l1=l1->next;
         
      }
      else
      {
         prev->next=l2;
         prev=l2;
         l2=l2->next; 
      }
      }
      //走到这可以判断，假如其中一个为空了，由于题目给的是有序链表直接连接在prev的后面
      if(l2)
      {
         prev->next=l2;
      }
      else if(l1)
      {
          prev->next=l1;
      }
      //假如两个都是空返回NULL
      else if(l1==NULL&&l2==NULL)
      {
          return NULL;
      }
      ListNode* head=dummy->next;
      free(dummy);
      return head;
}
```

