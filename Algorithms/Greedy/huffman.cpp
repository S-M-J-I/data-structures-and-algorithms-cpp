#include<bits/stdc++.h>
#define fastio ios::sync_with_stdio(); cin.tie(0); cout.tie(0);


using namespace std;

/** Huffman node */
struct HuffmanNode {
    char data;
    int freq;
    struct HuffmanNode *left, *right;
    HuffmanNode(char data, int freq) {
        this->data = data;
        this->freq = freq;
        left = right = NULL;
    }
};

// compare operator
struct compare {
    bool operator()(const HuffmanNode *left, const HuffmanNode *right){
        return left->freq > right->freq;
    }
};

// code printing
void printCodes(const HuffmanNode *root, string str) {

    // if there is no root
    if(!root) {
        return;
    }
    
    // if root does not have the special character, we print the data in that node
    if(root->data != '$') {
        cout << root->data << ": " << str << "\n";
    }

    // else keep traversing left and right to find a data or exit statement
    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}


// huffman coding
void HuffmanEncoding(const char data[], const int freq[], int size) {
    
    // create a left right and root node
    HuffmanNode *left, *right, *root;

    // create a min heap
    priority_queue<HuffmanNode*, vector<HuffmanNode*>, compare> minHeap;

    // initialize the minHeap by creating nodes from the data
    for(int i = 0 ; i < size; ++i) {
        minHeap.push(new HuffmanNode(data[i], freq[i]));
    }

    // while heap is not empty
    while(!minHeap.empty()) {

        // take the most minimum value as left
        left = minHeap.top();
        minHeap.pop();

        // same for right
        right = minHeap.top();
        minHeap.pop();

        // create their rrot node with the special character and the frequency is their sum
        root = new HuffmanNode('$', left->freq + right->freq);

        // assign the root left to left
        root->left = left;
        // same for right
        root->right = right;

        // push the root to the minHeap
        minHeap.push(root);
    }

    // print the heap from the most minimum root;
    printCodes(minHeap.top(), "");

}


int main() {

    fastio;

    char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i'};
    int freq[] = { 40, 10, 18, 20, 17, 25, 24, 35, 21 };
  
    int size = sizeof(arr) / sizeof(arr[0]);
  
    HuffmanEncoding(arr, freq, size);
}