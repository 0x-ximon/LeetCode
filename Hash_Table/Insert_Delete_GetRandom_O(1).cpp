#include <cstdlib>
#include <unordered_map>
#include <utility>
#include <vector>

using namespace std;

class RandomizedSet {
  vector<int> values;
  unordered_map<int, int> indexes;

 public:
  RandomizedSet() {
    values = {};
    indexes = {};
  }

  bool insert(int val) {
    if (indexes.find(val) != indexes.end()) return false;
    int i = values.size();

    values.push_back(val);
    indexes.insert({val, i});

    return true;
  };

  bool remove(int val) {
    if (indexes.find(val) == indexes.end()) return false;

    int i = indexes[val];
    int l = values.size() - 1;

    indexes[values[l]] = i;
    swap(values[i], values[l]);

    values.pop_back();
    indexes.erase(val);

    return true;
  };

  int getRandom() {
    int r = rand() % values.size();
    return values[r];
  };
};
