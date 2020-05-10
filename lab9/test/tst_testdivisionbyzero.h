#ifndef TST_TESTDIVISIONBYZERO_H
#define TST_TESTDIVISIONBYZERO_H

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "lockcontroller.h"
using namespace testing;
using ::testing::Return;

class MockIKeypad : public IKeypad {
 public:
  MOCK_METHOD(bool, isActive, (), (override));
  MOCK_METHOD(void, wait, (), (override));
  MOCK_METHOD(PasswordResponse, requestPassword, (), (override));
};

class MockILatch : public ILatch {
 public:
  MOCK_METHOD(bool, isActive, (), (override));
  MOCK_METHOD(DoorStatus, open, (), (override));
  MOCK_METHOD(DoorStatus, close, (), (override));
  MOCK_METHOD(DoorStatus, getDoorStatus, (), (override));
};


TEST(Calculator, wait)
{
    MockIKeypad keypad;
    MockILatch latch;
    LockController lc = LockController(&keypad, &latch);

    EXPECT_CALL(keypad, wait())
            .Times(1);
    lc.wait();
}

TEST(Calculator, isDoorOpen_lock)
{
    MockIKeypad keypad;
    MockILatch latch;
    LockController lc = LockController(&keypad, &latch);


    EXPECT_CALL(latch, getDoorStatus())
            .Times(1)
            .WillOnce(Return(DoorStatus::CLOSE));
    bool res = lc.isDoorOpen();
    EXPECT_FALSE(res);
}

TEST(Calculator, isDoorOpen_unlock)
{
    MockIKeypad keypad;
    MockILatch latch;
    LockController lc = LockController(&keypad, &latch);


    EXPECT_CALL(latch, getDoorStatus())
            .Times(1)
            .WillOnce(Return(DoorStatus::OPEN));
    bool res = lc.isDoorOpen();
    EXPECT_TRUE(res);
}

TEST(Calculator, unlockDoor)
{
    MockIKeypad keypad;
    MockILatch latch;
    LockController lc = LockController(&keypad, &latch);


    EXPECT_CALL(latch, open())
            .Times(1)
            .WillOnce(Return(DoorStatus::OPEN));

    EXPECT_EQ(lc.unlockDoor(), DoorStatus::OPEN);
}

TEST(Calculator, lockDoor)
{
    MockIKeypad keypad;
    MockILatch latch;
    LockController lc = LockController(&keypad, &latch);

    EXPECT_CALL(latch, close())
            .Times(1)
            .WillOnce(Return(DoorStatus::CLOSE));

    EXPECT_EQ(lc.lockDoor(), DoorStatus::CLOSE);
}

TEST(Calculator, hardWareCheck_ok)
{
    MockIKeypad keypad;
    MockILatch latch;
    LockController lc = LockController(&keypad, &latch);

    EXPECT_CALL(keypad, isActive())
            .Times(1)
            .WillOnce(Return(true));

    EXPECT_CALL(latch, isActive())
            .Times(1)
            .WillOnce(Return(true));

    auto res = lc.hardWareCheck();
    EXPECT_EQ(res, HardWareStatus::OK);
}

TEST(Calculator, hardWareCheck_error)
{
    MockIKeypad keypad;
    MockILatch latch;
    LockController lc = LockController(nullptr, &latch);

    EXPECT_CALL(keypad, isActive())
            .Times(AtLeast(0))
            .WillOnce(Return(true));

    EXPECT_CALL(latch, isActive())
            .Times(AtLeast(0))
            .WillOnce(Return(true));

    auto res = lc.hardWareCheck();
    EXPECT_EQ(res, HardWareStatus::ERROR);
}

TEST(Calculator, hardWareCheck_error_2)
{
    MockIKeypad keypad;
    MockILatch latch;
    LockController lc = LockController(&keypad, &latch);

    EXPECT_CALL(keypad, isActive())
            .Times(AtLeast(0))
            .WillOnce(Return(true));

    EXPECT_CALL(latch, isActive())
            .Times(AtLeast(0))
            .WillOnce(Return(false));

    auto res = lc.hardWareCheck();
    EXPECT_EQ(res, HardWareStatus::ERROR);
}

TEST(Calculator, isCorrectPassword)
{
    MockIKeypad keypad;
    MockILatch latch;
    LockController lc = LockController(&keypad, &latch);

    PasswordResponse ans;
    ans.status = PasswordResponse::Status::OK;
    ans.password = "0000";

    EXPECT_CALL(keypad, requestPassword())
            .Times(1)
            .WillOnce(Return(ans));

    auto res = lc.isCorrectPassword();
    EXPECT_TRUE(res);
}

TEST(Calculator, isCorrectPassword_error)
{
    MockIKeypad keypad;
    MockILatch latch;
    LockController lc = LockController(&keypad, &latch);

    PasswordResponse ans;
    ans.status = PasswordResponse::Status::OK;
    ans.password = "1234";

    EXPECT_CALL(keypad, requestPassword())
            .Times(1)
            .WillOnce(Return(ans));

    auto res = lc.isCorrectPassword();
    EXPECT_FALSE(res);
}

TEST(Calculator, resetPassword)
{
    MockIKeypad keypad;
    MockILatch latch;
    LockController lc = LockController(&keypad, &latch);

    PasswordResponse new_pass;
    new_pass.status = PasswordResponse::Status::OK;
    new_pass.password = "1234";

    PasswordResponse old_pass;
    old_pass.status = PasswordResponse::Status::OK;
    old_pass.password = "0000";

    EXPECT_CALL(keypad, requestPassword())
            .Times(2)
            .WillOnce(Return(old_pass))
            .WillOnce(Return(new_pass));

    lc.resetPassword();

    EXPECT_CALL(keypad, requestPassword())
            .Times(1)
            .WillOnce(Return(new_pass));

    auto res = lc.isCorrectPassword();
    EXPECT_TRUE(res); 
}

TEST(Calculator, resetPassword_2)
{
    MockIKeypad keypad;
    MockILatch latch;
    LockController lc = LockController(&keypad, &latch);

    PasswordResponse default_pass;
    default_pass.status = PasswordResponse::Status::OK;
    default_pass.password = "0000";

    PasswordResponse old_pass;
    old_pass.status = PasswordResponse::Status::OK;
    old_pass.password = "9786";

    EXPECT_CALL(keypad, requestPassword())
            .Times(2)
            .WillOnce(Return(default_pass))
            .WillOnce(Return(old_pass));
    lc.resetPassword();


    PasswordResponse new_pass;
    new_pass.status = PasswordResponse::Status::OK;
    new_pass.password = "1234";

    EXPECT_CALL(keypad, requestPassword())
            .Times(2)
            .WillOnce(Return(old_pass))
            .WillOnce(Return(new_pass));
    lc.resetPassword();

    EXPECT_CALL(keypad, requestPassword())
            .Times(1)
            .WillOnce(Return(new_pass));

    auto res = lc.isCorrectPassword();
    EXPECT_TRUE(res); 
}


#endif // TST_TESTDIVISIONBYZERO_H
