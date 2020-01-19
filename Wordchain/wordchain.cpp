#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <unordered_set>
#include <algorithm>

using std::unordered_set;
using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::queue;
using std::set;
using std::stack;


void print(vector<string> const&input){
  for(int i = 0; i < input.size(); i++){
    std::cout << input.at(i)<< "->";
  }
  std::cout <<'\n';
}

void print_set(set<string> const&myset){
  for (auto it=myset.begin(); it != myset.end(); ++it){
      cout << ' ' << *it;
    }
  std::cout << '\n';
}
// Typ som används för ordlistan. Den definieras med en typedef här så att du enkelt kan ändra
// representationen av en ordlista utefter vad din implementation behöver. Funktionen
// "read_questions" skickar ordlistan till "find_shortest" och "find_longest" med hjälp av denna
// typen.
typedef vector<string> Dictionary;

/**
void print(std::unordered_set<string> const &s)
{
    std::copy(s.begin(),
            s.end(),
            std::ostream_iterator<string>(std::cout, "->"));
    std::cout <<'\n';
}
 * Hitta den kortaste ordkedjan från 'first' till 'second' givet de ord som finns i
 * 'dict'. Returvärdet är den ordkedja som hittats, första elementet ska vara 'from' och sista
 * 'to'. Om ingen ordkedja hittas kan en tom vector returneras.
 */
vector<string> find_shortest(const unordered_set<string> &dict, const string &from, const string &to) {
    queue<vector<string>> mainQueue;
    vector<string> e;
    vector<string> vec;
    vec.push_back(from);
    mainQueue.push(vec);

    unordered_set<string> testedWords;
    while(!mainQueue.empty()){
      vector<string> chain = mainQueue.front();
      mainQueue.pop();
      string lastWord = chain.back();
      //std::cout << lastWord << '\n';
      if(lastWord == to){
        //print(chain);
        return chain;
      }
      string testWord;
      for(int i = 0; i < lastWord.size(); i++){
        testWord = lastWord;
        for(char x = 'a'; x<= 'z'; x++){
          testWord[i] = x;
          if(dict.count(testWord)){
            if(!testedWords.count(testWord)){
              vector<string> copy = chain;
              copy.push_back(testWord);
              mainQueue.push(copy);
            }
          }
          testedWords.insert(testWord);
        }

      }
      //e = chain;
    }
    return e;

}

/**
 * Hitta den längsta kortaste ordkedjan som slutar i 'word' i ordlistan 'dict'. Returvärdet är den
 * ordkedja som hittats. Det sista elementet ska vara 'word'.
 */
 vector<string> find_longest(const unordered_set<string> &dict, const string &from) {
   queue<vector<string>> mainQueue;
   vector<string> e;
   vector<string> vec;
   vec.push_back(from);
   mainQueue.push(vec);

   unordered_set<string> testedWords;
   while(!mainQueue.empty()){
     vector<string> chain = mainQueue.front();
     mainQueue.pop();
     string lastWord = chain.back();
     //std::cout << lastWord << '\n';
     string testWord;
     for(int i = 0; i < lastWord.size(); i++){
       testWord = lastWord;
       for(char x = 'a'; x<= 'z'; x++){
         testWord[i] = x;
         if(dict.count(testWord)){
           if(!testedWords.count(testWord)){
             vector<string> copy = chain;
             copy.push_back(testWord);
             mainQueue.push(copy);
           }
         }
         testedWords.insert(testWord);
       }

     }
     std::reverse(chain.begin(), chain.end());
     e = chain;
   }
   return e;
 }


/**
 * Läs in ordlistan och returnera den som en vector av orden. Funktionen läser även bort raden med
 * #-tecknet så att resterande kod inte behöver hantera det.
 */
unordered_set<string> read_dictionary() {
    string line;
    unordered_set<string> result;
    while (std::getline(std::cin, line)) {
        if (line == "#")
            break;

        result.insert(line);
    }

    return result;
}

/**
 * Skriv ut en ordkedja på en rad.
 */
void print_chain(const vector<string> &chain) {
    if (chain.empty())
        return;

    vector<string>::const_iterator i = chain.begin();
    cout << *i;

    for (++i; i != chain.end(); ++i)
        cout << " -> " << *i;

    cout << endl;
}


/**
 * Läs in alla frågor. Anropar funktionerna "find_shortest" eller "find_longest" ovan när en fråga hittas.
 */
void read_questions(const unordered_set<string> &dict) {
    string line;
    while (std::getline(std::cin, line)) {
        size_t space = line.find(' ');
        if (space != string::npos) {
            string first = line.substr(0, space);
            string second = line.substr(space + 1);
            vector<string> chain = find_shortest(dict, first, second);

            cout << first << " " << second << ": ";
            if (chain.empty()) {
                cout << "ingen lösning" << endl;
            } else {
                cout << chain.size() << " ord" << endl;
                print_chain(chain);
            }
        } else {
            vector<string> chain = find_longest(dict, line);

            cout << line << ": " << chain.size() << " ord" << endl;
            print_chain(chain);
        }
    }
}

int main() {
    unordered_set<string> dict = read_dictionary();
    read_questions(dict);

    return 0;
}
