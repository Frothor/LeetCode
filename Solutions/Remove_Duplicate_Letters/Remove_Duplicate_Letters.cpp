//O(nlogn)
//Constructing result string by choosing suitable element
string removeDuplicateLetters(string s) {
        unordered_map<char, vector<int> > umap;
        vector<bool> valid(26, false);
        string res = "";

        for(int i=0; i<s.length(); i++){
            umap[s[i]].push_back(i);
            valid[s[i]-'a'] = true;
        }

        int distinctCount = umap.size();
        int curIndex = 0;

        while(distinctCount--){
            for(char ch='a'; ch<='z'; ch++) {
			    // check character validity smaller -> bigger
                if(valid[ch-'a']) {
                    bool flag = true;
                    int index = lower_bound(umap[ch].begin(), umap[ch].end(), \
                                            curIndex) - umap[ch].begin();
					// check if all remaining characters appear atleast once if current character is choosen
                    for(char ch2='a'; ch2<='z'; ch2++) { 
                        if(not valid[ch2-'a'] or ch == ch2)   continue;
                        if(upper_bound(umap[ch2].begin(), umap[ch2].end(), \
                                       umap[ch][index]) - umap[ch2].begin() == umap[ch2].size()) {
                            flag = false;
                            break;
                        }
                    }

                    if(flag) {
                        valid[ch-'a'] = false;
                        res += ch;
                        curIndex = umap[ch][index];
                        umap.erase(ch);
                        break;
                    }
                }
            }
        }
        return res;
    }

//O(n)
//Greedy Approach
string removeDuplicateLetters(string s) {
        string res = "";
        vector<bool> visited(26, false);
        vector<int> dict(26, 0);

        for(auto it: s)     dict[it-'a'] ++;

        for(int i=0; i<s.length(); i++) {
            dict[s[i]-'a'] --;
            if(visited[s[i]-'a']) continue;
            while ( res.size() and res.back() > s[i] and dict[res.back() -'a'] ) {
                visited[res.back()-'a'] = false;
                res.pop_back();
            }
            res += s[i];
            visited[s[i]-'a'] = true;
        }
        return res;
    }

//Another
string removeDuplicateLetters(string s) {
 
    string str="";
    
    unordered_map<char,int> mp;
    vector<bool> visited(26,false);
    
    //count frequency of each character
    for(auto ch:s)
        mp[ch]++;
    
    for(auto c:s)
    {
        mp[c]--;
        
        //means we have not visited the current character before
        if(visited[c-'a']==false)
        {
            //if the last character at string is lexographically greater and 
            //its count is still there so that it can be adjusted later on in iteration
            //we remove it
            while(str.length()>0 and c<str.back() and mp[str.back()]>0)
            {
                visited[str.back()-'a']=false;
                str.pop_back();
            }
            //after we are done with removing elements from last
             //push the current element and set visited to true
        str.push_back(c);
        visited[c-'a']=true;
        }
       
    }
    
    return str;
}

//Most common
class Solution {
public:
    string removeDuplicateLetters(string s) {
        string res = "0";
        vector<int> dict(128, 0);
        for (char &c : s) dict[c]++;
        unordered_set<char> instk;
        for (char &c : s) {
            dict[c]--;
            if (instk.count(c)) continue;
            while (res.back() > c && dict[res.back()] > 0) {
                instk.erase(res.back());
                res.pop_back();
            }
            res.push_back(c);
            instk.insert(c);
        }
        return res.substr(1);
    }
};

//Fastest
class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> dict(256, 0);
        vector<bool> visited(256, false);
        for(auto ch : s)  dict[ch]++;
        string result = "0";
        /** the key idea is to keep a monotically increasing sequence **/
        for(auto c : s) {
            dict[c]--;
            /** to filter the previously visited elements **/
            if(visited[c])  continue;
            while(c < result.back() && dict[result.back()]) {
                visited[result.back()] = false;
                result.pop_back();
            }
            result += c;
            visited[c] = true;
        }
        return result.substr(1);
    }
};