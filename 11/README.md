# RSA #

### Compliation ###
Make sure to install GNU GMP.  
Ubuntu: `sudo apt-get install libgmp3-dev`

Run
`make`

### Usage ###
```
usage: ./rsa
	[generate <output_file> [key_size] ]
	[encrypt <key.pub> <message|pipe> ]
	[decrypt <key.pri> <message|pipe> ]
```

#### Generate Keys ####
`./rsa generate key` (Default key size: `2048`)
```
RSA SelfTesting: Success
Public key in key.pub
Private key in key.pri

```

#### Encrypt Message ####
`./rsa encrypt key.pub Hello`
```
91017...4896089407
```

#### Decrypt Message ####
`./rsa decrypt key.pri 91017...4896089407`
```
Hello
```

#### Quicktest ####
Using Pipe as input for decrypt  
`./rsa encrypt key.pub hello | ./rsa decrypt key.pri`
```
hello
```

---

### Cleaning ###
`make clean`
