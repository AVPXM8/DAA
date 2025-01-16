#include <iostream>
#include <vector>
#include <fstream>  // For CSV file handling
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time() to seed randomness
using namespace std;

// Linear search function to return index and count comparisons
int linearSearch(const vector<int>& arr, int key, int &comparisons) {
    comparisons = 0;  // Reset the comparison count
    for (int i = 0; i < arr.size(); i++) {
        comparisons++;
        if (arr[i] == key) {
            return i;  // Return the index if the key is found
        }
    }
    return -1;  // Return -1 if the key is not found
}

int main() {
    srand(time(0));  // Seed the random number generator

    ofstream csvFile("linear_search_results.csv");  // Create CSV file
    csvFile << "Size,Best Case,Worst Case,Average Case\n";  // CSV header

    for (int n = 10; n <= 100; n += 5) {  // Input sizes from 10 to 100, step 5
        vector<int> arr(n);  // Create an array of size n
        for (int i = 0; i < n; i++) {
            arr[i] = rand() % 1000 + 1;  // Fill the array with random numbers between 1 and 1000
        }

        // Best case: Search for the first element
        int comparisons = 0;
        int bestIndex = linearSearch(arr, arr[0], comparisons);
        int bestCase = comparisons;  // Comparisons for best case

        cout << "Best Case - Index Found: " << bestIndex << ", Comparisons: " << bestCase << endl;

        // Worst case: Search for an element that is guaranteed not to be in the array
        int worstIndex = linearSearch(arr, 2000, comparisons);  // Search for 2000
        int worstCase = comparisons;  // Comparisons for worst case

        cout << "Worst Case - Index Found: " << worstIndex << " (expected -1), Comparisons: " << worstCase << endl;

        // Average case: Perform n successful searches + 1 unsuccessful search
        int totalComparisons = 0;
        for (int i = 0; i < n; i++) {  // n successful searches
            linearSearch(arr, arr[i], comparisons);
            totalComparisons += comparisons;
        }
        linearSearch(arr, 2000, comparisons);  // Unsuccessful search
        totalComparisons += comparisons;
        double avgCase = (double)totalComparisons / (n + 1);  // Average comparisons

        // Save results to CSV and display on the console
        csvFile << n << "," << bestCase << "," << worstCase << "," << avgCase << "\n";
        cout << "Size: " << n << " | Best: " << bestCase << ", Worst: " << worstCase << ", Average: " << avgCase << endl;
    }

    csvFile.close();  // Close the CSV file
    cout << "Results saved in 'linear_search_results.csv'.\n";

    return 0;
}
