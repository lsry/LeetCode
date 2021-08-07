package L900;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Deque;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;

import util.TreeNode;

public class LeetCode0987 {
    private class Node {
        TreeNode tNode;
        int col;

        public Node(TreeNode node, int c) {
            this.tNode = node;
            this.col = c;
        }
    }

    public List<List<Integer>> verticalTraversal(TreeNode root) {
        if (root == null) {
            return new ArrayList<>();
        }
        HashMap<Integer, List<Integer>> rowMap = new HashMap<>();
        Deque<Node> queue = new LinkedList<>();
        queue.offer(new Node(root, 0));
        while (!queue.isEmpty()) {
            HashMap<Integer, List<Integer>> rows = new HashMap<>();
            int sz = queue.size();
            for (int i = 0;i < sz;++i) {
                Node node = queue.poll();
                List<Integer> cList = rows.getOrDefault(node.col, new ArrayList<>());
                cList.add(node.tNode.val);
                rows.put(node.col, cList);
                if (node.tNode.left != null) {
                    queue.offer(new Node(node.tNode.left, node.col - 1));
                }
                if (node.tNode.right != null) {
                    queue.offer(new Node(node.tNode.right, node.col + 1));
                }
            }
            for (Map.Entry<Integer, List<Integer>> entry : rows.entrySet()) {
                List<Integer> cList = rowMap.getOrDefault(entry.getKey(), new ArrayList<>());
                Collections.sort(entry.getValue());
                cList.addAll(entry.getValue());
                rowMap.put(entry.getKey(), cList);
            }
        }
        return rowMap.entrySet().stream().sorted((a, b) -> {
            return a.getKey() - b.getKey();
        }).map(Map.Entry<Integer, List<Integer>>::getValue).collect(Collectors.toList());
    }
}