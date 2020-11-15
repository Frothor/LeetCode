def poor_pigs(buckets, minutes_to_die, minutes_to_test)
  Math.log(buckets, minutes_to_test/minutes_to_die + 1).ceil
end