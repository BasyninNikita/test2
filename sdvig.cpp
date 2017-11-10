#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <stdlib.h>
using namespace std;
void vyvod(int *array,unsigned int n)
{
	for(unsigned int i=0;i<n;i++)
	{
		cout<<array[i]<<" ";
	}
}
bool vvod(int *array,unsigned int n)
{
	char a;
    string stroka;
    getline(cin,stroka);
    istringstream stream(stroka);
    for(unsigned int i=0;i<n;i++)
    {
        if(!(stream>>array[i])){
            cout<<"An error has occurred while reading input data";
            return false;
        }   
    }
    if(stream>>a)
    {
    	cout<<"An error has occurred while reading input data"; exit (0);
    
            return false; 
	}
    return true;
}
void reversechast(int *array,unsigned int n,unsigned int sdv)
{
    for(unsigned int i=0;i<(n-sdv)/2;i++)
    	{
    		swap(array[i],array[n-sdv-i-1]);
		}
	for(unsigned int i=n-sdv,j=0;i<n-sdv+(sdv/2);j++,i++)
    {
    	swap(array[i],array[n-1-j]);
	}
	for(unsigned int i=0;i<(n/2);i++)
    	{
    		swap(array[i],array[n-i-1]);
		}
}


int main(int argc, char** argv) {
		int n;int sdv;
        string stroka;
        getline(cin,stroka);
        istringstream stream(stroka);
	    if(!(stream>>n)){
        cout<<"An error has occurred while reading input data"<<endl;
        return -1;
    	}
    	if(n<=0)
		{
			cout<<"An error has occurred while reading input data";exit (0);
		}
    int *array=new int[n];
    if (vvod(array,n))
    {
    	string stroka;
        getline(cin,stroka);
        istringstream stream(stroka);
	    if(!(stream>>sdv)){
        cout<<"An error has occurred while reading input data"<<endl;
        return -1;}
        reversechast(array,n,sdv);
        
	}
    vyvod(array,n);
}
