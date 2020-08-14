import java.util.ArrayList;
import java.util.List;

class Node {
    public int val;
    public List<Node> neighbors;
    
    public Node() {
        val = 0;
        neighbors = new ArrayList<Node>();
    }
    
    public Node(int _val) {
        val = _val;
        neighbors = new ArrayList<Node>();
    }
    
    public Node(int _val, ArrayList<Node> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
}

public class LeetCode0133 {
    private Node[] nodes = new Node[101];
    public Node cloneGraph(Node node) {
        if (node == null) {
            return node;
        }
        if (nodes[node.val] == null) {
            Node cur = new Node(node.val);
            nodes[node.val] = cur;
            for (Node n : node.neighbors) {
                cur.neighbors.add(cloneGraph(n));   
            }
            return cur; 
        } else {
            return nodes[node.val];
        }
    }
}