def is_palindrome(str)
    processed_str = str.downcase.delete(' ').gsub(/\W/, '')
    j = processed_str.length - 1

    (0..(processed_str.length/2)).each do |i|
       return false if processed_str[i] != processed_str[j -1]
    end

    true
end

# Test cases

test1 = "A man, a plan, a canal, Panama!"
test2 = "race a car";
test3 = "No 'x' in Nixon";
test4 = "Was it a car or a cat I saw?";
test5 = " ";

puts "Test Case 1: #{test1} -> #{is_palindrome(test1) ? "True" : "False"}"
puts "Test Case 2: #{test2} -> #{is_palindrome(test2) ? "True" : "False"}"
puts "Test Case 3: #{test3} -> #{is_palindrome(test3) ? "True" : "False"}"
puts "Test Case 4: #{test4} -> #{is_palindrome(test4) ? "True" : "False"}"
puts "Test Case 5: #{test5} -> #{is_palindrome(test5) ? "True" : "False"}"
