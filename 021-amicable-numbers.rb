def sum_of_proper_divisors(n)
  (1..n/2+1).select {|i| n % i == 0}.reduce(:+)
end

puts (2...10000).select {|n|
  d = sum_of_proper_divisors(n)
  d != n && sum_of_proper_divisors(d) == n
}.reduce(:+)
