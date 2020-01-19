#include <iostream>
#include <chrono>
#include <map>
#include <string>
#include <vector>
#include <unordered_map>
#include "key.h"

using namespace std;

class un_key{
public:
  long operator()(const Key& x) const{
    long hash = 0;
    for(int i{N-1}; i >= 0; --i){
      hash = hash | x.bit(i) << i;
    }
    return hash;
  }
};


int main(int argc, char* argv[]) {
    if (argc != 2) {
        cout << "Usage:" << endl;
        cout << argv[0] << " <hashed password> < rand8.txt" << endl;
        return 1;
    }

    // Hashed password.
    Key hashed{argv[1]};
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

    Key half_point{};
    unordered_map<Key, vector<Key>, un_key> hashed_tbl;
    Key less_significant{};
    Key zero{};
    Key most_significant{};
    bool is_half{false};


    //Letar upp half_point (punkten där mitten biten är 1)
    while(!is_half){
      ++half_point;
      if(half_point.bit(N/2)){
        is_half = true;
      }
    }
    //std::cout << half_point << '\n';


    //Går över alla kombinationer med den mindre signifikanta
    //delen av hashed och sparar dom i en unordered_map. Key(i mappen) är summan vi måste hitta
    //för att få hela summan av hashed.
    while(less_significant <= half_point){
      hashed_tbl[hashed-subset_sum(less_significant, table)].push_back(less_significant);
      ++less_significant;
    }

    //Brute force där man kollar om summan som vi får från varje kombination matchar
    //en summa i less_significant.
    do{
      auto iterator = hashed_tbl.find(subset_sum(most_significant, table));
      if(iterator != hashed_tbl.end()){
        for(Key can : iterator->second){
          std::cout << most_significant + can << '\n';
        }
      }
      most_significant = most_significant + half_point;
    }while(most_significant != zero);


    // Find all possible passwords that hash to 'hashed' and print them.

    auto end = chrono::high_resolution_clock::now();
    cout << "Decryption took "
         << std::chrono::duration_cast<chrono::seconds>(end - begin).count()
         << " seconds." << endl;

    return 0;
}
