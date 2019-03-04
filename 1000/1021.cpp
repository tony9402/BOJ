#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> vc;
vector<int>::iterator it;

//Binary_Search 함수를 직접 구현
//원형 큐를 직접 구현하지 않고
//1차원 벡터에서 itertor을 이용하여 원형 큐처럼 사용
//또한 벡터는 항상 오름차순으로 사용하니깐 binary_search가 가능
int Search(int x)
{
  int left, right;
  left = 0;
  right = vc.size();
  while(left<=right)
  {
    int mid=(left+right)/2;
    if(vc[mid]==x)return mid;
    else if(vc[mid]>x)right=mid-1;
    else left=mid+1;
  }
  return -1;
}

int main()
{
	int n, k, ans=0;
	cin >> n >> k;
	for(int i=1;i<=n;i++)
		vc.push_back(i);
  it=vc.begin();
  
  for(int i=0;i<k;i++)
  {
    int x;
    cin >> x;
    x = Search(x);
    int now = it-vc.begin();
    int left, right;
    if(now < x)
    {
      left=now+vc.size()-x;
      right=x-now;
    }
    else
    {
      left=now-x;
      right=x+vc.size()-now;
    }
    if(left<right)
    {
      ans+=left;
      while(left--)
      {
        if(it==vc.begin())
          it=vc.end();
        it--;
      }
    }
    else
    {
      ans+=right;
      while(right--)
      {
        it++;
        if(it==vc.end())
          it=vc.begin();
      }
    }
    it=vc.erase(it);
    if(it==vc.end())
      it=vc.begin();
  }
  cout << ans;

	return 0;
}
