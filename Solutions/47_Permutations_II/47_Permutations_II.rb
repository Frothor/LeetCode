#Without set
# @param {Integer[]} nums
# @return {Integer[][]}
def permute_unique(nums)
  return [] if nums.empty?

  permute(nums.sort)
end

def permute(nums)
  return [nums] if nums.count == 1

  result = []
  nums.each_with_index do |elt, index|
    next if index > 0 && nums[index - 1] == elt
    result += permute(nums[0...index] + nums[index + 1..-1]).map{|p| [elt] + p}
  end
  
  result
end

#Third fastest
def permute_unique(nums)
    nums.sort!
    res = []
    used = Array.new(nums.length, false)
    helper(nums, 0, [], res, used)
    res
end

def helper(nums, i, curr, res, used)
    if i >= nums.length
        res << curr.dup
        return
    end
    
    0.upto(nums.length - 1).each do |j|
        next if used[j]
        next if j > 0 && nums[j] == nums[j - 1] && !used[j - 1]
        curr << nums[j]
        used[j] = true
        helper(nums, i + 1, curr, res, used)
        curr.pop
        used[j] = false
    end
end

#Second fastest
def permute_unique(nums)
    return [] if nums.empty? || nums.nil?
    result = []
      nums.sort!
    backtrack(nums, result, 0, [], Array.new(nums.length, false))
    return result
  end
  
  def backtrack(nums, result, start, temp, used)
      if temp.length == nums.length
          result << Array.new(temp) 
      else
          for i in 0.upto(nums.length - 1)
          next if used[i] || i > 0 && nums[i] == nums[i-1] && !used[i-1]
          used[i] = true
          temp << nums[i]
          backtrack(nums, result, 0, temp, used)
          used[i] = false
          temp.delete_at(-1)
      end
      end
  end

#Fastest
def permute_unique(nums)
    nums.sort!
    all_permutations = []
    used = [false] * nums.size
    generate_permutations(nums, all_permutations, used, [])
    all_permutations.to_a
  end
  
  def generate_permutations(nums, all_permutations, used, current_list)
    if current_list.size == nums.size
      all_permutations << current_list.clone
    else
      (0...nums.size).each do |i|
        next if used[i] || (i > 0 && nums[i - 1] == nums[i] && used[i - 1] == false)
  
        current_list << nums[i]
        used[i] = true
  
        generate_permutations(nums, all_permutations, used, current_list)
  
        used[i] = false
        current_list.pop
      end
    end
  end