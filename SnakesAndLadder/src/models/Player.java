package models;

import lombok.Getter;

import java.util.ArrayList;
import java.util.List;

@Getter
public abstract class Player {
    private List<Piece> pieces;

    public Player(int numPieces, int color) {
        pieces = new ArrayList<>();
        for(int i=0; i<numPieces; i++) {
            pieces.add(new Piece(color, i));
        }
    }
}
