#Second fastest
def sum(nums, divisor)
    divisor
  nums.reduce(0) do |acc, n|
      n-=1
    acc + n/divisor + 1
  end
end

def smallest_divisor(nums, threshold)
  left = (nums.sum/threshold.to_f).ceil
  right = nums.max

  while left < right
    divisor = (left + right) >> 1
    s = sum(nums, divisor)

    if s <= threshold
      right = divisor
    else
      left = divisor + 1
    end
  end

  left
end

#Fastest
# @param {Integer[]} nums
# @param {Integer} threshold
# @return {Integer}
def smallest_divisor(nums, threshold)
  low = 1
  high = nums.max
  
  while low < high
    mid = (low + high)/2
    
    if nums.map{|num| (num + mid - 1)/mid}.sum > threshold
      low = mid + 1
    else
      high = mid
    end
  end
  
  low
end