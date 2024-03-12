// https://leetcode.com/problems/word-frequency

# Read from the file words.txt and output the word frequency list to stdout.
grep -oE '[a-z]' words.txt | uniq -c | sort -nr | awk '{print $2 " " $1}'