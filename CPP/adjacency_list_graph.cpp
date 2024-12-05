#include<iostream>
#include<unordered_map>
#include<list>
#include <vector>


using namespace std;

vector < vector <int >> PrintAdjacency(int n, int m, vector < vector < int >> &edges){

    vector<vector<int>> ans(n);

    for(int i=0;i<m;i++){
        int u = edges[i][0];
        int v = edges[i][1];

        ans[u].push_back(v);
        ans[v].push_back(u);


    }

    return ans;

}

int main(){

    int n = 5;
    int m = 4;

    vector<vector<int>> edges = {

        {0 ,1},
        {0 ,4},
        {1 ,2},
        {1 ,3},



    };

    vector<vector<int>> adjacencyList = PrintAdjacency(n, m, edges);

    for (int i=0; i<adjacencyList.size();i++){
        cout<<i<< ": ";
        for (int j: adjacencyList[i]){
            cout<< j << " ";
        }

        cout<< endl;
    }

    return 0;
}
