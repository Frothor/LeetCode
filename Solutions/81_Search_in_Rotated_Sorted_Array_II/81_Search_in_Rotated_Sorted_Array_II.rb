#Third fastest
# @param {Integer[]} nums
# @param {Integer} target
# @return {Boolean}
def search(nums, target)
    if nums==nil || nums.length==0
        return false
    end
     
    nums = nums.map(&:to_i) 
     low=0
     high=nums.length-1
     mid=0
   #    |  |
   #  | |  |                               
   #  | |  |      | |
    # | |  |  | | | |
   #  | |  |  | | | |
 
     while low<=high
         mid=low+(high-low)/2;
        # puts "mid is #{mid}"
         if nums[mid]==nums[low]
            if  target==nums[mid]
                 return true
            else
                   low =low+1
            end
         elsif nums[mid]<nums[low]
                if   target==nums[mid]
                        return true
                elsif target>nums[mid] && target <=nums[high]
                         low=mid+1
                else 
                         high=mid-1
                end
         else
                if target==nums[mid]
                        return true
                elsif target<nums[mid] && target >= nums[low]
                         high=mid-1
                else
                         low=mid+1
                end    
         end    
     end         
             
             
    return false         
             
 end

#Second fastest and most common
# @param {Integer[]} nums
# @param {Integer} target
# @return {Boolean}
def search(nums, target)
    
    if(nums==nil || nums.length==0) 
        return false
    end
    
      nums= nums.map(&:to_i)
      low = 0
      high = nums.length-1;
      mid =0;
    
      while low<=high
         mid=low+(high-low)/2;
           if nums[mid]==target
               return true
           end
          
           if nums[mid]==nums[low]
               low=low+1
           elsif nums[mid]<nums[low]
               
               if target> nums[mid] && target<=nums[high]
                         low=mid+1
               else
                         high=mid-1
               end
               
           else
               if nums[low]<=target && target<nums[mid]
                        high=mid-1
               else
                        low=mid+1
               end
           end
      end
    return false
end


#Fastest
# @param {Integer[]} nums
# @param {Integer} target
# @return {Boolean}
def search(nums, target)
    nums.include?(target) ? true : false
end