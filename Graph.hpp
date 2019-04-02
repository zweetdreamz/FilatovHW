#include <iostream>
#include <string>
#include "fstream"
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/classification.hpp>
#include <boost/lexical_cast.hpp>


using namespace std;

class Graph {

public:

    vector<vector<int>> adjacencyList; // список смежности
    vector<vector<int>> routs; // все найденные пути между заданной парой вершин
    vector<vector<int>> simpleRouts;
    vector<int> path; // найденный путь
    set<set<int>> ribs; // рёбра

    ~Graph() {

        adjacencyList.clear();
        simpleRouts.clear();
        routs.clear();
        path.clear();
        ribs.clear();

    }

    void parserGraph(string path) {

        ifstream f(path);

        if (!f) {

            cin.get();

        }

        while (!f.eof()) {

            string line;
            vector<string> l;
            vector<int> num;

            l.reserve(100);
            num.reserve(100);
            getline(f, line);

            boost::split(l, line, boost::is_any_of(" "));

            for (auto ls:l) {

                num.emplace_back(boost::lexical_cast<int>(ls));

            }

            adjacencyList.emplace_back(num);
            num.clear();
            l.clear();

        }

        f.close();

        for (auto it: adjacencyList) {

            it.shrink_to_fit();

        }

        adjacencyList.shrink_to_fit();

    }

    void showAdjecencyListGraph() {

        for (auto it: adjacencyList) {

            copy(it.begin(), it.end(), ostream_iterator<int>(cout, " "));
            cout << endl;

        }

    }

    void showAllSimplePath(int start, int finish) {

        DFS(start, finish);
        getSimpleRouts();

        cout << "Простые пути между вершиной " << start << " и " << finish << endl;

        for (auto it: simpleRouts) {

            copy(it.begin(), it.end(), ostream_iterator<int>(cout, "  "));
            cout << endl;

        }

        cout << "Всего простых путей: " << simpleRouts.size() << endl;
        cout << "Всего путей: " << routs.size() << endl;

    }

    void DFS(int start, int finish) {

        dfs(start, finish);

    }

    void dfs(int currentNode, int lastNode) {

        path.emplace_back(currentNode);

        if (currentNode == lastNode) {

            routs.emplace_back(path);
            path.pop_back();
            return;

        }

        for (auto val : adjacencyList[currentNode - 1]) {

            set<int> rib = {currentNode, val};

            if (ribs.find(rib) == ribs.end()) {

                ribs.emplace(rib);
                dfs(val, lastNode);
                ribs.erase(ribs.find(rib));

            }

        }

        path.pop_back();

    }

    void getSimpleRouts() {

        bool check = false;

        for (auto it: routs) {

            for (int i = 0; i < it.size(); i++) {

                for (int j = i + 1; j < it.size(); j++) {

                    if (it[i] == it[j]) {

                        check = true;
                        break;

                    }

                }

            }

            if (!check) {

                simpleRouts.emplace_back(it);

            }

            check = false;

        }

    }

};


















