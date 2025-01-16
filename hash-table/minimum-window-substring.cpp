class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) return "";

        unordered_map<char, int> count;  // Map to store frequency of characters in t
        for (auto c : t) count[c]++;  // Initialize count map with characters from t

        int required = count.size();  // Number of unique characters in t
        int formed = 0;  // Number of unique characters in current window that match the required frequency
        unordered_map<char, int> windowCount;  // Map to store character counts in the current window

        int left = 0, right = 0;  // Sliding window pointers
        int minLength = INT_MAX;  // Length of the minimum window
        int start = 0;  // Starting index of the minimum window

        // Start sliding the right pointer
        while (right < s.length()) {
            char c = s[right];
            windowCount[c]++;  // Increment the count of the character at right pointer

            // If the current character's frequency matches the required frequency, increment formed
            if (count.find(c) != count.end() && windowCount[c] == count[c]) {
                formed++;
            }

            // Once all characters in t are matched, try to shrink the window from the left
            while (left <= right && formed == required) {
                c = s[left];

                // Update the result if the current window is smaller than the previous one
                if (right - left + 1 < minLength) {
                    minLength = right - left + 1;
                    start = left;
                }

                windowCount[c]--;  // Decrease the count of the character at the left pointer
                if (count.find(c) != count.end() && windowCount[c] < count[c]) {
                    formed--;  // If the character's count no longer matches the required frequency, decrease formed
                }

                left++;  // Move the left pointer to shrink the window
            }

            right++;  // Move the right pointer to expand the window
        }

        // If no valid window was found, return an empty string
        if (minLength == INT_MAX) return "";

        return s.substr(start, minLength);  // Return the smallest valid window
    }
};