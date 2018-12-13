#pragma once

#include "Component.h"
#include <glfw/GLFW/glfw3.h>

namespace YEngine
{
	struct Viewport
	{
		GLfloat x;
		GLfloat y;
		GLfloat width;
		GLfloat height;
	};

	class CameraComponent :	public DerivedComponent<CameraComponent>
	{
	protected:
		Viewport m_VP;
	
		mat4 m_View;
		mat4 m_Projection;
	
		vec3 m_UpVector;
		vec3 m_RightVector;
		vec3 m_ForwardVector;
		vec3 m_Position;
	
		float m_FoV;
		float m_FarPlane;
		float m_NearPlane;
		float m_AspectRatio;
	
		bool m_Active;
		size_t m_RenderDepth;
	public:
		CameraComponent();
		virtual ~CameraComponent() {}
	
		virtual void init();
		virtual void update(float dt);
		virtual void cleanup();
	
		void rebuildAll();
		void rebuildView();
		void rebuildProjection();
	
		const mat4& getView() const;
		const mat4& getProjection() const;
	
		Viewport getViewport() const;
		void setViewport(Viewport val);
		vec3 getUpVector() const;
		void setUpVector(vec3 val);
		vec3 getRightVector() const;
		void setRightVector(vec3 val);
		vec3 getForwardVector() const;
		void setForwardVector(vec3 val);
		vec3 getPosition() const;
		void setPosition(vec3 val);
		float getFieldOfView() const;
		void setFieldOfView(float val);
		float getFarPlane() const;
		void setFarPlane(float val);
		float getNearPlane() const;
		void setNearPlane(float val);
		float getAspectRatio() const;
		void setAspectRatio(float val);
		bool getActive() const;
		void setActive(bool val);
		size_t getRenderDepth() const;
		void setRenderDepth(size_t val);
	};
}
