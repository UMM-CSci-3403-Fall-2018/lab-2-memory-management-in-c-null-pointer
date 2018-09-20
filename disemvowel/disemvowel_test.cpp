#include <gtest/gtest.h>

#include "disemvowel.h"

TEST(Disemvowel, HandleEmptyString) {
  char* noVowels = disemvowel((char*) "");
  ASSERT_STREQ("", noVowels);
  free(noVowels);
}

TEST(Disemvowel, HandleNoVowels) {
  char* noVowels = disemvowel((char*) "pqrst");
  ASSERT_STREQ("pqrst", noVowels);
  free(noVowels);
}

TEST(Disemvowel, HandleOnlyVowels) {
  char* noVowels = disemvowel((char*) "aeiouAEIOUOIEAuoiea");
  ASSERT_STREQ("", noVowels);
  free(noVowels);
}

TEST(Disemvowel, HandleMorrisMinnesota) {
  char* noVowels = disemvowel((char*) "Morris, Minnesota");
  ASSERT_STREQ("Mrrs, Mnnst", noVowels);
  free(noVowels);
}

TEST(Disemvowel, HandlePunctuation) {
  char* noVowels = disemvowel((char*) "An (Unexplained) Elephant!");
  ASSERT_STREQ("n (nxplnd) lphnt!", noVowels);
  free(noVowels);
}

TEST(Disemvowel, HandleLongString) {
  char *str;
  int size;
  int i;

  size = 50000;
  str = (char*) calloc(size, sizeof(char));
  str[0] = 'x';
  str[1] = 'y';
  str[2] = 'z';
  for (i = 3; i < size-1; ++i) {
    str[i] = 'a';
  }
  str[size-1] = '\0';
  
  char* noVowels = disemvowel(str);
  free(str);

  ASSERT_STREQ("xyz", noVowels);

  free(noVowels);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
