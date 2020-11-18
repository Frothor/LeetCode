#https://leetcode.com/problems/merge-intervals/discuss/804870/Simple-ruby-solution-with-explanation
def merge(a)
    return [] if a == nil || a.size == 0
	# First sort array by first element of each subarray.
    a = a.sort_by{|arr| arr[0]} 
    res = [a[0]]  # Push first subarray in resulting array.
    j = 0  # Keep a pointer for res array.
    for i in 0..a.size-1 do
        # Compare previous and next element using res array.
        # If second element in res subarray is greater than or equal first element in next subarray, it means elements are overlapping.
        # Calculate max by comparing second element in previous and current subarray.
        # Modify res by overriding current subarray.
        if res[j][1] >= a[i][0]
            min = res[j][0]
            max = [a[i][1],res[j][1]].max
            res[j] = [min,max]
        # If second element in res subarray is less than first element in next subarray, it means elements are non overlapping.
        # Push subarray in res and increment pointer for res.
        else
            res << a[i]
            j = j+1
        end
    end
    return res
end

#Third fastest
def merge(intervals)
    return intervals if intervals.length < 2
    
    intervals.sort_by! { |interval| interval[0] }
    result = []
    i = 0
    
    result = [intervals[0]] 
    for i in 1..intervals.length - 1
        if intervals[i][0] <= result[-1][1]
            result[-1][1] = [result[-1][1],intervals[i][1]].max
        else
            result << intervals[i]
        end
    end

    result
end

#Second fastest
def merge(intervals)
    merged = []
    intervals.sort_by! { |interval| interval.first }

    intervals.each do |interval|
      if merged.empty? || merged.last.last < interval.first
        merged << interval
      else
        merged.last[1] = interval.last if interval.last > merged.last.last
      end
    end

    return merged
end

#Fastest
def merge(intervals)
    return intervals if intervals.empty?
    intervals.sort_by!{|interval| interval[0]}
    
    ans = [intervals[0]]
    1.upto(intervals.length-1) do |i|
        if ans[-1][1] >= intervals[i][0]
            ans[-1][1] = [ans[-1][1], intervals[i][1]].max
        else
            ans << intervals[i]
        end
    end
    ans
end