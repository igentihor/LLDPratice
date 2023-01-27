package commands;

import exceptions.InvalidCommandException;

import java.util.ArrayList;
import java.util.List;

public class CommandRegistry {
    private List<ICommand> commands = new ArrayList<>();

    public void registerCommand(ICommand command) {
        commands.add(command);
    }

    public void execute(String inputCommand) {
        String[] userInput = inputCommand.split(" ");
        for(ICommand command: commands) {
            if (command.matches(userInput[0])) {
                command.execute(inputCommand);
                return;
            }
        }
        throw new InvalidCommandException();
    }
}
