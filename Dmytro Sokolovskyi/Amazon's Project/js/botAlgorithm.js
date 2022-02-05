class TreeNode {
    constructor(x,y) {
      this.descendants = [];
      this.x = x;
      this.y = y;
      this.value = getNumberOfPossibleways(x, y);
    }
  }

function bot() {
    var tabOfQueen = new Array (document.gameChoiceForm.gameMode.value);
    let qw; 
    let className = "";
    //find all queen
    for (let i = 0; i < getBoardHeight(); i++) {
        for (let j = 0; j < getBoardHeight(); j++) {
            let tableCell = document.getElementById('tb' + i + '_' + j);
            if(tableCell.dataset.state == CellState.QUEEN) 
            {
                className = tableCell.childNodes[0].className;
                if(currentTeam == getCurrentTeam(className) && getNumberOfPossibleways(i, j) > 0){
                    qw = new TreeNode(i, j);
                    tabOfQueen.push(qw);
                }
            }   
        }
    }
    //push pw for qw
    for(let n = 1; n < tabOfQueen.length; n++){
        for (let i = 0; i < getBoardHeight(); i++) {
            for (let j = 0; j < getBoardHeight(); j++) {
                let tableCell = document.getElementById('tb' + i + '_' + j);
                if(checkValidMovement(i, j, tabOfQueen[n].x, tabOfQueen[n].y) && tableCell.dataset.state != CellState.QUEEN && tableCell.dataset.state != CellState.ARROW){
                    tabOfQueen[n].descendants.push(new TreeNode(i, j));
                }
            }
        }
    }
    
    let bestNode = new TreeNode(-1, -1);//queen;
    var bestNodePos;
    bestNode.value=0;
    for(let n = 1; n < tabOfQueen.length; n++){
        for(let i = 0; i < tabOfQueen[n].descendants.length; i++){
            if(tabOfQueen[n].descendants[i].value > bestNode.value){
                bestNode = tabOfQueen[n].descendants[i];
                bestNodePos = n;
            }
        }
    }
    
    console.log(bestNode);
    replaceFigure(bestNode.x, bestNode.y, tabOfQueen[bestNodePos].x, tabOfQueen[bestNodePos].y);
    
    for (let i = 0; i < getBoardHeight(); i++) {
        for (let j = 0; j < getBoardHeight(); j++) {
            let tableCell = document.getElementById('tb' + i + '_' + j);
            if(checkValidMovement(i, j, bestNode.x, bestNode.y) && tableCell.dataset.state != CellState.QUEEN && tableCell.dataset.state != CellState.ARROW){
                bestNode.descendants.push(new TreeNode(i, j));
            }
        }
    }
    console.log(bestNode.descendants);
    for(let i = 0; i < bestNode.descendants.length; i++){
        if(isEnemyQueenNearby(bestNode.descendants[i].x, bestNode.descendants[i].y)){
            makeShoot(bestNode.descendants[i].x, bestNode.descendants[i].y);
            return;
        }
    }
    if(isShoot){
        makeShoot(bestNode.descendants[0].x, bestNode.descendants[0].y);
    }
}

function getNumberOfPossibleways(currX, currY) {
    let currPW = 0;
    for (let i = 0; i < getBoardHeight(); i++) {
        for (let j = 0; j < getBoardHeight(); j++) {
            let tableCell = document.getElementById('tb' + i + '_' + j);
            if(checkValidMovement(i, j, currX, currY) && tableCell.dataset.state != CellState.QUEEN && tableCell.dataset.state != CellState.ARROW){
                currPW++;
            }
        }
    }
    return currPW;
}

function isEnemyQueenNearby(x, y){
    var isQueen = false;           
    let tableCell = document.getElementById('tb' + (x-1) + '_' + (y-1));
    isQueen = getProps(tableCell);
    if(isQueen) return true;
    tableCell = document.getElementById('tb' + (x-1) + '_' + y);
    isQueen = getProps(tableCell);
    if(isQueen) return true;
    tableCell = document.getElementById('tb' + (x-1) + '_' + (y+1));
    isQueen = getProps(tableCell);
    if(isQueen) return true;
    tableCell = document.getElementById('tb' + x + '_' + (y-1));
    isQueen = getProps(tableCell);
    if(isQueen) return true;
    tableCell = document.getElementById('tb' + x + '_' + (y+1));
    isQueen = getProps(tableCell);
    if(isQueen) return true;
    tableCell = document.getElementById('tb' + (x+1) + '_' + (y-1));
    isQueen = getProps(tableCell);
    if(isQueen) return true;
    tableCell = document.getElementById('tb' + (x+1) + '_' + y);
    isQueen = getProps(tableCell);
    if(isQueen) return true;
    tableCell = document.getElementById('tb' + (x+1) + '_' + (y+1));
    isQueen = getProps(tableCell);
    if(isQueen) return true;
    return false
}

function getProps(tableCell){
    let className = ""; 
    if(tableCell != null){
        if(tableCell.dataset.state == CellState.QUEEN){
            className = tableCell.childNodes[0].className;
            if(currentTeam != getCurrentTeam(className)){
                return true;
            }
        }
    }
}