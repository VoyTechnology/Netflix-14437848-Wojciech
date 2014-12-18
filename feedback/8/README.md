## Feedback ##

### Merits ###
* Compiles without problems
* Good test cases
* Good instructions
* Clear, well commented code
* Case-insensitive
* Reference corpus filename isn't hard-coded.
* Well done for attempting to handle words that are not in the reference corpus (i.e. language model smoothing) but the probability that is usually assigned to these so-called *unseen* words is lower than those that appear in the reference corpus.


### Demerits ###
* Although your code is clear, you could have broken it into more functions, with less code in *main*. For example, one function could handle the processing of the reference (training) corpus and another function could handle the computation of the probabilities of the words in the input sentence.
* The removal of everything but letters in the *lower* function is overkill. In reality, for example, digits 
would not be removed.
* Include a comment at the top of each function and at the top of the class.
* You could also have computed the total number of words when you are first iterating through the words, i.e. in the first while loop in *main*.

### To Think About ###
* What will happen to the probabilities as you move to large corpora and/or longer input sentences?