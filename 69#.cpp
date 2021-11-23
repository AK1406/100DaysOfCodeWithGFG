/*
Trie is an efficient information retrieval data structure. Use this data structure to store Strings and search strings. Your task is to use TRIE data structure and search the given string A. If found print 1 else 0.

Example 1:

Input:
N = 8
key[] = {the,a,there,answer,any,by,
         bye,their}
search = the
Output: 1
Explanation: the is present in the given
string "the a there answer any by bye
their"
Example 2:

Input:
N = 8
key[] = {the,a,there,answer,any,by,
         bye,their}
search = geeks
Output: 0
Explanation: geeks is not present in the
given string "the a there answer any by
bye their"
Your Task:
Complete insert and search function and return true if key is present in the formed trie else false in the search function. (In case of true, 1 is printed and false, 0 is printed by the driver's code.

Expected Time Complexity: O(M+|search|).
Expected Auxiliary Space: O(M).
M = sum of the length of all strings which is present in the key[] 

|search| denotes the length of the string search.

*/

//Function to insert string into TRIE.
void insert(struct TrieNode *root, string key)
{
    // code here
    int n = key.size();
    for(int i=0; i<n; i++){
        if(root->children[key[i]-'a'] == nullptr){
            root->children[key[i]-'a'] = getNode();
            root = root->children[key[i]-'a'];
        }
        else{
            root = root->children[key[i]-'a'];
        }
    }
    root->isLeaf = true;
}

//Function to use TRIE data structure and search the given string.
bool search(struct TrieNode *root, string key) 
{
    // code here
    int n = key.size();
    for(int i=0; i<n; i++){
        if(root->children[key[i]-'a'] == nullptr){
            return false;
        }
        else{
            root = root->children[key[i]-'a'];
        }
    }
    return (root->isLeaf);
}
