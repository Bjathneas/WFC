# Challenge: Word Frequency Counter

Write a program that reads a text file and outputs the frequency of each word in descending order. The program should ignore punctuation and treat uppercase and lowercase letters as the same.

# Requirements:

    The program should prompt the user to enter the path to the text file.
    The program should read the file and count the frequency of each word.
    Words should be considered as sequences of characters separated by whitespace.
    Punctuation marks (such as periods, commas, and parentheses) should be ignored.
    The program should ignore the case of words, treating uppercase and lowercase letters as the same.
    The program should output each word along with its frequency, sorted in descending order of frequency.
    If multiple words have the same frequency, they should be sorted alphabetically.
    The program should handle large text files efficiently.

# Example:
Given the following text file "sample.txt":

```sql
The quick brown fox jumps over the lazy dog.
The dog and the fox are good friends.
```

Output:

```sql
the - 3
fox - 2
dog - 2
and - 1
are - 1
brown - 1
friends - 1
good - 1
jumps - 1
lazy - 1
over - 1
quick - 1
```

# Note:

* The word "the" appears three times and is the most frequent, followed by "fox" and "dog" with a frequency of two.
* The words "and," "are," "brown," "friends," "good," "jumps," "lazy," "over," and "quick" appear once each.