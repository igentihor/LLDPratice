import commands.CommandRegistry;
import commands.CreateUserCommand;
import commands.StartGameCommand;
import exceptions.InvalidCommandException;

import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {

    public static void main(String[] args) {
        CommandRegistry commandRegistry = new CommandRegistry();
        commandRegistry.registerCommand(new CreateUserCommand());
        commandRegistry.registerCommand(new StartGameCommand());

        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));

        while(true) {
            try {
                System.out.println("Enter CREATE_USER  or START_GAME command\n > \n");
                String input = reader.readLine().toString();
                if(input.equals("CREATE_USER")) {
                    System.out.println("Enter name and email separated with space");
                    input = reader.readLine().toString();
                    commandRegistry.execute(input);
                } else {
                    System.out.println("Enter number of players, email IDs, board size, number of dices");
                    input = reader.readLine().toString();
                    commandRegistry.execute(input);
                }
            } catch (Exception e) {
                throw new InvalidCommandException();
            }
        }
    }
}
