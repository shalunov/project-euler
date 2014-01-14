def reciprocal_cycle_length(n)
  [2, 5].each {|factor_of_10| n /= factor_of_10 while n%factor_of_10 == 0}
  (1..n).each {|m| return m if (10**m-1)%n == 0}
  raise "I am clueless and don't understand the mathematics of 1/" + n.to_s
end

offset=2
puts (offset..1000).map {|n|
  reciprocal_cycle_length(n)
}.each_with_index.max[1] + offset
