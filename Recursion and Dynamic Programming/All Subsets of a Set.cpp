/*
  Write a method to return all subsets of a set.
*/
ArrayList<ArrayList<int>> getSubsets(Arraylist<int> set, int index) 
{
  ArrayList<ArrayList<int>> allsubsets;
  if (set.size() == index) { // Base case - add empty set
    allsubsets = new ArrayList<ArrayList<int>>();
    allsubsets.add(new ArrayList<int>()); // Empty set
  } else {
    allsubsets = getSubsets(set, index + 1);
    int item = set.get(index);
    ArrayList<ArrayList<int>> moresubsets = new ArrayList<ArrayList<int>>();
    for (ArrayList<int> subset : allsubsets) {
      ArrayList<int> newsubset = new ArrayList<int>();
      newsubset.addAll(subset); //
      newsubset.add(item);
      moresubsets.add(newsubset);
    }
    allsubsets.addAll(moresubsets);
  }
  return allsubsets;
}