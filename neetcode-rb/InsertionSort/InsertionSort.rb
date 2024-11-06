class Pair
  attr_accessor :key, :value

  def initialize(key, value)
    @key = key
    @value = value
  end
end

class Solution
  def insertion_sort(pairs)
    return [] if pairs.count == 0

    result = [pairs.dup]

    (1...pairs.length).each do |i|
      previous_state = result.last.dup
      current = pairs[i]
      inserted = false

      (0..i).each do |j|
        if current.key < previous_state[j].key && !inserted
          previous_state.insert(j, current)
          previous_state.delete_at(i + 1)
          inserted = true
        end
      end

      result.push(previous_state)
    end

    result
  end
end

def print_pairs(pairs)
  pairs.each do |pair|
    print "{#{pair.key}, #{pair.value}} "
  end
  puts
end

# Test cases
solution = Solution.new

test_pairs_1 = [Pair.new(3, "three"), Pair.new(1, "one"), Pair.new(2, "two")]
result1 = solution.insertion_sort(test_pairs_1)

puts "Test Case 1:"
result1.each { |step| print_pairs(step) }

test_pairs_2 = [Pair.new(5, "five"), Pair.new(3, "three"), Pair.new(4, "four"), Pair.new(1, "one"), Pair.new(2, "two")]
result2 = solution.insertion_sort(test_pairs_2)

puts "Test Case 2:"
result2.each { |step| print_pairs(step) }

test_pairs_3 = [Pair.new(1, "one")]
result3 = solution.insertion_sort(test_pairs_3)

puts "Test Case 3:"
result3.each { |step| print_pairs(step) }

test_pairs_4 = []
result4 = solution.insertion_sort(test_pairs_4)

puts "Test Case 4:"
result4.each { |step| print_pairs(step) }