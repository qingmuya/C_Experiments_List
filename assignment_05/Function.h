#ifndef FUNCTION_H_INCLUDED
#define FUNCTION_H_INCLUDED

//深度优先遍历（邻接矩阵）
void Matrix_DFS(AMGraph &G);

//深度优先遍历（邻接表）
void AdjList_DFS(ALGraph &G);

//广度优先遍历（邻接矩阵）
void Matrix_BFS(AMGraph &G);

//广度优先遍历（邻接表）
void AdjList_BFS(ALGraph &G);

#endif // FUNCTION_H_INCLUDED
