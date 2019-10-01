int main()
{
    int ia = 4;
    int ib = 5;

    int const *p1 = &ia; // a pointer to int type which cannot have other value
    // *p1 = 6; // Error. it CANNOT have other value (interger which in constant)
    p1 = &ib; // OK. it can point to other location in memory

    int *const p2 = &ib; // a pointer to int type that cannot point to somewhere else in memory
    *p2 = 6;
    // p2 = &ia; // Error. it CANNOT point to other memory location (interger pointer)

    /**
     * In general:
     * What matters is what comes AFTER the asteriks (*).
     * In the first example:
     *   only p1 comes after the *, so it can hold other values specifically,
     *   and because it is of type pointer, it CAN point to other memory location, but it CANNOT change the `int` value.
     * 
     * In the second example:
     *   `const p2` comes after the *, so it CAN 
     */
}