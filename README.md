# huffman-tree
 
This program illustrate the working of Huffman encoding algorithm which was devised by David A. Huffman of MIT in
1952 for compressing text data to make a file occupy a smaller number of bytes. Normally text data is stored in a standard
format of 8 bits per character using ASCII encoding. It maps every character to a binary integer value from 0-255.
The idea of Huffman encoding is to abandon the 8-bits-percharacter requirement and use different-length binary encodings for different characters. The advantage of doing this is that if a character occurs frequently in the file, such as the
common letter ’e’, it could be given a shorter encoding, making the file smaller. The trade off is that some characters may
need to use encodings t
