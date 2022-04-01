#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <map>

## g++ -o monop basic-mon.cpp
## ./monop  

using namespace std;
std::vector<int> vec;

int getNum(vector<int>& v)
{

    // Size of the vector
    int n = v.size();

    // Generate a random number
    srand(time(NULL));

    // Make sure the number is within
    // the index range
    int index = rand() % n;

    // Get random number from the vector
    int num = v[index];

    // Remove the number from the vector
    swap(v[index], v[n - 1]);
    v.pop_back();

    // Return the removed number
    return num;
}

// Function to generate n non-repeating random numbers
void generateRandom(int n)
{
    vector<int> v(n);

    // Fill the vector with the values
    // 1, 2, 3, ..., n
    for (int i = 0; i < n; i++)
        v[i] = i + 1;

    // While vector has elements
    // get a random number from the vector and print it
    while (v.size()) {
      vec.push_back (getNum(v));
  //    cout << getNum(v) << " ";
    }
    // for (int i = 0; i < n; i++)
    //   cout << vec[i] << " ";
}

int main() {
  int N = 6;
  generateRandom(N);

  const char *names[6] = {"kelly", "james", "cory" , "tom" , "jason", "bob"};
  int posi[6] = {0,0,0,0,0,0};

  map<int, string> m;
  map<string, int> position;

  for (int i = 0; i < N; i++)
    m.insert(pair<int, string>(vec[i], names[i]));

  cout << "Postion" << '\t' << '\t' << "Player" << '\n';

  for (auto itr = m.begin(); itr != m.end(); ++itr) {
    cout << itr->first << '\t' << '\t' << itr->second << '\n';
  }

  cout << " "  << endl;

  for (int i = 1; i < N+1; i++)
    cout << m[i] << endl;

  cout << " "  << endl;

  srand(time(NULL));

  for (int i = 1; i <= N; i++)
    position.insert(pair<string, int>(m[i], posi[i] + rand() % 10));

  cout << " "  << endl;

  for (auto itr = position.begin(); itr != position.end(); ++itr) {
    cout << itr->first << '\t' << '\t' << itr->second << '\n';
  }
  return 0;
}
