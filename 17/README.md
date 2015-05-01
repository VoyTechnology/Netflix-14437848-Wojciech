# Primes #

### Compliation ###
`make`

### Usage ###

`./anagram <dictionary file> [word]`

### Test Data ###
For convenience of testing I am also supplying the dictionary data from http://www.computing.dcu.ie/~john/dict.txt  
It is placed in a file called `dict.txt`

```
> ./anagram
Usage: ./anagram <dictionary file> [word]
```

```
> ./anagram dict.txt
Please enter your word: cat
	act
	cat
```

```
> ./anagram dict.txt cat
	act
	cat
```
### Cleaning ###
`make clean` would remove the compiled binary
