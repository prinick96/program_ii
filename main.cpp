#include "core/core.cpp"

int main() {

  vector<multi_array> array;
  array.push_back(multi_array());
  array[0].str = "Test";

  cout << array[0].str << endl;

  return true;
}
