#pragma once
#include <cassert>
#include <cmath>
#include "Point/Point.h"

namespace OptLib
{
	template<size_t dim>
	struct PointVal
	{
		Point<dim> point;
		double value;

		PointVal() = default;
		PointVal(const PointVal&) = default;
		PointVal(PointVal&&) = default;

		PointVal<dim>& operator = (const PointVal&) = default;
		PointVal<dim>& operator = (PointVal&&) = default;

		template<typename T>
		PointVal(T&& point, double value) : point{ std::forward<T>(point) }, value{ value } {};

		template<typename T>
		PointVal(const T& point, double value) : point{ point }, value{ value } {};

		auto operator [] (size_t i) const
		{
			return point[i];
		}

		auto operator + (const PointVal<dim>& rhs) const
		{
			return PointVal(point + rhs.point, value + rhs.value);
		}

		auto operator - (const PointVal<dim>& rhs) const
		{
			return PointVal(point - rhs.point, value - rhs.value);
		}

		auto operator * (const PointVal<dim>& rhs) const
		{
			return PointVal(point * rhs.point, value * rhs.value);
		}

		auto operator / (const PointVal<dim>& rhs) const
		{
			assert(rhs.value != 0);
			assert(
				std::none_of(
					rhs.point.cbegin(), rhs.point.cend(), [](double x)
					{
						return x == 0.0;
					}
				)
			);

			return PointVal(point / rhs.point, value / rhs.value);
		}

		auto operator < (const PointVal<dim>& rhs) const
		{
			return value < rhs.value;
		}
	};

	template<size_t dim, typename Stream>
	auto& operator << (Stream& o, const PointVal<dim>& p)
	{
		o << p.point << ", " << p.value;

		return o;
	};
}