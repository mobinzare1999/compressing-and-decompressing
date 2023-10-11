# compressing-and-decompressing
A text file (for example: source.txt) contains a text with unknown number of lines. Assume
that the file DOES NOT contain the character ‘$’.
The aim of the program is to compress the file, by replacing any sequence of repeated characters
(with a minimum of 2 and a maximum of 9 repetitions) with the following triplet of characters:
<repeated character>$<number of repetitions>.
NB: the number of repetitions should not consider the first occurrence of the character: for
example, AA contains 1 repetition, BBB contains 2 repetitions, etc. In case a character is repeated
more than 9 times, the sequence should be broken into multiple sub-sequences. For example:
- “AAAAAAAAAAAAA” should be encoded as “A$9A$2”
- “the number 1000000 is large” should be encoded as “the number 10$5 is large”
- “there are 15 repeated = : =============== and 4 dots….” should be encoded as “there
are 15 repeated = : =$9=$4 and 4 dots.$3”
The compressed text should be stored in a second file (for example: compressed.txt).
Example:
If input file source.txt is:
Partenza Destinazione Costo
Parigi New York 1000
Roma Londra 700
Sidney Los Angeles 2222
The file compressed.txt should be:
Partenza $5Destinazione $3Costo
Parigi $9New York $410$2
$4Roma $9 Londra $5700
$2Sidney $6Los Angeles $42$3
Write two different functions, respectively able to perform the compression (from original to
compressed encoding) and the decompression (reverse operation: from compressed to original
encoding). The prototypes of the two functions should be
int compressing(FILE *fin, FILE *fout);
int decompressing(FILE *fin, FILE *fout);
In case of error, the functions should return 0. In case of successful operation, they should return
the number of characters that were printed on the output file.
