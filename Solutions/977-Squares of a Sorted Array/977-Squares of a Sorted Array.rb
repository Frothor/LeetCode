#Third fastest
# @param {Integer[]} a
# @return {Integer[]}
def sorted_squares(a)
    # an array of integers A sorted in non-decreasing order
    #return an array of the squares of each number, also in sorted non-decreasing order.
    a.map{|e| e*e}.sort
end

#Second fastest
# @param {Integer[]} a
# @return {Integer[]}
def sorted_squares(a)
  n = a.size; i = 0
  while i < n && a[i] < 0
    i += 1
  end
  a.map! { _1 * _1 }
  # return a if i == 0
  # return a.reverse if i == n
  j = i - 1
  b = [0] * a.size; k = 0
  while j >= 0 && i < n
    if a[i] < a[j]
      b[k] = a[i]
      i += 1
    else
      b[k] = a[j]
      j -= 1
    end
    k += 1
  end
  while j >= 0
    b[k] = a[j]
    j -= 1
    k += 1
  end
  while i < n
    b[k] = a[i]
    i += 1
    k += 1
  end
  b
end

#Fastest
# @param {Integer[]} a
# @return {Integer[]}
def sorted_squares(a)
    a.map{|x| x*x }.sort
end