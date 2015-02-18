# Feedback (Wojciech Bednarzak)

## RSA

* Your code works - **very good**.
* ```make``` works.
* I don't think it is good practice for ```make clean``` to remove the executable file; see comments on problem ```1```.
* Separate files for public & private keys - **good**.
* You are using ```rand()``` and ```srand(time())```. These are not secure. You need to use a cryptographically secure **PRNG** (pseudorandom number generator). I'd be surprised if **GMP** does not include one.
* I think you could probably make more use of features of **GMP** rather than writing your own code.


#Suggestions

* I like your use of command-line arguments, but they are a bit confused.
	* For example, the arguments for ```generate``` are differnt in the ```README.nmd``` file and the ```usageInstructions()``` function.
	* I'm not sure how to interpret the ```encrypt``` and ```decrypt``` arguments.
* The following minor adjustments might be cleaner:
	1. For ```generate``` use ```generate [key-size [key-file]]```
	2. For ```encrypt``` and ```decrypt``` always assume that the input comes from ```stdin``` and the output goes to ```stdout```.
	3. Then we would have ```encrypt [key-file]``` & ```decrypt [key-file]```.
	4. We could then use Unix piping and redirection, e.g., 
	
	```
	echo "Hello world" | encrypt > ciphertext
	echo "Hello world" | encrypt | decrypt > plaintext
	
	```
  	
