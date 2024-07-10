#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring(char *s) {
  if (s == NULL || *s == '\0')
    return 0;

  int max_length = 0;
  int dp[256];
  memset(dp, -1, sizeof(dp));

  int start = 0;
  int i;

  for (i = 0; s[i]; i++) {
    if (dp[s[i]] != -1) {
      start = (start > dp[s[i]] + 1) ? start : dp[s[i]] + 1;
    }
    dp[s[i]] = i;
    max_length = (max_length > i - start + 1) ? max_length : i - start + 1;
  }

  return max_length;
}