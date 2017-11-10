#include <iostream>
#include <sstream>
#include <string>
#include <utility>
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
    string stroka;
    getline(cin,stroka);
    istringstream stream(stroka);
    for(unsigned int i=0;i<n;i++)
    {
        if(!(stream>>array[i])){
            cout<<"nepolnuy massiv";
            return false;
        }   
    }
    return true;
}
void reverse(int *array,unsigned int n)
{
    for(unsigned int i=0;i<(n/2);i++)
    	{
    		swap(array[i],array[n-i-1]);
		}
}
    

int main(int argc, char** argv) {
	unsigned int n;
        string stroka;
        getline(cin,stroka);
        istringstream stream(stroka);
	    if(!(stream>>n)){
        cout<<"error"<<endl;
        return -1;
    }
    int *array=new int[n];
    if (vvod(array,n))
    {
    	reverse(array,n);
	}
    vyvod(array,n);
}
