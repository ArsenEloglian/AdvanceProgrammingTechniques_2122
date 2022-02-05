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
let isBotMove;
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

let boardSnapshots;
let currentTurnNumber;
let firstCancel;

function selectGameMode(mode) {
    selectedGameMode = mode;
    setStage(UIStage.STAGE_PROPERTIES);
}

function getBoardHeight() {
    return boardHeight;
}

function getBoardWidth() {
    return boardWidth;
}

function startGame() {
    isMove = false;
    isShoot = false;
    isBotMove = false;
    gameFinished = false;
    currentPossibleWays = 0;
    whiteCaptured = 0;
    blackCaptured = 0;
    currentTeam = TEAMWHITE;
    boardSnapshots = [];
    currentTurnNumber = 0;
    firstCancel = true;
    currentTeamText = document.getElementById("currentTeamText");
    currentTeamText.textContent = "White's turn";
    gameTable = document.getElementById("gameTable");
    document.body.classList.add('table-white-turn');
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
    saveCurrentBoard();
}

function restartGame() {
    hideScoreBoard();
    startGame();
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

function replaceFigure(i, j, currX1, currY1) { 
    let tableCellTo = document.getElementById('tb' + i + '_' + j);
    let tableCellFrom = document.getElementById('tb' + currX1 + '_' + currY1);
    if(isMove || isBotMove){
        tableCellTo.innerHTML = tableCellFrom.innerHTML;
        tableCellTo.dataset.state = CellState.QUEEN;
        tableCellFrom.innerHTML = "";
        tableCellFrom.dataset.state = CellState.EMPTY;
        isMove = false;
        isShoot = true;
        logMove(currX1, currY1, i, j);
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
    saveCurrentBoard();
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
    if (tableCell.dataset.state == CellState.EMPTY && isMove == true && isShoot == false && checkValidMovement(i, j, currX, currY)) {
        replaceFigure(i, j, currX, currY);
    }
    if (tableCell.dataset.state == CellState.EMPTY && isShoot == true  && checkValidMovement(i, j, currX, currY)) {
        makeShoot(i, j);
    }
}

function checkValidMovement(i, j, currX1, currY1){ 
    if(isShoot == true || isMove == true || isBotMove == true) {
        //vertical/horizontal

        if(currX1 == i || currY1 == j) {
            if(currX1 == i){
                getStartStopMovement(currY1, j);
                return validHorVerMovement(i, null);
            }else if(currY1 == j){
                getStartStopMovement(currX1, i);
                return validHorVerMovement(null, j);
            }
        }//cross up right
        else if(currX1 > i && currY1 < j) {
            return validCrossMovement(i, j, true, false, true, currX1, currY1);
        //cross up left
        }else if(currX1 > i && currY1 > j){
            return validCrossMovement(i, j, true, false, false, currX1, currY1);
        //cross down right    
        }else if(currX1 < i && currY1 < j){
            return validCrossMovement(i, j, false, true, true, currX1, currY1);
        //cross down left
        }else if(currX1 < i && currY1 > j) {
            return validCrossMovement(i, j, false, true, false, currX1, currY1);
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
    for (let l = 0; l < queens.length; l++) {
        let p = queens[l].parentElement;
        let queenI = getQueenI(p);
        let queenJ = getQueenJ(p);
        if (checkFigureLoneliness(queens[l].className, queenI, queenJ) || isQueenCaptured(queenI, queenJ)) finishGame = true;
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
    let currMatrix = getFieldMatrix();
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

        for (let nI = i - 1; nI <= i + 1; nI++) {
            for (let nJ = j - 1; nJ <= j + 1; nJ++) {
                if (isValidCoord(nI, nJ, boardHeight, boardWidth) && visited[nI][nJ] == false) {
                    if (currMatrix[nI][nJ].state == CellState.EMPTY) {
                        queue.push({ i: nI , j: nJ });
                        visited[nI][nJ] = true;
                    }
                    else if (currMatrix[nI][nJ].state == CellState.QUEEN && queenClassName != currMatrix[nI][nJ].queenTeam) {
                        return false;
                    }
                }
            }
        }

    }

    return true;
}

function finishGameAndDisplayResults() {
    gameFinished = true;
    currentTeamText.textContent = "Game finished!";
    gameLog.value += "Game finished!"
    calculatePoints();
}

function calculatePoints() {
    //let blackQueens = Array.from(document.getElementsByClassName(BLACK));
    let visited = new Array(boardHeight);
    let whiteQueens = [];
    let blackQueens = [];
    let currMatrix = getFieldMatrix();
    for (let i = 0; i < currMatrix.length; i++) {
        visited[i] = new Array(boardWidth);
        for (let j = 0; j < currMatrix[i].length; j++) {
            visited[i][j] = false;
            if (currMatrix[i][j].state == CellState.QUEEN) {
                if (currMatrix[i][j].queenTeam == WHITE) {
                    whiteQueens.push({ queenI: i, queenJ: j, queenTeam: WHITE, visited: false });
                }
                else if (currMatrix[i][j].queenTeam == BLACK) {
                    blackQueens.push({ queenI: i, queenJ: j, queenTeam: BLACK, visited: false });
                }
            }
        }
    }

    //calculate white
    let whitePoints = calculateTeamPoints(currMatrix, whiteQueens);
    let blackPoints = calculateTeamPoints(currMatrix, blackQueens);

    if (whitePoints > blackPoints) displayResults('White won!', whitePoints, blackPoints);
    else if (blackPoints > whitePoints) displayResults('Black won!', whitePoints, blackPoints);
    else displayResults('Draw!', whitePoints, blackPoints);
}

function calculateTeamPoints(currMatrix, queensArray) {
    let teamPoints = 0;

    let visited = new Array(currMatrix.length);
    for (let i = 0; i < currMatrix.length; i++) {
        visited[i] = new Array(boardWidth);
        for (let j = 0; j < currMatrix[i].length; j++) {
            visited[i][j] = false;
        }
    }

    for (let q = 0; q < queensArray.length; q++) {
        if (!isQueenCaptured(queensArray[q].queenI, queensArray[q].queenJ) && queensArray[q].visited != true) {
            let queue = [];
            queue.push({i: queensArray[q].queenI, j: queensArray[q].queenJ});
            visited[queensArray[q].queenI][queensArray[q].queenJ] = true;
            queensArray[q].visited = true;
        
            while (queue.length > 0) {
        
                let coord = queue[0];
                let i = coord.i;
                let j = coord.j;
        
                queue.shift();

                for (let nI = i - 1; nI <= i + 1; nI++) {
                    for (let nJ = j - 1; nJ <= j + 1; nJ++) {
                        if (isValidCoord(nI, nJ, boardHeight, boardWidth) && visited[nI][nJ] == false) {
                            if (currMatrix[nI][nJ].state == CellState.EMPTY) {
                                queue.push({ i: nI , j: nJ });
                                visited[nI][nJ] = true;
                                teamPoints++;
                            }
                            else if (currMatrix[nI][nJ].state == CellState.QUEEN) {
                                for (let it = 0; it < queensArray.length; it++){
                                    if (queensArray[it].queenI == nI && queensArray[it].queenJ == nJ) {
                                        queensArray.visited = true;
                                        break;
                                    }
                                }
                            }
                        }
                    }
                }
                
            }
        }
    }
    return teamPoints;
}

function cancelLastMove() {
    isShoot = false;
    isMove = false;
    deHighlightFigure();
    stopShowPossibleFigureMoves();
    tmpLog = '';
    if (selectedGameMode == GameMode.AI) currentTurnNumber -= 1;
    if (firstCancel) {
        currentTurnNumber -= 2;
        firstCancel = false;
    } 
    else currentTurnNumber -= 1;
    let lastSnapshot = boardSnapshots[currentTurnNumber];
    if (lastSnapshot == undefined) alert("No moves were done");
    else {
        reviveBoardFormMatrix(lastSnapshot.snapshot);
        setCurrentTeam(lastSnapshot.teamTurn);
    }
}

function reviveBoardFormMatrix(snapshot) {
    for (let i = 0; i < boardHeight; i++) {
        for (let j = 0; j < boardWidth; j++) {
            let tableCell = document.getElementById('tb' + i + '_' + j);
            if (parseInt(tableCell.dataset.state) != snapshot[i][j].state) {
                tableCell.dataset.state = snapshot[i][j].state;
                switch(snapshot[i][j].state) {
                    case -1: { // Empty
                        tableCell.innerHTML = '';
                        break;
                    }
                    case 1: { // Arrow
                        let arrowFigure = document.createElement('div');
                        arrowFigure.className = 'figure figure-arrow';
                        tableCell.append(arrowFigure);
                        break;
                    }
                    case 2: { // Queen
                        placeFigure(i, j, snapshot[i][j].queenTeam);
                        break;
                    }
                    default: {
                        alert("Error");
                        break;
                    }
                }
            }
        }
    }
}

function saveCurrentBoard() {
    console.log(boardSnapshots, currentTurnNumber);
    let moveObj = { snapshot: getFieldMatrix(), teamTurn: currentTeam}
    if (!firstCancel) {
        firstCancel = true;
        currentTurnNumber += 1;
    } 
    boardSnapshots[currentTurnNumber] = moveObj;
    currentTurnNumber += 1;
}

function isValidCoord(i, j, height, width) {
    if (i < 0 || j < 0 ) return false;
    else if ( i >= height || j >= width) return false;
    else return true;
}

function validCrossMovement(i, j, isBigger, opX, opY, currX1, currY1){
    var x;
    if(isBigger) x = currX1 - i; //diff
    else x = i - currX1;
    
    for(let b = 1; b < x; b++){
        let tableCell;
        if(!opX && opY) tableCell = document.getElementById('tb' + (currX1-b) + '_' + (currY1+b));
        else if(!opX && !opY) tableCell = document.getElementById('tb' + (currX1-b) + '_' + (currY1-b));
        else if(opX && opY) tableCell = document.getElementById('tb' + (currX1+b) + '_' + (currY1+b));
        else if(opX && !opY) tableCell = document.getElementById('tb' + (currX1+b) + '_' + (currY1-b));
        else return false;

        if(tableCell == null){
            return false;
        }

        if(tableCell.dataset.state == CellState.ARROW || tableCell.dataset.state == CellState.QUEEN){
            return false;
        }
    }
    if(currY1 + x == j || currY1 - x == j) return true;
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
    if (highlightedCell != undefined) {
        highlightedCell.classList.remove('block-highlight');
        highlightedCell = undefined;
    }
}

function showPossibleFigureMoves() {
    for (let i = 0; i < boardHeight; i++) {
        for (let j = 0; j < boardWidth; j++) {
            let tableCell = document.getElementById('tb' + i + '_' + j);
            if(checkValidMovement(i, j, currX, currY) && tableCell.dataset.state != CellState.QUEEN && tableCell.dataset.state != CellState.ARROW){
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
    if (currentTeam == TEAMWHITE) {
        currentTeamText.textContent = "Black's turn";
        document.body.classList.remove('table-white-turn');
        document.body.classList.add('table-black-turn');
        currentTeam = TEAMBLACK;
        isBotMove = true;
        if (selectedGameMode == GameMode.AI) bot();
        isBotMove = false;
    } else {
        currentTeamText.textContent = "White's turn";
        document.body.classList.remove('table-black-turn');
        document.body.classList.add('table-white-turn');
        currentTeam = TEAMWHITE;
    }
}

function setCurrentTeam(team) {
    if (team == TEAMBLACK) {
        currentTeamText.textContent = "Black's turn";
        document.body.classList.remove('table-white-turn');
        document.body.classList.add('table-black-turn');
        currentTeam = TEAMBLACK;
        isBotMove = true;
        if (selectedGameMode == GameMode.AI) bot();
        isBotMove = false;
    } else {
        currentTeamText.textContent = "White's turn";
        document.body.classList.remove('table-black-turn');
        document.body.classList.add('table-white-turn');
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

function isCurrentCapture() {
    if (currentPossibleWays == 0) return true;
    return false;
}

function isQueenCaptured(queenI, queenJ) {
    let currMatrix = getFieldMatrix();
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

let tmpLog = '';

function logMove(fromI, fromJ, toI, toJ) {
    let symbol;
    if (currentTeam == TEAMWHITE) symbol = WHITE_LOG;
    else if (currentTeam == TEAMBLACK) symbol = BLACK_LOG;

    let tmp = document.createElement('span');
    tmp.innerHTML = symbol;

    gameLog.scrollTop = gameLog.scrollHeight;
    tmpLog = tmp.innerHTML + ': ' + '(' +  mapJToLetters(fromJ) + mapIToNumbers(fromI) + ')->(' + mapJToLetters(toJ) + mapIToNumbers(toI) + ')'; 
}

function logShot(i, j) {
    let tmp = document.createElement('span');
    tmp.innerHTML = "&#x1F525";
    gameLog.value += tmpLog + tmp.innerHTML + '->' + '(' + mapJToLetters(j) + mapIToNumbers(i) + ')\n';
    gameLog.scrollTop = gameLog.scrollHeight;
    tmpLog = '';
}