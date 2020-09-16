public class Solution 
{
    public class TrieNode
    {
        public TrieNode[] Children = new TrieNode[2];
    }
    
    public int FindMaximumXOR(int[] nums) 
    {
        TrieNode root = new TrieNode();
                
        foreach(var num in nums)
        {
            TrieNode node = root;
            for(int i = 31; i >= 0; i--)
            {
                int bit = (num & (1 << i)) != 0 ? 1 : 0;              
                if(node.Children[bit] == null)
                {
                    node.Children[bit] = new TrieNode();
                }
                    
                node = node.Children[bit];                    
            }
        }
        
        int result = int.MinValue;
        
        foreach(var num in nums)
        {
            TrieNode node = root;
            int xorValue = 0;
            for(int i = 31; i >= 0; i--)
            {
                int bit = (num & (1 << i)) != 0 ? 1 : 0;
                int flipBit = bit == 0 ? 1 : 0;
                
                if(node.Children[flipBit] != null)
                {
                    xorValue += (1 << i);                    
                    node = node.Children[flipBit];
                }
                else
                {
                    node = node.Children[bit];                        
                }
            }
            
            result = Math.Max(result, xorValue);
        }
                
        return result;        
    }
}

//Most common
public class Solution {
    
    private class Trie {
        public Trie[] children = new Trie[2];
    }

    private readonly int maxBits = 31;
    private Trie root = new Trie();
    
    public int FindMaximumXOR(int[] nums) {
        for(int idx = 0; idx < nums.Length; idx++) {
            Insert((uint) nums[idx]);
        }

        int max = 0;
        for(int idx = 0; idx < nums.Length; idx++) {
            uint target = (uint) ~nums[idx];
            int maxForTarget = (int) FindClosest(target);
            int maxXor = maxForTarget ^ nums[idx];
            max = Math.Max(max, maxXor);
        }
        return max;
    }

    private void Insert(uint num) {
        var node = root;
        
        for(int bit = maxBits; bit >= 0; bit--) {
            uint mask = 1u << bit;
            uint bitVal = ((uint) num & mask) >> bit;
            if(node.children[bitVal] == null) {
                var newNode = new Trie();
                node.children[bitVal] = newNode;
                node = newNode;
            } else {
                node = node.children[bitVal];
            }
        }
    }

    private int FindClosest(uint target) {
        var node = root;
        uint prefix = 0;

        for(int bit = maxBits; bit >= 0; bit--) {
            uint mask = 1u << bit;
            uint bitVal = (target & mask) >> bit;
            uint bitValToUse = bitVal;
            if(node.children[bitVal] == null) {
                bitValToUse = bitVal == 0u ? 1u : 0u;
            }

            prefix = (prefix << 1) | bitValToUse;
            node = node.children[bitValToUse];
        }
        
        return (int)prefix;
    }

}

//Fastest
public class Solution {
        public int FindMaximumXOR(int[] nums)
        {
            int max = 0, mask = 0;
            for (int i = 31; i >= 0; i--)
            {
                mask = mask | (1 << i);
                HashSet<int> set = new HashSet<int>();
                foreach (int num in nums)
                {
                    set.Add(num & mask);
                }
                int tmp = max | (1 << i);
                foreach (int prefix in set)
                {
                    if (set.Contains(tmp ^ prefix))
                    {
                        max = tmp;
                        break;
                    }
                }
            }
            return max;
        }
}