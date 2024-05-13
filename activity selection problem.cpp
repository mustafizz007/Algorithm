#include<bits/stdc++.h>
using namespace std;
using ll = long long;
struct Activity
{
    int start;
    int finish;
};
bool compareFinishTime (const Activity &a, const Activity &b)
{
    return a.finish<b.finish;
}
int main()
{
  int n; cin>>n;
  vector <Activity> activities;
  for (int i=0; i<n; i++)
  {
    cin>>activities[i].start>>activities[i].finish;
  }
  sort(activities.begin(), activities.end(), compareFinishTime);
  int cnt =1;
  int pre_finish_time = activities[0].finish;
  for (int i=1; i<n; i++)
  {
    if (activities[i].start >= pre_finish_time)
    {
        cnt++;
        pre_finish_time = activities[i].finish;
    }
  }
  cout<<cnt<<endl;
}