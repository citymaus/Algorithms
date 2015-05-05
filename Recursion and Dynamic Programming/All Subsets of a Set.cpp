/*
  Write a method to return all subsets of a set.
*/
#include <cstdio>
#include <vector>
using namespace std;

vector<vector<int>> getSubsets(vector<int> set, int index) 
{
  vector<vector<int>> allsubsets;
  if (set.size() == index) 
  { // Base case - add empty set
    vector<vector<int>> allsubsets;
    vector<int> emptysubset;
    allsubsets.push_back(emptysubset); // Empty set
  } 
  else 
  {
    allsubsets = getSubsets(set, index + 1);
    int item = set[index];
    vector<vector<int>> moresubsets;
    for (vector<vector<int>>::iterator subset = allsubsets.begin(); subset != allsubsets.end(); subset++) {
      vector<int> newsubset;
      newsubset.insert(newsubset.end(), (*subset).begin(), (*subset).end()); //
      newsubset.push_back(item);
      moresubsets.push_back(newsubset);
    }
    allsubsets.insert(allsubsets.end(), moresubsets.begin(), moresubsets.end());
  }
  return allsubsets;
}