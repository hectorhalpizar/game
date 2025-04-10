#ifndef __GAME_UTILS_UNIT_TESTS_ASSERTS_HPP__
#define __GAME_UTILS_UNIT_TESTS_ASSERTS_HPP__

namespace GameUtills {
	namespace UnitTesting {
		class AssertExtension {
			public:
				static void AreEqual(double expected, double result, double epsilon);
				static void AreEqual(double expected, double result);
		};
	}
}

#endif // __GAME_UTILS_UNIT_TESTS_ASSERTS_HPP__