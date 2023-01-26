package models;

public class Piece {
    private Color color;
    private int pieceNumber;
    private Cell cell;

    public Piece(int color, int pieceNumber) {
        this.color = Color.values()[color];
        this.pieceNumber = pieceNumber;
    }
}
