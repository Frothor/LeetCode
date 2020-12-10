#Third fastest
def valid_mountain_array(a)
    return false if a.size < 3
    direction = 1
    for i in 0..a.size-1
        if i > 0
            return false if a[i] - a[i-1] == 0
            direction = 0 if a[i] - a[i-1] < 0
        else
            return false if a[i] - a[i+1] > 0
        end
        return false if a[i] - a[i-1] > 0 if direction == 0
    end
    return direction == 0
end

#Second fastest
def valid_mountain_array(a)
    return false if a.length < 3
    l = left(a)
    r = right(a)
    !l || !r ? false : l == r
end

def left(a)
    i = 0
    while i < a.length - 1 do
        return false if a[i] == a[i+1]
        break if a[i] > a[i+1]
        i+=1
    end
    return i == a.length - 1 ? false : i
end

def right(a)
    i = a.length - 1
    while i > 0 do
        return false if a[i] == a[i-1]
        break if a[i-1] < a[i]
        i-=1
    end
    return i == 0 ? false : i
end

#Fastest
def valid_mountain_array(arr)
  # return false if size < 3 OR array starts in decreasingorder
  return false if arr.size < 3 || arr[0] > arr[1]

  dec_found = false
  i = 1
  
  # traverse the increasing part
  while i < arr.size
    return false if arr[i] == arr[i-1]
    if arr[i] < arr[i-1]
      dec_found = true
      break
    end
    i += 1
  end

  
  # finished iteration but dec_found = false
  # which means only increasing values present
  # so return false
  return false unless dec_found

# traverse the decreasing part of the array
  while i < arr.size
    return false if arr[i] >= arr[i-1]
    i += 1
  end

  true
end