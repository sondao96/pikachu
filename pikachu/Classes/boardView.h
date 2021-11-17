#pragma once
#include<cocos2d.h>
#include"board.h"

USING_NS_CC;
using namespace std;
class BoardView : public Layer {
private:
	Board* board;
	float squareSize, width, height;
	vector<vector<Sprite*>>pokemons;
public:
	static Layer* createBoardView(Board* board);
	void showBoard();
	Sprite* addPokemon(int row, int column, int type);
	Vec2 positionOf(int row, int columns);
	pair<int, int> findRowAndColumnOfSprite(Node* node);

	bool removePokemon(int row, int column);
	bool onTouchPokemon(Touch* touch, Event* event);
	
	CREATE_FUNC(BoardView);
};