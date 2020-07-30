class Solution {
    unordered_map<string, vector<string>> dp;
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        if(dp.find(s) != dp.end())
            return dp[s];
        vector<string> result;
        for(string w : wordDict){
            if(s.substr(0, w.length()) == w){
                if(w.length() == s.length())
                    result.push_back(w);
                else{
                    vector<string> tmp = wordBreak(s.substr(w.length()), wordDict);
                    for(string t : tmp)
                        result.push_back(w + " " + t);
                }
            }       
        }
        dp[s] = result;
        return result;
    }
};

/*
Most common:
class Solution {
public:
    
    vector<string> wordBreakHelper(string s, int cidx, 
                             unordered_set<string>& wordDict, 
                             unordered_map<int,vector<string>> &dp) 
    {
        int len = s.length();
        
        if(cidx == len) return {""};
        
        if(dp.find(cidx) == dp.end()) {
            string prefix = "";
            vector<string> possible;
            for(int i=cidx; i < len; i++) {
                prefix += s[i];
                if(wordDict.find(prefix) != wordDict.end()) {
                    vector<string> nxt_possible = 
                                        wordBreakHelper(s,i+1,wordDict,dp);
                    if(nxt_possible.size() > 0) {
                        for(string nxt : nxt_possible) 
                            if(nxt != "")
                                possible.push_back(prefix + " " + nxt);
                            else possible.push_back(prefix);
                    }
                }
            }
            dp[cidx] = possible;
        }
        return dp[cidx];
    }
    
    vector<string> wordBreak(string s, vector<string>& wordList) {
        
        unordered_set<string> wordDict;
        for(string w : wordList) wordDict.insert(w);
        unordered_map<int,vector<string>> dp;
        
        return wordBreakHelper(s,0,wordDict,dp);
    }
};

Fastest:
struct Node
{
#define Alphabetsize 58
	Node* next[Alphabetsize];
	bool valid;
	Node()
	{
		valid = 0;
		memset(next, 0, sizeof(Node*) * Alphabetsize);
	}
};

class WordTree
{
public:
	WordTree() { head = new Node(); }
	~WordTree() {}
	void Add(std::string in)
	{
		Node* current = head;
		Node* temp;
		for (auto i : in)
		{
			temp = current->next[int(i - 'A')];
			if (temp == NULL) current->next[int(i - 'A')] = new Node();
			current = current->next[int(i - 'A')];
		}
		current->valid = 1;
	}

	void FindPrefixMatches(std::string& targetword, std::vector<std::string>& out)
	{
		Node* node = head;
		std::string current;
		for (unsigned int i = 0; i < targetword.size(); i++)
		{
			if (node->next[targetword[i] - 'A'] != NULL)
			{
				current.push_back(targetword[i]);
				node = node->next[targetword[i] - 'A'];
				if (node->valid) out.push_back(current);
			}
			else break;
		}
	}

	bool FindWord(std::string& targetword)
	{
		Node* node = head;
		for (unsigned int i = 0; i < targetword.size(); i++)
		{
			if (node->next[targetword[i] - 'A'] != NULL) node = node->next[targetword[i] - 'A'];
			else return false;
		}
		if (node->valid) return true; else return false;
	}
private:
	Node* head;
};

class Solution {
private:
	void helper(std::string s, WordTree* t, std::vector<std::string>& r, std::string c = "")
	{
		std::vector<std::string> rl;
		t->FindPrefixMatches(s, rl);
		for (auto i : rl)
		{
			std::string w = s.substr(i.size());
			if (i.size() == s.size()) r.push_back((c.size() ? c + " " + i : i));
			else helper(w, t, r, (c.size() ? c + " " + i : i));
		}
	}
public:
	std::vector<std::string> wordBreak(std::string s, std::vector<std::string>& wordDict)
	{
		std::vector<int> a(256, 0), b(256, 0);
		for (auto i : s) a[i]++;
		for (auto i : wordDict) for (auto j : i) b[j]++;
		for (int i = 0; i < a.size(); i++) if (a[i] &&  b[i] == 0) return {};
		WordTree* t = new WordTree();
		for (auto i : wordDict) t->Add(i);
		std::vector<std::string> r;
		helper(s, t, r);
		return r;
	}
};

Another fast Trie solution:
class Node {
public:
    Node(): end(false), next(26, NULL) {}
    bool end;
    vector<Node*> next;
};

class Trie {
public:
    Trie() {
        root = new Node();
    }

    void add(string& str) {
        Node* node = root;
        for (auto& c: str) {
            if (!node->next[c - 'a']) node->next[c - 'a'] = new Node();
            node = node->next[c - 'a'];
        }
        node->end = true;
    }

    vector<string> dfs(const string& s, int idx, unordered_map<int, vector<string>>& mp) {
        if (idx == s.size()) return vector<string>{""};
        if (mp.count(idx)) return mp[idx];
        Node* node = root;
        vector<string> ret;
        for (int i = idx; i < s.size(); ++i) {
            if (!node->next[s[i] - 'a']) break;
            node = node->next[s[i] - 'a'];
            if (node->end) {
                vector<string> sub_ret = dfs(s, i + 1, mp);
                string cur_str = s.substr(idx, i + 1 - idx);
                for (auto& str: sub_ret) {
                    ret.push_back(cur_str + (str.size() ? " " : "") + str);
                }
            }
        }
        return mp[idx] = ret;
    }

private:
    Node* root;
};

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        if (s.size() == 0) return vector<string>();
        Trie trie;
        for (auto& word: wordDict) {
            trie.add(word);
        }
        unordered_map<int, vector<string>> mp;
        return trie.dfs(s, 0, mp);
    }
};
*/