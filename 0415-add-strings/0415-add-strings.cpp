class Solution {
public:
    string addStrings(string num1, string num2) {
        int a=stoi(num1);
        int b=stoi(num2);
        int c=a+b;

        return to_string(c);
    }
};