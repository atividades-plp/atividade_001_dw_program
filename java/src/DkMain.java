import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class DkMain {
    private static final String TEXT = "METHINKS IT IS LIKE A WEASEL";
    private static final String ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ ";
    private static final int PROBABILITY = 5;

    public static char sortChar(){
        int alphabetLength = ALPHABET.length();
        int charIndex = new Random().nextInt(alphabetLength);
        return ALPHABET.toCharArray()[charIndex];
    }

    public static String sortInitialString(){
        int textLength = TEXT.length();
        StringBuilder sortedString = new StringBuilder();
        for(int index = 0; index < textLength; index++)
            sortedString.append(sortChar());
        return sortedString.toString();
    }

    public static String resortString(String textCopy){
        StringBuilder newTextCopy = new StringBuilder();
        for(int index = 0; index < TEXT.length(); index++){
                if(textCopy.toCharArray()[index] == TEXT.toCharArray()[index] || !has2BeSorted())
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
        for(int index = 0; index<TEXT.length(); index++)
            if(textCopy.toCharArray()[index] == TEXT.toCharArray()[index]) score++;
        return score;
    }

    public static void printGeneration(int generation, String textCopy){
        System.out.println("GENERATION " + generation + " (SCORE "+getScoreOf(textCopy)+"): " + textCopy );
    }

    public static boolean has2BeSorted(){
        int probability = new Random().nextInt(99);
        return probability <= PROBABILITY - 1;
    }

    public static void main(String[] args) {
        String currentCopy = sortInitialString();
        int generation = 0;
        while(getScoreOf(currentCopy) < TEXT.length()){
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
