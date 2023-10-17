#include<bits/stdc++.h>
using namespace std;

int main(){
   const double vatRate = 0.1;//Thuế VAT
   double kwhUsage;
   cin >> kwhUsage;

    double currentPrice = 0.0;//giá điện 6 bậc
    if (kwhUsage <= 50) {
        currentPrice = kwhUsage * 1728;
    } else if (kwhUsage <= 100) {
        currentPrice = 50 * 1728 + (kwhUsage - 50) * 1786;
    } else if (kwhUsage <= 200) {
        currentPrice = 50 * 1728 + 50 * 1786 + (kwhUsage - 100) * 2074;
    } else if (kwhUsage <= 300) {
        currentPrice = 50 * 1728 + 50 * 1786 + 100 * 2074 + (kwhUsage - 200) * 2612;
    } else if (kwhUsage <= 400) {
        currentPrice = 50 * 1728 + 50 * 1786 + 100 * 2074 + 100 * 2612 + (kwhUsage - 300) * 2919;
    } else {
        currentPrice = 50 * 1728 + 50 * 1786 + 100 * 2074 + 100 * 2612 + 100 * 2919 + (kwhUsage - 400) * 3015;
    }

    double proposedPrice = 0.0; // giá điện 5 bậc
    if (kwhUsage <= 100) {
        proposedPrice = kwhUsage * 1.728;
    } else if (kwhUsage <= 200) {
        proposedPrice = 100 * 1728 + (kwhUsage - 100) * 2074;
    } else if (kwhUsage <= 400) {
        proposedPrice = 100 * 1728 + 100 * 2074 + (kwhUsage - 200) * 2612;
    } else if (kwhUsage <= 700) {
        proposedPrice = 100 * 1728 + 100 * 2074 + 200 * 2612 + (kwhUsage - 400) * 3111;
    } else {
        proposedPrice = 100 * 1728 + 100 * 2074 + 200 * 2612 + 300 * 3111 + (kwhUsage - 700) * 3457;
    }

    double priceDifference = proposedPrice *(vatRate+1) - currentPrice*(vatRate+1);
    cout << fixed << setprecision(2);
    cout << priceDifference;

    return 0;
}
