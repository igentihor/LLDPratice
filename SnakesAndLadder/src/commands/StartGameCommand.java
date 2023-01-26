package commands;

import controller.GameController;

import java.util.ArrayList;
import java.util.List;

public class StartGameCommand implements ICommand {
    GameController gameController = new GameController();

    @Override
    public boolean matches(String command) {
        if(command.equals("START_GAME")) {
            return true;
        }
        return false;
    }

    @Override
    public void execute(String command) {
        String[] input = command.split(" ");
        List<String> emailIDs = new ArrayList<>();
        int numPlayers = Integer.parseInt(input[0]);
        int i;
        for (i=1; i<numPlayers; i++) {
            emailIDs.add(input[i]);
        }
        int boardSize = Integer.parseInt(input[i]);
        int numDices = Integer.parseInt(input[i+1]);
        int maxDice = Integer.parseInt(input[i+2]);
        gameController.create(numPlayers, emailIDs, boardSize, numDices, maxDice);
    }
}
