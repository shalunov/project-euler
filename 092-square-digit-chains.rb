def sum_of_digit_squares(n)
  n.to_s.split('').map {|d| (d.to_i)**2}.reduce(:+)
end

@ultimate_sums_of_digit_squares = []

(1..(7*9**2)).each do |m|
  n = m
  n = sum_of_digit_squares(n) while n!=89 && n!=1
  @ultimate_sums_of_digit_squares[m] = n
end

def ultimate_sum_of_digit_squares(n)
  @ultimate_sums_of_digit_squares[sum_of_digit_squares(n)]
end

puts (1...10000000).select {|n| ultimate_sum_of_digit_squares(n) == 89}.length