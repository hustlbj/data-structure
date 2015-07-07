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
	//p·Ç¿Õ£¬»òÕ»·Ç¿Õ 
	while (NULL != p || !sta.empty()) 
	{
		if (NULL != p) 
		{
			//Êä³ö¸ù½Úµã£¬¸ù½ÚµãÈëÕ»£¬±éÀú×ó×ÓÊ÷ 
			cout << p->value << " ";
			sta.push(p);
			p = p->left;		
		}
		else
		{
			//¸ù½Úµã³öÕ»£¬±éÀúÓÒ×ÓÊ÷ 
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

//å› å¼åˆ†è§£å‡½æ•°
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
//ä»Žå°åˆ°å¤§æŽ’åº
void sort(int *temp, int len)
{
	//pass
}

//ä¸»å‡½æ•°
int func(int n) {
	if (n <= 0)
		return -1;
	//ä¸´æ—¶å­˜æ”¾å› æ•°ï¼Œé•¿åº¦å¯å˜ã€‚ã€‚ã€‚ã€‚
	int temp[100];
	//è¾“å‡ºçš„ä½æ•°
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

