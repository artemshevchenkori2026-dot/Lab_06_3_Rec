#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_06_3_Rec/Lab_06_3_Rec.cpp" // Перевірте шлях до вашого файлу

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
    TEST_CLASS(UnitTest_Lab06_3_Rec)
    {
    public:
        TEST_METHOD(TestMethod_RecursiveMinOddElement)
        {
            // Тестовий масив з непарними числами: -5, 15, 3
            // Найменше з непарних: -5
            int testArray[] = { 10, -5, 14, 15, 3, 20 };
            int size = 6;

            int expectedMinOdd = -5;

            // Перевірка звичайної рекурсивної функції
            Assert::AreEqual(expectedMinOdd, MinOddElement(testArray, size));

            // Перевірка шаблонної рекурсивної функції
            Assert::AreEqual(expectedMinOdd, MinOddElement<int>(testArray, size));
        }
    };
}