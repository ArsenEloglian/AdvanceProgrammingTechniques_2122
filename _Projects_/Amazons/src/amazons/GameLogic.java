package amazons;

public class GameLogic {

    long time;
    int turns;
    boolean gameEnd;
    boolean winner;
    int activePlayer;
    public GameLogic() {
        time = 0;
        turns = 1;
        gameEnd = false;
        winner = false; // if false white wins, else black wins
        activePlayer = 0; // white player starts the game
    }

    public void newTurn() {
        turns++;
    }

    public long getTime() {
        return time;
    }

    public void setTime(long time) {
        this.time = time;
    }

    public String getTurns() {

        return Integer.toString(turns);
    }

    public void setTurns(int turns) {
        this.turns = turns;
    }

    public boolean isGameEnd() {
        return gameEnd;
    }

    public void setGameEnd(boolean gameEnd) {
        this.gameEnd = gameEnd;
    }

    public int getActivePlayer() {
        return activePlayer;
    }

    public void setActivePlayer(int player) {
        activePlayer = player;
    }

    public boolean isWinner() {
        return winner;
    }

    public void setWinner(boolean winner) {
        this.winner = winner;
    }
}
