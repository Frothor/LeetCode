int* findMinHeightTrees(int n, int** edges, int edgesSize, int* edgesColSize, int* returnSize){
    int ** connect = malloc(sizeof(int *) * n);
    int * index = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++){
        connect[i] = malloc(sizeof(int));
        index[i] = 0;
    }
    int p1, p2;
    for (int i = 0; i < edgesSize; i++){
        p1 = edges[i][0];
        p2 = edges[i][1];
        connect[p1] = realloc(connect[p1], sizeof(int) * (index[p1] + 1));
        connect[p2] = realloc(connect[p2], sizeof(int) * (index[p2] + 1));
        connect[p1][index[p1]] = p2;
        connect[p2][index[p2]] = p1;
        index[p1] += 1;
        index[p2] += 1;
    }
    int * queue = malloc(sizeof(int) * n);
    int start = 0, end = 0;
    for (int i = 0; i < n; i++){
        if (index[i] <= 1){
            queue[end] = i;
            end++;
        }
    }
    int cur;
    int num = n;
    while (num > 2){
        int flag = end;
        while (start < flag){
            cur = queue[start];
            start++;
            num--;
            for (int i = 0; i < index[cur]; i++){
                while (index[connect[cur][i]] < 1){
                    i++;
                }
                index[connect[cur][i]]--;
                if (index[connect[cur][i]] == 1){
                    queue[end] = connect[cur][i];
                    end++;
                }
            }
            index[cur]--;
        }
        for (int i = start; i < end; i++){
            queue[i - start] = queue[i];
        }
        end = end - start;
        start = 0;
    }
    int * result = malloc(sizeof(int) * 2);
    *returnSize = 0;
    int i = 0;
    while (start < end){
        result[i] = queue[start];
        start++;
        i++;
        *returnSize = *returnSize + 1;
    }
    return result;
}

//Third fastest
struct graph{
  int val;
    struct graph *next;
};
int* findMinHeightTrees(int n, int** edges, int edgesSize, int* edgesColSize, int* returnSize){
    struct graph **g=(struct graph**)calloc(sizeof(struct graph*),n+1);
    int i,u,v,temp;
    int *degree=(int*)calloc(sizeof(int),n+1);
    int *queue=(int*)malloc(sizeof(int)*(n+1)),front=0,rear=-1;
    for(i=0;i<edgesSize;i++)
    {
        u=edges[i][0];
        v=edges[i][1];
        degree[u]++;
        degree[v]++;
       struct graph *node=(struct graph*)malloc(sizeof(struct graph));
        node->val=v;
        if(g[u]==NULL)
        {
            g[u]=node;
            node->next=NULL;
        }
        else
        {
            node->next=g[u];
            g[u]=node;
        }
        struct graph *node1=(struct graph*)malloc(sizeof(struct graph));
        node1->val=u;
        if(g[v]==NULL)
        {
            g[v]=node1;
            node1->next=NULL;
        }
        else
        {
            node1->next=g[v];
            g[v]=node1;
        }
    }
    for(i=0;i<n;i++)
    {
        if(degree[i]==1||degree[i]==0)
            queue[++rear]=i;
    }
    int visited=0;
    while(visited<n-2)
    {
        int temp=rear;
        for(front;front<=temp;front++)
        {
            struct graph *node=g[queue[front]];
            visited++;
            while(node)
            {
                degree[node->val]--;
                if(degree[node->val]==1)
                    queue[++rear]=node->val;
                node=node->next;
            }
        }
        front=temp+1;
    }
    //printf("%d %d %d",front,rear,queue[front]);
    *returnSize=rear-front+1;
    return queue+front;
}


//Second fastest
typedef struct GraphNode
{
	int node;
	struct GraphNode *next;
} GraphNode;

struct GraphNode *createNode(int val)
{
	struct GraphNode *node = (struct GraphNode *)malloc(sizeof(struct GraphNode));
	node->node = val;
	node->next = 0;
	return node;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *findMinHeightTrees(int n, int **edges, int edgesSize, int *edgesColSize, int *returnSize)
{
	if (n == 1)
	{
		*returnSize = 1;
		int *res = (int *)malloc(sizeof(int) * (*returnSize));
		res[0] = 0;
		return res;
	}

	struct GraphNode *graph[n];
	int indgree[n];
	memset(graph, 0, sizeof(graph));
	memset(indgree, 0, sizeof(indgree));
	for (int i = 0; i < edgesSize; ++i)
	{
		struct GraphNode *node = createNode(edges[i][1]);
		node->next = graph[edges[i][0]];
		graph[edges[i][0]] = node;
		node = createNode(edges[i][0]);
		node->next = graph[edges[i][1]];
		graph[edges[i][1]] = node;
		++indgree[edges[i][0]];
		++indgree[edges[i][1]];
	}
	int leavenode[n], leavenodesize = 0;
	for (int i = 0; i < n; ++i)
	{
		if (indgree[i] == 1)
			leavenode[leavenodesize++] = i;
	}

	for (int m = n; m > 2;)
	{
		int next[n], nextsize = 0;
		m -= leavenodesize;
		for (int i = 0; i < leavenodesize; ++i)
		{
			int node = leavenode[i];
			for (struct GraphNode *p = graph[node]; p; p = p->next)
			{
				if (--indgree[p->node] == 1)
					next[nextsize++] = p->node;
			}
		}
		leavenodesize = nextsize;
		memcpy(leavenode, next, sizeof(int) * nextsize);
	}
	*returnSize = leavenodesize;
	int *res = (int *)malloc(sizeof(int) * (*returnSize));
	memcpy(res, leavenode, sizeof(int) * (*returnSize));
	return res;
}

//Fastest
//Find the diameter of the tree(Longest path length)
//If longest path length is even then there is only one MHT else 2
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct graph{
  int val;
    struct graph *next;
};
int* findMinHeightTrees(int n, int** edges, int edgesSize, int* edgesColSize, int* returnSize){
    struct graph **g=(struct graph**)calloc(sizeof(struct graph*),n+1);
    int i,u,v,temp;
    for(i=0;i<edgesSize;i++)
    {
        u=edges[i][0];
        v=edges[i][1];
       struct graph *node=(struct graph*)malloc(sizeof(struct graph));
        node->val=v;
        if(g[u]==NULL)
        {
            g[u]=node;
            node->next=NULL;
        }
        else
        {
            node->next=g[u];
            g[u]=node;
        }
        struct graph *node1=(struct graph*)malloc(sizeof(struct graph));
        node1->val=u;
        if(g[v]==NULL)
        {
            g[v]=node1;
            node1->next=NULL;
        }
        else
        {
            node1->next=g[v];
            g[v]=node1;
        }
    }
    int *ret=(int*)malloc(sizeof(int)*2);
    int max_dist=0,start_node=0,root1=-1,root2=-1;
    int *dfs_order=(int*)malloc(sizeof(int)*(n+1));
    dfs(g,0,&max_dist,&start_node,dfs_order,0,-1,&root1,&root2);
    max_dist=0;
    root1=start_node;
    root2=-1;
   //printf("%d",start_node);
    dfs(g,start_node,&max_dist,&start_node,dfs_order,0,-1,&root1,&root2);
    ret[0]=root1;
    ret[1]=root2;
    *returnSize=2;
    if(root2==-1)
        *returnSize=1;
    return ret;
}
void dfs(struct graph **g,int i,int *max_dist,int *start_node,int *dfs_order,int dist,int parent,int *root1,int *root2)
{
    dfs_order[dist]=i;
    struct graph *node=g[i];
    while(node)
    {
        if(node->val!=parent)
            dfs(g,node->val,max_dist,start_node,dfs_order,dist+1,i,root1,root2);
        node=node->next;
    }
    if(dist>*max_dist){
        *max_dist=dist;
        *start_node=i;
        if(dist%2==0)
        {
            //printf("%d\n",*root1);
            *root1=dfs_order[dist/2];
            *root2=-1;
        }
        else
        {
            *root1=dfs_order[dist/2];
            *root2=dfs_order[dist/2+1];
        }
    }
}