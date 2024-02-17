// C++
#include <bits/stdc++.h>

using namespace std;

const int MAXN = (int)1e5 + 5;
unordered_map<string, int> customer;
unordered_map<string, int> total[MAXN];
unordered_map<string, int> rev;
long long s[24 * 60 * 60];

int ord(char c)
{
    return c - '0';
}

int convertTimetoInt(string c)
{
    return (ord(c[0]) * 10 + ord(c[1])) * 60 * 60 + (ord(c[3]) * 10 + ord(c[4])) * 60 + (ord(c[6]) * 10 + ord(c[7]));
}

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long totalRevenue = 0;
    int numOrder = 0;
    int numCustomer = 0;
    while (true)
    {
        string customerID, productID, shopID, timePoint;
        int price;
        cin >> customerID;
        if (customerID == "#")
            break;
        cin >> productID >> price >> shopID >> timePoint;
        s[convertTimetoInt(timePoint)] += price;
        totalRevenue += 1LL * price;
        numOrder++;
        if (customer[customerID] == 0)
        {
            customer[customerID] = ++numCustomer;
        }
        total[customer[customerID]][shopID] += price;
        rev[shopID] += price;
    }
    for (int i = 1; i < 24 * 60 * 60; ++i)
        s[i] += s[i - 1];

    while (true)
    {
        string type;
        cin >> type;
        if (type == "#")
            break;
        if (type == "?total_number_orders")
            cout << numOrder;
        if (type == "?total_revenue")
            cout << totalRevenue;
        if (type == "?revenue_of_shop")
        {
            string shopID;
            cin >> shopID;
            cout << rev[shopID];
        }
        if (type == "?total_consume_of_customer_shop")
        {
            string customerID, shopID;
            cin >> customerID >> shopID;
            cout << total[customer[customerID]][shopID];
        }
        if (type == "?total_revenue_in_period")
        {
            string sta, en;
            cin >> sta >> en;
            cout << s[convertTimetoInt(en)] - (convertTimetoInt(sta) == 0 ? 0 : s[convertTimetoInt(sta) - 1]);
        }
        cout << "\n";
    }

    return 0;
}