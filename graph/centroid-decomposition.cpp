// dis[l][u] denotes the distance in original tree of node u to the anscentor of u that is at depth l in centroid tree 
const long long MX = 1e5 + 10;
const long long MX1 = 20;
VI g[MX];
int lvl[MX], sz[MX], p[MX], dis[MX1][MX];
void cal_subtree_size(int u, int pu) {
    sz[u] = 1;
    for (int v : g[u]) {
        if (v != pu && lvl[v] == -1) {
            cal_subtree_size(v, u);
            sz[u] += sz[v];
        }
    }
}
int find_centroid(int u) {
    for (int v : g[u]) {
        if (lvl[v] == -1 && sz[v] > sz[u] / 2) {
            sz[u] -= sz[v];
            sz[v] += sz[u];
            return find_centroid(v);
        }
    }
    return u;
}
void cal_dis(int u, int pu, int l) {
    for (int v : g[u]) {
        if (v != pu && lvl[v] == -1) {
            dis[l][v] = dis[l][u] + 1;
            cal_dis(v, u, l);
        }
    }
}
int build_centroid_tree(int root, int l) {
    cal_subtree_size(root, -1);
    int croot = find_centroid(root);
    lvl[croot] = l;
    dis[l][croot] = 0;
    cal_dis(croot, -1, l);

    for (int v : g[croot]) {
        if (lvl[v] == -1) {
            int cv = build_centroid_tree(v, l + 1);
            p[cv] = croot;
        }
    }
    return croot;
}
void centroid_decomposition(int n, int root) {
    loop(i, 0, n + 1) lvl[i] = -1;
    int croot = build_centroid_tree(root, 0);
    p[croot] = -1;
}

