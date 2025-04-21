#pragma once
#include<array>

namespace OptLib
{
	template<size_t dim>
	using RawPoint = std::array<double, dim>;

	template<size_t dim>
	struct Point : private RawPoint<dim>
	{
		public:
			using RawPoint<dim>::RawPoint;
			using RawPoint<dim>::operator[];
			using RawPoint<dim>::size;
			using RawPoint<dim>::begin;
			using RawPoint<dim>::end;
			using RawPoint<dim>::cbegin;
			using RawPoint<dim>::cend;
			using RawPoint<dim>::iterator;
			using RawPoint<dim>::const_iterator;
			using RawPoint<dim>::reverse_iterator;
			using RawPoint<dim>::value_type;

			Point() noexcept = default;
			Point(const Point&) noexcept = default;
			Point& operator = (Point&&) noexcept = default;
			Point& operator = (const Point&&) noexcept;

			template<typename T>
			Point(T&& p) noexcept : RawPoint<dim>{ std::forward<T>(p) } {}

			template<typename ...Args>
			Point(Args... a) noexcept : RawPoint<dim>{ a... } {}
	};
};