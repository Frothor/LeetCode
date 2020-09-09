var sumRootToLeaf = function(root) {
    let retVal = 0;
    df(root, 0);
    return retVal;
	//recursive depth-first function here. Inputs are the current node, and the accumulated value.
    function df(node, val){
        if(node === null){return} //handles any null sets, as well as a single-child node.
		val <<= 1;              //bitwise operation, left shift assignment, basically shifts the binary bits of the number to the left by the set amount. 
								//In this case, we open up the rightmost position and then add in the current value. (could be acheived by taking val = val*2 + node.val, but the bitwise operations are (theoretically) faster.
        val += node.val;
		//add the current value, if we have no children on this node.
        if(node.left === null && node.right === null){
            retVal += val;
            return;
        }
		//recurses on both possible children.
        df(node.left, val);
        df(node.right, val);
        return;
    }
};


//Fastest
var sumRootToLeaf = function(root) {
    let result = 0;
    function traverse(root,temp){
        if(!root) return;
        temp += root.val;
        if(!root.left && !root.right){
            result+= Number(parseInt(temp, 2));
        }
        traverse(root.left,temp);
        traverse(root.right, temp);
    }
    traverse(root, '');
    return result;
    
};