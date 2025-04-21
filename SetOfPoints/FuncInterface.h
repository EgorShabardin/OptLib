#pragma once
#include <array>
#include "PointVals/Point/Point.h"
#include "PointVals/PointVal.h"
#include "SetOfPoints.h"

namespace OptLib
{
    template<size_t dim>
    using Grad = Point<dim>;

    template<size_t dim>
    using Hess = SetOfPoints<dim, Grad<dim>>;

    namespace FuncInterface
    {
        template<size_t dim>
        class IFunc
        {
            public:
                virtual double operator() (const Point<dim>&) const = 0;

                template<size_t count>
                auto operator() (const SetOfPoints<count, Point<dim>& x)
                {
                    Point<count> out;
                    for(size_t i{0}; i < count; ++i)
                    {
                        out[i] = (*this)(x[i]);
                    }

                    return out;
                }
        };

        template<size_t dim>
        class HyperFunc : public IFunc<dim>
        {
            private:
                
        };
    }
}