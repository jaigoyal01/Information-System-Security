#include <bits/stdc++.h>
using namespace std;
string encrypt(string text, string key)
{
    int tlen = text.length(), klen = key.length();
    string enc = "";
    for (int i = 0; i < tlen; i++)
    {
        int temp = (text[i] - 'a' + key[i % klen] - 'a') % 26;
        enc += char(temp + 'a');
    }
    return enc;
}
string decrypt(string cipher, string key)
{
    int tlen = cipher.length(), klen = key.length();
    string text = "";
    for (int i = 0; i < tlen; i++)
    {
        int temp = (cipher[i] - 'a' - (key[i % klen] - 'a') + 26) % 26;
        text += char('a' + temp);
    }
    return text;
}
int main()
{
    string text = "geeksforgeeks", key = "ayush";
    string res = encrypt(text, key);
    cout << res << endl;
    res = decrypt(res, key);
    cout << res << endl;
}
