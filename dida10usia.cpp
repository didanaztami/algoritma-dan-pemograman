#include<iostream>
using namespace std;
int main()
{
	int umur;
	cout<<"Masukan Umur : ";
	cin>>umur;
	
	if(umur<=18){
		if(umur<=10){
			cout<<"Anak-anak"<<endl;
		}else{
			cout<<"Reamaja"<<endl;
		}
	}else{
		cout<<"Bukan Usia Anaka Maupun Remaja"<<endl;
	}
}
