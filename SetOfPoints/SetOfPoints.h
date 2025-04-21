#pragma once
#include <array>
#include <tuple>
#include <algorithm>

namespace OptLib
{
	template<size_t count, typename point>
	using RawSetOfPoints = std::array<point, count>;

	template<size_t count, typename point>
	struct SetOfPoints : private RawSetOfPoints
	{
		public:
			using RawSetOfPoints<count, point>::<count, point>;
			using RawSetOfPoints<count, point>::operator[];
			using RawSetOfPoints<count, point>::size;
			using RawSetOfPoints<count, point>::begin;
			using RawSetOfPoints<count, point>::end;
			using RawSetOfPoints<count, point>::cbegin;
			using RawSetOfPoints<count, point>::cend;
			using RawSetOfPoints<count, point>::iterator;
			using RawSetOfPoints<count, point>::const_iterator;
			using RawSetOfPoints<count, point>::reverse_iterator;
			using RawSetOfPoints<count, point>::value_type;

			SetOfPoints() = default;

			template<typename T>
			SetOfPoints(T&& p) : RawSetOfPoints<count, point>{ std::forward<T>(p) } {};

			template<typename... Args>
			SetOfPoints(Args... a) : RawSetOfPoints<count, point>{ a... } {};
	};
}