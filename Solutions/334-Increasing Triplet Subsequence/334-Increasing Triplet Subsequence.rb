#Fourth fastest
#https://leetcode.com/problems/increasing-triplet-subsequence/discuss/976713/Ruby-O(n)-time-O(1)-space
def increasing_triplet(nums)
  min = Float::INFINITY
  mid = Float::INFINITY
  nums.each do |x|
    next min = x if x < min
    next mid = x if x > min && x < mid
    return true if x > mid
  end
  false
end

#Another
def increasing_triplet(nums)
    low = mid = Float::INFINITY
  
  for num in nums
    if num <= low
      low = num       # smallest so far
    elsif num <= mid
      mid = num       # 2nd smallest so far
    else 
      return true     # 3rd, so we return
    end    
  end

  return false
end

#Third fastest
def increasing_triplet(nums)
    small = Float::INFINITY
    big = Float::INFINITY
    nums.each do |num|
        if num <= small
            small = num
        elsif num <= big
            big = num
        else
            return true
        end
    end
    false
end

#Second fastest
def increasing_triplet(nums)
    max = ("1"*31).to_i(2)
    first = max
    second = max
    nums.each do |num|
        if num <= first
            first = num
        elsif num <= second
            second = num
        else
            return true
        end
    end
    
    return false
end

#Fastest
def increasing_triplet(nums)
    small = 1000000000000
    big = 1000000000000
    nums.each do |i|
        if i <= small
            small = i 
        elsif i <= big
            big = i
        else 
            return true
        end
    end
    false          
end