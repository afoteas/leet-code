class Solution {
public:
    string makeLargestSpecial(string s) {
        if (s == "") return s;
        vector<string> ans;
        int cnt = 0;
        for (int i = 0, j = 0; i < s.size(); ++i) {
            cnt += s[i] == '1' ? 1 : -1;
            if (cnt == 0) {
                ans.push_back("1" + makeLargestSpecial(s.substr(j + 1, i - j - 1)) + "0");
                j = i + 1;
            }
        }
        sort(ans.begin(), ans.end(), greater<string>{});
        return accumulate(ans.begin(), ans.end(), ""s);
    }


    string makeLargestSpecialWhatever(string s) {
        if (s.size() < 6) return s;
        int f_index = 0;
        int f_size = 2;
        int s_index = 0;
        int s_size=0;
        bool first = false;
        bool second = false;
        int previous = 0, current = 1;
        char c_val = '0';
        for(int i = 1; i < s.size(); ++i){
            if(!first && s[i] == '0') {
                f_index = i-1;
                first = true;
            } else {
                if(s[i] == s[i-1]) {
                    current++;
                }
                else {
                    c_val=s[i];
                    if (c_val == '1') {
                        // current is the size of zeros
                        // previous is the size of ones
                        last_check:
                        int tmp_size = min(previous,current);
                        if (tmp_size > 1 && tmp_size<<1 >= s_size) {
                            second = true;
                            s_size = tmp_size<<1;
                            if(previous>current) {
                                cout<< "entered1"<<endl;
                                s_index=i - (current<<1)+1;
                            } else {
                                cout<< "entered2"<<endl;
                                cout<< "i:"<<i<<endl;
                                cout<< "current:"<<current<<endl;
                                cout<< "previous:"<<previous<<endl;
                                s_index=i - (current-previous) - (previous<<1) + 1;
                            }
                        }
                        if (i == s.size()-1) break;
                    }
                    previous = current;
                    current = 1;
                }
            }
            if (i == s.size()-1) goto last_check;
        }
        cout << "f_index:" << f_index <<", s_index:" <<s_index <<endl;
        cout << "f_size:" << f_size <<", s_size:" <<s_size <<endl;
        if(second) {
            s.erase(s_index+1,s_size-2);
            s.insert(f_index+1,(s_size>>1)-1,'0');
            s.insert(f_index+1,(s_size>>1)-1,'1');
        }

        return s;
    }
};