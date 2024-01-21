#include <gtest/gtest.h>

#include "../lib.h"

TEST(CheckVersionNumber, correct_version) {
    ASSERT_TRUE(version() != 100);
}