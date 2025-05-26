string highestValuePalindrome(string s, int n, int k) {
      int changes_needed = 0;
    vector<bool> changed(n, false);
    
    
    for (int i = 0; i < n / 2; ++i) {
        if (s[i] != s[n - 1 - i]) {
            changes_needed++;
        }
    }
    
    if (changes_needed > k) {
        return "-1";
    }
    
    int extra_changes = k - changes_needed;
    
    for (int i = 0; i < n / 2; ++i) {
        int j = n - 1 - i;
        if (s[i] != s[j]) {
           
            if (extra_changes > 0) {
              
                if (max(s[i], s[j]) != '9') {
                    s[i] = '9';
                    s[j] = '9';
                    extra_changes--;
                } else {
                   
                    if (s[i] > s[j]) {
                        s[j] = s[i];
                    } else {
                        s[i] = s[j];
                    }
                }
            } else {
             
                if (s[i] > s[j]) {
                    s[j] = s[i];
                } else {
                    s[i] = s[j];
                }
            }
            changes_needed--;
        } else {
            
            if (extra_changes >= 2 && s[i] != '9') {
                s[i] = '9';
                s[j] = '9';
                extra_changes -= 2;
            }
        }
    }
    
   
    if (n % 2 == 1 && extra_changes > 0) {
        s[n / 2] = '9';
    }
    
    return s;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);

    string s;
    getline(cin, s);

    string result = highestValuePalindrome(s, n, k);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
