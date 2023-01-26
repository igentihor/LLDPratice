package models;

import java.util.Random;

public class Dice {
    private int maxNumber;

    Dice(int maxNumber) {
        this.maxNumber = maxNumber;
    }

    public int roll() {
        Random random = new Random();
        return random.nextInt(this.maxNumber+1);
    }
}
