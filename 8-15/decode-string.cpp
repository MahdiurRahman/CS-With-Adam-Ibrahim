class Solution {
public:
    int findNumber(string &code, int &index) {
        string number = "";
        while ((code[index] >= '0') and (code[index] <= '9')) {
            number += code[index];
            index++;
        }
        return stoi(number);
    }
    
    string helper(int num, string &code, int &index) {
        string answer = "";
        while ((code[index] != ']') and (index < code.length())) {
            if (code[index] == '[') {
                //cout << 1 << endl;
                index++;
            }
            else if ((code[index] > '0') and (code[index] <= '9')) {
                //cout << 2 << endl;
                int num_ = findNumber(code, index);
                string repeat = helper(num_, code, index);
                for (int i = 0; i < num_; i++) {
                    answer += repeat;
                    cout << answer << endl;
                }
            }
            else {
                //cout << 3 << endl;
                answer += code[index];
                cout << answer << endl;
                index++;
            }
        }
        index++;
        return answer;
    }
    
    string decodeString(string s) {
        int index = 0;
        string answer = "";
        while (index < s.length()) {
            answer += helper(1, s, index);
            index++;
        }
        return answer;
    }
};
