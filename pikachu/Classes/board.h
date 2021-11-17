#pragma once

#include<vector>
using namespace std;
class Board {
private:
	int n_rows;
	int n_columns;
	vector<vector<int>>_pokemons;
public:
	int _x = -1;
	int _y = -1;
	Board(int n_rows, int n_columns, int n_types, vector<int>count);
	int getNRows();
	int getNColumns();
	void addPokemon(int x, int y, int type);
	int getPokemon(int x, int y);
	void removePokemon(int x, int y);
	bool selectPokemon(int x, int y);
	bool canConnect(int _x, int _y, int x, int y);
	vector<pair<int, int>> findPath(int _x, int _y, int x, int y);
};