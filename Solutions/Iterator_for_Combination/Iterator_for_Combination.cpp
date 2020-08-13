set<string>GenaretAllComb(string s,int len){
    int mask = 1<<s.length();
    set<string>hold;
    string comString = "";
    for(int no=1;no<mask;no++){
        int num = no,i = 0;
        while(num){
            if(num&1)comString = comString + s[i];
            i++,num>>=1;
        }
        if(comString.length()==len)hold.insert(comString);
        comString = "";
    }
    return hold;
}

class CombinationIterator {
public:
    set<string>st;
    set <string> :: iterator cur;
    CombinationIterator(string characters, int combinationLength) {
        this->st = GenaretAllComb(characters,combinationLength);
        this->cur = begin(st);
    }
    
    string next() {
        return !(cur==end(st))?*cur++:"";
    }
    
    bool hasNext() {
        return !(cur==end(st));
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

 //Commmon
 class CombinationIterator {
public:
    CombinationIterator(string characters, int combinationLength) {
      n = characters.size();
      k = combinationLength;
      s = characters;
      nums.resize(k);
      iota(nums.begin(), nums.end(), 0);
      has_next = true;
    
    }
    
    string next() {
      int i = k-1;
      string rsl;
      for (int j  = 0; j < k; ++j) {
        rsl += s[nums[j]];  
      }
      while (i >= 0 && nums[i] == n-k+i) --i;
      if (i >= 0) {
        nums[i]++;
        for (int j = i+1; j < k; ++j) {
          nums[j] = nums[i] + (j-i);
        }
      } else {
        has_next = false;
      }
      return rsl;
    }
    
    bool hasNext() {
      return has_next; 
    }
    
    bool has_next;
    int n;
    int k;
    vector<int> nums;
    string s;
  
};


//Fastest
class CombinationIterator {
public:
    vector<int> a;
    vector<int> b;
    int stop;
    string s;
    int n;
    CombinationIterator(string characters, int combinationLength) {
        n = combinationLength;
        int m = characters.size();
        b.resize(n,0);
        stop = -1;
        s = characters;
        for(int i = 0; i<n;i++)
        {
            a.emplace_back(i);
        }
        for(int i=n-1, j=m-1; i>=0;i--,j--)
        {
            b[i]=j;
        }
        if(m==n)
            stop = 0;
    }
    
    string next() {
        string t;
        for(int i = 0; i<a.size();i++)
        {
            t+=s[a[i]];
        }
        int i= a.size()-1;
        bool bc=false;
        for( ; i> stop; i--)
        {
            if(a[i]<b[i])
            {
                a[i]++;
                bc=true;
                if(i==stop+1 && a[i]==b[i])
                {
                    stop = i;
                }
                break;
            }
        }
        if(!bc)
        {
            stop=n-1;
        }
        for(int j = i+1; j<a.size();j++)
        {
            a[j]= a[j-1]+1;
        }
        
        return t;
    }
    
    bool hasNext() {
       
        if(stop == n-1)
            return false;

        
        return true;
    }
};