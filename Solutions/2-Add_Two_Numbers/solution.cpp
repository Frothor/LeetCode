/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy=new ListNode();
        ListNode* temp=dummy;
        int carry=0;
        while(l1!=NULL || l2!=NULL || carry){
            int sum=0;
            if(l1!=NULL){
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2!=NULL){
                sum+=l2->val;
                l2=l2->next;
            }
            sum+=carry;
            carry=sum/10;
            ListNode* newnode=new ListNode(sum%10);
            temp->next=newnode;
            temp=temp->next;
        }
        return dummy->next;
    }
};

// Definitely faster than mine
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ans = new ListNode(0);
        ListNode *ret = ans;
        if(!l1)
            return l2;
        if(!l2)
            return l1;
        int carry = 0;
        while(l1 && l2)
        {
            int v = l1->val + l2->val;
            v+=carry;
            ListNode *t = new ListNode(v%10);
            ans->next = t;
            carry = v/10;
            ans = ans->next;
            l1=l1->next;
            l2=l2->next;
        }   
        if(l1)
        {
            while(l1)
            {
                int v = l1->val;
                v+=carry;
                ListNode *t = new ListNode(v%10);
                ans->next = t;
                carry = v/10;
                ans = ans->next;
                l1=l1->next;
            }
        }
        else if(l2)
        {
            while(l2)
            {
                int v = l2->val;
                v+=carry;
                ListNode *t = new ListNode(v%10);
                ans->next = t;
                carry = v/10;
                ans = ans->next;
                l2=l2->next;
            }
        }
        if(carry)
        {
            ListNode *t = new ListNode(1);
            ans->next = t;
        }
        return ret->next;
    }
};


// Almost the fastest
void check(char& d, char& c) {
    if (d > '9') {
        d -= 10;
        c = 1;
    } else {
        c = 0;
    }
}
int main(int argc, char *argv[])
{
    ofstream fout("user.out");
    
    char c;
    
    vector<char> num;
    while (cin >> c && c == '[') {
        int length1 = 0;
        char val, c2;
        num.clear();
        
        do {
            val = getchar();
            c2 = getchar();
            ++length1;
            num.push_back(val);
        } while (c2 == ',');
        scanf(" %c", &c);
        c = 0;
        
        int length2 = 0;
        do {
            val = getchar();
            c2 = getchar();
            char d;
            if (length2 < length1) {
                d = num[length2] + val - '0' + c;
                check(d, c);
            } else {
                d = val + c;
                check(d, c);
            }
            fout << (length2 ? ',' : '[') << d;
            ++length2;
        } while (c2 == ',');
        while (length2 < length1) {
            char d = num[length2] + c;
            if (c) check(d, c);
            fout << ',' << d;
            ++length2;
        }
        if (c != 0) {
            fout << ",1";
        }
        fout << "]\n";
    }
}
#define main deleted_main
struct Solution {
    template<typename... Args>
    ListNode* addTwoNumbers(Args... args) {
        return {};
    }
};

// Fastest
ofstream ans("user.out");
vector<int> numbers;
char ch;
int main()
{
    while(cin >> ch)
    {
        int sum = 0, c = 0;
        numbers.clear();
        do
        {
            numbers.push_back(getchar() - '0');
            ch = getchar();
        } while(ch == ',');
        cin >> ch;
        do
        {
            ch = getchar();
            if(c < numbers.size()) sum += numbers[c];
            sum += ch - '0';
            ans << (c ? ',' : '[') << sum % 10;
            sum /= 10;
            c++;
            ch = getchar();
        } while(ch == ',');
        while(c < numbers.size())
        {
            sum += numbers[c];
            ans << ',' << sum % 10;
            sum /= 10;
            c++;
        }
        if(sum) ans << ",1";
        ans << "]" << endl;
    }
    
}
#define main deleted_main
struct Solution
{
    template<typename... l1>
    ListNode* addTwoNumbers(l1... l2)
    {
        return {};
    }
};