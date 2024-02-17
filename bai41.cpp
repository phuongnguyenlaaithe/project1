#include <bits/stdc++.h>
using namespace std;

struct Transaction {
    string from_account;
    string to_account;
    int money;
    string time_point;
    string atm;
};

unordered_map<string, vector<string>> graph;
unordered_set<string> visited;

bool dfs(const string& current, const string& start, const int k, unordered_set<string>& current_path) {
    if (k == 0) {
        return current == start;
    }

    visited.insert(current);
    current_path.insert(current);

    for (const auto& neighbor : graph[current]) {
        if (visited.find(neighbor) == visited.end() && dfs(neighbor, start, k - 1, current_path)) {
            return true;
        } else if (neighbor == start && k - 1 == 0) {
            // Nếu neighbor trùng với điểm bắt đầu và độ dài còn lại là 0
            // Điều này đồng nghĩa với việc tìm thấy chu trình hợp lệ
            return true;
        }
    }

    visited.erase(current);
    current_path.erase(current);
    return false;
}


int main() {
    vector<Transaction> transactions;
    unordered_map<string, int> totalMoneyPerAccount;

    // Read data block
    string line;
    while (getline(cin, line) && line != "#") {
        istringstream iss(line);
        Transaction transaction;
        iss >> transaction.from_account >> transaction.to_account >> transaction.money >> transaction.time_point >> transaction.atm;
        transactions.push_back(transaction);

        // Update total transferred money for the from_account
        totalMoneyPerAccount[transaction.from_account] += transaction.money;

        // Build the graph for cycle detection
        graph[transaction.from_account].push_back(transaction.to_account);
    }

    // Process queries
    while (getline(cin, line) && line != "#") {
        istringstream iss(line);
        string query;
        iss >> query;

        if (query == "?number_transactions") {
            cout << transactions.size() << endl;
        } else if (query == "?total_money_transaction") {
            int total_money = 0;
            for (const auto &transaction : transactions) {
                total_money += transaction.money;
            }
            cout << total_money << endl;
        } else if (query == "?list_sorted_accounts") {
            set<string> accounts;
            for (const auto &transaction : transactions) {
                accounts.insert(transaction.from_account);
                accounts.insert(transaction.to_account);
            }
            for (const auto &account : accounts) {
                cout << account << " ";
            }
            cout << endl;
        } else if (query == "?total_money_transaction_from") {
            string account;
            iss >> account;

            auto it = totalMoneyPerAccount.find(account);
            int total_money = (it != totalMoneyPerAccount.end()) ? it->second : 0;
            cout << total_money << endl;
        } else if (query == "?inspect_cycle") {
            string account;
            int k;
            iss >> account >> k;

            visited.clear();
            unordered_set<string> current_path;
            cout << (dfs(account, account, k, current_path) ? "1" : "0") << endl;
        }
    }

    return 0;
}
