class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.length(), i = 0, j = 0;
        int maxV = 0, count = 0;

        // Edge case 
        if(k > n )
        return 0;

        auto isVowel = [&](char ch){
            return ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u';
        };

        while (j < n) {
            // 1) Always include s[j] in the window
            if (isVowel(s[j])) 
                count++;

            // 2) Once window size reaches k, record & slide
            if (j - i + 1 == k) {
                maxV = max(maxV, count);
                if (isVowel(s[i])) 
                    count--;
                i++;
            }

            // 3) Crucial: always advance j
            j++;
        }

        return maxV;
    }
};