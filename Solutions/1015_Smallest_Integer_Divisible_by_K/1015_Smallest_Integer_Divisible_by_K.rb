#https://leetcode.com/problems/smallest-integer-divisible-by-k/discuss/949012/Ruby-O(k)
def smallest_repunit_div_by_k(k)
  return -1 unless [1, 3, 7, 9].include?(k%10)
  
  mod = 0
  mod_set = Set.new
  
  (1..k).each do |length|
    mod = (10*mod + 1)%k

    return length if mod == 0
    return -1 if mod_set.include?(mod)

    mod_set << mod
  end
  
  -1
end