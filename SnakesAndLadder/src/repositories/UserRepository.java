package repositories;

import models.User;

import java.util.ArrayList;
import java.util.List;

public class UserRepository {
    private static List<User> users = new ArrayList<>();

    public static void printUsers() {
        users.forEach(user1 -> System.out.println(user1));
    }

    public static void addUser(User user) {
        users.add(user);
        printUsers();
    }

    public static User getUser(String emailId) {
        for(User user : users) {
            if (user.getEmail().equals(emailId))
                return user;
        }
        return null;
    }
}
