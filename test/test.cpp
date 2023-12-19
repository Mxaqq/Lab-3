

#include "..\TStack.h"
#include "..\TFormula.h"

#include <gtest.h>

// Тестирование метода IsEmpty
TEST(TStack, IsEmpty_WhenEmpty_ShouldReturnTrue)
{
    TStack stack;
    EXPECT_TRUE(stack.IsEmpty());
}

TEST(TStack, IsEmpty_WhenNotEmpty_ShouldReturnFalse)
{
    TStack stack;
    stack.Put(5);
    EXPECT_FALSE(stack.IsEmpty());
}

// Тестирование метода IsFull
TEST(TStack, IsFull_WhenNotFull_ShouldReturnFalse)
{
    TStack stack;
    stack.Put(1);
    EXPECT_FALSE(stack.IsFull());
}

TEST(TStack, IsFull_WhenFull_ShouldReturnTrue)
{
    TStack stack;
    for (int i = 0; i < MaxLength; ++i) {
        stack.Put(i);
    }
    EXPECT_TRUE(stack.IsFull());
}

// Тестирование метода Put
TEST(TStack, Put_WhenNotFull_ShouldPutElement)
{
    TStack stack;
    stack.Put(3);
    EXPECT_EQ(stack.Peek(), 3);
}

TEST(TStack, Put_WhenFull_ShouldPrintErrorMessage)
{
    testing::internal::CaptureStderr();
    TStack stack;
    for (int i = 0; i < MaxLength; ++i) {
        stack.Put(i);
    }
    stack.Put(100);
    std::string output = testing::internal::GetCapturedStderr();
    EXPECT_EQ(output, "Stack overflow!\n");
}
// Тестирование метода Peek
TEST(TStack, Peek_WhenNotEmpty_ShouldReturnTopElement)
{
    TStack stack;
    stack.Put(10);
    stack.Put(20);
    stack.Put(30);
    EXPECT_EQ(stack.Peek(), 30);
}

TEST(TStack, Peek_WhenEmpty_ShouldPrintErrorMessage)
{
    testing::internal::CaptureStderr();
    TStack stack;
    stack.Peek();
    std::string output = testing::internal::GetCapturedStderr();
    EXPECT_EQ(output, "Stack is empty!\n");
}

// Тестирование метода Pop
TEST(TStack, Pop_WhenNotEmpty_ShouldRemoveAndReturnTopElement)
{
    TStack stack;
    stack.Put(7);
    stack.Put(14);
    EXPECT_EQ(stack.Pop(), 14);
    EXPECT_EQ(stack.Pop(), 7);
    EXPECT_TRUE(stack.IsEmpty());
}

TEST(TStack, Pop_WhenEmpty_ShouldPrintErrorMessage)
{
    testing::internal::CaptureStderr();
    TStack stack;
    stack.Pop();
    std::string output = testing::internal::GetCapturedStderr();
    EXPECT_EQ(output, "Stack is empty!\n");
}