#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/**
 * In implementation of DNSReversLook_up we can easily use hashmap.
 * Here  a Trie based solution is discuessed. With Trie we can implement prefix search(like finding all urls for a common prefix of IP address)
 * The general disadvantage of Trie is large amount of memory requirement, but here since the size of IP address is fixed.Thus it's not a problem here
 * 
 */
#define CHARS 11


int getIndex(char c){
	return c == '.'?0:c-'0'+1;
}

char getCharFromIndex(int i){
	return i==0?'.':i-1+'0';
}
typedef struct trieNode{
	bool isLeaf;
	char * URL;
	struct trieNode * childs[CHARS];
}TrieNode;

/**
 * This method insert the ip address and corresponding domain name into the trie . The last node will be the leaf 
 * and contains the domain name
 * @param root   root to trie tree
 * @param ipAddr Ip address 
 * @param URL    domain name
 */

TrieNode * createNewNode(){
	TrieNode * newNode = (TrieNode *)malloc(sizeof(TrieNode));
	newNode->isLeaf = false; 
	newNode->URL = NULL;
	for(int i = 0;i < CHARS; i++){
		newNode->childs[i] = NULL;
	}
	return newNode;
}
void insert(TrieNode *root, char *ipAddr, char *URL){
	TrieNode * cur = root;
	int len = strlen(ipAddr);
	for(int level = 0; level < len; level++){
		int index = getIndex(ipAddr[level]);
		if(cur->childs[index] == NULL){
			cur->childs[index] = createNewNode();
		}
		cur = cur->childs[index];
	}
	cur->isLeaf = true;
	cur->URL = (char *)malloc(sizeof(URL)+1);// 1 is used for '\0'
	strcpy(cur->URL,URL);
	return;
}

char * lookupDNS(TrieNode * root, char *ipAddr){
	TrieNode *cur= root;
	int len = strlen(ipAddr);
	for(int level = 0;level < len; level++){
		int index = getIndex(ipAddr[level]);
		if(cur->childs[index] == NULL){
			return NULL;
		}
		cur = cur->childs[index];
	}
	if(cur ->isLeaf){
		return cur->URL;
	}
	return NULL;
}
int main(){
    char ipAdd[][50] = {"107.108.11.123", "107.109.123.255",
                         "74.125.200.106"};
    char URL[][50] = {"www.samsung.com", "www.samsung.net",
                      "www.google.in"};
    int n = sizeof(ipAdd)/sizeof(ipAdd[0]);
    TrieNode *root = createNewNode();
 
    // Inserts all the ip address and their corresponding
    // domain name after ip address validation.
    for (int i=0; i<n; i++)
        insert(root,ipAdd[i],URL[i]);
 
    // If reverse DNS look up succeeds print the domain
    // name along with DNS resolved.
    char ip[] = "107.109.123.255";
    char *res_url = lookupDNS(root, ip);
    if (res_url != NULL)
        printf("Reverse DNS look up resolved in cache:\n%s --> %s\n",
                ip, res_url);
    else
        printf("Reverse DNS look up not resolved in cache \n");
    char ip1[] = "107.108.11.1223";
    res_url = lookupDNS(root, ip1);
    if (res_url != NULL)
        printf("Reverse DNS look up resolved in cache:\n%s --> %s\n",
                ip, res_url);
    else
        printf("Reverse DNS look up not resolved in cache \n");
    return 0;
}