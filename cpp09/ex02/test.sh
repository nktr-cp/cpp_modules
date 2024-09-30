#!/bin/bash

test_count=0
max_tests=50000

while [ $test_count -lt $max_tests ]; do
  # Generate 21 random numbers between 1 and 100000
  random_numbers=$(jot -r 21 1 100000 | tr '\n' ' ')

  # Execute PmergeMe and capture the full output
  output=$(./PmergeMe $random_numbers)

  # Extract the number of comparisons
  comparison_count=$(echo "$output" | grep "Number of comparisons:" | uniq | awk '{print $4}')

  # Extract the "Before" and "After" lines, remove extra spaces and leading/trailing spaces, only the first match
  before=$(echo "$output" | grep -m 1 "Before:" | sed 's/Before://g' | xargs)
  after=$(echo "$output" | grep -m 1 "After:" | sed 's/After://g' | xargs)

  # Check if we got a valid number of comparisons
  if [ -n "$comparison_count" ]; then
    if [ "$comparison_count" -ge 67 ]; then
      echo "Test failed at iteration $test_count"
      echo "Number of comparisons: $comparison_count (66 or greater)"
      echo "Random numbers used: $random_numbers"
      exit 1
    fi
  else
    echo "Failed to get a valid comparison count at iteration $test_count"
    echo "got $comparison_count"
    echo "Random numbers used: $random_numbers"
    exit 1
  fi

  # Check if the "After" numbers are correctly sorted
  sorted_after=$(echo "$after" | tr ' ' '\n' | sort -n | tr '\n' ' ' | xargs)
  if [ "$after" != "$sorted_after" ]; then
    echo "Test failed at iteration $test_count"
    echo "Output is not sorted correctly."
    echo "Before: $before"
    echo "After:  $after"
    exit 1
  fi

  test_count=$((test_count + 1))

  # Optional: Print progress every 1000 tests
  if [ $((test_count % 1000)) -eq 0 ]; then
    echo "Completed $test_count tests"
  fi
done

echo "All $max_tests tests passed successfully. No comparison count was 66 or greater, and all outputs were correctly sorted."
