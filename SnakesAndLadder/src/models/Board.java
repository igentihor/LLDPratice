package models;

import java.util.List;

public class Board {
    private int size;
    private List<Cell> cells;

    public Board(int size) {
        this.size = size;
        for(int i=0; i<this.size; i++) {
            cells.add(new NormalCell(i));
        }
    }
}
