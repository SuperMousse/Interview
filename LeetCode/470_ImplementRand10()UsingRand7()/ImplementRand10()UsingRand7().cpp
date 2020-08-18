
int rand10() {
    int random = INT_MAX;
    while (random >= 40) {
        random = (rand7() - 1) * 7 + rand7() - 1;
    }
    return random % 10 + 1;
}
