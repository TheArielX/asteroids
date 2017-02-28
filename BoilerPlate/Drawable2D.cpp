#include "Drawable2D.hpp"
// OPENGL
#include <SDL2\SDL_opengl.h>

namespace Engine
{
	namespace Graphics
	{
		void Drawable2D::Translate(Math::Vector2 position)
		{
			m_position = position;
		}

		void Drawable2D::Draw(unsigned int mode, std::vector<Math::Vector2> points)
		{
			
			glLoadIdentity();
			
			glTranslatef(m_position.GetX(), m_position.GetY(), 0.0f);

			glRotatef(m_angle, 0.0f, 0.0f, 1.0f);

			glBegin(mode);
				for(auto point : points)
				{
					glVertex2f(point.GetX(), point.GetY());
				}				
			glEnd();
		}
	}
}