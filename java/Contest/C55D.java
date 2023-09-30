package Contest;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.stream.Collectors;

public class C55D {
    public boolean canBeIncreasing(int[] nums) {
        int t = -1;
        for (int i = 0;i < nums.length - 1;++i) {
            if (nums[i] >= nums[i + 1]) {
                t = i;
                break;
            }
        }
        return t == -1 || check(nums, t) || check(nums, t + 1);
    }

    private boolean check(int[] nums, int id) {
        for (int i = 0;i < nums.length - 1;++i) {
            if (i == id) {
                continue;
            }
            int n = i + 1 == id ? i + 2 : i + 1;
            if (n >= nums.length) {
                break;
            }
            if (nums[i] >= nums[n]) {
                return false;
            }
        }
        return true;
    } 

    public String removeOccurrences(String s, String part) {
        int i = 0;
        int x = part.length();
        while ((i = s.indexOf(part)) != -1) {
            s = s.substring(0, i) + s.substring(i + x);
        }
        return s;
    }
}

class MovieRentingSystem {
    private static final int BORROW = -1;
    private int N;

    private HashMap<Integer, HashMap<Integer,int[]>> shops = new HashMap<>();
    private HashMap<Integer, Integer> movies = new HashMap<>();
    private PriorityQueue<int[]> notRent = new PriorityQueue<>((a, b) -> {
        if (a[2] != b[2]) {
            return a[2] - b[2];
        } else {
            return a[0] - b[0];
        }
    });
    private PriorityQueue<int[]> rented = new PriorityQueue<>((a, b) -> {
        if (a[2] != b[2]) {
            return a[2] - b[2];
        } else if (a[0] != b[0]) {
            return a[0] - b[0];
        } else {
            return a[1] - b[1];
        }
    });

    public MovieRentingSystem(int n, int[][] entries) {
        this.N = n;
        for (int[] entry : entries) {
            HashMap<Integer,int[]> movie = shops.getOrDefault(entry[0], new HashMap<>());
            movie.put(entry[1], new int[]{entry[2], 0});
            shops.put(entry[0], movie);
            notRent.offer(entry);
        }
    }
    
    public List<Integer> search(int movie) {
        List<int[]> movieList = new ArrayList<>();
        for (Map.Entry<Integer, HashMap<Integer,int[]>> entry : shops.entrySet()) {
            HashMap<Integer,int[]> m = entry.getValue();
            if (m.containsKey(movie)) {
                int[] p = m.get(movie);
                if (p[1] == 0) {
                    movieList.add(new int[]{entry.getKey(), p[0]});
                }
            }
        }
        Collections.sort(movieList, (a, b) -> {
            if (a[2] != b[2]) {
                return a[2] - b[2];
            } else {
                return a[0] - b[0];
            }
        });
        if (movieList.size() <= 5) {
            return movieList.stream().map(x -> x[0]).collect(Collectors.toList());
        } else {
            List<Integer> res = new ArrayList<>();
            for (int i = 0;i < 5;++i) {
                res.add(movieList.get(i)[0]);
            }
            return res;
        }
    }
    
    public void rent(int shop, int movie) {
        HashMap<Integer,int[]> movieMap = shops.get(shop);
        int[] cur = movieMap.get(movie);
        cur[1] = BORROW;
        movieMap.put(movie, cur);
        shops.put(shop, movieMap);
    }
    
    public void drop(int shop, int movie) {
        HashMap<Integer,int[]> movieMap = shops.get(shop);
        int[] cur = movieMap.get(movie);
        cur[1] = 0;
        movieMap.put(movie, cur);
        shops.put(shop, movieMap);
    }
    
    public List<List<Integer>> report() {
        List<int[]> movieList = new ArrayList<>();
        for (Map.Entry<Integer, HashMap<Integer,int[]>> entry : shops.entrySet()) {
            HashMap<Integer,int[]> m = entry.getValue();
            for (Map.Entry<Integer,int[]> e : m.entrySet()) {
                int[] p = e.getValue();
                if (p[1] == BORROW) {
                    movieList.add(new int[]{entry.getKey(), e.getKey(), p[0]});
                }
            }
        }
        Collections.sort(movieList, (a, b) -> {
            if (a[2] != b[2]) {
                return a[2] - b[2];
            } else if (a[0] != b[0]) {
                return a[0] - b[0];
            } else {
                return a[1] - b[1];
            }
        });
        if (movieList.size() <= 5) {
            return movieList.stream().map(x -> Arrays.asList(x[0], x[1])).collect(Collectors.toList());
        } else {
            List<List<Integer>> res = new ArrayList<>();
            for (int i = 0;i < 5;++i) {
                int[] cur = movieList.get(i);
                res.add(Arrays.asList(cur[0], cur[1]));
            }
            return res;
        }
    }
}
