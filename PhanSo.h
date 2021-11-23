/*
 SV: Pham ThanhTuan
 MSSV: 2001207122
 Noi dung: Chieu thu 7: BTree
 */
#ifndef BTree_h
#define BTree_h

#define _CRT_SECURE_NO_WARNINGS
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

#define TRUE 1
#define FALSE 0
#define M 5
#define distance 0

struct Phanso
{
	int tuSo;
	int mauSo;
};
typedef Phanso ItemType;
struct BNode
{
	int numTree; /* numTree < M (Số khóa trong nút sẽ luôn ít hơn M của cây B) */
	ItemType Keys[M - 1]; /*Mảng chứa các khóa*/
	BNode* Branch[M]; /* numTree + 1 (M con trỏ sẽ được sử dụng) */
};

struct BTree
{
	BNode* Root; /* Con trỏ quản lý node gốc */
};
typedef BNode* NodePtr;

enum KeyStatus { Duplicate, SearchFailure, Success, InsertIt, LessKeys };

void initBTree(BTree &bt);
KeyStatus insertNode(NodePtr pCurrent, ItemType key, ItemType *upKey, NodePtr* newNode);
void insert(NodePtr &root, ItemType key);
void displayBTree(NodePtr root, int key);
KeyStatus remove(NodePtr &root, NodePtr pCurrent, ItemType key);
void deleteNode(NodePtr &root, ItemType key);
NodePtr searchNode(NodePtr root, ItemType key);
void search(NodePtr root, ItemType key);
enum KeyStatus insertNode(NodePtr root, ItemType key, ItemType* y, NodePtr* u);
int searchPosition(ItemType key, ItemType *keyArray, int numTree);
enum KeyStatus remove(NodePtr &root, NodePtr pCurrent, ItemType key);
//void createbrtree_From_File(ItemType y[], int &n);
//void taoPhanSoFile(BTree &bt);
void createbrtree_From_File(BTree &btree, int &n);
int timUCLN(int a, int b);
void rutGonPhanSo(ItemType &p);
int soSanhPhanSo(ItemType p1, ItemType p2);
ItemType congPhanSo(ItemType p1, ItemType p2);
void traverse(NodePtr proot);

#endif