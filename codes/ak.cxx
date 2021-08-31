#include<iostream>
#include<string>
using namespace std;
int main(void)
{
	string s1;

	cout<<"Enter String"<<endl;

	cin>>s1;


        int len=s1.size();
	
	for (int i=0;i<len;i++)

	{
		for(int j=i+1;j<len;j++)
		{
			if (s1[i]==s1[j])
			{

				cout<<"char is:" << s1[i];
				return 0;
			}

		}

	}

	cout<<"No repeat"<<endl;

}

