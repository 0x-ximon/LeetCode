#include <string>
using namespace std;

class Solution {
   public:
    // Algorithm Analysis
    //      Time Complexity:     Ο(m|n) Ω(m|n)  Θ(m|n)
    //      Space Complexity:    Ο(1)   Ω(1)    Θ(1)
    string addBinary(string a, string b) {
        string result = "";
        int c = 0;  // Holds the Current Carry
        int d = 0;  // Holds the Current Digit

        int p = a.size() - 1;  // Pointer for string A
        int q = b.size() - 1;  // Pointer for string B

        // Iterate through both strings from end to beginning
        while (p >= 0 || q >= 0) {
            int sum = 0;
            sum += c;

            // Compute sum for current character.
            if (p >= 0) {
                sum += a[p] - '0';
                p--;
            }

            if (q >= 0) {
                sum += b[q] - '0';
                q--;
            }

            // Compute digit and carry depending on sum.
            if (sum < 2) {
                d = sum;
                c = 0;
            } else {
                d = sum % 2;
                c = 1;
            }

            // Save the result to the beginning of the string.
            result = to_string(d) + result;
        }

        // Edge case for when result.size() is greater than max(p, q).
        if (c == 1)
            result = to_string(1) + result;

        return result;
    };
};
