#include <iostream>
#include <map>
#include <vector>

using namespace std;

// Function to calculate cumulative probability intervals
void computeIntervals(map<char, double>& freq, map<char, pair<double, double>>& intervals) {
    double low = 0.0;
    for (auto& pair : freq) {
        intervals[pair.first] = {low, low + pair.second};
        low += pair.second;
    }
}

// Function to perform Arithmetic Encoding
double arithmeticEncode(const string& text, map<char, double>& freq) {
    map<char, pair<double, double>> intervals;
    computeIntervals(freq, intervals);

    double low = 0.0, high = 1.0;
    for (char ch : text) {
        double range = high - low;
        high = low + range * intervals[ch].second;
        low = low + range * intervals[ch].first;
    }
    
    return (low + high) / 2; // Encoded value as a single floating-point number
}

int main() {
    string text = "arithmetic";
    
    // Step 1: Compute character frequencies
    map<char, double> freq;
    for (char ch : text) freq[ch]++;
    for (auto& pair : freq) pair.second /= text.length();

    // Step 2: Encode using Arithmetic Coding
    double encodedValue = arithmeticEncode(text, freq);

    cout << "Encoded Value: " << encodedValue << endl;

    return 0;
}