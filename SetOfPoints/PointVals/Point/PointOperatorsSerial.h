#pragma once
#include <functional>
#include <algorithm>
#include <cmath>
#include "Point.h"
#include "PointOperatorsImpl.h"

namespace OptLib
{
	#pragma region PLUS
	template <size_t dim>
	auto operator + (const Point<dim>& lhs, const Point<dim>& rhs)
	{
		Point<dim> result;
		std::transform(lhs.begin(), lhs.end(), rhs.begin(), result.begin(), PointOps::BinaryOps::plus<double>{});
		return result;
	}

	template <size_t dim>
	auto operator + (const Point<dim>& lhs, double a)
	{
		Point<dim> result;
		std::transform(lhs.begin(), lhs.end(), result.begin(), PointOps::UnaryOps::plus<double>{a});
		return result;
	}

	template <size_t dim>
	auto operator + (double a, const Point<dim>& rhs)
	{
		Point<dim> result;
		std::transform(rhs.begin(), rhs.end(), result.begin(), PointOps::UnaryOps::plus<double>{a});
		return result;
	}

	template <size_t dim>
	auto& operator += (Point<dim>& lhs, double a)
	{
		std::transform(lhs.begin(), lhs.end(), lhs.begin(), PointOps::UnaryOps::plus<double>{a});
		return lhs;
	}
	#pragma endregion

	#pragma region MINUS
	template <size_t dim>
	auto operator - (const Point<dim>& lhs, const Point<dim>& rhs)
	{
		Point<dim> result;
		std::transform(lhs.begin(), lhs.end(), rhs.begin(), result.begin(), PointOps::BinaryOps::minus<double>{});
		return result;
	}

	template <size_t dim>
	auto operator - (const Point<dim>& lhs, double a)
	{
		Point<dim> result;
		std::transform(lhs.begin(), lhs.end(), result.begin(), PointOps::UnaryOps::minus<double>{a});
		return result;
	}

	template <size_t dim>
	auto operator - (double a, const Point<dim>& rhs)
	{
		Point<dim> result;
		std::transform(rhs.begin(), rhs.end(), result.begin(), PointOps::UnaryOps::minus<double>{a});
		return result;
	}

	template <size_t dim>
	auto& operator -= (Point<dim>& lhs, double a)
	{
		std::transform(lhs.begin(), lhs.end(), lhs.begin(), PointOps::UnaryOps::minus<double>{a});
		return lhs;
	}
	#pragma endregion

	#pragma region MULTIPLIES
	template <size_t dim>
	auto operator * (const Point<dim>& lhs, const Point<dim>& rhs)
	{
		Point<dim> result;
		std::transform(lhs.begin(), lhs.end(), rhs.begin(), result.begin(), PointOps::BinaryOps::multiplies<double>{});
		return result;
	}

	template <size_t dim>
	auto operator * (const Point<dim>& lhs, double a)
	{
		Point<dim> result;
		std::transform(lhs.begin(), lhs.end(), result.begin(), PointOps::UnaryOps::multiplies<double>{a});
		return result;
	}

	template <size_t dim>
	auto operator * (double a, const Point<dim>& rhs)
	{
		Point<dim> result;
		std::transform(rhs.begin(), rhs.end(), result.begin(), PointOps::UnaryOps::multiplies<double>{a});
		return result;
	}

	template <size_t dim>
	auto& operator *= (Point<dim>& lhs, double a)
	{
		std::transform(lhs.begin(), lhs.end(), lhs.begin(), PointOps::UnaryOps::multiplies<double>{a});
		return lhs;
	}
	#pragma endregion

	#pragma region DIVIDES
	template <size_t dim>
	auto operator / (const Point<dim>& lhs, const Point<dim>& rhs)
	{
		Point<dim> result;
		std::transform(lhs.begin(), lhs.end(), rhs.begin(), result.begin(), PointOps::BinaryOps::divides<double>{});
		return result;
	}

	template <size_t dim>
	auto operator / (const Point<dim>& lhs, double a)
	{
		Point<dim> result;
		std::transform(lhs.begin(), lhs.end(), result.begin(), PointOps::UnaryOps::divides<double>{a});
		return result;
	}

	template <size_t dim>
	auto operator / (double a, const Point<dim>& rhs)
	{
		Point<dim> result;
		std::transform(rhs.begin(), rhs.end(), result.begin(), PointOps::UnaryOps::divides<double>{a});
		return result;
	}

	template <size_t dim>
	auto& operator /= (Point<dim>& lhs, double a)
	{
		std::transform(lhs.begin(), lhs.end(), lhs.begin(), PointOps::UnaryOps::divides<double>{a});
		return lhs;
	}
	#pragma endregion

	#pragma region ABS
	template <size_t dim>
	auto& abs (Point<dim>& lhs)
	{
		std::transform(lhs.begin(), lhs.end(), lhs.begin(), PointOps::UnaryOps::abs<double>{});
		return lhs;
	}
	#pragma endregion

	#pragma region SQRT
	template <size_t dim>
	auto& sqrt(Point<dim>& lhs)
	{
		std::transform(lhs.begin(), lhs.end(), lhs.begin(), PointOps::UnaryOps::sqrt<double>{});
		return lhs;
	}
	#pragma endregion
}