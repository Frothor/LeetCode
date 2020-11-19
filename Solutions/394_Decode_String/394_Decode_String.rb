#Fourth fastest
def decode_string(s)
    loop do
      break unless s.match?(%r{((\d+)\[(([a-z]|[A-Z])*)\])})
      s.scan(%r{((\d+)\[(([a-z]|[A-Z])*)\])}).each do |subset|
        s.gsub!(subset[0], Array.new(subset[1].to_i, subset[2]).join)
      end
    end
  
    s
  end

#Third fastest
def decode_string(s)
    p s
    result = ''
    arr= []
    count = 0
    multi_letter = ''
    digit = ''
  
    s.each_char.with_index(1) do |letter, i |
      if letter == "[" && count == 0
        unless multi_letter == ''
          arr.push([multi_letter.slice(0,multi_letter.length),1])
        end
        multi_letter = ''
  
      elsif letter == "]" && count == 1
        arr.push [multi_letter,digit]
        digit = ''
        multi_letter = ''
      elsif count > 0 
          multi_letter.concat(letter)
      elsif count == 0 
        if  (letter =~ /\d/) == nil
  
          multi_letter.concat(letter)
        end
      end
      p arr
      if count == 0 && (letter =~ /\d/) == 0
        digit.concat letter
      end
      
      if letter == '['    
        count +=1
      elsif letter == ']'    
        count -=1
      end
    end
    
    unless multi_letter==''
      arr.push [multi_letter,1]
    end
  
    until arr.empty?
      add_string = arr.shift
      if add_string[0].include?('[')
        add_string[0] = decode_string(add_string[0])
      end
      result.concat(add_string[0]*add_string[1].to_i)
    end
     result
  end

#Second fastest
def decode_string(s)
    stack = []
    s.split('').each do |c|
        stack.push(c) and next unless c == ']'
        temp = ''
        ch = stack.pop
        while ch != '[' 
            temp = ch + temp
            ch = stack.pop
        end
        n = ''
        (n = stack.pop + n) while numeric?(stack[-1])
        temp = temp * n.to_i
        stack.push(temp)
    end
    return stack.join('')
end
def numeric? str
    Float(str) != nil rescue false
end

#Fastest
def decode_string(s)
    stack = []
    nums = "1234567890"
    
    (0...s.length).each do |i|
        if s[i] == "]"
            decoded = []
            while stack.last != "["
                decoded << stack.pop
            end
            stack.pop
            base = 1
            k = 0
            while !stack.empty? && nums.include?(stack.last)
                k = k + stack.pop.to_i * base
                base *= 10
            end
            
            while k != 0
                j = decoded.length - 1
                while j >= 0
                    stack.push(decoded[j])
                    j -= 1
                end
                k -= 1
            end
        else
            stack.push(s[i])
        end
    end
    stack.join("")
end