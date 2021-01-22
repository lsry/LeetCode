package L1400;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;

public class LeetCode1489 {
    private class UnionFind {
        private int[] ids, ranks;
        private final int N;
        private int count;

        public UnionFind (int N) {
            this.N = N;
            this.count = N;
            ids = new int[N];
            ranks = new int[N];
            clear();
        }

        public void clear() {
            Arrays.fill(ranks, 0);
            this.count = N;
            for (int i = 0;i < N;++i) {
                ids[i] = i;
            }
        }

        public int find(int id) {
            while (ids[id] != id) {
                id = ids[id];
            }
            return id;
        }

        public boolean union(int p, int q) {
            p = find(p);
            q = find(q);
            if (p == q) {
                return false;
            }
            if (ranks[p] <= ranks[q]) {
                ids[p] = q;
                if (ranks[p] == ranks[q]) {
                    ranks[q] += 1;
                }
            } else {
                ids[q] = p;
            }
            this.count --;
            return true;
        }

    }

    private class Edge implements Comparable<Edge> {
        public int from, to, weight, index;

        public Edge(int from, int to, int weight, int index) {
            this.from = from;
            this.to = to;
            this.weight = weight;
            this.index = index;
        }

        @Override
        public int compareTo(Edge edge) {
            return this.weight - edge.weight;
        }
    }

    /**
     * 构造最小生成树，得到对应的权重及边集
     * @param edges 图中的所有边
     * @param nonIndex 最小生成树中不应该包含的边索引
     * @param mstEdgeIndex 最小生成树边索引
     * @param uf 辅助并查集
     * @param edgeIndex 最小生成树中首先应该包含的边索引
     * @return 最小生成树的边权重和
     */
    private int getMSTWeight(List<Edge> edges, int nonIndex, List<Integer> mstEdgeIndex, UnionFind uf, int edgeIndex) {
        final int N = edges.size();
        int weight = 0;
        if (edgeIndex >= 0 && edgeIndex < N) {
            Edge edge = edges.get(edgeIndex);
            uf.union(edge.from, edge.to);
            weight += edge.weight;
        }
        for (int i = 0;i < N;++i) {
            if (i == nonIndex || i == edgeIndex) {
                continue;
            }
            if (uf.count == 1) {
                break;
            }
            Edge edge = edges.get(i);
            if (uf.union(edge.from, edge.to)) {
                weight += edge.weight;
                if (mstEdgeIndex != null) {
                    mstEdgeIndex.add(i);
                }
            }
        }
        return weight;
    }

    public List<List<Integer>> findCriticalAndPseudoCriticalEdges(int n, int[][] edges) {
        final int N = edges.length;
        List<Edge> nedges = new ArrayList<>(N);
        for (int i = 0;i < N;++i) {
            nedges.add(new Edge(edges[i][0], edges[i][1], edges[i][2], i));
        }
        Collections.sort(nedges);
        LinkedList<Integer> mstEdgesIndex = new LinkedList<>();
        UnionFind uf = new UnionFind(n);
        int minWeight = getMSTWeight(nedges, -1, mstEdgesIndex, uf, -1);
        List<Integer> criticalEdgeIndex = new ArrayList<>(mstEdgesIndex.size());
        List<Integer> noncriticalEdgeIndex = new ArrayList<>();
        HashSet<Integer> nonEdgeIndexSet = new HashSet<>();
        for (int index : mstEdgesIndex) {
            uf.clear();
            int weight = getMSTWeight(nedges, index, null, uf, -1);
            if (weight > minWeight || uf.count != 1) { // 由于去掉关键边以后，可能无法合成一个连通子图或者导致权重变大
                criticalEdgeIndex.add(nedges.get(index).index);
            } else {
                noncriticalEdgeIndex.add(nedges.get(index).index);
            }
            nonEdgeIndexSet.add(index);
        }
        
        for (int i = 0;i < N;++i) {
            if (!nonEdgeIndexSet.contains(i)) {
                uf.clear();
                int weight = getMSTWeight(nedges, -1, null, uf, i);
                if (weight == minWeight) { // 当某个最小生成树包含该非关键边，导致权重不变
                    noncriticalEdgeIndex.add(nedges.get(i).index);
                }
            }
        }
        List<List<Integer>> res = new ArrayList<>();
        res.add(criticalEdgeIndex);
        res.add(noncriticalEdgeIndex);
        return res;
    }
}
