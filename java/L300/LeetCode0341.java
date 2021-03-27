package L300;

import java.util.Deque;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;

public class LeetCode0341 {}

interface NestedInteger {
    // @return true if this NestedInteger holds a single integer, rather than a nested list.
    public boolean isInteger();

    // @return the single integer that this NestedInteger holds, if it holds a single integer
    // Return null if this NestedInteger holds a nested list
    public Integer getInteger();
    
    // @return the nested list that this NestedInteger holds, if it holds a nested list
    // Return null if this NestedInteger holds a single integer
    public List<NestedInteger> getList();
}

class NestedIterator implements Iterator<Integer> {
    class Node {
        List<NestedInteger> nList;
        int index;

        public Node(List<NestedInteger> list, int index) {
            nList = list;
            this.index = index;
        }
    }

    private Deque<Node> stack;

    public NestedIterator(List<NestedInteger> nestedList) {
        stack = new LinkedList<>();
        if (!nestedList.isEmpty()) {
            stack.addFirst(new Node(nestedList, 0));
        }
    }

    @Override
    public Integer next() {
        Node node = stack.removeFirst();
        NestedInteger ni = node.nList.get(node.index);
        if (node.index + 1 < node.nList.size()) {
            node.index += 1;
            stack.addFirst(node);
        }
        return ni.getInteger();
    }

    @Override
    public boolean hasNext() {
        if (!stack.isEmpty()) {
            Node cur = stack.removeFirst();
            boolean flag = true;
            NestedInteger ni = cur.nList.get(cur.index);
            if (ni.isInteger()) {
                stack.addFirst(cur);
                return true;
            }
            if (cur.index + 1 < cur.nList.size()) {
                cur.index += 1;
                stack.addFirst(cur);
            }
            while (!ni.isInteger()) {
                List<NestedInteger> curList = ni.getList();
                if (!curList.isEmpty()) {
                    ni = curList.get(0);
                    if (ni.isInteger()) {
                        stack.addFirst(new Node(curList, 0));
                        break;
                    } else if (curList.size() > 1) {
                        stack.addFirst(new Node(curList, 1));
                    }
                } else if (stack.isEmpty()) {
                    flag = false;
                    break;
                } else {
                    cur = stack.removeFirst();
                    ni = cur.nList.get(cur.index);
                    if (ni.isInteger()) {
                        stack.addFirst(cur);
                        break;
                    } else if (cur.index + 1 < cur.nList.size()) {
                        cur.index += 1;
                        stack.addFirst(cur);
                    }
                }
            }
            return flag;
        }
        return false;
    }
}
