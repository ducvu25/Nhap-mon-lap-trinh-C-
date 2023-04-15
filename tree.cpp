#include <stdio.h>
#include <math.h>
 
typedef struct Node
{
    int data;
    Node* left;
    Node* right;
} node_t;
 
 
 
void Free( node_t* root )
{
    if ( root == NULL )
        return;
 
    Free( root->left );
    Free( root->right );
    delete( root );
}
 // const int hoac con tro --> se khong thay doi gia tri bien
 //trong qua trinh chay hoac con tro co dinh chi tro toi 1 doi
 //tuong duy nhat
int LeftOf( const int value, const node_t* root )
{
    // Neu muon c�y BST cho phep gia tri trung --> dong code 2
    return value < root->data;
//    return value <= root->data;
}
 
int RightOf( const int value, const node_t* root )
{
    return value > root->data;
}
 
node_t* Insert( node_t* root, const int value )
{
    if ( root == NULL )
    {
        node_t* node = new node_t;
        node->left = NULL;
        node->right = NULL;
        node->data = value;
        return node;
    }
    if ( LeftOf( value, root ) )
        root->left = Insert( root->left, value );
    else if ( RightOf( value, root ) )
        root->right = Insert( root->right, value );
    return root;
}
 
bool Search( const node_t *root, int value )
{
    if ( root == NULL )
        return false;
    if(root->data == value){
        return true;
    }else if ( LeftOf( value, root ) ){
        return Search( root->left, value );
    }else if( RightOf( value, root ) ){
        return Search( root->right, value );
    }
}
 
int LeftMostValue( const node_t *root )
{
    while ( root->left != NULL )
        root = root->left;
    return root->data;
}

int RightMostValue( const node_t *root )
{
    while ( root->right != NULL )
        root = root->right;
    return root->data;
}
 
node_t* Delete( node_t* root, int value )
{
    if ( root == NULL )
        return root;
    if ( LeftOf( value, root ) )
        root->left = Delete( root->left, value );
    else if ( RightOf( value, root ) )
        root->right = Delete( root->right, value );
    else
    {
        // root->data == value, delete this node
        if ( root->left == NULL )
        {
            node_t* newRoot = root->right;
            delete( root );
            return newRoot;
        }
        if ( root->right == NULL )
        {
            node_t* newRoot = root->left;
            delete( root );
            return newRoot;
        }
        root->data = LeftMostValue( root->right );
        root->right = Delete( root->right, root->data );
    }
    return root;
} 
void PreOrder(node_t* root){
    if(root != NULL)
    {
        printf("%d ", root->data);
        PreOrder(root->left);
        PreOrder(root->right);
    }
}
int KiemTraNT(int x){
	for(int i=2; i<=sqrt(x); i++)
		if(x % i == 0)
			return 0;
	return x > 1;
}
//void Xoa_PrimeNumber(node_t* root, int data)
//{
//    if(root != NULL );
//    {
//        if (KiemTraNT(root->data) == 1)
//        {
//            Delete(root, data);
//        }
//        else
//        {
//            printf("%d ", root ->data);
//        }
//        Xoa_PrimeNumber( root ->left , data);
//        Xoa_PrimeNumber( root -> right, data);
//
//    }
//}
void Xoa(node_t* root){
	if(root != NULL){
		if(KiemTraNT(root->data) == 1)
			Delete(root, root->data);
		else{
			printf("%d ", root ->data);
			Xoa( root ->left);
        	Xoa( root -> right);
		}
	}
}


 int main()
{
    node_t* root = NULL;
 
    root = Insert( root, 10 );
    root = Insert( root, 6 );
    root = Insert( root, 15 );
    root = Insert( root, 2 );
    root = Insert( root, 7 );
    root = Insert( root, 12 );
    root = Insert( root, 33 );
    root = Insert( root, 14 );
    root = Insert( root, 40 );
    
    printf("\nDuyet preorder : ");
    PreOrder(root);
    printf("\nSau khi xoa so nguyen to: ");
    Xoa(root);
    return 0;
}
