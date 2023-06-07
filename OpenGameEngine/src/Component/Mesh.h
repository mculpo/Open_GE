#ifndef __MESH_H__
#define __MESH_H__
#include <Core/tspch.h>
#include <Component/Component.h>
#include <Renderer/ElementBufferObject.h>
#include <Renderer/VertexBufferObject.h>
#include <Renderer/VertexArrayObject.h>
#include <Core/Vertex.h>
#include <Core/Vertex.h>


namespace openge {
	struct MeshData {
		std::vector<Vector3> positions;
		std::vector<Vector3> normals;
		std::vector<Vector2> texCoords;
	};
	class Mesh : public Component
	{
	public:
		Mesh() {};
		~Mesh() {};

		void setup();
		void disableVertexAttribArray();

		void setMeshData(MeshData& meshData);
		void setIndices(std::vector<unsigned int>& indices);
		void setVertices(std::vector<Vertex>& vertices);

		void setVAO(ref<VertexArrayObject> vao);
		void setVBO(ref<VertexBufferObject> vbo);
		void setEBO(ref<ElementBufferObject> ebo);

		void useVAO() const;
		void useVBO() const;
		void useEBO() const;
	private:
		std::vector<Vector3> m_positions;
		std::vector<Vector3> m_normals;
		std::vector<Vector2> m_texCoords;
		std::vector<unsigned int> m_indices;
		std::vector<Vertex> m_vertices;

		ref<VertexArrayObject> m_vao;
		ref<VertexBufferObject> m_vbo;
		ref<ElementBufferObject> m_ebo;
	};

}
#endif // !__MESH_H__





