#include <bits/stdc++.h>
using namespace std;
string generateKey(int len)
{
    string str = "";
    for (int i = 0; i < len; i++)
    {
        int r = rand() % 26;
        str += char('a' + r);
    }
    return str;
}
string encrypt(string text, string key)
{
    int tlen = text.length();
    string enc = "";
    for (int i = 0; i < tlen; i++)
    {
        int temp = (text[i] - 'a' + key[i] - 'a') % 26;
        enc += char(temp + 'a');
    }
    return enc;
}
string decrypt(string cipher, string key)
{
    int tlen = cipher.length();
    string text = "";
    for (int i = 0; i < tlen; i++)
    {
        int temp = (cipher[i] - 'a' - (key[i] - 'a') + 26) % 26;
        text += char('a' + temp);
    }
    return text;
}
int main()
{
    string text = "hello", key;
    key = generateKey(text.length());
    string encp = encrypt(text, key);
    string dec = decrypt(encp, key);
    cout << encp << endl
         << dec;
}