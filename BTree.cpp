#include <iostream> 
#include <vector>
#include <stack>

using namespace std;

typedef struct TreeNode {
	int value;
	TreeNode* left;
	TreeNode* right;
} TNode;

void TraverseTreePreOrder(std::vector<int>& values, TreeNode* root) 
{
	stack<TreeNode*> sta;
	TreeNode* p = root;
	//p非空，或栈非空 
	while (NULL != p || !sta.empty()) 
	{
		if (NULL != p) 
		{
			//输出根节点，根节点入栈，遍历左子树 
			cout << p->value << " ";
			sta.push(p);
			p = p->left;		
		}
		else
		{
			//根节点出栈，遍历右子树 
			p = sta.top();
			sta.pop();
			p = p->right;
		}
	}
}

int main() {
	struct TreeNode nodes[3];
	nodes[0].value = 1;
	nodes[1].value = 2;
	nodes[2].value = 3;
	nodes[0].left = &nodes[1];
	nodes[0].right = &nodes[2];
	nodes[1].left = NULL;
	nodes[1].right = NULL;
	nodes[2].left = NULL;
	nodes[2].right = NULL;
	vector<int> values; 
	TraverseTreePreOrder(values, nodes);
	return 0;
}

//鍥犲紡鍒嗚В鍑芥暟
int division(int n) {
	int i = 9;
	while (i > 1) {
		if (n % i == 0)
			return i;
		i -= 1;
	}
	if (n < 10)
		return 1;
	return 0;
}
//浠庡皬鍒板ぇ鎺掑簭
void sort(int *temp, int len)
{
	//pass
}

//涓诲嚱鏁�
int func(int n) {
	if (n <= 0)
		return -1;
	//涓存椂瀛樻斁鍥犳暟锛岄暱搴﹀彲鍙樸�傘�傘�傘��
	int temp[100];
	//杈撳嚭鐨勪綅鏁�
	int len = 0;
	int factor;
	int i = 0;
	while ((factor = division(n)) != 0) {
		temp[len ++] = factor;
		n /= factor;
		if (factor == 1)
			break;
	}
	if (len == 0)
		return -1;
	sort(temp, len);
	while (i < len) {
		std::cout << temp[i ++] << std::endl;
	}
}

