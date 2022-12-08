#include "Framework.h"
#include "GameObject.h"

GameObject::GameObject(fw::Mesh* pMesh, fw::ShaderProgram* pShader, fw::Texture* pTexture, vec2 pos, float angle, vec2 scale)
{
    fw::Transform* tempTransform = new fw::Transform;
    tempTransform->m_Angle = angle;
    tempTransform->m_Pos = pos;
    tempTransform->m_Scale = scale;

    fw::Renderable* tempRenderable = new fw::Renderable;
    tempRenderable->m_pMesh = pMesh ;
    tempRenderable->m_pShader = pShader;
    tempRenderable->m_pTexture = pTexture;

    m_pComponents.push_back(tempTransform);
    m_pComponents.push_back(tempRenderable);


}

GameObject::~GameObject()
{
    for (fw::BaseComponent* component : m_pComponents)
    {
        delete component;
    }
}

void GameObject::Update(float deltaTime)
{
}

void GameObject::Draw()
{
    fw::Renderable* tempR = nullptr;
    fw::Transform* tempT = nullptr;

    for (fw::BaseComponent* component : m_pComponents)
    {
        tempR = dynamic_cast<fw::Renderable*>(component);
        if (tempR != nullptr)
        {
            break;
        }
    }

    for (fw::BaseComponent* component : m_pComponents)
    {
        tempT = dynamic_cast<fw::Transform*>(component);
        if (tempT != nullptr)
        {
            break;
        }
    }

    if (tempR != nullptr && tempT != nullptr)
    {
        tempR->m_pMesh->Draw(tempR->m_pShader, tempR->m_pTexture, tempT, 1);
    }
}
