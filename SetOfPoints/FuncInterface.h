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

    namespace Funcinterface
    {
        template<size_t dim>
        class IFunc
        {
            public:
                virtual double operator() (const Point<dim>&) const = 0;

                template<size_t count>
                auto operator() (const SetOfPoints<count, Point<dim>>& x)
                {
                    Point<count> out;
                    for(size_t i{0ull}; i < count; ++i)
                        out[i] = (*this)(x[i]);
                    return out;
                }
        };

        template<size_t dim>
        static auto CreateFromPoint(Point<dim>&& p, const IFunc<dim>* f)
        {
            PointVal<dim> out;
            out.p = std::move(p);
            out.value = (*f)(out.p);
            return out;
        }

        template<size_t dim>
        class IGrad
        {
            virtual Grad<dim> grad(const Point<dim>&) const = 0;

            template<size_t count>
            auto grad(const SetOfPoints<count, Point<dim>> & x) const
            {
                SetOfPoints<count, Grad<dim>> out;
                for(size_t i{0}; i < count; ++i)
                    out[i] = (*this).grad(x[i]);
                return out;
            }
        };

        template<size_t dim>
        class IHess { virtual Hess<dim> hess(const Point<dim>&) const = 0; };

        template<size_t dim>
        class IFuncWithGrad : public IFunc<dim>, public IGrad<dim> {};

        template<size_t dim>
        class IFuncWithHess : public IFuncWithGrad<dim>, public IHess<dim> {};
    }
}