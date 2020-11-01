//Fastest
class Solution {
public:
    int getDecimalValue(ListNode* head) 
    {
        string str="";
        while(head!=nullptr)
        {
            string temp=to_string(head->val);
            str+=temp;
            head=head->next;
        }
        int ans=0,c=str.size()-1;
        for(auto x:str)
        {
            if(x=='1')
                ans+=pow(2,c);
            c--;
        }
        return ans;
    }
};

//Another
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int ans=0;
        while(head!=NULL){
            ans<<=1;
            ans+=head->val ;
            head=head->next;
        }
        return ans;
    }
};