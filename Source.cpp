//#include "BTree.h"
//
//void main()
//{
//	BTree bt;
//	initBTree(bt);
//	ItemType a[] = { 1, 12, 8, 2, 25, 5, 14, 28, 17, 7, 52, 16, 48, 68, 3, 26, 29, 53, 55, 45 };
//	int n = 20;
//	ItemType key;
//	int blanks = 0;
//	int minnode, maxnode, dem=0, sum=0;
//
//	int chucnang;
//	do
//	{
//		printf("\n\n CHUONG TRINH HIEN THUC CAY NHIEU NHANH");
//		printf("\n\n Cac chuc nang chinh cua chuong trinh");
//		printf("\n 1. Tao cay tu mang");
//		printf("\n 2. Tao cay tu mang ngau nhien");
//		printf("\n 3. Tao cay tu file");
//		printf("\n 4. Them mot vai phan tu vao cay");
//		printf("\n 5. Xoa phan tu trong cay");
//		printf("\n 6. Tim kiem phan tu trong cay");
//		printf("\n 7. Xuat ra cac nut chua it gia tri nhat");
//		printf("\n 8. Xuat ra cac nut chua nhieu gia tri nhat");
//		printf("\n 9. Dem cac nut la so nguyen to");
//		printf("\n 10. Tong cac nut tren cay");
//		printf("\n 0. Ket thuc chuong trinh");
//		printf("\n\n Chuc nang ban chon: ");
//		scanf_s("%d", &chucnang);
//		switch (chucnang)
//		{
//		case 1:
//		/*	printf("Creation of B tree for node: \n");
//			scanf_s("%d", &n);
//			initBTree(bt);
//			for (int i = 0; i < n; i++)
//			{
//			key = a[i];
//			insert(bt.Root, key);
//			}
//			printf("Btree is:\n");
//			displayBTree(bt.Root, 0);*/
//
//			printf("Creation of B-Tree for node %d\n", M);
//			initBTree(bt);
//			for (int i = 0; i < n; i++) {
//			key = a[i];
//			insert(bt.Root, key);
//			printf("B-Tree is added value %d:\n", key);
//			displayBTree(bt.Root,blanks);
//			_getch();
//			}
//
//			printf("B-Tree is:\n");
//			displayBTree(bt.Root,blanks);
//			break;
//		case 2:
//			TaoCayTuDong(bt);
//
//			printf("Btree is:\n");
//			displayBTree(bt.Root, 0);
//			break;
//		case 3:
//			createbrtree_From_File(bt,n);
//
//			printf("Btree is:\n");
//			displayBTree(bt.Root, 0);
//			break;
//		case 4:
//		/*	printf("Creation of B-Tree for node %d\n", M);
//			initBTree(bt);
//			for (int i = 0; i < n; i++) {
//				key = a[i];
//				insert(bt.Root, key);
//				printf("B-Tree is added value %d:\n", key);
//				displayBTree(bt.Root,blanks);
//				_getch();
//			}
//
//			printf("B-Tree is:\n");
//			displayBTree(bt.Root,blanks);*/
//			printf("Enter the key want to insert: ");
//			scanf_s("%d", &key);
//			insert(bt.Root, key);
//			printf("B-Tree is added value %d:\n", key);
//			displayBTree(bt.Root, blanks);
//			break;
//		case 5:
//			printf("Enter the key want to delete: ");
//			scanf_s("%d", &key);
//			deleteNode(bt.Root, key);
//			break;
//		case 6:
//			printf("Enter the key want to search: ");
//			scanf_s("%d", &key);
//			search(bt.Root, key);
//			break;
//		case 7:
//			minnode = bt.Root->numTree;
//			nodeMinNumTree(bt.Root, minnode);
//			printf("\nNode co so gia tri it nhat la: %d", minnode);
//			printf("\nCac node co so gia tri it nhat la:\n");
//			displayNodeMinNumTree(bt.Root, minnode);
//			break;
//		case 8:
//		    maxnode = bt.Root->numTree;
//			nodeMaxNumTree(bt.Root, maxnode);
//			printf("\nNode co so gia tri it nhat la: %d", maxnode);
//			printf("\nCac node co so gia tri it nhat la:\n");
//			displayNodeMaxNumTree(bt.Root, maxnode);
//			break;
//		case 9:
//			printf("\nCac nut la so nguyen to: %d", count_TNode_Is_PrimeNumber(bt.Root, dem));
//			break;
//	   case 10:
//			printf("Tong cac nut tren cay:%d", sumNode(bt.Root, sum));
//			break;
//		}
//	} while (chucnang != 0);
//	_getch();
//}/*End of main()*/
//
////
//void TaoCayTuDong(BTree &bt)
//{
//	int n = 50 ;
//	do
//	{
//		printf("Cho biet nut cua cay: ");
//		scanf_s("%d", &n);
//	} while (n >= 50);
//	int* a = new int[n];
//	initBTree(bt);
//	srand((unsigned)time(NULL));
//	for (int i = 0; i <=n; i++)
//	{
//		a[i] = (rand() % 100);
//		insert(bt.Root, a[i]);
//	}
//}
//void createbrtree_From_File(BTree &btree, int &n)
//{
//	initBTree(btree);
//	int  y;
//	FILE*f = fopen("INPUTBT.txt", "rt");
//	fscanf(f, "%d", &n);
//	if (f == NULL) printf( "Loi doc file");
//	while (!feof(f))
//	{
//		fscanf(f, "%d", &y);
//		insert(btree.Root, y);
//	}
//	fclose(f);
//}
////int check_PrimeNumber(ItemType x)
////{
////	if (x < 1) 
////		return 0;
////	for (int i = 2; i <= x-1; i++) {
////		if (x % i == 0) {
////			return 0;
////		}
////	}
////	return 1;
////}
////int count_TNode_Is_PrimeNumber(NodePtr root)
////{
////	if (!root)  return 0;
////	int nl = count_TNode_Is_PrimeNumber(root->Branch[M]);
////	if (check_PrimeNumber(root->Keys[M-1]) == 1)
////		return nl + 1;
////	return nl;
////}
//
////
//void initBTree(BTree &bt)
//{
//	bt.Root = NULL;
//}
//void insert(NodePtr &root, ItemType key)
//{
//	NodePtr newNode;
//	ItemType upKey;
//	KeyStatus result;
//	result = insertNode(root, key, &upKey, &newNode);
//	if (result == Duplicate)
//		printf("Key already available\n");
//	if (result == InsertIt)
//	{
//		NodePtr upRoot = root;
//		root = new BNode;
//		root->numTree = 1;
//		root->Keys[0] = upKey;
//		root->Branch[0] = upRoot;
//		root->Branch[1] = newNode;
//	}/*End of if */
//}/*End of insert()*/
//
//KeyStatus insertNode(NodePtr pCurrent, ItemType key, ItemType *upKey, NodePtr* newNode)
//{
//	NodePtr newPtr, lastPtr;
//	int pos, i, numTree, splitPos;
//	ItemType newKey, lastKey;
//	KeyStatus result;
//	if (pCurrent == NULL)
//	{
//		*newNode = NULL;
//		*upKey = key;
//		return InsertIt;
//	}
//	numTree = pCurrent->numTree;
//	pos = searchPosition(key, pCurrent->Keys, numTree);
//	if (pos < numTree && key == pCurrent->Keys[pos])
//		return Duplicate;
//	result = insertNode(pCurrent->Branch[pos], key, &newKey, &newPtr);
//	if (result != InsertIt)
//		return result;
//	/*If Keys in node is less than M-1 where M is order of B tree*/
//	if (numTree < M - 1)
//	{
//		pos = searchPosition(newKey, pCurrent->Keys, numTree);
//		/*Shifting the key and pointer right for inserting the new key*/
//		for (i = numTree; i > pos; i--)
//		{
//			pCurrent->Keys[i] = pCurrent->Keys[i - 1];
//			pCurrent->Branch[i + 1] = pCurrent->Branch[i];
//		}
//		/*Key is inserted at exact location*/
//		pCurrent->Keys[pos] = newKey;
//		pCurrent->Branch[pos + 1] = newPtr;
//		++pCurrent->numTree; /*incrementing the number of Keys in node*/
//		return Success;
//	}/*End of if */
//	/*If Keys in nodes are maximum and position of node to be inserted is last*/
//	if (pos == M - 1)
//	{
//		lastKey = newKey;
//		lastPtr = newPtr;
//	}
//	else /*If Keys in node are maximum and position of node to be inserted is not last*/
//	{
//		lastKey = pCurrent->Keys[M - 2];
//		lastPtr = pCurrent->Branch[M - 1];
//		for (i = M - 2; i > pos; i--)
//		{
//			pCurrent->Keys[i] = pCurrent->Keys[i - 1];
//			pCurrent->Branch[i + 1] = pCurrent->Branch[i];
//		}
//		pCurrent->Keys[pos] = newKey;
//		pCurrent->Branch[pos + 1] = newPtr;
//	}
//	splitPos = (M - 1) / 2;
//	(*upKey) = pCurrent->Keys[splitPos];
//
//	(*newNode) = new BNode;/*Right node after split*/
//	pCurrent->numTree = splitPos; /*No. of Keys for left splitted node*/
//	(*newNode)->numTree = M - 1 - splitPos; /*No. of Keys for right splitted node*/
//	for (i = 0; i < (*newNode)->numTree; i++)
//	{
//		(*newNode)->Branch[i] = pCurrent->Branch[i + splitPos + 1];
//		if (i < (*newNode)->numTree - 1)
//			(*newNode)->Keys[i] = pCurrent->Keys[i + splitPos + 1];
//		else
//			(*newNode)->Keys[i] = lastKey;
//	}
//	(*newNode)->Branch[(*newNode)->numTree] = lastPtr;
//	return InsertIt;
//}/*End of insertNode()*/
//
//void displayBTree(NodePtr pRoot, int blanks) {
//	if (pRoot) {
//		int i;
//		for (i = 1; i <= blanks; i++)
//			printf(" ");
//		for (i = 0; i < pRoot->numTree; i++)
//			printf("%d ", pRoot->Keys[i]);
//		printf("\n");
//		for (i = 0; i <= pRoot->numTree; i++)
//			displayBTree(pRoot->Branch[i], blanks + 10);
//	}/*End of if*/
//}/*End of displayBTree()*/
//
//int searchPosition(ItemType key, ItemType *keyArray, int numTree)
//{
//	int pos = 0;
//	while (pos < numTree && key > keyArray[pos])
//		pos++;
//	return pos;
//}/*End of searchPosition()*/
//
//NodePtr searchNode(NodePtr root, ItemType key)
//{
//	int pos, numTree;
//	NodePtr pCurrent = root;
//	while (pCurrent)
//	{
//		numTree = pCurrent->numTree;
//		pos = searchPosition(key, pCurrent->Keys, numTree);
//		if (pos < numTree && key == pCurrent->Keys[pos])
//		{
//			return pCurrent;
//		}
//		pCurrent = pCurrent->Branch[pos];
//	}
//	return NULL;
//}/*End of search()*/
//
//void search(NodePtr root, ItemType key)
//{
//	int pos, i, numTree;
//	NodePtr pCurrent = root;
//	printf("Search path:\n");
//	while (pCurrent)
//	{
//		numTree = pCurrent->numTree;
//		for (i = 0; i < pCurrent->numTree; i++)
//			printf(" %d", pCurrent->Keys[i]);
//		printf("\n");
//		pos = searchPosition(key, pCurrent->Keys, numTree);
//		if (pos < numTree && key == pCurrent->Keys[pos])
//		{
//			printf("Key %d found in position %d of last dispalyed node\n", key, pos);
//			return;
//		}
//		pCurrent = pCurrent->Branch[pos];
//	}
//	printf("Key %d is not available\n", key);
//}/*End of search()*/
//
//void deleteNode(NodePtr &root, ItemType key)
//{
//	NodePtr upRoot;
//	KeyStatus result;
//	result = remove(root, root, key);
//	switch (result)
//	{
//	case SearchFailure:
//		printf("Key %d is not available\n", key);
//		break;
//	case LessKeys:
//		upRoot = root;
//		root = root->Branch[0];
//		free(upRoot);
//		printf("\nBtree after removing the %d value:\n", key);
//		displayBTree(root, 0);
//		break;
//	case Success:
//		printf("\nBtree after removing the %d value:\n", key);
//		displayBTree(root, 0);
//		break;
//	}/*End of switch*/
//}/*End of delnode()*/
//
//KeyStatus remove(NodePtr &root, NodePtr pCurrent, ItemType key)
//{
//	int pos, i, pivot, numTree, min;
//	ItemType *keyArray;
//	KeyStatus result;
//	NodePtr *Branch, leftPtr, rightPtr;
//
//	if (pCurrent == NULL)
//		return SearchFailure;
//	/*Assigns values of node*/
//	numTree = pCurrent->numTree;
//	keyArray = pCurrent->Keys;
//	Branch = pCurrent->Branch;
//	min = (M - 1) / 2;/*Minimum number of Keys*/
//
//	pos = searchPosition(key, keyArray, numTree);
//	if (Branch[0] == NULL)
//	{
//		if (pos == numTree || key < keyArray[pos])
//			return SearchFailure;
//		/*Shift Keys and pointers left*/
//		for (i = pos + 1; i < numTree; i++)
//		{
//			keyArray[i - 1] = keyArray[i];
//			Branch[i] = Branch[i + 1];
//		}
//		return --pCurrent->numTree >= (pCurrent == root ? 1 : min) ? Success : LessKeys;
//	}/*End of if */
//
//	if (pos < numTree && key == keyArray[pos])
//	{
//		NodePtr qp = Branch[pos], qp1;
//		ItemType nkey;
//		while (1)
//		{
//			nkey = qp->numTree;
//			qp1 = qp->Branch[nkey];
//			if (qp1 == NULL)
//				break;
//			qp = qp1;
//		}/*End of while*/
//		keyArray[pos] = qp->Keys[nkey - 1];
//		qp->Keys[nkey - 1] = key;
//	}/*End of if */
//	result = remove(root, Branch[pos], key);
//	if (result != LessKeys)
//		return result;
//
//	if (pos > 0 && Branch[pos - 1]->numTree > min)
//	{
//		pivot = pos - 1; /*pivot for left and right node*/
//		leftPtr = Branch[pivot];
//		rightPtr = Branch[pos];
//		/*Assigns values for right node*/
//		rightPtr->Branch[rightPtr->numTree + 1] = rightPtr->Branch[rightPtr->numTree];
//		for (i = rightPtr->numTree; i > 0; i--)
//		{
//			rightPtr->Keys[i] = rightPtr->Keys[i - 1];
//			rightPtr->Branch[i] = rightPtr->Branch[i - 1];
//		}
//		rightPtr->numTree++;
//		rightPtr->Keys[0] = keyArray[pivot];
//		rightPtr->Branch[0] = leftPtr->Branch[leftPtr->numTree];
//		keyArray[pivot] = leftPtr->Keys[--leftPtr->numTree];
//		return Success;
//	}/*End of if */
//	if (pos < numTree && Branch[pos + 1]->numTree > min)
//	{
//		pivot = pos; /*pivot for left and right node*/
//		leftPtr = Branch[pivot];
//		rightPtr = Branch[pivot + 1];
//		/*Assigns values for left node*/
//		leftPtr->Keys[leftPtr->numTree] = keyArray[pivot];
//		leftPtr->Branch[leftPtr->numTree + 1] = rightPtr->Branch[0];
//		keyArray[pivot] = rightPtr->Keys[0];
//		leftPtr->numTree++;
//		rightPtr->numTree--;
//		for (i = 0; i < rightPtr->numTree; i++)
//		{
//			rightPtr->Keys[i] = rightPtr->Keys[i + 1];
//			rightPtr->Branch[i] = rightPtr->Branch[i + 1];
//		}/*End of for*/
//		rightPtr->Branch[rightPtr->numTree] = rightPtr->Branch[rightPtr->numTree + 1];
//		return Success;
//	}/*End of if */
//
//	if (pos == numTree)
//		pivot = pos - 1;
//	else
//		pivot = pos;
//
//	leftPtr = Branch[pivot];
//	rightPtr = Branch[pivot + 1];
//	/*merge right node with left node*/
//	leftPtr->Keys[leftPtr->numTree] = keyArray[pivot];
//	leftPtr->Branch[leftPtr->numTree + 1] = rightPtr->Branch[0];
//	for (i = 0; i < rightPtr->numTree; i++)
//	{
//		leftPtr->Keys[leftPtr->numTree + 1 + i] = rightPtr->Keys[i];
//		leftPtr->Branch[leftPtr->numTree + 2 + i] = rightPtr->Branch[i + 1];
//	}
//	leftPtr->numTree = leftPtr->numTree + rightPtr->numTree + 1;
//	free(rightPtr); /*Remove right node*/
//	for (i = pos + 1; i < numTree; i++)
//	{
//		keyArray[i - 1] = keyArray[i];
//		Branch[i] = Branch[i + 1];
//	}
//	return --pCurrent->numTree >= (pCurrent == root ? 1 : min) ? Success : LessKeys;
//}/*End of remove()*/
//void nodeMinNumTree(NodePtr Root, int &minnode)
//{
//	if (Root)
//	{
//		if (minnode > Root->numTree)
//			minnode = Root->numTree;
//		for (int i = 0; i <= Root->numTree; i++)
//		{
//			nodeMinNumTree(Root->Branch[i], minnode);
//		}
//	}
//}
//void displayNodeMinNumTree(NodePtr Root, int min)
//{
//	if (Root)
//	{
//		if (min == Root->numTree)
//		{
//			for (int i = 0; i < Root->numTree; i++)
//				printf("%d  ", Root->Keys[i]);
//			printf("\n");
//		}
//		for (int i = 0; i <= Root->numTree; i++)
//		{
//			displayNodeMinNumTree(Root->Branch[i], min);
//		}
//	}
//}
//void nodeMaxNumTree(NodePtr Root, int &maxnode)
//{
//	if (Root)
//	{
//		if (maxnode < Root->numTree)
//			maxnode = Root->numTree;
//		for (int i = 0; i <= Root->numTree; i++)
//		{
//			nodeMaxNumTree(Root->Branch[i], maxnode);
//		}
//	}
//}
//void displayNodeMaxNumTree(NodePtr Root, int max)
//{
//	if (Root)
//	{
//		if (max == Root->numTree)
//		{
//			for (int i = 0; i < Root->numTree; i++)
//				printf("%d  ", Root->Keys[i]);
//			printf("\n");
//		}
//		for (int i = 0; i <= Root->numTree; i++)
//		{
//			displayNodeMinNumTree(Root->Branch[i], max);
//		}
//	}
//}
//int check_PrimeNumber(ItemType x)
//{
//	if (x < 1) return 0;
//	for (int i = 2; i <= x-1; i++) {
//		if (x % i == 0) 
//		{
//			return 0;
//		}
//	}
//	return 1;
//}
//int kiemTraNodeTo(int a[], int n)
//{
//	for (int i = 0; i < n;i++)
//	if (check_PrimeNumber(a[i]) == 0)
//		return 0;
//	return 1;
//}
//int count_TNode_Is_PrimeNumber(NodePtr root,int &dem)
//{
//	if (root)
//	{
//		if (kiemTraNodeTo(root->Keys, root->numTree))
//			dem++;
//		for (int i = 0; i < root->numTree; i++)
//			count_TNode_Is_PrimeNumber(root->Branch[i], dem);
//	}
//	return dem;
//}
//int sumNode(NodePtr root,int &sum)
//{
//	if (!root)  return 0;
//	for (int i = 0; i < root->numTree; i++)
//	{
//		sum += root->Keys[i];
//	}
//	for (int i = 0; i <= root->numTree; i++)
//	{
//		sumNode(root->Branch[i], sum);
//	}
//}