package strategies;

import models.Game;
import models.Player;

public class AllPiecesReachEndStrategy implements IWinningStrategy {
    @Override
    public boolean checkIfGameEnded(Player player, int boardSize) {
        boolean status = true;
        for(int i=0; i<player.getPieces().size(); i++) {
            for(int j=0; j<player.getPieces().size(); j++) {
                status = status && player.getPieces().get(j).getCell().getIndex() >= boardSize;
            }
        }
        return status;
    }
}
