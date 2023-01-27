package models;

import lombok.Getter;

import java.util.ArrayList;
import java.util.List;

@Getter
public class Board {
    private int size;
    private List<Cell> cells = new ArrayList<>();

    public Board(int size) {
        this.size = size;
        for(int i=0; i<this.size; i++) {
            cells.add(new NormalCell(i));
        }
    }
}
