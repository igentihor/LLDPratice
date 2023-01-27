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

        for(int i=3; i>0; i--) {
            try {
                // CREATE_USER <name> <email>
                // CREATE_GAME <numberOfPlayers> <emailId1, emailId2,....> <boardSize> <numberOfDices>
                // START_GAME
                System.out.println("Enter CREATE_USER or START_GAME command\n >");
                String input = reader.readLine().toString();
                commandRegistry.execute(input);
            } catch (Exception e) {
                throw new InvalidCommandException();
            }
            //CREATE_USER Rohit rmail.com
            //CREATE_USER Varsha vmail.com
            //START_GAME 2 rmail.com vmail.com 10000 2 50 4
        }
    }
}
