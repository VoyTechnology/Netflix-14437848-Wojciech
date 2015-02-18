# Feedback (Wojciech Bednarzak)

## Primes

* Your program works - **good**.
* Your program works when ```N``` is a prime, i.e., ```N``` is not output - **good**.
* Your program considers ```1``` to be a prime; it is **not**.
* ```make``` works.
	* I don't think it is good practice for ```make clean``` to remove the executable file.
	* ```make clean``` is normally used to remove temporary files (e.g., ```.o``` files ) created during the make.
* Good ```README.md``` file.
* Using the file ```output.txt`` does not lead to a good user experience.
	* Outputting directly to the terminal would give a better user experience.
	* The output can be **redirected** if a file is required, e.g., ```primes 23 > output.txt```
	* If you really want to output information about the number of primes you could output it to ```stderr```.

## Suggestions

* The Sieve of Eratosthenes is an alternative algorithm that is worth exploring.

