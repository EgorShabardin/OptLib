#pragma once
#include "FuncInterface.h"
#include "PointVals/Point/Point.h"
#include "PointVals/Point/PointOperators.h"

namespace OptLib
{
    template<size_t dim>
    class Plane : public Funcinterface::IFunc<dim>
    {
        protected:
            Point<dim> c;

        public:
            using Funcinterface::IFunc<dim>::operator();
            Plane(const Point<dim>& c) : c{c} {};

            double operator()(const Point<dim>& x) const override
            {
                return dot_product(c, x);
            }
    };
}