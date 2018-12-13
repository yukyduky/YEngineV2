#pragma once

class GameManager;

class State
{
public:
	virtual ~State() {}
	virtual void init() = 0;
	virtual void cleanup() = 0;
	virtual void pause() = 0;
	virtual void resume() = 0;
	virtual void handleEvents(GameManager* gm) = 0;
	virtual void update(GameManager* gm) = 0;
	virtual void render(GameManager* gm) = 0;
};
