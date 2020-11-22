#https://leetcode.com/problems/unique-morse-code-words/discuss/655442/Ruby-solution.
def unique_morse_representations(words)
    a = [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
    w_map = ->x{
        x.chars.map{|x| a[x.ord - ?a.ord]}.join
    }
    words.map{|x| w_map[x]}.uniq.size
end

#Third fastest
# @param {String[]} words
# @return {Integer}
def unique_morse_representations(words)
    map = [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
    
    ret = []
    words.each_with_index do |word, idx|
      ret[idx] = ''
      bytes = word.bytes.map { |x| x - 97 }
      bytes.each { |i| ret[idx] << map[i] }
    end
    
    ret.uniq.size
  end

#Second fastest
# @param {String[]} words
# @return {Integer}
def unique_morse_representations(words)
    morse = [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
    alpha = "abcdefghijklmnopqrstuvwxyz"
    hash = {}
    unique = []
    alpha.each_char.with_index {|char, idx| hash[char] = morse[idx]}
    words.each do |word|
        new = ""
        word.each_char do |char|
            new += hash[char]
        end
        unique<<new
    end
    return unique.uniq.count
end

#Fastest
# @param {String[]} words
# @return {Integer}
def unique_morse_representations(words)
    morses = [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
    ret = {}
    words.each do |word|
      mos = ""
      word.each_byte do |chr|
        mos = mos + morses[chr-97]
      end
      ret[mos] = true
    end
    ret.keys.size
  end