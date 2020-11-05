#Second fastest
# @param {Integer} n
# @param {Integer[][]} edges
# @return {Integer[]}
def find_min_height_trees(n, edges)
    return [] if n == 0
    return [0] if n == 1
    graph = Array.new(n) {Array.new}
    edges.each do |p1, p2|
        graph[p1] << p2
        graph[p2] << p1
    end
    leaves = []
    for i in 0...graph.size
        if graph[i].size == 1
            leaves << i
        end
    end
    while n > 2
        n -= leaves.size
        new_leaves = []
        leaves.each do |l|
            v = graph[l].pop
            graph[v].delete(l)
            if graph[v].size == 1
                new_leaves << v
            end
        end
        leaves = new_leaves
    end
    leaves
end

#Fastest
# @param {Integer} n
# @param {Integer[][]} edges
# @return {Integer[]}
def find_min_height_trees(n, edges)
    return [] if n == 0
    return [0] if n == 1
    graph = Array.new(n) {Array.new}
    edges.each do |p1, p2|
        graph[p1] << p2
        graph[p2] << p1
    end
    leaves = []
    for i in 0...graph.size
        if graph[i].size == 1
            leaves << i
        end
    end
    while n > 2
        n -= leaves.size
        new_leaves = []
        leaves.each do |l|
            v = graph[l].pop
            graph[v].delete(l)
            if graph[v].size == 1
                new_leaves << v
            end
        end
        leaves = new_leaves
    end
    leaves
end