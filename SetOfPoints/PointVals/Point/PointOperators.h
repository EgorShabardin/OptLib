#pragma once
#include <cassert>
#include <numeric>
#include <cmath>
#include "Point.h"
#include "PointOperatorsSerial.h"

namespace OptLib
{
	template<size_t dim, typename Stream>
	auto& operator << (Stream& o, const Point<dim>& p)
	{
		static_assert(dim > 0);
		o << "{" << p[0];

		if constexpr (dim > 1)
		{
			for (size_t i{ 1 }; i < dim; ++i)
			{
				o << ", " << p[i];
			}

			o << "}";
		}

		return o;
	}

	template<size_t dim>
	auto dot_product(const Point<dim>& x, const Point<dim>& y)
	{
		Point<dim> vector = x * y;
		double result = std::accumulate(vector.begin(), vector.end(), 0.0);
		return result;
	}

	template<size_t dim>
	auto norm(const Point<dim>& x)
	{
		return std::sqrt(dot_product(x, x));
	}

	template<size_t dim>
	auto dist(const Point<dim>& x, const Point<dim>& y)
	{
		return norm(x - y);
	}
}