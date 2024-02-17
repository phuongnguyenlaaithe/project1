#include <bits/stdc++.h>
using namespace std;

struct Person {
    string code;
    string date_of_birth;
    string father_code;
    string mother_code;
    char is_alive;
    string region_code;
};

struct TreeNode {
    string code;
    int generation;
    vector<TreeNode*> children;

    TreeNode(string code, int generation) : code(code), generation(generation) {}
};

// Function to build the tree
TreeNode* buildTree(const vector<Person>& database, const string& rootCode) {
    unordered_map<string, TreeNode*> nodeMap;

    for (const Person& person : database) {
        nodeMap[person.code] = new TreeNode(person.code, -1);
    }

    for (const Person& person : database) {
        TreeNode* currentNode = nodeMap[person.code];
        TreeNode* fatherNode = nodeMap[person.father_code];
        TreeNode* motherNode = nodeMap[person.mother_code];

        if (fatherNode) {
            currentNode->children.push_back(fatherNode);
        }
        if (motherNode) {
            currentNode->children.push_back(motherNode);
        }
    }

    return nodeMap[rootCode];
}

// Function to find the height of the tree
int findTreeHeight(TreeNode* root) {
    if (!root) {
        return 0;
    }

    int maxHeight = 0;
    for (TreeNode* child : root->children) {
        maxHeight = max(maxHeight, findTreeHeight(child));
    }

    return maxHeight + 1;
}

int main() {
    vector<Person> database;

    // Read the database
    string line;
    while (getline(cin, line) && line != "*") {
        Person person;
        stringstream ss(line);
        ss >> person.code >> person.date_of_birth >> person.father_code >> person.mother_code >> person.is_alive >> person.region_code;
        database.push_back(person);
    }

    // Process queries
    while (getline(cin, line) && line != "***") {
        stringstream ss(line);
        string command;
        ss >> command;

        if (command == "NUMBER_PEOPLE") {
            cout << database.size() << endl;
        } else if (command == "NUMBER_PEOPLE_BORN_AT") {
            string date;
            ss >> date;
            int count = count_if(database.begin(), database.end(), [&](const Person &p) {
                return p.date_of_birth == date;
            });
            cout << count << endl;
        } else if (command == "MOST_ALIVE_ANCESTOR") {
            string code;
            ss >> code;

            // Build the tree
            TreeNode* root = buildTree(database, code);

            // Find the height of the tree
            int height = findTreeHeight(root);

            cout << height - 1 << endl;  // Subtract 1 to get the generation distance
        } else if (command == "NUMBER_PEOPLE_BORN_BETWEEN") {
            string from_date, to_date;
            ss >> from_date >> to_date;
            int count = count_if(database.begin(), database.end(), [&](const Person &p) {
                return p.date_of_birth >= from_date && p.date_of_birth <= to_date;
            });
            cout << count << endl;
        } else if (command == "MAX_UNRELATED_PEOPLE") {
            unordered_set<string> unrelated_set;
            for (const Person& p : database) {
                unrelated_set.insert(p.code);
            }

            for (const Person& p : database) {
                if (p.father_code != "0000000") {
                    unrelated_set.erase(p.father_code);
                }
                if (p.mother_code != "0000000") {
                    unrelated_set.erase(p.mother_code);
                }
            }

            int max_unrelated_size = unrelated_set.size();
            cout << max_unrelated_size << endl;
        }
    }

    return 0;
}
