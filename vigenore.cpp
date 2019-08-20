#include<bits/stdc++.h>
using namespace std;
string encrypt(string text,string key)
{
    int tlen=text.length(),klen=key.length();
    string enc="";
    for(int i=0;i<tlen;i++)
    {
        enc+='a'+((text[i]-'a')+(key[i%klen]))%26;
    }
    return enc;
}
string decrypt(string cipher,string key)
{
    int tlen=cipher.length(),klen=key.length();
    string text="";
    for(int i=0;i<tlen;i++)
    {
        text+='a'+((cipher[i]-'a')-(key[i%klen]))%26;
    }
    return text;
}
int main()
{
    string text="Hello",key="aaa";
    string res=encrypt(text,key);
    cout<<res<<endl;
    res=decrypt(res,key);
    cout<<res<<endl;
}