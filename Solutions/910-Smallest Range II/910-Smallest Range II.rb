#https://leetcode.com/problems/smallest-range-ii/discuss/980273/Ruby-O(NlogN)
# @param {Integer[]} a
# @param {Integer} k
# @return {Integer}
def smallest_range_ii(a, k)
  a.sort!
  diff = a.last - a.first
  
  if k < diff
    (a.count - 1).times do |i|
      max = [a.last - k, a[i] + k].max
      min = [a.first + k, a[i+1] - k].min
      diff = [diff, (max - min).abs].min
    end
  end

  diff
end