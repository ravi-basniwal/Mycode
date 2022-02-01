#include<bits/stdc++.h>
using namespace std;
int sizee;
int maxu;
int minu;
class Node
{
     public :
     int data;
     Node* left;
     Node* right;
     Node(int data)
     {
          this->data=data;
          left=NULL;
          right=NULL;
     }
};
Node* make_binary_tree(vector<int>v)
{
     Node* root=new Node(v[0]);
     pair<Node*,int>pr(root,1);
     stack<pair<Node*,int>>s;
     s.push(pr);
     int k=0;
     while(s.size())
     {
         if(s.top().second==1)
          {
               s.top().second++;
               k++;
               if(v[k]!=-1)
               {
                    Node* l=new Node(v[k]);
                    s.top().first->left=l;
                    s.push(make_pair(l,1));
               }
               else
               s.top().first->left=NULL;
              
               
          }
          else if(s.top().second==2)
          {
            s.top().second++;
            k++;
               if(v[k]!=-1)
               {
                    Node* l=new Node(v[k]);
                    s.top().first->right=l;
                    s.push(make_pair(l,1));
               }
               else
               s.top().first->right=NULL;
          }
          else
          {
               s.pop();
          }
          
     }
     return root;
}
void display_tree_pre(Node* root)
{
    
     if(root==NULL)
     return;
     cout << root->data << " ";
     display_tree_pre(root->left);
     display_tree_pre(root->right);
}
void display_tree_in(Node* root)
{
    
     if(root==NULL)
     return;
    
     display_tree_in(root->left);
      cout << root->data << " ";
     display_tree_in(root->right);
}
void display_tree_post(Node* root)
{
    
     if(root==NULL)
     return;
    
     display_tree_post(root->left);
     
     display_tree_post(root->right);
      cout << root->data << " ";
}
void display_tree_whole(Node* root)
{
     if(root==NULL)
     return;
     if(root->left==NULL)
     cout << ". -> ";
     else 
     cout << root->left->data << " -> ";
     cout << root->data << " -> ";
     if(root->right==NULL)
     cout << ".";
     else
     cout << root->right->data;
     cout << endl;
     display_tree_whole(root->left);
     display_tree_whole(root->right);
}
int set_max_min_h_size(Node* root)
{
     if(root==NULL)
     return 0;
     sizee++;
     maxu=max(maxu,root->data);
     minu=min(minu,root->data);
     int h1=set_max_min_h_size(root->left);
     int h2=set_max_min_h_size(root->right);
     return max(h1,h2)+1;
}
int max_height(Node* root)
{
     if(root==NULL)
     return 0;
     return max(max_height(root->left),max_height(root->right))+1;
}
void level_order_traversal(Node* root)
{
     queue<Node*>q;
     q.push(root);
     q.push(NULL);
     while(q.size())
     {
          if(q.front()==NULL)
          {cout << endl;
            q.pop();
            if(q.size())
           q.push(NULL);}
           else{
          cout << q.front()->data << " ";
         if(q.front()->left!=NULL)
         q.push(q.front()->left);
         if(q.front()->right!=NULL)
          q.push(q.front()->right);
          q.pop();}
          
          
     
     }
     
}
vector<Node*>pre,post,in;
void itretive_pre_post_in(Node* root)
{
     stack<pair<Node*,int>>s;
     s.push(make_pair(root,-1));
     while(s.size())
     {
          if(s.top().second==-1)
          {
               pre.push_back(s.top().first);
               s.top().second++;
               if(s.top().first->left!=NULL)
               s.push(make_pair(s.top().first->left,-1));
               
          }
           else if(s.top().second==0)
          {
               in.push_back(s.top().first);
               s.top().second++;
               if(s.top().first->right!=NULL)
               s.push(make_pair(s.top().first->right,-1));
               
          }
          else
          {post.push_back(s.top().first);
          s.pop();
          }
     }
}
vector<Node*>our;
bool node_to_root(Node* root,int k)
{
     
   if(root==NULL)
   return false;
   if(root->data==k)
   {
        our.push_back(root);
        return true;}
   if(node_to_root(root->left,k))
 {
        our.push_back(root);
        return true;}
   if(node_to_root(root->right,k))
  {
        our.push_back(root);
        return true;}
   return false;
     
}
vector<Node*>find_node_to_root(Node* root,int k)
{
     vector<Node*>v;
     if(root==NULL)
     return v;
     if(root->data==k)
     {
          v.push_back(root);
          return v;
     }
     v=find_node_to_root(root->left,k);
     if(v.size())
     {
          v.push_back(root);
          return v;
     }
     v=find_node_to_root(root->right,k);
     if(v.size())
     {
          v.push_back(root);
          return v;
     }
     return v;
}
vector<Node*>print_k_level_down(Node* root,int k)
{
     vector<Node*>v;
     if(k<0 or root==NULL)
     return v;
     if(k==0)
     {
          v.push_back(root);
          return v;
     }
     vector<Node*>l=print_k_level_down(root->left,k-1);
     for(auto x:l)
     v.push_back(x);
     l=print_k_level_down(root->right,k-1);
     for(auto x:l)
     v.push_back(x);
     return v;
}
vector<Node*>print_k_level_down_bar(Node* root,int k,Node* bar)
{
     vector<Node*>v;
     if(k<0 or root==NULL)
     return v;
     if(k==0)
     {
          v.push_back(root);
          return v;
     }
     if(root->left!=bar){
     vector<Node*>l=print_k_level_down(root->left,k-1);
     for(auto x:l)
     v.push_back(x);}
     if(root->right!=bar){
     vector<Node*>l=print_k_level_down(root->right,k-1);
     for(auto x:l)
     v.push_back(x);}
     return v;
}
vector<Node*>print_k_level_far(Node* root,int k,int source)
{
     vector<Node*>v=find_node_to_root(root,source);
     vector<Node*>p,ans;
     for(int i=0;i<v.size();i++)
     {
          if(i==0)
          p=print_k_level_down(v[i],k);
          else
          p=print_k_level_down_bar(v[i],k-i,v[i-1]);
          for(auto x:p)
          ans.push_back(x);
     }
     return ans;
}
void sum_path_leaf(Node* root,int sum,string si,int low,int up)
{
     if(root==NULL)
     return;
     if(root->left==NULL and root->right==NULL)
     {
          si=si+" "+to_string(root->data);
          sum=sum+root->data;
          if(sum>=low and sum<=up)
          {
              cout << si << endl; 
          }
          return;
     }
     sum_path_leaf(root->left,sum+root->data,si+" "+to_string(root->data),low,up);
     sum_path_leaf(root->right,sum+root->data,si+" "+to_string(root->data),low,up);
}
Node* copy_(Node* root)
{
     if(root==NULL)
     return root;
    
     Node* remp=new Node(root->data);
     root->left=copy_(root->left);
     root->right=copy_(root->right);
     remp->left=root->left;
     root->left=remp;
     
     return root;
}
Node* decopy_(Node* root)
{
     if(root==NULL)
     return root;
     root->left=decopy_(root->left->left);
     root->right=decopy_(root->right);
     return root;
}
void single_child_parents(Node* root)
{
     if(root==NULL)
     return;
     if(root->left==NULL or root->right==NULL)
     {
          if(root->left==NULL and root->right==NULL)
          return;
          else 
          {
          if(root->left==NULL)
          {cout << root->right->data << " ";
          single_child_parents(root->right);}
          else
          {
               cout << root->left->data << " ";
               single_child_parents(root->left);
          }
          
          }
          
     }
     else
     {
          single_child_parents(root->left);
          single_child_parents(root->right);
     }
}
Node* remove_leaves(Node* root)
{
     if(root==NULL)
     return root;
     if(root->left==NULL and root->right==NULL)
     return NULL;
     root->left=remove_leaves(root->left);
     root->right=remove_leaves(root->right);
     return root;
}
pair<int,int>diameter_of_a_b_tree(Node* root)
{
   if(root==NULL)
   return make_pair(0,0);
   pair<int,int>l=diameter_of_a_b_tree(root->left);
   pair<int,int>r=diameter_of_a_b_tree(root->right);
   int p=max(l.second,r.second)+1;
   int k=l.second+r.second+2;
   return(make_pair(max(k,max(l.first,r.first)),p));
}
pair<int,int>tilt_of_tree(Node* root)
{
     if(root==NULL)
     return make_pair(0,0);
     pair<int,int>l=tilt_of_tree(root->left);
     pair<int,int>r=tilt_of_tree(root->right);
     int sum=l.second+r.second+root->data;
     int diff=l.first+r.first+abs(l.second-r.second);
     return make_pair(diff,sum);
     
}
pair<pair<int,int>,bool>is_bst(Node* root)
{
     if(root==NULL)
     return make_pair(make_pair(INT_MIN,INT_MAX),true);
     if(root->data<root->left->data or root->data>root->right->data)
     return make_pair(make_pair(0,0),false);
     else{
          pair<pair<int,int>,bool>l,r;
          l=is_bst(root->left);
          r=is_bst(root->right);
          if(l.second and r.second)
          
     }
     
}


main()
{
     Node* root;
     vector<int>v;
     int a;
     while(cin >> a)
     v.push_back(a);
     root=make_binary_tree(v);
     //  single_child_parents(root);
     //  cout << endl;
     display_tree_pre(root);
     cout << endl;
     display_tree_post(root);
     cout << endl;
     display_tree_in(root);
     cout << endl;
     display_tree_whole(root);
     sizee=0;
     maxu=INT_MIN;
     minu=INT_MAX;
     int c=set_max_min_h_size(root);
     cout << "My size is " << sizee << endl;
     cout << "My height is " << c << endl;
     cout << "My max is " << maxu << endl;
     cout << "My min is " << minu << endl;
     level_order_traversal(root);
     itretive_pre_post_in(root);
     for(auto x:pre)
     cout << x->data << " ";
     cout << endl;
       for(auto x:in)
     cout << x->data << " ";
     cout << endl;
       for(auto x:post)
     cout << x->data << " ";
     cout << endl;
     
     bool r=node_to_root(root,40);
    for(auto x:our)
    cout<< x->data << " ";
    cout << endl;
     vector<Node*>f=find_node_to_root(root,40);
     for(auto x:f)
     cout << x->data << " ";
     cout << endl;
     f=print_k_level_down(root,2);
      for(auto x:f)
     cout << x->data << " ";
     cout << endl;
      f=print_k_level_down_bar(root,2,root->left);
      for(auto x:f)
     cout << x->data << " ";
     cout << endl;
      f=print_k_level_far(root,2,110);
      for(auto x:f)
     cout << x->data << " ";
     cout << endl;
     sum_path_leaf(root,0,"",10,2000);
     root=copy_(root);
     display_tree_pre(root);
     cout << endl;
     root=decopy_(root);
     display_tree_pre(root);
        cout << endl;
     // single_child_parents(root);
    root=remove_leaves(root);
    display_tree_pre(root);
    cout << endl;
    cout << max_height(root);
    cout << endl;
    pair<int,int>p=diameter_of_a_b_tree(root);
    cout << p.first << "  " << p.second<< endl;
    p=tilt_of_tree(root);
    cout << p.first << "  " << p.second<< endl;
    
    
     
}


