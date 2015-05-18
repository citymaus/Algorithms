/* Write your custom functions here */
void deepest_leaf(node* root, int level, int *maxlevel, bool is_left);
int diameter(node* root);
int height(node* root);

int diameterOfTree(node * root) {
/* For your reference
  struct node {
   struct node *left,*right;
   int val;
};
*/
    int left_diameter = 0;
    int right_diameter = 0;
    int ldiameter = 0;
    int rdiameter = 0;
    
    //deepest_leaf(root, 0, &left_diameter, true);
    //deepest_leaf(root, 0, &right_diameter, false);
    left_diameter = height(root->left);
    right_diameter = height(root->right);
    ldiameter = diameter(root->left);
    rdiameter = diameter(root->right);
    cout << "left:" << left_diameter << " right:" << right_diameter << endl;
    cout << "left:" << ldiameter << " right:" << rdiameter << endl;
    
    
    return left_diameter + right_diameter + 1; // plus one for root
}

void deepest_leaf(node* root, int level, int *maxlevel, bool is_left)
{
    if (root == NULL)
        return;
    
    if (!root->left && !root->right && (level > *maxlevel))
    {
        *maxlevel = level; 
        return;
    }
    
    deepest_leaf(root->left, level+1, maxlevel, true);
    deepest_leaf(root->right, level+1, maxlevel, false);
}

int height(node* root)
{
    if (root == NULL)
        return 0;

    return 1 + max(height(root->left), height(root->right));
}

int diameter(node* root)
{
    /* base case where tree is empty */
   if (root == 0)
     return 0;
 
  /* get the height of left and right sub-trees */
  int lheight = height(root->left);
  int rheight = height(root->right);
 
  /* get the diameter of left and right sub-trees */
  int ldiameter = diameter(root->left);
  int rdiameter = diameter(root->right);
 
  /* Return max of following three
   1) Diameter of left subtree
   2) Diameter of right subtree
   3) Height of left subtree + height of right subtree + 1 */
  return max(lheight + rheight + 1, max(ldiameter, rdiameter));    
}



//OR

/* Write your custom functions here */
void deepest_leaf(node* root, int level, int *maxlevel, bool is_left);
int diameter(node* root);
int height(node* root);

int diameterOfTree(node * root) {
/* For your reference
  struct node {
   struct node *left,*right;
   int val;
};
*/
    int left_diameter = 0;
    int right_diameter = 0;
    int ldiameter = 0;
    int rdiameter = 0;
    int ht = 0;
    int diametery = 0;
    
    //deepest_leaf(root, 0, &left_diameter, true);
    //deepest_leaf(root, 0, &right_diameter, false);
    left_diameter = height(root->left);
    right_diameter = height(root->right);
    //ldiameter = diameter(root->left);
    //rdiameter = diameter(root->right);
    diametery = diameter(root, &ht);
    //cout << "left:" << left_diameter << " right:" << right_diameter << endl;
    //cout << "left:" << ldiameter << " right:" << rdiameter << endl;
    
    
    //return left_diameter + right_diameter + 1; // plus one for root
    return diametery;
}

void deepest_leaf(node* root, int level, int *maxlevel, bool is_left)
{
    if (root == NULL)
        return;
    
    if (!root->left && !root->right && (level > *maxlevel))
    {
        *maxlevel = level; 
        return;
    }
    
    deepest_leaf(root->left, level+1, maxlevel, true);
    deepest_leaf(root->right, level+1, maxlevel, false);
}

int height(node* root)
{
    if (root == NULL)
        return 0;

    return 1 + max(height(root->left), height(root->right));
}

int diameter(node* root, int* height)
{
   /* lh --> Height of left subtree
      rh --> Height of right subtree */
  int lh = 0, rh = 0;
  
  /* ldiameter  --> diameter of left subtree
      rdiameter  --> Diameter of right subtree */
  int ldiameter = 0, rdiameter = 0;
  
  if(root == NULL)
  {
    *height = 0;
     return 0; /* diameter is also 0 */
  }
  
  /* Get the heights of left and right subtrees in lh and rh
    And store the returned values in ldiameter and ldiameter */
  ldiameter = diameter(root->left, &lh);
  rdiameter = diameter(root->right, &rh);
  
  /* Height of current node is max of heights of left and
     right subtrees plus 1*/
  *height = max(lh, rh) + 1;
  
  return max(lh + rh + 1, max(ldiameter, rdiameter));  
}
