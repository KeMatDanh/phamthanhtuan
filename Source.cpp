/*
Phạm Thanh Tuấn
Nguyễn Hữu Trung
Nội dung: Dùng thuật toán Dijkstra tìm đường đi trong khu du lịch Xoài Non
*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<conio.h>
#include<fstream> 
#include <string>

using namespace std;
#define MAX 100
#define TRUE 1
#define FALSE  0
#define VOCUNG 9999999

int chon = -1;
char a[10];
char b[10];
int n;//số đỉnh của đồ thị.
int s = 0;//đỉnh đầu.
int t = 0;//đỉnh cuối
int danhDau[MAX];//mảng đánh dấu đường đi.
int d[MAX];//mảng đánh dấu khoảng cách.
int Matran[MAX][MAX];//ma trận trọng số
int Duyet[MAX];//mảng đánh dấu đỉnh đã được gán nhãn.
int  tam[MAX];


void docfile(void){
	FILE *f = fopen("map.txt", "r");
	if (f == NULL)
		printf("\nKhong tim thay file");
	else
	{
		fscanf(f, "%d", &n);
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= n; j++){
				fscanf(f, "%d", &Matran[i][j]);
				if (Matran[i][j] == 0) Matran[i][j] = VOCUNG;
			}
		}
	}
}
void KetQua(void){
	char kq[MAX];
	int p = 0;
	cout << "\n\tTuyen duong di ngan nhat la :";
	tam[p] = t;
	p++;
	int i = danhDau[t];
	while (i != s){
		tam[p++] = i;
		i = danhDau[i];
	}
	tam[p] = s;
	p++;
	for (int i = p - 1; i >= 0; i--)
	{
		if (tam[i] == 1)
		{
			strcpy(kq, "Khu nghi duong ");
			cout << " " << kq << "\t";
		}
		if (tam[i] == 2)
		{
			strcpy(kq, "Choi ven ho");
			cout << " " << kq << "\t";
		}
		if (tam[i] == 3)
		{
			strcpy(kq, "Dap vit");
			cout << " " << kq << "\t";
		}
		if (tam[i] == 4)
		{
			strcpy(kq, "Khu vui choi thieu nhi");
			cout << " " << kq << "\t ";
		}
		if (tam[i] == 5)
		{
			strcpy(kq, "Ho boi");
			cout << " " << kq << "\t";
		}
		if (tam[i] == 6)
		{
			strcpy(kq, "Choi ven suoi ");
			cout << " " << kq << "\t";
		}
		if (tam[i] == 7)
		{
			strcpy(kq, "Ho ca sau");
			cout << " " << kq << "\t";
		}
		if (tam[i] == 8)
		{
			strcpy(kq, "Thue xe dap dien");
			cout << " " << kq << "\t";
		}
		if (tam[i] == 9)
		{
			strcpy(kq, "Ban sung son");
			cout << " " << kq << "\t";
		}
		if (tam[i] == 10)
		{
			strcpy(kq, "So thu");
			cout << " " << kq << "\t ";
		}
		if (tam[i] == 11)
		{
			strcpy(kq, "Cuoi voi");
			cout << " " << kq << "\t ";
		}
		if (tam[i] == 12)
		{
			strcpy(kq, "Cuoi da dieu");
			cout << " " << kq << "\t";
		}
		if (tam[i] == 13)
		{
			strcpy(kq, "Cam trai");
			cout << " " << kq << "\t";
		}
	}
	cout << endl << "\tDo dai duong di la : " << d[t] * 1.8 << " m";
	cout << "\n\n\n\n";
}
void Dijkstra(void){
	int u, minp;
	//khởi tạo nhãn tạm thời cho các đỉnh.
	for (int v = 1; v <= n; v++){
		d[v] = Matran[s][v];
		danhDau[v] = s;
		Duyet[v] = FALSE;
	}
	danhDau[s] = 0;
	d[s] = 0;
	Duyet[s] = TRUE;
	//bươc lặp
	while (!Duyet[t]) {
		minp = VOCUNG;
		//tìm đỉnh u sao cho d[u] là nhỏ nhất
		for (int v = 1; v <= n; v++){
			if ((!Duyet[v]) && (minp > d[v])){
				u = v;
				minp = d[v];
			}
		}
		Duyet[u] = TRUE;// u la dinh co nhan tam thoi nho nhat
		if (!Duyet[t]){
			//gán nhãn lại cho các đỉnh.
			for (int v = 1; v <= n; v++){
				if ((!Duyet[v]) && (d[u] + Matran[u][v] < d[v])){
					d[v] = d[u] + Matran[u][v];
					danhDau[v] = u;
				}
			}
		}
	}
}
void nhap(char a[], char b[])
{
	printf("\tNhap diem xuat phat  : ");
	fflush(stdin);
	gets(a);
	printf("\tNhap dia diem ban muon den : ");
	fflush(stdin);
	gets(b);
	fflush(stdin);
	if (_stricmp(a, "nghi duong") == 0)
		s = 1;
	if (_stricmp(a, "choi ven ho") == 0)
		s = 2;
	if (_stricmp(a, "dap vit") == 0)
		s = 3;
	if (_stricmp(a, "khu thieu nhi") == 0)
		s = 4;
	if (_stricmp(a, "ho boi") == 0)
		s = 5;
	if (_stricmp(a, "choi ven suoi") == 0)
		s = 6;
	if (_stricmp(a, "ca sau") == 0)
		s = 7;
	if (_stricmp(a, "thue xe dap dien") == 0)
		s = 8;
	if (_stricmp(a, "ban sung son") == 0)
		s = 9;
	if (_stricmp(a, "so thu") == 0)
		s = 10;
	if (_stricmp(a, "cuoi voi") == 0)
		s = 11;
	if (_stricmp(a, "cuoi da dieu") == 0)
		s = 12;
	if (_stricmp(a, "cam trai") == 0)
		s = 13;
	//-----------------------------
	if (_stricmp(b, "nghi duong") == 0)
		t = 1;
	if (_stricmp(b, "choi ven ho") == 0)
		t = 2;
	if (_stricmp(b, "dap vit") == 0)
		t = 3;
	if (_stricmp(b, "khu thieu nhi") == 0)
		t = 4;
	if (_stricmp(b, "ho boi") == 0)
		t = 5;
	if (_stricmp(b, "choi ven suoi") == 0)
		t = 6;
	if (_stricmp(b, "ca sau") == 0)
		t = 7;
	if (_stricmp(b, "thue xe dap dien") == 0)
		t = 8;
	if (_stricmp(b, "ban sung son") == 0)
		t = 9;
	if (_stricmp(b, "so thu") == 0)
		t = 10;
	if (_stricmp(b, "cuoi voi") == 0)
		t = 11;
	if (_stricmp(b, "cuoi da dieu") == 0)
		t = 12;
	if (_stricmp(b, "cam trai") == 0)
		t = 13;
}
void map()
{
	cout << "\n                                                                    Cuoi da dieu";
	cout << "\n                                                                      .                  ";
	cout << "\n                   . . . Ca sau . . . .  .                          .                             ";
	cout << "\n               .          .     .           .                    .                                ";
	cout << "\n            .             .        .           .              Cuoi voi .  .  . .  .               ";
	cout << "\n         .                .             .          .            .           .        .            ";
	cout << "\n     .                    .                .            .      .             .        .          ";
	cout << "\n Nghi duong. . . . . .Choi ven ho. . . . . Dap vit. . . . .Choi ven suoi       .        .         ";
	cout << "\n   .                        .                    .               .           .          .        ";
	cout << "\n     .                       .                      .               .       .            .        ";
	cout << "\n      .                        .                     .                .     .             .         ";
	cout << "\n       .                          .                   .              .  Cam trai         .    ";
	cout << "\n        .                           .                  .          .        .            .           ";
	cout << "\n         Khu thieu nhi. . . . . Thue xe dap dien       .         .         .           .                                     ";
	cout << "\n          .                        .   .               .       .           .          .  ";
	cout << "\n           .                    .         .           .      .            .          .   ";
	cout << "\n             .              .                .       .     .             .         .     ";
	cout << "\n               .        .                         .     .              .         .      ";
	cout << "\n                 Ho boi . . . . . . . . . . .Ban sung son            .         .                                               ";
	cout << "\n                                                    .              .          .      ";
	cout << "\n                                                       .         .         .       ";
	cout << "\n                                                          .     .       .                                                                   ";
	cout << "\n                                                          So thu  .  .                 ";
	cout << "\n                                                                                  ";
	cout << "\n\n";

}
void main(void)
{
	printf("\n");
	printf("*/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*");
	printf("\n\t\t\tCHAO MUNG DEN CHUONG TRINH TIM DUONG DI TRONG KHU DU LICH VUON XOAI \n");

	while (chon != 0)
	{
		map();
		printf("\n1. Chuong trinh tim duong di ngan nhat");
		printf("\n0. Thoat chuong trinh");
		printf("\n\n\t\t\t\tNhap lua chon cua ban : ");
		scanf("%d", &chon);
		printf("\n");
		switch (chon)
		{
		case 1:
		{
				  nhap(a, b);
				  docfile();
				  Dijkstra();
				  KetQua();
				  _getch();
				  break;
		}
		case 0:
			printf("\n\t\t\t\t\tCam on ban da su dung chuong trinh nay");
			break;
		default:
			break;
		}
	}
	_getch();
}