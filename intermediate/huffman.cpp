#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

// Node structure for Huffman Tree
struct Node {
    char ch;
    int freq;
    Node *left, *right;
    
    Node(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
};

// Comparator for priority queue
struct Compare {
    bool operator()(Node* l, Node* r) {
        return l->freq > r->freq;
    }
};

// Function to generate Huffman Codes
void generateCodes(Node* root, string code, unordered_map<char, string>& huffmanCode) {
    if (!root)
        return;
    if (!root->left && !root->right)
        huffmanCode[root->ch] = code;
    generateCodes(root->left, code + "0", huffmanCode);
    generateCodes(root->right, code + "1", huffmanCode);
}

// Huffman Encoding Function
void huffmanEncoding(const string& text) {
    // Count frequency of characters
    unordered_map<char, int> freq;
    for (char ch : text)
        freq[ch]++;
    
    // Min-Heap priority queue
    priority_queue<Node*, vector<Node*>, Compare> pq;
    for (auto pair : freq)
        pq.push(new Node(pair.first, pair.second));
    
    // Build Huffman Tree
    while (pq.size() > 1) {
        Node *left = pq.top(); pq.pop();
        Node *right = pq.top(); pq.pop();
        Node *newNode = new Node('\0', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;
        pq.push(newNode);
    }
    
    Node* root = pq.top();
    unordered_map<char, string> huffmanCode;
    generateCodes(root, "", huffmanCode);
    
    // Print Huffman Codes
    cout << "Huffman Codes:\n";
    for (auto pair : huffmanCode)
        cout << pair.first << " : " << pair.second << endl;
    
    // Encode text
    string encodedText = "";
    for (char ch : text)
        encodedText += huffmanCode[ch];
    
    cout << "Encoded Text: " << encodedText << endl;
}

int main() {
    string text = "huffman encoding example";
    huffmanEncoding(text);
    return 0;
}
