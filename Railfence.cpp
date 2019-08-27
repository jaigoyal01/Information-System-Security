#include <bits/stdc++.h>
using namespace std;
string encrypt(string text, string key)
{
    int klen = key.length(), tlen = text.length();
    int rows = (tlen % klen == 0) ? tlen / klen : tlen / klen + 1;
    char mat[rows][klen], k = 0;
    map<char, int> m;
    for (int i = 0; i < klen; i++)
    {
        m[key[i]] = i;
    }
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < klen; j++)
        {
            if (k < tlen)
            {
                mat[i][j] = text[k];
                k++;
            }
            else
            {
                mat[i][j] = 'x';
            }
        }
    }
    string ans = "";
    auto it = m.begin();
    while (it != m.end())
    {
        for (int i = 0; i < rows; i++)
            ans += mat[i][it->second];
        it++;
    }
    return ans;
}
string decrypt(string text, string key)
{
    int klen = key.length(), tlen = text.length();
    int rows = (tlen % klen == 0) ? tlen / klen : tlen / klen + 1;
    char mat[rows][klen], k = 0;
    map<char, int> m;
    for (int i = 0; i < klen; i++)
    {
        m[key[i]] = i;
    }

    auto it = m.begin();
    while (it != m.end())
    {
        for (int i = 0; i < rows; i++)
        {
            if (k < tlen)
            {
                mat[i][it->second] = text[k];
                k++;
            }
        }
        it++;
    }

    string ans = "";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < klen; j++)
        {
            ans += mat[i][j];
        }
    }
    return ans;
}
int main()
{
    int opt;
    cout << "Enter \n1) To Encrypt\n2)To Decrypt\n";
    cin >> opt;
    cout << "Enter input file name\n";
    string fname;
    cin >> fname;
    cout << "Enter output file name\n";
    string oname;
    cin >> oname;
    cout << "Enter key value\n";
    string key;
    cin >> key;
    ifstream fin;
    ofstream fout;
    fout.open(oname.c_str());
    fin.open(fname.c_str());
    if (opt == 1)
    {
        while (fin)
        {
            string str;
            getline(fin, str);
            string t = encrypt(str, key);
            fout << t << endl;
        }
        fin.close();
        fout.close();
    }
    if (opt == 2)
    {
        while (fin)
        {
            string str;
            getline(fin, str);
            string t = decrypt(str, key);
            fout << t << endl;
        }
        fin.close();
        fout.close();
    }

    return 0;
}