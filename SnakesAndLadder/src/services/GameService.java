package services;

import models.*;
import strategies.IWinningStrategy;

import java.util.List;
import java.util.Random;

public class GameService {
    IWinningStrategy winningStrategy = null;

    public GameService(IWinningStrategy winningStrategy) {
        this.winningStrategy = winningStrategy;
    }

    public Game createGame(int numPlayers, List<String> emailIDs, int boardSize, int numDices, int maxDice, int numPieces) {
        Game game = Game.getBuilder()
                .setNumPieces(numPieces)
                .setBoard(boardSize)
                .setDices(numDices, maxDice)
                .setPlayers(numPlayers, emailIDs)
                .build();
        return game;
    }

    public void startGame(Game game) {
        int numPlayers = game.getPlayers().size();
        while(true) {
            for(int i=0; i<numPlayers; i++) {
                HumanPlayer player = (HumanPlayer) game.getPlayers().get(i);
                System.out.println(player.getUser().getName() + "'s turn");
                Random random = new Random();
                int diceNumber = random.nextInt(game.getDices().size());
                int diceRollResult = game.getDices().get(diceNumber).roll();
                int pieceNumber = random.nextInt(game.getNumPieces());
                player.getPieces().get(pieceNumber).movePiece(game.getBoard(), diceRollResult);
                if(winningStrategy.checkIfGameEnded(player, game.getBoard().getSize()-1)) {
                    System.out.println(player.getUser().getName() + " won");
                    return;
                }
            }
        }
    }

}
