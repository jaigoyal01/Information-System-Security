#include <bits/stdc++.h>
using namespace std;
void prpmap(map<string, int> mp, string fname, vector<string> user)
{
    ifstream fin;
    fin.open(fname.c_str());
    string word;
    while (fin >> word)
    {
        mp[word]++;
    }
    fin.close();
    map<int, int> letters;
    for (int i = 0; i < 26; i++)
        letters[i] = 0;

    auto it = user.begin();
    while (it != user.end())
    {
        int len = (*it).length();
        auto it2 = mp.begin();
        int fre = -888;
        string w, s = *it;
        while (it2 != mp.end())
        {
            if ((it2->first).length() == len)
            {
                if (it2->second > fre)
                {
                    fre = it2->second;
                    w = it2->first;
                }
            }
            it2++;
        }
        for (int j = 0; j < len; j++)
        {
            if (letters[w[j] - 'a'] == 0)
                letters[w[j] - 'a'] = s[j] - 'a' + 1;
        }
        it++;
    }

    fin.open(fname.c_str());
    string output = "";
    while (fin >> word)
    {
        for (int j = 0; j < word.length(); j++)
        {
            if (letters[word[j] - 'a'] != 0)
                output += ('a' + letters[word[j] - 'a'] - 1);
            else
                output += word[j];
        }
        output += " ";
    }
    cout << output << endl;
}

int main()
{
    // cout << "Enter input file name\n";
    string fname = "input.txt";
    // cin >> fname;
    map<string, int> mp;

    vector<string> user;
    cout << "How many words\n";
    int num;
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        string t;
        cin >> t;
        user.push_back(t);
    }
    prpmap(mp, fname, user);
}