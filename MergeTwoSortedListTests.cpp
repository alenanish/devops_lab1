#include "pch.h"
#include "CppUnitTest.h"
#include "..\MergeTwoSortedLists\Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MergeTwoSortedListTests
{
	TEST_CLASS(MergeTwoSortedListTests)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Assert::IsTrue(mergeTwoLists(1, 1) == "0->1->nullptr");
		}
		TEST_METHOD(TestMethod2)
		{
			Assert::IsTrue(mergeTwoLists(5, 5) == "0->1->2->3->4->5->6->7->8->9->nullptr");
		}
		TEST_METHOD(TestMethod3)
		{
			Assert::IsTrue(mergeTwoLists(6, 10) == "0->1->2->3->4->5->6->7->8->9->10->11->13->15->17->19->nullptr");
		}
	};
}
