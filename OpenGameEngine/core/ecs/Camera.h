#ifndef __CAMERA_H__
#define __CAMERA_H__

#include "Component.h"
#include "Transform.h"
#include "Entity.h"
#include <glm/glm.hpp>
namespace openge {
	class Transform;
	enum class CameraType {
		Perpective,
		Orthographic
	};

	class Camera : public Component
	{
	private:
		glm::vec3 m_front;
		glm::vec3 m_up;
		float m_fov;
		float m_aspectRatio;
		float m_nearPlane;
		float m_farPlane;
		CameraType m_type;
	public:
		Camera(Entity& entity,std::uint64_t id, glm::vec3& front, glm::vec3& up, float fov, float aspectRatio, float nearPlane, float farPlane, CameraType type);
		Camera(Entity& entity, std::uint64_t id);
		~Camera();

		glm::mat4 getViewMatrix();
		glm::mat4 getProjectionMatrix();

		void setCameraType(const CameraType value);
		void setFov(const float value);
		void setAspectRatio(const float value);
		void setNearPlane(const float value);
		void setFarPlane(const float value);
		void setFront(const glm::vec3& front);
		void setUp(const glm::vec3& up);


		CameraType getCameraType() const;
		float getFov()const;
		float getAspectRatio()const;
		float getNearPlane()const;
		float getFarPlane()const;
		glm::vec3 getFront()const;
		glm::vec3 getUp()const;

	};
}
#endif
