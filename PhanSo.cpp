#include "PhanSo.h"

void main()
{
	BTree bt;
	initBTree(bt);
	ItemType a[] = { { 1, 12 }, { 8, 2 }, { 25, 5 }, { 14, 28 }, { 17, 7 }, { 52, 16 }, { 48, 68 }, { 3, 26 }, { 29, 53 }, { 55, 45 } };
	int n = 10;
	int blanks=0;
	ItemType key;
	ItemType m[31];

	int chucnang;
	do
	{
		printf("\n\n CHUONG TRINH HIEN THUC CAY NHIEU NHANH");
		printf("\n\n Cac chuc nang chinh cua chuong trinh");
		printf("\n 1. Tao cay tu mang");
		printf("\n 2. Tao cay tu mang ngau nhien");
		printf("\n 3. Duyet cay");
		printf("\n 4. Xoa mot vai phan tu cay");
		printf("\n 4. Tim mot vai phan tu cay");
		printf("\n 4. Them mot vai phan tu cay");
		printf("\n 0. Ket thuc chuong trinh");
		printf("\n\n Chuc nang ban chon: ");
		scanf_s("%d", &chucnang);
		switch (chucnang)
		{
		case 1:
			printf("Creation of B-Tree for node %d\n", M);
			initBTree(bt);
			for (int i = 0; i < n; i++)
			{
				rutGonPhanSo(a[i]);
				key = a[i];
				insert(bt.Root, key);
				printf("B-Tree is added value %d/%d:\n", key.tuSo, key.mauSo);
				displayBTree(bt.Root, blanks);
				_getch();
			}
			printf("B-Tree is:\n");
			displayBTree(bt.Root, blanks);
			break;
		case 2:
			createbrtree_From_File(bt,n);

			printf("Btree is:\n");
			displayBTree(bt.Root, 0);
			break;
		case 3:
			printf("\n Duyet cay theo thu tu tu nho den lon ");
			traverse(bt.Root);
			break;
		case 4:
			printf("Enter the key want to delete: ");
			scanf("%d%d", &key.tuSo, &key.mauSo);
			deleteNode(bt.Root, key);
			break;
		case 5:
			printf("Enter the key want to search: ");
			scanf("%d%d", &key.tuSo, &key.mauSo);
			search(bt.Root, key);
			break;
		case 6:
			printf("Enter the key want to insert: ");
			scanf("%d%d", &key.tuSo, &key.mauSo);
			insert(bt.Root, key);
			break;
		}
	} while (chucnang != 0);
	_getch();
}/*End of main()*/

//===============================================================
int timUCLN(int a, int b)
{
	a = abs(a);
	b = abs(b);
	if (a == 0 || b == 0) return 1;
	while (a != b)
	{
		if (a > b) a -= b;
		else b -= a;
	}
	return a; //Hoặc b
}
//===============================================================
void rutGonPhanSo(ItemType &p)
{
	int ucln = timUCLN(p.tuSo, p.mauSo);
	p.tuSo /= ucln;
	p.mauSo /= ucln;
}
//===============================================================
int soSanhPhanSo(ItemType p1, ItemType p2)
{
	rutGonPhanSo(p1);
	rutGonPhanSo(p2);

	if (p1.tuSo == p2.tuSo && p1.mauSo == p2.mauSo)  //nếu (p1 == p2)
		return 0;

	double gt = p1.tuSo*p2.mauSo - p1.mauSo*p2.tuSo;
	if (gt > 0)
		return 1;	//phân số 1 lớn hơn phân số 2 ( p1 > p2 )
	else
		return -1;	//phân số 1 nhỏ hơn phân số 2  ( p1 < p2 )
}
//===============================================================
ItemType congPhanSo(ItemType p1, ItemType p2)
{
	ItemType kq = { 0, 1 };
	kq.tuSo = p1.tuSo*p2.mauSo + p1.mauSo*p2.tuSo;
	kq.mauSo = p1.mauSo*p2.mauSo;
	rutGonPhanSo(kq);
	return kq;
}

NodePtr createBNode(NodePtr root, ItemType upKey, NodePtr newNode)
{
	NodePtr p = new BNode;
	if (p == NULL)
	{
		printf("\nKhong the cap phat nut moi!");
		_getch();
		return NULL;
	}
	p->numTree = 1;
	p->Keys[0] = upKey;
	p->Branch[0] = root;
	p->Branch[1] = newNode;
	return p;
}

void initBTree(BTree &bt)
{
	bt.Root = NULL;
}
void insert(NodePtr &root, ItemType key)
{
	NodePtr newNode;
	ItemType upKey;
	KeyStatus result;
	result = insertNode(root, key, &upKey, &newNode);
	if (result == Duplicate)
		printf("Key already available\n");
	else if (result == InsertIt)
	{
		root = createBNode(root, upKey, newNode);
	}/*End of if */
}/*End of insert()*/

KeyStatus insertNode(NodePtr pCurrent, ItemType key, ItemType *upKey, NodePtr* newNode)
{
	NodePtr newPtr, lastPtr;
	int pos, i, numTree, splitPos;
	ItemType newKey, lastKey;
	KeyStatus result;
	if (pCurrent == NULL)
	{
		*newNode = NULL;
		*upKey = key;
		return InsertIt;
	}
	numTree = pCurrent->numTree;
	pos = searchPosition(key, pCurrent->Keys, numTree);
	//if (pos < numTree && key == pCurrent->Keys[pos])
	if (pos < numTree && soSanhPhanSo(key, pCurrent->Keys[pos]) == 0)
		return Duplicate;
	result = insertNode(pCurrent->Branch[pos], key, &newKey, &newPtr);
	if (result != InsertIt)
		return result;
	/*If Keys in node is less than M-1 where M is order of B tree*/
	if (numTree < M - 1)
	{
		pos = searchPosition(newKey, pCurrent->Keys, numTree);
		/*Shifting the key and pointer right for inserting the new key*/
		for (i = numTree; i > pos; i--)
		{
			pCurrent->Keys[i] = pCurrent->Keys[i - 1];
			pCurrent->Branch[i + 1] = pCurrent->Branch[i];
		}
		/*Key is inserted at exact location*/
		pCurrent->Keys[pos] = newKey;
		pCurrent->Branch[pos + 1] = newPtr;
		++pCurrent->numTree; /*incrementing the number of Keys in node*/
		return Success;
	}/*End of if */
	/*If Keys in nodes are maximum and position of node to be inserted is last*/
	if (pos == M - 1)
	{
		lastKey = newKey;
		lastPtr = newPtr;
	}
	else /*If Keys in node are maximum and position of node to be inserted is not last*/
	{
		lastKey = pCurrent->Keys[M - 2];
		lastPtr = pCurrent->Branch[M - 1];
		for (i = M - 2; i > pos; i--)
		{
			pCurrent->Keys[i] = pCurrent->Keys[i - 1];
			pCurrent->Branch[i + 1] = pCurrent->Branch[i];
		}
		pCurrent->Keys[pos] = newKey;
		pCurrent->Branch[pos + 1] = newPtr;
	}
	splitPos = (M - 1) / 2;
	(*upKey) = pCurrent->Keys[splitPos];

	(*newNode) = new BNode;/*Right node after split*/
	pCurrent->numTree = splitPos; /*No. of Keys for left splitted node*/
	(*newNode)->numTree = M - 1 - splitPos; /*No. of Keys for right splitted node*/
	for (i = 0; i < (*newNode)->numTree; i++)
	{
		(*newNode)->Branch[i] = pCurrent->Branch[i + splitPos + 1];
		if (i < (*newNode)->numTree - 1)
			(*newNode)->Keys[i] = pCurrent->Keys[i + splitPos + 1];
		else
			(*newNode)->Keys[i] = lastKey;
	}
	(*newNode)->Branch[(*newNode)->numTree] = lastPtr;
	return InsertIt;
}/*End of insertNode()*/

void showBTreeNode(NodePtr pCurrent, int pos)
{
	printf("%4d/%d", pCurrent->Keys[pos].tuSo, pCurrent->Keys[pos].mauSo);
}

void displayBTree(NodePtr pRoot, int blanks) {
	if (pRoot) {
		int i;
		for (i = 1; i <= blanks; i++)
			printf(" ");
		for (i = 0; i < pRoot->numTree; i++)
			showBTreeNode(pRoot, i);
		printf("\n");
		for (i = 0; i <= pRoot->numTree; i++)
			displayBTree(pRoot->Branch[i], blanks);
	}/*End of if*/
}/*End of displayBTree()*/

int searchPosition(ItemType key, ItemType *keyArray, int numTree)
{
	int pos = 0;
	while (pos < numTree && soSanhPhanSo(key, keyArray[pos]) > 0)
		pos++;
	return pos;
}/*End of searchPosition()*/

NodePtr searchNode(NodePtr root, ItemType key)
{
	int pos, numTree;
	NodePtr pCurrent = root;
	while (pCurrent)
	{
		numTree = pCurrent->numTree;
		pos = searchPosition(key, pCurrent->Keys, numTree);
		if (pos < numTree && soSanhPhanSo(key, pCurrent->Keys[pos]) == 0)
		{
			return pCurrent;
		}
		pCurrent = pCurrent->Branch[pos];
	}
	return NULL;
}/*End of search()*/

void search(NodePtr root, ItemType key)
{
	int pos, i, numTree;
	NodePtr pCurrent = root;
	printf("Search path:\n");
	while (pCurrent)
	{
		numTree = pCurrent->numTree;
		for (i = 0; i < pCurrent->numTree; i++)
			showBTreeNode(pCurrent, i);
		printf("\n");
		pos = searchPosition(key, pCurrent->Keys, numTree);
		if (pos < numTree && soSanhPhanSo(key, pCurrent->Keys[pos]) == 0)
		{
			printf("Key %d/%d found in position %d of last dispalyed node\n", key.tuSo, key.mauSo, pos);
			return;
		}
		pCurrent = pCurrent->Branch[pos];
	}
	printf("Key %d/%d is not available\n", key.tuSo, key.mauSo);
}/*End of search()*/

void deleteNode(NodePtr &root, ItemType key)
{
	NodePtr upRoot;
	KeyStatus result;
	result = remove(root, root, key);
	switch (result)
	{
	case SearchFailure:
		printf("Key %d is not available\n", key);
		break;
	case LessKeys:
		upRoot = root;
		root = root->Branch[0];
		free(upRoot);
		printf("\nB-Tree after removing the %d value:\n", key);
		displayBTree(root, 0);
		break;
	case Success:
		printf("\nB-Tree after removing the %d value:\n", key);
		displayBTree(root, 0);
		break;
	}/*End of switch*/
}/*End of delnode()*/

KeyStatus remove(NodePtr &root, NodePtr pCurrent, ItemType key)
{
	int pos, i, pivot, numTree, min;
	ItemType *keyArray;
	KeyStatus result;
	NodePtr *Branch, leftPtr, rightPtr;

	if (pCurrent == NULL)
		return SearchFailure;
	/*Assigns values of node*/
	numTree = pCurrent->numTree;
	keyArray = pCurrent->Keys;
	Branch = pCurrent->Branch;
	min = (M - 1) / 2;/*Minimum number of Keys*/

	pos = searchPosition(key, keyArray, numTree);
	if (Branch[0] == NULL)
	{
		if (pos == numTree && soSanhPhanSo(key, keyArray[pos]) < 0)
			return SearchFailure;
		/*Shift Keys and pointers left*/
		for (i = pos + 1; i < numTree; i++)
		{
			keyArray[i - 1] = keyArray[i];
			Branch[i] = Branch[i + 1];
		}
		return --pCurrent->numTree >= (pCurrent == root ? 1 : min) ? Success : LessKeys;
	}/*End of if */

	if (pos < numTree && soSanhPhanSo(key, keyArray[pos]) == 0)
	{
		NodePtr qp = Branch[pos], qp1;
		int nkey;
		while (1)
		{
			nkey = qp->numTree;
			qp1 = qp->Branch[nkey];
			if (qp1 == NULL)
				break;
			qp = qp1;
		}/*End of while*/
		keyArray[pos] = qp->Keys[nkey - 1];
		qp->Keys[nkey - 1] = key;
	}/*End of if */
	result = remove(root, Branch[pos], key);
	if (result != LessKeys)
		return result;

	if (pos > 0 && Branch[pos - 1]->numTree > min)
	{
		pivot = pos - 1; /*pivot for left and right node*/
		leftPtr = Branch[pivot];
		rightPtr = Branch[pos];
		/*Assigns values for right node*/
		rightPtr->Branch[rightPtr->numTree + 1] = rightPtr->Branch[rightPtr->numTree];
		for (i = rightPtr->numTree; i > 0; i--)
		{
			rightPtr->Keys[i] = rightPtr->Keys[i - 1];
			rightPtr->Branch[i] = rightPtr->Branch[i - 1];
		}
		rightPtr->numTree++;
		rightPtr->Keys[0] = keyArray[pivot];
		rightPtr->Branch[0] = leftPtr->Branch[leftPtr->numTree];
		keyArray[pivot] = leftPtr->Keys[--leftPtr->numTree];
		return Success;
	}/*End of if */
	if (pos < numTree && Branch[pos + 1]->numTree > min)
	{
		pivot = pos; /*pivot for left and right node*/
		leftPtr = Branch[pivot];
		rightPtr = Branch[pivot + 1];
		/*Assigns values for left node*/
		leftPtr->Keys[leftPtr->numTree] = keyArray[pivot];
		leftPtr->Branch[leftPtr->numTree + 1] = rightPtr->Branch[0];
		keyArray[pivot] = rightPtr->Keys[0];
		leftPtr->numTree++;
		rightPtr->numTree--;
		for (i = 0; i < rightPtr->numTree; i++)
		{
			rightPtr->Keys[i] = rightPtr->Keys[i + 1];
			rightPtr->Branch[i] = rightPtr->Branch[i + 1];
		}/*End of for*/
		rightPtr->Branch[rightPtr->numTree] = rightPtr->Branch[rightPtr->numTree + 1];
		return Success;
	}/*End of if */

	if (pos == numTree)
		pivot = pos - 1;
	else
		pivot = pos;

	leftPtr = Branch[pivot];
	rightPtr = Branch[pivot + 1];
	/*merge right node with left node*/
	leftPtr->Keys[leftPtr->numTree] = keyArray[pivot];
	leftPtr->Branch[leftPtr->numTree + 1] = rightPtr->Branch[0];
	for (i = 0; i < rightPtr->numTree; i++)
	{
		leftPtr->Keys[leftPtr->numTree + 1 + i] = rightPtr->Keys[i];
		leftPtr->Branch[leftPtr->numTree + 2 + i] = rightPtr->Branch[i + 1];
	}
	leftPtr->numTree = leftPtr->numTree + rightPtr->numTree + 1;
	free(rightPtr); /*Remove right node*/
	for (i = pos + 1; i < numTree; i++)
	{
		keyArray[i - 1] = keyArray[i];
		Branch[i] = Branch[i + 1];
	}
	return --pCurrent->numTree >= (pCurrent == root ? 1 : min) ? Success : LessKeys;
}/*End of remove()*/
//void createbrtree_From_File(ItemType y[], int &n)
//{
//	FILE*f = fopen("input.txt", "rt");
//	fscanf(f, "%d", &n);
//	if (f == NULL) 
//		printf( "Loi doc file");
//	while (!feof(f))
//	{
//		for (int i = 0; i < n;i++)
//		fscanf(f, "%d/%d", &y[i].tuSo,&y[i].mauSo);
//	}
//	fclose(f);
//}
//void taoPhanSoFile(BTree &bt)
//{
//	int n;
//	ItemType y[31];
//	createbrtree_From_File(y, n);
//	for (int i = 0; i < n; i++)
//		insert(bt.Root, y[i]);
//}
void createbrtree_From_File(BTree &btree, int &n)
{
	initBTree(btree);
	ItemType  y;
	FILE*f = fopen("input.txt", "rt");
	fscanf(f, "%d", &n);
	if (f == NULL) printf( "Loi doc file");
	while (!feof(f))
	{
		fscanf(f, "%d/%d", &y.tuSo,&y.mauSo);
		insert(btree.Root, y);
	}
	fclose(f);
}
void traverse(NodePtr proot)
{
	int i, nt;
	if(proot==NULL)
		return;
	else
	{
		nt=proot->numTree;
		for(i=0;i<nt;i++)
		{
			traverse(proot->Branch[i]);           
			printf("%d/%d  ",proot->Keys[i].tuSo,proot->Keys[i].mauSo);
		}        
		traverse(proot->Branch[nt-1]);
	}
}