#include <iostream>
#include<queue>
#include<vector>

using namespace std;


class Graph {
private:
    bool **adjMatrix;
    int nVertices;

public:
    Graph(int n) {
        nVertices = n;
        adjMatrix = new bool*[n];

        for(int i = 0; i < n; i++) {
            adjMatrix[i] = new bool[n];

            for(int j = 0; j < n; j++) {
                adjMatrix[i][j] = false;
            }
        }
    }

    void addEdge(int i, int j) {
        adjMatrix[i-1][j-1] = true;
    }

    void deleteEdge(int i, int j) {
        adjMatrix[i-1][j-1] = false;
    }

    bool hasEdge(int i,int j) {
        return adjMatrix[i-1][j-1];
    }

    void toString() {
        for (int i = 0; i < nVertices; i++) {
          cout << i << " : ";
          for (int j = 0; j < nVertices; j++)
            cout << adjMatrix[i][j] << " ";
          cout << "\n";
        }
    }


    int hLeap(int i) {
        for(int j = nVertices-1; j >= 0; j--) {
            if(adjMatrix[i-1][j] == 1) return j + 1;
        }

        return -1;
    }


    void bfs(int start, int dSide) {

        queue<int> q;
        bool *visited = new bool[nVertices];
        vector<int> parent(nVertices + 1, -1);

        for(int i = 0; i < nVertices; i++) {
            visited[i] = false;
        }

        q.push(start);

        while(!q.empty()) {
            int curr = q.front();

            if(!visited[curr - 1]) {
                visited[curr-1] = true;
//                cout << "Node   : " << curr << endl;
            }

            q.pop();


            vector<int> tLeap(nVertices, 0);
            int t = 0;

            for(int i = 1; i <= nVertices; i++) {
                if(hasEdge(curr,i)) {
                        if(!visited[i - 1]) {
                            if(i == nVertices ) {
                                tLeap[t++] = nVertices;
                            } else
                                tLeap[t++] = hLeap(i);
                        }

                }
            }


            int tMax = tLeap[nVertices-1];
            t = nVertices-1;
            for(int i = nVertices-2; i >= 0; i--) {
                if(tLeap[i] > tMax) {
                    tMax = tLeap[i];
                    t = i;
                }
            }


            int x = 0;


            for(int i = 1; i <= nVertices; i++) {
                if(hasEdge(curr,i)) {
                    if(!visited[i - 1]) {
                        if(t == x) {
                            q.push(i);
                            parent[i] = curr;
                            break;
                        } else x++;

                    }
                }
            }

        }

        if(parent[nVertices] == -1) {
            cout << -1 << endl;
            cout << "No solution" << endl;
        } else {

            int nRolls = 0;
            int tLadder = 0;
            vector<int> stPath;

            for(int i = nVertices; i != -1; i = parent[i]) {
                if(parent[i] != -1 && (i - parent[i]) > dSide) tLadder++;
                nRolls++;
                stPath.push_back(i);
            }


            cout << nRolls - 1 - tLadder << endl;

            for(int i = nRolls-1; i >= 0; i--) {

                cout << stPath[i];

                if(i != 0)
                    cout << " -> ";
            }

            cout << endl;

        }

        return;
    }


    void traverseBFS(int start) {
        queue<int> q;
        bool *visited = new bool[nVertices];

        for(int i = 0; i < nVertices; i++) {
            visited[i] = false;
        }

        q.push(start);

        while(!q.empty()) {
            int curr = q.front();

            if(!visited[curr - 1]) {
                visited[curr-1] = true;
            }

            q.pop();

            for(int i = 1; i <= nVertices; i++) {
                if(hasEdge(curr,i)) {
                    if(!visited[i - 1]) {
                        q.push(i);
                    }
                }
            }
        }

        int cNotVisitable = 0;

        for(int i = 0; i < nVertices; i++) {
            if(!visited[i]) {
                cout << i+1 << " ";
                cNotVisitable++;
            }
        }

        if(cNotVisitable == 0) cout << "All reachable";


        cout << endl;


        return;
    }







    ~Graph() {
        for(int i = 0; i < nVertices; i++)
            delete[] adjMatrix[i];

        delete[] adjMatrix;
    }


};


/*

    void bfs(int start) {

        queue<int> q;
        bool *visited = new bool[nVertices];
        vector<int> parent(nVertices, -1);

        for(int i = 0; i < nVertices; i++) {
            visited[i] = false;
        }

        q.push(start);

        while(!q.empty()) {
            int curr = q.front();

            if(!visited[curr - 1]) {
                visited[curr-1] = true;
                cout << "Node   : " << curr << endl;
            }

            q.pop();
//            cout << q.front() << endl;

            for(int i = 1; i <= nVertices; i++) {
                if(hasEdge(curr,i)) {
                    if(!visited[i - 1]) {
                        q.push(i);
                        parent[i] = curr;
//                        cout << "Pushing" << i << " " << endl;
                    }
                }
            }

        }

        for(int i = nVertices - 1; i != -1; i = parent[i]) {
            cout << i << " ";
        }


        return;
    }
*/

/*


    void bfs(int start) {

        queue<int> q;
        bool *visited = new bool[nVertices];
        vector<int> parent(nVertices + 1, -1);

        for(int i = 0; i < nVertices; i++) {
            visited[i] = false;
        }

        q.push(start);

        while(!q.empty()) {
            int curr = q.front();

            if(!visited[curr - 1]) {
                visited[curr-1] = true;
                cout << "Node   : " << curr << endl;
            }

            q.pop();
//            cout << q.front() << endl;

            vector<int> tLeap(nVertices, 0);
            int t = 0;

            for(int i = 1; i <= nVertices; i++) {
                if(hasEdge(curr,i)) {
                        if(!visited[i - 1]) {
                            if(i == nVertices ) {
                                tLeap[t++] = nVertices + 1;
                            } else
                                tLeap[t++] = hLeap(i);
                        }

                }
            }

            cout << "Temo: "  << tLeap[0] << " " << tLeap[1] << " " << tLeap[2] << endl;

            int tMax = tLeap[0];
            t = 0;
            for(int i = 1; i < nVertices; i++) {
                if(tLeap[i] > tMax) {
                    tMax = tLeap[i];
                    t = i;
                }
            }


            int x = 0;


            for(int i = 1; i <= nVertices; i++) {
                if(hasEdge(curr,i)) {
                    if(!visited[i - 1]) {
                        if(t == x) {
                            q.push(i);
                            parent[i] = curr;
                            cout << "Parent" << i << " " << parent[i] << endl;
                            break;
                        } else x++;

                    }
                }
            }

        }

        int nRolls = 0;
        vector<int> stPath;

        for(int i = nVertices; i != -1; i = parent[i]) {
            cout << i << " ";
            nRolls++;
            stPath.push_back(i);
        }

        cout << endl;

        cout << nRolls << endl;

        for(int i = nRolls-1; i >= 0; i--) {
            cout << stPath[i];
        }

        cout << endl;

        for(int i = 0; i < nVertices; i++) {
            cout << i << " " << visited[i] << endl;
        }

        return;
    }
*/
