class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
	if (s.size() <= 10)
		return {};
	
	vector<string> res;
	unordered_map<string, int> map;
	
	for (int i=0; i<s.size()-9; i++) {
		string sub = s.substr(i, 10);
		map[sub]++;
		if (map[sub] == 2) {
			res.push_back(sub);
		}
	}
	return res;
    
    }
};

//Fourth fastest
class Solution1 {  // 4 进制
public:
	vector<string> findRepeatedDnaSequences(string s) {
        if(s.size() < 10) return {}; 
		vector<string> res;
        bitset<1<<20> m1, m2;
		unordered_map<int, int> mp{ {'A', 0}, {'C', 1}, {'G', 2}, {'T', 3} };  // compare
		int t = 0, k = (1 << 20) - 1;
		for (int i = 0; i < s.size(); ++i)
		{
			t = (t << 2) & k | mp[s[i]];  // compare, k as mask
            if(i < 9) continue;
			if (!m2[t] && m1[t])  // compare
            {
                res.push_back(s.substr(i - 9, 10));
                m2.set(t);
            }
            else m1.set(t);
		}
		return res;
	}
};

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<int, int> char2val{ {'A', 0}, {'C', 1}, {'G', 2}, {'T', 3} }; 
        
        if(s.size() < 10) return {}; 
        vector<string> ans;
        bitset<1<<20> s1;
        bitset<1<<20> s2;
        
        int val = 0, mask = (1<<20)-1;
        
        for(int i = 0; i < 10; i++) 
            val = (val << 2) | char2val[s[i]]; 
        
        s1.set(val); 
        
        for(int i = 10; i < s.size(); i++)
        {
            val = ((val << 2) & mask) | char2val[s[i]];
            
            if(!s2[val] && s1[val])
            {
                s2.set(val);
                ans.push_back(s.substr(i-10+1, 10));
            }
            else s1.set(val);
            
        }
        return ans;
    } 
};

//Third fastest
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<int, int> char2val{ {'A', 0}, {'C', 1}, {'G', 2}, {'T', 3} }; 
        
        if(s.size() < 10) return {}; 
        vector<string> ans;
        bitset<1<<20> s1;
        bitset<1<<20> s2;
        
        int val = 0, mask = (1<<20)-1;
        
        for(int i = 0; i < 10; i++) 
            val = (val << 2) | char2val[s[i]]; 
        
        s1.set(val); 
        
        for(int i = 10; i < s.size(); i++)
        {
            val = ((val << 2) & mask) | char2val[s[i]];
            
            if(!s2[val] && s1[val])
            {
                s2.set(val);
                ans.push_back(s.substr(i-10+1, 10));
            }
            else s1.set(val);
            
        }
        return ans;
        
    
}

// int char2val(char c) {
//     switch (c) {
//         case 'A': return 0;
//         case 'C': return 1;
//         case 'G': return 2;
//         case 'T': return 3;
//     }
//     return 0;
//  }
};

//Second fastest
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        //cout << s << endl;    
        int comp = 0;
        int seq_length = 10; 
        
        vector <string> test;

        if(s.length() < 10)
            return test;
        
        // perfect hashing
        int *big_array;
        big_array = new int[1048575];
        int index;
        string seq_1;
        //cout << s.length() << endl;
        for(int ii = 0; ii < s.length()-seq_length+1;ii++)
        {
            seq_1 = s.substr(ii,seq_length);
            //cout << seq_1 << endl;
            index = 0;
            index = index + ((seq_1[0] - 60) / 2) % 4;
            index = index + (((seq_1[1] - 60) / 2) % 4)*4;
            index = index + (((seq_1[2] - 60) / 2) % 4)*16;
            index = index + (((seq_1[3] - 60) / 2) % 4)*64;
            index = index + (((seq_1[4] - 60) / 2) % 4)*256;
            index = index + (((seq_1[5] - 60) / 2) % 4)*1024;
            index = index + (((seq_1[6] - 60) / 2) % 4)*4096;
            index = index + (((seq_1[7] - 60) / 2) % 4)*16384;
            index = index + (((seq_1[8] - 60) / 2) % 4)*65536;
            index = index + (((seq_1[9] - 60) / 2) % 4)*262144;
            //cout << seq_1 << endl;
            //cout << "Index: " << index << endl;
            //cout << seq_1 << endl;
            if(big_array[index] == 1)
            {
                test.push_back(seq_1);
            }
            big_array[index] += 1;
        }
            
        return test; 
    }
};

//Fastest
class Solution { // bitset
public:
	vector<string> findRepeatedDnaSequences(string s) {
		vector<string> res;
		bitset<1 << 20> m1, m2;  // faster than map/set
		int t = 0, k = (1 << 20) - 1;
		for (int i = 0; i < s.size(); ++i)
		{
			t = t << 2 & k | s[i] >> 1 & 3;  // compare, k as mask   // last 3 bits of 65 67 71 84 -> 001 011 111 100
			if (i < 9) continue;
			if (!m2[t] && m1[t])  // compare
			{
				res.push_back(s.substr(i - 9, 10));
				m2.set(t);
			}
			else m1.set(t);
		}
		return res;
	}
};