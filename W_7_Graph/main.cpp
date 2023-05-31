#include<iostream>
#include "Graph.cpp"
#include <queue>

using namespace std;


int main() {

    freopen("input1.txt", "r", stdin);
    freopen("output1.txt", "w", stdout);

    int t, n, X, l, s;

    cin >> t;

    while(t--) {

        cin >> n >> X;

        Graph g(X);

        for(int i = 1; i <= X; i++) {
            for(int j = 1; j <= n; j++) {
                g.addEdge(i, i + j);
            }
        }

//        g.toString();

        cin >> l;

        int x, y;

        for(int i = 0; i < l; i++) {
            cin >> x >> y;
            for(int j = 1; j <= n; j++) {
                g.deleteEdge(x, x + j);
            }
            g.addEdge(x , y);
        }

//        g.toString();

        cin >> s;

        for(int i = 0; i < s; i++) {
            cin >> x >> y;
            for(int j = 1; j <= n; j++) {
                g.deleteEdge(x , x +  j);
            }
            g.addEdge(x , y);
        }

//        g.toString();


        g.bfs(1, n);
        g.traverseBFS(1);

        cout << endl;

    }





}


/*
2
3 20
1
2 8
2
10 7
15 3
6 30
3
2 10
15 19
11 16
7
20 3
21 4
22 5
23 6
24 7
25 8
26 9
*/
