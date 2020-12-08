#Third fastest
# @param {Integer[]} time
# @return {Integer}
def num_pairs_divisible_by60(time)
    count = 0
    hash = Hash.new(0) # store time modulo 60 as key, and amount of suct modulo as a value.
    time.each do |duration|
        md = duration % 60

        if md == 0
            count += hash[0]
        else
            count += hash[60 - md]
        end
        hash[md] += 1

    end
    count
end

#Second fastest
# @param {Integer[]} time
# @return {Integer}
def num_pairs_divisible_by60(time)
    pairs = 0
    
    remainders = Array.new(60) { Integer(0) }
    time.each do |song|
      r60 = song % 60
      if r60 == 0
        pairs += remainders[0]
      else
        pairs += remainders[60 - (song % 60)]
      end
      
      remainders[r60] += 1
    end
      
    pairs
  end

#Fastest
# @param {Integer[]} time
# @return {Integer}
def num_pairs_divisible_by60(time)
  pairs = 0
  
  remainders = Array.new(60) { Integer(0) }
  time.each do |song|
    r60 = song % 60
    if r60 == 0
      pairs += remainders[0]
    else
      pairs += remainders[60 - (song % 60)]
    end
    
    remainders[r60] += 1
  end
    
  pairs
end