#include <iostream>
#include <chrono>
#include "key.h"

using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cout << "Usage:" << endl;
        cout << argv[0] << " <hashed password> < rand8.txt" << endl;
        return 1;
    }

    // Hashed password.
    Key hashed{argv[1]};
    std::cout << hashed << '\n';

    // Table.
    Key table[N];

    // Read table.
    for (int i{0}; i < N; i++) {
        char buffer[C + 1];
        if (scanf("%s", buffer) != 1) {
            cerr << "Too short table!" << endl;
            return 1;
        }
        table[i] = Key{buffer};
    }

    auto begin = chrono::high_resolution_clock::now();
    // Try all possible subsets of T.


    Key candidate{};
    Key zero{};
    do {
        Key enc = subset_sum(candidate, table);

        //std::cout << enc << "------" << hashed << '\n';
        if (enc == hashed)
            cout << candidate << endl;
        ++candidate;
    } while (candidate != zero);


    auto end = chrono::high_resolution_clock::now();
    cout << "Decryption took "
         << std::chrono::duration_cast<chrono::seconds>(end - begin).count()
         << " seconds." << endl;

    return 0;
}
