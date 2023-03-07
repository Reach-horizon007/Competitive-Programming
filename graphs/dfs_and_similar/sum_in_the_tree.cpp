#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/**
 * @brief https://codeforces.com/contest/1098/problem/A
 * 
 */

int n;
int vis[100003];
vector<int>adj[100003];
long long int ans[100003];
long long int s[100003];

bool dfs(int node,long long int sum)
{
	vis[node] = 1;
	if(s[node]==-1) ans[node] = 0;
	else if(s[node]!=-1)
	{
		long long int temp = s[node] - sum;
		if(temp<0) return false;
		else if(temp>0) ans[node] = temp;
	}
	bool var = true;
	for(int child : adj[node])
	{
		if(vis[child]==0)
		{
			bool var2 = dfs(child,sum+ans[node]);
			var = var && var2;
		}
	}
	return var;
}

void dfs2(int node,int h)
{	
	vis[node] = 1;
	if(h%2==0)
	{	
		if(adj[node].size()>2)
		{
			long long int var = 1000000009;
			for(int i : adj[node])
				if(vis[i]==0)
				var = min(var,ans[i]);
			ans[node] = var;
			for(int i : adj[node])
				if(vis[i]==0)
				ans[i]-=var;
		}
	}
	for(int child : adj[node])
		if(vis[child]==0) dfs2(child,h+1);
	return;
}


int main()
{
	cin>>n;
	for(int i=2;i<=n;i++)
	{
		int x;
		cin>>x;
		adj[x].push_back(i);
		adj[i].push_back(x);
	}
	for(int i=1;i<=n;i++) cin>>s[i];
	bool var = dfs(1,0);
	if(var==false) cout<<-1;
	else if(var==true)
	{	
		for(int i=1;i<=n;i++) vis[i]=0;
		dfs2(1,1);
		long long int p = 0;
		for(int i=1;i<=n;i++)
		{ 
			p+=ans[i];
		}
		cout<<p;
	} 

}