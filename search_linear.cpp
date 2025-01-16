#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include<climits>
using namespace std;

int linearSearch(const vector<int>& arr, int key, int &comparisons) {
    comparisons = 0;
    for (int i = 0; i < arr.size(); i++) {
        comparisons++;
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int main() {
    srand(time(0));
    ofstream csvFile("linear_search_results.csv");
    csvFile << "Size,Best Case,Worst Case,Average Case\n";

    for (int n = 10; n <= 100; n += 5) {
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            arr[i] = rand() % 1000;
        }

        vector<int> searchKeys = arr;
        searchKeys.push_back(2000);

        int bestCase = INT_MAX;
        int worstCase = 0;
        int totalComparisons = 0;

        for (const int& key : searchKeys) {
            int comparisons = 0;
            linearSearch(arr, key, comparisons);
            totalComparisons += comparisons;
            bestCase = min(bestCase, comparisons);
            worstCase = max(worstCase, comparisons);
        }

        double avgCase = static_cast<double>(totalComparisons) / searchKeys.size();

        csvFile << n << "," << bestCase << "," << worstCase << "," << avgCase << "\n";
        cout << "Size: " << n
             << "  Best: " << bestCase
             << ", Worst: " << worstCase
             << ", Average: " << avgCase << endl;
    }

    csvFile.close();
    cout << "Results saved in 'linear_search_results.csv'.\n";

    return 0;
}
