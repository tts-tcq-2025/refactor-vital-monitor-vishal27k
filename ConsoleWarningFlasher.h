// Function to flash warning message
static void flashWarning(const char *message) {
    printf("%s\n", message);
    for (int i = 0; i < 6; i++) {
        printf("\r* ");
        fflush(stdout);
        sleep(1);
        printf("\r *");
        fflush(stdout);
        sleep(1);
    }
    printf("\n");
}
