#include <iostream>
#include <vector>
#include <vector>

std::vector<int> minimum_operations(int t, const std::vector<std::vector<std::vector<int>>>& arrays, const std::vector<int>& ms) {
    std::vector<int> results;
    for (int i = 0; i < t; i++) {
        int m = ms[i];
        const auto& array = arrays[i];
        std::vector<int> counts;
        for (const auto& a : array) {
            int count = 0;
            for (int j = 0; j < m; j++) {
                count += a[j];
            }
            counts.push_back(count);
        }
        int mean = 0;
        for (int count : counts) {
            mean += count;
        }
        mean /= counts.size();
        int operations = 0;
        for (int count : counts) {
            int diff = mean - count;
            if (diff < 0) {
                results.push_back(-1);
                break;
            }
            operations += diff;
        }
        results.push_back(operations);
    }
    return results;
}


int main() {
    int t;
    std::cin >> t;

    std::vector<std::vector<std::vector<int>>> arrays(t);
    std::vector<int> ms(t);

    for (int i = 0; i < t; i++) {
        int n, m;
        std::cin >> n >> m;
        ms[i] = m;
        arrays[i].resize(n);
        for (int j = 0; j < n; j++) {
            arrays[i][j].resize(m);
            for (int k = 0; k < m; k++) {
                std::cin >> arrays[i][j][k];
            }
        }
    }

    std::vector<int> results = minimum_operations(t, arrays, ms);
    for (int result : results) {
        std::cout << result << std::endl;
    }

    return 0;
}
