package controller;

import models.User;
import repositories.UserRepository;
import services.UserService;

import java.util.ArrayList;
import java.util.List;

public class UserController {
    private UserService userService;

    public void createUser(String name, String email) {
        User user = userService.createUser(name, email);
    }
}
