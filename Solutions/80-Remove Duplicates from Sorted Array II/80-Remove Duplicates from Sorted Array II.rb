#Third fastest
def remove_duplicates(nums)
    previous = nil
    twice = false
    (nums.size - 1).downto(0).each do |index|
      current = nums[index]
      
      if current == previous
        if twice
          nums.delete_at(index)
        else
          twice = true
        end
      else
        previous = current
        twice = false
      end
    end
    
    nums.size
  end

#Second fastest
def remove_duplicates(nums)
  return 0 if nums.empty?
  
  index = 0
  
  for i in 0..nums.length-1
    next if i > 1 && nums[index-2] == nums[i]
    nums[index] = nums[i]
    index+=1
  end
  
  return index
end


#Fastest
def remove_duplicates(nums)
  return 0 if nums.empty?
  
  index = 0
  for i in 0..nums.length-1
    next if index > 1 && nums[index - 2] == nums[i]
    nums[index] = nums[i]
    index += 1
  end
  
  return index
end