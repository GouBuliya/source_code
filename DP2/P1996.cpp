#include <bits/stdc++.h>
#define ll long long
#define pn putchar('\n')
#define mclear(a) memset(a, 0, sizeof a)
#define fls() fflush(stdout)
using namespace std;
int re()
{
	int x = 0, t = 1;
	char ch = getchar();
	while (ch > '9' || ch < '0')
	{
		if (ch == '-')
			t = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
		x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return x * t;
}
struct treenode
{
	string dsta;
	treenode *L_pointer;
	treenode *R_pointer;
} node[30];

// void bring_tree(int )
string _inor, _pre;
// 分别对应中序，和前序；
void bring_tree(string inor, string pre)
{
	if (pre.empty())
	{
		return;
	}
	char ch = pre[0];
	size_t pos = inor.find(ch);
	pre.erase(pre.begin());
	string lift_inor = inor.substr(0, pos);
	string right_inor = inor.substr(pos + 1);
	string lift_pre = pre.substr(0, pos);
	string right_pre = pre.substr(pos);
	bring_tree(lift_inor, lift_pre);
	bring_tree(right_inor, right_pre);
	printf("%c", ch);
}
signed main()
{
#ifndef ONLINE_JUDGE
	// freopen("in.txt", "r", stdin);
#endif
	cin >> _inor >> _pre;
	bring_tree(_inor,_pre);
	return 0;
}
