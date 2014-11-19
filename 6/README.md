# Bracket Matching #

### Compilation ##
`make`

### Usage ###
`./bracketmatching <input file>`

### Test data ###
Included in the test folder
`./bracketmatching test/<test>`  
> Sample: `./bracketmatching test/2`

__1__: () `Yes`  
__2__: ()) `No`  
__3__: (2+2)\*8 `Yes`  
__4__: (2+2)\*8) `No`  
__5__: (2+4)\*8(4) `Yes`  
__6__: (((((())((()))(())))))(()) `Yes`



### Cleaning ###
`make clean`
