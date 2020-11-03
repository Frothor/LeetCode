# @param {String} s
# @return {Integer}
def max_power(s)
    return 0 if s.size < 1
    return 1 if s.size < 2
    max = 0
    count = 1
    (1...s.size).each do |i|
        if s[i-1] == s[i]
            count += 1
        else
            count = 1
        end
        max = count if count > max
    end
    max
end

#Second fastest
def max_power(s)
    return 1 if s.size == 1
    i = 1
    res = 1
    cnt = 1
    while i < s.size
      if s[i] == s[i-1]
        cnt += 1
      else
        cnt = 1
      end
      res = [res, cnt].max
      i += 1
    end
    res
  end

#Fastest
def max_power(s)
    last_char = nil
    current_count = 0
    max_count = 0
    s.chars.each do |c|
      if c == last_char
        current_count = current_count + 1
      else
        current_count = 1
      end
      
      if current_count > max_count
        max_count = current_count
      end
      
      last_char = c
    end
    max_count
  end