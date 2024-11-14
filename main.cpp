#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void unite_cities(int city1, int city2, vector<int>& parent, int& counter) {
    int city1_counter = 0;
    int city2_counter = 0;
    vector<int> city_parent_list;
    while (parent[city1] != city1) {
        city_parent_list.push_back(city1);
        city1 = parent[city1];
        city1_counter++;
    }
    for (int i = 0; i < city_parent_list.size(); i++) {
        parent[city_parent_list[i]] = city1;
    }
    city_parent_list.clear();
    while (parent[city2] != city2) {
        city_parent_list.push_back(city2);
        city2 = parent[city2];
        city2_counter++;
    }
    for (int i = 0; i < city_parent_list.size(); i++) {
        parent[city_parent_list[i]] = city2;
    }
    if (city1 == city2) {
        return;
    }
    if (city1_counter >= city2_counter) {
        parent[city2] = city1;
    }
    else {
        parent[city1] = city2;
    }
    counter--;
}
                                                                            //n + n(2*log(n)) = n*(1 + 2*log(n))
int main() {
    int n, q;
    ifstream in("input.txt");
    in >> n >> q;
    int counter = n;
    vector <int> parent (n + 1);
    for (int i = 1; i < n + 1; i++) {
        parent[i] = i;
    }
    vector<int> data (q);
    for (int i = 0; i < q; i++) {
        int city1, city2;
        in >> city1 >> city2;
        unite_cities(city1, city2, parent, counter);
        data[i] = counter;
    }
    in.close();
    ofstream out("output.txt");
    for (int i = 0; i < q; i++) {
        out << data[i] << endl;
    }
    out.close();
    
    return 0;
}
