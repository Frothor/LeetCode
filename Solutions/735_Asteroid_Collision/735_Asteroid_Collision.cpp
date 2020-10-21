//Third fastest
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> theStack;
        for(int i =0 ; i < asteroids.size(); ++i)
        {
           if(theStack.size() == 0)
           {
                theStack.push(asteroids[i]);
                continue;
           }
            
            // stack top explode only
            while(theStack.size() > 0 && asteroids[i] < 0 && theStack.top() > 0 && abs(asteroids[i]) > abs(theStack.top()))
            { 
                // stack top explode
                theStack.pop();    
                // then keep checking asteroids[i] with next top of the stack
            }
            
            //asteroids[i] explode only
            if(theStack.size() > 0 && asteroids[i] < 0 && theStack.top() > 0  && abs(asteroids[i]) < abs(theStack.top()))
            {
                // continue to next i
                continue;
            }
            
            //both explode 
            if(theStack.size() > 0 && asteroids[i] < 0 && theStack.top() > 0  && abs(asteroids[i]) == abs(theStack.top()))
            {
                // stack top explode
                theStack.pop();  
                
                // continue to next i
                continue;
            }
            
            // other cases, the same direction 
            theStack.push(asteroids[i]);
            
        }
      vector<int> res;
       while(theStack.size() > 0)
       {
           res.push_back(theStack.top());
           theStack.pop();
       }
        
        reverse(res.begin(), res.end());
        return res;
        
    }
};
//Second fastest
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        for(int i=0;i<asteroids.size();i++){
            bool flag=true;
            while(s.size()&&s.top()>0&&asteroids[i]<0){
                if(abs(s.top())>abs(asteroids[i])){
                    flag=false;
                    break;
                }
                else if(abs(s.top())==abs(asteroids[i])){
                    s.pop();
                    flag=false;
                    break;
                }
                else s.pop();
            }
            if(flag)
                s.push(asteroids[i]);
        }
        vector<int> v;
        while(s.size()){
            v.push_back(s.top());
            s.pop();
        }
        reverse(v.begin(),v.end());
        return v;
    }
};

//Fastest
bool same(int a, int b) {
    return (a > 0 && b > 0) || (a < 0 && b < 0);
}

void print_deque(deque<int>& d) {
    cout << "d=";
    for (int i : d) {
        cout << i << " ";
    }
    cout << endl;
}

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        deque<int> result;
        
        for (int i = 0; i < (int)asteroids.size(); ++i) {
            //cout << "\n\nstart!\nastr=" << asteroids[i] << endl;
            //print_deque(result);
            
            if (result.empty()) {
                //cout << "just add" << endl;
                result.push_back(asteroids[i]);
                continue;
            }
            else if (same(asteroids[i], result.back())) { // the same direction 
                result.push_back(asteroids[i]);
                //cout << "add - same dir" << endl;
            }
            else if (result.back() < 0 && asteroids[i] > 0) {
                //cout << "just add - they won't meet" << endl;
                result.push_back(asteroids[i]);
            }
            else if (abs(result.back()) > abs(asteroids[i])) { // different directions, but explosion
                // do nothing
                //cout << "do nothing - our element is bigger" << endl;
            }
            else if (abs(result.back()) == abs(asteroids[i])) {
                result.pop_back();
                //cout << "eliminate both - same value" << endl;
            }
            else {
                result.pop_back();
                --i;
                //cout << "remove from result and give one more change" << endl;
            }
        }
        
        return vector(result.begin(), result.end());
        
    }
};