#!/bin/bash

BIN=./filter

if [ ! -x "$BIN" ]; then
  echo "Error: $BIN not found or not executable"
  exit 1
fi

tests=(
  "abc" "abc" "***"
  "abcd" "abc" "***d"
  "xabcx" "abc" "x***x"
  "abcdefgaaaabcdefabc" "abc" "***defgaaa***def***"
  "abcdefgaaaabcdefabcs" "abc" "***defgaaa***def***s"
  "def" "abc" "def"
  "" "abc" ""
  "abcabcabc" "abc" "*********"
  "ababc" "abc" "ab***"
  "aabbcc" "abc" "aabbcc"
  "abcxabcx" "abc" "***x***x"
  "x" "abc" "x"
  "abcabcXabc" "abc" "******X***"
  "ABCabc" "abc" "ABC***"
)

pass=0
fail=0

for ((i=0; i<${#tests[@]}; i+=3)); do
  input="${tests[i]}"
  arg="${tests[i+1]}"
  expected="${tests[i+2]}"

  output=$(echo -n "$input" | $BIN "$arg")
  if [ "$output" = "$expected" ]; then
    echo "✅ Input: '$input' Arg: '$arg' => '$output'"
    ((pass++))
  else
    echo "❌ Input: '$input' Arg: '$arg'"
    echo "   Expected: '$expected'"
    echo "   Got:      '$output'"
    ((fail++))
  fi
done

echo
echo "Summary: $pass passed, $fail failed"
