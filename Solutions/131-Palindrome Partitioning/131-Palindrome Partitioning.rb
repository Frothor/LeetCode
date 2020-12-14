#Fourth fastest
def partition(s)
    @output = []
    helper(0, [], s)
    @output
end

def helper(start, comb, s)
    if start >= s.size
        @output << comb.dup

        return 
    end
    
    i = start
    
    while i < s.size
        if palindrome?(s, i, start)
            comb << s[start..i]
            
            helper(i + 1, comb, s)
            
            comb.pop
        end
        
        i += 1
    end
end

def palindrome?(s, hi, lo)
    while hi > lo
        return false if s[hi] != s[lo]
        hi -= 1
        lo += 1
    end
    
    true
end

#Third fastest
def partition(s)
    res = []
    dp = Array.new(s.length) { Array.new(s.length, false) }
    dfs(res, s, 0, [], dp)
    res
end

def dfs(res, s, start, curr, dp)
    if start >= s.length
        res << curr.dup
    end
    
    (start...s.length).each do |last|
        if s[start] == s[last] && ((last - start) <= 2 || dp[start + 1][last - 1])
            dp[start][last] = true
            curr << s[start..last]
            dfs(res, s, last + 1, curr, dp)
            curr.pop
        end
    end
end

#Second fastest
def partition(s)
    d = Array.new(s.length) { Array.new(s.length, false) }
    # d[i][j]: s[i..j] is palindrome
    1.upto(s.length).each do |l|
        0.upto(s.length - l).each do |i|
            j = i + l - 1
            d[i][j] = i == j || s[i] == s[j] && (i == j - 1 || d[i + 1][j - 1])
        end
    end
    res = []
    get_res(s, d, 0, [], res)
    res
end


def get_res(s, d, i, curr, res)
    if i >= s.length
        res << curr.dup
        return
    end
    i.upto(s.length - 1).each do |j|
        next if !d[i][j]
        curr << s[i..j]
        get_res(s, d, j + 1, curr, res)
        curr.pop
    end
end

#Fastest
def partition(s)
    s_next_indices = Hash.new {|hash, key| hash[key] = []}
    s.each_char.with_index.map {|char, index| s_next_indices[char].push(index)}
    start_end_palindrome = Hash.new {|hash, key| hash[key] = {}}
    return partition_helper(s, 0, s_next_indices, start_end_palindrome)
end

def partition_helper(s, start, s_next_indices, start_end_palindrome)
    puts "#{start}"
    if start == s.length
        return [[]]
    end
    partitions = []
    possible_indices = s_next_indices[s[start]]
    next_index = possible_indices.bsearch_index {|index| index >= start} 
    while next_index < possible_indices.length
        s_next_index = possible_indices[next_index]
        if is_palindrome(s, start, s_next_index, start_end_palindrome)
            partitions += multiply(s[start..s_next_index], partition_helper(s, s_next_index + 1, s_next_indices, start_end_palindrome))
        end
        next_index += 1
    end
    return partitions
end

def multiply(palindrome, partitions)
    partitions.each {|partition| partition.unshift(palindrome)}
    partitions
end
    
def is_palindrome(s, start_index, end_index, start_end_palindrome)
    if start_index == end_index
        return true
    elsif start_end_palindrome[start_index][end_index]
        return true
    elsif end_index - start_index == 1
        start_end_palindrome[start_index][end_index] = s[start_index] == s[end_index]
        return start_end_palindrome[start_index][end_index]
    else
        if s[start_index] != s[end_index]
            start_end_palindrome[start_index][end_index] = false
            return false
        end
        
        is_p = is_palindrome(s, start_index + 1, end_index - 1, start_end_palindrome)
        start_end_palindrome[start_index][end_index] = is_p
        return is_p    
    end
end