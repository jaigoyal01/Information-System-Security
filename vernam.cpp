#include <bits/stdc++.h>
using namespace std;
string encDec(string text, char key)
{
    int tlen = text.length();
    string enc = "";
    for (int i = 0; i < tlen; i++)
        enc+=key^text[i];
    return enc;
}
int main()
{
    int opt;
    cout<<"Enter \n1) To Encrypt\n2)To Decrypt\n";
    cin>>opt;
    cout<<"Enter input file name\n";
            string fname;
            cin>>fname;
            cout<<"Enter output file name\n";
            string oname;
            cin>>oname;
            cout<<"Enter key value\n";
            char key;
            cin>>key;
            ifstream fin;
            ofstream fout;
            fout.open(oname.c_str());
            fin.open(fname.c_str());

    if(opt==1)
    {        
        while(fin)
        {
            string str;
            getline(fin,str);
            string encp = encDec(str, key);
            fout<<encp<<endl;
        }
        fin.close();
        fout.close();
    }
    if(opt==2)
    {        
        while(fin)
        {
            string str;
            getline(fin,str);
            string encp = encDec(str, key);
            fout<<encp<<endl;
        }
        fin.close();
        fout.close();
    }

}
