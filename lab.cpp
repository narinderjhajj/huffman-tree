#include <iostream>      
#include <string>
#include "buildHuffmanTree.h"
/*
\marginnote{
\begin{itemize}
\item In the main function we test 
the methods of our buildHuffmanTree class
by creating a as its object and pass the string
s to it.
\item we call the tree method which should print out the 
character and their frequecies and it should 
also set r to the root of tree.
\item Then we call the printCode() method to 
see if the tree build by the tree() method leads to
the right binary code for each character.
\end{itemize}
}
*/
int main (){
	std::string s1 = "ohlone college";
	buildHuffmanTree<HNode<char>> a(s1);
	a.tree();
	int arr[0];
	a.printCodes(a.r,arr,0);
	std::string s2 = "Huffman encoding is an algorithm devised by David A. Huffman";
	buildHuffmanTree<HNode<char>> b(s2);
	b.tree();
	int arr2[0];
	b.printCodes(b.r,arr2,0);
  return 0;
}

