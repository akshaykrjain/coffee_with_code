#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

// We need this function to define how to sort
// the vector. We will pass this function into the
// third parameter and it will tell it to sort descendingly.
bool wayToSort(int i, int j) { return i > j; }

int main()
{
	vector<int> v1;
	v1={11,34,23,3,12,11,56,78,1};

	cout << "\n Before sorting : \n";

	for (int i=0;i<v1.size();i++)
		cout<<"\t"<<v1[i];


        //Quick Sort
	sort(v1.begin(),v1.end());


	cout << "\n After sorting : \n";
	
	for (int i=0;i<v1.size();i++)
		cout<<"\t"<<v1[i];

        //Quick Sort Descending
	sort(v1.begin(),v1.end(),wayToSort);


	cout << "\n After sorting (desc): \n";
	
	for (int i=0;i<v1.size();i++)
		cout<<"\t"<<v1[i];
     
       
	int n;
	  std::vector<int>::iterator it;
       cout << "\n Enter the number u want to search \n";
       cin >> n;

       cout << "\n Searching for " <<n;

       it = find(v1.begin(),v1.end(),n);

       if (it != v1.end())
    	 cout << "\nElement found in myvector: " << *it << '\n';
      else
         cout << "\nElement not found in myvector\n";


 
       cout<<endl;

	return 0;
}

	
