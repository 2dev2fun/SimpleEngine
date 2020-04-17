#pragma once

namespace engine {

enum class GameState {
	PLAY,
	EXIT
};

class Game {
public:
	Game();
	~Game();

	void loop();

	void setState(GameState state);
	GameState getState() const;

private:
	Game(Game const&) = delete;
	void operator=(Game const&) = delete;

	GameState mState;
};

inline void Game::setState(GameState state) {
	mState = state;
}

inline GameState Game::getState() const {
	return mState;
}

} // namespace engine
