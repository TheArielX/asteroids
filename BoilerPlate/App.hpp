#pragma once
#ifndef APP_HPP
#define APP_HPP

// C++ STL
#include <list>
#include <vector>


#include "SDLEvent.hpp"
#include "TimeManager.hpp"
#include "Ship.hpp"
#include "Asteroid.hpp"

namespace Engine
{
	class App : public SDLEvent
	{
	public:
		/* =============================================================
		* ENUMERATORS
		* ============================================================= */
		struct GameState
		{
			enum State
			{
				UNINITIALIZED = 0,
				INIT_FAILED = 1,
				INIT_SUCCESSFUL = 2,
				RUNNING = 4,
				PAUSED = 8,
				QUIT = 16
			};
		};

		/* =============================================================
		 * PUBLIC FUNCTIONS
		 * ============================================================= */
		App( const std::string& title, const int width, const int height );
		~App( );
		void Execute						( );
		bool Init							( );
		void Update							( );
		void Render							( );
	private:
		/* =============================================================
		 * PRIVATE FUNCTIONS
		 * ============================================================= */
		bool SDLInit						( );
		static bool GlewInit						( );
		void SetupViewport					( )const;
		void CleanupSDL						( )const;
		void OnResize						( int width, int height ) override;
		void OnExit							( ) override;
		void OnKeyDown						( SDL_KeyboardEvent keyBoardEvent ) override;
		void OnKeyUp						( SDL_KeyboardEvent keyBoardEvent ) override;


		/* =============================================================
		 * MEMBERS
		 * ============================================================= */
		int									m_width;
		int									m_height;
		int									m_nUpdates;
		double								m_lastFrameTime;
		std::string							m_title;
		SDL_Window*							m_mainWindow;
		SDL_GLContext						m_context;
		GameState::State					m_state;
		Engine::TimeManager*				m_timer;


		//
		int									m_currentIndex;
		std::vector<Asteroids::Entities::Ship*> m_entities;

	};
}
#endif /* GAME_HPP */
