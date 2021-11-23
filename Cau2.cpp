//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <fstream>
//#define vc 100
//#define vmax 100
//#include <stdio.h>
//#include <conio.h>
//#include<string>
//#include<stdlib.h>
//using namespace std;
//typedef struct dothi
//{
//
//	int w[vmax][vmax];
//	int M, N, S, T;
//}Graph;
//int sp[vc];
//int tp[vc];
//void input_matran_ke(Graph& Gr);
//int floyd(Graph Gr, int* &P, int start, int end);
//int TimDinh(Graph Gr, int f, int k)
//{
//	int* P;
//	int flag;
//
//
//	int len = floyd(Gr, P, f, k);
//	if (len != 0)
//	{
//		flag = k;
//	}
//	else return 0;
//
//
//	return flag;
//}
//int timVTMin(int s[], Graph Gr)
//{
//
//	int* P;
//	int min = 1;
//	int vtmin = 0;
//	int n = sizeof(n) / sizeof(s[0]);
//	for (int i = 0; i < Gr.M; i++)
//	{
//		if (min >= floyd(Gr, P, Gr.S, s[i]))
//		{
//			min = floyd(Gr, P, Gr.S, s[i]);
//			vtmin = i;
//		}
//	}
//	return vtmin;
//
//
//}
//void HanhTrinh(Graph Gr, int f, int t, int r[])
//{
//	int l = 1;
//	int* P;
//	int len = floyd(Gr, P, f, t);
//
//	int i = t - 1;
//
//	r[0] = i + 1;
//	while (i != f - 1)
//	{
//
//		r[l] = P[i] + 1;
//		l++;
//		i = P[i];
//	}
//
//}
//void main()
//{
//	Graph Gr;
//
//	input_matran_ke(Gr);
//	cout << endl << "---------------Thuat toan Floyd-----------" << endl;
//	printf("\n///////Hanh Tinh Hai Ong Ba Ngau Gap Nhau///////");
//	printf("\nOng ngau xuat phat tu hanh tinh so %d", Gr.S);
//	printf("\nBa ngau xuat phat tu hanh tinh so %d", Gr.T);
//	int n = sizeof(n) / sizeof(sp[0]);
//	int flag = 1;
//	int ss[vc];
//	int p = 0;
//	int* P;
//	for (int i = 0; i < Gr.M; i++)
//	{
//		if (TimDinh(Gr, Gr.S, i) != 0 && TimDinh(Gr, Gr.T, i) != 0)
//		{
//			HanhTrinh(Gr, Gr.S, TimDinh(Gr, Gr.S, i), sp);
//			HanhTrinh(Gr, Gr.T, TimDinh(Gr, Gr.T, i), tp);
//			for (int j = 0; j < n; j++)
//			if (sp[j] != Gr.S && sp[j] != Gr.T && sp[j] == tp[j] && floyd(Gr, P, Gr.S, sp[j]) == floyd(Gr, P, Gr.S, tp[j]))
//				ss[p++] = sp[j];
//			else
//				flag = 0;
//		}
//
//
//	}
//
//	int min = 1;
//	int vt = 0;;
//	int m = sizeof(m) / sizeof(ss[0]);
//	if (flag == 0)
//	{
//		printf("\nCRY");
//	}
//	else
//	{
//		for (int i = 0; i <= m; i++)
//		{
//			if (min >= floyd(Gr, P, Gr.S, ss[i]))
//			{
//				min = floyd(Gr, P, Gr.S, ss[i]);
//				vt = i;
//			}
//		}
//		printf("\nHanh tinh ong ba ngau co the gap nhau voi thoi gian ngan nhat la:\nHanh tinh so: %d", ss[vt]);
//	}
//	cout << endl;
//	system("pause");
//}
//void input_matran_ke(Graph& Gr)
//{
//	ifstream fileIn("test.txt");
//	if (!fileIn.is_open())
//	{
//		cout << "Khong tim thay file.";
//		return;
//	}
//	fileIn >> Gr.M;
//	fileIn >> Gr.N;
//	fileIn >> Gr.S;
//	fileIn >> Gr.T;
//	for (int i = 0; i < Gr.N; i++)
//	{
//		for (int j = 0; j < Gr.N; j++)
//			fileIn >> Gr.w[i][j];
//	}
//	fileIn.close();
//}
//int floyd(Graph Gr, int* &P, int start, int end)
//{
//	int a = start - 1, b = end - 1;
//	int* Len = new int[Gr.N];
//	int* S = new int[Gr.N];
//	P = new int[Gr.N];
//	fill(Len, Len + Gr.N, vc);
//	fill(P, P + Gr.N, a);
//	fill(S, S + Gr.N, 0);
//	Len[a] = 0;
//	int i = a;
//
//	for (i = 0; i < Gr.N; i++)
//	if (!S[i] && Len[i] != vc)
//		break;
//	for (int j = i + 1; j < Gr.N; j++)
//	if (!S[j] && Len[j] < Len[i])
//		i = j;
//	S[i] = 1;
//
//	for (int k = 0; k<Gr.N; k++)
//	{
//		for (int i = 0; i<Gr.N; i++)
//		for (int j = 0; j<Gr.N; j++)
//		for (int j = 0; j < Gr.N; j++)
//		{
//			if (!S[j] && Gr.w[i][j])
//			if (Len[i] + Gr.w[i][j] < Len[j])
//			{
//				Len[j] = Len[i] + Gr.w[i][j];
//				P[j] = i;
//
//			}
//		}
//
//	}
//	return Len[b];
//}