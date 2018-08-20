#include "pch.h"
#include <iostream>
#define NAME 10
using namespace std;
struct MOB {
	int code;
	int tel;
	char name[NAME] = {"0"};
};
int MainMenu();
MOB* Add(MOB*arr1,int &numarr);
MOB* Delet(MOB*arr1, int &numarr);
void WriteArr(MOB*arr1, int numarr);
void Serch(MOB*arr1, int numarr);
int main()
{
	MOB *arr = NULL;
	int numarr = 0;
	while (true) {
		WriteArr(arr,numarr);
		switch (MainMenu())
		{
		case 1:{
			arr = Add(arr, numarr);
			break;}
		case 2: {
			arr = Delet(arr, numarr);
			break; }
		case 3: {
			Serch(arr, numarr);
			break; }
			
		default:;
		}
 }
}
int MainMenu() {
	int i = 0;

	cout << "\n1)Add        2)Delete         3)Serch\nWrite num comand";
	cin >> i;
	system("cls");
	return i;
}
MOB* Add(MOB*arr1, int &numarr) {
	numarr++;
	MOB *arr2 = new MOB[numarr];
	cout << "Cod-";
	cin >> arr2[numarr-1].code;
	cout << "\nTel-";
	cin >> arr2[numarr-1].tel;
	cout << "\nName-";
	cin >> arr2[numarr-1].name;
	for (int i = 0; i < numarr-1; i++) {
		arr2[i].code = arr1[i].code;
		arr2[i].tel = arr1[i].tel;
		for(int k=0;k<NAME;k++)
		arr2[i].name[k] = arr1[i].name[k];
	}
	system("cls");
	delete[] arr1;
	return arr2;
}
MOB* Delet(MOB*arr1, int &numarr) {//с ошибкой !!!!
	numarr--;
	int num=0;
	MOB *arr2 = new MOB[numarr];
	cout << "Write num element fo delete";
	cin >> num;
	for (int i = 0,z=0; i < numarr ; i++,z++) {
		if (i == num - 1)
			z++;
			arr2[i].code = arr1[z].code;
			arr2[i].tel = arr1[z].tel;
			for (int k = 0; k < NAME; k++)
				arr2[i].name[k] = arr1[z].name[k];
		
	}
	system("cls");
	delete[] arr1;
	return arr2;
}
void WriteArr(MOB*arr1, int numarr) {
	for (int i = 0; i < numarr; i++) {
		cout << i + 1 << ") " << arr1[i].code << arr1[i].tel << " - " << arr1[i].name<<endl;
	}
}
void Serch(MOB*arr1, int numarr) {
	int test = 0;
	char sername[NAME] = {"0"};
	cout << "Write Name-";
	cin >> sername;
	for (int i = 0; i < numarr; i++) {
		for (int k = 0; k < NAME; k++) {
			if (sername[k] == arr1[i].name[k])
				test++;
		}
		if (test == 10) {
			cout << " - " << arr1[i].code << arr1[i].tel;
		}
		test = 0;
	}
	system("pause");
	system("cls");
}