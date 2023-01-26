package models;

import lombok.Getter;

import java.util.UUID;

@Getter
public class User {
    private UUID id;
    private String name;
    private String email;

    public User(UUID id, String name, String email) {
        this.email = email;
        this.name = name;
    }
}
