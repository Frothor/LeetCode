def longest_substring(s, k)
  return 0 if s.empty? || s.length < k

  cnt = {}
  s.each_char { |char| cnt.key?(char) ? cnt[char] += 1 : cnt[char] = 1 }

  max = 0
  st = 0
  s.each_char.with_index do |key, i|
    if cnt[key] < k
      max = [max, longest_substring(s[st...i], k)].max
      st = i + 1
    end
  end

  st.zero? ? s.length : [max,longest_substring(s[st..-1], k)].max
end

#Second fastest
def longest_substring(s, k)
    return 0 if s.empty? || s.length < k
  
    cnt = Hash.new(0)
    s.each_char { |char| cnt[char] += 1 }
  
    max = 0
    start = 0
    s.each_char.with_index do |key, i|
      if cnt[key] < k
        max = [max, longest_substring(s[start...i], k)].max
        start = i + 1
      end
    end
  
    start.zero? ? s.length : [max, longest_substring(s[start..-1], k)].max
  end

#Fastest
def longest_substring(s, k)
  return 0 if s.size < k

  freq = {}
  
  s.split('').each do |char|
    freq[char] ||= 0
    freq[char] += 1
  end
  
  return 0 unless freq.values.any? { |value| value >= k }
  return s.size unless freq.values.any? { |value| value < k }
  
  candidates = []
  
  left = 0
  current = 0

  while current < s.size
    if freq[s[current]] < k
      candidates.push(s[left...current]) if current - left >= k
      left = current + 1
    end
    current += 1
  end
  
  candidates.push(s[left..current]) if current - left + 1 >= k
  
  candidates.map { |candidate| longest_substring(candidate, k) }.max || 0
end