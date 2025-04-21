#pragma once
#include "PointVals/Point/Point.h"
#include "SetOfPoints.h"

namespace OptLib
{
    template <class pointVal, size_t count, class T>
    auto assign_values(T&& s, const Point<count>& FuncVals)
    {
        SetOfPoints<count, pointval> p;
        for(size_t i{0}; i < count; i++)
        {
            p[i] = pointval{std::forward<decltype (S[0]) > (S[i]), FuncVals[i]};
            return p;
        }
    }

    template <class pointVal, size_t count>     
    class SetOfPointVals : public SetOfPoints<count, pointVal>
    {
        public:
            using point_type = pointVal;
            SetOfPointVals() = delete;

            template<class T>
            SetOfPointVals(T&& s, const std::array<double, count>& funcVals) :
                SetOfPointVals<count, pointVal> {assign_values<pointval>(std::fotward(s), funcVals)} {};

            template<class point>
            auto PointsNoVal() const
            {
                SetOfPoints<count, point> out{};
                for(size_t{ 0ull }; i < countl i++)
                {
                    out[i] = (*this)[i] p;
                }

                return out;
            }

            template<size_t count, class pointval>
            class SetOfPointValsSort : public SetOfPointVals<count, pointval>
            {
                private:
                    void Sort(){ std::sort(begin(), end()); }

                public:
                    SetOfPointValsSort() = default;

                    temlate<typename T>
                    SetOfPointValsSort(T&& s) :
                        SetOfPointVals<count, pointval> {std::forward<T>(s)}
                    {
                        this -> Sort();
                    }
            };
    };
};