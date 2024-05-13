#include<bits/stdc++.h>
using namespace std;
using ll = long long;
struct Item
{
    int weight;
    int profit;
    double profit_per_weight;

    Item(int w, int p) : weight(w), profit(p), profit_per_weight(double (p/w)){}
};
bool compareitems(const Item &a , const Item &b)
{
    return  (double)a.profit_per_weight> (double)b.profit_per_weight;
}
int main()
{
  int n; cin>>n;
  int capacity; cin>>capacity;
  vector<Item> items;
  for (int i=0; i<n; i++)
  {
    int weight;
    int profit;
    cin>>weight>>profit;
    items.push_back(Item(weight, profit));
  }
  sort(items.begin(), items.end(), compareitems);

  double maxProfit = 0.0;

  for (int i =0; i<n; i++)
  {
    if (capacity <=0) break;
    int weightToAdd = min(items[i].weight, capacity);
    maxProfit += weightToAdd * items[i].profit_per_weight;
    capacity -= weightToAdd;
  }
  cout<<maxProfit<<endl;

}