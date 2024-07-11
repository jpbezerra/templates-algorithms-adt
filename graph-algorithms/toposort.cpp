void topoSort(int value, stack<int> myStack) {
    setMark(value, true);

    for (auto i : adj[value]) {
        if (isEdge(value, i)) {
            if (!getMark(i)) {
                topoSort(i, myStack)
            }
        }
    }
    
    myStack.push(value);
}