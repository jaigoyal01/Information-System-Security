#include <bits/stdc++.h>
using namespace std;
string encp(string text, int key)
{

	if (key > 26)
		key = key % 26;
	if (key < 0)
	{
		while (key < 0)
			key += 26;
	}
	int len = text.length();
	string res = "";
	for (int i = 0; i < len; i++)
	{
		if (text[i] != ' ')
		{
			int t = text[i] - 'a';
			int t2 = (t + key) % 26;
			res += (char)(65 + t2);
		}
		else
			res += text[i];
	}
	return res;
}
string decrp(string text, int key)
{
	if (key > 26)
		key = key % 26;
	if (key < 0)
	{
		while (key < 0)
			key += 26;
	}
	int len = text.length();
	string res = "";
	for (int i = 0; i < len; i++)
	{
		if (text[i] != ' ')
		{
			int t = text[i] - 'A';
			int t2 = (t) % 26 - key;
			if (t2 < 0)
			{
				res += (char)(97 + (26 + t2));
			}
			else
				res += (char)(97 + t2);
		}
		else
			res += text[i];
	}
	return res;
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
	cout << "Enter key value\n";
	int key;
	cin >> key;
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
			string t = encp(str, key);
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
			string t = decrp(str, key);
			fout << t << endl;
		}
		fin.close();
		fout.close();
	}
	if (opt == 3)
		exit(0);
	return 0;
}
