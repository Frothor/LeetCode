public class Solution {
    public IList<string> FindRepeatedDnaSequences(string s) {
        if(string.IsNullOrEmpty(s) || s.Length < 10)
            return new List<string>();
        
        var map = new Dictionary<string, int>();
        for(int i = 0; i + 9 < s.Length; i++) {
            var sub = s.Substring(i, 10);
            if(map.ContainsKey(sub))
                map[sub]++;
            else
                map.Add(sub, 1);
        }
        var res = new List<string>();
        foreach(var key in map.Keys) {
            if(map[key] > 1)
                res.Add(key);
        }
        
        return res;
    }
}

//Most common
public class Solution {
    public IList<string> FindRepeatedDnaSequences(string s) {
        if(s==null||s.Length<=10) return new List<string>();
        Dictionary<string, int> map=new Dictionary<string,int>();
        for(int i=0;i<=s.Length-10;i++)
        {
            string str=s.Substring(i,10);
            if(map.ContainsKey(str)) map[str]++;
            else map[str]=1;
        }
        IList<string> res=new List<string>();
        foreach(var kv in map)
        {
            if(kv.Value>1) res.Add(kv.Key);
        }
        return res;
    }
}

//Third fastest
public class Solution {
    public IList<string> FindRepeatedDnaSequences(string s) {
        int len = s.Length;
        var result = new List<string>();
        if(len <=10)
            return result;
        //in hexadecimal, 4 bits, from 0~9, A-F(10-15)
        int mask = 0x7ffffff;
        var m = new Dictionary<char, int>();
        //用3个bit就可以表示ACGT
        m.Add('A',1); m.Add('C',2); m.Add('G',3); m.Add('T',4);
        //所以用3bit来表示每个字符，总长应该是30
        int cur=0;
        var dic = new Dictionary<int, int>();
        for(int i = 0; i < 9; ++i)
            cur = cur << 3 | m[s[i]];
        
        for(int i = 9; i < len; ++i){
            //mask的长度是27，这样&操作可以把当前cur里第一个字符给消除了，再左移三位
            cur = ((cur & mask) << 3) | m[s[i]];
            if(!dic.ContainsKey(cur))
                dic.Add(cur,0);
            dic[cur]++;
            if(dic[cur] == 2)
                result.Add(s.Substring(i-9,10));
        }
        return result;
        
    }
}

//Second fastest
public class Solution {
    public IList<string> FindRepeatedDnaSequences(string s) {
        Dictionary<char, int> integ= new Dictionary<char, int>();
        integ['A'] = 0;
        integ['C'] = 1;
        integ['G'] = 2;
        integ['T'] = 3;
        int[] num = new int[s.Length];
        int k = 0;
        foreach(char c in s){
            num[k++] = integ[c];
        }
        
        //HashSet<string> set1 = new HashSet<string>();
        HashSet<int> set1 = new HashSet<int>();
        HashSet<string> set2= new HashSet<string>();
        IList<string> res = new List<string>();
        /*for(int i = 0; i <= s.Length-10; i++){
            int k = i+10;
            string r = s.Substring(i,10);
            if(!set1.Contains(r))
                set1.Add(r);
            else
                res.Add(r);
        }*/
        int sum;
        int a = 4;
        int aL = (int)Math.Pow(4,10);
        int hash = 0;
        for(int i=0; i<=s.Length-10; i++){
            if(i == 0){
                for(int j = 0; j<10; j++)
                    hash = hash * a + num[j];
            }
            else{
                int start = num[i-1];
                int end = num[i+10-1];
                hash = (hash * a) - (start*aL) + end;
            }
            
            if(!set1.Contains(hash)){
                set1.Add(hash);
            }
            else{
                set2.Add(s.Substring(i, 10));
            }
        }
        return set2.ToList();
    }
}

//Fast
public class Solution {
        public IList<string> FindRepeatedDnaSequences(string s)
        {
            Dictionary<char, int> map = new Dictionary<char, int>();
            map['A'] = 0;
            map['C'] = 1;
            map['G'] = 2;
            map['T'] = 3;

            HashSet<int> visited = new HashSet<int>();
            HashSet<string> result = new HashSet<string>();

            int bitMask = 0;
            for (int i = 0; i < s.Length; i++)
            {
                bitMask <<= 2;
                bitMask |= map[s[i]];
                if (i >= 10)
                {
                    bitMask &= (1 << 20) - 1;
                    bitMask &= (1 << 21) - 1;
                }

                if (i >= 9)
                {
                    if (visited.Contains(bitMask))
                    {
                        result.Add(GetString(bitMask));
                    }
                    else
                    {
                        visited.Add(bitMask);
                    }
                }
            }

            return result.ToList();
        }

        private string GetString(int bitMask)
        {
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < 20; i++)
            {
                int bit1 = bitMask & (1 << i);
                i++;
                int bit2 = bitMask & (1 << i);
                if (bit1 == 0 && bit2 == 0)
                {
                    sb.Insert(0, 'A');
                }
                else if (bit1 > 0 && bit2 == 0)
                {
                    sb.Insert(0, 'C');
                }
                else if (bit1 == 0 && bit2 > 0)
                {
                    sb.Insert(0, 'G');
                }
                else
                {
                    sb.Insert(0, 'T');
                }
            }

            return sb.ToString();
        }
}