#include<bits/stdc++.h>
using namespace std;
class graph{
	int V;
	list<pair<int,int> > *l;
public:
	graph(int V){
		this->V=V;
		l=new list<pair<int,int> >[V];
	}
	void add_edge(int src,int dest,int weight){
		l[src].push_back({weight,dest});
		l[dest].push_back({weight,src});
	}
	int mst(){
		int visited[V]={0};
		// in pq, first value is weight and second value is the node to which we are going
		priority_queue<pair<int,int>, vector<pair<int,int> > , greater<pair<int,int> > > pq;
		int ans =0;
		pq.push({0,0});
		while(pq.size()!=0){
			pair<int,int> current=pq.top();
			pq.pop();
			int to= current.second;
			int cost= current.first;
			if(visited[to]){
				continue;
			}
			ans+= cost;
			visited[to]=1;
			for(auto it:l[to]){
				pq.push(it);
			}
		}
		return ans;
	}
};
int main(){
	int n,m;
	cin>>n>>m;
	graph g(n);
	int src,dest,weight;
	for(int i=0;i<m;i++){
		cin>>src>>dest>>weight;
		g.add_edge(src-1,dest-1,weight);
	}
	int ans=g.mst();
	cout<<ans;

}
