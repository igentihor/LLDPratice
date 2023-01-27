package models;

import lombok.Getter;

@Getter
public class Cell {
    private int index;

    public Cell(int index) {
        this.index = index;
    }
}
