package L000;

import java.util.*;

public class LeetCode0039{
    public List<List<Integer>> combine(int[] candidates,int target,int index){
        List<List<Integer>> lli = new ArrayList<>();
        if (target > 0){
            for (int i = index;i < candidates.length;i++){
                if (target - candidates[i] == 0){
                    List<Integer> li = new ArrayList<>();
                    li.add(candidates[i]);
                    lli.add(li);
                } else if (target - candidates[i] > 0){
                    List<List<Integer>> temp = combine(candidates, target - candidates[i],i);
                    if (temp.size() > 0){
                        for (List<Integer> li : temp){
                            li.add(candidates[i]);
                            lli.add(li);
                        }
                    }
                }
            }
        } 
        return lli;
    }

    public List<List<Integer>> combinationSumTrace(int[] candidates, int target) {
        return combine(candidates, target, 0);
    }

    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> res = new ArrayList<>();
        List<Integer> path = new ArrayList<>();
        trace(res, path, candidates, 0, target);
        return res;
    }

    public void trace(List<List<Integer>> res,List<Integer> path,int[] candidates,int index,int target) {
        if (target < 0) {
            return;
        } else if (target == 0) {
            res.add(new ArrayList<>(path));
            return;
        } 
        for (int i = index;i < candidates.length;++i) {
            path.add(candidates[i]);
            trace(res, path, candidates, i, target - candidates[i]);
            path.remove(path.size() - 1);
        }
    }
}