#Second fastest
def valid_square(p1, p2, p3, p4)
    points = [p1, p2, p3, p4]
    points.sort! { |a, b| custom_sort(a, b) }
    distance(points[0], points[1]) != 0 &&
    all_equal?(
        distance(points[0], points[1]),
        distance(points[1], points[3]),
        distance(points[3],points[2]),
        distance(points[2], points[0])) && 
    all_equal?(distance(points[0], points[3]), distance(points[1], points[2]))
end

def custom_sort(a, b)
    b[0] == a[0] ? a[1] - b[1] : a[0] - b[0]
end

def all_equal?(*elements)
  elements.all? { |x| x == elements.first }
end

def distance(a, b)
    Math.sqrt(((b[0]-a[0])**2) + ((b[1] - a[1])**2)).to_i
end

#Fastest
# @param {Integer[]} p1
# @param {Integer[]} p2
# @param {Integer[]} p3
# @param {Integer[]} p4
# @return {Boolean}
def valid_square(p1, p2, p3, p4)
  all = [p1, p2, p3, p4]
  lines = Hash.new { 0 }
  (0...all.length).each do |i|
    x1, y1 = all[i]
    ((i + 1)...all.length).each do |j|
      x2, y2 = all[j]
      lines[dist(x1, y1, x2, y2)] += 1
    end
  end
  
  return false if lines.keys.length != 2
  side = lines.keys.min
  diag = lines.keys.max
  (diag ** 2 - 2 * (side ** 2)).abs < 10 ** -4
end

def dist(x1, y1, x2, y2)
  ((x2 - x1) ** 2 + (y2 - y1) ** 2) ** 0.5
end



=begin

x.    x

x.    x

=end