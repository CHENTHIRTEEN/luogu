### bfs
使用队列实现
+ 一般形式
```cpp
Q.push(初始状态);//将初始状态入队
while(!Q.empty()){
    State u = Q.front(); Q.pop();//取出队首元素
    Q.pop();
    for(){
        if(合法){
            Q.push(新状态);//将新状态入队
        }
    }
}
```