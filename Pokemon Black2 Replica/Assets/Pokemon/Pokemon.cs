using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using UnityEngine;

public class Pokemon : MonoBehaviour
{
    // Automatic Properties
    // Most types are not yet implemented and have been substituted with strings
    public string Trainer { get; private set; }

    public string Name { get; private set; }
    public Species Species { get; private set; }

    public int Level { get; private set; }
    public int Experience { get; private set; }

    public Nature Nature { get; private set; }

    public string Ability { get; private set; }

    public string Item { get; set; }

    public Type Type1 { get; set; }
    public Type Type2 { get; set; }

    public Dictionary<int, Move> Moves { get; private set; } = new Dictionary<int, Move>();

    public string Condition { get; set; }

    public Dictionary<string, int> IndividualValues { get; private set; } = new Dictionary<string, int>
    {
        {"HitPoints", 0},
        {"Attack", 0},
        {"Defense", 0},
        {"SpecialAttack", 0},
        {"SpecialDefense", 0},
        {"Speed", 0}
    };
    public Dictionary<string, int> EffortValues { get; set; } = new Dictionary<string, int>
    {
        {"HitPoints", 0},
        {"Attack", 0},
        {"Defense", 0},
        {"SpecialAttack", 0},
        {"SpecialDefense", 0},
        {"Speed", 0}
    };

    public Dictionary<string, int> MaxStats { get; private set; } = new Dictionary<string, int>
    {
        {"HitPoints", 1},
        {"Attack", 1},
        {"Defense", 1},
        {"SpecialAttack", 1},
        {"SpecialDefense", 1},
        {"Speed", 1}
    };
    public Dictionary<string, int> CurrentStats { get; private set; } = new Dictionary<string, int>
    {
        {"HitPoints", 1},
        {"Attack", 1},
        {"Defense", 1},
        {"SpecialAttack", 1},
        {"SpecialDefense", 1},
        {"Speed", 1}
    };
    public Dictionary<string, int> CurrentStages { get; private set; } = new Dictionary<string, int>
    {
        {"Attack", 0},
        {"Defense", 0},
        {"SpecialAttack", 0},
        {"SpecialDefense", 0},
        {"Speed", 0},
        {"Accuracy", 0},
        {"Evasion", 0}
    };

    public uint PersonalityValue { get; private set; }

    // Private Methods
    private void SetIndividualValues(Dictionary<string, int> inputIndividualValues)
    {
        foreach (var (StatName, StatNumber) in inputIndividualValues)
        {
            var invalidKeys = inputIndividualValues.Keys.Where(key => !IndividualValues.ContainsKey(key)).ToList();
            if (invalidKeys.Any())
            {
                string validStatsList = string.Join("\n", IndividualValues.Keys.Select(k => $"{k}"));
                throw new ArgumentException(
                    $"Pokemon -> SetIndividualValues: Invalid stat names provided: '{string.Join(", ", invalidKeys)}'. " +
                    $"\nValid Stats\n{{\n{validStatsList}\n}}"
                );
            }
        }
        foreach (var (StatName, StatNumber) in inputIndividualValues)
        {
            {
                IndividualValues[StatName] = StatNumber;
            }
        }
    }

    private void CalculatePokemonStats()
    {

    }

    private void SetPokemonMoves(Dictionary<int, string> inputMoveNames)
    {
        foreach (var (MoveNumber, MoveName) in inputMoveNames)
        {
            if (MoveNumber >= 1 && MoveNumber <= 4)
            {
                Moves[MoveNumber] = Move.MoveMap[MoveName];
            }
            else
            {
                throw new ArgumentOutOfRangeException($"Pokemon -> SetPokemonMoves -> {MoveNumber} ({MoveName}) Out of Range (Valid: int 1-4");
            }
        }
    }

    public void calculateStageChanges()
    {

    }

    // Public Methods
    public void Evolve()
    {
        Debug.Log($"{Name} is Evolving!\n {Name} Evolved from {Species.Name} to {Species.Evolution.Name}");
        int currentAbilityIndex = 0;
        foreach (var (abilityNumber, abilityName) in Species.Abilities)
        {
            if (abilityName == Ability)
            {
                currentAbilityIndex = abilityNumber;
            }
        }

        Species = Species.Evolution;
        if (currentAbilityIndex != 0) Ability = Species.Abilities[currentAbilityIndex];
        Type1 = Species.Type1;
        Type2 = Species.Type2;

        CalculatePokemonStats();
    }

    public void ChangeStages(string inputStat, int stageChange)
    {

    }

    public void AddExperience(int inputExperience)
    {
        while (Experience + inputExperience >= Species.GrowthRate.ToNextLevel[Level])
        {
            inputExperience -= (Species.GrowthRate.ToNextLevel[Level] - Experience);
            Experience = 0;
            Level += 1;
        }
        Experience += inputExperience;

        if (Level >= Species.EvolutionLevel && Species.EvolutionLevel != 0)
        {
            Evolve();
        }

        CalculatePokemonStats();
    }

    public void Initialize(
        string inputName, string inputSpecies, string inputNature = "Hardy",
        int inputLevel = 1, int inputExperience = 0, string inputAbility = null,
        Dictionary<int, string> inputMoves = null, Dictionary<string, int> inputIndividualValues = null, Dictionary<string, int> inputEffortValues = null,
        string inputCondition = null
    )
    {
        Name = inputName;
        Species = Species.SpeciesMap[inputSpecies];
        Nature = Nature.NatureMap[inputNature];
        Level = inputLevel;
        Experience = inputExperience;

        if (inputAbility != null) { Ability = inputAbility; }
        if (inputMoves != null) { SetPokemonMoves(inputMoves); }
        if (inputIndividualValues != null) { SetIndividualValues(inputIndividualValues); }
        if (inputEffortValues != null) { EffortValues = inputEffortValues; }
        if (inputCondition != null) { Condition = inputCondition; }

        Type1 = Species.Type1;
        Type2 = Species.Type2;

        PersonalityValue = (uint)UnityEngine.Random.Range(0, 4294967295);
    }


    // Start is called once before the first execution of Update after the MonoBehaviour is created
    void Start()
    {
        Initialize("Bulbyboi", "Bulbasaur", inputIndividualValues: new Dictionary<string, int> { { "No", 0 } });
        Debug.Log(Species.GrowthRate.ToNextLevel[Level]);
        Debug.Log(Nature.NatureMap["Adamant"].StatMultipliers["Attack"]);
        Debug.Log(Species.Name);
        Debug.Log(Species.Type1.Name);
        Debug.Log(Species.Stats["HitPoints"]);
        Debug.Log(Species.Moves.LevelUp.Keys.Contains(Move.MoveMap["Vine Whip"]));
        Debug.Log(Species.Evolution.Name);
        Evolve();
        Debug.Log(Nature.NatureMap["Adamant"].StatMultipliers["Attack"]);
        Debug.Log(Species.Name);
        Debug.Log(Species.Type1.Name);
        Debug.Log(Species.Stats["HitPoints"]);
        Debug.Log(Species.Moves.LevelUp.Keys.Contains(Move.MoveMap["Vine Whip"]));
        Debug.Log(Species.Evolution.Name);
        Debug.Log(Species.GrowthRate.ToNextLevel[Level]);
        AddExperience(100000);
        Debug.Log(Species.GrowthRate.ToNextLevel[Level]);
        Debug.Log(Level);
        Debug.Log(Experience);
        SetPokemonMoves(new Dictionary<int, string> { { 1, "Vine Whip" }, { 2, "Leech Seed" }, { 3, "Absorb" }, { 4, "Petal Dance" } });
        Debug.Log(Moves[1].Name);
        Debug.Log(Moves[2].Name);
        Debug.Log(Moves[3].Name);
        Debug.Log(Moves[4].Name);
        Debug.Log(Moves[5].Name);
    }

    // Update is called once per frame
    void Update()
    {
        
    }
}
