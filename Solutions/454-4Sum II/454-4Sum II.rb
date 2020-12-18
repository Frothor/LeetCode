#Third fastest
# @param {Integer[]} a
# @param {Integer[]} b
# @param {Integer[]} c
# @param {Integer[]} d
# @return {Integer}
def four_sum_count(a, b, c, d)
  len = a.length
  return 0 if len == 0
  
  partial_sums = Hash.new(0)
  0.upto(len - 1) do |i|
    0.upto(len - 1) do |j|
      partial_sums[a[i] + b[j]] += 1
    end
  end
  
  res = 0  
  0.upto(len - 1) do |i|
    0.upto(len - 1) do |j|
      sum = c[i] + d[j]
      res += partial_sums[-sum]
    end
  end
  
  res
end

#Second fastest
# @param {Integer[]} a
# @param {Integer[]} b
# @param {Integer[]} c
# @param {Integer[]} d
# @return {Integer}
def four_sum_count(a, b, c, d)
  hash = {}
  a.each do |first|
      b.each do |second|
          if hash[first+second].nil?
              hash[first+second] = 1
          else
              hash[first+second] += 1
          end
      end
  end
  count = 0
  c.each do |first|
      d.each do |second|
          if hash[-(first+second)]
              count += hash[-(first+second)]
          end
      end
  end
   return count   
end

#O(n^2)
#Fastest?
#https://leetcode.com/problems/4sum-ii/discuss/976116/Ruby-O(n2)
def four_sum_count(a, b, c, d)
  count = 0
  h = Hash.new(0)
  a.each do |i|
    b.each do |j|
      h[j+i] += 1
    end
  end

  c.each do |i|
    d.each do |j|
      count += h[-(j+i)]
    end
  end
  count
end