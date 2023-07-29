/*
\marginnote{
\begin{itemize}
\item \textbf{Description :}\\
Structure HNode is to store the char and its frequency. 
While building the tree we will store this HNode 
inside Meldable Class Node
\item \textbf{Data Members :}\\
\begin{enumerate}
\item x :-\\
To store the character
\item weight :- \\
To store the frequency of the character
\item *left :- \\
HNode pointer to store left child
\item *right :- \\
HNode pointer to store right child
\item *parent :- \\
HNode pointer to store parent of the HNode
\end{enumerate}
\item \textbf{Constructor :}\\
The constructor of this struct will initialize 
x with the passed parameter and by default x 
will be a space. weight will be initialize to
the passed integer.
Left, right and parent will be set to a nullptr.
\item \textbf{Overloaded Operator > :}\\
greater than operator is overloaded so when creating the 
priority queue, two HNodes can be compared by their 
weight.
\end{itemize}
}
*/
#pragma once
template<typename T>
struct HNode{
T x;
int weight; 
HNode *left;
HNode *right;
HNode *parent;
	
HNode(T u = ' ', int w = 0){
	x = u;
	weight = w;
	left = right = parent = nullptr;
}
bool operator>(const HNode& n)
{return weight > n.weight; }
};
