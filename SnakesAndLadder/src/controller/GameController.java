package controller;

import models.Game;
import services.GameService;
import strategies.AllPiecesReachEndStrategy;
import strategies.EitherPieceReachEndStrategy;

import java.util.List;

public class GameController {
    GameService gameService = null;

    public GameController() {
        gameService = new GameService(new AllPiecesReachEndStrategy());
    }

    public void startGame(int numPlayers, List<String> emailIDs, int boardSize, int numDices, int maxDice, int numPieces) {
        Game game = gameService.createGame(numPlayers, emailIDs, boardSize, numDices, maxDice, numPieces);
        gameService.startGame(game);
        return;
    }
}
