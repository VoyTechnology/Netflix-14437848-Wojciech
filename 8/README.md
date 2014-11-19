# Simple Language Model

### Compilation ###
`make`

### Usage ###
`./simpleLanguageModel [<language corpus>]`  
The language corpus is optional. If left blank, the program will default to _Gone_ by _Michael Grant_. This is contained in the _corpus.txt_ file

### Test data ###
The test data is available in the `test` directory

| Number | Content             | Sample input | Probability |
| ------ | -------------       | ------------ | ----------- |
| 1      | Cat                 | Cat          | 1           |
| 2      | This is a cat       | This cat     | 0.625       |
| 3      | I love cats. Domestic cats are the best cats | cats | 0.3333 |



### Cleaning ###
`make clean`
