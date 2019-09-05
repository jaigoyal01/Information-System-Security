#include <bits/stdc++.h>
using namespace std;
string encrypt(string text)
{
    string st = "qwertyuiopasdfghjklzxcvbnm";
    int tlen = text.length();
    string left, mid, right, st2;
    left = "qazwsxedcrfvtgbyhnujmikolp";
    mid = "zxcvbnmasdfghjklqwertyuiop";
    right = "asdfghjklqzwxecrvtbynumiop";
    st2 = "pqowieurytlaksjdhfgmznxbcv";
    // cout << left.length() << " " << mid.length() << " " << right.length();
    vector<char> l, m, r;
    for (int i = 0; i < left.length(); i++)
        l.push_back(left[i]);

    for (int i = 0; i < mid.length(); i++)
        m.push_back(mid[i]);

    for (int i = 0; i < right.length(); i++)
        r.push_back(right[i]);

    for (int i = 0; i < tlen; i++)
    {
        char c = st[text[i] - 'a'];
        char d = l[c - 'a'];
        char e = m[d - 'a'];
        char f = r[e - 'a'];
        char g = st2[f - 'a'];

        //traversing back
        vector<char>::iterator it;
        int dis;
        dis = distance(r.begin(), find(r.begin(), r.end(), g));
        char h = 'a' + d;

        dis = distance(r.begin(), find(r.begin(), r.end(), g));
        char h = 'a' + d;

        dis = distance(r.begin(), find(r.begin(), r.end(), g));
        char h = 'a' + d;
    }
}
int main()
{
    string text, cipher;
    text = "abc";
    cipher = encrypt(text);

    return 0;
}