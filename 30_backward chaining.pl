% Define the clues and relationships
owns(john, cat).
owns(susan, dog).
owns(mary, parrot).

friend(john, susan).
friend(susan, mary).

% Backward chaining
owns_pet(X, Pet) :-
    owns(X, Pet).

owns_pet(X, Pet) :-
    friend(X, Y),
    owns_pet(Y, Pet).
