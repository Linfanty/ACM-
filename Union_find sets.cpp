// #include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
const int maxn = 1005;

int pre[maxn];

int find(int x) {
	return  x == pre[x] ? x : pre[x] = find(pre[x]); 
}

void join(int x, int y) {
	int px = find(x);
	int py = find(y);
	if( px != py )
		pre[px] = py;
}


int main() {
	int n, m;
	while( scanf("%d", &n) && n)
	{
		scanf("%d", &m);
		for(int i = 1; i <= n; i++)
			pre[i] = i;

		int u, v;
		for(int i = 1; i <= m; i++)
		{
			scanf("%d %d", &u, &v);
			join(u, v);
		}
		int cnt = -1;
		for(int i = 1; i <= n; i++)
			if( pre[i] == i)
				cnt++;
		printf("%d\n", cnt);
	}

}

