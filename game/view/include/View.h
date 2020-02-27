#pragma once

#include "Model.h"

namespace Game {
    class View {
    public:
        View(Model* model);

    private:
        Model* model_;
    };
}