#ifndef _GAME_CLIENT_STATES_
#define _GAME_CLIENT_STATES_

namespace LoginState
{
	enum LoginState
	{
		Normal,
		Username,
		Password,
		Login,
		Quit
	};
}

namespace MenuState
{
	enum MenuState
	{
		Normal,
		Start,
		Quit
	};
}

namespace PageState
{
	enum PageState
	{
		LoginPage,
		MenuPage,
		GamePage,
		QuitPage
	};
}
#endif // _GAME_CLIENT_STATES_