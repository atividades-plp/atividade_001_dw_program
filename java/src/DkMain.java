import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class DkMain {
    private static final String text = "METHINKS IT IS LIKE A WEASEL";
    private static final String alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ ";

    public static char sortChar(){
        int alphabetLength = alphabet.length();
        Random random = new Random();
        int charIndex = random.nextInt(alphabetLength);
        return alphabet.toCharArray()[charIndex];
    }

    public static String sortInitialString(){
        int textLength = text.length();
        StringBuilder sortedString = new StringBuilder();
        for(int index = 0; index < textLength; index++)
            sortedString.append(sortChar());
        return sortedString.toString();
    }

    public static String resortString(String textCopy){
        StringBuilder newTextCopy = new StringBuilder();
        for(int index = 0; index < text.length(); index++){
            if(textCopy.toCharArray()[index] == text.toCharArray()[index])
                newTextCopy.append(textCopy.toCharArray()[index]);
            else
                newTextCopy.append(sortChar());
        }
        return newTextCopy.toString();
    }

    public static List<String> copyOf(String target, int length){
        List<String> copies = new ArrayList<>();
        for(int index = 0; index < length; index++)
            copies.add(target);
        return copies;
    }

    public static int getScoreOf(String textCopy){
        int score = 0;
        for(int index = 0; index<text.length(); index++)
            if(textCopy.toCharArray()[index] == text.toCharArray()[index]) score++;
        return score;
    }

    public static void printGeneration(int generation, String textCopy){
        System.out.println("Generation " + generation + " (score of "+getScoreOf(textCopy)+"): " + textCopy );
    }

    public static void main(String[] args) {
        String currentCopy = sortInitialString();
        int generation = 0;
        while(getScoreOf(currentCopy) < text.length()){
            List<String> copies = copyOf(currentCopy, 100);
            for(String copy: copies){
                String resortedCopy = resortString(copy);
                if(getScoreOf(resortedCopy) > getScoreOf(currentCopy))
                    currentCopy = resortedCopy;
            }
            printGeneration(generation, currentCopy);
            generation++;
        }
    }
}
