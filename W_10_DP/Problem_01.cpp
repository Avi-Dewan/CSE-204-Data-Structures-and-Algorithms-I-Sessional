#include<iostream>
#include<string>
#include<vector>

using namespace std;

int DpLCS(string X, string Y, vector<vector<int>> &L, vector<vector<int>> &D) {

    int m = X.size(), n = Y.size();

    for(int i = 0; i <= m; i++) {
        L[i][0] = 0;
    }

    for(int j = 0; j <= n; j++) {
        L[0][j] = 0;
    }

    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(X[i-1] == Y[j-1]) {
                L[i][j] = L[i-1][j-1] + 1;
                D[i][j] = 1;
            } else {
                if(L[i-1][j] > L[i][j-1]) {
                    L[i][j] = L[i-1][j];
                    D[i][j] = 2;
                } else {
                    L[i][j] = L[i][j-1];
                    D[i][j] = 3;
                }
            }
        }
    }

    return L[m][n];
}


string constructLCS(string X, string Y, vector<vector<int>> &L, vector<vector<int>> &D) {

    int m = X.size(), n = Y.size();

    int i = L[m][n];

    string R(i, 'a');

    while(m!=0 && n!=0) {
        if(D[m][n] == 1) {
            R[i-1] = X[m-1];
            i--;
            m--;
            n--;
        } else if(D[m][n] == 2) {
            m--;
        } else {
            n--;
        }
    }

    return R;

}


int main()
{

    string X, Y;

    cin >> X >> Y;

    int m = X.size(), n = Y.size();

    vector<vector<int>> L(m + 1, vector<int>(n + 1, 0));
    vector<vector<int>> D(m + 1, vector<int>(n + 1, 0));


    cout << DpLCS(X, Y, L, D) << endl;
    cout << constructLCS(X, Y, L, D) << endl;

    return 0;
}
