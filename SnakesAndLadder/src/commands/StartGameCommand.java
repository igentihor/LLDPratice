package commands;

import controller.GameController;
import models.Game;

import java.util.ArrayList;
import java.util.List;

public class StartGameCommand implements ICommand {
    GameController gameController = null;

    public StartGameCommand() {
        gameController = new GameController();
    }

    @Override
    public boolean matches(String command) {
        if(command.equals("START_GAME")) {
            return true;
        }
        return false;
    }

    @Override
    public void execute(String command) {
        // START_GAME 2 rmail.com vmail.com 10000 2 50 4
        String[] input = command.split(" ");
        List<String> emailIDs = new ArrayList<>();
        int numPlayers = Integer.parseInt(input[1]);
        int i;
        for (i=2; i<numPlayers+2; i++) {
            emailIDs.add(input[i]);
        }
        int boardSize = Integer.parseInt(input[i]);
        int numDices = Integer.parseInt(input[i+1]);
        int maxDice = Integer.parseInt(input[i+2]);
        int numPieces = Integer.parseInt(input[i+3]);
        gameController.startGame(numPlayers, emailIDs, boardSize, numDices, maxDice, numPieces);
    }
}
