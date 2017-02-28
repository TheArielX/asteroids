#include "Vector2.hpp"
#include <cmath>

#include <string>
namespace Engine
{
	namespace Math
	{
		Vector2::Vector2()
			: m_x( 0.0f )
			, m_y( 0.0f )
			, m_length( 0.0f )
		{}

		Vector2::Vector2(float uniform)
			 : m_x(uniform)
			 , m_y(uniform)
			 , m_length(0)
			 {
				// Calculate length for the given point
				//
				Length();
			}

		Vector2::Vector2(float x, float y)
			: m_x( x )
			, m_y( y )
			, m_length( 0 )
		{
			// Calculate length for the given point
			//
			Length();
		}

		const float Vector2::GetX()
		{
			return m_x;
		}

		const float Vector2::GetY()
		{
			return m_y;
		}

		float Vector2::Length()
		{
			return std::sqrt(m_x * m_x + m_y * m_y);
		}

		float Vector2::SquaredLength()
		{
			return m_x * m_x + m_y * m_y;
		}

		// operators
		//
		Vector2& Vector2::operator=(const Vector2& rhs)
		{
			// Prevent self assignment. Two objects
			// are equal if their memory address are equal.
			if (this == &rhs)
			{
				return *this;
			}

			m_x = rhs.m_x;
			m_y = rhs.m_y;

			return *this;
		}

		Vector2& Vector2::operator+=(const Vector2& rhs)
		{
			m_x = m_x + rhs.m_x;
			m_y = m_y + rhs.m_y;

			return *this;
		}

		Vector2& Vector2::operator-=(const Vector2& rhs)
		{
			m_x = m_x - rhs.m_x;
			m_y = m_y - rhs.m_y;

			return *this;
		}

		Vector2& Vector2::operator*=(const Vector2& rhs)
		{
			m_x = m_x * rhs.m_x;
			m_y = m_y * rhs.m_y;

			return *this;
		}

		Vector2& Vector2::operator/=(const Vector2& rhs)
		{
			m_x = m_x / rhs.m_x;
			m_y = m_y / rhs.m_y;

			return *this;
		}

		Vector2 Vector2::operator+(const Vector2& rhs)
		{
			Vector2 sum;

			sum.m_x = m_x + rhs.m_x;
			sum.m_y = m_y + rhs.m_y;

			return sum;
		}

		Vector2 Vector2::operator-(const Vector2& rhs)
		{
			Vector2 sub;
			sub.m_x = m_x - rhs.m_x;
			sub.m_y = m_y - rhs.m_y;

			return sub;
		}

		Vector2 Vector2::operator-()
		{
			return Vector2(-m_x, -m_y);
		}

		Vector2 Vector2::operator*(const Vector2& rhs)
		{
			Vector2 scaled;

			scaled.m_y = m_y * rhs.m_y;
			scaled.m_x = m_x * rhs.m_x;

			return scaled;
		}

		Vector2 Vector2::operator/(const Vector2& rhs)
		{
			Vector2 inverseScaled;

			inverseScaled.m_x = m_x / rhs.m_x;
			inverseScaled.m_y = m_y / rhs.m_y;

			return inverseScaled;
		}

		bool Vector2::operator==(const Vector2& rhs)
		{
			return
				m_x == rhs.m_x &&
				m_y == rhs.m_y;
		}

		bool Vector2::operator!=(const Vector2& rhs)
		{
			return
				m_x != rhs.m_x ||
				m_y != rhs.m_y;
		}

		// friend functions
		Vector2 operator*(float scaleUnit, const Vector2& rhs)
		{
			Vector2 scaled;
			scaled.m_x = scaleUnit * rhs.m_x;
			scaled.m_y = scaleUnit * rhs.m_y;

			return scaled;
		}

		Vector2 operator*(const Vector2& lhs, float scaleUnit)
		{
			Vector2 scaled;
			scaled.m_x = scaleUnit * lhs.m_x;
			scaled.m_y = scaleUnit * lhs.m_y;

			return scaled;
		}
	}
}