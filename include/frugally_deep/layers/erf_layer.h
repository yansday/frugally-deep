// Copyright 2016, Tobias Hermann.
// https://github.com/Dobiasd/frugally-deep
// Distributed under the MIT License.
// (See accompanying LICENSE file or at
//  https://opensource.org/licenses/MIT)

#pragma once

#include "frugally_deep/layers/actication_layer.h"

namespace fd
{

class erf_layer : public actication_layer
{
private:
    erf_layer(const size3d& size_in)
        : actication_layer(size_in)
    {
    }
    matrix3d transform_input(const matrix3d& in_vol) const override
    {
        auto actication_function = [](float_t x) -> float_t
        {
            return std::erf(x);
        };
        return transform_matrix3d(actication_function, in_vol);
    }
};

} // namespace fd
