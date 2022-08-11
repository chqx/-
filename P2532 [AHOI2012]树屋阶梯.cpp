// P2532 ���ݽ��� https://www.luogu.com.cn/problem/P2532
// ���������ǿ��������󣬻ᷢ�ָ߾��˳����鷳 
// ���ǿ��Բ�ȡ�ֽ����������������ֻ���ÿ����ݺ͸߾��˾Ϳ��� 
// ps:һ���������״��ͼ�ξ�ȥ���뿨������~~

#include<bits/stdc++.h>

typedef long long ll;
const int MX = 2000;

using namespace std;
int f[MX], ans[MX*100];

int n;

int qpow(int a,int b)
{
    int res=1;
    for(; b; b>>=1)
	{
        if(b&1)
			res = res*a;
        a *= a;
    }
    return res;
}

void mul(int x)
{
	int k = 0;
	
	for(int i=1; i<=ans[0]; i++)
	{
		ans[i] *= x;
		ans[i] += k;
		k = ans[i]/10;
		ans[i] %= 10;
	}
	
	while(k)
	{
		ans[++ans[0]] = k%10;
		k = k/10;
	}
}


int main()
{
	scanf("%d", &n);
	 
	for(int i=2; i<=n; i++)
	{
        int a = i+n, b = i;
        
        for(int j=2; j*j<=a; j++)
		{
            while(a%j == 0)
            {
            	f[j] ++;
				a /= j;
			}
				
        } 
        
        if(a>1) f[a]++;
        
        for(int j=2; j*j<=b; j++)
		{
            while(b%j == 0)
			{
				f[j] --;
				b /= j;
			}
        }
        
        if(b>1) f[b] --;
    }
    
    ans[0] = ans[1] = 1;
    
    for(int i=2; i<=n*2; i++)
	{
        if(f[i]==0) continue;
        
        int x = qpow(i, f[i]);
        mul(x);
    }
    
    for(int i=ans[0]; i>=1; --i)
	{
		printf("%d", ans[i]);
	}
	
	
	return 0;
} 
