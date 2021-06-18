#include <iostream>
#include <vector>
#include <functional>
#include <numeric>
#define INT_MAX 1000000
using namespace std;

vector<int> vi(10);
void operator+=(vector<int> &a, const vector<int> &b) {
    for (int i = 0; i < a.size(); i++)
        a[i] += b[i];
}

void operator-=(vector<int> &a, const vector<int> &b) {
    for (int i = 0; i < a.size(); i++)
        a[i] -= b[i];
}

bool operator<(const vector<int> &a, const int &n) {
    for (int i : a)
        if (i < n)
            return true;
    return false;
}

template<typename T>
std::ostream& operator<<(std::ostream& s, std::vector<T> t) {
    s << "[";
    for (std::size_t i = 0; i < t.size(); i++) {
        s << t[i] << (i == t.size() - 1 ? "" : ",");
    }
    return s << "]" << std::endl;
}

int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs, int cost = 0) {
    if (needs < 0)
        return INT_MAX;
        cout << "hi i am in : " << endl;
    int m = inner_product(needs.begin(), needs.end(), price.begin(), cost);

    for (auto &offer : special) {
      cout << "cost : " << cost << endl;
        if (cost + offer.back() >= m) // pruning
            continue;
        needs -= offer;
        cout << "needs : " << needs << endl;
        cout << "price : " << m << endl;
        cout << "offer :" << offer << endl;
        cout << "=======" << endl;
        m = min(m, shoppingOffers(price, special, needs, cost + offer.back()));
        needs += offer;
        cout << "hi i am outtttttt" << endl;
    }

    return m;
}

int main()
{

  vector<int> price = {2,5};
  vector<vector<int>> special = {{3,0,5},{1,2,10}};
  vector<int> needs = {3,2};
  int ans = shoppingOffers(price,special,needs);
  cout << "ans :" << ans << endl;

}
