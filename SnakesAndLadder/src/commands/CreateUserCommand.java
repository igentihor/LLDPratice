package commands;

import controller.UserController;
import exceptions.InvalidCommandException;

public class CreateUserCommand implements ICommand {
    UserController userController = new UserController();

    @Override
    public boolean matches(String command) {
        if(command.equals("CREATE_USER")) {
            return true;
        }
        return false;
    }

    @Override
    public void execute(String command) {
        String[] userDetails = command.split(" ");
        userController.createUser(userDetails[1], userDetails[2]);
    }
}
