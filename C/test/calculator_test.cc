#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "../inc/calculator.h"

/**
 * MockCFunctions
 *
 * GMock macro to define the mock API
 * MOCK_METHOD: Mock C style functions
 * in order to enable unit test coverage.
 *
 */
 class MockCFunctions
 {
    public:
        virtual ~MockCFunctions() {};

        // Mock APIs
        MOCK_METHOD(int, sum, (int x, int y));
        MOCK_METHOD(int, subtract, (int x, int y));
        MOCK_METHOD(int, multiply, (int x, int y));
        MOCK_METHOD(float, divide, (float x, int y));
 };


/**
 * CExampleUnitTest
 *
 * GTest tests unit test class. Used to
 * instatiate test class. Also includes
 * test case setup and tear down.
 *
 * @param _mockCFunctions pointer to test class;
 * Enables external access to test object.
 */
 class CExampleUnitTest : public ::testing::Test
 {
    public:
        CExampleUnitTest()
        {
            // Allocate the mock object
            _mockCFunctions.reset(new ::testing::NiceMock<MockCFunctions>());
        }

        ~CExampleUnitTest()
        {
            _mockCFunctions.reset();
        }

        virtual void SetUp() {};
        virtual void TearDown() {};

        static std::unique_ptr<MockCFunctions> _mockCFunctions;
 };

  // Make the class static member accessible to other function
  std::unique_ptr<MockCFunctions> CExampleUnitTest::_mockCFunctions;

  // Mock functions
  int sum(int x, int y) 
  {
    return CExampleUnitTest::_mockCFunctions->sum(x, y);
  }

  int subtract(int x, int y) 
  {
    return CExampleUnitTest::_mockCFunctions->subtract(x, y);
  }

  int multiply(int x, int y) 
  {
    return CExampleUnitTest::_mockCFunctions->multiply(x, y);
  }

  float divide(float x, int y) 
  {
    return CExampleUnitTest::_mockCFunctions->divide(x, y);
  }

  // Tests
  TEST_F(CExampleUnitTest, sum)
  {
    EXPECT_CALL(*_mockCFunctions, sum(5, 10)).Times(1).WillOnce(testing::Return(25));
    EXPECT_EQ(25, sum(5, 10));
  }

  TEST_F(CExampleUnitTest, subtract)
  {
    EXPECT_CALL(*_mockCFunctions, subtract(5, 10)).Times(1).WillOnce(testing::Return(41));
    EXPECT_EQ(41, subtract(5, 10));
  }

  TEST_F(CExampleUnitTest, multiply)
  {
    EXPECT_CALL(*_mockCFunctions, multiply(5, 10)).Times(1).WillOnce(testing::Return(13));
    EXPECT_EQ(13, multiply(5, 10));
  }

  TEST_F(CExampleUnitTest, divide)
  {
    EXPECT_CALL(*_mockCFunctions, divide(17.0, 10)).Times(1).WillOnce(testing::Return(2.35));
   
    float getFloat = 2.35;
    EXPECT_EQ(getFloat, divide(17.0, 10));
  }

  int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
  }
