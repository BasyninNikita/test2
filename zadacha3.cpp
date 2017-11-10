#include <iostream>
#include <sstream>
#include <string>
using namespace std;
bool vvod(float ** & matr, unsigned int & rows, unsigned int & columns){
    string str;
    getline(cin, str);
    istringstream STREAM(str);
    char znak;
    if((STREAM>>rows)&&(STREAM>>znak)&&(znak==',')&&(STREAM>>columns)){
        matr=new float *[rows];
        for(unsigned int i=0; i<rows; ++i){
            matr[i]=new float[columns];
            string stroka;
            getline(cin, stroka);
            istringstream stream(stroka);
            for(unsigned int j=0; j<columns; ++j){ 
                if(!(stream>>matr[i][j])){
                    return false; 
                }
            }
        }
    }
    else{
        return false;
    }
    return true;
}
void sdvig(float *array, int n, int sdv){
    float *arraylev=new float[n-sdv];
    float *arrayprav=new float[sdv];
    for(unsigned int i=0; i<n; ++i){
        if(i<n-sdv){
            arraylev[i]=array[i];
        }
        else{
            arrayprav[i+sdv-n]=array[i];
        }
    }
    for(unsigned int i=0; i<(n-sdv)/2; ++i){
        swap(arraylev[i], arraylev[n-sdv-1-i]);
    }
    for(unsigned int i=0; i<sdv/2; ++i){
        swap(arrayprav[i], arrayprav[sdv-1-i]);
    }
    for(unsigned int i=0; i<n; ++i){
        if(i<n-sdv){
            array[i]=arraylev[i];
        }
        else{
            array[i]=arrayprav[i+sdv-n];
        }
    }
    for(unsigned int i=0; i<n/2; ++i){
        swap(array[i], array[n-1-i]);
    }
}
int main(){
    float **matr;
    unsigned int rows, columns;
    if(!(vvod(matr, rows, columns))){
        cout<<"An error has occured while reading input data"<<endl;
        return -1;
    }
    int sdv;
    string s;
    getline(cin, s);
    istringstream stream(s);
    if(!(stream>>sdv)||(sdv<0)){
        cout<<"An error has occured while reading input data."<<endl;
        return -2;
    }
    unsigned int n=2*rows+2*columns-4;
    float *mass=new float[n];
    unsigned int x=0;
    for(unsigned int j=0; j<columns-1; ++j){
        mass[x]=matr[0][j];
        x++;
    }
    for(unsigned int i=0; i<rows-1; ++i){
        mass[x]=matr[i][columns-1];
        x++;
    }
    for(unsigned int j=columns-1; j>0; --j)
    {
        mass[x]=matr[rows-1][j];
        x++;
    }
    for(unsigned int i=rows-1; i>0; --i)
    {
        mass[x]=matr[i][0];
        x++;
    }
    sdvig(mass, n, sdv);
    x=0;
    for(unsigned int j=0; j<columns-1; ++j){
        matr[0][j]=mass[x];
        x++;
    }
    for(unsigned int i=0; i<rows-1; ++i){
        matr[i][columns-1]=mass[x];
        x++;
    }
    for(unsigned int j=columns-1; j>0; --j){
        matr[rows-1][j]=mass[x];
        x++;
    }
    for(unsigned int i=rows-1; i>0; --i){
        matr[i][0]=mass[x];
        x++;
    }
    delete[]mass;
    for(unsigned int i=0; i<rows; ++i){
        for(unsigned int j=0; j<columns; ++j){
            cout<<matr[i][j]<<" ";
        }
        cout<<endl;
    }
    for(unsigned int i=0; i<rows; ++i){
        delete[]matr[i];
    }
    delete[]matr;
}
