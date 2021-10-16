#include<iostream>
using namespace std;

//bai toan: xay dung duong giao thong, gia su muon noi n thanh pho sao cho giua cac tp bat ki luon co duong di sao cho tong chi phi xay dung nho nhat
//y tuong: nap dan cac dinh vao khung. moi lan chon 1 dinh chua nap sao cho dinh do ke va gan nhat voi cac dinh da nap

// ham thuc hien thuat toan Prim

// A graph is a data structure that consists of the following two components: 
//1. A finite set of vertices also called as nodes. 
//2. A finite set of ordered pair of the form (u, v) called as edge. 
//	The pair is ordered because (u, v) is not the same as (v, u) in case of a directed graph(di-graph). 
//	The pair of the form (u, v) indicates that there is an edge from vertex u to vertex v. 
//	The edges may contain weight/value/cost.
void primMST(int graph[V][V]){
	int parent[V]; // luu dinh cha cua dinh V trong cay bao trum nho nhat 
	int key[V];
	bool mstSet[V]; // danh dau cac dinh da duoc them vao tap cac dinh da xet 

	for (int i = 0; i < V; i++){
		key[i] = INT_MAX;
		mstSet[i] = false;
	}

	key[0] = 0;
	parent[0] = -1;

	for (int count = 0; count < V-1; cout++){
		int u = minKey(key,mstSet);
		mstSet[u] = true;

		for(int v = 0; v < V; v++){
			if(graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]){
				parent[v] = u;
				key[v] = graph[u][v];
			}
		}
 	}
}

// ham dua ra dinh co khoang cach nho nhat voi tap dinh da xet 
++
// mang key luu khoang cach nho nhat tu cay bao trum den cac dinh 
int minKey(int key[], bool mstSet[]){
	int min = INT_MAX, min_index;

	for(int v = 0; v < V; v++){
		if (mstSet[v] == false && key[v] < min){
			min = key[v];
			min_index = v;
		}
	}

	return min_index;
}

