
/*
\marginnote{
\begin{itemize}
\item \textbf{Description :}\\
class buildHuffmanTree implements the Huffman encoding
algorithm. It will create a Huffman tree with its tree()
method which can be traversed to get the
binary codes for each character.
\item \textbf{Data Members :}\\
\item \textbf{Data Members :}\\
\begin{enumerate}
\item bh :-\\
bh is an object of class MeldableHeap 
and type thats passed in when creating
bh is HNode.
\item *r :-
pointer r of HNOde type is to store
the root of bh once its build using the
tree() method.
\item s :-
s is the string which will be parsed to obtain 
the characters which will futher be converted 
to binary codes.
\end{enumerate}
\item \textbf{Constructor :}\\
The constructor of this class will initialize the
s data member with the passed string.
\item \textbf{tree() method :}\\
\item \textbf{printCodes() method :}\\
\item \textbf{isLeaf() methor :}\\
\item \textbf{printArr() methor :}\\
\end{itemize}
}
*/
#include "MeldableHeap.hpp"
#include "HNode.h"
#include <map>
#include <string>
template<typename T>
class buildHuffmanTree
{
public:
MeldableHeap <HNode<T>> bh;
HNode<T>* r;
std::string s;
    
buildHuffmanTree(std::string str){
    s = str;
}
/*
\vspace{400px}\clearpage
\marginnote{
\begin{itemize}
\item \textbf{tree() method :}\\
\begin{enumerate}
\item Step 1 :- In the tree method we first create a map m 
to map the character with its frequency using 
a for loop. 
\item Step 2 :-In the second for loop  
we display the character and its frequency
and create a HNode pointer to store the char
and frequency. 
\item Step 3 :-Then we add that to the tree
which will implement the priority queue
and keep the characters with lowest frequency
on the top.
\item Step 4 :- Then in a while loop 
we remove two nodes from the tree and store them 
in n1 and n2. Then we create another node with the 
accumlated weight of n1 and n2 and add it back to the
tree. Also we set the left and right childs of h to 
n1 and n2 respectively. 
\item Step 5 :- Once we are done with the while 
loop we return the tree.
\end{enumerate}

\end{itemize}
}
*/
MeldableHeap <HNode<T>> tree() {
std::map<char, int> m;
for(auto e : s) m[e]++;
for(auto e : m) {
std::cout<<e.first <<" "<<e.second;
std::cout<<std::endl;
HNode<T>*n = new HNode<T>(e.first,e.second);
bh.add(*n);
}
while(bh.n > 1) {
	HNode<T>* n1 = new HNode<T>();
    *n1 = bh.remove();
    HNode<T>* n2 = new HNode<T>();
    *n2 = bh.remove();
    HNode<T>* h = new HNode<T>
    ('*', n1->weight+n2->weight);
    r = h;
    n1->parent = h;
    n2->parent = h;
    h->left = n1;
    h->right = n2;
    bh.add(*h);
}
return bh;
}
/*
\vspace{400px}\clearpage
\marginnote{
\begin{itemize}
\item \textbf{printCodes() method :}\\
It prints huffman codes from the root of Huffman Tree. 
It uses arr[] to store codes and top is the length of 
the code which increases with every recursive call to
printCodes().
\item In the first if statement we 
assign 0 to left edge and recur 
\item In the seconde if statement we 
assign 1 to right edge and recur 
\item In the third if statement if this it
hits a leaf node, then 
it contains one of the input 
characters, print the character 
and its code from arr[] 
\item This function is to display the binary
code for each character and it returns nothing
\end{itemize}
}
*/

void printCodes
(HNode<T> * root, int arr[], int top){ 
  
if (root->left) { 	
    arr[top] = 0; 
    printCodes(root->left, arr, top + 1); 
} 
if (root->right) { 
    arr[top] = 1; 
    printCodes(root->right, arr, top + 1); 
}  
if (isLeaf(root)) { 
	std::cout << root->x.x << " :" ;
    printArr(arr, top); 
} 
  
} 
/*
\vspace{400px}\clearpage
\marginnote{
\begin{itemize}
\item \textbf{isLeaf() methor :}\\
It is a utility function to check if this node is leaf.

It will return 0 if the passed node in not a leaf and
1 if it is.
\end{itemize}
}
*/

int isLeaf(HNode<T> * root){  
   return !(root->left) && !(root->right); 
} 
/*
\vspace{400px}\clearpage
\marginnote{
\begin{itemize}
\item \textbf{printArr() methor :}\\
It is a utility function to print an array of size n 
\end{itemize}
}
*/
void printArr(int arr[], int n){ 
    int i;  std::string bits;
    for (i = 0; i < n; ++i){
        std::cout<< arr[i];
         bits += arr[i];
     }
    std::cout<<"\n"; 
} 

};

