#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

// Huffman Tree Node
struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char c, int f) {
        ch = c;
        freq = f;
        left = right = nullptr;
    }
};

// Custom comparator for min-heap
struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

// Generate Huffman Codes
void generateCodes(Node* root, string code, unordered_map<char, string>& huffmanCodes) {
    if (!root) return;
    if (!root->left && !root->right) huffmanCodes[root->ch] = code;

    generateCodes(root->left, code + "0", huffmanCodes);
    generateCodes(root->right, code + "1", huffmanCodes);
}

// Main Huffman Encoding function
void huffmanEncoding(string text) {
    // Count frequency of characters
    unordered_map<char, int> freq;
    for (char c : text) freq[c]++;

    // Min-heap priority queue
    priority_queue<Node*, vector<Node*>, Compare> pq;
    for (auto& pair : freq) pq.push(new Node(pair.first, pair.second));

    // Build Huffman Tree
    while (pq.size() > 1) {
        Node *left = pq.top(); pq.pop();
        Node *right = pq.top(); pq.pop();
        Node *merged = new Node('\0', left->freq + right->freq);
        merged->left = left;
        merged->right = right;
        pq.push(merged);
    }

    // Generate Huffman Codes
    unordered_map<char, string> huffmanCodes;
    generateCodes(pq.top(), "", huffmanCodes);

    // Display Huffman Codes
    cout << "Huffman Codes:\n";
    for (auto& pair : huffmanCodes) {
        cout << pair.first << " : " << pair.second << endl;
    }
}

// Driver Code
int main() {
    string text = "huffman example";
    huffmanEncoding(text);
    return 0;
}