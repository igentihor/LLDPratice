package models;

import java.util.List;

public abstract class Player {
    private List<Piece> pieces;

    public Player(int numPieces, int color) {
        for(int i=0; i<numPieces; i++) {
            pieces.add(new Piece(color, i));
        }
    }

    public abstract void makeMove();
}
