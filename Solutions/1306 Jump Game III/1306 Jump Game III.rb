#Third fastest
# https://leetcode.com/problems/jump-game-iii/discuss/495214/Ruby-DFS-easy-to-understand
# @param {Integer[]} arr
# @param {Integer} start
# @return {Boolean}
require 'set'

def can_reach(arr, start)
    visitted = Set[]
    return false if arr.empty? || start >= arr.count || start < 0
    dfs(start, visitted, arr)
end

def dfs(index, visitted, arr)
    return true if arr[index] == 0
    visitted.add(index)
    nxt, pre = index + arr[index], index - arr[index]
    if nxt <= arr.count - 1 and !(visitted.include? nxt)
        return true if dfs(nxt, visitted, arr)
    end
    
    return dfs(pre, visitted, arr) if pre >= 0 and !(visitted.include? pre)
    return false
end

#Second fastest
def can_reach(arr, start)
    s = [start]
    v = []
    v[start] = true
    
    until s.empty?
        i = s.pop
        if arr[i] == 0
            return true
        end
        
        step = arr[i]
        [i + step, i - step].each do |x|
            if x.between?(0, arr.length - 1) && !v[x]
                v[x] = true
                s << x
            end
        end
    end
    
    false
end

#Fastest
def can_reach(arr, start)
    s = [start]
    v = []
    v[start] = true
    
    until s.empty?
        i = s.pop
        if arr[i] == 0
            return true
        end
        
        step = arr[i]
        [i + step, i - step].each do |x|
            if x.between?(0, arr.length - 1) && !v[x]
                v[x] = true
                s << x
            end
        end
    end
    
    false
end