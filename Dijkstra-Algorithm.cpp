#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;

/*
    AL SHARIAR HOSSAIN
*/
class minHeap
{
private:
    vector<pii>heap;
    unordered_map<int,int>key_map;
    void heapify_up(int index);
    void heapify_down(int index);
    void swap(int index1, int index2);
public:
    minHeap(int Size);
    void insert(int key,int value);
    pii extract_min();
    void decrease_key(int key, int value);
    bool is_empty();
};

minHeap::minHeap(int Size)
{
    heap.reserve(Size);
}

void minHeap::insert(int key, int value)
{
    heap.push_back(make_pair(value,key));
    key_map[key] = heap.size()-1;
    heapify_up(heap.size()-1);
}
/*
 extract_min() function is used to find the minimum element in
 a min_Heap. The '0' index pair is the required element which 
 is stored to return.As the root is removed, so heapify_down()
 is required to maintain the heap property with the last element
 added to the heap.
*/
pii minHeap::extract_min()
{
    if(heap.size()==0)return make_pair(INT_MAX,-1);
    pii minElement = heap[0];
    heap[0] = heap.back();
    key_map[heap[0].second] = 0;
    heap.pop_back();
    heapify_down(0);
    key_map.erase(minElement.second);
    return minElement;
}

void minHeap::decrease_key(int key,int new_value)
{
    int index = key_map[key];
    heap[index].first = new_value;
    heapify_up(index);
}

bool minHeap::is_empty()
{
    return heap.size()==0;
}
/*
  Heapify_up requires to maintain the heap property when any element 
  element is added. Here is the implementation of heapify_up
*/
void minHeap::heapify_up(int index)
{
    while(index>0 and heap[index].first < heap[(index-1)/2].first)
    {
        swap(index,(index-1)/2);
        index = (index-1)/2;
    }
}
/*
  Heapify_down requires to maintain the heap property when the root 
  element is removed. Here is the implementation of heapify_down
*/
void minHeap::heapify_down(int index)
{
    int smallest = index;
    int left = 2*index +1;
    int right = 2*index+2;
    
    if(left< heap.size() and heap[left].first < heap[smallest].first)smallest = left;
    if(right<heap.size() and heap[right].first < heap[smallest].first)smallest  = right;

    if(smallest !=index)
    {
        swap(index, smallest);
        heapify_down(smallest);
    }
}

void minHeap::swap(int index1, int index2)
{
    key_map[heap[index1].second] = index2;
    key_map[heap[index2].second] = index1;

    pii tmp = heap[index1];
    heap[index1] = heap[index2];
    heap[index2] = tmp;
}

int main()
{
    int n,m;cin>>n>>m;
        
    //Graph is represented using adjacency list.//
    
    vector<pii>g[n];
    while(m--)
    {
        int u,v,w;cin>>u>>v>>w;
        g[u].push_back(make_pair(v,w));
        g[v].push_back(make_pair(u,w));
    }
    int src = 0;
    //cin>>src;
    /*
        Implementation of Dijkstra Algorithm using 
        a user-defined-min-heap.
    */
    vector<int>dis(n,INT_MAX);
    minHeap min_heap(n);

    dis[src] = 0;
    min_heap.insert(src,0);
    while(!min_heap.is_empty())
    {
        pii tmp = min_heap.extract_min();
        int u = tmp.second;

        for(auto &neighbor: g[u])
        {
            int v = neighbor.first;
            int weight = neighbor.second;

            if(dis[u]+weight < dis[v])
            {
                dis[v] = dis[u]+weight;
                min_heap.insert(v,dis[v]);
            }
        }
    }
    for(int i = 0;i<n;i++)
    {
        cout<<"Vertex "<<i<<": Distance "<<dis[i]<<"\n";
    }
    return 0;
}
