const WHITE_TILE_COLOR = "rgb(255, 228, 196)";
const BLACK_TILE_COLOR = "rgb(206, 162, 128)";
const HIGHLIGHT_COLOR = "rgb(75, 175, 75)";
const WHITE = 'figure figure-white';
const BLACK = 'figure figure-black';
const WHITE_LOG = '&#x2656;';
const BLACK_LOG = '&#x265C;';

const CellState = Object.freeze({ EMPTY: -1, ARROW: 1, QUEEN: 2 , CAPTURE: 3});
const GameMode = Object.freeze({ PLAYER: 0, AI: 1});

let selectedGameMode;

const INVALID = 0;
const VALID = 1;
const VALID_CAPTURE = 2;

let whiteCasualitiesText;
let blackCasualitiesText;
let totalVictoriesText;

let whiteCasualities;
let blackCasualities;

let whiteVictories;
let blackVictories;

let isMove;
let isShoot;
let currX;
let currY;
let currentTeam;
let currentPossibleWays;
let whiteCaptured;
let blackCaptured;
let MaxFigurePerTeam;
const TEAMWHITE = 0;
const TEAMBLACK = 1;
let currentTeamText;
let gameTable;
let gameLog;
let highlightedCell;

let gameType;
let state = 'EMPTY';
let startValidMove;
let stopValidMove;
let boardHeight;
let boardWidth;
let gameFinished;

function selectGameMode(mode) {
    selectedGameMode = mode;
    setStage(UIStage.STAGE_PROPERTIES);
}

function startGame() {
    isMove = false;
    isShoot = false;
    gameFinished = false;
    currentPossibleWays = 0;
    whiteCaptured = 0;
    blackCaptured = 0;
    currentTeam = TEAMWHITE;
    currentTeamText = document.getElementById("currentTeamText");
    currentTeamText.textContent = "White's turn";
    gameTable = document.getElementById("gameTable");
    gameTable.classList.add('tabble-white-turn');
    gameLog = document.getElementById('gameLog');
    gameLog.value = "";
    gameType = document.gameChoiceForm.gameMode.value;
    MaxFigurePerTeam = gameType;
    if (gameType == 2) {
        createField(6, 6);
        placeFigure(0,3, BLACK);
        placeFigure(5,2, BLACK);
        placeFigure(2,0, WHITE);
        placeFigure(3,5, WHITE);
    }
    else if (gameType == 3) {
        createField(8, 8);
        placeFigure(2,0, WHITE);
        placeFigure(0,3, WHITE);
        placeFigure(2,7, WHITE);
        placeFigure(5,0, BLACK);
        placeFigure(7,4, BLACK);
        placeFigure(5,7, BLACK);
    }
    else if (gameType == 4) {
        createField(10, 10);
        placeFigure(9,3, BLACK);
        placeFigure(6,0, BLACK);
        placeFigure(9,6, BLACK);
        placeFigure(6,9, BLACK);
        placeFigure(3,0, WHITE);
        placeFigure(0,3, WHITE);
        placeFigure(0,6, WHITE);
        placeFigure(3,9, WHITE);
    }
    drawFieldMarks(boardHeight, boardWidth);
    setStage(UIStage.STAGE_GAME);
}

function createField(width, height) {
    boardHeight = height;
    boardWidth = width;
    gameTable.innerHTML = "";

    for (let i = 0; i < height; i++) {
        let tableRow = document.createElement("div");
        tableRow.className = 'table-row';
        tableRow.id = 'row' + i;
        for (let j = 0; j < width; j++) {
            let tableBlock = document.createElement("div");
            tableBlock.className = 'table-block';
            tableBlock.id = 'tb' + i + '_' + j;
            tableBlock.onclick = (function() {
                return function() { 
                    onCellClicked(i, j);
                }
            })();
            tableBlock.dataset.state = CellState.EMPTY;
            tableRow.append(tableBlock);
        }
        gameTable.append(tableRow);
    }
}



function placeFigure(i, j, className) {
    let tableCell = document.getElementById('tb' + i + '_' + j);
    tableCell.innerHTML = "";
    let figure = document.createElement('div');
    figure.className = className;
    tableCell.append(figure);
    tableCell.dataset.state = CellState.QUEEN;
}

function replaceFigure(i, j) { 
    let tableCellTo = document.getElementById('tb' + i + '_' + j);
    let tableCellFrom = document.getElementById('tb' + currX + '_' + currY);
    if(isMove){
        tableCellTo.innerHTML = tableCellFrom.innerHTML;
        tableCellTo.dataset.state = CellState.QUEEN;
        tableCellFrom.innerHTML = "";
        tableCellFrom.dataset.state = CellState.EMPTY;
        isMove = false;
        isShoot = true;
        logMove(currX, currY, i, j);
        currX = i;
        currY = j;
        highlightCurrentFigure();
        showPossibleFigureMoves();
    }
}

function makeShoot(i, j){
    let tableCell = document.getElementById('tb' + i + '_' + j);
    let arrowFigure = document.createElement('div');
    arrowFigure.className = 'figure figure-arrow';
    tableCell.append(arrowFigure);
    tableCell.dataset.state = CellState.ARROW;
    isShoot = false;
    deHighlightFigure();
    stopShowPossibleFigureMoves();
    logShot(i, j);
    changeCurrentTeam();
    checkForSeparatedTeamsFigures();
}

function onCellClicked(i, j) {
    if (gameFinished) return;
    let tableCell = document.getElementById('tb' + i + '_' + j);
    let className = "";
    if(tableCell.dataset.state != CellState.EMPTY) className = tableCell.childNodes[0].className;

    if(tableCell.dataset.state != CellState.EMPTY && currentTeam == getCurrentTeam(className) && tableCell.dataset.state != CellState.ARROW && isShoot == false && tableCell.dataset.state != CellState.CAPTURE){
        isMove = true;
        currX = i;
        currY = j;
        highlightCurrentFigure();
        showPossibleFigureMoves();
        if(isCurrentCapture()){
            tableCell.dataset.state = CellState.CAPTURE;
            if (getCurrentTeam(className) == TEAMWHITE) whiteCaptured++;
            else blackCaptured++;
        }
    }
    if(tableCell.dataset.state == CellState.EMPTY && isMove == true && isShoot == false && checkValidMovement(i, j)){
        replaceFigure(i, j);
    }
    if(tableCell.dataset.state == CellState.EMPTY && isShoot == true  && checkValidMovement(i, j)){
        makeShoot(i, j);
    }
}

function checkValidMovement(i, j){ 
    if(isShoot == true || isMove == true) {
        //vertical/horizontal
        if(currX == i || currY == j) {
            if(currX == i) {
                getStartStopMovement(currY, j);
                return validHorVerMovement(i, null);
            } else if (currY == j) {
                getStartStopMovement(currX, i);
                return validHorVerMovement(null, j);
            }
        }//cross up right
        else if(currX > i && currY < j) {
            return validCrossMovement(i, j, true, false, true);
        //cross up left
        }else if(currX > i && currY > j){
            return validCrossMovement(i, j, true, false, false);
        //cross down right    
        }else if(currX < i && currY < j){
            return validCrossMovement(i, j, false, true, true);
        //cross down left
        }else if(currX < i && currY > j) {
            return validCrossMovement(i, j, false, true, false);
        }
    }
    return false;
}

/**
 * After every finished move this function must determine if there is no way for figures
 * from opposite team to meet each other
 */
function checkForSeparatedTeamsFigures() {
    let finishGame =  false;
    let queens = Array.from(document.getElementsByClassName(WHITE));
    Array.from(document.getElementsByClassName(BLACK)).forEach(elem => queens.push(elem));
    //document.getElementsByClassName(BLACK).forEach((elem) => queens.push(elem));
    for (let l = 0; l < queens.length; l++) {
        //console.log(queens[i]);
        let p = queens[l].parentElement;
        let queenI = getQueenI(p);
        let queenJ = getQueenJ(p);
        console.log( 'Queen on position ' + mapJToLetters(queenJ) + mapIToNumbers(queenI) + ' is lonely: ' + checkFigureLoneliness(queens[l].className, queenI, queenJ));
        if (isQueenCaptured(queenI, queenJ)) {
            console.log("queen " + queenI + ' ' + queenJ + ' is captured');
            finishGame = true;
        } 
        else if (checkFigureLoneliness(queens[l].className, queenI, queenJ)) finishGame = true;
        else return;
    }
    if (finishGame) {
        console.log("Game finished");
        finishGameAndDisplayResults();
    }
}

/**
 * Check if queen is not colliding with opposite team queens
 * BFS approach alghoritm
 * @param {HTMLElement} queen
 * @returns false if queen collide with other team's queen
 * @returns true if no other team's queens are in all possible neigbour cells
 */
function checkFigureLoneliness(queenClassName, queenI, queenJ) {
    // to compare queen teams just compare their classList
    //let queenI = getQueenI(queen);
    //let queenJ = getQueenJ(queen);
    let currentFieldMatrix = getFieldMatrix();
    let visited = new Array(boardHeight);
    for (let k = 0; k < boardHeight; k++) {
        visited[k] = new Array(boardWidth);
        for (let l = 0; l < boardWidth; l++) {
            visited[k][l] = false;
        }
    }

    //const coords = { i: 0, j: 0 }
    let queue = [];
    queue.push({i: queenI, j: queenJ});
    visited[queenI][queenJ] = true;

    while (queue.length > 0) {
        
        let coord = queue[0];
        let i = coord.i;
        let j = coord.j;

        queue.shift();

        // up
        if (isValidCoord(i - 1, j, boardHeight, boardWidth) && visited[i - 1][j] == false) {
            if (currentFieldMatrix[i - 1][j].state == CellState.EMPTY) {
                queue.push({ i: i - 1 , j: j });
                visited[i - 1][j] = true;
            }
            else if (currentFieldMatrix[i - 1][j].state == CellState.QUEEN && queenClassName != currentFieldMatrix[i - 1][j].queenTeam) return false;
        }

        // up left
        if (isValidCoord(i - 1, j - 1, boardHeight, boardWidth) && visited[i - 1][j - 1] == false) {
            if (currentFieldMatrix[i - 1][j - 1].state == CellState.EMPTY) {
                queue.push({ i: i - 1 , j: j - 1 });
                visited[i - 1][j - 1] = true;
            }
            else if (currentFieldMatrix[i - 1][j - 1].state == CellState.QUEEN && queenClassName != currentFieldMatrix[i - 1][j - 1].queenTeam) return false;
        }

        // up right
        if (isValidCoord(i - 1, j + 1, boardHeight, boardWidth) && visited[i - 1][j + 1] == false) {
            if (currentFieldMatrix[i - 1][j + 1].state == CellState.EMPTY) {
                queue.push({ i: i - 1 , j: j + 1 });
                visited[i - 1][ j + 1] = true;
            }
            else if (currentFieldMatrix[i - 1][j + 1].state == CellState.QUEEN && queenClassName != currentFieldMatrix[i - 1][j + 1].queenTeam) return false;
        }

        // left
        if (isValidCoord(i, j - 1, boardHeight, boardWidth) && visited[i][j - 1] == false) {
            if (currentFieldMatrix[i][j - 1].state == CellState.EMPTY) {
                queue.push({ i: i , j: j - 1 });
                visited[i][ j - 1] = true;
            }
            else if (currentFieldMatrix[i][j - 1].state == CellState.QUEEN && queenClassName != currentFieldMatrix[i][j - 1].queenTeam) return false;
        }

        // right
        if (isValidCoord(i, j + 1, boardHeight, boardWidth) && visited[i][j + 1] == false) {
            if (currentFieldMatrix[i][j + 1].state == CellState.EMPTY) {
                queue.push({ i: i , j: j + 1 });
                visited[i][ j + 1] = true;
            }
            else if (currentFieldMatrix[i][j + 1].state == CellState.QUEEN && queenClassName != currentFieldMatrix[i][j + 1].queenTeam) return false;
        }

        // down
        if (isValidCoord(i + 1, j, boardHeight, boardWidth) && visited[i + 1][j] == false) {
            if (currentFieldMatrix[i + 1][j].state == CellState.EMPTY) {
                queue.push({ i: i + 1 , j: j });
                visited[i + 1][ j] = true;
            }
            else if (currentFieldMatrix[i + 1][j].state == CellState.QUEEN && queenClassName != currentFieldMatrix[i + 1][j].queenTeam) return false;
        }

        // down left
        if (isValidCoord(i + 1, j - 1, boardHeight, boardWidth) && visited[i + 1][j - 1] == false) {
            if (currentFieldMatrix[i + 1][j - 1].state == CellState.EMPTY) {
                queue.push({ i: i + 1 , j: j - 1 });
                visited[i + 1][ j - 1] = true;
            }
            else if (currentFieldMatrix[i + 1][j - 1].state == CellState.QUEEN && queenClassName != currentFieldMatrix[i + 1][j - 1].queenTeam) return false;
        }

        // down right
        if (isValidCoord(i + 1, j + 1, boardHeight, boardWidth) && visited[i + 1][j + 1] == false) {
            if (currentFieldMatrix[i + 1][j + 1].state == CellState.EMPTY) {
                queue.push({ i: i + 1 , j: j + 1 });
                visited[i + 1][ j + 1] = true;
            }
            else if (currentFieldMatrix[i + 1][j + 1].state == CellState.QUEEN && queenClassName != currentFieldMatrix[i + 1][j + 1].queenTeam) return false;
        }

    }

    return true;
}

function finishGameAndDisplayResults() {
    gameFinished = true;
    currentTeamText.textContent = "Game finished!";
    gameLog.value += "Game finished!"
}

function calculateTeamPoints() {
    let whitePoints = 0;
    let blackPoints = 0;
    let whiteQueens = Array.from(document.getElementsByClassName(WHITE));
    let blackQueens = Array.from(document.getElementsByClassName(BLACK));
}

function isValidCoord(i, j, height, width) {
    if (i < 0 || j < 0 ) return false;
    else if ( i >= height || j >= width) return false;
    else return true;
}

function validCrossMovement(i, j, isBigger, opX, opY){
    var x;
    if(isBigger) x = currX - i; //diff
    else x = i - currX;
    
    for(let b = 1; b < x; b++){
        let tableCell;
        if(!opX && opY) tableCell = document.getElementById('tb' + (currX-b) + '_' + (currY+b));
        else if(!opX && !opY) tableCell = document.getElementById('tb' + (currX-b) + '_' + (currY-b));
        else if(opX && opY) tableCell = document.getElementById('tb' + (currX+b) + '_' + (currY+b));
        else if(opX && !opY) tableCell = document.getElementById('tb' + (currX+b) + '_' + (currY-b));
        else return false;

        if(tableCell == null){
            return false;
        }

        if(tableCell.dataset.state == CellState.ARROW || tableCell.dataset.state == CellState.QUEEN){
            return false;
        }
    }
    if(currY + x == j || currY - x == j) return true;
}

function validHorVerMovement(i , j){
    for(let b = startValidMove; b < stopValidMove; b++){
        let tableCell;
        if(i != null){tableCell = document.getElementById('tb' + i + '_' + b); }
        else {tableCell = document.getElementById('tb' + b + '_' + j); }

        if(tableCell.dataset.state == CellState.ARROW || tableCell.dataset.state == CellState.QUEEN){
            return false;
        }
    }
    return true;
}

function getStartStopMovement(a, b){
    if(a > b){
        startValidMove = b + 1;
        stopValidMove = a;
    }else{
        startValidMove = a + 1;
        stopValidMove = b;
    }
}

function highlightCurrentFigure() {
    if (highlightedCell != undefined) {
        deHighlightFigure();
        stopShowPossibleFigureMoves();
    }
    let tableCell = document.getElementById('tb' + currX + '_' + currY);
    tableCell.classList.add('block-highlight');
    highlightedCell = tableCell;
}

function deHighlightFigure() {
    highlightedCell.classList.remove('block-highlight');
    highlightedCell = undefined;
}

function showPossibleFigureMoves() {
    for (let i = 0; i < boardHeight; i++) {
        for (let j = 0; j < boardWidth; j++) {
            let tableCell = document.getElementById('tb' + i + '_' + j);
            if(checkValidMovement(i, j) && tableCell.dataset.state != CellState.QUEEN && tableCell.dataset.state != CellState.ARROW){
                let possibleWay = document.createElement('div');
                possibleWay.className = 'possible-way'
                tableCell.append(possibleWay);
                currentPossibleWays++;
            }
        }
    }
}

function stopShowPossibleFigureMoves() {
    currentPossibleWays = 0;
    let possibleWays = document.getElementsByClassName('possible-way');
    while (possibleWays.length > 0) {
        possibleWays[0].parentNode.removeChild(possibleWays[0]);
    }
}

function changeCurrentTeam() {
    if (currentTeam === TEAMWHITE) {
        currentTeamText.textContent = "Black's turn";
        gameTable.classList.remove('tabble-white-turn');
        gameTable.classList.add('table-black-turn');
        currentTeam = TEAMBLACK;
    } else {
        currentTeamText.textContent = "White's turn";
        gameTable.classList.remove('table-black-turn');
        gameTable.classList.add('tabble-white-turn');
        currentTeam = TEAMWHITE;
    }
}

function getCurrentTeam(figure) {
    if(figure == WHITE) {
        return TEAMWHITE;
    } else if(figure == BLACK) {
        return TEAMBLACK;
    }
    return null;
}

function getQueenI(queen) {
    return parseInt(queen.id[2]);
}

function getQueenJ(queen) {
    return parseInt(queen.id[4]);
}

function isCurrentCapture(){
    if(currentPossibleWays == 0) return true;
    return false;
}

function isQueenCaptured(queenI, queenJ) {
    let currMatrix = getFieldMatrix();
    //let currQeenOnMatrix = currMatrix[queenI][queenJ];
    for (let i = queenI - 1; i <= queenI + 1; i++) {
        for (let j = queenJ - 1; j <= queenJ + 1; j++) {
            if (isValidCoord(i , j, boardHeight, boardWidth) && currMatrix[i][j].state == CellState.EMPTY) {
                return false;
            }
        }
    }
    return true;
}

/**
 * Creates matrix from html elements on board
 */
function getFieldMatrix() {
    let matrix = new Array(boardHeight);
    for (let i = 0; i < boardHeight; i++){
        matrix[i] = new Array(boardWidth);
        for (let j = 0; j < boardWidth; j++){
            let cell = document.getElementById('tb' + i + '_' + j);
            let s = { state: parseInt(cell.dataset.state), queenTeam: null };
            if (cell.dataset.state == CellState.QUEEN) s.queenTeam = cell.firstChild.className;
            matrix[i][j] = s;
        }
    }
    return matrix;
}

function logMove(fromI, fromJ, toI, toJ) {
    let symbol;
    if (currentTeam == TEAMWHITE) symbol = WHITE_LOG;
    else if (currentTeam == TEAMBLACK) symbol = BLACK_LOG;

    // другого способа нету
    let tmp = document.createElement('span');
    tmp.innerHTML = symbol;

    gameLog.value += tmp.innerHTML + ': ' + '(' +  mapJToLetters(fromJ) + mapIToNumbers(fromI) + ')->(' + mapJToLetters(toJ) + mapIToNumbers(toI) + ')'; 
}

function logShot(i, j) {
    let tmp = document.createElement('span');
    tmp.innerHTML = "&#x1F525";
    gameLog.value += '->' + tmp.innerHTML + '(' + mapJToLetters(j) + mapIToNumbers(i) + ')\n';
}
