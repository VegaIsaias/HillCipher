# HillCipher

## 1. Objective

The objective of this program is to encrypt the alphabetic letter in a file using the Hill Cipher where the Hill matrix can be of any size from 2x2 up to 9x9. The program will take two command line parameters containing the names of the file storing the encryption key and the file to be encrypted. The program will then generate the encrypted text and out to the console screen as specified below.

## 2. Command Line Parameters

* The program will not prompt the user to enter the name of the encrypted key file and the text file. These should be takes as command line parameters.
* The first parameter must be the name of the encrypted key file. The second parameter must be the name of the file to be encrypted. 

## 3. File Formatting

### 3.1 Encryption Key File Format

The	encryption	key	file	will	store	a	single	positive	integer,	n	(1	<	n	<	10),	on	the	first	line,	indicating	
the	 number	 of	 rows	and	 columns	in	 the	encryption	matrix.	The	 following	n lines	will	 contain	 the	
contents	of	each	row,	in	order,	of	the	encryption	matrix,	separated	by	spaces.

#### Sample Key File

```
4
9 12 13 1
7 3 6 9
8 4 2 1
10 5 15 3
```


### 3.2 Format of the File to be Encrypted

The	 file	 to	be	encrypted	can	be	any	valid	 text	 file	with	no	more	 than	9991	letters	in	it.	 (Thus,	it's	
safe	 to	 store	 all	 characters	 in	 the	 file	 in	 a	 character	 array	 of	 size	 10000,	 including	 any	 padding	
characters.) 

Please	 note	 that	 the	 input	 text	 file	 will	 also	 generally	 have	 punctuation,	 numbers,	 special	characters,	and	
whitespace	in	it,	which	should	be	ignored.	You	should	also	ignore	whether	a	 letter	is	uppercase	or	lowercase in	the	input	file. Thus,	you	should	treat	‘A’	and	‘a’	the	same	in	your program.

#### Sample Input File

```
Security professionals have said for years that the only way to make a computer truly secure is for it to not be 
connected to any other computers, a method called airgapping. Then, any attack would have to happen physically,
with the attacker actually entering the room and accessing the computer that way, which is incredibly unlikely. 
In the case of computers containing highly sensitive information, additional, physical security can always be added 
in the form of security guards, cameras, and so on.

Researchers at Georgia Institute of Technology have uncovered a vulnerability in all computers, however, which can be 
exploited regardless of an air gap. It’s a vulnerability which you’d never suspect, and it’s one that’s hard to fight 
against. All CPUs emit electromagnetic signals when they are performing tasks, and the first thing these researchers 
discovered was that binary ones and zeroes emit different levels. The second thing they discovered is that electromagnetic 
radiation is also emitted by the voltage fluctuations and that it can be read from up to six meters away. These signals, 
by the way, are known as side-channels, and they are well-documented in the cryptography field.
```

### 3.3 Output Format

The program must output the following to the console (terminal) screen:

1. Echo the input key file
2. Echo the input plaintext file
3. Cipher text output produced from running the cipher against the input plaintext file.

The	ciphertext output portion should	consist	of	only	lowercase	letters	in	rows	of	exactly	80	letters	per	 row,	
except for	 the	 last	 row,	 which	 may	 possibly	 have	 fewer.	 These	 characters	 should	correspond	to	the	ciphertext 
produced	by encrypting	all	the	letters	in	the	input	file. Please	note	that	only	the	alphabetic	letters	in	the	input	plaintext	file	will	be	encrypted.	All	other	characters	should	be	ignored.

#### Sample Output

```
wsceafwvgznsacsihctehylsayiyanlevvrznraqaimmhdcajbjnuqowykyivehgkiztslktzvtlhxbb
lehmcpoddwkbnrmwpszcognnoxhsujopvehggfgfunbegpydafnalyubtzumbaryxctoolpkueyssrjy
cdyhojobqftmdqgbdfftfpcmptrlqblscygqqqdxwtlikntstkzynvmmvpysnfggiyyorwarxoifrocr
rcncuxmfjhrdnuqlnmwfonkzfaqrzcsxurclysqewceqsrudvehgixiljruwhapsojuzfyktsnyjyhwl
vrkceovbtuqheptotuqheqeyygyqfrognudutffdcjkvhektblwuzixkijszqyjnwsceafwvzvpdjjwu
nqqfwxruffhfxpkedwbggfgfxpqkrduinkpehormclniilpmejihjohafckdfanspsnorbauspqbypan
fmxwfpgccdibgdcrdqevwnmtyvwhdyqzyiusrivktliuywsytxpbihilgmtlonudnaxuhkxypwnahkql
mtcpzdugihctxighzgbyyjitpujkqnitbwpwwrsvvvkqpzzllwxwapqpkwkocnmxnnkwrdrpgvwblrtl
ybybnynehxqikxelwhtopgejztqwwxruaplojwfyihbunvmmtqqztfvrperkihifvkobcjypcxngpfie
ytgpolihmwfdkrcjkwkoebdcgdqzyqymixqhncybvbdnqksubaryhimvzptvjahmwbzifyrgmprwqgkk
edkrrojkpigzojqpqhqdrxlrzqtytrakzkfizjlbuijltoypwlshrrfjnqhmgxrkgzedkeooqpribrpd
rmyvbhwowplkkiakbwktopebrmcntrjpbcipirmbpwerlwfqotefguzlhxqixnsmyuwscauakrjiomfj
tounfowfrmrauhyhppnt
```

## 4. Compilation and Execution

To compile:
```
gcc -o HillCipher.c
```

To run:
```
./hillcipher keyfile.txt plainText.txt
```


