#pragma once
#include "BaseComponent.h"
#include "Math/Vector.h"

namespace fw 
{
    class Mesh;
    class ShaderProgram;
    class Texture;

    class Transform : public BaseComponent
    {
    public:
        vec2 m_Pos = vec2(0, 0);
        float m_Angle = 0;
        vec2 m_Scale = vec2(1, 1);
    };

    class Renderable : public BaseComponent
    {
    public:
        Mesh* m_pMesh = nullptr;
        ShaderProgram* m_pShader = nullptr;
        Texture* m_pTexture = nullptr;
    };
}
