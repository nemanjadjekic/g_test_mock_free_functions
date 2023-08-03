#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "../inc/calculator.h"

/**
 * MockStaticMethods
 *
 * GMock macro to define the mock API
 * MOCK_METHOD: Mock CPP static functions
 * in order to enable unit test coverage.
 *
 */
 class MockStaticMethods
 {
    public:
        virtual ~MockStaticMethods() {};

        // Mock APIs
        MOCK_METHOD(int, sum, (int x, int y));
        MOCK_METHOD(int, subtract, (int x, int y));
        MOCK_METHOD(int, multiply, (int x, int y));
        MOCK_METHOD(float, divide, (float x, int y));
 };


/**
 * CppExampleUnitTest
 *
 * GTest tests unit test class. Used to
 * instatiate test class. Also includes
 * test case setup and tear down.
 *
 * @param _mockStaticMethods pointer to test class;
 * Enables external access to test object.
 */
 class CppExampleUnitTest : public ::testing::Test
 {
    public:
      CppExampleUnitTest()
      {
          // Allocate the mock object
          _mockStaticMethods.reset(new ::testing::NiceMock<MockStaticMethods>());
      }

      ~CppExampleUnitTest()
      {
          _mockStaticMethods.reset();
      }

      virtual void SetUp() {};

      virtual void TearDown() {};

      static std::unique_ptr<MockStaticMethods> _mockStaticMethods;
 };

  // Make the class static member accessible to other function
  std::unique_ptr<MockStaticMethods> CppExampleUnitTest::_mockStaticMethods;

  class MockCalculator
  {
    public:
        // Mock functions
        static int sum(int x, int y) 
        {
          return CppExampleUnitTest::_mockStaticMethods->sum(x, y);
        }

        static int subtract(int x, int y) 
        {
          return CppExampleUnitTest::_mockStaticMethods->subtract(x, y);
        }

        static int multiply(int x, int y) 
        {
          return CppExampleUnitTest::_mockStaticMethods->multiply(x, y);
        }

        static float divide(float x, int y) 
        {
          return CppExampleUnitTest::_mockStaticMethods->divide(x, y);
        }
  };

  // Tests
  TEST_F(CppExampleUnitTest, sum)
  {
    EXPECT_CALL(*_mockStaticMethods, sum(5, 10)).Times(1).WillOnce(testing::Return(25));

    MockCalculator mockCalculator;
    EXPECT_EQ(25, mockCalculator.sum(5, 10));
  }

  TEST_F(CppExampleUnitTest, subtract)
  {
    EXPECT_CALL(*_mockStaticMethods, subtract(5, 10)).Times(1).WillOnce(testing::Return(41));

    MockCalculator mockCalculator;
    EXPECT_EQ(41, mockCalculator.subtract(5, 10));
  }

  TEST_F(CppExampleUnitTest, multiply)
  {
    EXPECT_CALL(*_mockStaticMethods, multiply(5, 10)).Times(1).WillOnce(testing::Return(13));

    MockCalculator mockCalculator;
    EXPECT_EQ(13, mockCalculator.multiply(5, 10));
  }

  TEST_F(CppExampleUnitTest, divide)
  {
    EXPECT_CALL(*_mockStaticMethods, divide(17.0, 10)).Times(1).WillOnce(testing::Return(2.35));
   
    float getFloat = 2.35;
    MockCalculator mockCalculator;
    EXPECT_EQ(getFloat, mockCalculator.divide(17.0, 10));
  }

  int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
  }
