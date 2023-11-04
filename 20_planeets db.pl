orbits(mercury,sun).
orbits(venus,sun).
orbits(earth,sun).
orbits(mars,sun).
orbits(moon,earth).
orbits(phobo,mars).
orbits(deimos,mars).
planet(P) :- orbits(P,sun).
satellite(S) :- orbits(S,P), planet(P).
