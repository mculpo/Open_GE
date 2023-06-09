#include <Core/tspch.h>
#include <Renderer/Shader.h>
#include <Renderer/Texture.h>
#ifndef __MATERIAL_H__
#define __MATERIAL_H__
namespace openge {
    class Texture;
    class Shader;

    class Material {
    public:
        Material();
        Material(ref<Shader> shader);
        ~Material();

        void setTexture(const std::string& name, ref<Texture> texture);
        ref<Texture> getTexture() const;

        void setShader(ref < Shader> shader);
        ref<Shader> getShader() const;

        void setup();
        void bind();
    private:
        // Propriedades adicionais
        std::string m_name;
        ref<Shader> m_shader;
        std::map<std::string, ref<Texture>> m_textures;
    };
}
#endif

