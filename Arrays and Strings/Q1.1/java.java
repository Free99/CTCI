// Before we start coding, we should ask what those characters are.
// This will help us save lots space.

import java.util.HashSet;

public class CheckUniqueCharacter {
    
    // the most
    public boolean isAllUniqueGeneral(String target) {
        // we should ask here what if the target string is null or empty.
        // here we assume that in this case we should return false.
        if (target == null || target.equals(""))
            return false;
        // I used to use a Hashtable, but it seems that we are wasting
        // some space. So I switch to HashSet.
        HashSet<Character> occurence = new HashSet<Character>();
        int len = target. length();
        char c;
        for (int i = 0; i < len; i++) {
            c = target.charAt(i);
            if (occurence.contains(c))
                return false;
            else
                occurence.add(c);
        }
        return true;
    }

    // if we are talking about ASCII characters
    // then we can limit our space to 128 booleans
    // however if we are talking about the other 128 extensions,
    // change 128 to 256
    public boolean isAllUniqueCharacterTypeKnown(String target) {
        if (target == null || target.equals(""))
            return false;

        boolean[] occured = new boolean[128];
        int len = target.length();
        char c;
        for (int i = 0; i < len; i++) {
            c = target.charAt(i);
            if (occured[c])
                return false;
            else
                occured[c] = true;
        }
        return true;
    }

    // The solution above all requires using an additional data structure.
    // If this is not allowed, we have to ask at least two questions:
    // 1. Can we destroy the orginal data when solving the problem?
    // That means doing something in place.
    // 2. Think about bit operations.
    // Now I'm not sure if the first approach applies here. We are merely
    // conting things.
    // We need something to keep track of the occurence of characters,
    // without addtional data structure.
    // Usually at this point, we can ask if a samll constant size space is
    // allowed.
    //
    // It's hard to jump to the answer in the book. It only works for
    // characters between a to z. Since there are only 26 characters,
    // we could use an integer to hold it (4*8 = 32 bits)
    public boolean isAllUnique(String target) {
        if (target == null || target.equals(""))
            return false;
        
        int occurence = 0;
        int len = target.length();
        int offset, token, compare;
        for (int i = 0; i < len; i++) {
            char c = target.charAt(i);
            offset = c - 'a';
            token = 1 << offset;
            compare = occurence & token;
            if (compare == 0)
                occurence += token;
            else
                return false;
        }
    }
}


