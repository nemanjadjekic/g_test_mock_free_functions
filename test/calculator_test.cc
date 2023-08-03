#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "calculator.h"

/**
 * CExampleMock
 *
 * GMock macro to define the mock API
 * MOCK_METHOD: Mock C style functions
 * in order to enable unit test coverage.
 *
 */
 class CExampleMock
 {
    public:
        virtual ~CExampleMock() {};

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
 * @param _CExampleMock pointer to test class;
 * Enables external access to test object.
 */
 class CExampleUnitTest : public ::testing::Test
 {
    public:
        CExampleUnitTest()
        {
            // Allocate the mock object
            _CExampleMock.reset(new ::testing::NiceMock<CExampleMock>());
        }

        ~CExampleUnitTest()
        {
            _CExampleMock.reset();
        }

        virtual void SetUp() {};
        virtual void TearDown() {};

        static std::unique_ptr<CExampleMock> _CExampleMock;
 };

  // Make the class static member accessible to other function
  std::unique_ptr<CExampleMock> CExampleUnitTest::_CExampleMock;

  // Mock functions
  int sum(int x, int y) 
  {
    return CExampleUnitTest::_CExampleMock->sum(x, y);
  }

  int subtract(int x, int y) 
  {
    return CExampleUnitTest::_CExampleMock->subtract(x, y);
  }

  int multiply(int x, int y) 
  {
    return CExampleUnitTest::_CExampleMock->multiply(x, y);
  }

  float sum(float x, int y) 
  {
    return CExampleUnitTest::_CExampleMock->divide(x, y);
  }

  // Tests
  TEST_F(CExampleUnitTest, sum)
  {
    EXPECT_CALL(*_CExampleMock, sum(5, 10)).Times(1).WillOnce(testing::Return(25));
    EXPECT_EQ(25, sum(5, 10));
  }

  int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
  }
