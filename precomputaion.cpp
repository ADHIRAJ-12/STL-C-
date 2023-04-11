#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int hsh[N][26];
int main()
{
	int t;int n; int q; cin>>t ;
	while(t--)
	{
		cin>>n ;cin>>q ;
		for (int i=0;i<n;i++) 
		{
			for (int j=0;j<26;j++) 
			{
				hsh[i][j]=0 ; 
			}
		}
		
		string s ;
		cin>>s ;
		for (int i=0;i<n;i++)  //storing  count of every alphabet which comes in s at the position of their respective element , if an alphabet comes in a position that position in the grid gets changed to one
		{
			hsh[i][s[i]-'a']++ ;  //example a gets stored in [][0]
		}
		for (int i=0;i<26;i++) //presumming for all alphabets....fixing the columns 
		{
			for (int j=1;j<n;j++) //running through the string for every alphabet
			{
				hsh[j][i]+=hsh[j-1][i] ; 
			}
		}
		//all alphabet occurences have been presummed now
		while(q--)
		{
			int l,r ; cin>>l>>r ; int oddcount=0; //The concept is that if oddcount<=1 then we have chances of palindrom otherwise not . we cannot have palindrome for a word which has oddnumber of occurunces of a letter for more than 1 time
			for(int i=0;i<26;i++)
			{
				int charcount=hsh[r-1][i]-hsh[l-2][i]; //seeing how many times a particular alphabet comes in a string
				if (charcount%2==1) oddcount++ ;
			}
			if(oddcount<=1) cout<<"YES"<<endl ;
			else cout<<"NO"<<endl;
			
		}
	}
}
