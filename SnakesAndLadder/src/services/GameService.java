package services;

import models.*;

import java.util.ArrayList;
import java.util.List;

public class GameService {

    public Game createGame(int numPlayers, List<String> emailIDs, int boardSize, int numDices, int maxDice) {
        Game game = Game.getBuilder()
                .setBoard(boardSize)
                .setDices(numDices, maxDice)
                .setPlayers(numPlayers, emailIDs)
                .build();
        return game;
    }
}
