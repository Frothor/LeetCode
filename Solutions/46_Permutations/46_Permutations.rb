#Third fastest
# @param {Integer[]} nums
# @return {Integer[][]}
def permute(nums)
    return generate_permute(nums, 0, Array.new)
end

def generate_permute(nums, index, result)
    result << nums.dup if index == nums.length

    for i in index...nums.length
        swap(nums, index, i)
        generate_permute(nums, index+1, result)
        swap(nums, index, i)
    end
    result
end

def swap(nums, i, j)
    t = nums[i]
    nums[i] = nums[j]
    nums[j] = t
end

#Second fastest
# @param {Integer[]} nums
# @return {Integer[][]}
def permute(nums)
    if nums.length == 1
      return [nums]
    end
    
    permutations = []
    nums.each_with_index do |num, idx|
      permute(nums[0, idx] + nums[idx+1..-1]).each do |permutation|
        permutations << [num] + permutation
      end
    end
    
    permutations
  end

#Fastest
def permute(nums)
  results = []
  backtrack(nums, [], results)
  results
end

def backtrack(list, temp, results)
  if temp.length == list.length
    results << temp.dup
  end
  
  list.each do |n|
    next if temp.include? n
    temp << n
    backtrack(list, temp, results)
    temp.pop
  end
end