#include<bits/stdc++.h>
using namespace std;
void heapsort(int[],int );
void maxheapify(int[],int,int);
void display(int arr[],int N)
{cout<<endl;
int i,j,m,n,q,p=0,temp=8,flag=0,counts,loc,spaces=0,flag2=0,k;
//for(i=1;i<=N;i++)
//cin>>arr[i];
m=floor(log(N)/log(2))+1;
//cout<<"value of m is"<<m;
q=pow(2,m);
for(i=1;i<=m&&p<N;i++)
{
j=1;counts=1;
for(j=1;j<q&&p<N;j++)
{
if(j==q/(pow(2,i)))
{if(arr[p]<10)
{cout<<arr[p++];flag=1;loc=j;}
 else {for(k=1;k<=m-i+1;k++)cout<<" ";
 if(i!=m)cout<<" "<<arr[p++];else cout<<arr[p++];

//cout<<"now j is"<<j<<" ";
flag=1;loc=j;}}

else if(flag==1&&j==(loc+counts*temp))
{if(arr[p]<10){
cout<<arr[p++];
//cout<<"0"<<arr[p];flag2=1;

//cout<<" now j is"<<j<<" ";
counts++;}
else {for(k=1;k<=m-i+1;k++)cout<<" ";
 if(i!=m)cout<<" "<<arr[p++];else cout<<arr[p++];

//cout<<arr[p++];
//cout<<"0"<<arr[p];flag2=1;

//cout<<" now j is"<<j<<" ";
counts++;}}
else
{cout<<" ";}
}temp=loc;cout<<endl;

}
cout<<endl;
}
/*{cout<<endl;
int i,j,m,n,q,p=0,temp=8,flag=0,flag1,counts,loc,spaces=0,flag2=0;
//for(i=1;i<=N;i++)
//cin>>arr[i];
m=floor(log(N)/log(2))+1;
//cout<<"value of m is"<<m;
q=pow(2,m);
for(i=1;i<=m&&p<N;i++)
{
j=1;counts=1;
for(j=1;j<q&&p<N;j++)
{
if(j==q/(pow(2,i)))
//{//if(arr[p]>9)
//cout<<arr[p++];flagloc=j;}
 {cout<<arr[p++];
flag1=0;
//cout<<"now j is"<<j<<" ";
flag=1;loc=j;}

else if(flag==1&&j==(loc+counts*temp))
{//if(arr[p]>9)

cout<<arr[p++];
//cout<<"0"<<arr[p];flag2=1;

//cout<<" now j is"<<j<<" ";
counts++;}
else
{cout<<" ";}
}temp=loc;cout<<endl;

}
cout<<endl;
}*/
void heap_insert(int arr[],int key,int pos)
{int temp,parent;
if(key<=arr[pos])
{
cout<<endl<<"no improvement";
arr[pos]=key;return;
}
arr[pos]=key;parent=ceil((float)pos/2)-1;cout<<"parent is"<<parent;
while(pos>0&&arr[parent]<arr[pos])
{
temp=arr[pos];arr[pos]=arr[parent];arr[parent]=temp;pos=parent;
parent=ceil((float)pos/2)-1;
}
}
int main()
{int n;
int i;
cout<<"enter the total no of elements u want to get sorted"<<endl;
cin>>n;
int arr[n];
for(i=0;i<n;i++)
cin>>arr[i];
cout<<"before the sorting/n";
//for(i=0;i<n;i++)cout<<arr[i]<<" ";
display(arr,n);

heapsort(arr,n);
//cout<<"now the array is";
//for(i=0;i<6;i++)cout<<arr[i];
return 0;
}
void heapsort(int arr[],int siz)
{
int i,temp,key,pos;
for(i=(siz-2)/2;i>=0;i--)
maxheapify(arr,i,siz);
cout<<endl;
cout<<"enter the key u want to get inserted in"<<endl;
cin>>key;
cout<<"enter the position where u want to get insert that key"<<endl;
cin>>pos;
heap_insert(arr,key,pos);display(arr,siz);
while(siz>1)
{
    //cout<<endl<<arr[0]<<" " ;
    temp=arr[0];
    arr[0]=arr[siz-1];
    arr[siz-1]=temp;
    siz--;
    maxheapify(arr,0,siz);//if(siz==1)cout<<endl<<arr[0];
}
}
void maxheapify(int arr[],int idx,int heapsize)
{int largest,temp,i;
int left=2*idx+1;//cout<<endl<<left<<" ";
int right=2*idx+2;//cout<<right<<" ";
if(left<heapsize&&arr[left]>arr[idx])
largest=left;
else
largest=idx;
if(right<heapsize&&arr[right]>arr[largest])
largest=right;
if(largest!=idx)
{temp=arr[idx];arr[idx]=arr[largest];arr[largest]=temp;
//for(i=0;i<heapsize;i++)//cout<<arr[i]<<" ";
//cout<<endl;
maxheapify(arr,largest,heapsize);
}
display(arr,heapsize);
}
