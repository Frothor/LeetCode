# @param {String} s
# @return {Integer}
def length_of_longest_substring(s)
    return s.size if s.size < 2
    
    queue, hash = [], {}
    s.each_char.reduce(-Float::INFINITY) do |max, c|
        hash.delete(char = queue.shift) until queue.empty? || char.eql?(c) if hash.key?(c)

        [max, (queue << hash[c] = c).size].max
    end
end

# Second fastest
# @param {String} s
# @return {Integer}
def length_of_longest_substring(s)
    return 0 if s.length == 0
    return 1 if s.length == 1
    
    current_max = 0
    
    test = ""
    s.each_char do |char|
        test = test[test.index(char)+1..] if test.include? char
        test << char
        current_max = [test.size, current_max].max
    end
    current_max
end

# Fastest
# @param {String} s
# @return {Integer}
def length_of_longest_substring(s)
    r = 0
    i = 0
    j = 0
    m = Hash.new(0)
    s.each_char do |c|
      r = [r, (j += 1) - (i = [i, m[c]].max)].max
      m[c] = j
    end
    r
  en