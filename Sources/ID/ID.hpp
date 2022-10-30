// TODO: Make raw value transparent

#ifndef ID_H
#define ID_H

/// A random integer identifier.
class ID {
public:
    ID();
    ~ID();

    int get_raw_value();

    /// Reset seed for generation of a raw value in ID.
    static void seed();

private:
    /// The raw value of the identifier.
    int raw_value;
};

#endif