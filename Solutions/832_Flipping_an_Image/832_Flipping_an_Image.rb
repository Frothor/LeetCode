#Third fastest
def flip_and_invert_image(a)
    a.map do |row|
      ret = []
      row.each_with_index.map do |el, i|
        ret[row.size - i - 1] = row[i] == 0 ? 1 : 0
      end
      ret
    end
end

#Second fastest
# @param {Integer[][]} a
# @return {Integer[][]}
def flip_and_invert_image(a)
    a.map!(&:reverse!).each do |row|
       row.map! { |bit| bit.zero? ? 1 : 0 }
    end
end

#Fastest
# @param {Integer[][]} a
# @return {Integer[][]}
def flip_and_invert_image(a)
    a.each do |arr|
        arr.reverse!
        arr.map! { |pixel| pixel ^ 1 }
    end
    return a
end