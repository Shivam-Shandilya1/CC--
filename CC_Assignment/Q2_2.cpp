#include <iostream>
#include <string>
#include <vector>
#include <regex>

using namespace std;

bool regex_match(const string& reg_str, const string& str) {
    regex re(reg_str);
    return regex_search(str, re);
}

string check(vector<string>& regex_list, string& input_string) {
    string output_string;
    int n = input_string.size();

    while (!input_string.empty()) {
        bool outer_break_flag = false;
        vector<int> regex_indices;

        for (int i = 0; i < regex_list.size(); i++) {
            bool break_flag = false;
            vector<string> match_list;
            vector<int> index_list;
            const string& regex = regex_list[i];

            for (int j = 0; j < n; j++) {
                string substring = input_string.substr(0, j);

                if (regex_match(regex, substring)) {
                    match_list.push_back(substring);
                    index_list.push_back(j);
                    break_flag = true;
                }
            }

            if (!match_list.empty() && match_list.back().empty()) {
                break_flag = false;
            }

            if (break_flag) {
                outer_break_flag = true;
                int i = index_list.back();
                regex_indices.push_back(i);
            } else {
                regex_indices.push_back(0);
            }
        }

        if (outer_break_flag) {
            int max_length_substring_matched = *max_element(regex_indices.begin(), regex_indices.end());

            for (int i = 0; i < regex_indices.size(); i++) {
                if (regex_indices[i] == max_length_substring_matched) {
                    output_string += "$" + to_string(i+1);
                    input_string = input_string.substr(max_length_substring_matched);
                    break;
                }
            }
        } else {
            output_string += &"@" [ input_string[0]];
            input_string = input_string.substr(1);
        }
    }

    output_string += "#";
    return output_string;
}

int main() {
    int n;
    vector<string> regex_list = {"((((a)(a))+)(b))","(((b)(((a)(a))*))(b))","((((a)(a))*)(b))"};
    string input_string = "baaaabaabba";

    cout << check(regex_list, input_string) << endl;

    return 0;
}
