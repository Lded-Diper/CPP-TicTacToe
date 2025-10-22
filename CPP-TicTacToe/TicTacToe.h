#pragma once

#include "Game.h"

class TicTacToe : public Game
{
private:

	char m_board[9];
	int m_currentplayer;


public:

	TicTacToe()
	{
		for (int i = 0; i < 9; i++)
			m_board[i] = '1' + i;
		m_currentplayer = 1;
	}

	bool IsGameOver() const
	{
		int combos[8][3] =
		{
			{0, 1, 2}, {3, 4, 5}, {6, 7, 8}, {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, {0, 4, 8}, {2, 4, 6}
		};

		for (int i = 0; i < 8; i++)
		{
			int a = combos[i][0];
			int b = combos[i][1];
			int c = combos[i][2];

			if (m_board[a] == m_board[b] && m_board[b] == m_board[c])
			{
				std::cout << "Player " << (m_board[a] == 'X' ? 1 : 2) << " wins\n"; return true;
			}
		}

		int fullBoard = true;
		for (int i = 0; i < 9; i++)
		{
			if (m_board[i] != 'X' && m_board[i] != 'O')
			{
				fullBoard = false;
				break;
			}
		}

		if (fullBoard)
		{
			std::cout << "It is a draw\n"; return true;
		}

		return false;
	};

	void TakeTurn()
	{
		int boardLocation;
		std::cout << "Player " << m_currentplayer << " choose a spot (1-9): ";
		std::cin >> boardLocation;

		if (boardLocation < 1 || boardLocation > 9) { std::cout << "Invalid spot"; return; }
			
		int boardIndex = boardLocation - 1;
		if (m_board[boardIndex] == 'X' || m_board[boardIndex] == 'O') { std::cout << "Spot taken"; return; }

		m_board[boardIndex] = (m_currentplayer == 1 ? 'X' : 'O');
		m_currentplayer = (m_currentplayer == 1 ? 2 : 1);
	};

	void Display() const
	{
		std::cout << "\n";
		for (int i = 0; i < 9; i++)
		{
			std::cout << " " << m_board[i] << " ";
			if ((i + 1) % 3 == 0)
				std::cout << "\n";
			else
				std::cout << "|";
		}
		std::cout << "\n\n";
	};

};