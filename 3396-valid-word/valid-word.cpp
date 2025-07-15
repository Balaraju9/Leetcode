class Solution {
public:
    bool isValid(string word) {
        if (word.size() < 3) return false;
        
        bool hasVowel = false;
        bool hasConsonant = false;
        
        for (char ch : word) {
            if (!isalnum(ch)) {
                return false;
            }
            
            if (isVowel(ch)) {
                hasVowel = true;
            }
            else if (isalpha(ch)) {
                hasConsonant = true;
            }
        }
        
        return hasVowel && hasConsonant;
    }

private:
    bool isVowel(char ch) {
        ch = tolower(ch);
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }
};
