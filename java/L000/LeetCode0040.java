package L000;

import java.util.*;

public class LeetCode0040{

    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        List<List<Integer>> res = new ArrayList<>();
        List<Integer> path = new ArrayList<>();
        Arrays.sort(candidates);
        trace(res, path, candidates, 0, target);
        return res;
    }
    /**
     * 回溯测试每一个可能，当当前路径中数字和等于target，则加入结果集中
     * @param candidates 候选数组，需要已经排序过
     */
    public void trace(List<List<Integer>> res,List<Integer> path,int[] candidates,int index,int target) {
        if (target < 0) {
            return;
        } else if (target == 0) {
            res.add(new ArrayList<>(path));
            return;
        } 
        for (int i = index;i < candidates.length;++i) {
            if (i > index && candidates[i] == candidates[i - 1]) { // 去除重复
                continue;
            } else if (target - candidates[i] >= 0) {  // 只有余留数字大于0才继续回溯
                path.add(candidates[i]);
                trace(res, path, candidates, i + 1, target - candidates[i]);
                path.remove(path.size() - 1);
            } else {  // 当小于0，后面的数字也不会满足条件，中断循环
                break;
            } 
        }
    }

    public HashSet<List<Integer>> combine(int[] candidates,int target,int index){
        HashSet<List<Integer>> lli = new HashSet<>();
        if (target > 0){
            for (int i = index;i < candidates.length;i++){
                if (target - candidates[i] == 0){
                    List<Integer> li = new ArrayList<>();
                    li.add(candidates[i]);
                    lli.add(li);
                } else if (target - candidates[i] > 0){
                    HashSet<List<Integer>> temp = combine(candidates, target - candidates[i],i + 1);
                    if (temp.size() > 0){
                        for (List<Integer> li : temp){
                            li.add(candidates[i]);
                            Collections.sort(li);
                            lli.add(li);
                        }
                    }
                }
            }
        } 
        return lli;
    }

    public List<List<Integer>> combinationSum2Set(int[] candidates, int target) {
        List<List<Integer>> lli = new ArrayList<>();
        HashSet<List<Integer>> hli = combine(candidates, target, 0);
        for (List<Integer> li : hli){            
            lli.add(li);
        }       
        return lli;
    }
}