#pragma once
#include "../Core/IListener.h"
#include "../Core/WindowInfo.h"
#include "Models_Manager.h"

namespace Managers {
class Scene_Manager : public Core::IListener {
   public:
    Scene_Manager();
    ~Scene_Manager();
    virtual void NotifyBeginFrame();
    virtual void NotifyDisplayFrame();
    virtual void NotifyEndFrame();
    virtual void NotifyReshape(int width, int height, int previos_width,
                               int previous_height);
    Core::WindowInfo window;

   private:
    Managers::Models_Manager* models_manager;
};

}  // namespace Managers
