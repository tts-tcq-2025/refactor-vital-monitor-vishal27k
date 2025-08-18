#include <gtest/gtest.h>
#include "./monitor.h"

TEST(Monitor, NotOkWhenAnyVitalIsOffRange) {
  ASSERT_FALSE(handleVitals(99, 102, 70));
  ASSERT_TRUE(handleVitals(98.1, 70, 98));
}

