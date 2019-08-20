#include <bits/stdc++.h>
#include<fstream>
#include<string>
using namespace std;
int determinant(int **t,int order)
{
    if(order==2)
        return t[0][0]*t[1][1]-t[0][1]*t[1][0];
    if(order==3)
        return t[0][0] * (t[1][1] * t[2][2] - t[1][2] * t[2][1]) - t[0][1] * (t[1][0] * t[2][2] - t[1][2] * t[2][0]) + t[0][2] * (t[1][0] * t[2][1] - t[1][1] * t[2][0]);
}
string encrypt(string text,int **t,int order)
{
    // int t[3][3]={{6,24,1},{13,16,10},{20,17,15}};
    for (int i = 0; i < order; i++)
    {
        for (int j = 0; j < order; j++)
        {
            t[i][j] = t[i][j]%26;
        }
    }

    // IF DETERMINANT IS ZERO
    int det,tlen,aclen,k=0;
    if(order==2)
    {
        // det=t[0][0]*t[1][1]-t[0][1]*t[1][0];
        tlen = text.length()/2;
        tlen=(text.length()%2==0)?tlen:tlen+1;
    }
        
    if(order==3)
    {
        // det=t[0][0] * (t[1][1] * t[2][2] - t[1][2] * t[2][1]) - t[0][1] * (t[1][0] * t[2][2] - t[1][2] * t[2][0]) + t[0][2] * (t[1][0] * t[2][1] - t[1][1] * t[2][0]);
        tlen = text.length()/3;
        tlen=(text.length()%3==0)?tlen:tlen+1;
    }
    aclen=text.length();
    string str="";
    while(tlen)
    {
        int tmat[order] = {};
        for (int i = 0; i < order; i++)
        {
            if(k+i<aclen)
            tmat[i] = text[k+i] - 'A';
            else
            tmat[i] = 'X'-'A';
        }
        int res[order] = {};
        for (int i = 0; i < order; i++)
        {
            for (int j = 0; j < order; j++)
            {
                res[i] += (t[i][j] * tmat[j]);
            }
            res[i] = res[i] % 26;
        }
        for (int i = 0; i < order; i++)
            str+=char('A' + (res[i]));

        k+=order;
        tlen--;
    }
    return str;
}
string decrypt(string cipher,int **t,int order, int det)
{
    
}
int main()
{
    string fname;
    int opt;
    cout << "Enter \n1) To Encrypt\n2)To Decrypt\n";
    // cin >> opt;
    cout<<"Enter file name\n";
    cin>>fname;
    cout<<"Enter output file name\n";
	string oname;
	cin>>oname;
    ifstream fin;
	ofstream fout;
    fin.open(fname.c_str());
    fout.open(oname.c_str());
    opt = 1;
    int order;
    cout<<"Enter order of key matrix\n";
    cin>>order;
    int **mat=new int*[order];
    for(int i=0;i<order;i++)
        mat[i]=new int[order];
    //Taking matrix elements
    for(int i=0;i<order;i++)
        for(int j=0;j<order;j++)
            cin>>mat[i][j];
    if(determinant(mat,order)==0)
    {
        cout<<"Encryption not possible\n";
        exit(0);
    }
    if (opt == 1)
    {
        while(fin)
			{
				string str;
				getline(fin,str);
				string t=encrypt(str,mat,order);
				fout<<t<<endl;
			}
			fin.close();
			fout.close();
    }
    if (opt == 2)
    {
     while(fin)
			{
				string str;
				getline(fin,str);
				string t=decrypt(str,mat,order,determinant(mat,order));
				fout<<t<<endl;
			}	
			fin.close();
			fout.close();
    }
}
