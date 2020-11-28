//https://leetcode.com/problems/longest-substring-with-at-least-k-repeating-characters/discuss/87815/C-0ms-solution
int myLongestSubstring(char *s, int begin, int end, int k) {
    if (end > strlen(s) || 
        begin >= end || 
        end - begin < k) 
        return 0;

    int i;
    int map[26];
    int lmap = 0;
    int result = 0;
    int tb = begin;
    int tr = 0;
    int count = 0;
    
    memset(map, 0, 26 * sizeof(int));
    for (i = begin; i < end; ++i) {
        ++map[s[i] - 'a'];
        if (map[s[i] - 'a'] == k)
            lmap |= 1<<(s[i] - 'a');
    }
    
    for (i = begin; i < end; ++i) {
        if (!(lmap&(1<<(s[i] - 'a')))) {
            tr = myLongestSubstring(s, tb, i, k);
            result = tr > result ? tr : result;
            tb = i + 1;
        } else {
            ++count;
        }
    }
    
    if (tb != begin) {
        tr = myLongestSubstring(s, tb, end, k);
        result = tr > result ? tr : result;
    } else {
        result = count;
    }
    
    return result;
}

int longestSubstring(char* s, int k) {
    return myLongestSubstring(s, 0, strlen(s), k);
}

//Another
int longestSubstringR(char * s, int k, int start, int end){
    
    int count[26] = {0}, max_len = 0, res = 0;
    int i = 0, j = 0;
    bool isLongest = true;
    bool impossible = true;
    
    for(i = start; i < end; ++i){
        ++count[s[i]-'a'];
    }
    
    for(i = 0; i < 26; ++i){
        if(count[i] > 0 && count[i] < k)
            isLongest = false;
        else if(count[i] >= k)
            impossible = false;
    }
    
    if(isLongest)
        return end-start;
    
    if(impossible)
        return 0;
    
    j = start;
    for(i = start; i < end; ++i){
        if(count[s[i]-'a'] < k){
            if(i-j >= k) {
                res = longestSubstringR(s, k, j, i);
                max_len = fmax(max_len, res);
            }
            j = i+1;
        }
        else if(i == end-1 && i-j+1 >= k){
            res = longestSubstringR(s, k, j, i+1);
            max_len = fmax(max_len, res);
        }
    }
    return max_len;
}

int longestSubstring(char * s, int k){
    return longestSubstringR(s, k, 0, strlen(s));
    
}