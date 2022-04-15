# TextProcessor

Extensible text processing package.

dropfirst n Drop the first n characters of each word.

doublewords Double up all words in the string.

allcaps All letters in the string are presented in uppercase.

count c The first occurrence of the character c in the string is replaced with 1. The second is replaced with 2, ... the tenth is replaced with 10, and so on.

sample.txt contains Hello World:
input:
sample.txt doublewords dropfirst 2 count l
output:
1 12o
2 34o
3 r5d
4 r6d

input:
sample.txt allcaps
output:
1 HELLO
2 WORLD
