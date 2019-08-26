#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main() {

    int n;
    int word_number;
    vector<string> datas;
    map<string, int> results;
    string input_line;

    cin >> n;

    for (int i = 0; i < n; i++) {
        fflush(stdin);  //FLUSHING STDIN
        getline(cin, input_line);

        stringstream sep(input_line);
        string word;

        datas.clear();
        word_number=0;
        while (getline(sep, word, ' ')) {
            if ( word.length() >= 1 ) {
                datas.push_back(word);

                word_number++;
                if( word_number == 1) {
                    auto it = results.find(word);
                    if (it != results.end())
                        results[word]++;
                    else
                        results.insert({word, 1});
                }
            }
        }
    }

    for (auto itr = results.begin(); itr != results.end(); ++itr) {
        cout << itr->first <<" "<<itr->second<<endl;
    }
    cout << endl;

    return EXIT_SUCCESS;
}