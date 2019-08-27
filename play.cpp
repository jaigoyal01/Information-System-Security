#include <bits/stdc++.h>
using namespace std;
char mat[5][5], dup;
void generate(string key)
{
	map<char, int> m;
	for (int i = 0; i < 26; i++)
		m['a' + i] = 1;

	int k = 0;
	int len = key.length();
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			int c = 0, f = 0;
			while (k < len && c != 1)
			{
				if (m[key[k]] == 1)
				{
					mat[i][j] = key[k];
					m[key[k]] = 0;
					c++;
					f = 1;
				}
				k++;
			}
			c = 0;
			if (f == 0)
			{

				map<char, int>::iterator it = m.begin();
				while (it != m.end() && it->second != 1)
				{
					it++;
				}
				mat[i][j] = it->first;
				it->second = 0;
			}
		}
	}
	map<char, int>::iterator it = m.begin();
	while (it != m.end() && it->second != 1)
	{
		it++;
	}
	dup = it->first;
}
void displaymat()
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
			cout << mat[i][j] << " ";
		cout << endl;
	}

	cout << "Special letter is " << dup << endl;
}
string pre(string text)
{
	if (text.length() % 2 != 0)
		text += 'x';
	int len = text.length();
	for (int i = 0; i < len; i++)
		if (text[i] == dup)
			text[i] = mat[4][4];
	return text;
}
string encrypt(string text)
{
	string fin = pre(text);
	int len = fin.length();
	string res = "";
	for (int k = 0; k < len - 1; k = k + 2)
	{
		string posa = "", posb = "";
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (fin[k] == mat[i][j])
				{
					posa += ('0' + i);
					posa += ('0' + j);
				}
				if (fin[k + 1] == mat[i][j])
				{
					posb += ('0' + i);
					posb += ('0' + j);
				}
			}
			// cout<<posa<<" "<<posb<<endl;
			if (posa.length() == 2 && posb.length() == 2)
				break;
		}
		if (posa[0] == posb[0])
		{
			res += mat[posa[0] - '0'][(posa[1] - '0' + 1) % 5];
			res += mat[posa[0] - '0'][(posb[1] - '0' + 1) % 5];
		}
		else if (posa[1] == posb[1])
		{
			res += mat[(posa[0] - '0' + 1) % 5][posa[0] - '0'];
			res += mat[(posb[1] - '0' + 1) % 5][posa[0] - '0'];
		}
		else
		{
			res += mat[posa[0] - '0'][posb[1] - '0'];
			res += mat[posb[0] - '0'][posa[1] - '0'];
		}
	}

	return res;
}
string decrypt(string text)
{
	string fin = text;
	int len = fin.length();
	string res = "";
	for (int k = 0; k < len - 1; k = k + 2)
	{
		string posa = "", posb = "";
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (fin[k] == mat[i][j])
				{
					posa += ('0' + i);
					posa += ('0' + j);
				}
				if (fin[k + 1] == mat[i][j])
				{
					posb += ('0' + i);
					posb += ('0' + j);
				}
			}
			// cout<<posa<<" "<<posb<<endl;
			if (posa.length() == 2 && posb.length() == 2)
				break;
		}
		if (posa[0] == posb[0])
		{
			res += mat[posa[0] - '0'][((posa[1] - '0' - 1) % 5) > 0 ? (posa[1] - '0' - 1) % 5 : (posa[1] - '0' - 1) + 5];
			res += mat[posa[0] - '0'][((posb[1] - '0' - 1) % 5) > 0 ? (posb[1] - '0' - 1) % 5 : (posb[1] - '0' - 1) + 5];
		}
		else if (posa[1] == posb[1])
		{
			res += mat[((posa[1] - '0' - 1) % 5) > 0 ? (posa[1] - '0' - 1) % 5 : (posa[1] - '0' - 1) + 5][posa[0] - '0'];
			res += mat[((posb[1] - '0' - 1) % 5) > 0 ? (posb[1] - '0' - 1) % 5 : (posb[1] - '0' - 1) + 5][posa[0] - '0'];
		}
		else
		{
			res += mat[posa[0] - '0'][posb[1] - '0'];
			res += mat[posb[0] - '0'][posa[1] - '0'];
		}
	}

	return res;
}
int main()
{
	string key = "monarchy", text = "hybride";
	generate(key);
	displaymat();
	string ans = encrypt(text);
	ans = decrypt(ans);
	cout << ans;
}
