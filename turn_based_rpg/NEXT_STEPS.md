# Turn-Based RPG: Next Steps

## Current status

The project has:

- A player
- An enemy
- Turn-based combat
- Random damage
- Random starting bonuses
- A CMake build file

## Recommended order

1. Add item names instead of using only item numbers.
2. Add a real `Inventory` class.
3. Add attack, defend, and use-item choices.
4. Add different enemy types.
5. Add experience and player levels.
6. Add a shop and gold.
7. Add a simple village and forest map.
8. Add quests.
9. Add a GUI with SFML.
10. Add saving and loading.

## First goal

Improve the battle system before adding graphics.

The next feature should be an interactive battle where the player chooses:

- Attack
- Defend
- Use an item

After the battle works well, connect the same game logic to a GUI.
