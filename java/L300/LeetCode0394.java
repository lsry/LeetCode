package L300;

import java.util.ArrayDeque;
import java.util.Deque;

public class LeetCode0394 {
    /**
     * 栈解析
     */
    public String decodeStringStack(String s) {
        if (s == null || s.length() <= 0){
            return "";
        }
        Deque<Character> dc = new ArrayDeque<>();
        Deque<Integer> di = new ArrayDeque<>();
        int repeat = 0;
        for (int i = 0;i < s.length();i++){
            char c = s.charAt(i);
            if (Character.isDigit(c)){
                repeat = repeat * 10 + c - '0';
            } else if (c == '['){
                di.addFirst(repeat);
                repeat = 0;
                dc.addFirst(c);
            } else if (c == ']'){
                int r = di.removeFirst();
                StringBuilder curStr = new StringBuilder();
                while(dc.getFirst() != '['){
                    curStr.append(dc.removeFirst());
                }
                dc.removeFirst();
                String curString = curStr.reverse().toString();
                curString = repeat(curString, r);
                putChar(dc, curString);
            } else {
                dc.addFirst(c);
            }
        }
        StringBuilder sb = new StringBuilder();
        while(!dc.isEmpty()){
            sb.append(dc.removeFirst());
        }
        return sb.reverse().toString();
    }

    public void putChar(Deque<Character> dc,String s){
        for (int i = 0;i < s.length();i++){
            dc.addFirst(s.charAt(i));
        }
    }

    public String repeat(String s,int x){
        StringBuilder sb = new StringBuilder(s);
        for (int i = 1;i < x;i++){
            sb.append(s);
        } 
        return sb.toString();
    }

    private char[] src;
    private int ptr;

    public String decodeString(String s) {
        src = s.toCharArray();
        ptr = 0;
        return getString().toString();
    }

    private StringBuilder getString() {
        if (ptr >= src.length || src[ptr] == ']') {
            return new StringBuilder();
        }    
        StringBuilder sb = new StringBuilder();    
        if (Character.isDigit(src[ptr])) {
            int repeat = getTimes();
            ++ptr;
            StringBuilder s = getString();
            ++ptr;
            while (repeat > 0) {
                sb.append(s);
            }
        } else if (Character.isLetter(src[ptr])) {
            sb.append(src[ptr]);
            ++ptr;
        }
        return sb.append(getString());
    }

    private int getTimes() {
        int res = 0;
        while (ptr < src.length && Character.isDigit(src[ptr])) {
            res = res * 10 + (src[ptr] - '0');
            ++ptr;
        }
        return res;
    }
}