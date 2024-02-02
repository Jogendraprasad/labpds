#include<bits/stdc++.h>
using namespace std;

void merge(vector<vector<int>> &m, int s, int mid, int e, int x, int order){
  vector<int> v1, v2;
  if(order == 0){
    for(int i=s;i<=mid;i++) v1.push_back(m[x][i]);
    for(int i=mid+1;i<=e;i++) v2.push_back(m[x][i]);
  }else{
    for(int i=s;i<=mid;i++) v1.push_back(m[i][x]);
    for(int i=mid+1;i<=e;i++) v2.push_back(m[i][x]);
  }

  int k=s, i=0, j=0;
  while(i<v1.size() && j<v2.size()){
    if(order == 0){
      if(v1[i] < v2[j]) m[x][k++] = v1[i++];
      else m[x][k++] = v2[j++];
    }else{
      if(v1[i] > v2[j]) m[k++][x] = v1[i++];
      else m[k++][x] = v2[j++];
    }
  }

  if(order == 0){
    while(i<v1.size()) m[x][k++] = v1[i++];
    while(j<v2.size()) m[x][k++] = v2[j++];
  }else{
    while(i<v1.size()) m[k++][x] = v1[i++];
    while(j<v2.size()) m[k++][x] = v2[j++];
  }
}

void mergeSort(vector<vector<int>> &m, int s, int e, int r, int order){
  if(s>=e) return;

  int mid = s+(e-s)/2;

  mergeSort(m, s, mid, r, order);
  mergeSort(m, mid+1, e, r, order);
  merge(m, s, mid, e, r, order);
}

bool findElement(vector<vector<int>> &mat, int elem){
  int n = mat.size();
  int i=0,j=0;
  while(i<n && j<n){
    if(mat[i][j] == elem) return true;
    else if(elem < mat[i][j]) i++;
    else j++;
  }

  return false;
}

int main(){
  int n;
  cout<<"Enter the integer n: ";
  cin>>n;
  vector<vector<int>> m(n,vector<int>(n));

  cout<<"Enter the integers: "<<endl;

  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      int temp;
      cin>>temp;

      m[i][j] = temp;
    }
  }

  for(int i=0;i<n;i++) mergeSort(m, 0, n-1, i, 0);
  for(int i=0;i<n;i++) mergeSort(m, 0, n-1, i, 1);

  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      cout<<m[i][j]<<" ";
    }
    cout<<endl;
  }

  printf("Enter the number to find in the matrix: ");
  int felem;
  cin>>felem;

  if(findElement(m, felem)){
    cout<<"NUMBER FOUND!"<<endl;
  }else{
    cout<<"NUMBER NOT FOUND!"<<endl;
  }

  return 0;
}