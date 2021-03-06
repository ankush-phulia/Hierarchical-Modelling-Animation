#include "Models_Manager.h"

using namespace Managers;
using namespace Rendering;

Models_Manager::Models_Manager() {
    Models::Frog* frog = new Models::Frog();
    frog->Create(glm::vec3(0.0f, 0.0f, 0.0f));
    gameModelList["frog"] = frog;
    passinggameModelList["frog"] = frog;

    Models::Frog* frog2 = new Models::Frog();
    frog2->Create(glm::vec3(0.0f, 0.0f, 20.0f));
    gameModelList["frog2"] = frog2;

    Models::Frog* frog3 = new Models::Frog();
    frog3->Create(glm::vec3(20.0f, 0.0f, 0.0f));
    gameModelList["frog3"] = frog3;
}

Models_Manager::~Models_Manager() {
    for (auto model : gameModelList) {
        delete model.second;
    }
    gameModelList.clear();
}

void Models_Manager::DeleteModel(const std::string& gameModelName) {
    IGameObject* model = gameModelList[gameModelName];
    model->Destroy();
    gameModelList.erase(gameModelName);
}

const IGameObject& Models_Manager::GetModel(
    const std::string& gameModelName) const {
    return (*gameModelList.at(gameModelName));
}

void Models_Manager::Update(glm::vec3 ins) {
    for (auto model : gameModelList) {
        passinggameModelList.erase(model.first);
        model.second->Update(ins, passinggameModelList);
        passinggameModelList[model.first] = model.second;
    }
}

void Models_Manager::Draw() {
    for (auto model : gameModelList) {
        model.second->Draw();
    }
}
