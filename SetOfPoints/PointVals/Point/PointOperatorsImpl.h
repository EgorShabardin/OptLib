#pragma once
#include <functional>
#include <cmath>

namespace OptLib
{
	namespace PointOps
	{
		namespace UnaryOps
		{
			template<class Scalar>
			struct plus
			{
				plus(Scalar value) : scalar{ value } {}
				constexpr Scalar operator() (const Scalar& lhs) const
				{
					return lhs + scalar;
				}

				protected:
					Scalar scalar;
			};

			template<class Scalar>
			struct minus
			{
				minus(Scalar value) : scalar{ value } {}
				constexpr Scalar operator() (const Scalar& lhs) const
				{
					return lhs - scalar;
				}

				protected:
					Scalar scalar;
			};

			template<class Scalar>
			struct multiplies
			{
				multiplies(Scalar value) : scalar{ value } {}
				constexpr Scalar operator() (const Scalar& lhs) const
				{
					return lhs * scalar;
				}

				protected:
					Scalar scalar;
			};

			template<class Scalar>
			struct divides
			{
				divides(Scalar value) : scalar{ value } {}
				constexpr Scalar operator() (const Scalar& lhs) const
				{
					return lhs / scalar;
				}

			protected:
				Scalar scalar;
			};

			template<class Scalar>
			struct sqrt
			{
				constexpr Scalar operator() (const Scalar& lhs) const
				{
					return std::sqrt(lhs);
				}
			};

			template<class Scalar>
			struct abs
			{
				constexpr Scalar operator() (const Scalar& lhs) const
				{
					return std::abs(lhs);
				}
			};
		};

		namespace BinaryOps
		{
			template<class T = void>
			using plus = std::plus<T>;

			template<class T = void>
			using minus = std::minus<T>;

			template<class T = void>
			using multiplies = std::multiplies<T>;

			template<class T = void>
			using divides = std::divides<T>;
		};
	};
};