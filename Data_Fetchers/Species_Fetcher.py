import copy
import json

from icecream import ic

outputDictionary = {}

def main():
    rawPokemonData = r"../Raw_Data/Raw_Pokemon_Data.json"
    rawSpeciesData = r"../Raw_Data/Raw_Pokemon-species_Data.json"
    rawEvolutionData = r"../Raw_Data/Raw_Evolution-chain_Data.json"

    global allRawData
    allRawData = getPokemonInfo({"Pokemon": rawPokemonData, "Species": rawSpeciesData, "Evolution": rawEvolutionData})
    # pokemonNameDict = allRawData["Pokemon"]["meowth"][0]
    # pokemonName = pokemonNameDict["name"]
    # addToFinal(parsePokeInfo({"Pokemon": allRawData["Pokemon"][pokemonName][0], "Species": allRawData["Species"][pokemonNameDict["species"]["name"]][0]}))
    for pokemon in allRawData["Pokemon"]:
        pokemonNameDict = allRawData["Pokemon"][pokemon][0]
        pokemonName = pokemonNameDict["name"]
        addToFinal(parsePokeInfo({"Pokemon": allRawData["Pokemon"][pokemonName][0], "Species": allRawData["Species"][pokemonNameDict["species"]["name"]][0]}))
        ic(pokemonName)
    Write(outputDictionary, r"../Pokemon Black2 Replica/Assets/StreamingAssets/Data/Species.json")


def getPokemonInfo(inputDictionary):
    returnDict = {}
    for name, URL in inputDictionary.items():
        with open(URL, 'r') as file:
            returnDict[name] = json.load(file)
    return returnDict

def getTypes(rawData):
    tempTypes = {}
    
    # set types to current types
    tempTypes[1] = rawData["types"][0]["type"]["name"].capitalize()
    tempTypes[2] = rawData["types"][1]["type"]["name"].capitalize() if len(rawData["types"]) > 1 else "None"

    # generations use roman numerals. This map will allow for the an easy conversion and comparison
    # additional characters are added the front of numerals so that all numerals are four characters (to match with generation-#)
    romanDict = {
        'on-i': 1, 'n-ii': 2, '-iii': 3, 'n-iv': 4, 'on-v': 5,
        'n-vi': 6, '-vii': 7, 'viii': 8, 'n-ix': 9
    }

    generationChanges = []

    # check each time a typing has changed
    for i in rawData["past_types"]:
        generationChanges.append(romanDict[i["generation"]["name"][-4:]])
    # identify the correct generation
    correctGeneration = 100
    # if there were relevent changes | change to the correct typing
    if generationChanges:
        # if the last change was before or at gen 5 | use either the most information for gen 5 or none at all (causing the types to not change)
        if max(generationChanges) <= 5:
            correctGeneration = 5
        # if there was a change past gen 5 | use the lowest generation past gen 5
        elif max(generationChanges) > 5:
            for i in generationChanges:
                if i < correctGeneration & i > 5:
                    correctGeneration = i
    # use the correct generation data
    for i in rawData["past_types"]:
        if romanDict[i["generation"]["name"][-4:]] == correctGeneration:
            tempTypes[1] = i["types"][0]["type"]["name"].capitalize()
            tempTypes[2] = i["types"][1]["type"]["name"].capitalize() if len(i["types"]) > 1 else "None"

    return tempTypes

def getAbilities(rawPokemonData):
    # populate tempAbilities with modern slots and abilities
    tempAbilities = {item["slot"]: item["ability"]["name"].capitalize() for item in rawPokemonData.get("abilities", [])}
    # if ability slots 2 or 3 are missing replace with "None"
    tempAbilities[2] = tempAbilities.get(2, "None")
    tempAbilities[3] = tempAbilities.get(3, "None")

    # generations use roman numerals. This map will allow for the an easy conversion and comparison
    # additional characters are added the front of numerals so that all numerals are four characters (to match with generation-#)
    romanDict = {
        'on-i': 1, 'n-ii': 2, '-iii': 3, 'n-iv': 4, 'on-v': 5,
        'n-vi': 6, '-vii': 7, 'viii': 8, 'n-ix': 9
    }

    generationChanges = []
    # check each time abilities have changed
    for i in rawPokemonData["past_abilities"]:
        generationChanges.append(romanDict[i["generation"]["name"][-4:]])
    
    # identify the correct generation
    correctGeneration = 100
    # if there were relevent changes | change to the correct abilities
    if generationChanges:
        # if the last change was before or at gen 5 | use either the most information for gen 5 or none at all (causing the abilities to not change)
        if max(generationChanges) <= 5:
            correctGeneration = 5
        # if there was a change past gen 5 | use the lowest generation past gen 5
        elif max(generationChanges) > 5:
            for i in generationChanges:
                if i < correctGeneration & i > 5:
                    correctGeneration = i
    
    # use the correct generation data
    for i in rawPokemonData["past_abilities"]:
        if romanDict[i["generation"]["name"][-4:]] == correctGeneration:
            # replace each ability slot that has changed with its respective ability
            tempAbilities.update({ability["slot"]: ability["ability"]["name"].capitalize() if ability["ability"] is not None else "None" for ability in i["abilities"]})

    return tempAbilities

def getEvolve(pokemonName):
    evolutionChain = allRawData["Evolution"][pokemonName][pokemonName]
    evolution = pokemonName
    evolveLevel = 0
    print(pokemonName)
    # if first pokemon is an only stage pokemon | default
    if len(evolutionChain.get("evolves_to", [])) == 0:
        ic(1)
    # if first pokemon name == name of pokemon
    elif evolutionChain["species"]["name"] == pokemonName:
        ic(2)
        # if first pokemon can evolve into 1 other pokemon | evolve = second pokemon
        if len([item for item in evolutionChain["evolves_to"] if item["species"]["name"] in allRawData["Species"].keys()]) == 1:
            ic(2.1)
            evolution = evolutionChain["evolves_to"][0]["species"]["name"]
            # if second pokemon does not have evolution details | evolveLevel = 0
            evolveLevel = evolutionChain["evolves_to"][0]["evolution_details"][0]["min_level"] if evolutionChain["evolves_to"][0]["evolution_details"] else 0
        # if first pokemon can evolve into more than 1 pokemon | evolve = Special, evolveLevel = 0
        elif len([item for item in evolutionChain["evolves_to"] if item["species"]["name"] in allRawData["Species"].keys()]) > 1:
            ic(2.2)
            evolution = "Special"
    # if second pokemon is a two stage pokemon | default
    elif len(evolutionChain["evolves_to"][0].get("evolves_to", [])) == 0:
        ic(3)
    # if second pokemon name == name of pokemon
    elif evolutionChain["evolves_to"][0]["species"]["name"] == pokemonName:
        ic(4)
        # if second pokemon can evolve into 1 other pokemon | evolve = third pokemon
        if len([item for item in evolutionChain["evolves_to"][0]["evolves_to"] if item["species"]["name"] in allRawData["Species"].keys()]) == 1 and len(evolutionChain["evolves_to"][0].get("evolution_details", [])) != 0:
            ic(4.1)
            evolution = evolutionChain["evolves_to"][0]["evolves_to"][0]["species"]["name"]
            # if third pokemon does not have evolution details | evolveLevel = 0
            evolveLevel = evolutionChain["evolves_to"][0]["evolves_to"][0]["evolution_details"][0]["min_level"] if evolutionChain["evolves_to"][0]["evolves_to"][0]["evolution_details"] else 0
        # if second pokemon can evolve into more than 1 pokemon | evolve = Special, evolveLevel = 0
        elif len([item for item in evolutionChain["evolves_to"][0]["evolves_to"] if item["species"]["name"] in allRawData["Species"].keys()]) > 1:
            ic(4.2)
            evolution = "Special"

    # Darumaka is the only species that evolves into a species that has forms so it was easier to just manually fix this evolution.
    if evolution == "darmanitan":
        evolution = "Darmanitan-standard"
        evolveLevel = 35
    
    evolution = evolution.capitalize()
    evolveLevel = evolveLevel if evolveLevel is not None else 0
    return {"evolves-to": evolution.capitalize(), "min-level": evolveLevel}

def getMoves(rawPokemonData):
    tempMoves = {"level-up": {}, "egg": [], "machine": [], "tutor": [], "other": {}}
    for move in rawPokemonData["moves"]:
        for version in move["version_group_details"]:
            if version["version_group"]["name"] != "black-2-white-2":
                continue
            moveGroup = version["move_learn_method"]["name"]
            moveName = move["move"]["name"]
            if version["move_learn_method"]["name"] == "level-up":
                tempMoves[moveGroup][moveName] = version["level_learned_at"]
            elif version["move_learn_method"]["name"] in tempMoves:
                tempMoves[moveGroup].append(moveName)
            else:
                tempMoves["other"][moveName] = version["move_learn_method"]["name"]

    tempMoves2 = copy.deepcopy(tempMoves)
    # The naming scheme of PokeAPI is destructive in nature so several move names had to be manually respecified
    hyphenatedDict = {"double-edge": "Double-Edge", "freeze-dry": "Freeze-Dry", "lock-on": "Lock-On", "mud-slap": "Mud-Slap", "power-up-punch": "Power-Up Punch",
                      "self-destruct": "Self-Destruct", "soft-boiled": "Soft-Boiled", "u-turn": "U-turn", "v-create": "V-create", "wake-up-slap": "Wake-Up Slap",
                      "will-o-wisp": "Will-O-Wisp", "x-scissor": "X-Scissor"}
    for learnType, learnData in tempMoves.items():
        if isinstance(learnData, dict):
            for move in learnData:
                if move in hyphenatedDict.keys():
                    tempMoves2[learnType][hyphenatedDict[move]] = learnData[move]
                    tempMoves2[learnType].pop(move)
                else:
                    # If the move name did not have to be manually respecified | Capitalize all words in move name and replace the hyphens with spaces
                    tempMoves2[learnType][" ".join([word.capitalize() for word in move.split("-")])] = learnData[move]
                    tempMoves2[learnType].pop(move)
        elif isinstance(learnData, list):
            for move in learnData:
                if move in hyphenatedDict.keys():
                    tempMoves2[learnType].append(hyphenatedDict[move])
                    tempMoves2[learnType].remove(move)
                else:
                    # If the move name did not have to be manually respecified | Capitalize all words in move name and replace the hyphens with spaces
                    tempMoves2[learnType].append(" ".join([word.capitalize() for word in move.split("-")]))
                    tempMoves2[learnType].remove(move)
    
    return tempMoves2

def printFinalData(finalData):
    for i in finalData:
        print(i)
        print(finalData[i])

def printRawData(rawData):
    for i in rawData:
        print(i)
    print()

def parsePokeInfo(rawData):
    rawPokemonData = rawData["Pokemon"]
    rawSpeciesData = rawData["Species"]
    # printRawData(rawPokemonData)
    # printRawData(rawSpeciesData)
    pokeData = {}

    pokeData["name"] = rawPokemonData["name"].capitalize()

    tempStats = {}
    for i in range(6):
        tempStats[rawPokemonData["stats"][i]["stat"]["name"]] = rawPokemonData["stats"][i]["base_stat"]
    pokeData["stats"] = tempStats
    pokeData["stats"] = {}
    pokeData["stats"]["HitPoints"] = rawPokemonData["stats"][0]["base_stat"]
    pokeData["stats"]["Attack"] = rawPokemonData["stats"][1]["base_stat"]
    pokeData["stats"]["Defense"] = rawPokemonData["stats"][2]["base_stat"]
    pokeData["stats"]["SpecialAttack"] = rawPokemonData["stats"][3]["base_stat"]
    pokeData["stats"]["SpecialDefense"] = rawPokemonData["stats"][4]["base_stat"]
    pokeData["stats"]["Speed"] = rawPokemonData["stats"][5]["base_stat"]

    pokeData["types"] = getTypes(rawPokemonData)

    pokeData["abilities"] = getAbilities(rawPokemonData)

    pokeData["evolve"] = getEvolve(pokeData["name"].lower())

    tempGrowthRate = str
    growthRate = rawSpeciesData["growth_rate"]["name"]
    if growthRate == "slow":
        tempGrowthRate = "Slow"
    elif growthRate == "medium-slow":
        tempGrowthRate = "Medium Slow"
    elif growthRate == "medium":
        tempGrowthRate = "Medium Fast"
    elif growthRate == "fast":
        tempGrowthRate = "Fast"
    elif growthRate == "fast-then-very-slow":
        tempGrowthRate = "Fluctuating"
    elif growthRate == "slow-then-very-fast":
        tempGrowthRate = "Erratic"
    pokeData["growth-rate"] = tempGrowthRate

    pokeData["base-experience"] = rawPokemonData["base_experience"]

    pokeData["effort-values"] = {}
    pokeData["effort-values"]["HitPoints"] = rawPokemonData["stats"][0]["effort"]
    pokeData["effort-values"]["Attack"] = rawPokemonData["stats"][1]["effort"]
    pokeData["effort-values"]["Defense"] = rawPokemonData["stats"][2]["effort"]
    pokeData["effort-values"]["SpecialAttack"] = rawPokemonData["stats"][3]["effort"]
    pokeData["effort-values"]["SpecialDefense"] = rawPokemonData["stats"][4]["effort"]
    pokeData["effort-values"]["Speed"] = rawPokemonData["stats"][5]["effort"]

    pokeData["moves"] = getMoves(rawPokemonData)

    return pokeData


def addToFinal(inputDictionary):
    outputDictionary[inputDictionary["name"]] = inputDictionary

def Write(Object, FileName):
    json_string = json.dumps(Object, indent=4)
    with open(FileName, 'w') as f:
        f.write(json_string)

if __name__ == "__main__":
    main()