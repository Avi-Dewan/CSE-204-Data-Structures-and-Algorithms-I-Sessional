#include "BST.cpp"
#include <iostream>
#include<fstream>
#include<string>

using namespace std;

int main() {

    BST <int> *bst = new BST<int>();

    ifstream inputFile("input.txt");

    string line;

    if(inputFile.is_open()) {

        while(getline(inputFile, line)) {

            string words[2];

            int c = 0;

            for(int i = 0; i < (int)line.size(); i++) {
                if(line[i] != ' ' ) words[c] += line[i];
                else c++;
            }

            int k;
            string t;

            if(words[0] == "I" ) {
                k = stoi(words[1]);
                bst->insert(k);
                bst->print();
            } else if(words[0] == "D") {
                k = stoi(words[1]);

                bool x = bst->find(k);

                bst->remove(k);
                if(x)
                    bst->print();
            } else if(words[0] == "F") {
                k = stoi(words[1]);
                if (bst->find(k)) {

                    cout << "True" << endl;
                } else {

                    cout << "False" << endl;
                }
            } else if(words[0] == "T") {
                if(words[1] == "In")
                    bst->in_traverse();
                else if(words[1] == "Pre")
                    bst->pre_traverse();
                else if(words[1] == "Post")
                    bst->post_traverse();
            }

        }

    } else {
        cout << "Unable to open the file";
    }

    inputFile.close();

    return 0;
}

