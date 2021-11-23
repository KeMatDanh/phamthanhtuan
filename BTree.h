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
#define destance 
typedef int ItemType;
struct BNode{
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
void displayBTree(NodePtr root, ItemType key);
KeyStatus remove(NodePtr &root, NodePtr pCurrent, ItemType key);
void deleteNode(NodePtr &root, ItemType key);
NodePtr searchNode(NodePtr root, ItemType key);
void search(NodePtr root, ItemType key);
enum KeyStatus insertNode(NodePtr root, ItemType key, ItemType* y, NodePtr* u);
int searchPosition(ItemType key, ItemType *keyArray, int numTree);
enum KeyStatus remove(NodePtr &root, NodePtr pCurrent, ItemType key);
void TaoCayTuDong(BTree &bt);
//
void createbrtree_From_File(BTree &btree, int &n);
void nodeMinNumTree(NodePtr Root, int &minnode);
void displayNodeMinNumTree(NodePtr Root, int min);
void nodeMaxNumTree(NodePtr Root, int &maxnode);
void displayNodeMaxNumTree(NodePtr Root, int max);
int check_PrimeNumber(ItemType x);
int kiemTraNodeTo(int a[], int n);
int count_TNode_Is_PrimeNumber(NodePtr root, int &dem);
int sumNode(NodePtr root, int &sum);

#endif