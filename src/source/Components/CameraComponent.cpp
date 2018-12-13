#include "Components/CameraComponent.h"
#include <glm/gtc/matrix_transform.hpp>

namespace YEngine
{
	CameraComponent::CameraComponent()
	{
		m_VP.x = 0.0f;
		m_VP.y = 0.0f;
		m_VP.width = 800.0f;
		m_VP.height = 600.0f;
	
		m_Position = vec3(0.0f, 0.0f, 0.0f);
		m_UpVector = vec3(0.0f, 1.0f, 0.0f);
		m_RightVector = vec3(1.0f, 0.0f, 0.0f);
		m_ForwardVector = vec3(0.0f, 0.0f, 1.0f);
	
		m_FoV = 45.0f;
		m_FarPlane = 1000.0f;
		m_NearPlane = 1.0f;
		m_AspectRatio = m_VP.width / m_VP.height;
	
		m_Active = false;
		m_RenderDepth = 0;
	}
	
	void CameraComponent::init()
	{
		this->rebuildAll();
	}
	
	void CameraComponent::update(float dt)
	{
	
	}
	
	void CameraComponent::cleanup()
	{
	
	}
	
	void CameraComponent::rebuildAll()
	{
		this->rebuildView();
		this->rebuildProjection();
	}
	
	void CameraComponent::rebuildView()
	{
		m_View = lookAt(m_Position, m_ForwardVector, m_UpVector);
	}
	
	void CameraComponent::rebuildProjection()
	{
		m_Projection = glm::perspectiveFovLH_NO(glm::radians(m_FoV), m_VP.width, m_VP.height, m_NearPlane, m_FarPlane);
	}
	
	YEngine::Viewport CameraComponent::getViewport() const
	{
		return m_VP;
	}
	
	void CameraComponent::setViewport(Viewport val)
	{
		m_VP = val;
	}
	
	const mat4& CameraComponent::getView() const
	{
		return m_View;
	}
	
	const mat4& CameraComponent::getProjection() const
	{
		return m_Projection;
	}
	
	vec3 CameraComponent::getUpVector() const
	{
		return m_UpVector;
	}
	
	void CameraComponent::setUpVector(vec3 val)
	{
		m_UpVector = val;
	}
	
	vec3 CameraComponent::getRightVector() const
	{
		return m_RightVector;
	}
	
	void CameraComponent::setRightVector(vec3 val)
	{
		m_RightVector = val;
	}
	
	vec3 CameraComponent::getForwardVector() const
	{
		return m_ForwardVector;
	}
	
	void CameraComponent::setForwardVector(vec3 val)
	{
		m_ForwardVector = val;
	}
	
	vec3 CameraComponent::getPosition() const
	{
		return m_Position;
	}
	
	void CameraComponent::setPosition(vec3 val)
	{
		m_Position = val;
	}
	
	float CameraComponent::getFieldOfView() const
	{
		return m_FoV;
	}
	
	void CameraComponent::setFieldOfView(float val)
	{
		m_FoV = val;
	}
	
	float CameraComponent::getFarPlane() const
	{
		return m_FarPlane;
	}
	
	void CameraComponent::setFarPlane(float val)
	{
		m_FarPlane = val;
	}
	
	float CameraComponent::getNearPlane() const
	{
		return m_NearPlane;
	}
	
	void CameraComponent::setNearPlane(float val)
	{
		m_NearPlane = val;
	}
	
	float CameraComponent::getAspectRatio() const
	{
		return m_AspectRatio;
	}
	
	void CameraComponent::setAspectRatio(float val)
	{
		m_AspectRatio = val;
	}
	
	bool CameraComponent::getActive() const
	{
		return m_Active;
	}
	
	void CameraComponent::setActive(bool val)
	{
		m_Active = val;
	}
	
	size_t CameraComponent::getRenderDepth() const
	{
		return m_RenderDepth;
	}
	
	void CameraComponent::setRenderDepth(size_t val)
	{
		m_RenderDepth = val;
	}
}
