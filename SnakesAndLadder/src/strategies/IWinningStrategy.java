package strategies;

import models.Game;
import models.Player;

public interface IWinningStrategy {
    public boolean checkIfGameEnded(Player player, int boardSize);
}
