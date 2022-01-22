const UIStage = Object.freeze({ STAGE_PLAYERS: 'mainSelector', STAGE_PROPERTIES: 'gamePropertiesSelector', STAGE_GAME: 'gameBlock' });

let currentStage = UIStage.STAGE_PLAYERS;

function setStage(stage) {
    aimateUIElements(currentStage, stage);
    currentStage = stage;
}

function aimateUIElements(stageFrom, stageTo) {
    let disappearElement = document.getElementById(stageFrom);
    let appearElement = document.getElementById(stageTo);
    disappearElement.classList.remove('item-appear');
    disappearElement.classList.add('item-disappear');
    appearElement.classList.remove('item-disappear');
    appearElement.classList.remove('non-shown');
    appearElement.classList.add('item-appear');
}

function mapJToLetters(i) {
    i = parseInt(i);
    var ordA = 'A'.charCodeAt(0); // 65
    var ordZ = 'Z'.charCodeAt(0); // 90
    var len = ordZ - ordA + 1;
  
    var s = "";
    while(i >= 0) {
        s = String.fromCharCode(i % len + ordA) + s;
        i = Math.floor(i / len) - 1;
    }
    return s;
}

function mapIToNumbers(j) {
    j = parseInt(j);
    return j + 1;
}

function drawFieldMarks(boardHeight, boardWidth) {
    for (let j = 0; j < boardWidth; j++) {
        let cell = document.getElementById('tb0_' + j);
        cell.dataset.letter = mapJToLetters(j);
    }
    for (let i = 0; i < boardHeight; i++) {
        let cell = document.getElementById('tb' + i + '_0');
        cell.dataset.number = mapIToNumbers(i);
    }
}