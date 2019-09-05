#include <bits/stdc++.h>
using namespace std;
int posl, posm, posr;
void tra(vector<char> l, vector<char> m, vector<char> r)
{
}

string encrypt(string text)
{
    string st = "qwertyuiopasdfghjklzxcvbnm";
    int tlen = text.length();
    string left, mid, right, ref;
    left = "qazwsxedcrfvtgbyhnujmikolp";
    mid = "zxcvbnmasdfghjklqwertyuiop";
    right = "asdfghjklqzwxecrvtbynumiop";
    ref = "pqowieurytlaksjdhfgmznxbcv";
    // cout << left.length() << " " << mid.length() << " " << right.length();
    vector<char> l, m, r, str;
    string res = "";
    for (int i = 0; i < st.length(); i++)
        str.push_back(st[i]);
    for (int i = 0; i < left.length(); i++)
        l.push_back(left[i]);

    for (int i = 0; i < mid.length(); i++)
        m.push_back(mid[i]);

    for (int i = 0; i < right.length(); i++)
        r.push_back(right[i]);

    for (int i = 0; i < tlen; i++)
    {
        char c = str[text[i] - 'a'];
        cout << c << " ";
        char d = l[c - 'a'];
        cout << d << " ";
        char e = m[d - 'a'];
        cout << e << " ";
        char f = r[e - 'a'];
        cout << f << " ";
        char g = ref[f - 'a'];
        cout << g << " ";

        //traversing back
        vector<char>::iterator it;
        int dis;
        dis = distance(r.begin(), find(r.begin(), r.end(), g));
        char h = 'a' + dis;
        cout << h << " ";
        dis = distance(m.begin(), find(m.begin(), m.end(), h));
        char j = 'a' + dis;
        cout << j << " ";
        dis = distance(l.begin(), find(l.begin(), l.end(), j));
        char k = 'a' + dis;
        cout << k << " ";

        dis = distance(str.begin(), find(str.begin(), str.end(), k));
        cout << str[dis] << " ";

        res += str[dis];

        // rotate(l.begin(), l.begin() + 1, l.end());
        // rotate(m.begin(),m.begin()+1,m.end());
        // rotate(r.begin(),r.begin()+1,r.end());
        cout << endl;
    }
    return res;
}
int main()
{
    string text, cipher;
    text = "abc";
    cipher = encrypt(text);
    cout << cipher;
    return 0;
}