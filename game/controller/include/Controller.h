#pragma once

#include "Model.h"

namespace Game {
    class Controller {
    public:
        Controller(Model* model);

    private:
        Model* model_;
    };
}