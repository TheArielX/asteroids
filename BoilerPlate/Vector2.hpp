#pragma once

#ifndef _VECTOR2_H_
#define _VECTOR2_H_

namespace Engine
{
	namespace Math
	{
		class Vector2
		{
		public:
			/*
			 * CONST
			 */
			Vector2( );
			Vector2(float uniform);
			Vector2( float x, float y );

			/*
			 * PUBLIC FUNCTIONS
			 */
			float Length();
			float SquaredLength();
			const float GetX();
			const float GetY();

			/*
			 * OPERATORS
			 */
			Vector2& operator=( const Vector2& rhs );
			Vector2& operator+=( const Vector2& rhs );
			Vector2& operator-=( const Vector2& rhs );
			Vector2& operator*=( const Vector2& rhs );
			Vector2& operator/=( const Vector2& rhs );
			Vector2 operator+( const Vector2& rhs );
			Vector2 operator-( const Vector2& rhs );
			Vector2 operator-( );
			Vector2 operator*( const Vector2& rhs );
			Vector2 operator/( const Vector2& rhs );
			bool operator==(const Vector2& rhs);
			bool operator!=(const Vector2& rhs);
			friend Vector2 operator*(float scaleUnit, const Vector2& rhs);
			friend Vector2 operator*(const Vector2& lhs, float scaleUnit);

		private:
			float m_x;
			float m_y;
			float m_length;
		};
	}
}

#endif // !_VECTOR2_H_
