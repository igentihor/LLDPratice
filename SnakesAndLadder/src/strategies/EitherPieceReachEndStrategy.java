package strategies;

import models.Game;
import models.Player;

public class EitherPieceReachEndStrategy implements IWinningStrategy {
    @Override
    public boolean checkIfGameEnded(Player player, int boardSize) {
        for(int i=0; i<player.getPieces().size(); i++) {
            System.out.println(player.getPieces().get(i).getCell().getIndex());
            System.out.println(boardSize);
            if (player.getPieces().get(i).getCell().getIndex() >= boardSize) {
                return true;
            }
        }
        return false;
    }
}
