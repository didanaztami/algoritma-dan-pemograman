#include<iostream>

using namespace std;

main()
{
	int hari;
	cout<<"Masukan Kode Hari :";
	cin>>hari;
	switch (hari) {
		case 1:
			cout << "Senin";
			break;
		case 2:
			cout << "Selasa";
			break;
		case 3:
			cout << "Rabu";
			break;
		case 4:
			cout << "Kamis";
			break;
		case 5:
			cout << "Jumat";
			break;
		case 6:
			cout << "Sabtu";
			break;
		case 7:
			cout << "Minggu";
			break;
			default:
				cout << "Tidak Ada Hari";
	}
	return 0;
}
