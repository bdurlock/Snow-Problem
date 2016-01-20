#include "stdafx.h"
#include "CppUnitTest.h"
#include "TreeFactory.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Testing
{
	TEST_CLASS(CTreeFactoryTest)
	{
	public:
		
		TEST_METHOD(TestCTreeFactoryCreate)
		{

            CTreeFactory factory;
            auto tree = factory.CreateTree();
            Assert::IsTrue(tree != nullptr);
		}

	};
}