#include <gtest/gtest.h>

#include "../OTemplate/include/ScopedPtr.h"

TEST(SmartPointers, ScopedPtr) {
  Otac::ScopedPtr<float> p{10.f};

  EXPECT_EQ(*p, 10.f);
};