#include <bits/stdc++.h>
using namespace std;
int determinant(int size, int t[size][size])
{
    if (size == 1)
        return t[0][0];
    if (size == 2)
        return t[0][0] * t[1][1] - t[0][1] * t[1][0];
    if (size == 3)
        return t[0][0] * (t[][] * t[][] - t[][] * t[][]) - t[0][0] * (t[][] * t[][] - t[][] * t[][]) + t[0][0] * (t[][] * t[][] - t[][] * t[][])
}
string encrypt(string text, string key)
{
    int tlen = text.length();
    int tmat[tlen] = {};
    for (int i = 0; i < tlen; i++)
    {
        tmat[i] = text[i] - 'A';
    }
    // for (int i = 0; i < tlen; i++)
    //     cout << tmat[i] << " ";
    // cout << endl;
    int klen = key.length(), ksq = sqrt(klen);
    int kmat[ksq][ksq] = {};
    int k = 0;
    for (int i = 0; i < ksq; i++)
    {
        for (int j = 0; j < ksq; j++)
        {
            kmat[i][j] = key[k] - 'A';
            k++;
        }
    }
    // for (int i = 0; i < ksq; i++)
    // {
    //     for (int j = 0; j < ksq; j++)
    //     {
    //         cout << kmat[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    int res[tlen] = {};
    for (int i = 0; i < ksq; i++)
    {
        for (int j = 0; j < ksq; j++)
        {
            res[i] += (kmat[i][j] * tmat[j]);
        }
        res[i] = res[i] % 26;
    }
    for (int i = 0; i < tlen; i++)
        cout << char('A' + (res[i])) << " ";
    return "done";
}
string decrypt(string cipher, string key)
{
}
int main()
{
    string text = "POH", key = "GYBNQKURP";
    int opt;
    // cout << "Enter \n1) To Encrypt\n2)To Decrypt\n";
    // cin >> opt;
    opt = 1;
    if (opt == 1)
    {
        string cipher = encrypt(text, key);
        cout << cipher << endl;
    }
    if (opt == 2)
    {
        string required = decrypt(text, key);
        cout << required << endl;
    }
}