#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <sstream>

using namespace std;

int main() {

    int n, q;
    cin >> n >> q;
    cin.ignore();

    map<string, string> attributes;
    vector<string> path;

    for (int i = 0; i < n; i++) {

        string line;
        getline(cin, line);

        // Closing tag
        if (line[1] == '/') {
            path.pop_back();
            continue;
        }

        // Remove < and >
        line = line.substr(1, line.size() - 2);

        stringstream ss(line);

        string tag;
        ss >> tag;

        path.push_back(tag);

        // Build full path
        string currentPath = "";

        for (int j = 0; j < path.size(); j++) {

            if (j > 0)
                currentPath += ".";

            currentPath += path[j];
        }

        string attribute;
        string equals;
        string value;

        while (ss >> attribute >> equals >> value) {

            // Remove quotes
            value = value.substr(1, value.size() - 2);

            string key = currentPath + "~" + attribute;

            attributes[key] = value;
        }
    }

    for (int i = 0; i < q; i++) {

        string query;
        cin >> query;

        if (attributes.count(query))
            cout << attributes[query] << endl;
        else
            cout << "Not Found!" << endl;
    }

    return 0;
}
