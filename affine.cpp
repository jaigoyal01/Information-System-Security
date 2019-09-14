#include <bits/stdc++.h>
using namespace std;
bool check(int a)
{
    if ((a % 2) == 0 || a == 13)
        return false;
    return true;
}
int inv(int a)
{
    int j;
    for (int i = 0; i < 26; i++)
    {
        int flag = (a * i) % 26;
        if (flag == 1)
        {
            j = i;
            // break;
        }
    }
    return j;
}
string encp(string text, int a, int b)
{
    string cipher = "";
    for (int i = 0; i < text.length(); i++)
    {
        if (text[i] != ' ')
            cipher = cipher + (char)((((a * (tolower(text[i]) - 'a')) + b) % 26) + 'A');
        else
            cipher += text[i];
    }
    return cipher;
}
string decp(string cipher, int a, int b)
{
    string msg = "";
    int in = inv(a);

    for (int i = 0; i < cipher.length(); i++)
    {
        if (cipher[i] != ' ')
            msg = msg + (char)(((in * ((cipher[i] + 'A' - b)) % 26)) + 'a');
        else
            msg += cipher[i];
    }

    return msg;
}
int main()
{
    int opt;
    cout << "Enter \n1) To Encrypt\n2)To Decrypt\n3)To Exit\n";
    cin >> opt;
    cout << "Enter input file name\n";
    string fname;
    cin >> fname;
    cout << "Enter output file name\n";
    string oname;
    cin >> oname;
    cout << "Enter a and b value\n";
    int a, b;
    cin >> a >> b;
    if (!check(a))
    {
        cout << "Value of a should be coprime with 26\n";
        exit(0);
    }
    ifstream fin;
    ofstream fout;
    fout.open(oname.c_str());

    fin.open(fname.c_str());
    if (opt == 1)
    {
        // cout<<"hello";
        while (fin)
        {
            string str;
            getline(fin, str);
            // cout<<str;
            string t = encp(str, a, b);
            // cout<<t<<endl;
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
            string t = decp(str, a, b);
            fout << t << endl;
        }
        fin.close();
        fout.close();
    }
    if (opt == 3)
        exit(0);
    return 0;
}