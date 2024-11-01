#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  bool areSentencesSimilar(string sentence1, string sentence2) {
    stringstream word1(sentence1);
    stringstream word2(sentence2);
    vector<string> words1;
    vector<string> words2;
    string word;
    while (word1 >> word) {
      words1.push_back(word);
    }
    while (word2 >> word) {
      words2.push_back(word);
    }
    size_t i = 0, j = 0;
    size_t n1 = words1.size(), n2 = words2.size();

    while (i < n1 && i < n2 && words1[i] == words2[i]) {
      i++;
    }
    while (j < n1 - i && j < n2 - i &&
           words1[n1 - j - 1] == words2[n2 - j - 1]) {
      j++;
    }

    return (i + j == ((n1 < n2) ? n1 : n2));
  }
};
