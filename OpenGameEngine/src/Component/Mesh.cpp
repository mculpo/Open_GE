#include "Mesh.h"
namespace openge {
	void Mesh::setup()
	{
		setVAO(std::make_shared<VertexArrayObject>());
		setVBO(std::make_shared<VertexBufferObject>(m_vertices.data(), m_vertices.size() * sizeof(Vertex), GL_STATIC_DRAW));
		//setEBO(std::make_shared<ElementBufferObject>(m_indices.data(), m_indices.size() * sizeof(unsigned int), GL_STATIC_DRAW));
		
		m_vao->AddLayout(3, VP_FLOAT); // aPos
		m_vao->AddLayout(3, VP_FLOAT); // aNormal
		m_vao->AddLayout(2, VP_FLOAT); // aTexCoords

		m_vao->runLayout();

		m_vbo->Unbind();
		m_vao->Unbind();
	}

	void Mesh::disableVertexAttribArray()
	{
		m_vao->runLayout();
	}

	void Mesh::setMeshData(MeshData& meshData)
	{
		m_positions = meshData.positions;
		m_normals = meshData.normals;
		m_texCoords = meshData.texCoords;
	}

	void Mesh::setIndices(std::vector<unsigned int>& indices)
	{
		m_indices = indices;
	}

	void Mesh::setVertices(std::vector<Vertex>& vertices)
	{
		m_vertices = vertices;
	}

	void Mesh::setVAO(ref<VertexArrayObject> vao)
	{
		m_vao = std::move(vao);
	}

	void Mesh::setVBO(ref<VertexBufferObject> vbo) 
	{
		m_vbo = std::move(vbo);
	}
	void Mesh::setEBO(ref<ElementBufferObject> ebo) 
	{
		m_ebo = std::move(ebo);
	}

	void Mesh::useVAO() const
	{
		m_vao.get()->Bind();
	}
	void Mesh::useVBO() const
	{
		m_vbo.get()->Bind();
	}
	void Mesh::useEBO() const
	{
		m_ebo.get()->Bind();
	}
}