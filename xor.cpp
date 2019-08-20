#include <bits/stdc++.h>
using namespace std;
string encrypt(string text, char key)
{
    int tlen = text.length();
    string enc = "";
    for (int i = 0; i < tlen; i++)
    {
        // enc += (char)((int)text[i] ^ (int)key);
        // enc += char(temp);
        enc += char(int(text[i] - 'a') ^ int(key - 'a'));
    }
    return enc;
}
string decrypt(string cipher, char key)
{
    int tlen = cipher.length();
    string text = "";
    for (int i = 0; i < tlen; i++)
    {
        // text += (char)((int)cipher[i] ^ (int)key);
        // text += char(temp);
        text += char(int(cipher[i] - 'a') ^ int(key - 'a'));
    }
    return text;
}
int main()
{
    string text = "ge";
    char key = 'k';
    string encp = encrypt(text, key);
    string dec = decrypt(encp, key);
    cout << encp << endl
         << dec;
}