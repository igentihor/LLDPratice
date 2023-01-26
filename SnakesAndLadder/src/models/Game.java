package models;

import java.util.List;

public class Game {
    private Board board;
    private List<Dice> dices;
    private List<Player> players;
    private int numPieces;

    public static Builder getBuilder() {
        return new Builder();
    }

    public static class Builder {
        private Game game;

        private Builder() {
            game = new Game();
        }

        public Builder setNumPieces(int numPieces) {
            game.numPieces = numPieces;
            return this;
        }

        public Builder setBoard(int size) {
            game.board = new Board(size);
            return this;
        }

        public Builder setDices(int numDices, int maxNumber) {
            for(int i=0; i<numDices; i++) {
                game.dices.add(new Dice(maxNumber));
            }
            return this;
        }

        public Builder setPlayers(int numPlayers, List<String> emailIDs) {
            for(int i=0; i<numPlayers; i++) {
                game.players.add(new HumanPlayer(emailIDs.get(i), game.numPieces, i));
            }
            return this;
        }

        public Game build() {
            return game;
        }

    }

    public void launchGame() {

    }

    public void checkIfGameEnded() {

    }
}
