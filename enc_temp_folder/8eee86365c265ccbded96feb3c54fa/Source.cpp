#include <iostream>
#include <vector>
#include <queue>
#include <stack> //stack for dfs
#define V 5
void AddEdge(std::vector<int> adj[], int a, int b)
{
	adj[a].push_back(b);
	adj[b].push_back(a);
}

void dfs(int src, std::stack<int>& stack, std::vector<int> adj[], std::vector<bool>& visited, std::vector<int>& answer)
{
	
	if (!visited[0]) //for the base case (if the first one is false, do this
	{
		stack.push(src);
		visited[src] = true;
	
	}
	

		src = stack.top();
		answer.push_back(src);
		stack.pop();

		for (int i = 0; i < adj[src].size(); i++)
		{
			int check = adj[src].at(i);

	    	if (!visited[check])
			{
				stack.push(check); //we are dealing with stack, so this should come at last,
							//the last one will be 3, so 3 will be pushed first
				visited[check] = true;
				dfs(check, stack, adj, visited, answer);  //here the src will be "i"
				//because src is changing :_) we are doing recusrive for each list
			
			}


		}

		

	

}

std::vector<int> dfsofGraph(int v, std::vector<int> adj[])
{
	std::vector<bool> visited(v, false);
	std::vector<int> answer;
	std::stack<int> stack;
	dfs(0, stack, adj, visited, answer);

	return answer;

}

int main(void)
{

	std::vector<int> adj[V];
	
	AddEdge(adj, 0, 1);
	AddEdge(adj, 0, 2);
	AddEdge(adj, 0, 4);
	AddEdge(adj, 4, 3);

	std::vector<int> answer = dfsofGraph(V, adj);

	return 0;
}