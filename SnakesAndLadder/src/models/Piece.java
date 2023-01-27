package models;

import lombok.Getter;

@Getter
public class Piece {
    private Color color;
    private int pieceNumber;
    private Cell cell;

    public Piece(int color, int pieceNumber) {
        this.color = Color.values()[color];
        this.pieceNumber = pieceNumber;
        this.cell = new Cell(0);
    }

    public void movePiece(Board board, int moveBy) {
        int currentIndex = this.getCell().getIndex();
        System.out.println("currentIndex " + currentIndex);
        System.out.println("Moveby " + moveBy);
        if (currentIndex >= board.getSize()) return;
        if(currentIndex+moveBy >= board.getSize()) {
            this.cell = board.getCells().get(board.getSize()-1);
            System.out.println("Cell index " + this.cell.getIndex());
            return;
        }
        this.cell = board.getCells().get(currentIndex+moveBy);
    }
}
