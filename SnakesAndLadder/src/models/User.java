package models;

import lombok.Getter;
import lombok.NonNull;

import java.util.UUID;

@Getter
public class User {
    private UUID id;
    private String name;
    private String email;

    public User(UUID id, @NonNull String name, @NonNull String email) {
        this.id = id;
        this.email = email;
        this.name = name;
    }
}
