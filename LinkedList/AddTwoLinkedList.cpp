// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:

// its code from forwaerd to backward only
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* fake = new ListNode(-1);
        ListNode* temp = fake;
        int carry = 0;
        while (l1 || l2 || carry) {
            int sum = 0;  //after sum then 0
            if (l1) {
                sum += l1->val;  //2  4
                l1 = l1->next;
            }
            if (l2) {
                sum += l2->val; //2+5 4+6
                l2 = l2->next;
            }
            sum += carry; //2+5+0  //4+6+0
            carry = sum / 10;      //10/10 =>1                   
            ListNode* newNode = new ListNode(sum % 10); // 10%10 => 0
            temp->next = newNode;
            temp = temp->next;
        }
        return fake->next;
    }
};

// its orginal and logical with ther proper adding rule
class Solution {
  public:
    Node* reverse(Node* head) {
        Node *prev = nullptr,*cur = head,*next = nullptr;
        while(cur != nullptr) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
    Node* addTwoLists(Node* num1, Node* num2) {
       Node *l1 = reverse(num1);
       Node *l2 = reverse(num2);
       
       Node* dummy = new Node(0);
       Node* cur = dummy;
       int carry = 0;
       
       while(l1 || l2 || carry) {
           int sum = carry;
           if(l1) {
               sum += l1->data;
               l1 = l1->next;
           }
           if(l2) {
               sum += l2->data;
               l2 = l2->next;
           }
           
           carry = sum / 10;
           cur->next = new Node(sum % 10);
           cur = cur->next;
       }
       Node* res =  reverse(dummy->next);
       //for leading zeros at fronmt
       while(res && res->data == 0 && res->next) {
        //   Node* temp  = res;
           res = res->next;
        //   delete temp;
       }
       return res;
    }
};