#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Graph
{
	private :
		unordered_map<T,list<pair<T,int>>> mp;
	public :
		void AddEdge(T u, T v, int dist, bool bidir=true)
		{
			mp[u].push_back(make_pair(v,dist));
			if(bidir)
				mp[v].push_back(make_pair(u,dist));
		}
		
		void Print_AdjList()
		{
			for(auto k : mp)
			{
				T node = k.first;
				cout<<node<<"-->";
				for(auto neighbour : k.second)
					cout<<'('<<neighbour.first<<','<<neighbour.second<<')'<<' '; 
				cout<<endl<<endl;
			}
		}
		
		void Dijkstra(T source)
		{
			unordered_map<T,int> dist;
			//Initially marking all node's distance as infinite
			for(auto node : mp)
				dist[node.first] = INT_MAX;
			//Creating a set to keep record of min
			//In a set all pairs are sorted arrocding to their 1st parameter
			set<pair<int,T>> s;
			//Marking dist of source as 0
			dist[source] = 0;
			//Pushing a source in the set
			s.insert(make_pair(0,source));
			//Until the set becomes empty we're iterating
			while(!s.empty())
			{
				//taking min from the set i.e. the fisrt pair from the set
				auto p = *(s.begin());
				T node = p.second;
				int NodeDist = p.first;
				//now this current node has been finalized so we've to delete this one
				s.erase(s.begin());
				//Now we've to iterste over the neigbours of the current node and check whether 
				//there is a chance to update their distances or not
				for(auto neighbour : mp[node])
				{
					//Checking if (curr node dist + distance from curr node to it's neighbour)<dist[neighbour]
					//dist[neighbour] means that previously calculated shortest distance
					if((NodeDist+neighbour.second)<dist[neighbour.first])
					{
						//Now we've to update the previous record for it's neigbour(if it was previously present in set)
						//But there is no direct function to update the pair so we've delete it first then insert it
						auto f = s.find(make_pair(dist[neighbour.first],neighbour.first));
						//Checking if the pair was previously present or not
						//If present then deleting it otherwise not
						if(f!=s.end())
							s.erase(f);
						//updating the value of dist for the node's neighbour
						dist[neighbour.first] = NodeDist + neighbour.second;
						//Now inserting the updated pair again
						s.insert(make_pair(dist[neighbour.first],neighbour.first)); 
					}	
				} 
			}
			for(auto node : mp)
				cout<<"Shortest dis of "<<node.first<<" is "<<dist[node.first]<<endl<<endl;;
		}
};

int main()
{
	Graph<string> g;
	
	g.AddEdge("Sealdah","Chingrigatha",1);
	g.AddEdge("Sealdah","Ruby",4);
	g.AddEdge("Sealdah","Dhakuriya",7);
	g.AddEdge("Chingrigatha","Ruby",1);
	g.AddEdge("Ruby","Dhakuriya",2);
	
	g.Print_AdjList();
	
	g.Dijkstra("Sealdah");
	
	return 0;
}
