#include <iostream>
using namespace std;
char tree[26][2];

void print_preorder(int a){
	cout<<(char)(a+65);
	if(tree[a][0] != '.')
	print_preorder((int)tree[a][0] - 65);
	if(tree[a][1] != '.')
	print_preorder((int)tree[a][1] - 65);
	return;
};
void print_inorder(int a){
	if(tree[a][0] != '.')
	print_inorder((int)tree[a][0] - 65);
	cout<<(char)(a+65);
	if(tree[a][1] != '.')
	print_inorder((int)tree[a][1] - 65);
	return;
};
void print_postorder(int a){
	if(tree[a][0] != '.')
	print_postorder((int)tree[a][0] - 65);
	if(tree[a][1] != '.')
	print_postorder((int)tree[a][1] - 65);
	cout<<(char)(a+65);
	return;
};

int main(int argc, char* argv[]) {
	int N;
	cin>> N;
	
	char parent;
	char left;
	char right;
	while(N--){
		cin>> parent >> left >> right;
		tree[(int)parent - 65][0] = left;
		tree[(int)parent - 65][1] = right;
	}
	print_preorder(0);cout<<endl;
	print_inorder(0);cout<<endl;
	print_postorder(0);
	return 0;
}