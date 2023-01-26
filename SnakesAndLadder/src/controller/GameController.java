package controller;

import models.Game;
import services.GameService;

import java.util.List;

public class GameController {
    GameService gameService = new GameService();

    public Game create(int numPlayers, List<String> emailIDs, int boardSize, int numDices, int maxDice) {
        gameService.createGame(numPlayers, emailIDs, boardSize, numDices, maxDice);
        return null;
    }
}
