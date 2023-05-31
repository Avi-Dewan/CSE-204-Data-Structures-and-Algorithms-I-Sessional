class DishWash {
    private int friend;
    private int dishNo;
    private int time;
    private boolean clean;


    DishWash(int friend, int time, int dishNo) {
        this.friend = friend;
        this.time = time;
        this.dishNo = dishNo;
        this.clean = false;
    }

    public int getDishNo() {
        return dishNo;
    }

    public void setDishNo(int dishNo) {
        this.dishNo = dishNo;
    }

    public int getTime() {
        return time;
    }

    public void setTime(int time) {
        this.time = time;
    }

    public boolean isClean() {
        return clean;
    }

    public void setClean(boolean clean) {
        this.clean = clean;
    }

    public int getFriend() {
        return friend;
    }

    public void setFriend(int friend) {
        this.friend = friend;
    }
}
