#Most common
def min_cost_to_move_chips(position)
    even = 0
    odd = 0
    
    position.each do |cost|
        if cost % 2 == 0
            even += 1
        else
            odd += 1
        end
    end
    
    [even, odd].min
end

# Find the count of all positions, sum them all up
# Keep track of what the largest  cost was, and subtract from the very end
# The idea is that we need to move all the position of all but one chip

#Fastest
def min_cost_to_move_chips(chips)
  [even = chips.count { |pos| pos >> 1 << 1 == pos }, chips.size - even].min
end

#Another
# @param {Integer[]} position
# @return {Integer}
def min_cost_to_move_chips(position)
    odds = evens = 0
    position.each do |el|
        if el % 2 == 1
          odds += 1
         else
            evens += 1
        end
        
    end
    
    odds > evens ? evens : odds
end