#include<bits/stdc++.h>
using namespace std;
int keylength(string name)
{
	ifstream fin;
	fin.open("key.txt");
	string str;
	getline(fin,str);
	return str.length();
}
string getkey(string name)
{
	ifstream fin;
	fin.open("key.txt");
	string str;
	getline(fin,str);
	map<char,int> m;
	for(int i=0;i<26;i++)
	{
		if(((str[i]>=65 && str[i]<=90) || (str[i]>=97 && str[i]<=122)) && m[str[i]]==0)
		{
			m[str[i]]++;
		}
		else
		{
			cout<<"Your key should be unique and does not contain special symbols\n";
			exit(0);	
		}
		
	}

	return str;
}
string encp(string text,string key)
{
	int len=text.length();
	string res="";
	for(int i=0;i<len;i++)
	{
		if(text[i]!=' ')
		{
			res+=key[text[i]-'a'];
		}
		else
			res+=text[i];
	}
	return res;
}
string decrp(string text,string key)
{
	int len=text.length();
	string res="";
	for(int i=0;i<len;i++)
	{
		if(text[i]!=' ')
		{
			int j=0;
			while(key[j]!=text[i])
				j++;
			res+=(char)(97+j);
		}
		else
			res+=text[i];
	}
	return res;
}
int main()
{
	cout<<"Enter key file name\n";
	string keyfile;
	cin>>keyfile;
	int keylen=keylength(keyfile);
	if(keylen!=26)
	{
		cout<<"Key length should be of 26 length\n";
		exit(0);
	}
	string key=getkey(keyfile);

	int opt;
	cout<<"Enter \n1) To Encrypt\n2)To Decrypt\n3)To Exit\n";
	cin>>opt;
	cout<<"Enter input file name\n";
	string fname;
	cin>>fname;
	cout<<"Enter output file name\n";
	string oname;
	cin>>oname;

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
			// cout<<str;
			string t=encp(str,key);
			// cout<<t<<endl;
			fout<<t<<endl;
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
			// cout<<str;
			string t=decrp(str,key);
			// cout<<t<<endl;
			fout<<t<<endl;
		}
		fin.close();
		fout.close();
	}
	if (opt == 3)
		exit(0);
}
